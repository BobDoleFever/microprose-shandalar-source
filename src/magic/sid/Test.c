/*
 * sid/Test.c - MicroProse Magic: The Gathering (Shandalar 1997) Main Engine & Authentic Game Loops
 * Original Authors: Sid Meier & Ned Way
 * Reconstructed ANSI C Implementation of the Authentic Shandalar Adventure Game
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
static void RenderActiveScene(void);

/* Engine globals */
static int  g_GameScreenWidth  = 640;
static int  g_GameScreenHeight = 480;
static HWND g_HwndScreen       = NULL;
static HDC  g_HdcScreen        = NULL;

/* Main Game 8-bit Framebuffer Surface */
static ScreenSurface g_GameSurface = {0};
static uint8_t      *g_GamePixelBuffer = NULL;

/* 2D Sprite Tables & Backdrops */
static void *g_SpriteTable[256] = {0};
static int   g_SpriteCount = 0;

/* Authentic PCX Backdrops */
static PicImage *g_PicAdvInter = NULL;
static PicImage *g_PicCityInfo = NULL;
static PicImage *g_PicBuyCards = NULL;
static PicImage *g_PicCaveBkgd = NULL;
static PicImage *g_PicMenuBak  = NULL;

/* Mouse and Input state */
int32_t g_MousePosX   = 0;
int32_t g_MousePosY   = 0;
int32_t g_MouseButton = 0;

/*
 * Authentic Game State Machine:
 * 0: Main Menu (TITLE.PIC / MENUBAK.PIC)
 * 1: Difficulty Selection (MENU2-HI.PIC)
 * 2: Color Specialization / Starting Deck (MENU3.PIC)
 * 3: Character Face Selection (ADVFAC64.PIC / 16FACES.SPR)
 * 4: SHANDALAR CAMPAIGN OVERWORLD ADVENTURE (ADVINTER.pic) - DEFAULT
 * 5: DUEL COMBAT ARENA (MAGIC.PIC)
 * 6: TOWN / CITY VIEW (CITYINFO.PIC)
 * 7: CARD BAZAAR (BUYCARDS.PIC)
 * 8: DUNGEON CRAWL (CAVEBKGD.PIC)
 */
static int g_ActiveGameMode = 4; /* Defaults directly to Shandalar Adventure Mode! */
static int g_GameTicks = 0;

/* Character & Campaign Configuration */
static int g_SelectedDifficulty = 0; /* 0 = Apprentice, 1 = Mage, 2 = Archmage, 3 = Wizard */
static int g_SelectedColor      = 0; /* 0 = White, 1 = Blue, 2 = Black, 3 = Red, 4 = Green */
static int g_SelectedFaceIndex  = 0; /* 0..15 face portrait index */
static int g_PlayerGold         = 250;
static int g_FoodDays           = 14;
static int g_PlayerHp           = 20;
static int g_PlayerMaxHp        = 20;
static int g_DayCount           = 1;
static int g_TravelSteps        = 0;
static int g_ActiveTownId       = 0;
static int g_ActiveDungeonId    = 0;
static int g_ActiveDungeonFloor = 1;
static char g_NotificationText[128] = "WELCOME TO SHANDALAR! EXPLORE THE OVERWORLD, VISIT TOWNS & DEFEAT WIZARDS.";

/* Elemental Mana Links */
static int g_ManaLinks[5] = {1, 0, 0, 0, 0}; /* W, U, B, R, G */

/* Card Record Structure */
typedef struct CardEntry {
    int  id;
    char name[32];
    char type[32];
    int  cost_color;
    int  cost_amount;
    int  power;
    int  toughness;
    int  gold_price;
} CardEntry;

/* Authentic 40-card starting deck profiles by color */
static CardEntry g_StartingDecks[5][7] = {
    /* 0: White */
    {
        {0, "Serra Angel",      "Summon Angel",     0, 5, 4, 4, 120},
        {1, "Benalish Hero",    "Summon Hero",      0, 1, 1, 1, 30},
        {2, "Swords to Plowshares","Instant",       0, 1, 0, 0, 60},
        {3, "Disenchant",       "Instant",          0, 2, 0, 0, 45},
        {4, "Healing Salve",    "Instant",          0, 1, 0, 0, 20},
        {5, "Holy Strength",    "Enchant Creature", 0, 1, 0, 0, 35},
        {6, "Plains",           "Basic Land",       0, 0, 0, 0, 10}
    },
    /* 1: Blue */
    {
        {0, "Air Elemental",    "Summon Elemental", 1, 5, 4, 4, 110},
        {1, "Prodigal Sorcerer","Summon Wizard",    1, 3, 1, 1, 50},
        {2, "Ancestral Recall", "Instant",          1, 1, 0, 0, 250},
        {3, "Counterspell",     "Instant",          1, 2, 0, 0, 75},
        {4, "Unsummon",         "Instant",          1, 1, 0, 0, 25},
        {5, "Control Magic",    "Enchant Creature", 1, 4, 0, 0, 90},
        {6, "Island",           "Basic Land",       1, 0, 0, 0, 10}
    },
    /* 2: Black */
    {
        {0, "Sengir Vampire",   "Summon Vampire",   2, 5, 4, 4, 130},
        {1, "Black Knight",     "Summon Knight",    2, 2, 2, 2, 55},
        {2, "Dark Ritual",      "Mana Source",      2, 1, 0, 0, 40},
        {3, "Terror",           "Instant",          2, 2, 0, 0, 50},
        {4, "Drain Life",       "Sorcery",          2, 2, 0, 0, 45},
        {5, "Unholy Strength",  "Enchant Creature", 2, 1, 0, 0, 35},
        {6, "Swamp",            "Basic Land",       2, 0, 0, 0, 10}
    },
    /* 3: Red */
    {
        {0, "Shivan Dragon",    "Summon Dragon",    3, 6, 5, 5, 180},
        {1, "Goblin Balloon",   "Summon Goblins",   3, 1, 1, 1, 35},
        {2, "Lightning Bolt",   "Instant",          3, 1, 0, 0, 65},
        {3, "Fireball",         "Sorcery",          3, 1, 0, 0, 80},
        {4, "Stone Rain",       "Sorcery",          3, 3, 0, 0, 40},
        {5, "Dragon Whelp",     "Summon Dragon",    3, 4, 2, 3, 75},
        {6, "Mountain",         "Basic Land",       3, 0, 0, 0, 10}
    },
    /* 4: Green */
    {
        {0, "Force of Nature",  "Summon Force",     4, 6, 8, 8, 160},
        {1, "Llanowar Elves",   "Summon Elf",       4, 1, 1, 1, 40},
        {2, "Giant Growth",     "Instant",          4, 1, 0, 0, 30},
        {3, "Birds of Paradise","Summon Mana Bird", 4, 1, 0, 1, 120},
        {4, "Tranquility",      "Sorcery",          4, 3, 0, 0, 35},
        {5, "Craw Wurm",        "Summon Wurm",      4, 6, 6, 4, 70},
        {6, "Forest",           "Basic Land",       4, 0, 0, 0, 10}
    }
};

/* Bazaar Inventory Stock */
static CardEntry g_BazaarStock[6] = {
    {10, "Black Lotus",     "Artifact Mana",    5, 0, 0, 0, 300},
    {11, "Mox Sapphire",    "Artifact Mana",    1, 0, 0, 0, 200},
    {12, "Time Walk",       "Sorcery",          1, 2, 0, 0, 220},
    {13, "Sol Ring",        "Artifact",         5, 1, 0, 0, 140},
    {14, "Hypnotic Specter","Summon Specter",   2, 3, 2, 2, 95},
    {15, "Armageddon",      "Sorcery",          0, 4, 0, 0, 110}
};

/* ==========================================================================
 * Overworld Campaign Simulation Data
 * ========================================================================== */

#define WORLD_MAP_SIZE 64

