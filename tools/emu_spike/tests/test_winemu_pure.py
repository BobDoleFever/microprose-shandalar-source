"""Tests for the parts of the Win32 host that need no emulator: printf/scanf formatting and path mapping."""
import os
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from winemu.cformat import VaReader, format_c, scan_c            # noqa: E402
from winemu.paths import host_path, normalize                     # noqa: E402


class FakeMem:
    """Just enough of Machine for the formatters: byte memory, cstr and put_cstr."""
    def __init__(self):
        self.mem = bytearray(4096)

    def rd(self, a, n):
        return bytes(self.mem[a:a + n])

    def wr(self, a, b):
        self.mem[a:a + len(b)] = b

    def r32(self, a):
        return struct.unpack("<I", self.rd(a, 4))[0]

    def cstr(self, a, limit=4096):
        e = self.mem.index(0, a)
        return bytes(self.mem[a:e])

    def put_cstr(self, a, b):
        self.wr(a, bytes(b) + b"\0")


def varargs(m, base, *vals):
    for i, v in enumerate(vals):
        if isinstance(v, float):
            m.wr(base, struct.pack("<d", v))
            base += 8
        else:
            m.wr(base, struct.pack("<I", v & 0xFFFFFFFF))
            base += 4


class FormatTests(unittest.TestCase):
    def setUp(self):
        self.m = FakeMem()

    def fmt(self, f, *args):
        varargs(self.m, 2000, *args)
        return format_c(self.m, f, VaReader(self.m, 2000))

    def test_integers(self):
        self.assertEqual(self.fmt(b"%d|%5d|%-5d|%05d", 5, 42, 42, 42), b"5|   42|42   |00042")
        self.assertEqual(self.fmt(b"%d", 0xFFFFFFFF), b"-1")
        self.assertEqual(self.fmt(b"%u %x %X", 0xFFFFFFFF, 255, 255), b"4294967295 ff FF")

    def test_strings_and_chars(self):
        self.m.put_cstr(100, b"hello")
        self.assertEqual(self.fmt(b"[%s][%8s][%.3s][%c]", 100, 100, 100, ord("z")), b"[hello][   hello][hel][z]")

    def test_float_and_percent(self):
        self.assertEqual(self.fmt(b"%.2f%%", 3.14159), b"3.14%")

    def test_star_width(self):
        self.assertEqual(self.fmt(b"%*d", 4, 7), b"   7")


class ScanTests(unittest.TestCase):
    def setUp(self):
        self.m = FakeMem()

    def test_ints_and_string(self):
        r = scan_c(self.m, b"12 -7 name", b"%d %d %s", [100, 104, 108])
        self.assertEqual(r, 3)
        self.assertEqual(struct.unpack("<ii", self.m.rd(100, 8)), (12, -7))
        self.assertEqual(self.m.cstr(108), b"name")

    def test_literal_and_char_set(self):
        r = scan_c(self.m, b"key=abc,rest", b"key=%[^,],%s", [200, 300])
        self.assertEqual(r, 2)
        self.assertEqual((self.m.cstr(200), self.m.cstr(300)), (b"abc", b"rest"))

    def test_short_input_returns_count_so_far(self):
        self.assertEqual(scan_c(self.m, b"5", b"%d %d", [100, 104]), 1)

    def test_hex_and_short(self):
        scan_c(self.m, b"ff 9", b"%x %hd", [100, 104])
        self.assertEqual(struct.unpack("<I", self.m.rd(100, 4))[0], 255)
        self.assertEqual(struct.unpack("<H", self.m.rd(104, 2))[0], 9)


class PathTests(unittest.TestCase):
    def test_normalize(self):
        self.assertEqual(normalize("C:\\Magic\\Program", "sound\\a.wav"), "C:\\Magic\\Program\\sound\\a.wav")
        self.assertEqual(normalize("C:\\Magic\\Program", "C:sound\\a.wav"), "C:\\Magic\\Program\\sound\\a.wav")
        self.assertEqual(normalize("C:\\Magic\\Program", "..\\Tutorial\\x"), "C:\\Magic\\Tutorial\\x")
        self.assertEqual(normalize("C:\\Magic\\Program", "\\assertFile.txt"), "C:\\assertFile.txt")
        self.assertEqual(normalize("C:\\Magic\\Program", "d:\\x\\.\\y"), "D:\\x\\y")

    def test_case_insensitive_lookup_and_overlay(self):
        with tempfile.TemporaryDirectory() as root, tempfile.TemporaryDirectory() as ov:
            os.makedirs(os.path.join(root, "Program", "Sound"))
            with open(os.path.join(root, "Program", "Sound", "KWALKL.WAV"), "wb") as f:
                f.write(b"x")
            p, ok = host_path(root, ov, "C:\\Magic\\Program", "sound\\kwalkl.wav")
            self.assertTrue(ok)
            self.assertTrue(p.endswith("KWALKL.WAV"))
            w, _ = host_path(root, ov, "C:\\Magic\\Program", "save.dat", for_write=True)
            self.assertTrue(w.startswith(ov))
            with open(w, "wb") as f:
                f.write(b"y")
            p2, ok2 = host_path(root, ov, "C:\\Magic\\Program", "SAVE.DAT")
            self.assertTrue(ok2 and p2 == w)


if __name__ == "__main__":
    unittest.main()
