
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_006808bc;
extern int DAT_0068a694;
extern int DAT_006a2848;
int Rules_ParseFilter_0040360b();
extern int DAT_0050b37c;
extern int g_CardSlot_TargetSlot;
extern int g_CardSlot_TypeFlags;
extern int g_CardSlot_DamageReceived;
extern int g_CardSlot_ConvertedManaCost;
extern int DAT_006a5f74;
extern int DAT_006a5f4d;
extern int DAT_0050ed70;
extern int g_StackObjectCardId;
extern int g_CardSlot_Toughness;
extern int DAT_006a6029;
extern int DAT_0051aed1;
extern int g_CardSlot_Abilities1;
extern int g_PlayerActiveCardCount;
extern int DAT_0068f0bc;
extern int g_MasterCardTypeTable;
extern int DAT_006b3088;
extern int g_CardSlot_OriginalCardId;
extern int DAT_006a5f4c;
extern int DAT_006a602f;
int Pic_Subsystem_004488a0();
extern int DAT_006ff2e0;
extern int g_DuelModeFlags;
extern int g_MasterCardColorTable;
extern int g_CardSlot_Power;
extern int DAT_006a5f69;
extern int DAT_006a604f;
extern int g_CurrentStepCode;
extern int g_ActiveCardsInPlay;
bool Card_IsTapped();
extern int DAT_006a5f6f;
extern int DAT_0051aec2;
extern int DAT_006a5f4a;
extern int DAT_006a5f46;
extern int DAT_006a5f48;
extern int DAT_0051aecc;
extern int g_CardSlot_Abilities2;
int Card_SetTapState();
int Card_UntapCard();

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
extern int g_EventCardColorMask;
extern int DAT_006b157c;
extern int DAT_006fedc0;
extern int DAT_00527e88;
extern int DAT_005ef980;
extern int DAT_00666444;
extern int DAT_00627870;
extern int DAT_0051aebe;
extern int DAT_00676500;
extern int DAT_00666900;
extern int g_EventCardId;
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
extern int g_EventTargetSlot;
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
 * Decompiled function: Magic_QueryCardAttribute
 * Entry Point: 00473179
 * Size: 2823 bytes
 */


uint Magic_QueryCardAttribute(int player,int slot,int event_code,undefined4 flags)

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
  
  uVar3 = DAT_0067bdb0;
  DAT_00677340 = DAT_00677340 + 1;
  if (DAT_0063ee18 != 0) {
    Magic_PushEventContext(0, 0, 0);
  }
  g_EventSourcePlayer = player;
  g_EventSourceSlot = slot;
  g_EventCardId = *(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
  g_EventCardColorMask = (int)(char)(&DAT_0051aebe)[g_EventCardId * 0x34];
  g_EventTargetSlot = flags;
  switch(event_code) {
  case 0x32:
    if (((&g_CardSlot_Flags)[slot * 0x120 + player * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec2 + g_EventCardId * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec2 + g_EventCardId * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f48 + slot * 0x120 + player * 0x5b20);
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 4) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfbffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = (uint)*(short *)(&g_CardSlot_Counters + slot * 0x120 + player * 0x5b20);
    break;
  case 0x33:
    if (((&g_CardSlot_Flags)[slot * 0x120 + player * 0x5b20] & 2) == 0) {
      local_8 = (uint)*(short *)(&DAT_0051aec4 + g_EventCardId * 0x34);
    }
    else {
      local_8 = (int)*(short *)(&DAT_0051aec4 + g_EventCardId * 0x34) & 0xffffbfff;
    }
    local_8 = local_8 + (int)*(short *)(&DAT_006a5f4a + slot * 0x120 + player * 0x5b20);
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 2) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfdffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = (uint)*(short *)(&DAT_006a5f46 + slot * 0x120 + player * 0x5b20);
    break;
  case 0x34:
    uVar1 = *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20);
    uVar2 = *(uint *)(&DAT_0051aecc + g_EventCardId * 0x34);
    local_8 = uVar1 & 0x7000000 | uVar2;
    if ((uVar2 & 0x1ff81f) != 0) {
      local_1c = 0;
      for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
        if ((local_8 & 1 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Card_UntapCard(player, slot, local_18 + 1);
          local_1c = local_1c | 1 << (cVar4 - 1U & 0x1f);
        }
        if ((local_8 & 0x800 << ((byte)local_18 & 0x1f)) != 0) {
          cVar4 = Card_SetTapState(player, slot, local_18 + 1);
          local_1c = local_1c | 0x800 << (cVar4 - 1U & 0x1f);
        }
      }
      local_8 = uVar1 & 0x7000000 | uVar2 & 0xffe007e0 | local_1c;
    }
    if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 8) != 0) {
      *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
           *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xf7ffffff;
      goto LAB_004737a0;
    }
    g_CardEventResult = *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20);
    break;
  case 0x35:
    local_8 = (uint)*(short *)(&g_CardSlot_Power + slot * 0x120 + player * 0x5b20);
    goto LAB_004737a0;
  case 0x36:
    local_8 = (uint)(char)(&DAT_0051aebe)[g_EventCardId * 0x34];
    goto LAB_004737a0;
  default:
    local_8 = 0;
