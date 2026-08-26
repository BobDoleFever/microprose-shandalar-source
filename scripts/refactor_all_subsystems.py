#!/usr/bin/env python3
"""
refactor_all_subsystems.py - Universal Reverse-Engineering Refactoring Pipeline
Covers all 7 game binaries: MAGIC.EXE, DUEL.EXE, DECK.EXE, DECKDLL.DLL, STATWIN.DLL, MAGSND.DLL, MAGVID.DLL.
"""

import os
import re
import csv
import glob
import subprocess

BASE_DIR = "/Users/ben/decomp"
GHIDRA_HEADLESS = "/opt/homebrew/Cellar/ghidra/12.1.3/libexec/support/analyzeHeadless"
JAVA_HOME = "/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home"

# ------------------------------------------------------------------------------
# 1. Subsystem Function Mappings
# ------------------------------------------------------------------------------
SUBSYSTEM_FUNCS = {
    # MAGVID.DLL
    "10001740": "AVI_InitializeSubsystem",
    "10001926": "AVI_ShutdownSubsystem",
    "10001951": "AVI_OpenFileStream",
    "100019c7": "AVI_ReleaseFileStream",
    "10001a02": "AVI_GetVideoStreamInfo",
    "10001c16": "AVI_ReleaseVideoStream",
    "10001c8e": "AVI_InitTimerPeriod",
    "10001d28": "AVI_EndTimerPeriod",
    "10001d71": "AVI_StopPlaybackTimer",
    "10001dba": "AVI_SeekFrameToTime",
    "10001ec2": "AVI_GetNextFrameSample",

    # MAGSND.DLL
    "10001240": "Sound_DirectSoundInit",
    "100013b6": "Sound_DirectSoundShutdown",
    "100016e4": "Sound_LockAudioBuffer",
    "10001848": "Sound_UnlockAudioBuffer",
    "10001893": "Sound_SetChannelVolume",
    "1000192c": "Sound_UnloadSample",
    "10001c4c": "Sound_SetChannelPanning",
    "10002389": "Sound_PlayWaveSample",
    "10002476": "Sound_StopWaveSample",
    "1000269b": "Sound_GetChannelStatus",
    "100028a5": "Sound_SetMasterVolume",

    # STATWIN.DLL
    "100014b0": "StatWin_LoadSoundDll",
    "1000160f": "StatWin_FreeSoundDll",
    "10001f30": "StatWin_RegisterWindowClass",
    "100021a3": "StatWin_SetAssetPath",
    "100023fd": "StatWin_ProcessMessagePump",
    "1000245c": "StatWin_ProcessPendingEvents",
    "100024fd": "StatWin_PlayVictorySound",
    "1000268a": "StatWin_DisplayStatusScreen",
    "10002be9": "StatWin_CreateStatusWindow",
    "10002d38": "StatWin_WindowProc",
    "10002f86": "StatWin_DrawDibRender",

    # DECKDLL.DLL
    "10001f20": "DeckDll_LoadCardArtCatalogs",
    "10002340": "DeckDll_ReleaseCardArtCatalogs",
    "10002360": "DeckDll_DecompressHaarWavelet",
    "10003300": "DeckDll_RenderCardPreview",
    "10003380": "DeckDll_BlitCardArtwork",
    "10004070": "DeckDll_RegisterWindowClasses",
    "10004380": "DeckDll_DeckSurfaceWndProc",
    "10004b20": "DeckDll_SideboardWndProc",
    "10005120": "DeckDll_CardInventoryWndProc",
    "10005a40": "DeckDll_ManaCurveWndProc",
    "10006200": "DeckDll_SaveDeckFile",
    "10006500": "DeckDll_LoadDeckFile",

    # DECK.EXE
    "00401010": "DeckBuilder_CheckExistingInstance",
    "004010aa": "DeckBuilder_MainEntry",
    "0040161a": "DeckBuilder_InitSubsystems",
}

# ------------------------------------------------------------------------------
# 2. Subsystem DAT Mappings
# ------------------------------------------------------------------------------
SUBSYSTEM_DATS = {
    # MAGVID.DLL
    "10004000": "g_AviPlaybackState",
    "10004004": "g_AviTimerPeriodActive",
    "10004010": "g_AviStreamFrameRate",
    "10004020": "g_AviVideoSurfaceHandle",

    # MAGSND.DLL
    "10005000": "g_DirectSoundObject",
    "10005004": "g_DirectSoundPrimaryBuffer",
    "10005008": "g_SoundCriticalSection",
    "10005020": "g_ActiveSoundChannels",
    "10005040": "g_MasterVolumeLevel",

    # STATWIN.DLL
    "10004000": "g_StatWinInstanceHandle",
    "10004004": "g_StatWinSoundDllHandle",
    "10004008": "g_StatWinHwnd",
    "10004020": "g_StatWinAssetPath",

    # DECKDLL.DLL
    "10008000": "g_DeckDllCardCount",
    "10008004": "g_DeckDllActiveDeckList",
    "10008010": "g_DeckDllSideboardList",
    "10008020": "g_DeckDllMedArtCatalog",
    "10008024": "g_DeckDllSmallArtCatalog",
}

