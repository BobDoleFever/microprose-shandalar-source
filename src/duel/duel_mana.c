
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_004ff5a9;
extern int DAT_006827df;
extern int DAT_00618ad8;
extern int DAT_006826dc;
extern int DAT_006826d0;
extern int DAT_006826f9;
int Action_ValidateTarget_0041e2a2();
int Pic_Subsystem_004488a0();
extern int DAT_004ff596;
extern int DAT_004ff59c;
extern int DAT_006826da;
extern int DAT_004ff59a;
extern int DAT_006826ff;
extern int DAT_004ff5a4;
extern int DAT_00681ecc;
extern int DAT_006826d4;
extern int DAT_006826d6;
extern int DAT_0068ee64;

#define _rand rand
#define _sprintf sprintf
#define _strlen strlen
#define _strcmp strcmp
#define _fopen fopen
#define _fclose fclose
#define _fgets fgets
#define _fscanf fscanf
#define _read read
#define __read read
#define __strnicmp strncasecmp

typedef int (*GhidraCall)(void *, ...);

int Duel_ColorMaskToIndex(byte arg_1);
uint Duel_TapCardForMana(int x, int y, int width, undefined4 arg_4);
uint Mana_GetCardColorRequirement(int player, int card_slot);
bool Mana_CanAffordCost(int arg_1, uint arg_2, int arg_3);
int Duel_GetCardColorOverride(int arg_1, int arg_2, int arg_3);

int Duel_ApplyCombatDamage(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5);
int Duel_GetCardModifiedPower(int arg_1, int arg_2, int arg_3);
int Duel_RandomRange(int arg_1);

void Duel_UpdateBoardState(undefined4 arg1, undefined4 arg2);
bool Duel_CardIsTapped(int arg1, int arg2);
int Duel_TriggerCardEvent(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5);
int Duel_PlayCardSoundEffect(int arg_1, int arg_2, int arg_3, undefined4 arg_4, undefined4 arg_5);

void Duel_DrawCardSprite(int arg_1, int arg_2, int arg_3);
int Duel_DrawString(int arg_1, uint arg_2, int arg_3);
undefined4 UI_SelectTargetCardDialog(void *arg1, uint arg2);

void EnterCriticalSection(void *cs);
void LeaveCriticalSection(void *cs);
int thunk_FUN_10001c16(void *p);
int thunk_FUN_100019c7(void *p);
int thunk_FUN_1000dd80();
int IsSndLoaded();
int GetLRUSnd();
void OutputDebugStringA(const char *s);
void _splitpath(const char *path, char *drive, char *dir, char *fname, char *ext);
HMODULE LoadLibraryA(const char *lib);
FARPROC GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
int ReleaseSnd();
void DeckBuilderMain();
int AVIFileOpenA();
int AVIFileRelease();
int AVIFileGetStream();
LRESULT SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

extern int32_t g_DuelCardSlot_CardId;
extern int32_t g_DuelCardSlot_Flags;
extern uint8_t g_DuelCardSlot_Subtypes;
extern uint8_t g_DuelCardSlot_ColorMask;
extern uint8_t g_DuelCardSlot_Controller;
extern int16_t g_DuelCardSlot_Power;
extern int32_t g_DuelCardSlot_Counters;
extern int32_t g_DuelCardSlot_TargetSlot;
extern int32_t g_DuelCardSlot_DisplayIndex;
extern uint32_t g_DuelCardSlot_Abilities1;
extern uint32_t g_DuelCardSlot_Abilities2;
extern int32_t g_DuelCardSlot_TargetPlayer;
extern int32_t g_DuelCardSlot_CombatTargetSlot;
extern int32_t g_DuelCardSlot_AttachedAuraPlayer;
extern int32_t g_DuelCardSlot_AttachedAuraSlot;
extern uint8_t g_DuelCardSlot_TapState;
extern uint8_t g_DuelCardSlot_SpecialState;

