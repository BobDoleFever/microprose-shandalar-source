#!/usr/bin/env python3
"""Shrink an arm64 Mach-O page-zero segment without moving its code."""

from __future__ import annotations

import argparse
import struct
from pathlib import Path


MACHO_64_MAGIC = 0xFEEDFACF
LC_SEGMENT_64 = 0x19
PAGEZERO_SIZE = 0x00100000


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("binary", type=Path)
    return parser.parse_args()


def main() -> None:
    arguments = parse_arguments()
    image = bytearray(arguments.binary.read_bytes())
    if len(image) < 32 or struct.unpack_from("<I", image, 0)[0] != MACHO_64_MAGIC:
        raise ValueError("The input is not a 64-bit little-endian Mach-O file.")

    command_count = struct.unpack_from("<I", image, 16)[0]
    command_offset = 32
    changed = False
    for _ in range(command_count):
        command, command_size = struct.unpack_from("<II", image, command_offset)
        if command_size < 8 or command_offset + command_size > len(image):
            raise ValueError("The Mach-O load commands are not valid.")
        if command == LC_SEGMENT_64:
            segment_name = bytes(image[command_offset + 8 : command_offset + 24])
            segment_name = segment_name.split(b"\0", 1)[0]
            if segment_name == b"__PAGEZERO":
                image[command_offset + 8 : command_offset + 24] = (
                    b"__LOWGUARD" + b"\0" * 6
                )
                struct.pack_into("<Q", image, command_offset + 32, PAGEZERO_SIZE)
                changed = True
                break
        command_offset += command_size

    if not changed:
        raise ValueError("The Mach-O file does not contain __PAGEZERO.")
    arguments.binary.write_bytes(image)


if __name__ == "__main__":
    main()
