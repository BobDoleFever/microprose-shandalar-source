#!/usr/bin/env python3
import csv
import re
import sys

def sanitize_ident(name):
    clean = re.sub(r'[^a-zA-Z0-9_]', '_', name)
    clean = re.sub(r'_+', '_', clean).strip('_')
    if not clean or clean[0].isdigit():
        clean = '_' + clean
    return clean

def generate_symbol_name(addr, current_name, str_refs_raw, api_refs_raw, size):
    if not current_name.startswith("FUN_"):
        return current_name

    str_refs = [s.strip() for s in str_refs_raw.split(" | ") if s.strip()]
    api_refs = [a.strip() for a in api_refs_raw.split(" | ") if a.strip()]

    # Check for asserts
    for s in str_refs:
        m = re.search(r'([A-Za-z0-9_]+)\.c line (\d+)', s)
        if m:
            module = m.group(1)
            line = m.group(2)
            return f"{module}_Assert_L{line}"
        if "Assertion failed" in s or "assert" in s.lower():
            return f"Assert_Handler_{addr}"

    # Check for specific files
    for s in str_refs:
        s_low = s.lower()
        if "master.csv" in s_low:
            if "fseek" in api_refs or "fscanf" in api_refs:
                return f"Csv_SearchMaster_{addr}"
            return f"Csv_LoadMaster_{addr}"
        if "info.csv" in s_low:
            return f"Csv_LoadInfo_{addr}"
        if "concise.csv" in s_low:
            if "fprintf" in api_refs:
                return f"Csv_WriteConcise_{addr}"
            return f"Csv_ReadConcise_{addr}"
        if "hints.txt" in s_low:
            if "fseek" in api_refs:
                return f"Hints_GetNext_{addr}"
            return f"Hints_Load_{addr}"
        if "story.txt" in s_low:
            return f"Story_Load_{addr}"
        if "tale.txt" in s_low:
            return f"Tale_Load_{addr}"
        if "prompts.txt" in s_low:
            return f"Prompts_Load_{addr}"
        if "menus.txt" in s_low:
            return f"Menus_Load_{addr}"
        if "savegame" in s_low or "savedescs" in s_low:
            return f"Save_ProcessGame_{addr}"

    # Check for UI / Window registration & procs
    if "RegisterClassA" in api_refs or "CreateWindowExA" in api_refs:
        for s in str_refs:
            if "Class" in s or "Window" in s or ".pic" in s:
                clean_s = sanitize_ident(s.replace(".pic", "").replace("\\", ""))
                return f"UI_Register_{clean_s}_{addr}"
        return f"UI_CreateWindow_{addr}"

    if "BeginPaint" in api_refs or "EndPaint" in api_refs or "DefWindowProcA" in api_refs:
        for s in str_refs:
            if "Class" in s or "BigCard" in s:
                return f"UI_WndProc_{sanitize_ident(s)}_{addr}"
        return f"UI_WndProc_{addr}"

    if "DialogBoxParamA" in api_refs or "CreateDialogParamA" in api_refs or "EndDialog" in api_refs:
        return f"UI_DialogProc_{addr}"

    # Check for card attributes and rules
    for s in str_refs:
        if any(keyword in s.lower() for keyword in ["abilities", "artifact creature", "attacking", "blocking", "basicland", "target player"]):
            return f"Rules_ParseFilter_{addr}"
        if any(keyword in s.lower() for keyword in ["activating:", "casting:", "processing:", "pick a card", "pick a player"]):
            return f"Action_PromptTarget_{addr}"
        if "illegal target" in s.lower():
            return f"Action_ValidateTarget_{addr}"
        if "the card seller" in s.lower() or "buyany.spr" in s.lower() or "buybuttons" in s.lower():
            return f"Merchant_ProcessBuy_{addr}"
        if any(keyword in s.lower() for keyword in [".vartifact", ".vblack", ".vblue", ".vgreen", ".vred", ".vwhite", "4th edition"]):
            return f"Deck_FilterAttributes_{addr}"
        if "dungeon" in s.lower():
            return f"Dungeon_Process_{addr}"
        if "castle" in s.lower():
            return f"Castle_Process_{addr}"
        if "village" in s.lower() or "city" in s.lower():
            return f"Town_Process_{addr}"
        if "terrain" in s.lower() or "ter.pic" in s.lower():
            return f"World_LoadTerrain_{addr}"

    # Check for graphics routines
    for s in str_refs:
        if s.lower().endswith(".pic"):
            return f"Pic_Load_{sanitize_ident(s.replace('.pic', ''))}_{addr}"
        if s.lower().endswith(".spr"):
            return f"Sprite_Load_{sanitize_ident(s.replace('.spr', ''))}_{addr}"
        if s.lower().endswith(".wav"):
            return f"Sound_LoadWav_{sanitize_ident(s.replace('.wav', ''))}_{addr}"
        if s.lower().endswith(".avi"):
            return f"Video_Play_{sanitize_ident(s.replace('.avi', ''))}_{addr}"
        if s.lower().endswith(".ttf"):
            return f"Font_LoadTTF_{sanitize_ident(s.replace('.ttf', ''))}_{addr}"

    # Check for memory / string utils
    if set(api_refs).issubset({"malloc", "free", "realloc", "memcpy", "memset"}):
        if size < 50:
            return f"Mem_AllocOrFree_{addr}"

    return None

def process_file(tsv_path, out_csv_path):
    mappings = []
    with open(tsv_path, "r", encoding="utf-8") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        for row in r:
            if len(row) < 6: continue
            addr, curr_name, str_refs, api_refs, call_count, size = row[0], row[1], row[2], row[3], row[4], int(row[5])
            new_name = generate_symbol_name(addr, curr_name, str_refs, api_refs, size)
            if new_name and new_name != curr_name:
                mappings.append((addr, curr_name, new_name))

    with open(out_csv_path, "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for m in mappings:
            w.writerow(m)

    print(f"Generated {len(mappings)} new symbol names in {out_csv_path}")

if __name__ == "__main__":
    process_file("/Users/ben/decomp/scratch_magic_exe_context.tsv", "/Users/ben/decomp/magic_symbol_renames.csv")
    process_file("/Users/ben/decomp/scratch_duel_exe_context.tsv", "/Users/ben/decomp/duel_symbol_renames.csv")
