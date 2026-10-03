"""
Host-side stand-ins for a few guest functions that are pure and called very often, so that a live game starts in seconds
instead of a minute (live.py needs it; the exact-hosting comparisons of tools/lift do not use it, as it changes how many
instructions the guest runs).

Each one is the function's machine code read and written as Python over the same arguments, and checked against what the
original returned for the same arguments (tests/test_accel.py, from a recorded trace when the game's files are present).
"""
from .machine import Block, u32

DECKDLL_FIND_WORD = 0x100327B1
MAGIC_FIND_WORD = 0x004F4CE1          # the same function compiled into MAGIC.EXE (identical but for addresses)


def find_word(text: bytes, word: bytes, case_sensitive: bool) -> int:
    """DECKDLL.DLL FUN_100327b1(text, word, case_sensitive): where `word` occurs in `text` as a word (-1 if it does not).

    An occurrence counts when what follows it is 's' or '.', or a space that is not followed by a capital letter; one
    followed by anything else, or by the end of the text, is passed over (the scan goes on one character further).
    The result is the index of the first occurrence that counts."""
    if not text or not word:
        return -1
    n = len(word)
    if not case_sensitive:
        low_text, low_word = text.lower(), word.lower()                  # the C locale's tolower: ASCII only, as bytes.lower
    else:
        low_text, low_word = text, word
    i = low_text.find(low_word)
    while i >= 0:
        after = text[i + n:i + n + 1]
        if after in (b"s", b"."):
            return i
        if after == b" ":
            nxt = text[i + n + 1:i + n + 2]
            if not (nxt and 65 <= nxt[0] <= 90):                         # isupper in the C locale
                return i
        i = low_text.find(low_word, i + 1)
    return -1


def _find_word_native(m, esp):
    text, word, mode = m.r32(esp + 4), m.r32(esp + 8), m.r32(esp + 12)
    if not text or not word:
        return u32(-1)
    return u32(find_word(m.cstr(text), m.cstr(word), mode != 0))


MAGIC_KEY_POLL = 0x00408089            # MAGIC.EXE: `return DAT_00516bdc != 0` -- the menu loops call it flat out, waiting for input


def _key_poll_native(m, esp):
    """The same function, but a loop that calls it 16 times without any other import call in between is waiting for input: it
    sleeps 4 virtual ms (the machine then runs other threads, or sleeps for real when `--live` paces it). The original spins at
    100% of a CPU; in the emulator that is a laptop's fan for nothing."""
    st = m.state.setdefault("accel_poll", [0, -1])
    if m.calls == st[1]:
        st[0] += 1
    else:
        st[0] = 0
    st[1] = m.calls
    if st[0] >= 16:
        st[0] = 0
        return Block(until=m.vt + 0.004)
    return 1 if m.r32(0x516BDC) else 0


def install(m):
    """Replace the guest functions above (those whose module is loaded). Returns how many."""
    n = 0
    if "deckdll.dll" in m.modules:
        m.add_intercept(DECKDLL_FIND_WORD, _find_word_native)             # cdecl: the caller pops its arguments
        n += 1
    if m.exe_guest_path.lower().endswith("\\magic.exe"):
        m.add_intercept(MAGIC_FIND_WORD, _find_word_native)               # (870,000 calls when a new game's cards are set up)
        m.add_intercept(MAGIC_KEY_POLL, _key_poll_native)
        n += 2
    return n
