"""winemu.accel: the Python stand-ins agree with the guest functions they replace."""
import os
import re
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
from winemu import accel  # noqa: E402


def test_find_word_rules():
    f = accel.find_word
    assert f(b"Flying", b"black", False) == -1
    assert f(b"Target black creature", b"black", False) == 7
    assert f(b"black.", b"black", False) == 0                   # followed by '.'
    assert f(b"blacks", b"black", False) == 0                   # followed by 's'
    assert f(b"x black wins", b"black", False) == 2             # followed by a space and a lower-case letter
    assert f(b"black Wins", b"black", False) == -1              # a space and a capital: passed over
    assert f(b"black", b"black", False) == -1                   # at the end of the text: passed over
    assert f(b"BLACK.", b"black", False) == 0                   # case-insensitive
    assert f(b"BLACK.", b"black", True) == -1                   # case-sensitive
    assert f(b"", b"black", False) == -1 and f(b"black.", b"", False) == -1
    assert f(b"blackx black.", b"black", False) == 7            # the first occurrence that counts


TRACE = os.environ.get("FIND_WORD_TRACE", "")


@pytest.mark.skipif(not os.path.exists(TRACE), reason="set FIND_WORD_TRACE to a trace of the original: winemu.run --accel off --seconds 3 --break 0x100327b1:Find:3:0,1:ret")
def test_find_word_against_original():
    """Every call of the original that the trace shows (strings the trace did not cut short) gives the same result."""
    call = re.compile(r"\[trace .*?\] Find\((.*)\) <- 0x[0-9a-f]+")
    ret = re.compile(r"\[ret .*?\] Find\((.*)\) <- 0x[0-9a-f]+\s+= (-?\d+)")
    seen, checked = {}, 0
    for line in open(TRACE, errors="replace"):
        m = ret.search(line)
        if not m:
            continue
        args = eval("(" + m.group(1) + ",)")                        # noqa: S307  (our own trace: two strings and a number)
        text, word, mode = args[0].encode("latin-1"), args[1].encode("latin-1"), args[2]
        if len(text) >= 59 or len(word) >= 59:
            continue
        assert accel.find_word(text, word, mode != 0) == int(m.group(2)), (text, word, mode)
        checked += 1
    assert checked > 100
