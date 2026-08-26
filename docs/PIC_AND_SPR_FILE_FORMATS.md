# MicroProse MTG (Shandalar) Image Formats: `.PIC` & `.SPR` Specification

This document provides a comprehensive technical reference for the graphics file formats used in *Magic: The Gathering* (MicroProse 1997 / Shandalar):
1. **`.PIC` (KIM / PCX Background Images)**: 8-bit palette-indexed full-screen backdrops, town dialogs, and UI panels.
2. **`.SPR` (MicroProse 2D RLE Sprites)**: Animated game pieces, spell icons, buttons, creature tokens, and overworld characters.

---

## 1. `.PIC` Image Format (KIM / PCX Format)

MicroProse `.PIC` files are authentic **ZSoft PCX Version 5** 8-bit palette-indexed image files.

### On-Disk Binary Layout

```
+-------------------------------------------------------------+
| 128-Byte PCX Header (0x00 - 0x7F)                           |
| Magic 0x0A, Version 0x05, Bounding Box, Pitch               |
+-------------------------------------------------------------+
| RLE Compressed Scanline Data (0x80 - EOF-769)               |
| Scanline 0 ... Scanline (Height - 1)                        |
+-------------------------------------------------------------+
| Palette Flag (1 Byte: 0x0C)                                 |
+-------------------------------------------------------------+
| 256-Color VGA Palette (768 Bytes: 256 x RGB Triplets)       |
+-------------------------------------------------------------+
```

---

### Struct Definition: `PcxHeader` (128 Bytes)

```c
#pragma pack(push, 1)
typedef struct PcxHeader {
    uint8_t  manufacturer;     /* 0x00: Always 0x0A (ZSoft PCX identifier) */
    uint8_t  version;          /* 0x01: Always 0x05 (PCX Version 5 with 256-color palette) */
    uint8_t  encoding;         /* 0x02: Always 0x01 (PCX Run-Length Encoding) */
    uint8_t  bits_per_pixel;   /* 0x03: 8 bits per pixel (1 byte per pixel) */
    uint16_t xmin;             /* 0x04: Left window coordinate */
    uint16_t ymin;             /* 0x06: Top window coordinate */
    uint16_t xmax;             /* 0x08: Right window coordinate */
    uint16_t ymax;             /* 0x0A: Bottom window coordinate */
    uint16_t hres;             /* 0x0C: Horizontal DPI resolution (typically 320/640) */
    uint16_t vres;             /* 0x0E: Vertical DPI resolution (typically 200/480) */
    uint8_t  palette_16[48];   /* 0x10: Legacy 16-color EGA palette (unused in 256-color mode) */
    uint8_t  reserved;         /* 0x40: Reserved (0x00) */
    uint8_t  color_planes;     /* 0x41: Number of color planes (Always 1 for 8-bit paletted) */
    uint16_t bytes_per_line;   /* 0x42: Scanline byte pitch (must be an even number) */
    uint16_t palette_type;     /* 0x44: 1 = Color / 2 = Grayscale */
    uint8_t  filler[58];       /* 0x46: Zero padding to complete 128-byte header */
} PcxHeader;
#pragma pack(pop)
```

#### Field Explanations
- **Dimensions**:
  - $\text{Width} = (\text{xmax} - \text{xmin}) + 1$
  - $\text{Height} = (\text{ymax} - \text{ymin}) + 1$
- **Pitch (`bytes_per_line`)**: The byte stride of each decoded scanline. If $\text{Width}$ is odd, `bytes_per_line` pads to the nearest even number.
- **Palette**: Located at the end of the file. A 768-byte buffer of $256 \times (R, G, B)$ bytes where each channel ranges from `0` to `255`.

---

### `.PIC` RLE Compression Algorithm

Scanlines are encoded sequentially. For each scanline, bytes are read from the stream:

1. Read byte $B$.
2. If $(B \ \& \ \text{0xC0}) == \text{0xC0}$ (top two bits are `11`):
   - $\text{RunLength} = B \ \& \ \text{0x3F}$ ($1$ to $63$).
   - Read next byte $V$ (pixel value).
   - Output $V$ repeated $\text{RunLength}$ times.
