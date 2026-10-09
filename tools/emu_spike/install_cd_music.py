#!/usr/bin/env python3
"""
Copy the music from the game's CD into the emulator's overlay, where the emulated game finds it.

The game plays its music (`sound\\locmus0..19.wav`, the duel tunes, the castle themes) from the CD-ROM, which the retail install does not
copy. Give this the CD as a mounted folder or as the disc image, and it copies the CD's `Sound` folder to `sources/emu_overlay/Program/Sound`
(the folder is git-ignored; the installed copy is not touched):

    python3 install_cd_music.py                       # the .iso in sources/Magic_The_Gathering_ISO (macOS: mounted with hdiutil, read only)
    python3 install_cd_music.py /Volumes/MTG          # a mounted CD, or any folder that has a Sound folder
    python3 install_cd_music.py "MTG v1.0.iso"
"""
import glob
import os
import shutil
import subprocess
import sys
import tempfile

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
DEST = os.path.join(ROOT, "sources", "emu_overlay", "Program", "Sound")


def sound_dir(folder):
    for name in os.listdir(folder):
        if name.lower() == "sound" and os.path.isdir(os.path.join(folder, name)):
            return os.path.join(folder, name)
    return None


def copy_from(folder):
    src = sound_dir(folder)
    if src is None:
        sys.exit(f"{folder} has no Sound folder")
    os.makedirs(DEST, exist_ok=True)
    n = 0
    for f in sorted(os.listdir(src)):
        if f.lower().endswith(".wav"):
            shutil.copy2(os.path.join(src, f), os.path.join(DEST, f))
            n += 1
    print(f"copied {n} files to {DEST}")


def main():
    arg = sys.argv[1] if len(sys.argv) > 1 else None
    if arg is None:
        found = glob.glob(os.path.join(ROOT, "sources", "Magic_The_Gathering_ISO", "*.iso"))
        if not found:
            sys.exit("no disc image in sources/Magic_The_Gathering_ISO: give the CD folder or the .iso as an argument")
        arg = found[0]
    if os.path.isdir(arg):
        copy_from(arg)
        return
    if sys.platform != "darwin":
        sys.exit("mount the image yourself (mount -o loop on Linux) and give the mounted folder")
    mount = tempfile.mkdtemp(prefix="mtgcd")
    subprocess.run(["hdiutil", "attach", "-readonly", "-nobrowse", "-mountpoint", mount, arg], check=True, capture_output=True)
    try:
        copy_from(mount)
    finally:
        subprocess.run(["hdiutil", "detach", mount], capture_output=True)
        os.rmdir(mount)


if __name__ == "__main__":
    main()
