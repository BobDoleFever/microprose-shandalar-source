#!/usr/bin/env python3
import csv
import re

def analyze():
    # Load context TSV
    context = {}
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        for row in r:
            if len(row) >= 6:
                addr, name, str_refs, api_refs, calls, size = row[0], row[1], row[2], row[3], row[4], row[5]
                context[addr] = {
                    "name": name,
                    "strings": str_refs,
                    "apis": api_refs,
                    "calls": calls,
                    "size": int(size)
                }

    with open("/Users/ben/decomp/src/magic/sid/Ai.c", "r") as f:
        content = f.read()

    funcs = re.findall(r"/\*\s+\*\s+Decompiled function:\s+(\w+)\s+\*\s+Entry Point:\s+(\w+)\s+\*\s+Size:\s+(\d+)\s+bytes\s+\*/", content)

    print(f"Total functions in Ai.c: {len(funcs)}")

    ai_map = []
    for name, addr, sz in funcs:
        info = context.get(addr, {"name": name, "strings": "", "apis": "", "calls": "0", "size": int(sz)})
        strings = info["strings"]
        apis = info["apis"]
        
        # Heuristic determination of AI function role
        semantic_name = name
        
        if addr == "004aa830":
            semantic_name = "Ai_SaveGameState"
        elif addr == "004aaaea":
            semantic_name = "Ai_RestoreGameState"
        elif addr == "004aad61":
            semantic_name = "Ai_PushBoardState"
        elif addr == "004aafa8":
            semantic_name = "Ai_PopBoardState"
        elif addr == "004ab1ef":
            semantic_name = "Ai_ClearPlan"
        elif addr == "004ab214":
            semantic_name = "Ai_BeginTrial"
        elif addr == "004ab28b":
            semantic_name = "Ai_RecordChoice"
        elif addr == "004ab35e":
            semantic_name = "Ai_GetOpponentPlayerScore"
        elif addr == "004ab3a9":
            semantic_name = "Ai_CalcLifeAdvantage"
        elif addr == "004ab3f3":
            semantic_name = "Ai_ReplayChoice"
        elif addr == "004ab45f":
            semantic_name = "Ai_CommitBestPlan"
        elif addr == "004ab552":
            semantic_name = "Ai_EvaluateBoard"
        elif addr == "004abff4":
            semantic_name = "Ai_PenalizeCounterattack"
        elif addr == "004ac940":
            semantic_name = "Ai_ChooseBlockers"
        elif addr == "004acb7f":
            semantic_name = "Ai_FilterValidBlockers"
        elif addr == "004acc20":
            semantic_name = "Duel_ShowStartOfDuelDialog"
        elif addr == "004ace3a":
            semantic_name = "Ai_DuelDialogProc"
        elif addr == "004ad6c5":
            semantic_name = "Ai_LoadStartDuel2Backdrop"
        elif addr == "004ad7c8":
            semantic_name = "Ai_StartDuelWndProc"
        elif addr == "004ae632":
            semantic_name = "Ai_LoadStartDuelBackdrop"
        elif addr == "004ae995":
            semantic_name = "Ai_DuelMainWndProc"
        elif addr == "004af4fd":
            semantic_name = "Ai_LoadEndDuelBackdrop"
        elif "dungeon" in strings.lower():
            semantic_name = f"Ai_DungeonEncounter_{addr}"
        elif "castle" in strings.lower():
            semantic_name = f"Ai_CastleEncounter_{addr}"
        elif "village" in strings.lower() or "city" in strings.lower():
            semantic_name = f"Ai_TownEncounter_{addr}"
        elif "mana" in strings.lower() or "color" in strings.lower():
            semantic_name = f"Ai_CalcManaRequirement_{addr}"
        elif "attack" in strings.lower():
            semantic_name = f"Ai_EvalAttackCandidate_{addr}"
        elif "block" in strings.lower():
            semantic_name = f"Ai_EvalBlockCandidate_{addr}"
        elif "card" in strings.lower() or "spell" in strings.lower():
            semantic_name = f"Ai_ScoreCardPlay_{addr}"
        elif info["size"] < 50:
            semantic_name = f"Ai_Util_{addr}"
        else:
            semantic_name = f"Ai_Subsystem_{addr}"

        ai_map.append((addr, name, semantic_name, strings, apis, sz))

    for m in ai_map[:40]:
        print(f"{m[0]}: {m[1]} -> {m[2]} | Strings: {m[3][:50]} | Size: {m[5]}")

    with open("/Users/ben/decomp/ai_symbol_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for m in ai_map:
            w.writerow([m[0], m[1], m[2]])

if __name__ == "__main__":
    analyze()