3. Otherwise:
   - Output $B$ as a single pixel ($\text{RunLength} = 1$).

---

### Pseudocode: Reading & Writing `.PIC` Files

#### Reading `.PIC`
```python
def read_pic_file(filename):
    with open(filename, "rb") as f:
        data = f.read()

    # 1. Parse Header
    header = parse_pcx_header(data[0:128])
    width = (header.xmax - header.xmin) + 1
    height = (header.ymax - header.ymin) + 1
    pitch = header.bytes_per_line

    # 2. Read 256-color Palette (Last 768 bytes)
    palette = data[-768:]  # 256 * (R, G, B)

    # 3. Decode RLE Scanlines
    pixels = bytearray(width * height)
    offset = 128
    for y in range(height):
        x = 0
        scanline = bytearray(pitch)
        while x < pitch:
            b = data[offset]
            offset += 1
            if (b & 0xC0) == 0xC0:
                run_len = b & 0x3F
                val = data[offset]
                offset += 1
                for _ in range(run_len):
                    if x < pitch:
                        scanline[x] = val
                        x += 1
            else:
                scanline[x] = b
                x += 1
        # Copy valid image width (ignore pitch padding)
        pixels[y * width : (y + 1) * width] = scanline[:width]

    return width, height, pixels, palette
```

#### Writing `.PIC`
```python
def write_pic_file(filename, width, height, pixels, palette_256_rgb):
    header = bytearray(128)
    header[0] = 0x0A    # Manufacturer (PCX)
    header[1] = 0x05    # Version 5 (256-color)
    header[2] = 0x01    # RLE Encoding
    header[3] = 0x08    # 8 bpp
    # xmin = 0, ymin = 0, xmax = width - 1, ymax = height - 1
    struct.pack_into("<HHHH", header, 4, 0, 0, width - 1, height - 1)
    header[65] = 0x01   # 1 Color Plane
    pitch = width + (width % 2)
    struct.pack_into("<H", header, 66, pitch)
    header[68] = 0x01   # Palette Type

    encoded_data = bytearray()
    for y in range(height):
        row = pixels[y * width : (y + 1) * width]
        if len(row) < pitch:
            row += b'\x00' * (pitch - len(row))
        
        # RLE encode scanline
        i = 0
        while i < pitch:
            val = row[i]
            run = 1
            while i + run < pitch and row[i + run] == val and run < 63:
                run += 1
            if run > 1 or (val & 0xC0) == 0xC0:
                encoded_data.append(0xC0 | run)
                encoded_data.append(val)
            else:
                encoded_data.append(val)
            i += run

    with open(filename, "wb") as f:
        f.write(header)
        f.write(encoded_data)
        f.write(b'\x0C')  # Palette marker
        f.write(palette_256_rgb)
```

---

## 2. `.SPR` Sprite Format (MicroProse 2D Sprite Engine)

MicroProse `.SPR` files store collections of 2D RLE-compressed sprites with transparency masking, bounding box offsets, and unclipped/clipped fast blitting.

### On-Disk Binary Layout

A `.SPR` file contains sequential sprite records followed by a terminating `int32_t` `-1` (`0xFFFFFFFF`):

```
+-------------------------------------------------------------+
| Sprite Record 0 Header (16 Bytes)                           |
| TotalSize, Width, Height, ClipLeft, ClipTop, OffsetY, VisH  |
+-------------------------------------------------------------+
| Sprite Record 0 RLE Byte Stream                             |
+-------------------------------------------------------------+
| Sprite Record 1 Header (16 Bytes)                           |
+-------------------------------------------------------------+
| Sprite Record 1 RLE Byte Stream                             |
+-------------------------------------------------------------+
| ...                                                         |
+-------------------------------------------------------------+
| File Terminator (4 Bytes: 0xFFFFFFFF / -1)                  |
+-------------------------------------------------------------+
```

