
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_006827bf;

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

extern uint32_t g_CardEventResult;
extern int32_t g_CardSlot_Counters;
extern int32_t g_CardSlot_CardId;
extern int32_t g_CardSlot_Flags;
extern int g_EventSourcePlayer;
extern int g_OverworldPlayerCoordY;
extern int g_EventSourceSlot;
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
 * Decompiled function: Duel_ApplyCombatDamage
 * Entry Point: 004af950
 * Size: 972 bytes
 */


int Duel_ApplyCombatDamage(int attacker_player,int attacker_slot,int defender_player,int defender_slot,int damage)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_8;
  
  if (((attacker_player == -1) || (defender_slot == -1)) || (defender_player < 1)) {
    iVar1 = -1;
  }
  else {
    if (attacker_slot == -1) {
      local_8 = attacker_player;
    }
    else {
      local_8 = defender_slot;
    }
    iVar1 = Pic_Subsystem_00451291(local_8,g_DuelTargetCardId);
    if (iVar1 != -1) {
      *(uint *)(&g_DuelCardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) =
           *(uint *)(&g_DuelCardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) |
           CONCAT31((uint32_t)((local_8 == 0) - 1 >> 8) & 0x10,2);
      (&g_DuelCardSlot_ColorMask)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)attacker_player;
      *(int *)(&g_DuelCardSlot_TargetSlot + iVar1 * 0x120 + local_8 * 0x5b20) = attacker_slot;
      *(int *)(&g_DuelCardSlot_Counters + iVar1 * 0x120 + local_8 * 0x5b20) = defender_player;
      (&g_DuelCardSlot_Controller)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)defender_slot;
      *(int *)(&DAT_006826ec + iVar1 * 0x120 + local_8 * 0x5b20) = damage;
      if (damage == -1) {
        *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&g_DuelCardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20) == -1) ||
           (*(int *)(&g_DuelCardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20) == DAT_0068eee0)) {
          local_10 = *(int *)(&DAT_006826c0 + damage * 0x120 + defender_slot * 0x5b20);
        }
        else {
          local_10 = *(int *)(&g_DuelCardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20);
        }
        (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] =
             (&DAT_006826dd)[damage * 0x120 + defender_slot * 0x5b20];
        if (((&g_DuelMasterCardTable)[local_10 * 0x34] & 0x40) != 0) {
          (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] =
               (&DAT_006826dd)[iVar1 * 0x120 + local_8 * 0x5b20] | 0x40;
        }
        *(uint *)(&g_DuelCardSlot_DisplayIndex + iVar1 * 0x120 + local_8 * 0x5b20) =
             (uint)(byte)(&g_DuelMasterCardTable)[local_10 * 0x34];
        if ((*(int *)(&DAT_004ff590 + local_10 * 0x34) == DAT_00666444) ||
           (*(int *)(&DAT_004ff590 + local_10 * 0x34) == DAT_0066aae8)) {
          *(undefined4 *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) =
               *(undefined4 *)(&DAT_00682704 + damage * 0x120 + defender_slot * 0x5b20);
        }
        else {
          iVar2 = FUN_00486c12(*(int *)(&DAT_004ff590 + local_10 * 0x34),defender_slot,damage);
          *(uint *)(&DAT_00682704 + iVar1 * 0x120 + local_8 * 0x5b20) =
               iVar2 << 0x10 | *(uint *)(&DAT_004ff590 + local_10 * 0x34);
        }
      }
      g_DuelPlayerManaPool = g_DuelPlayerManaPool | 2;
    }
  }
  return iVar1;
}

/*
 * Decompiled function: Duel_GetCardModifiedPower
 * Entry Point: 004af74c
 * Size: 106 bytes
 */


int Duel_GetCardModifiedPower(int player,int card_slot,int base_power)

{
  if ((&DAT_006827bf)[base_power + player * 0x5b20 + card_slot * 0x120] != '\0') {
    base_power = (int)(char)(&DAT_006827bf)[base_power + player * 0x5b20 + card_slot * 0x120];
  }
  return base_power;
}

/*
 * Decompiled function: Duel_RandomRange
 * Entry Point: 00439892
 * Size: 44 bytes
 */


int Duel_RandomRange(int max_val)

{
  int iVar1;
  
  if (max_val < 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = _rand();
    iVar1 = iVar1 % max_val;
  }
  return iVar1;
}
