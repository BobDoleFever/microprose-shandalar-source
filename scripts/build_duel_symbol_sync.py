#!/usr/bin/env python3
import csv
import json

def main():
    # Load magic context
    magic_context = {}
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r", encoding="utf-8") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        for row in r:
            if len(row) >= 6:
                addr, name, strings, apis, calls, sz = row[:6]
                magic_context[addr] = {
                    "name": name,
                    "strings": strings,
                    "apis": apis,
                    "size": int(sz)
                }

    # Load master renamed map for MAGIC.EXE
    magic_renamed = {}
    with open("/Users/ben/decomp/unified_engine_symbol_map.csv", "r", encoding="utf-8") as f:
        r = csv.reader(f)
        header = next(r)
        for row in r:
            if len(row) >= 3:
                magic_renamed[row[0].strip()] = row[2].strip()

    # Load duel context
    duel_context = {}
    with open("/Users/ben/decomp/scratch_duel_exe_context.tsv", "r", encoding="utf-8") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        for row in r:
            if len(row) >= 6:
                addr, name, strings, apis, calls, sz = row[:6]
                duel_context[addr] = {
                    "name": name,
                    "strings": strings,
                    "apis": apis,
                    "size": int(sz)
                }

    print(f"Loaded {len(magic_context)} MAGIC functions and {len(duel_context)} DUEL functions.")

    # Create string-to-name index from MAGIC
    str_to_magic_name = {}
    for addr, new_name in magic_renamed.items():
        m_info = magic_context.get(addr)
        if m_info and m_info["strings"]:
            # Clean string list
            str_list = [s.strip() for s in m_info["strings"].split("|") if len(s.strip()) > 3]
            for s in str_list:
                if s not in str_to_magic_name:
                    str_to_magic_name[s] = new_name

    # Match DUEL functions
    duel_matches = {}
    for d_addr, d_info in duel_context.items():
        if d_info["strings"]:
            d_strs = [s.strip() for s in d_info["strings"].split("|") if len(s.strip()) > 3]
            for s in d_strs:
                if s in str_to_magic_name:
                    matched_name = str_to_magic_name[s]
                    duel_matches[d_addr] = matched_name
                    break

    # Also match specific known DUEL addresses
    # Audio functions in DUEL.EXE
    duel_matches["0043dae2"] = "PlaySnd"
    duel_matches["0043db03"] = "PlaySndFile"
    duel_matches["0043db35"] = "StopSnd"
    duel_matches["0043d870"] = "Sound_Init"
    duel_matches["0043d937"] = "Sound_Shutdown"
    duel_matches["0043db56"] = "Sound_SetVolume"
    duel_matches["0043db77"] = "Sound_GetVolume"
    duel_matches["0043db98"] = "Sound_SetPan"
    duel_matches["0043dbb9"] = "Sound_GetPan"
    duel_matches["0043dbda"] = "Sound_SetPitch"
    duel_matches["0043dbfb"] = "Sound_GetPitch"

    print(f"Matched {len(duel_matches)} functions in DUEL.EXE to MAGIC.EXE symbols!")

    with open("/Users/ben/decomp/duel_symbol_sync_map.csv", "w", encoding="utf-8") as out:
        w = csv.writer(out)
        w.writerow(["Address", "NewName"])
        for addr, name in sorted(duel_matches.items()):
            w.writerow([addr, name])

if __name__ == "__main__":
    main()