LAB_004737a0:
    g_CardEventResult = local_8;
    if ((DAT_0063ee18 != 0) && (Magic_ScanCards(event_code), (g_DuelModeFlags & 0x10000) != 0)) {
      g_DuelModeFlags = g_DuelModeFlags & 0xfffeffff;
      *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) = g_CardEventResult;
      g_DuelModeFlags = g_DuelModeFlags | 0x20000;
      Magic_ScanCards(event_code);
      g_DuelModeFlags = g_DuelModeFlags & 0xfffdffff;
    }
    if (event_code == 0x32) {
      if ((int)g_CardEventResult < 0) {
        g_CardEventResult = 0;
      }
      if (((&DAT_006a5f69)[slot * 0x120 + player * 0x5b20] & 0x40) != 0) {
        g_CardEventResult = g_CardEventResult << 1;
      }
    }
    break;
  case 0x3c:
    if (((*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) < DAT_006ff2e0) ||
        (DAT_006ff2e0 + 0x1d <= *(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20))) &&
       (*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) != -1)) {
      local_8 = *(uint *)(&g_ActiveCardsInPlay + slot * 0x120 + player * 0x5b20);
      if (((&DAT_006a5f6f)[slot * 0x120 + player * 0x5b20] & 1) != 0) {
        *(undefined4 *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) =
             *(undefined4 *)(&g_ActiveCardsInPlay + slot * 0x120 + player * 0x5b20);
        *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) =
             *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) & 0xfeffffff;
        (&DAT_006a604f)[slot * 0x120 + player * 0x5b20] = 0;
        goto LAB_004737a0;
      }
      g_CardEventResult = *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
    }
    else {
      g_CardEventResult = *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20);
    }
  }
  uVar1 = g_CardEventResult;
  iVar5 = Card_IsTapped(player, slot);
  if (((iVar5 != 0) && (event_code == 0x33)) &&
     ((((&g_MasterCardColorTable)[g_EventCardId * 0x34] & 2) != 0 &&
      (((((int)uVar1 < 1 ||
         ((int)uVar1 <= (int)*(short *)(&g_CardSlot_Power + slot * 0x120 + player * 0x5b20))) &&
        (g_CurrentStepCode == -1)) && ((g_DuelModeFlags & 0x204) == 0)))))) {
    Pic_Subsystem_0044867e(player,slot,2);
    Pic_Subsystem_004488a0();
  }
  if (DAT_0063ee18 != 0) {
    Magic_PopEventContext(0, 0);
  }
  if (event_code == 0x32) {
    *(short *)(&g_CardSlot_Counters + slot * 0x120 + player * 0x5b20) = (short)uVar1;
  }
  if (event_code == 0x33) {
    *(short *)(&DAT_006a5f46 + slot * 0x120 + player * 0x5b20) = (short)uVar1;
  }
  if (event_code == 0x34) {
    *(uint *)(&g_CardSlot_Abilities2 + slot * 0x120 + player * 0x5b20) = uVar1;
  }
  if (event_code != 0x3c) {
    DAT_0067bdb0 = uVar3;
    return uVar1;
  }
  *(uint *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) = uVar1;
  if (((&DAT_0051aed1)[uVar1 * 0x34] & 0x10) == 0) goto LAB_00473adb;
  iVar5 = *(int *)(&g_MasterCardTypeTable + uVar1 * 0x34);
  if (iVar5 < 0x12d) {
    if (iVar5 == 300) {
      (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = 1;
      goto LAB_00473adb;
    }
    if (iVar5 == 0xf) {
      (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = 0x3e;
      goto LAB_00473adb;
    }
  }
  else if ((iVar5 == 0x13e) || (iVar5 == 0x366)) goto LAB_00473adb;
  (&DAT_006a5f4c)[slot * 0x120 + player * 0x5b20] = (&DAT_0051aebe)[uVar1 * 0x34];
LAB_00473adb:
  if ((((&g_CardSlot_Abilities1)[slot * 0x120 + player * 0x5b20] & 0x40) != 0) &&
     (((&g_MasterCardColorTable)[*(int *)(&g_CardSlot_CardId + slot * 0x120 + player * 0x5b20) * 0x34] & 2)
      == 0)) {
    for (local_c = 0; local_c < 2; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < (int)(&g_PlayerActiveCardCount)[local_c];
          local_10 = local_10 + 1) {
        if ((((*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) != -1) &&
             (((&g_CardSlot_Flags)[local_10 * 0x120 + local_c * 0x5b20] & 2) != 0)) &&
            ((char)(&g_CardSlot_Toughness)[local_10 * 0x120 + local_c * 0x5b20] == player)) &&
           (((*(int *)(&g_CardSlot_OriginalCardId + local_10 * 0x120 + local_c * 0x5b20) == slot &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + local_c * 0x5b20) * 0x34] & 4) != 0
             )) && (*(int *)(&DAT_006b3088 +
                            *(int *)(&g_MasterCardTypeTable +
                                    *(int *)(&g_CardSlot_CardId +
                                            local_10 * 0x120 + local_c * 0x5b20) * 0x34) * 0x98) ==
                    0x2d)))) {
          Pic_Subsystem_0044867e(local_c,local_10,3);
        }
      }
    }
  }
  DAT_0067bdb0 = uVar3;
  return uVar1;
}