enum TerrainType {
    TERRAIN_OCEAN    = 0,
    TERRAIN_PLAINS   = 1,
    TERRAIN_FOREST   = 2,
    TERRAIN_MOUNTAIN = 3,
    TERRAIN_SWAMP    = 4,
    TERRAIN_DESERT   = 5,
    TERRAIN_ROAD     = 6,
    TERRAIN_TOWN     = 7,
    TERRAIN_CASTLE   = 8,
    TERRAIN_DUNGEON  = 9
};

static uint8_t g_WorldMap[WORLD_MAP_SIZE][WORLD_MAP_SIZE];
static bool    g_WorldMapGenerated = false;

/* Player World Coordinates */
static int g_PlayerTileX = 32;
static int g_PlayerTileY = 32;
static int g_PlayerFacing = 0; /* 0: East, 1: South, 2: West, 3: North */

/* 5 Elemental Castles */
typedef struct CastleLocation {
    const char *name;
    const char *wizard;
    int x;
    int y;
    int color;
    bool defeated;
} CastleLocation;

static CastleLocation g_Castles[5] = {
    {"White Castle",  "High Priestess Kiera", 32, 14, 0, false},
    {"Blue Citadel",  "Archmage Dunraith",    50, 20, 1, false},
    {"Black Tower",   "Lich Lord Volkan",     46, 48, 2, false},
    {"Red Volcano",   "Warlord Ramaz",        16, 44, 3, false},
    {"Green Grove",   "Druid Patriarch Guy",  16, 20, 4, false}
};

/* 8 Towns & Cities */
typedef struct TownLocation {
    const char *name;
    const char *ruler;
    int x;
    int y;
    int color;
} TownLocation;

static TownLocation g_Towns[8] = {
    {"Sylvan Glen",     "Elder Arwen",       24, 22, 4},
    {"Stonehaven",      "Mayor Kenneth",     34, 26, 0},
    {"Port Aven",       "Captain Drake",     44, 24, 1},
    {"Oasis of Karoo",  "Sheikh Malik",      22, 36, 3},
    {"Ironhold",        "Smith Voran",       28, 42, 3},
    {"Whispering Bog",  "Witch Morgana",     38, 44, 2},
    {"Sunburst",        "Justiciar Elaine",  32, 32, 0},
    {"Frostpeak",       "Hermit Thorne",     48, 32, 1}
};

/* 5 Ancient Dungeons */
typedef struct DungeonLocation {
    const char *name;
    const char *boss;
    int x;
    int y;
    int max_floors;
    bool cleared;
} DungeonLocation;

static DungeonLocation g_Dungeons[5] = {
    {"Tomb of the Lich",    "Nether Lich",       42, 50, 3, false},
    {"Cave of the Dragon",  "Elder Red Dragon",  14, 48, 3, false},
    {"Sunken Vault",        "Leviathan",         54, 28, 3, false},
    {"Forest Crypt",        "Autumn Willow",     12, 16, 3, false},
    {"Volcanic Abyss",      "Balduvian Demon",   20, 52, 3, false}
};

/* Roaming Wandering Monsters */
typedef struct RoamingMonster {
    const char *name;
    int x;
    int y;
    int color;
    int hp;
    bool active;
} RoamingMonster;

static RoamingMonster g_Monsters[6] = {
    {"Goblin Raider",    28, 30, 3, 12, true},
    {"Elvish Archer",    36, 28, 4, 14, true},
    {"Vampire Stalker",  26, 38, 2, 16, true},
    {"Sea Serpent",      46, 36, 1, 18, true},
    {"Zealot Knight",    30, 24, 0, 15, true},
    {"Mountain Dragon",  18, 40, 3, 20, true}
};

/* Deobfuscated Core Duel Engine State */
int32_t g_PlayerLife[2] = {20, 20};
int32_t g_ActiveTurn = 1;
int32_t g_ActivePlayerId = 0;
int32_t g_CurrentTurnPhaseId = 3; /* 0: Untap, 1: Upkeep, 2: Draw, 3: Main 1, 4: Combat, 5: Main 2, 6: End, 7: Cleanup */
int32_t g_CurrentStepCode[2][6] = {{0}}; /* W, U, B, R, G, C */

/* Surface Info and Globals for 2D Sprite blitter */
static SurfaceInfo g_MainSurfaceInfo = {0};
SurfaceInfo* g_ScreenSurfaces[4] = { &g_MainSurfaceInfo, &g_MainSurfaceInfo, &g_MainSurfaceInfo, &g_MainSurfaceInfo };

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
 * World Map Procedural Generation
 * ========================================================================== */
static void GenerateWorldMap(void)
{
    if (g_WorldMapGenerated) return;

    for (int y = 0; y < WORLD_MAP_SIZE; y++) {
        for (int x = 0; x < WORLD_MAP_SIZE; x++) {
            if (x < 3 || x >= WORLD_MAP_SIZE - 3 || y < 3 || y >= WORLD_MAP_SIZE - 3) {
                g_WorldMap[y][x] = TERRAIN_OCEAN;
                continue;
            }

            float dx = (float)(x - 32);
            float dy = (float)(y - 32);
            float dist = sqrtf(dx * dx + dy * dy);

            if (dist > 28.0f) {
                g_WorldMap[y][x] = TERRAIN_OCEAN;
            } else if (dist > 24.0f) {
                g_WorldMap[y][x] = (uint8_t)(((x + y) % 3 == 0) ? TERRAIN_PLAINS : TERRAIN_OCEAN);
            } else {
                if (y < 22 && x < 28) {
                    g_WorldMap[y][x] = TERRAIN_FOREST;
                } else if (y < 22 && x >= 28) {
                    g_WorldMap[y][x] = TERRAIN_PLAINS;
                } else if (y >= 22 && y < 38 && x < 28) {
                    g_WorldMap[y][x] = TERRAIN_DESERT;
                } else if (y >= 22 && y < 38 && x >= 38) {
                    g_WorldMap[y][x] = TERRAIN_PLAINS;
                } else if (y >= 38 && x >= 32) {
                    g_WorldMap[y][x] = TERRAIN_SWAMP;
                } else if (y >= 38 && x < 32) {
                    g_WorldMap[y][x] = TERRAIN_MOUNTAIN;
                } else {
                    g_WorldMap[y][x] = TERRAIN_PLAINS;
                }
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        g_WorldMap[g_Castles[i].y][g_Castles[i].x] = TERRAIN_CASTLE;
    }

    for (int i = 0; i < 8; i++) {
        g_WorldMap[g_Towns[i].y][g_Towns[i].x] = TERRAIN_TOWN;
    }

    for (int i = 0; i < 5; i++) {
        g_WorldMap[g_Dungeons[i].y][g_Dungeons[i].x] = TERRAIN_DUNGEON;
    }

    g_WorldMapGenerated = true;
    printf("[Adventure] Procedural Shandalar world map generated successfully (64x64)!\n");
}

/* ==========================================================================
 * Load Authentic Palette from ADVINTER.pic / TITLE.PIC
 * ========================================================================== */
static void LoadAuthenticGamePalette(void)
{
    uint32_t palette[256];
    memset(palette, 0, sizeof(palette));

    if (g_PicAdvInter && g_PicAdvInter->has_palette) {
        for (int i = 0; i < 256; i++) {
            uint8_t r = g_PicAdvInter->palette[i * 3 + 0];
            uint8_t g = g_PicAdvInter->palette[i * 3 + 1];
            uint8_t b = g_PicAdvInter->palette[i * 3 + 2];
            palette[i] = 0xFF000000U | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
        }
        Shandalar_SetPalette(palette);
        printf("[DisplayShim] Applied authentic 256-color palette from ADVINTER.pic!\n");
        return;
    }

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
        ['!'] = {0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x00},
        [','] = {0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x30},
        ['?'] = {0x3C,0x66,0x0C,0x18,0x18,0x00,0x18,0x00},
        ['|'] = {0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00},
        ['+'] = {0x00,0x18,0x18,0x7E,0x18,0x18,0x00,0x00},
        ['>'] = {0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00},
        ['<'] = {0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x00},
        [' '] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    };

    uint8_t uc = (uint8_t)c;
    if (uc >= 'a' && uc <= 'z') uc -= 32;
    if (uc >= 128) uc = '?';
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

static void Surface_FillRect(ScreenSurface *surf, int x, int y, int w, int h, uint8_t color)
{
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            Surface_PutPixel(surf, x + i, y + j, color);
        }
    }
}