---

### Struct Definition: `SpriteHeader` (16 Bytes)

```c
#pragma pack(push, 1)
typedef struct SpriteHeader {
    int32_t  total_size;      /* 0x00: Total byte size of sprite record (including header) */
    int16_t  width;           /* 0x04: Full bounding box width */
    int16_t  height;          /* 0x06: Full bounding box height */
    int16_t  clip_left;       /* 0x08: Left transparent margin */
    int16_t  clip_top;        /* 0x0A: Top transparent margin */
    int16_t  offset_y;        /* 0x0C: First non-empty row index (skips top transparent rows) */
    int16_t  visible_height;  /* 0x0E: Number of active encoded rows (height - offset_y) */
    uint8_t  data[];          /* 0x10: RLE compressed scanline byte stream */
} SpriteHeader;
#pragma pack(pop)
```

#### Field Explanations
- **`total_size`**: Byte offset from the start of the current sprite record to the start of the next sprite record. Enables $O(1)$ skipping between frames.
- **`offset_y`**: Number of leading fully-transparent rows. The renderer skips rendering these rows entirely.
- **`visible_height`**: Number of encoded scanlines present in the `data[]` payload.

---

### `.SPR` Scanline RLE Stream Encoding

The `data[]` stream contains sequential scanline packets for `visible_height` rows:

```
[skip_pixels] -> [run_header] -> [raw pixel bytes...]
```

1. **`skip_pixels` (1 Byte)**:
   - `0xFF` (`255`): The entire row is **transparent** (no pixels encoded).
   - Otherwise ($0 \dots 254$): Number of transparent pixels to skip from the left margin before drawing visible pixels.
2. **`run_header` (1 or 2 Bytes)**:
   - If first byte is `0xFE` (`254`):
     - Indicates a **solid opaque block** (no inner transparent holes).
     - The next byte is `opaque_length`. The renderer uses a fast `memcpy` / 32-bit DWORD copy.
   - If first byte is $\ne \text{0xFE}$:
     - The byte itself is `opaque_length`.
     - The following `opaque_length` bytes contain pixel data, where index `0` represents internal transparency (keying).
3. **`pixels` (`opaque_length` Bytes)**: Raw palette-indexed color bytes.

---

### Pseudocode: Reading & Writing `.SPR` Files

#### Reading `.SPR`
```python
def read_spr_file(filename):
    sprites = []
    with open(filename, "rb") as f:
        data = f.read()

    offset = 0
    while offset < len(data) - 4:
        total_size = struct.unpack_from("<i", data, offset)[0]
        if total_size == -1:
            break

        width, height, clip_l, clip_t, offset_y, vis_h = struct.unpack_from("<hhhhhh", data, offset + 4)
        
        # Decode sprite image
        canvas = bytearray(width * height)
        rle_ptr = offset + 16
        
        for row in range(vis_h):
            skip_left = data[rle_ptr]
            rle_ptr += 1
            
            if skip_left != 0xFF:
                marker = data[rle_ptr]
                rle_ptr += 1
                
                is_solid = (marker == 0xFE)
                if is_solid:
                    length = data[rle_ptr]
                    rle_ptr += 1
                else:
                    length = marker
                
                cur_y = offset_y + row
                dst_idx = cur_y * width + skip_left
                
                for i in range(length):
                    color = data[rle_ptr + i]
                    if color != 0 or is_solid:
                        canvas[dst_idx + i] = color
                
                rle_ptr += length

        sprites.append({
            "width": width,
            "height": height,
            "offset_y": offset_y,
            "pixels": canvas
        })
        offset += total_size

    return sprites
```

