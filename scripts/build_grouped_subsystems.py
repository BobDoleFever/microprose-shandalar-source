#!/usr/bin/env python3
"""
build_grouped_subsystems.py - Group Refactored Functions into Modular Subsystems
Consolidates single-function files into clean, cohesive subsystem source modules.
"""

import os
import re
import glob

BASE_DIR = "/Users/ben/decomp"

MODULE_GROUPS = {
    # 1. Duel Subsystems
    "src/duel/duel_mana.c": {
        "header": '/*\n * duel_mana.c - Duel Mana & Casting Engine\n */\n#include "duel.h"\n\n',
        "addrs": ["004521e2", "0048b81a", "00468130", "0048c367", "004af7bb"]
    },
    "src/duel/duel_combat.c": {
        "header": '/*\n * duel_combat.c - Duel Combat & Damage Resolution Engine\n */\n#include "duel.h"\n\n',
        "addrs": ["004af950", "004af74c", "00439892"]
    },
    "src/duel/duel_board.c": {
        "header": '/*\n * duel_board.c - Duel Battlefield State & Card Status Engine\n */\n#include "duel.h"\n\n',
        "addrs": ["00451482", "0048a33f", "004a2b00", "0048c907"]
    },
    "src/duel/duel_ui.c": {
        "header": '/*\n * duel_ui.c - Duel Arena User Interface & Card Sprites\n */\n#include "duel.h"\n\n',
        "addrs": ["0046e571", "0049b309", "0041bcf0"]
    },

    # 2. Magic Subsystems
    "src/magic/sid/card_rules_core.c": {
        "header": '/*\n * card_rules_core.c - Magic Turn Actions & Card State Rules\n */\n#include "magic.h"\n\n',
        "addrs": ["00473179", "00471c32", "0041d963", "0041d9d2", "00473cc5", "0043071d", "00410cc0", "0041db67", "00403250", "0040a3e1"]
    },

    # 3. Platform & Graphics
    "src/platform/gdi_display.c": {
        "header": '/*\n * gdi_display.c - GDI Palette, DIB Sections & Surface Drawing\n */\n#include "magic.h"\n#include "duel.h"\n\n',
        "addrs": ["004709ae", "00471395", "004f4548", "004707a4", "004f3955", "00472b60", "004f5d1a", "0050dce0", "0040c761", "005112b0"]
    },
    "src/platform/font_engine.c": {
        "header": '/*\n * font_engine.c - Bitmap Font & Formatted Text Rendering\n */\n#include "magic.h"\n\n',
        "addrs": ["0040d949", "0040d4d1", "0040cc7e"]
    },

    # 4. Sound
    "src/platform/sound_engine.c": {
        "header": '/*\n * sound_engine.c - Spatial Audio & Sound Track Player\n */\n#include "duel.h"\n\n',
        "addrs": ["0048d00c", "0047a090"]
    },

    # 5. Utilities & File I/O
    "src/util/math_util.c": {
        "header": '/*\n * math_util.c - Core Math, Clamping & Randomization Utilities\n */\n#include "magic.h"\n#include "duel.h"\n\n',
        "addrs": ["0040a305", "0040a1d2", "004d7d5e"]
    },
    "src/util/str_util.c": {
        "header": '/*\n * str_util.c - High-Speed String & Memory Copy Routines\n */\n#include "duel.h"\n\n',
        "addrs": ["004d9640", "004d9630"]
    },
    "src/util/file_io.c": {
        "header": '/*\n * file_io.c - Asset Streaming & Catalog Parsing\n */\n#include "magic.h"\n#include "duel.h"\n\n',
        "addrs": ["0048e01d", "00433bb6", "0046f172", "00434660"]
    },

    # 6. Secondary Binaries
    "deck/src/deck_builder.c": {
        "header": '/*\n * deck_builder.c - Deck Builder Application Subsystem\n */\n#include "deck_unified.h"\n\n',
        "addrs": ["00401010", "004010aa", "0040161a", "00447184"]
    },
    "deckdll/src/deck_engine.c": {
        "header": '/*\n * deck_engine.c - Deck DLL Management Subsystem\n */\n#include "deckdll_unified.h"\n\n',
        "addrs": ["10001f20", "10002340", "10002360", "10003300", "10003380", "10004070", "10004380", "10004b20", "10005120", "10005a40", "10006200", "10006500"]
    },
    "statwin/src/statwin_engine.c": {
        "header": '/*\n * statwin_engine.c - Status Window Subsystem\n */\n#include "statwin_unified.h"\n\n',
        "addrs": ["100014b0", "1000160f", "10001f30", "100021a3", "100023fd", "1000245c", "100024fd", "1000268a", "10002be9", "10002d38", "10002f86"]
    },
    "magsnd/src/sound_driver.c": {
        "header": '/*\n * sound_driver.c - DirectSound Driver Subsystem\n */\n#include "magsnd_unified.h"\n\n',
        "addrs": ["10001240", "100013b6", "100016e4", "10001848", "10001893", "1000192c", "10001c4c", "10002389", "10002476", "1000269b", "100028a5"]
    },
    "magvid/src/video_driver.c": {
        "header": '/*\n * video_driver.c - AVI Video Subsystem\n */\n#include "magvid_unified.h"\n\n',
        "addrs": ["10001740", "10001926", "10001951", "100019c7", "10001a02", "10001c16", "10001c8e", "10001d28", "10001d71", "10001dba", "10001ec2"]
    }
}

def extract_clean_function_body(fpath):
    with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    
    # Strip includes
    content = re.sub(r'#include\s+["<][^">]+[">]\n', '', content)
    content = content.strip()
    return content

def build_modules():
    print(">>> Assembling grouped subsystem modules...")
    
    for mod_path, info in MODULE_GROUPS.items():
        full_mod_path = os.path.join(BASE_DIR, mod_path)
        os.makedirs(os.path.dirname(full_mod_path), exist_ok=True)
        
        module_code = [info["header"]]
        
        for addr in info["addrs"]:
            matches = glob.glob(f"{BASE_DIR}/**/*{addr}*.c", recursive=True)
            matches = [m for m in matches if not m.endswith(('unified.c', 'all.c')) and not m.endswith(os.path.basename(mod_path))]
            if matches:
                src_file = matches[0]
                func_body = extract_clean_function_body(src_file)
                module_code.append(func_body)
                module_code.append("\n\n")
            else:
                pass
                
        with open(full_mod_path, 'w', encoding='utf-8') as f:
            f.write("".join(module_code))
            
        print(f"  -> Generated module: {mod_path}")

def main():
    build_modules()

if __name__ == "__main__":
    main()
