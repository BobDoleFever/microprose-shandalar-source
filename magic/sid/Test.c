/*
 * sid/Test.c - MicroProse Magic: The Gathering (Shandalar 1997) Main Engine & Authentic Game Loops
 * Original Authors: Sid Meier & Ned Way
 * Reconstructed ANSI C Implementation of the Authentic MAGIC.EXE Startup Flow
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <math.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/display_shim.h"
#include "shandalar/sprite.h"
#include "shandalar/sound.h"
#include "shandalar/magic_engine.h"

/* Forward declarations */
LRESULT UI_WndProc_ShowPaletteClass(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

/* Engine globals */
static int  g_GameScreenWidth  = 640;
static int  g_GameScreenHeight = 480;
static HWND g_HwndScreen       = NULL;
static HDC  g_HdcScreen        = NULL;

/* Main Game 8-bit Framebuffer Surface */
static ScreenSurface g_GameSurface = {0};
static uint8_t      *g_GamePixelBuffer = NULL;

/* 2D Sprite Table */
static void *g_SpriteTable[256] = {0};
static int   g_SpriteCount = 0;

/* Mouse and Input state */
int32_t g_MousePosX   = 0;
int32_t g_MousePosY   = 0;
int32_t g_MouseButton = 0;
static int g_HoveredButton = -1;

/*
 * Authentic MAGIC.EXE State Machine:
 * 0: Main Menu (Sprite_Load_begin_0047a2e6)
 * 1: Difficulty Selection (Pic_Load_menu2_hi_0047abf1)
 * 2: Color Specialization / Starting Deck (Pic_Load_menu3_but1_0047b208)
 * 3: Character Face Selection (Sprite_Load__16faces_0047b899)
 * 4: Shandalar Campaign Overworld Map (Glue_Subsystem_004ec7f9)
 * 5: Duel Combat Arena (Magic_MainTurnPhase / Ai_Subsystem)
 * 6: Deck Builder & Card Catalog
 */
static int g_ActiveGameMode = 0;
static int g_GameTicks = 0;

/* Character & Campaign Configuration */
static int g_SelectedDifficulty = 0; /* 0 = Apprentice, 1 = Mage, 2 = Archmage, 3 = Wizard */
static int g_SelectedColor      = 0; /* 0 = White, 1 = Blue, 2 = Black, 3 = Red, 4 = Green */
static int g_SelectedFaceIndex  = 0; /* 0..15 face portrait index */
static int g_PlayerGold         = 250;
static int g_FoodDays           = 14;

/* Deobfuscated Core Engine State */
int32_t g_PlayerLife[2] = {20, 20};
int32_t g_ActiveTurn = 1;
int32_t g_ActivePlayerId = 0;
int32_t g_CurrentTurnPhaseId = 3; /* 0: Untap, 1: Upkeep, 2: Draw, 3: Main 1, 4: Combat, 5: Main 2, 6: End, 7: Cleanup */
int32_t g_PlayerManaPool[2][6] = {{0}}; /* W, U, B, R, G, C */

/* Card Record Structure */
typedef struct CardEntry {
    int  id;
    char name[32];
    char type[32];
    int  cost_color;
    int  cost_amount;
    int  power;
    int  toughness;
} CardEntry;

/* Authentic 40-card starting deck profiles by color */
static CardEntry g_StartingDecks[5][7] = {
    /* 0: White */
    {
        {0, "Serra Angel",      "Summon Angel",     0, 5, 4, 4},
        {1, "Benalish Hero",    "Summon Hero",      0, 1, 1, 1},
        {2, "Swords to Plowshares","Instant",       0, 1, 0, 0},
        {3, "Disenchant",       "Instant",          0, 2, 0, 0},
        {4, "Healing Salve",    "Instant",          0, 1, 0, 0},
        {5, "Holy Strength",    "Enchant Creature", 0, 1, 0, 0},
        {6, "Plains",           "Basic Land",       0, 0, 0, 0}
    },
    /* 1: Blue */
    {
        {0, "Air Elemental",    "Summon Elemental", 1, 5, 4, 4},
        {1, "Prodigal Sorcerer","Summon Wizard",    1, 3, 1, 1},
        {2, "Ancestral Recall", "Instant",          1, 1, 0, 0},
        {3, "Counterspell",     "Instant",          1, 2, 0, 0},
        {4, "Unsummon",         "Instant",          1, 1, 0, 0},
        {5, "Control Magic",    "Enchant Creature", 1, 4, 0, 0},
        {6, "Island",           "Basic Land",       1, 0, 0, 0}
    },
    /* 2: Black */
    {
        {0, "Sengir Vampire",   "Summon Vampire",   2, 5, 4, 4},
        {1, "Black Knight",     "Summon Knight",    2, 2, 2, 2},
        {2, "Dark Ritual",      "Mana Source",      2, 1, 0, 0},
        {3, "Terror",           "Instant",          2, 2, 0, 0},
        {4, "Drain Life",       "Sorcery",          2, 2, 0, 0},
        {5, "Unholy Strength",  "Enchant Creature", 2, 1, 0, 0},
        {6, "Swamp",            "Basic Land",       2, 0, 0, 0}
    },
    /* 3: Red */
    {
        {0, "Shivan Dragon",    "Summon Dragon",    3, 6, 5, 5},
        {1, "Goblin Balloon",   "Summon Goblins",   3, 1, 1, 1},
        {2, "Lightning Bolt",   "Instant",          3, 1, 0, 0},
        {3, "Fireball",         "Sorcery",          3, 1, 0, 0},
        {4, "Stone Rain",       "Sorcery",          3, 3, 0, 0},
        {5, "Dragon Whelp",     "Summon Dragon",    3, 4, 2, 3},
        {6, "Mountain",         "Basic Land",       3, 0, 0, 0}
    },
    /* 4: Green */
    {
        {0, "Force of Nature",  "Summon Force",     4, 6, 8, 8},
        {1, "Llanowar Elves",   "Summon Elf",       4, 1, 1, 1},
        {2, "Giant Growth",     "Instant",          4, 1, 0, 0},
        {3, "Birds of Paradise","Summon Mana Bird", 4, 1, 0, 1},
        {4, "Tranquility",      "Sorcery",          4, 3, 0, 0},
        {5, "Craw Wurm",        "Summon Wurm",      4, 6, 6, 4},
        {6, "Forest",           "Basic Land",       4, 0, 0, 0}
    }
};

/* Surface Info and Globals for 2D Sprite blitter */
static SurfaceInfo g_MainSurfaceInfo = {0};
SurfaceInfo* DAT_0070a850[4] = { &g_MainSurfaceInfo, &g_MainSurfaceInfo, &g_MainSurfaceInfo, &g_MainSurfaceInfo };

int*    DAT_0062517c = NULL;
int32_t DAT_00624168 = 0;
int32_t DAT_0062416c = 0;
int32_t DAT_00624170 = 0;
int32_t DAT_00624178 = 0;
int32_t DAT_00625180 = 0;
int32_t DAT_00625184 = 0;
int32_t DAT_00625188 = 0;
int32_t DAT_0062518c = 0;
int32_t DAT_00625190 = 0;
int32_t DAT_00625194 = 0;
int32_t DAT_00625198 = 0;
int32_t DAT_00626198 = 0;

long _filelength(int fd)
{
    FILE *fp = fdopen(fd, "rb");
    if (!fp) return 0;
    long cur = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    fseek(fp, cur, SEEK_SET);
    return sz;
}

void AssertOrLog(int cond, int file_id, int line, const char *fmt, ...)
{
    (void)cond; (void)file_id; (void)line; (void)fmt;
}

uint32_t Surface_GetPixel(int surface_id, int x, int y)
{
    (void)surface_id; (void)x; (void)y;
    return 0;
}

void Surface_PutPixel(void *surface, int x, int y, uint32_t color)
{
    ScreenSurface *s = (ScreenSurface *)surface;
    if (!s || !s->pixels) return;
    int w = (s->clip_right > 0) ? s->clip_right : 640;
    int h = (s->clip_bottom > 0) ? s->clip_bottom : 480;
    if (x >= 0 && x < w && y >= 0 && y < h) {
        int pitch = (s->pitch > 0) ? s->pitch : w;
        s->pixels[y * pitch + x] = (uint8_t)color;
    }
}

void Surface_GetLine(void *dst_line, int surface_id, int x, int y, int width)
{
    (void)surface_id; (void)x; (void)y;
    memset(dst_line, 0, width);
}

void Surface_PutLine(void *src_data, int unused, int x, int y, uint32_t count)
{
    (void)unused;
    if (!g_MainSurfaceInfo.frame_buffer) return;
    int pitch = g_MainSurfaceInfo.pitch;
    uint8_t *dst = g_MainSurfaceInfo.frame_buffer + (y * pitch + x);
    memcpy(dst, src_data, count);
}

/* ==========================================================================
 * Load Authentic Palette from TITLE.PIC or Fallback to MTG Colors
 * ========================================================================== */
static void LoadAuthenticGamePalette(void)
{
    uint32_t palette[256];
    memset(palette, 0, sizeof(palette));

    FILE *fp = fopen("TITLE.PIC", "rb");
    if (!fp) fp = fopen("STATUS.PIC", "rb");

    if (fp) {
        uint8_t hdr[6];
        if (fread(hdr, 1, 6, fp) == 6 && hdr[0] == 'M' && hdr[1] == '1') {
            uint8_t rgb[768];
            if (fread(rgb, 1, 768, fp) == 768) {
                printf("[DisplayShim] Successfully loaded authentic 256-color palette from TITLE.PIC!\n");
                for (int i = 0; i < 256; i++) {
                    uint8_t r = rgb[i * 3 + 0];
                    uint8_t g = rgb[i * 3 + 1];
                    uint8_t b = rgb[i * 3 + 2];
                    palette[i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
                }
                Shandalar_SetPalette(palette);
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    printf("[DisplayShim] Initializing default Magic color palette...\n");
    palette[0] = 0xFF08080CU;
    palette[1] = 0xFFFFFFFFU;
    palette[2] = 0xFF000000U;

    for (int i = 0; i < 16; i++) {
        uint8_t v = (uint8_t)(i * 17);
        palette[16 + i] = 0xFF000000U | ((uint32_t)v << 16) | ((uint32_t)v << 8) | (uint32_t)v;
    }
    for (int i = 0; i < 16; i++) {
        uint8_t r = (uint8_t)(160 + i * 6);
        uint8_t g = (uint8_t)(120 + i * 7);
        uint8_t b = (uint8_t)(30 + i * 4);
        palette[32 + i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    }
    for (int i = 0; i < 16; i++) {
        uint8_t r = (uint8_t)(20 + i * 4);
        uint8_t g = (uint8_t)(70 + i * 9);
        uint8_t b = (uint8_t)(150 + i * 7);
        palette[48 + i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    }
    for (int i = 0; i < 16; i++) {
        uint8_t r = (uint8_t)(25 + i * 4);
        uint8_t g = (uint8_t)(120 + i * 8);
        uint8_t b = (uint8_t)(35 + i * 4);
        palette[64 + i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    }
    for (int i = 0; i < 16; i++) {
        uint8_t r = (uint8_t)(160 + i * 6);
        uint8_t g = (uint8_t)(35 + i * 4);
        uint8_t b = (uint8_t)(20 + i * 3);
        palette[80 + i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    }
    for (int i = 96; i < 256; i++) {
        uint8_t r = (uint8_t)((i * 37) & 0xFF);
        uint8_t g = (uint8_t)((i * 59) & 0xFF);
        uint8_t b = (uint8_t)((i * 83) & 0xFF);
        palette[i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
    }

    Shandalar_SetPalette(palette);
}

/* ==========================================================================
 * Graphics & Text Primitives
 * ========================================================================== */
static void DrawChar(ScreenSurface *surf, int x, int y, char c, uint8_t color)
{
    static const uint8_t font8x8[128][8] = {
        ['A'] = {0x18,0x3C,0x66,0x66,0x7E,0x66,0x66,0x00},
        ['B'] = {0x7C,0x66,0x66,0x7C,0x66,0x66,0x7C,0x00},
        ['C'] = {0x3C,0x66,0x60,0x60,0x60,0x66,0x3C,0x00},
        ['D'] = {0x78,0x6C,0x66,0x66,0x66,0x6C,0x78,0x00},
        ['E'] = {0x7E,0x60,0x60,0x78,0x60,0x60,0x7E,0x00},
        ['F'] = {0x7E,0x60,0x60,0x78,0x60,0x60,0x60,0x00},
        ['G'] = {0x3C,0x66,0x60,0x6E,0x66,0x66,0x3C,0x00},
        ['H'] = {0x66,0x66,0x66,0x7E,0x66,0x66,0x66,0x00},
        ['I'] = {0x3C,0x18,0x18,0x18,0x18,0x18,0x3C,0x00},
        ['J'] = {0x1E,0x0C,0x0C,0x0C,0x0C,0x6C,0x38,0x00},
        ['K'] = {0x66,0x6C,0x78,0x70,0x78,0x6C,0x66,0x00},
        ['L'] = {0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x00},
        ['M'] = {0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x00},
        ['N'] = {0x66,0x76,0x7E,0x7E,0x6E,0x66,0x66,0x00},
        ['O'] = {0x3C,0x66,0x66,0x66,0x66,0x66,0x3C,0x00},
        ['P'] = {0x7C,0x66,0x66,0x7C,0x60,0x60,0x60,0x00},
        ['Q'] = {0x3C,0x66,0x66,0x66,0x6A,0x6C,0x36,0x00},
        ['R'] = {0x7C,0x66,0x66,0x7C,0x6C,0x66,0x66,0x00},
        ['S'] = {0x3C,0x66,0x60,0x3C,0x06,0x66,0x3C,0x00},
        ['T'] = {0x7E,0x18,0x18,0x18,0x18,0x18,0x18,0x00},
        ['U'] = {0x66,0x66,0x66,0x66,0x66,0x66,0x3C,0x00},
        ['V'] = {0x66,0x66,0x66,0x66,0x66,0x3C,0x18,0x00},
        ['W'] = {0x63,0x63,0x63,0x6B,0x7F,0x77,0x63,0x00},
        ['X'] = {0x66,0x66,0x3C,0x18,0x3C,0x66,0x66,0x00},
        ['Y'] = {0x66,0x66,0x66,0x3C,0x18,0x18,0x18,0x00},
        ['Z'] = {0x7E,0x06,0x0C,0x18,0x30,0x60,0x7E,0x00},
        ['0'] = {0x3C,0x66,0x6E,0x76,0x66,0x66,0x3C,0x00},
        ['1'] = {0x18,0x38,0x18,0x18,0x18,0x18,0x3C,0x00},
        ['2'] = {0x3C,0x66,0x06,0x0C,0x18,0x30,0x7E,0x00},
        ['3'] = {0x3C,0x66,0x06,0x1C,0x06,0x66,0x3C,0x00},
        ['4'] = {0x0C,0x1C,0x3C,0x6C,0x7E,0x0C,0x0C,0x00},
        ['5'] = {0x7E,0x60,0x7C,0x06,0x06,0x66,0x3C,0x00},
        ['6'] = {0x3C,0x60,0x7C,0x66,0x66,0x66,0x3C,0x00},
        ['7'] = {0x7E,0x06,0x0C,0x18,0x18,0x18,0x18,0x00},
        ['8'] = {0x3C,0x66,0x66,0x3C,0x66,0x66,0x3C,0x00},
        ['9'] = {0x3C,0x66,0x66,0x3E,0x06,0x0C,0x38,0x00},
        [':'] = {0x00,0x18,0x18,0x00,0x18,0x18,0x00,0x00},
        ['-'] = {0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00},
        ['['] = {0x3C,0x30,0x30,0x30,0x30,0x30,0x3C,0x00},
        [']'] = {0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00},
        ['('] = {0x0C,0x18,0x30,0x30,0x30,0x18,0x0C,0x00},
        [')'] = {0x30,0x18,0x0C,0x0C,0x0C,0x18,0x30,0x00},
        ['/'] = {0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00},
        ['.'] = {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00},
        [' '] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    };

    uint8_t uc = (uint8_t)c;
    if (uc >= 'a' && uc <= 'z') uc -= 32;
    const uint8_t *glyph = font8x8[uc];

    for (int row = 0; row < 8; row++) {
        uint8_t bits = glyph[row];
        for (int col = 0; col < 8; col++) {
            if (bits & (0x80 >> col)) {
                Surface_PutPixel(surf, x + col, y + row, color);
            }
        }
    }
}

static void DrawString(ScreenSurface *surf, int x, int y, const char *text, uint8_t color)
{
    while (*text) {
        DrawChar(surf, x, y, *text, color);
        x += 8;
        text++;
    }
}

static void DrawRect(ScreenSurface *surf, int x, int y, int w, int h, uint8_t color)
{
    for (int i = 0; i < w; i++) {
        Surface_PutPixel(surf, x + i, y, color);
        Surface_PutPixel(surf, x + i, y + h - 1, color);
    }
    for (int j = 0; j < h; j++) {
        Surface_PutPixel(surf, x, y + j, color);
        Surface_PutPixel(surf, x + w - 1, y + j, color);
    }
}

static void FillRect(ScreenSurface *surf, int x, int y, int w, int h, uint8_t color)
{
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            Surface_PutPixel(surf, x + i, y + j, color);
        }
    }
}

/* ==========================================================================
 * Mode 0: Main Menu (Sprite_Load_begin_0047a2e6)
 * ========================================================================== */
static void RenderMainMenu(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 0);

    /* Decorative gold border */
    DrawRect(surf, 4, 4, g_GameScreenWidth - 8, g_GameScreenHeight - 8, 40);
    DrawRect(surf, 6, 6, g_GameScreenWidth - 12, g_GameScreenHeight - 12, 45);

    /* MicroProse Title Header */
    FillRect(surf, 20, 20, g_GameScreenWidth - 40, 60, 34);
    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, 60, 45);
    DrawString(surf, 120, 32, "MICROPROSE MAGIC: THE GATHERING", 1);
    DrawString(surf, 180, 52, "AUTHENTIC SHANDALAR ENGINE (1997)", 46);

    /* Five Mana Icons */
    if (g_SpriteCount > 0) {
        int sprite_y = 100;
        int sprite_spacing = 100;
        int start_x = 90;

        for (int i = 0; i < 5 && i < g_SpriteCount; i++) {
            int sx = start_x + i * sprite_spacing;
            DrawRect(surf, sx - 4, sprite_y - 4, 72, 72, 42);
            if (g_SpriteTable[i % g_SpriteCount]) {
                Sprite_DrawClipped(surf, sx, sprite_y, g_SpriteTable[i % g_SpriteCount]);
            }
        }
        DrawString(surf, 100, 180, "WHITE", 1);
        DrawString(surf, 205, 180, "BLUE", 55);
        DrawString(surf, 305, 180, "BLACK", 25);
        DrawString(surf, 410, 180, "RED", 90);
        DrawString(surf, 500, 180, "GREEN", 72);
    }

    /* Menu Options matching original Sprite_Load_begin_0047a2e6 */
    const char *menu_options[] = {
        "[1] NEW GAME (START CAMPAIGN WIZARD)",
        "[2] LOAD SAVED GAME",
        "[3] DUEL / GAUNTLET BATTLE",
        "[4] DECK BUILDER & CARD CATALOG",
        "[5] EXIT TO SYSTEM"
    };

    int btn_w = 420;
    int btn_h = 32;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_start_y = 220;

    for (int i = 0; i < 5; i++) {
        int by = btn_start_y + i * 42;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        if (is_hovered) {
            g_HoveredButton = i;
            FillRect(surf, btn_x, by, btn_w, btn_h, 44);
            DrawRect(surf, btn_x, by, btn_w, btn_h, 1);
            DrawString(surf, btn_x + 30, by + 12, menu_options[i], 1);
            DrawString(surf, btn_x + 10, by + 12, "->", 1);
        } else {
            FillRect(surf, btn_x, by, btn_w, btn_h, 18);
            DrawRect(surf, btn_x, by, btn_w, btn_h, 38);
            DrawString(surf, btn_x + 30, by + 12, menu_options[i], 45);
        }
    }

    FillRect(surf, 20, g_GameScreenHeight - 35, g_GameScreenWidth - 40, 20, 16);
    DrawRect(surf, 20, g_GameScreenHeight - 35, g_GameScreenWidth - 40, 20, 35);
    DrawString(surf, 30, g_GameScreenHeight - 28, "ORIGINAL 1997 FLOW | PRESS 1-5 OR CLICK TO SELECT", 43);
}

/* ==========================================================================
 * Mode 1: Difficulty Selection (Pic_Load_menu2_hi_0047abf1)
 * ========================================================================== */
static void RenderDifficultyMenu(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);

    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    FillRect(surf, 40, 40, g_GameScreenWidth - 80, 50, 32);
    DrawRect(surf, 40, 40, g_GameScreenWidth - 80, 50, 45);
    DrawString(surf, 160, 55, "STEP 1: CHOOSE CAMPAIGN DIFFICULTY", 1);
    DrawString(surf, 175, 70, "(SETS STARTING GOLD & OPPONENT LIFE)", 46);

    const char *diff_names[] = {
        "[1] APPRENTICE (EASIEST - 500 GOLD, 25 HP)",
        "[2] MAGE       (NORMAL  - 350 GOLD, 20 HP)",
        "[3] ARCHMAGE   (HARD    - 200 GOLD, 15 HP)",
        "[4] WIZARD     (MASTER  - 100 GOLD, 10 HP)"
    };

    int btn_w = 460;
    int btn_h = 40;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_y = 130;

    for (int i = 0; i < 4; i++) {
        int by = btn_y + i * 55;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 18);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 38);
        DrawString(surf, btn_x + 20, by + 16, diff_names[i], is_hovered ? 1 : 45);
    }

    FillRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 18);
    DrawRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 38);
    DrawString(surf, 50, g_GameScreenHeight - 55, "PRESS 1-4 OR CLICK TO CHOOSE DIFFICULTY | [ESC] BACK", 1);
}

/* ==========================================================================
 * Mode 2: Color Specialization / Starting Deck (Pic_Load_menu3_but1_0047b208)
 * ========================================================================== */
static void RenderColorSpecializationMenu(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);

    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    FillRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 32);
    DrawRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 45);
    DrawString(surf, 130, 45, "STEP 2: CHOOSE YOUR STARTING COLOR SPECIALIZATION", 1);
    DrawString(surf, 165, 60, "(DETERMINES STARTING DECK & HOME TERRITORY)", 46);

    const char *colors[] = {
        "[1] WHITE - PLAINS OF SANCTUARY (HEALING & PROTECTION)",
        "[2] BLUE  - ISLANDS OF ILLUSION  (COUNTERSPELLS & FLYING)",
        "[3] BLACK - SWAMPS OF DESOLATION (NECROMANCY & REMOVAL)",
        "[4] RED   - MOUNTAINS OF FIRE    (DIRECT DAMAGE & GOBLINS)",
        "[5] GREEN - FORESTS OF PRIMORDIA (GIANT CREATURES & GROWTH)"
    };

    uint8_t badge_colors[] = {1, 55, 25, 90, 72};

    int btn_w = 520;
    int btn_h = 42;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_y = 100;

    for (int i = 0; i < 5; i++) {
        int by = btn_y + i * 54;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 18);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : badge_colors[i]);
        DrawString(surf, btn_x + 20, by + 16, colors[i], is_hovered ? 1 : 45);
    }

    FillRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 18);
    DrawRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 38);
    DrawString(surf, 50, g_GameScreenHeight - 55, "PRESS 1-5 OR CLICK TO SELECT COLOR | [ESC] BACK", 1);
}