/* ==========================================================================
 * Mode 4: Shandalar Campaign Overworld Adventure (ADVINTER.pic)
 * ========================================================================== */
static void RenderCampaignOverworld(ScreenSurface *surf)
{
    GenerateWorldMap();

    /* 1. Render Authentic Frame or Fallback */
    if (g_PicAdvInter) {
        Pic_Draw(surf, 0, 0, g_PicAdvInter);
    } else {
        Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);
        DrawRect(surf, 2, 2, g_GameScreenWidth - 4, g_GameScreenHeight - 4, 45);
    }

    /* 2. Overworld Viewport Coordinates (Inner Frame) */
    int view_x = 16;
    int view_y = 38;
    int view_w = 440;
    int view_h = 370;

    int tile_size = 28;
    int tiles_x = view_w / tile_size + 2;
    int tiles_y = view_h / tile_size + 2;

    int start_tx = g_PlayerTileX - tiles_x / 2;
    int start_ty = g_PlayerTileY - tiles_y / 2;

    /* Render Terrain Grid */
    for (int ty = 0; ty < tiles_y; ty++) {
        for (int tx = 0; tx < tiles_x; tx++) {
            int map_x = start_tx + tx;
            int map_y = start_ty + ty;

            int px = view_x + tx * tile_size;
            int py = view_y + ty * tile_size;

            uint8_t terrain = TERRAIN_OCEAN;
            if (map_x >= 0 && map_x < WORLD_MAP_SIZE && map_y >= 0 && map_y < WORLD_MAP_SIZE) {
                terrain = g_WorldMap[map_y][map_x];
            }

            uint8_t t_color = 48;
            switch (terrain) {
                case TERRAIN_OCEAN:    t_color = 50; break;
                case TERRAIN_PLAINS:   t_color = 66; break;
                case TERRAIN_FOREST:   t_color = 70; break;
                case TERRAIN_MOUNTAIN: t_color = 20; break;
                case TERRAIN_SWAMP:    t_color = 24; break;
                case TERRAIN_DESERT:   t_color = 36; break;
                case TERRAIN_TOWN:     t_color = 40; break;
                case TERRAIN_CASTLE:   t_color = 1;  break;
                case TERRAIN_DUNGEON:  t_color = 18; break;
                default:               t_color = 66; break;
            }

            if (px + tile_size <= view_x + view_w && py + tile_size <= view_y + view_h) {
                Surface_FillRect(surf, px, py, tile_size - 1, tile_size - 1, t_color);

                /* Landmarks Rendering */
                if (terrain == TERRAIN_CASTLE) {
                    Surface_FillRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 88);
                    DrawRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 1);
                    DrawChar(surf, px + 8, py + 8, 'C', 1);
                } else if (terrain == TERRAIN_TOWN) {
                    Surface_FillRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 34);
                    DrawRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 45);
                    DrawChar(surf, px + 8, py + 8, 'T', 1);
                } else if (terrain == TERRAIN_DUNGEON) {
                    Surface_FillRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 2);
                    DrawRect(surf, px + 4, py + 4, tile_size - 9, tile_size - 9, 88);
                    DrawChar(surf, px + 8, py + 8, 'D', 88);
                }
            }
        }
    }

    /* 3. Render Roaming Monsters */
    for (int m = 0; m < 6; m++) {
        if (!g_Monsters[m].active) continue;
        int m_rel_x = g_Monsters[m].x - start_tx;
        int m_rel_y = g_Monsters[m].y - start_ty;
        if (m_rel_x >= 0 && m_rel_x < tiles_x && m_rel_y >= 0 && m_rel_y < tiles_y) {
            int mpx = view_x + m_rel_x * tile_size;
            int mpy = view_y + m_rel_y * tile_size;
            if (mpx + 20 <= view_x + view_w && mpy + 20 <= view_y + view_h) {
                Surface_FillRect(surf, mpx + 4, mpy + 4, 18, 18, 88);
                DrawRect(surf, mpx + 4, mpy + 4, 18, 18, 1);
                DrawChar(surf, mpx + 9, mpy + 9, 'M', 1);
            }
        }
    }

    /* 4. Render Player Hero Token (Center of Viewport) */
    int hero_px = view_x + (view_w / 2) - 10;
    int hero_py = view_y + (view_h / 2) - 10;
    uint8_t hero_colors[] = {1, 55, 25, 90, 72};
    Surface_FillRect(surf, hero_px, hero_py, 20, 20, hero_colors[g_SelectedColor]);
    DrawRect(surf, hero_px, hero_py, 20, 20, 1);
    DrawChar(surf, hero_px + 6, hero_py + 6, 'H', (g_SelectedColor == 0) ? 2 : 1);

    /* 5. Viewport Outer Border */
    DrawRect(surf, view_x, view_y, view_w, view_h, 45);

    /* 6. Top Status Bar */
    Surface_FillRect(surf, 16, 6, g_GameScreenWidth - 32, 26, 32);
    DrawRect(surf, 16, 6, g_GameScreenWidth - 32, 26, 45);

    const char *color_names[] = {"WHITE", "BLUE", "BLACK", "RED", "GREEN"};
    const char *headings[] = {"EAST", "SOUTH", "WEST", "NORTH"};
    char stat_str[128];
    snprintf(stat_str, sizeof(stat_str), "SHANDALAR [%s WIZARD] | HP:%d/%d | GOLD:%d GP | FOOD:%d DAYS | DAY %d",
             color_names[g_SelectedColor], g_PlayerHp, g_PlayerMaxHp, g_PlayerGold, g_FoodDays, g_DayCount);
    DrawString(surf, 24, 14, stat_str, 1);

    /* 7. Right Sidebar HUD & Controls */
    int side_x = 466;
    int side_y = 38;
    int side_w = 158;
    int side_h = 370;

    Surface_FillRect(surf, side_x, side_y, side_w, side_h, 18);
    DrawRect(surf, side_x, side_y, side_w, side_h, 38);

    DrawString(surf, side_x + 10, side_y + 12, "COMPASS HEADING:", 45);
    DrawString(surf, side_x + 10, side_y + 28, headings[g_PlayerFacing], 1);

    DrawString(surf, side_x + 10, side_y + 50, "ACTIVE QUEST:", 45);
    DrawString(surf, side_x + 10, side_y + 68, "HUNT ROAMING", 1);
    DrawString(surf, side_x + 10, side_y + 84, "GOBLIN RAIDER", 88);

    DrawString(surf, side_x + 10, side_y + 112, "MANA LINKS:", 45);
    char mana_str[64];
    snprintf(mana_str, sizeof(mana_str), "W:%d U:%d B:%d R:%d G:%d",
             g_ManaLinks[0], g_ManaLinks[1], g_ManaLinks[2], g_ManaLinks[3], g_ManaLinks[4]);
    DrawString(surf, side_x + 10, side_y + 130, mana_str, 1);

    DrawString(surf, side_x + 10, side_y + 155, "ADVENTURE KEYS:", 45);
    DrawString(surf, side_x + 10, side_y + 175, "ARROWS / WASD: MOVE", 1);
    DrawString(surf, side_x + 10, side_y + 195, "CLICK MAP: WALK", 1);
    DrawString(surf, side_x + 10, side_y + 215, "SPACE: DUEL ARENA", 1);
    DrawString(surf, side_x + 10, side_y + 235, "T: ENTER TOWN", 1);
    DrawString(surf, side_x + 10, side_y + 255, "B: CARD BAZAAR", 1);
    DrawString(surf, side_x + 10, side_y + 275, "D: DUNGEON CRAWL", 1);
    DrawString(surf, side_x + 10, side_y + 295, "M / ESC: MENU", 1);

    /* Quick Action Button */
    Surface_FillRect(surf, side_x + 10, side_y + 325, side_w - 20, 32, 32);
    DrawRect(surf, side_x + 10, side_y + 325, side_w - 20, 32, 45);
    DrawString(surf, side_x + 16, side_y + 336, "[SPACE] DUEL ARENA", 1);

    /* 8. Bottom Notification Bar */
    Surface_FillRect(surf, 16, g_GameScreenHeight - 60, g_GameScreenWidth - 32, 46, 32);
    DrawRect(surf, 16, g_GameScreenHeight - 60, g_GameScreenWidth - 32, 46, 45);
    DrawString(surf, 24, g_GameScreenHeight - 48, g_NotificationText, 1);
    DrawString(surf, 24, g_GameScreenHeight - 30, "TRAVEL STEPPING CONSUMES FOOD | REACH CASTLES & TOWNS TO GAIN CARDS & GOLD", 43);
}