extern int32_t g_DuelActivePlayer;
extern int32_t g_DuelActiveCardSlot;
extern int32_t g_DuelHumanPlayerIndex;
extern int32_t g_DuelPlayerLifeTotals;
extern int32_t g_DuelPlayerManaPool;
extern int32_t g_DuelTurnCounter;
extern int32_t g_DuelPlayerCreatureCount;
extern int32_t g_DuelCurrentTurnPhase;
extern int32_t g_DuelDefendingPlayer;
extern int32_t g_DuelTargetPlayer;
extern int32_t g_DuelTargetCardSlot;
extern int32_t g_DuelDebugModeFlag;
extern int32_t g_DuelCombatPhaseState;
extern int32_t g_DuelCurrentEventCode;
extern int32_t g_DuelTargetCardId;
extern int32_t g_DuelDamageAccumulator;
extern int32_t g_DuelCombatAttackerPlayer;
extern int32_t g_DuelCombatBlockerSlot;
extern uint8_t g_DuelMasterCardTable;
extern uint8_t g_DuelMasterCardSubType;
extern char g_DuelCardChoicePrompt;
extern char g_DuelCardNameBuffer;
extern HINSTANCE g_DuelInstanceHandle;
extern HWND g_DuelMainHwnd;
extern char g_DuelAssetDirectory;
extern int32_t g_DisplayScreenWidth;
extern int32_t g_DisplayScreenHeight;

extern uint32_t g_ActivePalette;
extern int32_t g_CardSlot_Counters;
extern int32_t g_CardSlot_CardId;
extern int32_t g_CardSlot_Flags;
extern int g_OverworldPlayerCoordX;
extern int g_OverworldPlayerCoordY;
extern int g_OverworldMapGrid;
extern int g_ActivePlayerPriority;
extern int g_IsAiThinking;

extern int DAT_0068eee0;
extern int DAT_0068eed8;
extern int DAT_006826c0;
extern int DAT_006826ec;
extern int DAT_00682704;
extern int DAT_00682710;
extern int DAT_006826dd;
extern int DAT_00682714;
extern int DAT_0068f2e0;
extern int DAT_0068ed10;
extern int DAT_006b2fe4;
extern int DAT_006b157c;
extern int DAT_006fedc0;
extern int DAT_00527e88;
extern int DAT_005ef980;
extern int DAT_00666444;
extern int DAT_00627870;
extern int DAT_0051aebe;
extern int DAT_00676500;
extern int DAT_00666900;
extern int DAT_006a4f70;
extern int DAT_0063edd0;
extern int DAT_0068ecfc;
extern int DAT_0068ee70;
extern int DAT_0068eef0;
extern int DAT_0068edd4;
extern int DAT_0068ee98;
extern int DAT_00681ec8;
extern int DAT_00681eb4;
extern int DAT_00690310;
extern int DAT_00667994;
extern int DAT_0067bdb0;
extern int DAT_00677340;
extern int DAT_005239ec;
extern int DAT_0067bda0;
extern int DAT_00627a20;
extern int DAT_00665ed0;
extern int DAT_0054aab0;
extern int DAT_0054aab8;
extern int DAT_00515e80;
extern int DAT_00515e88;
extern int DAT_0061815c;
extern int PTR_DAT_004f7914;
extern int DAT_0051aec4;
extern int DAT_006a4b70;
extern int DAT_004fb0f4;
extern int _DAT_1004c884;
extern int DAT_1004c6d4;
extern int DAT_1004044c;
extern int DAT_1001e8a0;
extern int *DAT_1000a640;
extern int DAT_1000a440;
extern int *DAT_1000ba90;
extern int _DAT_0068f0b4;
extern int DAT_0063ee18;
extern int DAT_0063ee90;
extern int DAT_004ff590;
extern int DAT_00666760;
extern int DAT_006663e0;
extern int DAT_0066aae8;
extern int DAT_0068f0b0;
extern int DAT_006b2d5c;
extern int DAT_0063eea8;
extern int DAT_0060d4a0;
extern int DAT_00412ac4;
extern int g_OverworldWorldState;
extern const char* s_spr1024__00525754;
extern const char* s_spr800__0052574c;
extern const char* s_SmallArt_cat_10040480;
extern const char* s_MedArt_cat_10040470;
extern const char* s__08X_LoadKimPicture___s___file_m_004f7970;
extern const char* s_Magic__The_Gathering_00412a30;
extern const char* s__MTGshell_00412a48;
extern const char* s__08x_DestroyDIBSection__file_map_004f9804;
extern const char* s__08x_DestroyDIBSection__file_map_00530204;
extern const char* PTR_s_magsnd_1001152c;
extern int DAT_101cf930;
extern int DAT_10011524;
extern int DAT_1001e87c;
extern int DAT_1000a434;

