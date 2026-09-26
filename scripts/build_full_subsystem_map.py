#!/usr/bin/env python3
import csv
import re
import os

def main():
    with open("/Users/ben/decomp/scratch_magic_exe_context.tsv", "r") as f:
        r = csv.reader(f, delimiter="\t")
        header = next(r)
        context = {row[0]: row for row in r if len(row) >= 6}

    catalog_renames = {
        "004938e0": "Catalog_Open",
        "00493b2c": "Catalog_Close",
        "00493bea": "Catalog_CompareEntryHash",
        "00493c3a": "Catalog_FindEntry",
        "00493cb6": "Catalog_ReadFile",
        "00493d62": "Catalog_ComputeFilenameHash",
        "00493e50": "ColorOctree_AllocNode",
        "00493e70": "Catalog_LoadPaletteMap",
        "00494080": "Palette_InitSquareDistanceTable",
        "004940c0": "ColorOctree_CollectLeaves",
        "00494120": "ColorOctree_BuildClusters",
        "00494200": "ColorOctree_InsertColor",
        "004942a0": "ColorOctree_FreeTree",
        "00494310": "Color_QuantizeRGBToPalette",
        "00494380": "Palette_BuildFastColorLookup",
        "004943f0": "Color_FindNearestRGB",
        "00494540": "Color_FindNearestPaletteIndex",
        "00494690": "ColorOctree_Flatten",
        "004946f0": "Palette_RemapBitmapRGB",
        "00494820": "Palette_DitherBitmapRGB",
        "00494c00": "Palette_RotateDitherBuffers"
    }

    haar_renames = {
        "004f1920": "Haar_DecompressWaveletImage",
        "004f1e50": "Haar_Transform2D_Inverse",
        "004f2080": "Haar_ReconstructBands",
        "004f2400": "Haar_DecompressHeader",
        "004f25b0": "Haar_DecodeCoefficients",
        "004f2780": "Haar_InverseDWT_Pass",
        "004f2910": "Haar_UnpackBitstream",
        "004f2a50": "Haar_FreeImageBuffer"
    }

    magic_renames = {
        "00473f06": "Magic_ScanCards",
        "00474266": "Magic_TriggerCardEvent",
        "00474389": "Magic_ResolveSpellStack",
        "00474428": "Magic_PayManaCost",
        "004744de": "Magic_TapCardForMana",
        "00474588": "Magic_UntapTurnPhase",
        "00474939": "Magic_CheckTurnTriggers",
        "0047496b": "Duel_PlaySoundById",
        "00474c7f": "Duel_PreloadSoundEffects",
        "00474d7d": "Magic_MainTurnPhase",
        "004751d7": "Magic_CombatPhase",
        "004756a1": "Magic_EndTurnPhase",
        "00475bb0": "Magic_DiscardToHandSize",
        "00475d64": "Magic_CleanupPhase"
    }

    fileio_renames = {
        "0050d240": "FileIO_OpenPackArchive",
        "0050d310": "FileIO_ClosePackArchive",
        "0050d360": "FileIO_ReadPackEntry",
        "0050d410": "FileIO_SeekPackEntry",
        "0050d490": "FileIO_GetPackFileSize",
        "0050d500": "FileIO_ExtractToBuffer"
    }

    text_renames = {
        "00511870": "Font_LoadBitmapFont",
        "00511940": "Font_UnloadBitmapFont",
        "005119b0": "Font_MeasureStringWidth",
        "00511a50": "Font_DrawCharGlyph",
        "00511b80": "Font_DrawTextString",
        "00511d10": "Font_DrawTextFormatted"
    }

    combined = {}
    combined.update(catalog_renames)
    combined.update(haar_renames)
    combined.update(magic_renames)
    combined.update(fileio_renames)
    combined.update(text_renames)

    print(f"Total specific subsystem renames mapped: {len(combined)}")

    with open("/Users/ben/decomp/subsystems_symbol_map.csv", "w", encoding="utf-8") as out_f:
        w = csv.writer(out_f)
        w.writerow(["Address", "OldName", "NewName"])
        for addr, new_name in combined.items():
            old_name = context.get(addr, [addr, f"FUN_{addr}"])[1]
            w.writerow([addr, old_name, new_name])

if __name__ == "__main__":
    main()