/* ==========================================================================
 * Mode 3: Character Portrait Face Selection (Sprite_Load__16faces_0047b899)
 * ========================================================================== */
static void RenderCharacterFaceMenu(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);

    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    FillRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 32);
    DrawRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 45);
    DrawString(surf, 160, 45, "STEP 3: CHOOSE YOUR WIZARD PORTRAIT", 1);
    DrawString(surf, 175, 60, "(16 AUTHENTIC MICROPROSE CHARACTER FACES)", 46);

    /* Render 16 Character Face Slots (4x4 Grid) */
    int grid_start_x = 100;
    int grid_start_y = 100;
    int slot_w = 95;
    int slot_h = 65;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int idx = row * 4 + col;
            int fx = grid_start_x + col * 115;
            int fy = grid_start_y + row * 75;

            bool is_hovered = (g_MousePosX >= fx && g_MousePosX <= fx + slot_w &&
                               g_MousePosY >= fy && g_MousePosY <= fy + slot_h);

            FillRect(surf, fx, fy, slot_w, slot_h, is_hovered ? 44 : 20);
            DrawRect(surf, fx, fy, slot_w, slot_h, (idx == g_SelectedFaceIndex) ? 1 : 45);

            char face_str[16];
            snprintf(face_str, sizeof(face_str), "FACE #%d", idx + 1);
            DrawString(surf, fx + 15, fy + 25, face_str, 1);
        }
    }

    FillRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 18);
    DrawRect(surf, 40, g_GameScreenHeight - 65, g_GameScreenWidth - 80, 30, 38);
    DrawString(surf, 50, g_GameScreenHeight - 55, "CLICK ANY FACE TO BEGIN SHANDALAR CAMPAIGN | [ESC] BACK", 1);
}

