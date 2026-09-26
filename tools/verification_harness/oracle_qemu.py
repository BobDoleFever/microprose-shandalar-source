#!/usr/bin/env python3
"""
Clients for driving the QEMU-hosted Windows 98 oracle (see docs/ORACLE_VM.md).

- QMP: QEMU's JSON control channel. Used to send keystrokes and take screenshots.
- GDBRemote: a minimal GDB Remote Serial Protocol client for QEMU's gdbstub. Used to set
  breakpoints at addresses from the decompilation and to read registers and memory.

Both are deliberately small and dependency-free. Start the VM with oracle_launch.sh.

Notes on the gdbstub: QEMU pauses the guest when a debugger attaches, and software
breakpoints match on the virtual address (EIP) in whatever process is running. That is fine
for the game's fixed-address code (image base 0x00400000), but memory reads are interpreted
in the page tables of the process that is current when the guest is stopped.
"""

import json
import socket
import time

I386_REGS = ["eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi",
             "eip", "eflags", "cs", "ss", "ds", "es", "fs", "gs"]


class QMP:
    def __init__(self, path, timeout=30):
        self.events = []
        self.sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        self.sock.settimeout(timeout)
        self.sock.connect(path)
        self.f = self.sock.makefile("rw", encoding="utf-8")
        self._read_obj()  # greeting
        self.cmd("qmp_capabilities")

    def _read_obj(self):
        line = self.f.readline()
        if not line:
            raise ConnectionError("QMP connection closed")
        return json.loads(line)

    def cmd(self, execute, **arguments):
        msg = {"execute": execute}
        if arguments:
            msg["arguments"] = arguments
        self.f.write(json.dumps(msg) + "\n")
        self.f.flush()
        while True:
            obj = self._read_obj()
            if "event" in obj:
                self.events.append(obj)
                continue
            if "error" in obj:
                raise RuntimeError(f"QMP {execute}: {obj['error']}")
            return obj.get("return")

    def status(self):
        return self.cmd("query-status")["status"]

    def send_key(self, *qcodes, hold_ms=100):
        """Press and release the given qcodes together (e.g. "ret", or "alt","f4")."""
        keys = [{"type": "qcode", "data": q} for q in qcodes]
        self.cmd("send-key", keys=keys, **{"hold-time": hold_ms})

    def screendump(self, path, fmt="png"):
        self.cmd("screendump", filename=path, format=fmt)


def _checksum(payload: bytes) -> bytes:
    return b"%02x" % (sum(payload) & 0xFF)


class GDBRemote:
    def __init__(self, host="127.0.0.1", port=1234, timeout=30):
        self.sock = socket.create_connection((host, port), timeout=timeout)
        self.buf = b""

    def _send_packet(self, payload: bytes):
        self.sock.sendall(b"$" + payload + b"#" + _checksum(payload))

    def _recv_byte(self):
        if not self.buf:
            chunk = self.sock.recv(4096)
            if not chunk:
                raise ConnectionError("gdbstub closed the connection")
            self.buf = chunk
        b, self.buf = self.buf[:1], self.buf[1:]
        return b

    def _recv_packet(self):
        while self._recv_byte() != b"$":
            pass
        data = b""
        while True:
            c = self._recv_byte()
            if c == b"#":
                break
            data += c
        cs = self._recv_byte() + self._recv_byte()
        if cs != _checksum(data):
            self.sock.sendall(b"-")
            raise IOError("bad gdb packet checksum")
        self.sock.sendall(b"+")
        return data

    def request(self, payload: str) -> bytes:
        self._send_packet(payload.encode())
        return self._recv_packet()

    def read_registers(self):
        raw = bytes.fromhex(self.request("g").decode())
        return {name: int.from_bytes(raw[i * 4:i * 4 + 4], "little")
                for i, name in enumerate(I386_REGS) if i * 4 + 4 <= len(raw)}

    def read_memory(self, addr, length):
        out = b""
        while length > 0:
            n = min(length, 0x200)
            reply = self.request(f"m{addr:x},{n:x}")
            if reply.startswith(b"E"):
                raise IOError(f"read of 0x{addr:x} failed: {reply!r}")
            out += bytes.fromhex(reply.decode())
            addr += n
            length -= n
        return out

    def read_cstring(self, addr, limit=260):
        data = self.read_memory(addr, limit)
        return data.split(b"\0")[0]

    def set_breakpoint(self, addr):
        reply = self.request(f"Z0,{addr:x},1")
        if reply != b"OK":
            raise IOError(f"could not set breakpoint at 0x{addr:x}: {reply!r}")

    def clear_breakpoint(self, addr):
        self.request(f"z0,{addr:x},1")

    def cont(self):
        """Resume the guest. Use wait_stop() to block until it stops again."""
        self._send_packet(b"c")

    def step(self):
        self._send_packet(b"s")
        return self.wait_stop()

    def resume(self, breakpoints=()):
        """Continue after a stop. If we are sitting on one of our own breakpoints, step past it
        first (remove, single-step, re-insert), because QEMU's stub re-triggers a breakpoint
        at the current PC immediately when asked to continue; real debuggers do this dance."""
        pc = self.read_registers()["eip"]
        if pc in breakpoints:
            self.clear_breakpoint(pc)
            self.step()
            self.set_breakpoint(pc)
        self.cont()

    def wait_stop(self, timeout=None):
        old = self.sock.gettimeout()
        self.sock.settimeout(timeout)
        try:
            return self._recv_packet()
        finally:
            self.sock.settimeout(old)

    def interrupt(self):
        self.sock.sendall(b"\x03")
        return self.wait_stop(timeout=10)

    def close(self):
        self.sock.close()


if __name__ == "__main__":
    # Smoke test against a running oracle: python3 oracle_qemu.py <qmp.sock>
    import sys
    q = QMP(sys.argv[1])
    print("VM status:", q.status())
