
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
undefined8 * thunk_FUN_10002360();
extern int s_MAGICDECK_TradeSurfaceClass_10040560;
extern int s_MAGICDECK_DeckSurfaceClass_10040524;
extern int LAB_1000133e;
extern int LAB_100016a4;
extern int s_MAGICDECK_SideboardSurfaceClass_10040540;
int operator_delete();
int thunk_FUN_10001926();
extern int s_wavelet_pieces_has_illegal_value_100404bc;
extern int LAB_1000107d;
extern int lpbmi;
extern int DAT_1004c890;
extern int DAT_101cf334;
int thunk_FUN_10002a60();
int GetClientRect();
int FillRect();
int thunk_FUN_10002e20();
extern int DAT_1004c6d8;
extern int _DAT_1004c88c;
extern int DAT_1004046c;
extern int *PTR_DAT_10040448;
extern int _DAT_1004c888;
extern int _DAT_102151e4;
int thunk_FUN_10016850();

int thunk_FUN_10014a60();
int thunk_FUN_100030e0();
extern int DAT_100c7090;
extern int DAT_10103c90;
extern int DAT_1004c77c;
extern int DAT_1004c880;
extern int DAT_1004c700;
extern int DAT_1004c6e0;
extern int DAT_1004c6fc;
extern int DAT_10040450;
extern int DAT_1004c708;
int _strlwr();
int thunk_FUN_1000e156();

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
int Magic_TriggerCardEvent(int arg_1, int arg_2, int arg_3, int arg_4, int arg_5);

void Duel_DrawCardSprite(int arg_1, int arg_2, int arg_3);
int Duel_DrawString(int arg_1, uint arg_2, int arg_3);
undefined4 UI_SelectTargetCardDialog(void *arg1, uint arg2);

void EnterCriticalSection(void *cs);
void LeaveCriticalSection(void *cs);
void* thunk_FUN_10003410();
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
 * Decompiled function: DeckDll_LoadCardArtCatalogs
 * Entry Point: 10001f20
 * Size: 841 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t * DeckDll_LoadCardArtCatalogs(int arg_1,char *str_2,int arg_3)