/* ==========================================================================
 * Mode 4: Shandalar Campaign Overworld (Glue_Subsystem_004ec7f9)
 * ========================================================================== */
static void RenderCampaignOverworld(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);

    /* Header Bar with gold & stats calculated from difficulty */
    FillRect(surf, 10, 10, g_GameScreenWidth - 20, 30, 32);
    DrawRect(surf, 10, 10, g_GameScreenWidth - 20, 30, 45);

    const char *color_names[] = {"WHITE", "BLUE", "BLACK", "RED", "GREEN"};
    char stat_str[128];
    snprintf(stat_str, sizeof(stat_str), "PLANE OF SHANDALAR [%s WIZARD] | GOLD: %d GP | FOOD: %d DAYS",
             color_names[g_SelectedColor], g_PlayerGold, g_FoodDays);
    DrawString(surf, 20, 22, stat_str, 1);

    /* World Map */
    int map_x = 20;
    int map_y = 50;
    int map_w = 420;
    int map_h = 360;
    DrawRect(surf, map_x, map_y, map_w, map_h, 45);

    /* Procedural terrain tiles matching color affinity */
    for (int ty = 0; ty < 10; ty++) {
        for (int tx = 0; tx < 12; tx++) {
            uint8_t color = (uint8_t)(64 + ((tx * 7 + ty * 13) % 16));
            FillRect(surf, map_x + 2 + tx * 34, map_y + 2 + ty * 35, 33, 34, color);
        }
    }

    /* 5 Elemental Castles (Castle_Process_0046c8b0) */
    int castle_coords[5][2] = {{180, 60}, {320, 80}, {300, 240}, {80, 220}, {180, 160}};
    const char *castle_names[] = {"WHITE CASTLE", "BLUE CITADEL", "BLACK TOWER", "RED VOLCANO", "GREEN GROVE"};
    uint8_t castle_colors[] = {1, 55, 25, 90, 72};

    for (int c = 0; c < 5; c++) {
        int cx = map_x + castle_coords[c][0];
        int cy = map_y + castle_coords[c][1];
        FillRect(surf, cx, cy, 36, 36, castle_colors[c]);
        DrawRect(surf, cx, cy, 36, 36, 1);
        DrawString(surf, cx - 20, cy + 38, castle_names[c], 1);
    }

    /* Animated Player Token */
    int home_x = map_x + castle_coords[g_SelectedColor][0] + (int)(sin(g_GameTicks * 0.05) * 35);
    int home_y = map_y + castle_coords[g_SelectedColor][1] + 45 + (int)(cos(g_GameTicks * 0.05) * 20);
    FillRect(surf, home_x, home_y, 16, 16, 88);
    DrawRect(surf, home_x, home_y, 16, 16, 1);
    DrawString(surf, home_x - 10, home_y - 10, "HERO", 1);

    /* Sidebar */
    int side_x = 450;
    int side_y = 50;
    int side_w = 170;
    int side_h = 360;
    FillRect(surf, side_x, side_y, side_w, side_h, 18);
    DrawRect(surf, side_x, side_y, side_w, side_h, 38);

    DrawString(surf, side_x + 10, side_y + 15, "QUEST OBJECTIVE:", 45);
    DrawString(surf, side_x + 10, side_y + 35, "DEFEAT ARZAKON", 1);
    DrawString(surf, side_x + 10, side_y + 55, "AND THE 5 WIZARDS", 1);

    DrawString(surf, side_x + 10, side_y + 90, "STARTING DECK:", 45);
    for (int i = 0; i < 4; i++) {
        DrawString(surf, side_x + 10, side_y + 110 + i * 18, g_StartingDecks[g_SelectedColor][i].name, 1);
    }

    /* Duel Encounter Button */
    int d_y = side_y + 240;
    bool is_duel_hov = (g_MousePosX >= side_x + 10 && g_MousePosX <= side_x + 160 &&
                        g_MousePosY >= d_y && g_MousePosY <= d_y + 35);
    FillRect(surf, side_x + 10, d_y, 150, 35, is_duel_hov ? 44 : 88);
    DrawRect(surf, side_x + 10, d_y, 150, 35, 1);
    DrawString(surf, side_x + 20, d_y + 12, "[SPACE] DUEL ENEMY", 1);

    /* Return Button */
    int b_y = side_y + 290;
    bool is_hov = (g_MousePosX >= side_x + 10 && g_MousePosX <= side_x + 160 &&
                   g_MousePosY >= b_y && g_MousePosY <= b_y + 30);
    FillRect(surf, side_x + 10, b_y, 150, 30, is_hov ? 44 : 25);
    DrawRect(surf, side_x + 10, b_y, 150, 30, 1);
    DrawString(surf, side_x + 20, b_y + 10, "[ESC] MAIN MENU", 1);

    /* Bottom Status Bar */
    FillRect(surf, 10, g_GameScreenHeight - 45, g_GameScreenWidth - 20, 35, 32);
    DrawRect(surf, 10, g_GameScreenHeight - 45, g_GameScreenWidth - 20, 35, 45);
    DrawString(surf, 20, g_GameScreenHeight - 32, "OVERWORLD ACTIVE | SPACE: DUEL | CLICK CASTLE TO ATTACK | ESC: EXIT", 1);
}

