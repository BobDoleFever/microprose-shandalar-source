#!/usr/bin/env python3
import csv

def main():
    combined = {}

    files = [
        "/Users/ben/decomp/ai_symbol_map.csv",
        "/Users/ben/decomp/subsystems_symbol_map.csv",
        "/Users/ben/decomp/palette_kimpic_map.csv",
        "/Users/ben/decomp/minit_glue_map.csv"
    ]

    for fpath in files:
        with open(fpath, "r", encoding="utf-8") as f:
            r = csv.reader(f)
            header = next(r)
            for row in r:
                if len(row) >= 3:
                    addr, old_name, new_name = row[0].strip(), row[1].strip(), row[2].strip()
                    combined[addr] = (old_name, new_name)

    print(f"Total unified symbols across all modules: {len(combined)}")

    with open("/Users/ben/decomp/unified_engine_symbol_map.csv", "w", encoding="utf-8") as out:
        w = csv.writer(out)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, (old_name, new_name) in combined.items():
            w.writerow([addr, old_name, new_name])

if __name__ == "__main__":
    main()
