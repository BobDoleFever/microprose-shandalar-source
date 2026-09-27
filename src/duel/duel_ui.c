
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_0068f2f8;
extern int DAT_0068ed28;
extern int DAT_0066640c;
extern int DAT_00666570;
int Rules_ParseFilter_0041c0ab();

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
uint Duel_QueryCardAttribute(int player, int slot, int event_code, undefined4 target_slot);
uint Card_GetColorAndTypeFlags(int player, int card_slot);
bool CardTarget_PromptTargetCreature(int arg_1, uint arg_2, int arg_3);
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
undefined4 UI_SelectTargetCardDialog();

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

extern int32_t g_EventSourcePlayer;
extern int32_t g_EventSourceSlot;
extern int32_t g_DuelHumanPlayerIndex;
extern int32_t g_DuelPlayerLifeTotals;
extern int32_t g_DuelModeFlags;
extern int32_t g_DuelTurnCounter;
extern int32_t g_DuelPlayerCreatureCount;
extern int32_t g_CardEventResult;
extern int32_t g_TurnPlayer;
extern int32_t g_DuelTargetPlayer;
extern int32_t g_DuelTargetCardSlot;
extern int32_t g_IsAiThinking;
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

extern int g_StackObjectCardId;
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
int Magic_IsManaSource();
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
 * Decompiled function: Duel_DrawCardSprite
 * Entry Point: 0046e571
 * Size: 546 bytes
 */


void Duel_DrawCardSprite(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_1 != -1) && (arg_2 != -1)) &&
     (((&g_DuelCardSlot_Abilities1)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x80) == 0)) {
    *(uint *)(&g_DuelCardSlot_Abilities1 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&g_DuelCardSlot_Abilities1 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x80;
    iVar1 = *(int *)(&g_DuelCardSlot_CardId + arg_1 * 0x5b20 + arg_2 * 0x120);
    if (iVar1 != -1) {
      if (((&g_DuelCardSlot_Flags)[arg_1 * 0x5b20 + arg_2 * 0x120] & 2) == 0) {
        arg_3 = 3;
      }
      if (((((&g_DuelCardSlot_Abilities1)[arg_1 * 0x5b20 + arg_2 * 0x120] & 8) == 0) && (arg_3 != 3)) &&
         ((arg_3 != 4 &&
          ((((&g_DuelMasterCardTable)[iVar1 * 0x34] & 3) != 0 && ((&g_DuelMasterCardTable)[iVar1 * 0x34] != -0x80)))))
         ) {
        (&g_StackObjectCardId)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)arg_3;
        *(uint *)(&g_DuelCardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) =
             *(uint *)(&g_DuelCardSlot_Flags + arg_1 * 0x5b20 + arg_2 * 0x120) | 2;
        if (((&g_DuelMasterCardTable)[iVar1 * 0x34] & 2) == 0) {
          Pic_Subsystem_0044895f(arg_1,arg_2);
        }
        else {
          *(undefined4 *)(&DAT_00682710 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0xd6;
        }
        DAT_00666760 = Pic_Subsystem_0044895f;
      }
      else {
        (&g_StackObjectCardId)[arg_1 * 0x5b20 + arg_2 * 0x120] = (undefined1)arg_3;
        Pic_Subsystem_0044895f(arg_1,arg_2);
      }
    }
  }
  return;
}

/*
 * Decompiled function: Duel_DrawString
 * Entry Point: 0049b309
 * Size: 895 bytes
 */


int Duel_DrawString(int x,uint y,int text)