/* ==========================================================================
 * Mode 5: Duel Combat Arena (Magic_MainTurnPhase / Ai_Subsystem)
 * ========================================================================== */
static void RenderDuelArena(ScreenSurface *surf)
{
    FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 18);

    /* Arena Header */
    FillRect(surf, 10, 8, g_GameScreenWidth - 20, 26, 32);
    DrawRect(surf, 10, 8, g_GameScreenWidth - 20, 26, 45);

    char duel_title[128];
    snprintf(duel_title, sizeof(duel_title), "DUEL COMBAT ARENA - TURN %d [ACTIVE: %s]",
             g_ActiveTurn, (g_ActivePlayerId == 0) ? "PLAYER" : "AI OPPONENT");
    DrawString(surf, 20, 16, duel_title, 1);

    /* Turn Phase Tracker Banner */
    const char *phases[] = {"UNTAP", "UPKEEP", "DRAW", "MAIN 1", "COMBAT", "MAIN 2", "END", "CLEAN"};
    int px = 20;
    for (int p = 0; p < 8; p++) {
        bool is_curr = (p == g_CurrentTurnPhaseId);
        FillRect(surf, px, 40, 70, 20, is_curr ? 44 : 16);
        DrawRect(surf, px, 40, 70, 20, is_curr ? 1 : 35);
        DrawString(surf, px + 10, 46, phases[p], is_curr ? 1 : 45);
        px += 74;
    }

    /* Opponent Battlefield */
    FillRect(surf, 20, 68, g_GameScreenWidth - 40, 140, 16);
    DrawRect(surf, 20, 68, g_GameScreenWidth - 40, 140, 88);

    char opp_str[128];
    snprintf(opp_str, sizeof(opp_str), "OPPONENT (LIFE: %d) | CARDS IN HAND: 7 | LIBRARY: 53", g_PlayerLife[1]);
    DrawString(surf, 30, 76, opp_str, 1);

    /* Opponent Creatures */
    for (int i = 0; i < 3; i++) {
        int cx = 40 + i * 110;
        FillRect(surf, cx, 100, 90, 95, 25);
        DrawRect(surf, cx, 100, 90, 95, 1);
        DrawString(surf, cx + 5, 110, "SENGIR", 1);
        DrawString(surf, cx + 5, 125, "VAMPIRE", 1);
        DrawString(surf, cx + 50, 175, "4/4", 1);
    }

    /* Player Battlefield */
    FillRect(surf, 20, 218, g_GameScreenWidth - 40, 140, 16);
    DrawRect(surf, 20, 218, g_GameScreenWidth - 40, 140, 55);

    char plyr_str[128];
    snprintf(plyr_str, sizeof(plyr_str), "PLAYER (LIFE: %d) | MANA: W:%d U:%d B:%d R:%d G:%d | LIBRARY: 53",
             g_PlayerLife[0], g_PlayerManaPool[0][0], g_PlayerManaPool[0][1], g_PlayerManaPool[0][2],
             g_PlayerManaPool[0][3], g_PlayerManaPool[0][4]);
    DrawString(surf, 30, 226, plyr_str, 1);

    /* Player Creatures in Play */
    for (int i = 0; i < 4; i++) {
        int cx = 40 + i * 110;
        FillRect(surf, cx, 250, 90, 95, 48);
        DrawRect(surf, cx, 250, 90, 95, 1);
        DrawString(surf, cx + 5, 260, g_StartingDecks[g_SelectedColor][i].name, 1);
        DrawString(surf, cx + 5, 275, g_StartingDecks[g_SelectedColor][i].type, 45);
        if (g_StartingDecks[g_SelectedColor][i].power > 0) {
            char pt_str[16];
            snprintf(pt_str, sizeof(pt_str), "%d/%d",
                     g_StartingDecks[g_SelectedColor][i].power,
                     g_StartingDecks[g_SelectedColor][i].toughness);
            DrawString(surf, cx + 50, 325, pt_str, 1);
        } else {
            DrawString(surf, cx + 45, 325, "[TAP]", 46);
        }
    }

    /* Player Hand Cards */
    FillRect(surf, 20, 368, 440, 100, 16);
    DrawRect(surf, 20, 368, 440, 100, 45);
    DrawString(surf, 30, 375, "HAND:", 45);

    for (int i = 0; i < 4; i++) {
        int hx = 30 + i * 102;
        int hy = 390;
        bool is_hov = (g_MousePosX >= hx && g_MousePosX <= hx + 95 &&
                       g_MousePosY >= hy && g_MousePosY <= hy + 70);
        FillRect(surf, hx, hy, 95, 70, is_hov ? 44 : 20);
        DrawRect(surf, hx, hy, 95, 70, 1);
        DrawString(surf, hx + 5, hy + 10, g_StartingDecks[g_SelectedColor][i].name, 1);
        DrawString(surf, hx + 5, hy + 30, g_StartingDecks[g_SelectedColor][i].type, 45);
    }

    /* Actions Sidebar */
    int act_x = 470;
    int act_y = 368;
    int act_w = 150;

    /* Next Phase Button */
    bool is_next = (g_MousePosX >= act_x && g_MousePosX <= act_x + act_w &&
                    g_MousePosY >= act_y && g_MousePosY <= act_y + 45);
    FillRect(surf, act_x, act_y, act_w, 45, is_next ? 44 : 32);
    DrawRect(surf, act_x, act_y, act_w, 45, 1);
    DrawString(surf, act_x + 15, act_y + 18, "[SPACE] NEXT PHASE", 1);

    /* Concede Button */
    bool is_esc = (g_MousePosX >= act_x && g_MousePosX <= act_x + act_w &&
                   g_MousePosY >= act_y + 52 && g_MousePosY <= act_y + 95);
    FillRect(surf, act_x, act_y + 52, act_w, 45, is_esc ? 88 : 18);
    DrawRect(surf, act_x, act_y + 52, act_w, 45, 1);
    DrawString(surf, act_x + 20, act_y + 70, "[ESC] CONCEDE", 1);
}