/* ==========================================================================
 * Mode 6: Town / City View (CITYINFO.PIC)
 * ========================================================================== */
static void RenderTownScreen(ScreenSurface *surf)
{
    if (g_PicCityInfo) {
        Pic_Draw(surf, 0, 0, g_PicCityInfo);
    } else {
        Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 18);
        DrawRect(surf, 4, 4, g_GameScreenWidth - 8, g_GameScreenHeight - 8, 45);
    }

    Surface_FillRect(surf, 30, 20, g_GameScreenWidth - 60, 50, 32);
    DrawRect(surf, 30, 20, g_GameScreenWidth - 60, 50, 45);

    char town_title[128];
    snprintf(town_title, sizeof(town_title), "WELCOME TO %s - PROVINCE OF SHANDALAR", g_Towns[g_ActiveTownId].name);
    DrawString(surf, 50, 34, town_title, 1);
    DrawString(surf, 50, 50, "TOWN SQUARE & TRADING OUTPOST", 46);

    const char *town_options[] = {
        "[1] VISIT CARD BAZAAR (BUY & SELL MAGIC CARDS)",
        "[2] VISIT INN & TAVERN (BUY FOOD: +10 DAYS FOR 10 GP)",
        "[3] VISIT HEALER (RESTORE FULL HP FOR 25 GP)",
        "[4] BOUNTY OFFICE (ACCEPT QUEST: HUNT MONSTER FOR 100 GP)",
        "[ESC] LEAVE TOWN & RETURN TO OVERWORLD"
    };

    int btn_w = 520;
    int btn_h = 42;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_y = 100;

    for (int i = 0; i < 5; i++) {
        int by = btn_y + i * 54;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        Surface_FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 20);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 45);
        DrawString(surf, btn_x + 20, by + 16, town_options[i], is_hovered ? 1 : 45);
    }

    Surface_FillRect(surf, 30, g_GameScreenHeight - 65, g_GameScreenWidth - 60, 35, 32);
    DrawRect(surf, 30, g_GameScreenHeight - 65, g_GameScreenWidth - 60, 35, 45);
    char footer_str[128];
    snprintf(footer_str, sizeof(footer_str), "GOLD: %d GP | FOOD: %d DAYS | LIFE: %d/%d | PRESS 1-4 OR CLICK",
             g_PlayerGold, g_FoodDays, g_PlayerHp, g_PlayerMaxHp);
    DrawString(surf, 45, g_GameScreenHeight - 52, footer_str, 1);
}

/* ==========================================================================
 * Mode 7: Card Bazaar (BUYCARDS.PIC)
 * ========================================================================== */
static void RenderCardBazaar(ScreenSurface *surf)
{
    if (g_PicBuyCards) {
        Pic_Draw(surf, 0, 0, g_PicBuyCards);
    } else {
        Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);
        DrawRect(surf, 4, 4, g_GameScreenWidth - 8, g_GameScreenHeight - 8, 45);
    }

    Surface_FillRect(surf, 30, 16, g_GameScreenWidth - 60, 44, 32);
    DrawRect(surf, 30, 16, g_GameScreenWidth - 60, 44, 45);
    DrawString(surf, 50, 26, "SHANDALAR CARD BAZAAR - ACQUIRE POWERFUL SPELLS", 1);
    DrawString(surf, 50, 42, "SELECT A CARD TO PURCHASE WITH GOLD", 46);

    int grid_x = 40;
    int grid_y = 75;
    int card_w = 175;
    int card_h = 150;

    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            int idx = row * 3 + col;
            int cx = grid_x + col * 190;
            int cy = grid_y + row * 165;

            bool is_hov = (g_MousePosX >= cx && g_MousePosX <= cx + card_w &&
                           g_MousePosY >= cy && g_MousePosY <= cy + card_h);

            Surface_FillRect(surf, cx, cy, card_w, card_h, is_hov ? 44 : 20);
            DrawRect(surf, cx, cy, card_w, card_h, is_hov ? 1 : 45);

            char num_str[32];
            snprintf(num_str, sizeof(num_str), "[%d] %s", idx + 1, g_BazaarStock[idx].name);
            DrawString(surf, cx + 8, cy + 12, num_str, 1);
            DrawString(surf, cx + 8, cy + 32, g_BazaarStock[idx].type, 45);

            char cost_str[32];
            snprintf(cost_str, sizeof(cost_str), "MANA COST: %d", g_BazaarStock[idx].cost_amount);
            DrawString(surf, cx + 8, cy + 60, cost_str, 1);

            char price_str[32];
            snprintf(price_str, sizeof(price_str), "PRICE: %d GP", g_BazaarStock[idx].gold_price);
            DrawString(surf, cx + 8, cy + 90, price_str, (g_PlayerGold >= g_BazaarStock[idx].gold_price) ? 40 : 88);

            DrawString(surf, cx + 8, cy + 120, "CLICK TO BUY", is_hov ? 1 : 43);
        }
    }

    Surface_FillRect(surf, 30, g_GameScreenHeight - 50, g_GameScreenWidth - 60, 35, 32);
    DrawRect(surf, 30, g_GameScreenHeight - 50, g_GameScreenWidth - 60, 35, 45);
    char footer[128];
    snprintf(footer, sizeof(footer), "PLAYER GOLD: %d GP | PRESS 1-6 OR CLICK TO PURCHASE | [ESC] BACK TO TOWN", g_PlayerGold);
    DrawString(surf, 40, g_GameScreenHeight - 38, footer, 1);
}

/* ==========================================================================
 * Mode 8: Dungeon Crawl (CAVEBKGD.PIC)
 * ========================================================================== */
