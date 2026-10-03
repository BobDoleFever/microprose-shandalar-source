"""
A silent stand-in for the game's sound library, MAGSND.DLL, run on the host instead of in the guest.

The real DLL needs DirectSound, the multimedia file I/O (mmio*) and AVIFile, none of which the emulated Windows has. Without
them its InitSnd fails, the game carries on with sound off, and then waits for a sound to finish by polling GetSndState until
it says "stopped" (the duel's coin toss does this, in a loop that makes no calls at all): the loop never ends because the DLL
reports an unloaded sound without touching the answer. Here all 27 exports exist, work the way the game uses them
(`cdecl`, 0 means success, an answer is written through the pointer argument) and say that nothing is playing.

`install(m)` makes LoadLibraryA("magsnd.dll") return this module and GetProcAddress give out its functions by ordinal.
Real audio would hook PlaySnd / PlaySndFile here (the WAV files are the game's own).
"""
from .machine import REG

# ordinal -> (name, index of the pointer argument an answer is written through, answer)
EXPORTS = {
    1: ("InitSnd", None, 0), 2: ("ReleaseSnd", None, 0), 3: ("LoadSnd", None, 0), 4: ("UnloadSnd", None, 0),
    5: ("UnloadAllSnds", None, 0), 6: ("PlaySnd", None, 0), 7: ("PlaySndFile", 2, 0), 8: ("StopSnd", None, 0),
    9: ("StopAllSnds", None, 0), 10: ("PlayMidiFile", None, 0), 11: ("SetPitch", None, 0), 12: ("GetPitch", 1, 0),
    13: ("SetVol", None, 0), 14: ("GetVol", 1, 0), 15: ("SetPan", None, 0), 16: ("GetPan", 1, 0),
    17: ("UpdateSnd", None, 0), 18: ("SetSndMarker", None, 0), 19: ("PlaySndMarker", None, 0), 20: ("GetSndTime", 1, 0),
    21: ("ResetSnd", None, 0), 22: ("GetSndState", 1, 0), 23: ("GetAVISndBuff", None, 0),
    24: ("ReleaseAVISndBuff", None, 0), 25: ("GetSndHWND", None, 0), 26: ("IsSndLoaded", 1, 1), 27: ("GetLRUSnd", None, 0),
}
BASE = 0x7E000000                                              # the module handle LoadLibraryA gives


def _handler(name, out_index, answer):
    def fn(m, a):                                              # cdecl: `a` holds the first stack arguments
        if out_index is not None and a[out_index] > 0xFFFF:
            m.w32(a[out_index], answer)
        return 0
    return name, fn


for _ordinal, (_name, _out, _answer) in EXPORTS.items():
    _n, _f = _handler(_name, _out, _answer)
    REG.handlers[("magsnd.host", _n)] = (_f, None)


def install(m):
    """Make the game's LoadLibraryA('magsnd.dll') find the host version."""
    mods = m.state.setdefault("host_modules", {})
    mods["magsnd.dll"] = {"base": BASE, "exports": {f"#{o}": m.stub_for("magsnd.host", e[0]) for o, e in EXPORTS.items()}}
