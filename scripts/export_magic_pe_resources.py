#!/usr/bin/env python3
"""Export a PE resource tree from a Ghidra virtual-memory image."""

from __future__ import annotations

import argparse
import json
import struct
import zlib
from dataclasses import dataclass
from pathlib import Path


ORDINAL_MARKER = 0xFFFF
DEFAULT_MEMORY_FLAGS = 0x1030


@dataclass(frozen=True)
class ResourceKey:
    identifier: int | None = None
    name: str | None = None


@dataclass(frozen=True)
class Resource:
    resource_type: ResourceKey
    name: ResourceKey
    language: int
    code_page: int
    data: bytes


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--image", required=True, type=Path)
    parser.add_argument("--output-res", required=True, type=Path)
    parser.add_argument("--output-manifest", required=True, type=Path)
    return parser.parse_args()


def u16(data: bytes, offset: int) -> int:
    return struct.unpack_from("<H", data, offset)[0]


def u32(data: bytes, offset: int) -> int:
    return struct.unpack_from("<I", data, offset)[0]


def align4(data: bytearray) -> None:
    while len(data) % 4:
        data.append(0)


def image_metadata(image: bytes) -> tuple[int, int, int]:
    if image[:2] != b"MZ":
        raise ValueError("The image does not have an MZ header.")
    pe_offset = u32(image, 0x3C)
    if image[pe_offset:pe_offset + 4] != b"PE\0\0":
        raise ValueError("The image does not have a PE header.")
    optional = pe_offset + 24
    if u16(image, optional) != 0x10B:
        raise ValueError("The image is not PE32.")
    image_base = u32(image, optional + 28)
    image_size = u32(image, optional + 56)
    resource_rva = u32(image, optional + 96 + 2 * 8)
    resource_size = u32(image, optional + 96 + 2 * 8 + 4)
    if image_size < len(image):
        raise ValueError("The exported image is larger than SizeOfImage.")
    return image_base, resource_rva, resource_size


def resource_key(image: bytes, root: int, value: int) -> ResourceKey:
    if value & 0x80000000:
        offset = root + (value & 0x7FFFFFFF)
        length = u16(image, offset)
        raw = image[offset + 2:offset + 2 + length * 2]
        return ResourceKey(name=raw.decode("utf-16le"))
    return ResourceKey(identifier=value & 0xFFFF)


def parse_resources(image: bytes) -> list[Resource]:
    image_base, resource_rva, resource_size = image_metadata(image)
    del image_base
    if resource_rva == 0 or resource_size == 0:
        return []
    root = resource_rva
    resources: list[Resource] = []

    def directory_entries(offset: int) -> list[tuple[ResourceKey, int, bool]]:
        if offset < root or offset + 16 > root + resource_size:
            raise ValueError("A resource directory is outside the resource section.")
        named = u16(image, offset + 12)
        identified = u16(image, offset + 14)
        result = []
        for index in range(named + identified):
            entry = offset + 16 + index * 8
            name_value = u32(image, entry)
            target = u32(image, entry + 4)
            result.append((
                resource_key(image, root, name_value),
                root + (target & 0x7FFFFFFF),
                bool(target & 0x80000000),
            ))
        return result

    for type_key, type_target, type_is_directory in directory_entries(root):
        if not type_is_directory:
            raise ValueError("A resource type does not contain a directory.")
        for name_key, name_target, name_is_directory in directory_entries(type_target):
            if not name_is_directory:
                raise ValueError("A resource name does not contain a directory.")
            for language_key, data_entry, language_is_directory in directory_entries(name_target):
                if language_is_directory or language_key.identifier is None:
                    raise ValueError("A resource language entry is not valid.")
                data_rva = u32(image, data_entry)
                size = u32(image, data_entry + 4)
                code_page = u32(image, data_entry + 8)
                if data_rva + size > len(image):
                    raise ValueError("A resource payload is outside the image.")
                resources.append(Resource(
                    type_key,
                    name_key,
                    language_key.identifier,
                    code_page,
                    image[data_rva:data_rva + size],
                ))
    return resources


def encode_key(output: bytearray, key: ResourceKey) -> None:
    if key.name is not None:
        output.extend(key.name.encode("utf-16le"))
        output.extend(b"\0\0")
    elif key.identifier is not None:
        output.extend(struct.pack("<HH", ORDINAL_MARKER, key.identifier))
    else:
        raise ValueError("A resource key has no value.")


def append_record(output: bytearray, resource: Resource) -> None:
    header = bytearray(b"\0" * 8)
    encode_key(header, resource.resource_type)
    encode_key(header, resource.name)
    align4(header)
    header.extend(struct.pack(
        "<IHHII",
        0,
        DEFAULT_MEMORY_FLAGS,
        resource.language,
        0,
        0,
    ))
    struct.pack_into("<II", header, 0, len(resource.data), len(header))
    output.extend(header)
    output.extend(resource.data)
    align4(output)


def key_json(key: ResourceKey) -> int | str:
    return key.name if key.name is not None else int(key.identifier or 0)


def main() -> None:
    arguments = parse_arguments()
    image = arguments.image.read_bytes()
    resources = parse_resources(image)
    resources.sort(key=lambda item: (
        str(key_json(item.resource_type)),
        str(key_json(item.name)),
        item.language,
    ))

    output = bytearray()
    append_record(output, Resource(ResourceKey(identifier=0), ResourceKey(identifier=0), 0, 0, b""))
    for resource in resources:
        append_record(output, resource)

    manifest = {
        "schema_version": 1,
        "resource_count": len(resources),
        "resources": [
            {
                "type": key_json(resource.resource_type),
                "name": key_json(resource.name),
                "language": resource.language,
                "code_page": resource.code_page,
                "size": len(resource.data),
                "crc32": f"{zlib.crc32(resource.data) & 0xffffffff:08x}",
            }
            for resource in resources
        ],
    }
    arguments.output_res.parent.mkdir(parents=True, exist_ok=True)
    arguments.output_manifest.parent.mkdir(parents=True, exist_ok=True)
    arguments.output_res.write_bytes(output)
    arguments.output_manifest.write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


if __name__ == "__main__":
    main()