#### Writing `.SPR`
```python
def write_spr_file(filename, sprite_list):
    out = bytearray()

    for s in sprite_list:
        width = s["width"]
        height = s["height"]
        pixels = s["pixels"]
        
        # 1. Skip top transparent rows
        offset_y = 0
        while offset_y < height:
            row = pixels[offset_y * width : (offset_y + 1) * width]
            if any(p != 0 for p in row):
                break
            offset_y += 1
            
        vis_h = height - offset_y
        rle_stream = bytearray()
        
        # 2. Encode active rows
        for y in range(offset_y, height):
            row = pixels[y * width : (y + 1) * width]
            
            # Find left transparent margin
            skip_l = 0
            while skip_l < width and row[skip_l] == 0:
                skip_l += 1
                
            if skip_l == width:
                rle_stream.append(0xFF) # Entire row empty
            else:
                rle_stream.append(skip_l)
                # Find right edge
                end_r = width
                while end_r > skip_l and row[end_r - 1] == 0:
                    end_r -= 1
                
                opaque_len = end_r - skip_l
                segment = row[skip_l:end_r]
                
                if 0 not in segment:
                    # Solid opaque row
                    rle_stream.append(0xFE)
                    rle_stream.append(opaque_len)
                else:
                    # Masked row
                    rle_stream.append(opaque_len)
                    
                rle_stream.extend(segment)
                
        # 3. Assemble Header
        record_size = 16 + len(rle_stream)
        # Pad record to 4-byte boundary
        pad = (4 - (record_size % 4)) % 4
        record_size += pad
        
        hdr = struct.pack("<ihhhhhh", record_size, width, height, 0, 0, offset_y, vis_h)
        out.extend(hdr)
        out.extend(rle_stream)
        out.extend(b'\x00' * pad)

    # 4. Write EOF Terminator
    out.extend(struct.pack("<i", -1))

    with open(filename, "wb") as f:
        f.write(out)
```

---

## 3. Full Decompiled Function References

### `.PIC` Engine
- **Header Parsing & Resolution Setup**:
  [`FUN_00512500`](../magic/functions/FUN_00512500_00512500.c) (Entry: `0x00512500`, Size: 421 bytes)
- **Scanline RLE Decompression Loop**:
  [`FUN_005126b0`](../magic/functions/FUN_005126b0_005126b0.c) (Entry: `0x005126b0`, Size: 132 bytes)
- **Master Image File Loader & Surface Blitter**:
  [`FUN_00510b70`](../magic/functions/FUN_00510b70_00510b70.c) (Entry: `0x00510b70`, Size: 610 bytes)
- **High-Level Wrapper**:
  [`Mem_AllocOrFree_00510e20`](../magic/functions/Mem_AllocOrFree_00510e20_00510e20.c) (Entry: `0x00510e20`, Size: 25 bytes)

### `.SPR` Engine ([`src/magic/sidlib/sprite.c`](../src/magic/sidlib/sprite.c))
- **`Sprite_LoadAll`**:
  [`Sprite_LoadAll_0050fcc0`](../src/magic/sidlib/sprite.c) (Entry: `0x0050fcc0`, Size: 144 bytes)
- **`Sprite_LoadCount`**:
  [`Sprite_LoadCount_0050fd50`](../src/magic/sidlib/sprite.c) (Entry: `0x0050fd50`, Size: 154 bytes)
- **`Sprite_ScanRunLength`**:
  [`Sprite_ScanRunLength_0050fdf0`](../src/magic/sidlib/sprite.c) (Entry: `0x0050fdf0`, Size: 157 bytes)
- **`Sprite_EncodeFromSurface`**:
  [`Sprite_EncodeFromSurface_0050fe90`](../src/magic/sidlib/sprite.c) (Entry: `0x0050fe90`, Size: 846 bytes)
- **`Sprite_DrawDirect`**:
  [`Sprite_DrawDirect_005101e0`](../src/magic/sidlib/sprite.c) (Entry: `0x005101e0`, Size: 371 bytes)
- **`Sprite_DrawClipped`**:
  [`Sprite_DrawClipped_00510360`](../src/magic/sidlib/sprite.c) (Entry: `0x00510360`, Size: 1068 bytes)
- **`Sprite_DrawScaled`**:
  [`Sprite_DrawScaled`](../src/magic/sidlib/sprite.c) (Entry: `0x00510790`, Size: 978 bytes)