static void RenderDungeonScreen(ScreenSurface *surf)
{
    if (g_PicCaveBkgd) {
        Pic_Draw(surf, 0, 0, g_PicCaveBkgd);
    } else {
        Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 18);
        DrawRect(surf, 4, 4, g_GameScreenWidth - 8, g_GameScreenHeight - 8, 45);
    }

    Surface_FillRect(surf, 30, 20, g_GameScreenWidth - 60, 50, 32);
    DrawRect(surf, 30, 20, g_GameScreenWidth - 60, 50, 45);

    char dung_title[128];
    snprintf(dung_title, sizeof(dung_title), "%s - FLOOR %d OF %d",
             g_Dungeons[g_ActiveDungeonId].name, g_ActiveDungeonFloor, g_Dungeons[g_ActiveDungeonId].max_floors);
    DrawString(surf, 50, 34, dung_title, 88);
    DrawString(surf, 50, 50, "SUBTERRANEAN CAVERN OF ANCIENT POWER", 1);

    const char *dung_options[] = {
        "[1] EXPLORE DEEPER INTO CAVERN (ENCOUNTER GUARDIAN)",
        "[2] LOOT TREASURE CHEST (GAIN ARTIFACT CARDS & GOLD)",
        "[3] REST AT CAMPFIRE (RESTORE 5 HP, CONSUME 1 FOOD)",
        "[ESC] RETREAT TO OVERWORLD"
    };

    int btn_w = 520;
    int btn_h = 42;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_y = 110;

    for (int i = 0; i < 4; i++) {
        int by = btn_y + i * 56;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        Surface_FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 20);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 45);
        DrawString(surf, btn_x + 20, by + 16, dung_options[i], is_hovered ? 1 : 45);
    }

    Surface_FillRect(surf, 30, g_GameScreenHeight - 65, g_GameScreenWidth - 60, 35, 32);
    DrawRect(surf, 30, g_GameScreenHeight - 65, g_GameScreenWidth - 60, 35, 45);
    char footer[128];
    snprintf(footer, sizeof(footer), "HP: %d/%d | GOLD: %d GP | FOOD: %d DAYS | GUARDIAN: %s",
             g_PlayerHp, g_PlayerMaxHp, g_PlayerGold, g_FoodDays, g_Dungeons[g_ActiveDungeonId].boss);
    DrawString(surf, 45, g_GameScreenHeight - 52, footer, 1);
}

/* ==========================================================================
 * Mode 5: Duel Combat Arena
 * ========================================================================== */
static void RenderDuelArena(ScreenSurface *surf)
{
    Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 18);

    /* Arena Header */
    Surface_FillRect(surf, 10, 8, g_GameScreenWidth - 20, 26, 32);
    DrawRect(surf, 10, 8, g_GameScreenWidth - 20, 26, 45);

    const char *color_names[] = {"WHITE", "BLUE", "BLACK", "RED", "GREEN"};
    char duel_title[128];
    snprintf(duel_title, sizeof(duel_title), "DUEL COMBAT ARENA - TURN %d [ACTIVE: %s]",
             g_ActiveTurn, (g_ActivePlayerId == 0) ? "PLAYER" : "OPPONENT");
    DrawString(surf, 20, 16, duel_title, 1);

    /* Turn Phase Tracker Banner */
    const char *phases[] = {"UNTAP", "UPKEEP", "DRAW", "MAIN 1", "COMBAT", "MAIN 2", "END", "CLEAN"};
    int px = 20;
    for (int p = 0; p < 8; p++) {
        bool is_curr = (p == g_CurrentTurnPhaseId);
        Surface_FillRect(surf, px, 40, 70, 20, is_curr ? 44 : 16);
        DrawRect(surf, px, 40, 70, 20, is_curr ? 1 : 35);
        DrawString(surf, px + 10, 46, phases[p], is_curr ? 1 : 45);
        px += 74;
    }

    /* Opponent Battlefield */
    Surface_FillRect(surf, 20, 68, g_GameScreenWidth - 40, 135, 16);
    DrawRect(surf, 20, 68, g_GameScreenWidth - 40, 135, 88);

    char opp_str[128];
    snprintf(opp_str, sizeof(opp_str), "OPPONENT (LIFE: %d) | CARDS IN HAND: 5 | LIBRARY: 45", g_PlayerLife[1]);
    DrawString(surf, 30, 78, opp_str, 88);

    /* Opponent Creatures in Play */
    DrawString(surf, 30, 100, "OPPONENT CREATURES IN PLAY:", 45);
    Surface_FillRect(surf, 30, 118, 90, 60, 24);
    DrawRect(surf, 30, 118, 90, 60, 1);
    DrawString(surf, 35, 126, "DRAGON", 1);
    DrawString(surf, 35, 144, "5/5 FLYING", 88);

    Surface_FillRect(surf, 130, 118, 90, 60, 24);
    DrawRect(surf, 130, 118, 90, 60, 1);
    DrawString(surf, 135, 126, "GOBLIN", 1);
    DrawString(surf, 135, 144, "2/2 ATTACK", 88);

    /* Player Battlefield */
    Surface_FillRect(surf, 20, 212, g_GameScreenWidth - 40, 145, 16);
    DrawRect(surf, 20, 212, g_GameScreenWidth - 40, 145, 45);

    char play_str[128];
    snprintf(play_str, sizeof(play_str), "PLAYER [%s] (LIFE: %d) | MANA POOL [W:%d U:%d B:%d R:%d G:%d]",
             color_names[g_SelectedColor], g_PlayerLife[0],
             g_ManaLinks[0], g_ManaLinks[1], g_ManaLinks[2], g_ManaLinks[3], g_ManaLinks[4]);
    DrawString(surf, 30, 222, play_str, 1);

    for (int i = 0; i < 2; i++) {
        int cx = 30 + i * 105;
        Surface_FillRect(surf, cx, 242, 95, 65, 34);
        DrawRect(surf, cx, 242, 95, 65, 1);
        DrawString(surf, cx + 6, 252, g_StartingDecks[g_SelectedColor][i].name, 1);
        char pt_str[32];
        snprintf(pt_str, sizeof(pt_str), "%d/%d CREATURE",
                 g_StartingDecks[g_SelectedColor][i].power, g_StartingDecks[g_SelectedColor][i].toughness);
        DrawString(surf, cx + 6, 272, pt_str, 40);
    }

    /* Player Hand */
    DrawString(surf, 20, 368, "PLAYER HAND:", 45);
    for (int i = 0; i < 4; i++) {
        int hx = 20 + i * 105;
        int hy = 388;
        bool is_hov = (g_MousePosX >= hx && g_MousePosX <= hx + 95 &&
                       g_MousePosY >= hy && g_MousePosY <= hy + 75);
        Surface_FillRect(surf, hx, hy, 95, 75, is_hov ? 44 : 20);
        DrawRect(surf, hx, hy, 95, 75, 1);
        DrawString(surf, hx + 5, hy + 10, g_StartingDecks[g_SelectedColor][i + 2].name, 1);
        DrawString(surf, hx + 5, hy + 30, g_StartingDecks[g_SelectedColor][i + 2].type, 45);
        char cost[32];
        snprintf(cost, sizeof(cost), "COST: %d", g_StartingDecks[g_SelectedColor][i + 2].cost_amount);
        DrawString(surf, hx + 5, hy + 50, cost, 1);
    }

    /* Actions Sidebar */
    int act_x = 460;
    int act_y = 368;
    int act_w = 160;

    bool is_next = (g_MousePosX >= act_x && g_MousePosX <= act_x + act_w &&
                    g_MousePosY >= act_y && g_MousePosY <= act_y + 45);
    Surface_FillRect(surf, act_x, act_y, act_w, 45, is_next ? 44 : 32);
    DrawRect(surf, act_x, act_y, act_w, 45, 1);
    DrawString(surf, act_x + 15, act_y + 18, "[SPACE] ADVANCE PHASE", 1);

    bool is_esc = (g_MousePosX >= act_x && g_MousePosX <= act_x + act_w &&
                   g_MousePosY >= act_y + 52 && g_MousePosY <= act_y + 95);
    Surface_FillRect(surf, act_x, act_y + 52, act_w, 45, is_esc ? 88 : 18);
    DrawRect(surf, act_x, act_y + 52, act_w, 45, 1);
    DrawString(surf, act_x + 15, act_y + 70, "[ESC] RETURN TO MAP", 1);
}

/* ==========================================================================
 * Mode 0: Main Menu
 * ========================================================================== */