{
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_1c;
  int local_10;
  byte local_8;
  
  if (y == 6) {
    local_28 = 7;
  }
  else if (y == 0) {
    local_28 = 7;
  }
  else {
    local_28 = y;
  }
  if (text == 0) {
    local_34 = 1;
  }
  else {
    local_2c = 0;
    local_24 = 0;
    while (((int)local_24 < 10 && (*(int *)(&DAT_00666900 + local_24 * 4 + x * 0x2c) != -1))) {
      if (local_28 == *(uint *)(&DAT_00666900 + local_24 * 4 + x * 0x2c) >> 0x10) {
        local_8 = (byte)*(undefined2 *)(&DAT_00666900 + local_24 * 4 + x * 0x2c);
        local_2c = local_2c | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_30 = *(int *)(&DAT_0068f2e0 + local_28 * 4 + x * 0x20);
    for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
      if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
        local_30 = local_30 + *(int *)(&DAT_0068f2e0 + local_24 * 4 + x * 0x20);
      }
    }
    local_1c = *(int *)(&DAT_0068ed10 + local_28 * 4 + x * 0x20);
    if (((x == g_DuelTargetCardSlot) || (DAT_0068f0b0 != 0)) || (g_IsAiThinking == 1)) {
      for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
        if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
          local_1c = local_1c + *(int *)(&DAT_0068ed10 + local_24 * 4 + x * 0x20);
        }
      }
    }
    local_10 = 0;
    local_24 = 0;
    while (((int)local_24 < 0x32 && (*(int *)(&DAT_00666570 + local_24 * 4 + x * 0xcc) != -1)))
    {
      if (local_28 == 7) {
        local_10 = local_10 + (*(int *)(&DAT_00666570 + local_24 * 4 + x * 0xcc) >> 0x10);
      }
      else if ((*(uint *)(&DAT_00666570 + local_24 * 4 + x * 0xcc) &
               1 << ((byte)local_28 & 0x1f)) == 0) {
        if ((((x == g_DuelTargetCardSlot) || (DAT_0068f0b0 != 0)) || (g_IsAiThinking == 1)) &&
           ((local_2c & *(uint *)(&DAT_00666570 + local_24 * 4 + x * 0xcc)) != 0)) {
          local_10 = local_10 + (*(int *)(&DAT_00666570 + local_24 * 4 + x * 0xcc) >> 0x10);
        }
      }
      else {
        local_10 = local_10 + (*(int *)(&DAT_00666570 + local_24 * 4 + x * 0xcc) >> 0x10);
      }
      local_24 = local_24 + 1;
    }
    if ((y == 7) || (y == 0)) {
      local_34 = (((local_30 - *(int *)(&DAT_0068f2f8 + x * 0x20)) + local_1c) -
                 *(int *)(&DAT_0068ed28 + x * 0x20)) + local_10;
    }
    else {
      local_34 = local_10 + local_1c + local_30;
    }
    if (local_34 < text) {
      local_34 = 0;
    }
  }
  return local_34;
}

/*
 * Decompiled function: UI_SelectTargetCardDialog
 * Entry Point: 0041bcf0
 * Size: 955 bytes
 */


undefined4
UI_SelectTargetCardDialog(int *arg_1,int arg_2,int arg_3,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,
            uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,
            uint arg_16,uint arg_17,uint arg_18,uint arg_19)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  int local_2c;
  int local_28;
  undefined4 local_20;
  int local_18;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_18 = 0;
  local_20 = 0;
  if (((arg_2 == 0) || (arg_2 == 1)) || (arg_2 == 2)) {
    bVar1 = false;
    local_28 = 0;
    while( true ) {
      if (1 < local_28) break;
      iVar2 = Rules_ParseFilter_0041c0ab
                        (local_28,-1,(undefined1 *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,arg_7,
                         arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,
                         arg_19);
      if (iVar2 != 0) {
        local_20 = 1;
        local_18 = local_18 + 1;
        if (arg_1 == (int *)0x0) {
          bVar1 = true;
        }
      }
      local_28 = local_28 + 1;
    }
    if (arg_3 == 0) {
      local_8 = (uint)((arg_4 & 2) == 0);
    }
    else if (((arg_5 & 2) == 0) && ((arg_5 & 1) == 0)) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
    local_28 = 0;
    while ((local_28 < 2 && (!bVar1))) {
      local_c = 0;
      while( true ) {
        iVar2 = DAT_0066640c;
        if (DAT_0066640c <= g_DuelPlayerCreatureCount) {
          iVar2 = g_DuelPlayerCreatureCount;
        }
        if ((iVar2 <= local_c) || (bVar1)) break;
        if (*(int *)(&g_DuelCardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          if (arg_2 == 0) {
            local_10 = local_8;
            local_2c = local_c;
            bVar3 = true;
          }
          else if (arg_2 == 1) {
            bVar3 = *(int *)(&g_DuelCardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == g_DuelTargetCardId;
            if (bVar3) {
              local_10 = (uint)(char)(&g_DuelCardSlot_ColorMask)[local_c * 0x120 + local_8 * 0x5b20];
              local_2c = *(int *)(&g_DuelCardSlot_TargetSlot + local_c * 0x120 + local_8 * 0x5b20);
            }
          }
          else if (*(int *)(&g_DuelCardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == g_DuelTargetCardId) {
            local_10 = (uint)(char)(&g_DuelCardSlot_Controller)[local_c * 0x120 + local_8 * 0x5b20];
            local_2c = *(int *)(&DAT_006826ec + local_c * 0x120 + local_8 * 0x5b20);
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if ((bVar3) &&
             (iVar2 = Rules_ParseFilter_0041c0ab
                                (local_10,local_2c,(undefined1 *)0x0,arg_3,(byte)arg_4,(byte)arg_5,
                                 arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,
                                 arg_16,arg_17,arg_18,arg_19), iVar2 != 0)) {
            local_20 = 1;
            local_18 = local_18 + 1;
            if (arg_1 == (int *)0x0) {
              bVar1 = true;
            }
          }
        }
        local_c = local_c + 1;
      }
      local_28 = local_28 + 1;
      local_8 = 1 - local_8;
    }
    if (arg_1 != (int *)0x0) {
      *arg_1 = local_18;
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}
