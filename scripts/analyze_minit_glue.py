#!/usr/bin/env python3
import csv
import re

def analyze():
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        context = {row[0]: row for row in r if len(row) >= 6}

    # Analyze Minit.c
    with open("/Users/ben/decomp/src/magic/sid/Minit.c", "r") as f:
        content_min = f.read()
    funcs_min = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content_min)
    print(f"Total functions in Minit.c: {len(funcs_min)}")

    # Analyze glue.c
    with open("/Users/ben/decomp/src/magic/sid/glue.c", "r") as f:
        content_glue = f.read()
    funcs_glue = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content_glue)
    print(f"Total functions in glue.c: {len(funcs_glue)}")

    mappings = {}

    # Minit function classifications
    for name, addr, sz in funcs_min:
        row = context.get(addr, [addr, name, "", "", "0", sz])
        strs = row[2].lower()
        if addr == "00452793":
            sname = "Engine_ReportFatalError"
        elif addr == "004527bc":
            sname = "UI_DrawCombatBanner"
        elif "deck" in strs:
            sname = f"Deck_Init_{addr}"
        elif "card" in strs:
            sname = f"Card_Setup_{addr}"
        elif "player" in strs:
            sname = f"Player_Init_{addr}"
        elif "mana" in strs:
            sname = f"Mana_Init_{addr}"
        elif "shuffl" in strs:
            sname = f"Deck_Shuffle_{addr}"
        elif "mulligan" in strs:
            sname = f"Deck_Mulligan_{addr}"
        elif int(sz) < 30:
            sname = f"Minit_Util_{addr}"
        else:
            sname = f"Minit_Subsystem_{addr}"
        mappings[addr] = sname

    # Glue function classifications
    for name, addr, sz in funcs_glue:
        row = context.get(addr, [addr, name, "", "", "0", sz])
        strs = row[2].lower()
        if "sound" in strs or "snd" in strs or "wav" in strs:
            sname = f"Glue_Sound_{addr}"
        elif "dialog" in strs or "wnd" in strs or "window" in strs:
            sname = f"Glue_UI_{addr}"
        elif "timer" in strs or "tick" in strs:
            sname = f"Glue_Timer_{addr}"
        elif "mouse" in strs or "cursor" in strs or "click" in strs:
            sname = f"Glue_Input_{addr}"
        elif "draw" in strs or "paint" in strs or "blit" in strs:
            sname = f"Glue_Render_{addr}"
        elif int(sz) < 30:
            sname = f"Glue_Util_{addr}"
        else:
            sname = f"Glue_Subsystem_{addr}"
        mappings[addr] = sname

    with open("/Users/ben/decomp/minit_glue_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, sname in mappings.items():
            old = context.get(addr, [addr, f"FUN_{addr}"])[1]
            w.writerow([addr, old, sname])

    print(f"Generated {len(mappings)} mappings for Minit.c and glue.c")

if __name__ == "__main__":
    analyze()