static void RenderMainMenu(ScreenSurface *surf)
{
    if (g_PicMenuBak) {
        Pic_Draw(surf, 0, 0, g_PicMenuBak);
    } else {
        Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 0);
        DrawRect(surf, 4, 4, g_GameScreenWidth - 8, g_GameScreenHeight - 8, 40);
    }

    Surface_FillRect(surf, 20, 20, g_GameScreenWidth - 40, 60, 34);
    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, 60, 45);
    DrawString(surf, 120, 32, "MICROPROSE MAGIC: THE GATHERING", 1);
    DrawString(surf, 180, 52, "AUTHENTIC SHANDALAR ENGINE (1997)", 46);

    const char *menu_options[] = {
        "[1] RESUME / ENTER SHANDALAR ADVENTURE",
        "[2] NEW GAME (CHARACTER CREATION WIZARD)",
        "[3] DUEL / GAUNTLET BATTLE",
        "[4] VISIT CARD BAZAAR",
        "[5] EXIT TO SYSTEM"
    };

    int btn_w = 460;
    int btn_h = 36;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_start_y = 180;

    for (int i = 0; i < 5; i++) {
        int by = btn_start_y + i * 46;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        Surface_FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 18);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 38);
        DrawString(surf, btn_x + 30, by + 14, menu_options[i], is_hovered ? 1 : 45);
    }

    Surface_FillRect(surf, 20, g_GameScreenHeight - 35, g_GameScreenWidth - 40, 20, 16);
    DrawRect(surf, 20, g_GameScreenHeight - 35, g_GameScreenWidth - 40, 20, 35);
    DrawString(surf, 30, g_GameScreenHeight - 28, "PRESS 1-5 OR CLICK | DIRECT ADVENTURE BOOT ACTIVE", 43);
}

/* ==========================================================================
 * Mode 1: Difficulty Selection
 * ========================================================================== */
static void RenderDifficultyMenu(ScreenSurface *surf)
{
    Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);
    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    Surface_FillRect(surf, 40, 40, g_GameScreenWidth - 80, 50, 32);
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

        Surface_FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 18);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 38);
        DrawString(surf, btn_x + 20, by + 16, diff_names[i], is_hovered ? 1 : 45);
    }
}

/* ==========================================================================
 * Mode 2: Color Specialization
 * ========================================================================== */
static void RenderColorSpecializationMenu(ScreenSurface *surf)
{
    Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);
    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    Surface_FillRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 32);
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

    int btn_w = 520;
    int btn_h = 42;
    int btn_x = (g_GameScreenWidth - btn_w) / 2;
    int btn_y = 100;

    for (int i = 0; i < 5; i++) {
        int by = btn_y + i * 54;
        bool is_hovered = (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                           g_MousePosY >= by && g_MousePosY <= by + btn_h);

        Surface_FillRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 44 : 18);
        DrawRect(surf, btn_x, by, btn_w, btn_h, is_hovered ? 1 : 45);
        DrawString(surf, btn_x + 20, by + 16, colors[i], is_hovered ? 1 : 45);
    }
}

/* ==========================================================================
 * Mode 3: Character Face Selection
 * ========================================================================== */
static void RenderCharacterFaceMenu(ScreenSurface *surf)
{
    Surface_FillRect(surf, 0, 0, g_GameScreenWidth, g_GameScreenHeight, 16);
    DrawRect(surf, 20, 20, g_GameScreenWidth - 40, g_GameScreenHeight - 40, 45);

    Surface_FillRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 32);
    DrawRect(surf, 40, 30, g_GameScreenWidth - 80, 50, 45);
    DrawString(surf, 160, 45, "STEP 3: CHOOSE YOUR WIZARD PORTRAIT", 1);
    DrawString(surf, 175, 60, "(16 AUTHENTIC MICROPROSE CHARACTER FACES)", 46);

    int grid_start_x = 100;
    int grid_start_y = 100;
    int slot_w = 95;
    int slot_h = 65;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            int idx = row * 4 + col;
            int fx = grid_start_x + col * 115;
            int fy = grid_start_y + row * 75;

            Surface_FillRect(surf, fx, fy, slot_w, slot_h, 20);
            DrawRect(surf, fx, fy, slot_w, slot_h, 45);

            char face_str[16];
            snprintf(face_str, sizeof(face_str), "FACE #%d", idx + 1);
            DrawString(surf, fx + 15, fy + 25, face_str, 1);
        }
    }
}

/* ==========================================================================
 * Master Display Renderer & Scene Dispatcher
 * ========================================================================== */