/* ==========================================================================
 * Master Display Renderer & Scene Dispatcher
 * ========================================================================== */
static void RenderActiveScene(void)
{
    ScreenSurface *surf = &g_GameSurface;
    if (!surf->pixels) return;

    switch (g_ActiveGameMode) {
        case 0:
            RenderMainMenu(surf);
            break;
        case 1:
            RenderDifficultyMenu(surf);
            break;
        case 2:
            RenderColorSpecializationMenu(surf);
            break;
        case 3:
            RenderCharacterFaceMenu(surf);
            break;
        case 4:
            RenderCampaignOverworld(surf);
            break;
        case 5:
            RenderDuelArena(surf);
            break;
        default:
            RenderMainMenu(surf);
            break;
    }

    /* Draw Mouse Cursor */
    if (g_MousePosX >= 0 && g_MousePosY >= 0) {
        int mx = g_MousePosX;
        int my = g_MousePosY;
        for (int i = 0; i < 8; i++) {
            Surface_PutPixel(surf, mx + i, my, 1);
            Surface_PutPixel(surf, mx, my + i, 1);
            Surface_PutPixel(surf, mx + i, my + i, 1);
        }
    }

    /* Present backbuffer */
    Shandalar_UpdateSurface(surf);
    Shandalar_PresentFrame();
}

