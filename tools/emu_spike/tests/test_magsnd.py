"""winemu.magsnd: the host sound library has the exports (and ordinals) of the real MAGSND.DLL."""
import os
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from winemu import magsnd  # noqa: E402

DLL = os.path.join(os.path.dirname(__file__), "..", "..", "..", "sources", "installed", "Magic", "Program", "MAGSND.DLL")


def test_there_are_27_exports_numbered_1_to_27():
    assert sorted(magsnd.EXPORTS) == list(range(1, 28))


@pytest.mark.skipif(not os.path.exists(DLL), reason="needs the game's own MAGSND.DLL")
def test_names_match_the_real_dll():
    import pefile
    pe = pefile.PE(DLL)
    real = {e.ordinal: e.name.decode() for e in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    assert {o: e[0] for o, e in magsnd.EXPORTS.items()} == real


def test_an_answer_is_written_through_the_pointer_argument():
    class M:
        def __init__(self):
            self.mem = {}

        def w32(self, a, v):
            self.mem[a] = v
    name, out, answer = magsnd.EXPORTS[22]                      # GetSndState(id, *state): 0 = not playing
    assert (name, out, answer) == ("GetSndState", 1, 0)
    _, fn = magsnd._handler(name, out, answer)
    m = M()
    assert fn(m, [0, 0x5026cc50]) == 0 and m.mem == {0x5026cc50: 0}
    assert fn(m, [0, 0]) == 0                                   # no pointer: nothing written