static void RenderActiveScene(void)
{
    ScreenSurface *surf = &g_GameSurface;
    if (!surf->pixels) return;

    switch (g_ActiveGameMode) {
        case 0: RenderMainMenu(surf); break;
        case 1: RenderDifficultyMenu(surf); break;
        case 2: RenderColorSpecializationMenu(surf); break;
        case 3: RenderCharacterFaceMenu(surf); break;
        case 4: RenderCampaignOverworld(surf); break;
        case 5: RenderDuelArena(surf); break;
        case 6: RenderTownScreen(surf); break;
        case 7: RenderCardBazaar(surf); break;
        case 8: RenderDungeonScreen(surf); break;
        default: RenderCampaignOverworld(surf); break;
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
 * Overworld Player Movement & Action Handler
 * ========================================================================== */
static void MovePlayer(int dx, int dy)
{
    int nx = g_PlayerTileX + dx;
    int ny = g_PlayerTileY + dy;

    if (dx > 0) g_PlayerFacing = 0;
    else if (dy > 0) g_PlayerFacing = 1;
    else if (dx < 0) g_PlayerFacing = 2;
    else if (dy < 0) g_PlayerFacing = 3;

    if (nx >= 0 && nx < WORLD_MAP_SIZE && ny >= 0 && ny < WORLD_MAP_SIZE) {
        uint8_t t = g_WorldMap[ny][nx];
        if (t != TERRAIN_OCEAN && t != TERRAIN_MOUNTAIN) {
            g_PlayerTileX = nx;
            g_PlayerTileY = ny;
            g_TravelSteps++;

            /* Food consumption: 1 food day per 10 travel steps */
            if (g_TravelSteps % 10 == 0) {
                if (g_FoodDays > 0) {
                    g_FoodDays--;
                } else {
                    g_PlayerHp = (g_PlayerHp > 1) ? g_PlayerHp - 1 : 1;
                    snprintf(g_NotificationText, sizeof(g_NotificationText), "STARVATION! NO FOOD LEFT, LOST 1 LIFE POINT!");
                }
            }

            /* Day count progression */
            if (g_TravelSteps % 20 == 0) {
                g_DayCount++;
            }

            /* Check Landmarks */
            if (t == TERRAIN_TOWN) {
                for (int i = 0; i < 8; i++) {
                    if (g_Towns[i].x == nx && g_Towns[i].y == ny) {
                        g_ActiveTownId = i;
                        g_ActiveGameMode = 6; /* Enter Town Screen */
                        snprintf(g_NotificationText, sizeof(g_NotificationText), "ENTERED TOWN OF %s!", g_Towns[i].name);
                        printf("[Adventure] Entered Town: %s\n", g_Towns[i].name);
                        return;
                    }
                }
            } else if (t == TERRAIN_DUNGEON) {
                for (int i = 0; i < 5; i++) {
                    if (g_Dungeons[i].x == nx && g_Dungeons[i].y == ny) {
                        g_ActiveDungeonId = i;
                        g_ActiveDungeonFloor = 1;
                        g_ActiveGameMode = 8; /* Enter Dungeon */
                        snprintf(g_NotificationText, sizeof(g_NotificationText), "ENTERED DUNGEON: %s!", g_Dungeons[i].name);
                        printf("[Adventure] Entered Dungeon: %s\n", g_Dungeons[i].name);
                        return;
                    }
                }
            } else if (t == TERRAIN_CASTLE) {
                for (int i = 0; i < 5; i++) {
                    if (g_Castles[i].x == nx && g_Castles[i].y == ny) {
                        g_ActiveGameMode = 5; /* Duel Castle Wizard */
                        snprintf(g_NotificationText, sizeof(g_NotificationText), "CHALLENGING CASTLE WIZARD: %s!", g_Castles[i].wizard);
                        printf("[Adventure] Challenging Castle Wizard: %s\n", g_Castles[i].wizard);
                        return;
                    }
                }
            }

            /* Check Roaming Monster Collisions */
            for (int m = 0; m < 6; m++) {
                if (g_Monsters[m].active && g_Monsters[m].x == nx && g_Monsters[m].y == ny) {
                    g_ActiveGameMode = 5; /* Start Duel with Monster */
                    snprintf(g_NotificationText, sizeof(g_NotificationText), "INTERCEPTED BY %s! DUEL COMMENCING!", g_Monsters[m].name);
                    printf("[Adventure] Monster Encounter: %s!\n", g_Monsters[m].name);
                    return;
                }
            }
        }
    }
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
            PostQuitMessage(0);
            return 0;

        case 0x0F: /* WM_PAINT */
            g_GameTicks++;
            RenderActiveScene();
            return 0;

        case 0x100: /* WM_KEYDOWN */
            if (wParam == 27) { /* VK_ESCAPE */
                if (g_ActiveGameMode == 4) {
                    g_ActiveGameMode = 0; /* Return to Main Menu */
                } else if (g_ActiveGameMode == 6 || g_ActiveGameMode == 7 || g_ActiveGameMode == 8 || g_ActiveGameMode == 5) {
                    g_ActiveGameMode = 4; /* Return to Overworld Adventure */
                } else if (g_ActiveGameMode > 0) {
                    g_ActiveGameMode--;
                } else {
                    PostQuitMessage(0);
                }
            } else if (g_ActiveGameMode == 4) {
                /* Overworld Movement Keys */
                if (wParam == VK_UP || wParam == 'W' || wParam == 'w') MovePlayer(0, -1);
                else if (wParam == VK_DOWN || wParam == 'S' || wParam == 's') MovePlayer(0, 1);
                else if (wParam == VK_LEFT || wParam == 'A' || wParam == 'a') MovePlayer(-1, 0);
                else if (wParam == VK_RIGHT || wParam == 'D' || wParam == 'd') MovePlayer(1, 0);
                else if (wParam == ' ') { g_ActiveGameMode = 5; }
                else if (wParam == 'T' || wParam == 't') { g_ActiveGameMode = 6; }
                else if (wParam == 'B' || wParam == 'b') { g_ActiveGameMode = 7; }
                else if (wParam == 'M' || wParam == 'm') { g_ActiveGameMode = 0; }
            } else if (g_ActiveGameMode == 6) {
                /* Town Options */
                if (wParam == '1') { g_ActiveGameMode = 7; }
                else if (wParam == '2') {
                    if (g_PlayerGold >= 10) { g_PlayerGold -= 10; g_FoodDays += 10; snprintf(g_NotificationText, sizeof(g_NotificationText), "PURCHASED 10 FOOD RATIONS!"); }
                } else if (wParam == '3') {
                    if (g_PlayerGold >= 25) { g_PlayerGold -= 25; g_PlayerHp = g_PlayerMaxHp; snprintf(g_NotificationText, sizeof(g_NotificationText), "HEALED TO FULL LIFE!"); }
                } else if (wParam == '4') {
                    snprintf(g_NotificationText, sizeof(g_NotificationText), "ACCEPTED QUEST: HUNT GOBLIN RAIDER FOR 100 GP!");
                }
            } else if (g_ActiveGameMode == 7) {
                /* Bazaar Purchases */
                if (wParam >= '1' && wParam <= '6') {
                    int b_idx = (int)(wParam - '1');
                    if (g_PlayerGold >= g_BazaarStock[b_idx].gold_price) {
                        g_PlayerGold -= g_BazaarStock[b_idx].gold_price;
                        snprintf(g_NotificationText, sizeof(g_NotificationText), "PURCHASED %s!", g_BazaarStock[b_idx].name);
                    }
                }
            } else if (g_ActiveGameMode == 5) {
                /* Duel Controls */
                if (wParam == ' ') {
                    g_CurrentTurnPhaseId = (g_CurrentTurnPhaseId + 1) % 8;
                    if (g_CurrentTurnPhaseId == 0) {
                        g_ActiveTurn++;
                        g_PlayerLife[1] -= 2;
                        if (g_PlayerLife[1] <= 0) {
                            g_PlayerGold += 75;
                            g_ActiveGameMode = 4;
                            snprintf(g_NotificationText, sizeof(g_NotificationText), "VICTORY IN DUEL! REWARDED 75 GP!");
                        }
                    }
                }
            } else if (g_ActiveGameMode == 0) {
                if (wParam == '1') { g_ActiveGameMode = 4; }
                else if (wParam == '2') { g_ActiveGameMode = 1; }
                else if (wParam == '3') { g_ActiveGameMode = 5; }
                else if (wParam == '4') { g_ActiveGameMode = 7; }
                else if (wParam == '5') { PostQuitMessage(0); }
            } else if (g_ActiveGameMode == 1) {
                if (wParam >= '1' && wParam <= '4') {
                    g_SelectedDifficulty = (int)(wParam - '1');
                    g_PlayerGold = (5 - g_SelectedDifficulty) * 50;
                    g_ActiveGameMode = 2;
                }
            } else if (g_ActiveGameMode == 2) {
                if (wParam >= '1' && wParam <= '5') {
                    g_SelectedColor = (int)(wParam - '1');
                    g_ActiveGameMode = 3;
                }
            } else if (g_ActiveGameMode == 3) {
                g_ActiveGameMode = 4;
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

            if (g_ActiveGameMode == 4) {
                if (g_MousePosX >= 16 && g_MousePosX <= 456 && g_MousePosY >= 38 && g_MousePosY <= 408) {
                    int clicked_tx = (g_MousePosX - 16) / 28;
                    int clicked_ty = (g_MousePosY - 38) / 28;
                    int center_tx = (440 / 28) / 2;
                    int center_ty = (370 / 28) / 2;
                    int dx = (clicked_tx > center_tx) ? 1 : (clicked_tx < center_tx ? -1 : 0);
                    int dy = (clicked_ty > center_ty) ? 1 : (clicked_ty < center_ty ? -1 : 0);
                    MovePlayer(dx, dy);
                } else if (g_MousePosX >= 476 && g_MousePosX <= 614 && g_MousePosY >= 363 && g_MousePosY <= 395) {
                    g_ActiveGameMode = 5; /* Duel Arena */
                }
            } else if (g_ActiveGameMode == 6) {
                int btn_w = 520;
                int btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 5; i++) {
                    int by = 100 + i * 54;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + 42) {
                        if (i == 0) g_ActiveGameMode = 7;
                        else if (i == 1 && g_PlayerGold >= 10) { g_PlayerGold -= 10; g_FoodDays += 10; snprintf(g_NotificationText, sizeof(g_NotificationText), "PURCHASED 10 FOOD RATIONS!"); }
                        else if (i == 2 && g_PlayerGold >= 25) { g_PlayerGold -= 25; g_PlayerHp = g_PlayerMaxHp; snprintf(g_NotificationText, sizeof(g_NotificationText), "HEALED TO FULL LIFE!"); }
                        else if (i == 3) { snprintf(g_NotificationText, sizeof(g_NotificationText), "ACCEPTED QUEST: HUNT GOBLIN RAIDER FOR 100 GP!"); }
                        else if (i == 4) { g_ActiveGameMode = 4; }
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 7) {
                int grid_x = 40, grid_y = 75, card_w = 175, card_h = 150;
                for (int row = 0; row < 2; row++) {
                    for (int col = 0; col < 3; col++) {
                        int idx = row * 3 + col;
                        int cx = grid_x + col * 190;
                        int cy = grid_y + row * 165;
                        if (g_MousePosX >= cx && g_MousePosX <= cx + card_w &&
                            g_MousePosY >= cy && g_MousePosY <= cy + card_h) {
                            if (g_PlayerGold >= g_BazaarStock[idx].gold_price) {
                                g_PlayerGold -= g_BazaarStock[idx].gold_price;
                                snprintf(g_NotificationText, sizeof(g_NotificationText), "PURCHASED %s!", g_BazaarStock[idx].name);
                            }
                            break;
                        }
                    }
                }
            } else if (g_ActiveGameMode == 8) {
                int btn_w = 520, btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 4; i++) {
                    int by = 110 + i * 56;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + 42) {
                        if (i == 0) { g_ActiveGameMode = 5; }
                        else if (i == 1) { g_PlayerGold += 50; snprintf(g_NotificationText, sizeof(g_NotificationText), "LOOTED 50 GP FROM DUNGEON CHEST!"); }
                        else if (i == 2) { if (g_FoodDays > 0) { g_FoodDays--; g_PlayerHp = (g_PlayerHp + 5 <= g_PlayerMaxHp) ? g_PlayerHp + 5 : g_PlayerMaxHp; } }
                        else if (i == 3) { g_ActiveGameMode = 4; }
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 5) {
                if (g_MousePosX >= 460 && g_MousePosX <= 620 && g_MousePosY >= 368 && g_MousePosY <= 413) {
                    g_CurrentTurnPhaseId = (g_CurrentTurnPhaseId + 1) % 8;
                    if (g_CurrentTurnPhaseId == 0) {
                        g_ActiveTurn++;
                        g_PlayerLife[1] -= 2;
                        if (g_PlayerLife[1] <= 0) {
                            g_PlayerGold += 75;
                            g_ActiveGameMode = 4;
                            snprintf(g_NotificationText, sizeof(g_NotificationText), "VICTORY IN DUEL! REWARDED 75 GP!");
                        }
                    }
                } else if (g_MousePosX >= 460 && g_MousePosX <= 620 && g_MousePosY >= 420 && g_MousePosY <= 465) {
                    g_ActiveGameMode = 4;
                }
            } else if (g_ActiveGameMode == 0) {
                int btn_w = 460, btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 5; i++) {
                    int by = 180 + i * 46;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + 36) {
                        if (i == 0) g_ActiveGameMode = 4;
                        else if (i == 1) g_ActiveGameMode = 1;
                        else if (i == 2) g_ActiveGameMode = 5;
                        else if (i == 3) g_ActiveGameMode = 7;
                        else if (i == 4) PostQuitMessage(0);
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 1) {
                int btn_w = 460, btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 4; i++) {
                    int by = 130 + i * 55;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + 40) {
                        g_SelectedDifficulty = i;
                        g_PlayerGold = (5 - i) * 50;
                        g_ActiveGameMode = 2;
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 2) {
                int btn_w = 520, btn_x = (g_GameScreenWidth - btn_w) / 2;
                for (int i = 0; i < 5; i++) {
                    int by = 100 + i * 54;
                    if (g_MousePosX >= btn_x && g_MousePosX <= btn_x + btn_w &&
                        g_MousePosY >= by && g_MousePosY <= by + 42) {
                        g_SelectedColor = i;
                        g_ActiveGameMode = 3;
                        break;
                    }
                }
            } else if (g_ActiveGameMode == 3) {
                g_ActiveGameMode = 4;
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
    printf(" Executing Authentic Shandalar Adventure Game\n");
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

    /* 3. Parse command line flags */
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
        if (strstr(lpCmdLine, "--menu") || strstr(lpCmdLine, "/mode:menu")) {
            g_ActiveGameMode = 0;
        } else if (strstr(lpCmdLine, "--duel") || strstr(lpCmdLine, "/mode:duel")) {
            g_ActiveGameMode = 5;
        } else if (strstr(lpCmdLine, "--town") || strstr(lpCmdLine, "/mode:town")) {
            g_ActiveGameMode = 6;
        } else if (strstr(lpCmdLine, "--bazaar") || strstr(lpCmdLine, "/mode:bazaar")) {
            g_ActiveGameMode = 7;
        }
    }

    printf("[WinMain] Resolution: %dx%d | Active Game Mode: %d (Shandalar Adventure)\n",
           g_GameScreenWidth, g_GameScreenHeight, g_ActiveGameMode);

    /* 4. Create Game Window & Initialize Display Shim */
    g_HwndScreen = CreateWindowExA(
        8,
        "ShandalarMainClass",
        "Magic: The Gathering - Shandalar Adventure (1997)",
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

    /* 6. Load Authentic PCX Backdrops */
    printf("[WinMain] Loading authentic game backdrops (.PIC)...\n");
    g_PicAdvInter = Pic_LoadFile("ADVINTER.pic");
    if (!g_PicAdvInter) g_PicAdvInter = Pic_LoadFile("advinter800.pic");
    g_PicCityInfo = Pic_LoadFile("CITYINFO.PIC");
    if (!g_PicCityInfo) g_PicCityInfo = Pic_LoadFile("village.pic");
    g_PicBuyCards = Pic_LoadFile("BUYCARDS.PIC");
    g_PicCaveBkgd = Pic_LoadFile("CAVEBKGD.PIC");
    g_PicMenuBak  = Pic_LoadFile("MENUBAK.PIC");
    if (!g_PicMenuBak) g_PicMenuBak = Pic_LoadFile("TITLE.PIC");

    /* 7. Load Authentic 256-color Palette */
    LoadAuthenticGamePalette();

    /* 8. Load Authentic MicroProse 2D Sprites */
    printf("[WinMain] Loading authentic game sprites (ICONS.SPR)...\n");
    g_SpriteCount = Sprite_LoadAll(g_SpriteTable, "ICONS.SPR");
    if (g_SpriteCount <= 0) {
        g_SpriteCount = Sprite_LoadAll(g_SpriteTable, "/Users/ben/Downloads/shand-extract/program/ICONS.SPR");
    }
    printf("[WinMain] Loaded %d authentic MicroProse sprites.\n", g_SpriteCount);

    /* 9. Generate Procedural Adventure World Map */
    GenerateWorldMap();

    /* 10. Initialize Sound & Music */
    Sound_Init(0, NULL, 0);
    Sound_LoadWav_sound_locmus1();

    /* 11. Render Initial Adventure Scene */
    RenderActiveScene();

    /* 12. Main Message Pump Loop */
    printf("[WinMain] Entering Shandalar Adventure main message pump loop...\n");
    tagMSG msg;
    bool is_test = (lpCmdLine && strstr(lpCmdLine, "--test") != NULL);

    while (1) {
        if (is_test) {
            if (PeekMessageA(&msg, NULL, 0, 0, 1)) {
                if (msg.message == 0x12) break; /* WM_QUIT */
                TranslateMessage(&msg);
                DispatchMessageA(&msg);
            }
            g_GameTicks++;
            RenderActiveScene();
            if (g_GameTicks >= 60) {
                printf("[WinMain] Test mode reached %d frames, cleanly exiting message loop.\n", g_GameTicks);
                break;
            }
        } else {
            if (!GetMessageA(&msg, NULL, 0, 0)) break;
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }

    printf("[WinMain] Exiting game session cleanly.\n");
    if (g_PicAdvInter) Pic_Free(g_PicAdvInter);
    if (g_PicCityInfo) Pic_Free(g_PicCityInfo);
    if (g_PicBuyCards) Pic_Free(g_PicBuyCards);
    if (g_PicCaveBkgd) Pic_Free(g_PicCaveBkgd);
    if (g_PicMenuBak)  Pic_Free(g_PicMenuBak);

    if (g_GamePixelBuffer) {
        free(g_GamePixelBuffer);
        g_GamePixelBuffer = NULL;
    }
    Shandalar_DisplayShutdown();
    return (int)msg.wParam;
}