{
  char cVar1;
  uint32_t uval_2;
  uint32_t uval_3;
  int val_4;
  int val_5;
  char *pcVar6;
  int32_t *puVar7;
  char *pcVar8;
  char *pcVar9;
  int32_t *puVar10;
  char local_40c [260];
  char local_308 [264];
  char local_200 [256];
  char local_100 [256];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  _splitpath(str_2,(char *)0x0,local_40c,local_200,local_100);
  if (DAT_1004c6d4 == 0) {
    uval_2 = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = local_308;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uval_2 = 0xffffffff;
    pcVar6 = s_SmallArt_cat_10040480;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    val_4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (val_4 == 0) break;
      val_4 = val_4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = pcVar8 + -1;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_1004044c = thunk_FUN_1000dd80(local_308);
    uval_2 = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = local_308;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uval_2 = 0xffffffff;
    pcVar6 = s_MedArt_cat_10040470;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    val_4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (val_4 == 0) break;
      val_4 = val_4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = pcVar8 + -1;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_10040450 = thunk_FUN_1000dd80(local_308);
    DAT_1004c6d4 = 1;
  }
  val_4 = -1;
  pcVar6 = local_40c;
  do {
    if (val_4 == 0) break;
    val_4 = val_4 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  val_4 = DAT_1004044c;
  if ((arg_1 != 0) && (val_4 = DAT_10040450, arg_1 != 1)) {
    return (int32_t *)0x0;
  }
  uval_2 = 0xffffffff;
  pcVar6 = local_200;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = local_40c;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uval_2 = 0xffffffff;
  pcVar6 = local_100;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  val_5 = -1;
  pcVar6 = local_40c;
  do {
    pcVar8 = pcVar6;
    if (val_5 == 0) break;
    val_5 = val_5 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = pcVar8 + -1;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_10103c90 = val_4;
  _strlwr(local_40c);
  puVar7 = &DAT_1004c6e0;
  for (val_4 = 0x6c; val_4 != 0; val_4 = val_4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uval_2 = 0xffffffff;
  pcVar6 = str_2;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = (char *)&DAT_1004c77c;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_1004c880 = (int32_t *)&DAT_100c7090;
  val_4 = thunk_FUN_1000e156(DAT_10103c90,local_40c,(int *)&DAT_1004c880);
  if (val_4 != -1) {
    _DAT_1004c884 = val_4 + -0x9c;
    puVar7 = DAT_1004c880;
    puVar10 = &DAT_1004c6e0;
    for (val_4 = 0x27; val_4 != 0; val_4 = val_4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_1004c880 = DAT_1004c880 + 0x27;
    if (DAT_1004c708 == 4) {
      DAT_1004c6fc = DAT_1004c6fc * 2;
      DAT_1004c700 = DAT_1004c700 * 2;
    }
    if (arg_3 != 0) {
      _DAT_1004c88c = thunk_FUN_10002360(&DAT_1004c6e0,(undefined8 *)0x0);
      if (_DAT_1004c88c == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
        return (int32_t *)0x0;
      }
      _DAT_1004c888 = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
    }
    return &DAT_1004c6e0;
  }
  uval_2 = 0xffffffff;
  pcVar6 = (char *)&DAT_1004046c;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  val_4 = -1;
  pcVar6 = str_2;
  do {
    pcVar8 = pcVar6;
    if (val_4 == 0) break;
    val_4 = val_4 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = pcVar8 + -1;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  OutputDebugStringA(str_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  return (int32_t *)0x0;
}

/*
 * Decompiled function: DeckDll_ReleaseCardArtCatalogs
 * Entry Point: 10002340
 * Size: 14 bytes
 */


int32_t DeckDll_ReleaseCardArtCatalogs(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  return 0;
}

/*
 * Decompiled function: thunk_FUN_10002360
 * Entry Point: 1000143d
 * Size: 5 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * thunk_FUN_10002360(int *arg1,undefined8 *arg2)

{
  int *arg_1;
  int *arg_1_00;
  uint32_t uval_1;
  int val_2;
  int arg_8;
  int val_3;
  undefined8 *_Memory;
  undefined8 *puVar4;
  int val_5;
  int val_6;
  uint32_t uval_7;
  undefined8 *puVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  bool bVar12;
  int arg_4;
  int arg_9;
  int iStack_2c;
  int iStack_10;
  undefined8 *stack_arg;
  
  if (DAT_1004c6d8 == 0) {
    val_5 = -0x400;
    iVar9 = -0x3fc00;
    do {
      if ((iVar9 < 0) || (0xf708 < iVar9)) {
        if (iVar9 < 0x9f6) {
          PTR_DAT_10040448[val_5] = 0;
        }
        else {
          PTR_DAT_10040448[val_5] = 0xff;
        }
      }
      else {
        PTR_DAT_10040448[val_5] = (char)(iVar9 / 0xf8);
      }
      iVar9 = iVar9 + 0xff;
      val_5 = val_5 + 1;
    } while (iVar9 < 0x3fc01);
    DAT_1004c6d8 = 1;
  }
  bVar12 = arg2 != (undefined8 *)0x0;
  if (bVar12) {
    val_5 = arg1[0x24] + 2000;
    thunk_FUN_10014a60(arg2,(int)(val_5 + (val_5 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = malloc(arg1[0x24] + 2000);
    thunk_FUN_10014a60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_102151e4 = thunk_FUN_100030e0((int32_t *)arg2,arg1);
  val_5 = arg1[10];
  if (val_5 == 1) {
    stack_arg = (undefined8 *)0x1;
  }
  else if (val_5 == 4) {
    stack_arg = (undefined8 *)0x2;
  }
  else if (val_5 == 0x10) {
    stack_arg = (undefined8 *)0x4;
  }
  else {
    thunk_FUN_10016850(0,0x10040490,0x15e,s_wavelet_pieces_has_illegal_value_100404bc);
  }
  iVar9 = arg1[7] / (int)stack_arg;
  val_5 = arg1[9];
  iStack_10 = 0;
  val_2 = arg1[8] / (int)stack_arg;
  if (0 < arg1[10]) {
    arg_8 = iVar9 * iVar9;
    do {
      val_3 = val_2;
      val_6 = iVar9;
      if (*arg1 != 0) {
        val_6 = (arg1[10] == 1) + 1;
        val_3 = (val_2 / (int)stack_arg) / val_6;
        val_6 = (iVar9 / (int)stack_arg) / val_6;
      }
      arg_1 = (int *)((int)arg2 + (arg_8 + 0x40 + val_6 * val_6 * 2) * iStack_10 * 4);
      arg_1_00 = arg_1 + arg_8 + 0x20;
      thunk_FUN_10002a60(arg_1,iVar9,val_5);
      thunk_FUN_10002a60(arg_1_00,val_6,val_5);
      thunk_FUN_10002a60(arg_1_00 + val_6 * val_6 + 0x20,val_6,val_5);
      if (iStack_10 < arg1[10] / 2) {
        arg_9 = *arg1;
        arg_4 = iVar9;
        arg_8 = val_6;
      }
      else {
        arg_9 = *arg1;
        arg_4 = val_2;
        arg_8 = val_3;
        if (1 < arg1[10]) {
          arg_4 = arg1[8] - iVar9;
        }
      }
      _Memory = (undefined8 *)
                thunk_FUN_10002e20(&DAT_1004c890,arg_1,iVar9,arg_4,arg_1_00,
                                   arg_1_00 + val_6 * val_6 + 0x20,val_6,arg_8,arg_9);
      if (arg1[10] < 2) {
        puVar4 = _Memory;
        if (!bVar12) {
          iStack_10 = 0x1000267c;
          free(arg2);
          stack_arg = arg2;
        }
      }
      else {
        puVar4 = (undefined8 *)
                 ((int)arg2 +
                 ((iStack_10 / (int)stack_arg) * arg_9 + iStack_10 % (int)stack_arg)
                 * iVar9 * 3);
        if (0 < iVar9) {
          uval_1 = iVar9 * 3;
          puVar8 = _Memory;
          iStack_2c = iVar9;
          do {
            puVar11 = puVar4;
            puVar10 = puVar8;
            for (uval_7 = uval_1 >> 3; uval_7 != 0; uval_7 = uval_7 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            uval_7 = uval_1 & 7;
            if (uval_7 != 0) {
              for (; uval_7 != 0; uval_7 = uval_7 - 1) {
                *(uint8_t *)puVar11 = *(uint8_t *)puVar10;
                puVar10 = (undefined8 *)((int)puVar10 + 1);
                puVar11 = (undefined8 *)((int)puVar11 + 1);
              }
            }
            puVar8 = (undefined8 *)((int)puVar8 + uval_1);
            puVar4 = (undefined8 *)((int)puVar4 + arg_9 * 3);
            iStack_2c = iStack_2c + -1;
          } while (iStack_2c != 0);
        }
        iStack_10 = 0x10002666;
        free(_Memory);
        puVar4 = arg2;
        stack_arg = _Memory;
      }
      arg2 = puVar4;
      iStack_10 = iStack_10 + 1;
    } while (iStack_10 < arg1[10]);
  }
  return arg2;
}

/*
 * Decompiled function: DeckDll_RenderCardPreview
 * Entry Point: 10003300
 * Size: 92 bytes
 */


int32_t DeckDll_RenderCardPreview(HWND hwnd)

{
  HDC hDC;
  HBRUSH hbr;
  tagRECT local_10;
  
  if (hwnd == (HWND)0x0) {
    return 0;
  }
  hDC = GetDC(hwnd);
  GetClientRect(hwnd,&local_10);
  hbr = GetStockObject(0);
  FillRect(hDC,&local_10,hbr);
  ReleaseDC(hwnd,hDC);
  return 1;
}

/*
 * Decompiled function: DeckDll_BlitCardArtwork
 * Entry Point: 10003380
 * Size: 104 bytes
 */


int DeckDll_BlitCardArtwork(HWND hwnd,void *arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  BITMAPINFO *lpbmi;
  HDC hdc;
  int val_1;
  
  lpbmi = (BITMAPINFO *)thunk_FUN_10003410(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_1 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,arg_2,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  return val_1;
}

/*
 * Decompiled function: thunk_FUN_10004070
 * Entry Point: 10001226
 * Size: 5 bytes
 */


int32_t thunk_FUN_10004070(void)

{
  ATOM AVar1;
  int32_t uval_2;
  WNDCLASSA WStack_2c;
  
  WStack_2c.style = 0;
  WStack_2c.lpfnWndProc = (WNDPROC)&LAB_1000107d;
  WStack_2c.cbClsExtra = 0;
  WStack_2c.cbWndExtra = 0;
  WStack_2c.hInstance = DAT_101cf334;
  WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  WStack_2c.hbrBackground = (HBRUSH)0x0;
  WStack_2c.lpszMenuName = (LPCSTR)0x0;
  WStack_2c.lpszClassName = s_MAGICDECK_DeckSurfaceClass_10040524;
  AVar1 = RegisterClassA(&WStack_2c);
  if (AVar1 == 0) {
    uval_2 = 0;
  }
  else {
    WStack_2c.style = 0;
    WStack_2c.lpfnWndProc = (WNDPROC)&LAB_100016a4;
    WStack_2c.cbClsExtra = 0;
    WStack_2c.cbWndExtra = 0;
    WStack_2c.hInstance = DAT_101cf334;
    WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    WStack_2c.hbrBackground = (HBRUSH)0x0;
    WStack_2c.lpszMenuName = (LPCSTR)0x0;
    WStack_2c.lpszClassName = s_MAGICDECK_SideboardSurfaceClass_10040540;
    AVar1 = RegisterClassA(&WStack_2c);
    if (AVar1 == 0) {
      uval_2 = 0;
    }
    else {
      WStack_2c.style = 0;
      WStack_2c.lpfnWndProc = (WNDPROC)&LAB_1000133e;
      WStack_2c.cbClsExtra = 0;
      WStack_2c.cbWndExtra = 0;
      WStack_2c.hInstance = DAT_101cf334;
      WStack_2c.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      WStack_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
      WStack_2c.hbrBackground = (HBRUSH)0x0;
      WStack_2c.lpszMenuName = (LPCSTR)0x0;
      WStack_2c.lpszClassName = s_MAGICDECK_TradeSurfaceClass_10040560;
      AVar1 = RegisterClassA(&WStack_2c);
      if (AVar1 == 0) {
        uval_2 = 0;
      }
      else {
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}

/*
 * Decompiled function: DeckDll_SideboardWndProc
 * Entry Point: 10004b20
 * Size: 57 bytes
 */


int * __thiscall DeckDll_SideboardWndProc(void *this,uint8_t arg_2)

{
  thunk_FUN_10001926(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/*
 * Decompiled function: DeckDll_LoadDeckFile
 * Entry Point: 10006500
 * Size: 157 bytes
 */


int32_t __cdecl DeckDll_LoadDeckFile(int32_t arg_1)

{
  int32_t local_8;
  
  switch(arg_1) {
  case 0:
    local_8 = 0xffffffff;
    break;
  case 1:
    local_8 = 0;
    break;
  case 2:
    local_8 = 1;
    break;
  case 3:
    local_8 = 2;
    break;
  case 4:
    local_8 = 3;
    break;
  case 5:
  case 6:
  case 7:
    local_8 = 4;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    local_8 = 5;
    break;
  default:
    local_8 = 6;
  }
  return local_8;
}