int Pic_Subsystem_00451291();
int Pic_Subsystem_0044895f();
int Pic_Subsystem_0044867e();
int Pic_Subsystem_0044b84b();
int FUN_00451760();
int FUN_0046da4a();
int FUN_00451995();
int Mem_AllocOrFree_0049f704();
int Mem_AllocOrFree_00408089();
int Mem_AllocOrFree_004f1e20();
int Mem_AllocOrFree_0050f740();
uint32_t* Mem_AllocOrFree_004d9630(uint32_t*, uint32_t*);
int FUN_0048ac2f();
int FUN_00470a16();
int FUN_0048cb7f();
int FUN_0048ca2a();
int FUN_0048cac9();
int FUN_0048caf4();
int FUN_00432c2a();
int FUN_00447114();
int FUN_00446de2();
int FUN_00401010();
int FUN_004010aa();
int FUN_0040161a();
int FUN_0040cc08();
int FUN_0043d3ff();
int FUN_0049b2c1();
int FUN_0049b1a9();
int FUN_0050d560();
int FUN_00511120();
int FUN_00510fc0();
int FUN_0050e8b0();
int FUN_0050ec90();
int FUN_0050f820();
int FUN_0050f440();
int FUN_00486c12();
int FUN_00478aa4();

/*
 * Decompiled function: Mana_GetCardColorRequirement
 * Entry Point: 004521e2
 * Size: 645 bytes
 */


uint Mana_GetCardColorRequirement(int player,int card_slot)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  if (*(int *)(&g_DuelCardSlot_CardId + card_slot * 0x120 + player * 0x5b20) == DAT_0068eee0) {
    local_8 = *(int *)(&DAT_006826c0 + card_slot * 0x120 + player * 0x5b20);
  }
  else {
    local_8 = *(int *)(&g_DuelCardSlot_CardId + card_slot * 0x120 + player * 0x5b20);
  }
  if (((&g_DuelMasterCardTable)[local_8 * 0x34] & 4) == 0) {
    if (((&g_DuelMasterCardTable)[local_8 * 0x34] & 0x10) == 0) {
      if (((&g_DuelMasterCardTable)[local_8 * 0x34] & 0x20) == 0) {
        if (((&g_DuelMasterCardTable)[local_8 * 0x34] & 8) == 0) {
          iVar2 = Duel_ColorMaskToIndex((&DAT_006826dd)[card_slot * 0x120 + player * 0x5b20]);
          cVar1 = Duel_GetCardColorOverride(player, card_slot, iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f);
        }
        else {
          iVar2 = Duel_ColorMaskToIndex((&DAT_006826dd)[card_slot * 0x120 + player * 0x5b20]);
          cVar1 = Duel_GetCardColorOverride(player, card_slot, iVar2);
          uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x100000;
        }
      }
      else {
        iVar2 = Duel_ColorMaskToIndex((&DAT_006826dd)[card_slot * 0x120 + player * 0x5b20]);
        cVar1 = Duel_GetCardColorOverride(player, card_slot, iVar2);
        uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x80000;
      }
    }
    else {
      iVar2 = Duel_ColorMaskToIndex((&DAT_006826dd)[card_slot * 0x120 + player * 0x5b20]);
      cVar1 = Duel_GetCardColorOverride(player, card_slot, iVar2);
      uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x40000;
    }
  }
  else {
    iVar2 = Duel_ColorMaskToIndex((&DAT_006826dd)[card_slot * 0x120 + player * 0x5b20]);
    cVar1 = Duel_GetCardColorOverride(player, card_slot, iVar2);
    uVar3 = 0x800 << (cVar1 - 1U & 0x1f) | 0x20000;
  }
  return uVar3;
}

/*
 * Decompiled function: Duel_TapCardForMana
 * Entry Point: 0048b81a
 * Size: 2824 bytes
 */