/*
 * Decompiled function: Card_IsTapped
 * Entry Point: 00471c32
 * Size: 114 bytes
 */


bool Card_IsTapped(int player,int card_slot)

{
  bool bVar1;
  
  if (*(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) == -1) {
    bVar1 = false;
  }
  else {
    bVar1 = ((byte)*(undefined4 *)(&g_CardSlot_Flags + card_slot * 0x120 + player * 0x5b20) & 0x22) == 2;
  }
  return bVar1;
}

/*
 * Decompiled function: Card_UntapCard
 * Entry Point: 0041d963
 * Size: 106 bytes
 */


int Card_UntapCard(int player,int card_slot,int arg_3)

{
  if ((&DAT_006a602f)[arg_3 + player * 0x5b20 + card_slot * 0x120] != '\0') {
    arg_3 = (int)(char)(&DAT_006a602f)[arg_3 + player * 0x5b20 + card_slot * 0x120];
  }
  return arg_3;
}

/*
 * Decompiled function: Card_SetTapState
 * Entry Point: 0041d9d2
 * Size: 106 bytes
 */


int Card_SetTapState(int player,int card_slot,int tap_state)

{
  if ((&DAT_006a6029)[tap_state + player * 0x5b20 + card_slot * 0x120] != '\0') {
    tap_state = (int)(char)(&DAT_006a6029)[tap_state + player * 0x5b20 + card_slot * 0x120];
  }
  return tap_state;
}

