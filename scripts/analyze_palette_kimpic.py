#!/usr/bin/env python3
import csv
import re

def analyze():
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        context = {row[0]: row for row in r if len(row) >= 6}

    # Analyze Palette.c
    with open("/Users/ben/decomp/src/magic/NedCard/Palette.c", "r") as f:
        content_pal = f.read()
    funcs_pal = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content_pal)
    print(f"Total functions in Palette.c: {len(funcs_pal)}")

    # Analyze Kimpic.c
    with open("/Users/ben/decomp/src/magic/sidlib/Kimpic.c", "r") as f:
        content_kim = f.read()
    funcs_kim = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content_kim)
    print(f"Total functions in Kimpic.c: {len(funcs_kim)}")

    mappings = {}

    # Palette function classifications
    for name, addr, sz in funcs_pal:
        row = context.get(addr, [addr, name, "", "", "0", sz])
        strs = row[2].lower()
        if addr == "00494c30":
            sname = "Palette_AllocErrorDiffusionTable"
        elif addr == "004950b0":
            sname = "Palette_DitherScanline"
        elif addr == "00495390":
            sname = "Palette_BuildPaletteLUT"
        elif addr == "00495440":
            sname = "Palette_FadeColors"
        elif addr == "004955b0":
            sname = "Palette_SetSystemEntries"
        elif "fade" in strs:
            sname = f"Palette_Fade_{addr}"
        elif "gamma" in strs:
            sname = f"Palette_Gamma_{addr}"
        elif "color" in strs or "rgb" in strs:
            sname = f"Palette_Color_{addr}"
        elif int(sz) < 40:
            sname = f"Palette_Util_{addr}"
        else:
            sname = f"Palette_Subsystem_{addr}"
        mappings[addr] = sname

    # Kimpic function classifications
    for name, addr, sz in funcs_kim:
        row = context.get(addr, [addr, name, "", "", "0", sz])
        strs = row[2].lower()
        if "pic" in strs or "kimpic" in strs:
            sname = f"Pic_Load_{addr}"
        elif "draw" in strs or "blit" in strs:
            sname = f"Pic_Draw_{addr}"
        elif "palette" in strs:
            sname = f"Pic_Palette_{addr}"
        elif "rect" in strs or "clip" in strs:
            sname = f"Pic_Clip_{addr}"
        elif int(sz) < 40:
            sname = f"Pic_Util_{addr}"
        else:
            sname = f"Pic_Subsystem_{addr}"
        mappings[addr] = sname

    with open("/Users/ben/decomp/palette_kimpic_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, sname in mappings.items():
            old = context.get(addr, [addr, f"FUN_{addr}"])[1]
            w.writerow([addr, old, sname])

    print(f"Generated {len(mappings)} mappings for Palette.c and Kimpic.c")

if __name__ == "__main__":
    analyze()