uint Duel_TapCardForMana(int x,int y,int width,undefined4 flags)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  uint local_1c;
  int local_18;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar3 = DAT_005ef980;
  DAT_006663e0 = DAT_006663e0 + 1;
  if (DAT_0068eed8 != 0) {
    FUN_0048cac9();
  }
  g_DuelActivePlayer = x;
  g_DuelActiveCardSlot = y;
  DAT_00681ecc = *(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20);
  DAT_0068ee64 = (int)(char)(&DAT_004ff596)[DAT_00681ecc * 0x34];
  DAT_0068ecfc = flags;
  switch(width) {
  case 0x32:
    if (((&g_DuelCardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_004ff59a + DAT_00681ecc * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_004ff59a + DAT_00681ecc * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&g_DuelCardSlot_Power + y * 0x120 + x * 0x5b20);
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 4) != 0) {
      *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfbffffff;
      goto LAB_0048be41;
    }
    g_DuelCurrentTurnPhase = (uint)*(short *)(&DAT_006826d4 + y * 0x120 + x * 0x5b20);
    break;
  case 0x33:
    if (((&g_DuelCardSlot_Flags)[y * 0x120 + x * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_004ff59c + DAT_00681ecc * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_004ff59c + DAT_00681ecc * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006826da + y * 0x120 + x * 0x5b20);
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 2) != 0) {
      *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfdffffff;
      goto LAB_0048be41;
    }
    g_DuelCurrentTurnPhase = (uint)*(short *)(&DAT_006826d6 + y * 0x120 + x * 0x5b20);
    break;
  case 0x34:
    uVar1 = *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    uVar2 = *(uint *)(&DAT_004ff5a4 + DAT_00681ecc * 0x34);
    local_8 = uVar1 & 0x7000000 | uVar2;
    if ((uVar2 & 0x1ff81f) != 0) {
      local_1c = 0;
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        if ((local_8 & 1 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Duel_GetCardModifiedPower(x, y, local_18 + 1);
          local_1c = local_1c | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((local_8 & 0x800 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Duel_GetCardColorOverride(x, y, local_18 + 1);
          local_1c = local_1c | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      local_8 = uVar1 & 0x7000000 | uVar2 & 0xffe007e0 | local_1c;
    }
    if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 8) != 0) {
      *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
           *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xf7ffffff;
      goto LAB_0048be41;
    }
    g_DuelCurrentTurnPhase = *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20);
    break;
  case 0x35:
    local_8 = (uint)*(short *)(&DAT_006826d0 + y * 0x120 + x * 0x5b20);
    goto LAB_0048be41;
  case 0x36:
    local_8 = (uint)(char)(&DAT_004ff596)[DAT_00681ecc * 0x34];
    goto LAB_0048be41;
  default:
    local_8 = 0;
LAB_0048be41:
    g_DuelCurrentTurnPhase = local_8;
    if ((DAT_0068eed8 != 0) && (Magic_ScanCards(width), (g_DuelPlayerManaPool & 0x10000) != 0)) {
      g_DuelPlayerManaPool = g_DuelPlayerManaPool & 0xfffeffff;
      *(uint *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) = g_DuelCurrentTurnPhase;
      g_DuelPlayerManaPool = g_DuelPlayerManaPool | 0x20000;
      Magic_ScanCards(width);
      g_DuelPlayerManaPool = g_DuelPlayerManaPool & 0xfffdffff;
    }
    if (width == 0x32) {
      if ((int)g_DuelCurrentTurnPhase < 0) {
        g_DuelCurrentTurnPhase = 0;
      }
      if (((&DAT_006826f9)[y * 0x120 + x * 0x5b20] & 0x40) != 0) {
        g_DuelCurrentTurnPhase = g_DuelCurrentTurnPhase << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) < g_DuelTargetCardId) ||
        (g_DuelTargetCardId + 0x1d <= *(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20))) &&
       (*(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) != -1)) {
      local_8 = *(uint *)(&DAT_006826c0 + y * 0x120 + x * 0x5b20);
      if (((&DAT_006826ff)[y * 0x120 + x * 0x5b20] & 1) != 0) {
        *(undefined4 *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&DAT_006826c0 + y * 0x120 + x * 0x5b20);
        *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) & 0xfeffffff;
        (&DAT_006827df)[y * 0x120 + x * 0x5b20] = 0;
        goto LAB_0048be41;
      }
      g_DuelCurrentTurnPhase = *(uint *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
    else {
      g_DuelCurrentTurnPhase = *(uint *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20);
    }
  }
  uVar1 = g_DuelCurrentTurnPhase;
  iVar5 = Duel_CardIsTapped(x, y);
  if (((iVar5 != 0) && (width == 0x33)) &&
     ((((&g_DuelMasterCardTable)[DAT_00681ecc * 0x34] & 2) != 0 &&
      (((((int)uVar1 < 1 || ((int)uVar1 <= (int)*(short *)(&DAT_006826d0 + y * 0x120 + x * 0x5b20)))
        && (g_DuelCurrentEventCode == -1)) && ((g_DuelPlayerManaPool & 0x204) == 0)))))) {
    Duel_DrawCardSprite(x,y,2);
    Pic_Subsystem_004488a0();
  }
  if (DAT_0068eed8 != 0) {
    FUN_0048cb7f();
  }
  if (width == 0x32) {
    *(short *)(&DAT_006826d4 + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x33) {
    *(short *)(&DAT_006826d6 + y * 0x120 + x * 0x5b20) = (short)uVar1;
  }
  if (width == 0x34) {
    *(uint *)(&g_DuelCardSlot_Abilities2 + y * 0x120 + x * 0x5b20) = uVar1;
  }
  if (width != 0x3c) {
    DAT_005ef980 = uVar3;
    return uVar1;
  }
  *(uint *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) = uVar1;
  if (((&DAT_004ff5a9)[uVar1 * 0x34] & 0x10) == 0) goto LAB_0048c17d;
  iVar5 = *(int *)(&DAT_004ff590 + uVar1 * 0x34);
  if (iVar5 < 0x12d) {
    if (iVar5 == 300) {
      (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = 1;
      goto LAB_0048c17d;
    }
    if (iVar5 == 0xf) {
      (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = 0x3e;
      goto LAB_0048c17d;
    }
  }
  else if ((iVar5 == 0x13e) || (iVar5 == 0x366)) goto LAB_0048c17d;
  (&DAT_006826dc)[y * 0x120 + x * 0x5b20] = (&DAT_004ff596)[uVar1 * 0x34];
LAB_0048c17d:
  if ((((&g_DuelCardSlot_Abilities1)[y * 0x120 + x * 0x5b20] & 0x40) != 0) &&
     (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < (int)(&g_DuelPlayerCreatureCount)[local_c]; local_10 = local_10 + 1) {
        if ((((*(int *)(&g_DuelCardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) &&
             (((&g_DuelCardSlot_Flags)[local_10 * 0x120 + local_c * 0x5b20] & 2) != 0)) &&
            ((char)(&g_DuelCardSlot_ColorMask)[local_10 * 0x120 + local_c * 0x5b20] == x)) &&
           (((*(int *)(&g_DuelCardSlot_TargetSlot + local_10 * 0x120 + local_c * 0x5b20) == y &&
             (((&g_DuelMasterCardTable)[*(int *)(&g_DuelCardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) * 0x34]
              & 4) != 0)) &&
            (*(int *)(&DAT_00618ad8 +
                     *(int *)(&DAT_004ff590 +
                             *(int *)(&g_DuelCardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) * 0x34) *
                     0x98) == 0x2d)))) {
          Duel_DrawCardSprite(local_c,local_10,3);
        }
      }
    }
  }
  DAT_005ef980 = uVar3;
  return uVar1;
}

/*
 * Decompiled function: Mana_CanAffordCost
 * Entry Point: 00468130
 * Size: 300 bytes
 */


bool Mana_CanAffordCost(int player,uint cost_mask,int card_slot)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int iVar1;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (cost_mask == 0xffffffff) {
    cost_mask = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &g_DuelCardNameBuffer;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  iVar1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = Mana_GetCardColorRequirement(player,card_slot);
  iVar1 = Action_ValidateTarget_0041e2a2
                    (player,2,cost_mask,0x200,2,0,0,arg_8,arg_9,arg_10,iVar1,arg_12,arg_13,arg_14,arg_15,
                     arg_16,arg_17,arg_18,arg_19,arg_20);
  if (iVar1 != 0) {
    *(undefined4 *)
     (&g_DuelCardSlot_CombatTargetSlot +
     player * 0x5b20 + card_slot * 0x120 + (char)(&g_DuelCardSlot_TapState)[player * 0x5b20 + card_slot * 0x120] * 8) =
         local_8;
    *(int *)(&g_DuelCardSlot_TargetPlayer +
            player * 0x5b20 +
            card_slot * 0x120 + (char)(&g_DuelCardSlot_TapState)[player * 0x5b20 + card_slot * 0x120] * 8) = local_c;
    (&g_DuelCardSlot_TapState)[player * 0x5b20 + card_slot * 0x120] =
         (&g_DuelCardSlot_TapState)[player * 0x5b20 + card_slot * 0x120] + '\x01';
  }
  return iVar1 != 0;
}

/*
 * Decompiled function: Duel_ColorMaskToIndex
 * Entry Point: 0048c367
 * Size: 121 bytes
 */


undefined4 Duel_ColorMaskToIndex(byte color_mask)

{
  undefined4 uVar1;
  
  if ((color_mask & 2) == 0) {
    if ((color_mask & 4) == 0) {
      if ((color_mask & 8) == 0) {
        if ((color_mask & 0x10) == 0) {
          if ((color_mask & 0x20) == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 5;
          }
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 3;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/*
 * Decompiled function: Duel_GetCardColorOverride
 * Entry Point: 004af7bb
 * Size: 106 bytes
 */


int Duel_GetCardColorOverride(int player,int card_slot,int base_color)

{
  if ((&g_DuelCardSlot_SpecialState)[base_color + player * 0x5b20 + card_slot * 0x120] != '\0') {
    base_color = (int)(char)(&g_DuelCardSlot_SpecialState)[base_color + player * 0x5b20 + card_slot * 0x120];
  }
  return base_color;
}