/*
 * Decompiled function: Card_ColorMaskToColorIndex
 * Entry Point: 00473cc5
 * Size: 121 bytes
 */


undefined4 Card_ColorMaskToColorIndex(byte color_mask)

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
 * Decompiled function: Card_DispatchRulesEvent
 * Entry Point: 0043071d
 * Size: 75 bytes
 */


undefined4 Card_DispatchRulesEvent(int arg_1)

{
  if ((g_IsAiThinking != 1) &&
     (DAT_0068f0bc = *(uint *)(&DAT_0050ed70 + (arg_1 + DAT_0050b37c) * 4),
     DAT_0068f0bc != 0xffffffff)) {
    DAT_0068f0bc = DAT_0068f0bc & 0xfff;
  }
  return 0;
}

/*
 * Decompiled function: Card_ApplyTriggerEffect
 * Entry Point: 00410cc0
 * Size: 561 bytes
 */


int Card_ApplyTriggerEffect(int player,int card_slot,int target_player,int target_slot,int flags)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = Pic_Subsystem_00451291(player,target_player);
  if (iVar2 != -1) {
    *(uint *)(&g_CardSlot_Flags + iVar2 * 0x120 + player * 0x5b20) =
         CONCAT31((uint32_t)((player == 0) - 1 >> 8) & 0x10,2);
    (&DAT_006a5f4c)[iVar2 * 0x120 + player * 0x5b20] =
         (&DAT_006a5f4c)[card_slot * 0x120 + player * 0x5b20];
    (&DAT_006a5f4d)[iVar2 * 0x120 + player * 0x5b20] =
         (&DAT_006a5f4d)[card_slot * 0x120 + player * 0x5b20];
    (&g_CardSlot_DamageReceived)[iVar2 * 0x120 + player * 0x5b20] = (undefined1)player;
    *(int *)(&g_CardSlot_TypeFlags + iVar2 * 0x120 + player * 0x5b20) = card_slot;
    uVar1 = *(uint *)(&g_MasterCardTypeTable +
                     *(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) * 0x34);
    iVar3 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable +
                                 *(int *)(&g_CardSlot_CardId + card_slot * 0x120 + player * 0x5b20) *
                                 0x34),player,card_slot);
    *(uint *)(&DAT_006a5f74 + iVar2 * 0x120 + player * 0x5b20) = uVar1 | iVar3 << 0x10;
    (&g_CardSlot_Toughness)[iVar2 * 0x120 + player * 0x5b20] = (undefined1)target_slot;
    *(int *)(&g_CardSlot_OriginalCardId + iVar2 * 0x120 + player * 0x5b20) = flags;
    if ((target_slot != -1) && (flags != -1)) {
      *(uint *)(&g_CardSlot_Abilities2 + target_slot * 0x5b20 + flags * 0x120) =
           *(uint *)(&g_CardSlot_Abilities2 + target_slot * 0x5b20 + flags * 0x120) | 0xf000000;
    }
  }
  return iVar2;
}

/*
 * Decompiled function: Card_ApplyCombatDamage
 * Entry Point: 0041db67
 * Size: 972 bytes
 */