# ------------------------------------------------------------------------------
# 3. CSV File Generator
# ------------------------------------------------------------------------------
def generate_subsystem_csvs():
    print(">>> Generating and updating subsystem symbol CSVs...")

    for mod, prog in [("magsnd", "MAGSND.DLL"), ("magvid", "MAGVID.DLL"), ("statwin", "STATWIN.DLL"), ("deck", "DECK.EXE"), ("deckdll", "DECKDLL.DLL")]:
        csv_file = os.path.join(BASE_DIR, f"{mod}_symbol_map.csv")
        mod_map = {}

        if os.path.exists(csv_file):
            with open(csv_file, 'r', encoding='utf-8') as f:
                r = csv.reader(f)
                next(r, None)
                for row in r:
                    if len(row) >= 3:
                        mod_map[row[0].strip().lower()] = (row[1].strip(), row[2].strip())

        for addr, name in SUBSYSTEM_FUNCS.items():
            addr_l = addr.lower()
            if addr_l.startswith("100") if "dll" in mod or "magsnd" in mod or "magvid" in mod or "statwin" in mod else addr_l.startswith("004"):
                mod_map[addr_l] = (f"FUN_{addr_l}", name)

        with open(csv_file, 'w', newline='', encoding='utf-8') as f:
            w = csv.writer(f)
            w.writerow(["Address", "OldName", "NewName"])
            for addr, (old_name, new_name) in sorted(mod_map.items()):
                w.writerow([addr, old_name, new_name])

        print(f"  -> {mod}_symbol_map.csv updated with {len(mod_map)} entries.")

# ------------------------------------------------------------------------------
# 4. Source Refactoring for All Subsystems
# ------------------------------------------------------------------------------
def refactor_all_modules():
    print(">>> Refactoring C source code across all subsystems...")

    rep_dict = {}
    for addr, name in SUBSYSTEM_FUNCS.items():
        rep_dict[f"FUN_{addr}"] = name
        rep_dict[f"FUN_{addr.lower()}"] = name

    for addr, name in SUBSYSTEM_DATS.items():
        rep_dict[f"DAT_{addr}"] = name
        rep_dict[f"_DAT_{addr}"] = name
        rep_dict[f"DAT_{addr.lower()}"] = name
        rep_dict[f"_DAT_{addr.lower()}"] = name

    modules = ["magsnd", "magvid", "statwin", "deck", "deckdll", "src", "include"]
    all_files = []
    for m in modules:
        all_files.extend(glob.glob(os.path.join(BASE_DIR, m, "**/*.c"), recursive=True))
        all_files.extend(glob.glob(os.path.join(BASE_DIR, m, "**/*.h"), recursive=True))

    updated_count = 0
    for fpath in all_files:
        with open(fpath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()

        orig = content

        for old_sym, new_sym in rep_dict.items():
            if old_sym in content:
                content = re.sub(r'\b' + old_sym + r'\b', new_sym, content)

        if content != orig:
            with open(fpath, 'w', encoding='utf-8') as f:
                f.write(content)
            updated_count += 1
            print(f"  -> Updated: {os.path.relpath(fpath, BASE_DIR)}")

    print(f"Successfully updated {updated_count} files across all subsystems.")

# ------------------------------------------------------------------------------
# 5. Ghidra Headless Synchronization
# ------------------------------------------------------------------------------
def sync_all_ghidra_programs():
    print(">>> Synchronizing all 7 binaries with Ghidra database...")

    env = os.environ.copy()
    env["JAVA_HOME"] = JAVA_HOME
    env["PATH"] = f"{JAVA_HOME}/bin:" + env.get("PATH", "")

    programs = [
        "MAGIC.EXE",
        "DUEL.EXE",
        "DECK.EXE",
        "DECKDLL.DLL",
        "STATWIN.DLL",
        "MAGSND.DLL",
        "MAGVID.DLL"
    ]

    for prog in programs:
        print(f"  -> Synchronizing {prog}...")
        cmd = [
            GHIDRA_HEADLESS,
            "/Users/ben",
            "ShandalarDecomp",
            "-process", prog,
            "-noanalysis",
            "-scriptPath", os.path.join(BASE_DIR, "scripts"),
            "-postScript", "RenameGlobalSymbols.java"
        ]
        res = subprocess.run(cmd, env=env, capture_output=True, text=True)
        if res.returncode == 0:
            print(f"     [OK] {prog} symbols synchronized.")
        else:
            print(f"     [WARN] {prog}: {res.stderr[:100]}")

def main():
    print("==========================================================")
    print(" Running Universal 7-Binary Refactoring Pipeline")
    print("==========================================================")

    generate_subsystem_csvs()
    refactor_all_modules()
    sync_all_ghidra_programs()

    print("==========================================================")
    print(" Universal Refactoring Pipeline Finished Successfully!")
    print("==========================================================")

if __name__ == "__main__":
    main()