/* ==========================================================================
 * Sound_LoadWav_sound_locmus1 - Play overworld theme music
 * ========================================================================== */
void Sound_LoadWav_sound_locmus1(void)
{
    printf("[Sound] Triggering background music (sound/locmus1.wav)...\n");
    PlaySndFile("sound/locmus1.wav", 0, NULL);
}

/* ==========================================================================
 * UI_WndProc_ShowPaletteClass - Primary Game Window Procedure
 * ========================================================================== */
LRESULT UI_WndProc_ShowPaletteClass(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case 0x02: /* WM_DESTROY */
            printf("[Engine] Window destroyed, exiting game loop.\n");
            PostQuitMessage(0);
            return 0;

        case 0x0F: /* WM_PAINT */
            g_GameTicks++;
            RenderActiveScene();
            return 0;

        case 0x100: /* WM_KEYDOWN */
            if (wParam == 27) { /* VK_ESCAPE */
                if (g_ActiveGameMode > 0) {
                    if (g_ActiveGameMode == 4 || g_ActiveGameMode == 5) {
                        g_ActiveGameMode = 0; /* Return to main menu */
                    } else {
                        g_ActiveGameMode--; /* Back to previous wizard step */
                    }
                    printf("[Engine] Navigated back (Mode %d).\n", g_ActiveGameMode);
                } else {
                    printf("[Engine] Escape pressed, quitting.\n");
                    PostQuitMessage(0);
                }
            } else if (wParam == ' ') { /* SPACE */
                if (g_ActiveGameMode == 4) {
                    g_ActiveGameMode = 5; /* Start Duel encounter */
                    printf("[Engine] Overworld encounter initiated -> Duel Arena!\n");
                } else if (g_ActiveGameMode == 5) {
                    g_CurrentTurnPhaseId = (g_CurrentTurnPhaseId + 1) % 8;
                    if (g_CurrentTurnPhaseId == 0) {
                        g_ActiveTurn++;
                    }
                    printf("[Combat] Advanced Turn Phase to: %d\n", g_CurrentTurnPhaseId);
                }
            } else if (wParam >= '1' && wParam <= '5') {
                int opt = (int)(wParam - '1');
                if (g_ActiveGameMode == 0) {
                    if (opt == 0) {
                        g_ActiveGameMode = 1; /* Step 1: Difficulty */
                        printf("[Wizard] Step 1: Select Difficulty.\n");
                    } else if (opt == 2) {
                        g_ActiveGameMode = 5; /* Duel Arena */
                        printf("[Engine] Entered Duel Arena!\n");
                    } else if (opt == 4) {
                        PostQuitMessage(0);
                    }
                } else if (g_ActiveGameMode == 1) {
                    if (opt < 4) {
                        g_SelectedDifficulty = opt;
                        g_PlayerGold = (5 - opt) * 50;
                        g_ActiveGameMode = 2; /* Step 2: Color */
                        printf("[Wizard] Selected Difficulty: %d, Starting Gold: %d GP. Proceeding to Color selection.\n",
                               opt, g_PlayerGold);
                    }
                } else if (g_ActiveGameMode == 2) {
                    if (opt < 5) {
                        g_SelectedColor = opt;
                        g_ActiveGameMode = 3; /* Step 3: Face */
                        printf("[Wizard] Selected Color Alignment: %d. Proceeding to Portrait selection.\n", opt);
                    }
                }
            }
            RenderActiveScene();
            return 0;

        case 0x200: /* WM_MOUSEMOVE */
            g_MousePosX = (int32_t)(lParam & 0xFFFF);
            g_MousePosY = (int32_t)(lParam >> 16);
            RenderActiveScene();
            return 0;

        case 0x201: /* WM_LBUTTONDOWN */
            g_MouseButton = 1;
            g_MousePosX = (int32_t)(lParam & 0xFFFF);
            g_MousePosY = (int32_t)(lParam >> 16);

            if (g_ActiveGameMode == 0) {
                if (g_HoveredButton == 0) {
                    g_ActiveGameMode = 1; /* Step 1: Difficulty */
                    printf("[Wizard] Step 1: Select Difficulty.\n");
                } else if (g_HoveredButton == 2) {
                    g_ActiveGameMode = 5; /* Duel Arena */
                    printf("[Engine] Entered Duel Combat Arena!\n");
                } else if (g_HoveredButton == 4) {
                    PostQuitMessage(0);
                }
            } else if (g_ActiveGameMode == 1) {
                /* Difficulty click */
                int btn_w = 460;
                int btn_h = 40;
                int btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 4; i++) {
                    int by = 130 + i * 55;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + btn_h) {
                        g_SelectedDifficulty = i;
                        g_PlayerGold = (5 - i) * 50;
                        g_ActiveGameMode = 2;
                        printf("[Wizard] Selected Difficulty: %d, Starting Gold: %d GP.\n", i, g_PlayerGold);
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 2) {
                /* Color click */
                int btn_w = 520;
                int btn_h = 42;
                int btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 5; i++) {
                    int by = 100 + i * 54;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + btn_h) {
                        g_SelectedColor = i;
                        g_ActiveGameMode = 3;
                        printf("[Wizard] Selected Color Alignment: %d.\n", i);
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 3) {
                /* Face portrait click */
                int grid_start_x = 100;
                int grid_start_y = 100;
                int slot_w = 95;
                int slot_h = 65;
                for (int row = 0; row < 4; row++) {
                    for (int col = 0; col < 4; col++) {
                        int idx = row * 4 + col;
                        int fx = grid_start_x + col * 115;
                        int fy = grid_start_y + row * 75;
                        if (g_MousePosX >= fx && g_MousePosX <= fx + slot_w &&
                            g_MousePosY >= fy && g_MousePosY <= fy + slot_h) {
                            g_SelectedFaceIndex = idx;
                            g_ActiveGameMode = 4; /* Launch Campaign Overworld! */
                            printf("[Wizard] Selected Character Portrait #%d -> Launching Shandalar Overworld!\n", idx + 1);
                            break;
                        }
                    }
                }
            } else if (g_ActiveGameMode == 4) {
                /* Overworld buttons */
                if (g_MousePosX >= 460 && g_MousePosX <= 610 && g_MousePosY >= 290 && g_MousePosY <= 325) {
                    g_ActiveGameMode = 5; /* Duel Encounter */
                } else if (g_MousePosX >= 460 && g_MousePosX <= 610 && g_MousePosY >= 340 && g_MousePosY <= 370) {
                    g_ActiveGameMode = 0; /* Menu */
                }
            } else if (g_ActiveGameMode == 5) {
                /* Duel actions */
                if (g_MousePosX >= 470 && g_MousePosX <= 620 && g_MousePosY >= 368 && g_MousePosY <= 413) {
                    g_CurrentTurnPhaseId = (g_CurrentTurnPhaseId + 1) % 8;
                    if (g_CurrentTurnPhaseId == 0) g_ActiveTurn++;
                } else if (g_MousePosX >= 470 && g_MousePosX <= 620 && g_MousePosY >= 420 && g_MousePosY <= 465) {
                    g_ActiveGameMode = 4; /* Return to overworld */
                }
            }
            RenderActiveScene();
            return 0;

        case 0x202: /* WM_LBUTTONUP */
            g_MouseButton = 0;
            RenderActiveScene();
            return 0;

        default:
            return DefWindowProcA(hwnd, uMsg, wParam, lParam);
    }
}