int Card_ApplyCombatDamage(int attacker_player,int attacker_slot,int defender_player,int defender_slot,int damage)

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
    iVar1 = Pic_Subsystem_00451291(local_8,DAT_006ff2e0);
    if (iVar1 != -1) {
      *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) =
           *(uint *)(&g_CardSlot_Flags + iVar1 * 0x120 + local_8 * 0x5b20) |
           CONCAT31((uint32_t)((local_8 == 0) - 1 >> 8) & 0x10,2);
      (&g_CardSlot_Toughness)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)attacker_player;
      *(int *)(&g_CardSlot_OriginalCardId + iVar1 * 0x120 + local_8 * 0x5b20) = attacker_slot;
      *(int *)(&g_CardSlot_ConvertedManaCost + iVar1 * 0x120 + local_8 * 0x5b20) = defender_player;
      (&g_CardSlot_DamageReceived)[iVar1 * 0x120 + local_8 * 0x5b20] = (undefined1)defender_slot;
      *(int *)(&g_CardSlot_TypeFlags + iVar1 * 0x120 + local_8 * 0x5b20) = damage;
      if (damage == -1) {
        *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) = 0xef;
      }
      else {
        if ((*(int *)(&g_CardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20) == -1) ||
           (*(int *)(&g_CardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20) == g_StackObjectCardId)) {
          local_10 = *(int *)(&g_ActiveCardsInPlay + damage * 0x120 + defender_slot * 0x5b20);
        }
        else {
          local_10 = *(int *)(&g_CardSlot_CardId + damage * 0x120 + defender_slot * 0x5b20);
        }
        (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
             (&DAT_006a5f4d)[damage * 0x120 + defender_slot * 0x5b20];
        if (((&g_MasterCardColorTable)[local_10 * 0x34] & 0x40) != 0) {
          (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] =
               (&DAT_006a5f4d)[iVar1 * 0x120 + local_8 * 0x5b20] | 0x40;
        }
        *(uint *)(&g_CardSlot_TargetSlot + iVar1 * 0x120 + local_8 * 0x5b20) =
             (uint)(byte)(&g_MasterCardColorTable)[local_10 * 0x34];
        if ((*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_0068a694) ||
           (*(int *)(&g_MasterCardTypeTable + local_10 * 0x34) == DAT_006a2848)) {
          *(undefined4 *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               *(undefined4 *)(&DAT_006a5f74 + damage * 0x120 + defender_slot * 0x5b20);
        }
        else {
          iVar2 = FUN_00478aa4(*(int *)(&g_MasterCardTypeTable + local_10 * 0x34),defender_slot,damage);
          *(uint *)(&DAT_006a5f74 + iVar1 * 0x120 + local_8 * 0x5b20) =
               iVar2 << 0x10 | *(uint *)(&g_MasterCardTypeTable + local_10 * 0x34);
        }
      }
      g_DuelModeFlags = g_DuelModeFlags | 2;
    }
  }
  return iVar1;
}

/*
 * Decompiled function: UI_PaintBigCardInfo
 * Entry Point: 00403250
 * Size: 955 bytes
 */


undefined4
UI_PaintBigCardInfo(int *arg_1,int arg_2,int arg_3,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,
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
      iVar2 = Rules_ParseFilter_0040360b
                        (local_28,-1,(char *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,arg_7,arg_8,
                         arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,arg_19
                        );
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
        iVar2 = DAT_006808bc;
        if (DAT_006808bc <= g_PlayerActiveCardCount) {
          iVar2 = g_PlayerActiveCardCount;
        }
        if ((iVar2 <= local_c) || (bVar1)) break;
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          if (arg_2 == 0) {
            local_10 = local_8;
            local_2c = local_c;
            bVar3 = true;
          }
          else if (arg_2 == 1) {
            bVar3 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) ==
                    DAT_006ff2e0;
            if (bVar3) {
              local_10 = (uint)(char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20];
              local_2c = *(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20);
            }
          }
          else if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0
                  ) {
            local_10 = (uint)(char)(&g_CardSlot_DamageReceived)[local_c * 0x120 + local_8 * 0x5b20];
            local_2c = *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_8 * 0x5b20);
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if ((bVar3) &&
             (iVar2 = Rules_ParseFilter_0040360b
                                (local_10,local_2c,(char *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,
                                 arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,
                                 arg_17,arg_18,arg_19), iVar2 != 0)) {
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

/*
 * Decompiled function: App_ProcessPendingMessages
 * Entry Point: 0040a3e1
 * Size: 65 bytes
 */


void App_ProcessPendingMessages(void)

{
  int iVar1;
  
  iVar1 = DAT_005239ec;
  while (iVar1 != 0) {
    Pic_Subsystem_0044b84b();
    iVar1 = DAT_0067bda0;
  }
  while (iVar1 = Mem_AllocOrFree_00408089(), iVar1 != 0) {
    FUN_0048ac2f();
  }
  return;
}
