#!/usr/bin/env python3
import csv
import re

def analyze():
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        context = {row[0]: row for row in r if len(row) >= 6}

    with open("/Users/ben/decomp/src/magic/sid/Magic.c", "r") as f:
        content = f.read()

    funcs = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content)

    print(f"Total functions in Magic.c: {len(funcs)}")

    magic_map = []
    for name, addr, sz in funcs:
        row = context.get(addr, [addr, name, "", "", "0", sz])
        strings = row[2]
        apis = row[3]

        if addr == "00473f06":
            sname = "Magic_ScanCards"
        elif addr == "00474266":
            sname = "Magic_TriggerCardEvent"
        elif addr == "00474389":
            sname = "Magic_IsManaSource"
        elif addr == "0047444b":
            sname = "Magic_PushEventContext"
        elif addr == "0047458f":
            sname = "Magic_PopEventContext"
        elif addr == "00474712":
            sname = "Magic_UntapTurnPhase"
        elif addr == "00474890":
            sname = "Duel_PlaySoundById"
        elif addr == "004749f0":
            sname = "Duel_PreloadSoundEffects"
        elif addr == "00474b50":
            sname = "Magic_MainTurnPhase"
        elif addr == "00474cf0":
            sname = "Magic_PushSpellStack"
        elif addr == "00474e20":
            sname = "Magic_ResolveTopSpell"
        elif "mana" in strings.lower():
            sname = f"Magic_Mana_{addr}"
        elif "damage" in strings.lower() or "life" in strings.lower():
            sname = f"Magic_Damage_{addr}"
        elif "graveyard" in strings.lower():
            sname = f"Magic_Graveyard_{addr}"
        elif "library" in strings.lower() or "deck" in strings.lower():
            sname = f"Magic_Library_{addr}"
        elif "card" in strings.lower():
            sname = f"Magic_Card_{addr}"
        elif int(sz) < 50:
            sname = f"Magic_Util_{addr}"
        else:
            sname = f"Magic_Subsystem_{addr}"

        magic_map.append((addr, name, sname, strings, sz))

    for m in magic_map[:30]:
        print(f"{m[0]}: {m[1]} -> {m[2]} | Strings: {m[3][:50]} | Size: {m[4]}")

    with open("/Users/ben/decomp/magic_engine_symbol_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for m in magic_map:
            w.writerow([m[0], m[1], m[2]])

if __name__ == "__main__":
    analyze()