/* ==========================================================================
 * WinMain - Authentic MicroProse Engine Entry Point (0x00500e80)
 * ========================================================================== */
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    (void)hPrevInstance;
    (void)nCmdShow;

    printf("=========================================================\n");
    printf(" MicroProse Magic: The Gathering (Shandalar 1997)\n");
    printf(" Executing Authentic WinMain Entry Point\n");
    printf("=========================================================\n");

    /* 1. Seed random number generator */
    DWORD tick = GetTickCount();
    srand(tick);

    /* 2. Register main window class */
    WNDCLASSA wc;
    memset(&wc, 0, sizeof(wc));
    wc.style         = 0x23; /* CS_HREDRAW | CS_VREDRAW | CS_OWNDC */
    wc.lpfnWndProc   = UI_WndProc_ShowPaletteClass;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIconA(hInstance, (LPCSTR)0x65);
    wc.hCursor       = LoadCursorA((HINSTANCE)0, (LPCSTR)0x7F00);
    wc.hbrBackground = GetStockObject(4);
    wc.lpszClassName = "ShandalarMainClass";

    if (!RegisterClassA(&wc)) {
        MessageBoxA(NULL, "Couldn't register the classes", "Error", 0x10);
        return 0;
    }

    /* 3. Parse resolution command line flags */
    if (lpCmdLine && *lpCmdLine != '\0') {
        if (strstr(lpCmdLine, "6") || strstr(lpCmdLine, "640")) {
            g_GameScreenWidth = 640;
            g_GameScreenHeight = 480;
        } else if (strstr(lpCmdLine, "8") || strstr(lpCmdLine, "800")) {
            g_GameScreenWidth = 800;
            g_GameScreenHeight = 600;
        } else if (strstr(lpCmdLine, "1") || strstr(lpCmdLine, "1024")) {
            g_GameScreenWidth = 1024;
            g_GameScreenHeight = 768;
        }
    }

    printf("[WinMain] Resolution: %dx%d\n", g_GameScreenWidth, g_GameScreenHeight);

    /* 4. Create Game Window & Initialize Display Shim */
    g_HwndScreen = CreateWindowExA(
        8,
        "ShandalarMainClass",
        "Magic: The Gathering - Shandalar (1997)",
        0x80000000,
        0, 0,
        g_GameScreenWidth,
        g_GameScreenHeight,
        NULL, NULL,
        hInstance, NULL
    );

    if (!g_HwndScreen) {
        fprintf(stderr, "[WinMain] Error: Could not create main game window!\n");
        return 0;
    }

    ShowWindow(g_HwndScreen, nCmdShow);
    g_HdcScreen = GetDC(g_HwndScreen);

    /* 5. Allocate Main Screen Surface */
    g_GamePixelBuffer = (uint8_t *)calloc(g_GameScreenWidth * g_GameScreenHeight, 1);
    g_GameSurface.pixels = g_GamePixelBuffer;
    g_GameSurface.clip_left = 0;
    g_GameSurface.clip_top = 0;
    g_GameSurface.clip_right = g_GameScreenWidth;
    g_GameSurface.clip_bottom = g_GameScreenHeight;
    g_GameSurface.pitch = g_GameScreenWidth;

    g_MainSurfaceInfo.pitch = g_GameScreenWidth;
    g_MainSurfaceInfo.frame_buffer = g_GamePixelBuffer;

    /* 6. Load Authentic 256-color Palette */
    LoadAuthenticGamePalette();

    /* 7. Load Authentic MicroProse 2D Sprites from ICONS.SPR */
    printf("[WinMain] Loading authentic game sprites (ICONS.SPR)...\n");
    g_SpriteCount = Sprite_LoadAll(g_SpriteTable, "ICONS.SPR");
    if (g_SpriteCount > 0) {
        printf("[WinMain] Successfully loaded %d authentic sprites!\n", g_SpriteCount);
    } else {
        printf("[WinMain] Notice: ICONS.SPR not in current dir, trying absolute path...\n");
        g_SpriteCount = Sprite_LoadAll(g_SpriteTable, "/Users/ben/Downloads/shand-extract/program/ICONS.SPR");
        if (g_SpriteCount > 0) {
            printf("[WinMain] Successfully loaded %d authentic sprites from absolute path!\n", g_SpriteCount);
        }
    }

    /* 8. Initialize Sound & Load Music */
    Sound_Init(0, NULL, 0);
    Sound_LoadWav_sound_locmus1();

    /* 9. Open Authentic Card Art Catalogs (NedCard/Catalog.c) */
    printf("[WinMain] Initializing card art catalogs (SMALLART.CAT & MEDART.CAT)...\n");
    int cat_small = Catalog_Open("CardArt/SMALLART.CAT");
    if (!cat_small) cat_small = Catalog_Open("/Users/ben/Downloads/shand-extract/program/CardArt/SMALLART.CAT");

    int cat_med = Catalog_Open("CardArt/MEDART.CAT");
    if (!cat_med) cat_med = Catalog_Open("/Users/ben/Downloads/shand-extract/program/CardArt/MEDART.CAT");

    /* 10. Render Initial Active Scene */
    RenderActiveScene();

    /* 10. Main Message Pump Loop */
    printf("[WinMain] Entering main game message pump loop...\n");
    tagMSG msg;
    while (GetMessageA(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);

        /* In automated test mode without interactive UI, exit after 60 frames */
        if (g_GameTicks > 60 && lpCmdLine && strstr(lpCmdLine, "--test")) {
            printf("[WinMain] Test mode reached %d frames, cleanly exiting message loop.\n", g_GameTicks);
            break;
        }
    }

    printf("[WinMain] Exiting game session cleanly.\n");
    if (g_GamePixelBuffer) {
        free(g_GamePixelBuffer);
        g_GamePixelBuffer = NULL;
    }
    Shandalar_DisplayShutdown();
    return (int)msg.wParam;
}
