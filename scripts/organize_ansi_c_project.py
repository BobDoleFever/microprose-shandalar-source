#!/usr/bin/env python3
import os
import re
import shutil

BASE_DIR = "/Users/ben/decomp"
INCLUDE_DIR = os.path.join(BASE_DIR, "include/shandalar")
SRC_DIR = os.path.join(BASE_DIR, "src")

os.makedirs(INCLUDE_DIR, exist_ok=True)

# 1. Generate types.h
types_h_content = """/*
 * shandalar/types.h - Standard ANSI C Win32 & Engine Type Definitions
 */
#ifndef SHANDALAR_TYPES_H
#define SHANDALAR_TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "../windows_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Game Constants */
#define MAX_CARDS_IN_DECK     60
#define MAX_PLAYERS           2
#define MAX_HAND_SIZE         7
#define MAX_COLORS            5

/* Game Primitives */
typedef uint16_t CardID;
typedef uint8_t  PlayerID;
typedef uint8_t  ColorID;

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_TYPES_H */
"""

with open(os.path.join(INCLUDE_DIR, "types.h"), "w", encoding="utf-8") as f:
    f.write(types_h_content)

# 2. Generate sound.h
sound_h_content = """/*
 * shandalar/sound.h - Sound & Audio Driver API
 */
#ifndef SHANDALAR_SOUND_H
#define SHANDALAR_SOUND_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Core Audio API */
int         Sound_Init(int param_1, void* param_2, uint32_t flags);
void        CloseSnd(void);
undefined4  PlaySnd(undefined4 sound_id, undefined4 flags);
int         PlaySndFile(const char* filename, int loop, int* out_handle);
undefined4  StopSnd(undefined4 sound_id);
void        PauseSnd(void);
undefined4  ResumeSnd(undefined4 param_1, undefined4 param_2);
void        ResetSnd(void);
void        UpdateSnd(void);

/* Volume & Pitch Controls */
undefined4  SetVol(undefined4 volume);
undefined4  GetVol(void);
undefined4  SetPan(undefined4 pan);
undefined4  GetPan(void);
undefined4  SetPitch(undefined4 pitch);
undefined4  GetPitch(void);

/* Track & Markers */
undefined4  InitSndTrack(undefined4 track_id, undefined4 param_2, undefined4 param_3);
undefined4  CloseSndTrack(undefined4 track_id);
undefined4  StopSndTrack(void);
undefined4  SetSndMarker(undefined4 marker_id, undefined4 param_2);
undefined4  PlaySndMarker(undefined4 marker_id, uint32_t flags);
undefined4  GetSndTime(undefined4 sound_id);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_SOUND_H */
"""

with open(os.path.join(INCLUDE_DIR, "sound.h"), "w", encoding="utf-8") as f:
    f.write(sound_h_content)

# 3. Generate ai.h
ai_h_content = """/*
 * shandalar/ai.h - Tactical AI & Decision Engine
 */
#ifndef SHANDALAR_AI_H
#define SHANDALAR_AI_H

#include "types.h"
#include "sound.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Tactical AI Routines */
void Ai_EvaluateBoard(void);
int  Ai_ChooseAttacker(int creature_id, int target_player);
int  Ai_ChooseBlocker(int attacker_id, int defender_id);
int  Ai_ScoreThreat(int card_id);
void Ai_CalculateManaCurve(void);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_AI_H */
"""

with open(os.path.join(INCLUDE_DIR, "ai.h"), "w", encoding="utf-8") as f:
    f.write(ai_h_content)

# 4. Generate graphics.h
graphics_h_content = """/*
 * shandalar/graphics.h - 2D Graphics, PCX, PIC, Sprites, and Palettes
 */
#ifndef SHANDALAR_GRAPHICS_H
#define SHANDALAR_GRAPHICS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Image & Resource Loaders */
int  Pic_Load(const char* filename, void** out_buffer);
int  Pcx_Decode(const char* filename, void* dst_surface);
void Sprite_Draw(void* sprite, int x, int y, int flags);
void Palette_SetColors(const void* palette, int start, int count);
void Haar_DecompressWavelet(const void* src, void* dst, int width, int height);
void Font_DrawText(HDC hdc, const char* str, int x, int y, uint32_t color);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_GRAPHICS_H */
"""

with open(os.path.join(INCLUDE_DIR, "graphics.h"), "w", encoding="utf-8") as f:
    f.write(graphics_h_content)

# 5. Generate fileio.h
fileio_h_content = """/*
 * shandalar/fileio.h - File System, CSV Parsers, and Archive IO
 */
#ifndef SHANDALAR_FILEIO_H
#define SHANDALAR_FILEIO_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* CSV & Text Loaders */
int  Csv_LoadMaster(const char* path);
int  Csv_LoadInfo(const char* path);
int  Csv_ReadConcise(const char* path);
int  Csv_WriteConcise(const char* path);
int  Hints_Load(const char* path);
int  Story_Load(const char* path);
int  Tale_Load(const char* path);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_FILEIO_H */
"""

with open(os.path.join(INCLUDE_DIR, "fileio.h"), "w", encoding="utf-8") as f:
    f.write(fileio_h_content)

# 6. Generate cards.h
cards_h_content = """/*
 * shandalar/cards.h - Card Database, Attributes, and Rules Engine
 */
#ifndef SHANDALAR_CARDS_H
#define SHANDALAR_CARDS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Card Rules & Filters */
int  Rules_ParseFilter(const char* filter_expr, void* out_filter);
int  Action_PromptTarget(int spell_id, int target_type);
int  Action_ValidateTarget(int spell_id, int target_id);
int  Deck_FilterAttributes(int card_id, uint32_t color_mask);
int  Catalog_GetCardInfo(int card_index, void* out_card_struct);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_CARDS_H */
"""

with open(os.path.join(INCLUDE_DIR, "cards.h"), "w", encoding="utf-8") as f:
    f.write(cards_h_content)

# 7. Generate ui.h
ui_h_content = """/*
 * shandalar/ui.h - User Interface, Window Procedures & Dialogs
 */
#ifndef SHANDALAR_UI_H
#define SHANDALAR_UI_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UI Window Procedures & Dialog Handlers */
LRESULT CALLBACK UI_BigCardWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL    CALLBACK UI_BigCardDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
ATOM             UI_RegisterBigCardClass(HINSTANCE hInstance);
int              Merchant_ProcessBuy(HWND hwnd, int item_id);

#ifdef __cplusplus
}
#endif

#endif /* SHANDALAR_UI_H */
"""

with open(os.path.join(INCLUDE_DIR, "ui.h"), "w", encoding="utf-8") as f:
    f.write(ui_h_content)

# 8. Generate unified shandalar.h
shandalar_h_content = """/*
 * shandalar/shandalar.h - Master Include Header for Shandalar ANSI C Codebase
 */
#ifndef SHANDALAR_MASTER_H
#define SHANDALAR_MASTER_H

#include "types.h"
#include "sound.h"
#include "graphics.h"
#include "fileio.h"
#include "cards.h"
#include "ai.h"
#include "ui.h"

#endif /* SHANDALAR_MASTER_H */
"""

with open(os.path.join(INCLUDE_DIR, "shandalar.h"), "w", encoding="utf-8") as f:
    f.write(shandalar_h_content)

print("Created modular headers in include/shandalar/")
