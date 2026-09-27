
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int PTR_s_statscrn_wav_10011548;
extern int this;
extern int LAB_10002bd1;
extern int DAT_1001168c;
extern int s_statscrn_wav_10011bc4;
extern int CPrintPreviewState;
extern int DAT_10011688;
extern int PTR_s_Whit_hit_avi_10011558;
int thunk_FUN_100016c1();
int thunk_FUN_10009ace();
int thunk_FUN_10009b0f();
int thunk_FUN_100097f0();
int thunk_FUN_10009824();
int thunk_FUN_1000308a();
extern int DAT_10011556;
extern int PTR_s_cball00_avi_100115a8;
extern int s_statscrn_wav_10011bb4;
extern int DAT_10013174;
extern int DAT_10011554;
extern int LAB_10001019;
extern int PTR_DAT_10011544;
extern int DAT_1001e878;
int thunk_FUN_10001c1a();
int thunk_FUN_1000432f();
int thunk_FUN_100097b0();
int thunk_FUN_10009a89();
int thunk_FUN_100099ba();
int thunk_FUN_100099ff();
int DialogBoxParamA();
extern int DLGPROC;
extern int DAT_10013184;
extern int _DAT_1001314c;
extern int _DAT_10011794;
extern int _DAT_10013160;
extern int _DAT_10013158;
extern int _DAT_10013164;
extern int _DAT_10013148;
extern int _DAT_1001315c;
extern int DAT_1001317c;
extern int lpDialogFunc;
extern int _DAT_10013154;
extern int PTR_s___statwin__10011540;
extern int DAT_10013140;
int thunk_FUN_10004512();
int thunk_FUN_100035b2();
extern int PTR_s_STATWINCLASS_100117a0;
extern int _DAT_10013144;
extern int DAT_1001178c;
extern int DAT_10013150;
extern int LAB_100010fa;
extern int _DAT_10013140;
extern int DAT_1001316c;
extern int DAT_10011790;
int operator_new();
int UnregisterClassA();
int thunk_FUN_1000160f();
int thunk_FUN_10004407();
int thunk_FUN_10009640();
int thunk_FUN_10009766();
extern int LAB_10002188;
extern int DAT_10011520;
extern int DAT_10011528;
extern int DAT_1001e8a4;
extern int DAT_100117a4;
int thunk_FUN_100041b0();
int thunk_FUN_10001cdc();

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
extern FARPROC *DAT_1001e8a0;
extern void* DAT_1001e8a0_ptr;
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
 * Decompiled function: thunk_FUN_100014b0
 * Entry Point: 1000108c
 * Size: 5 bytes
 */


int __cdecl thunk_FUN_100014b0(int arg_1,int32_t arg_2,uint32_t arg_3)

{
  int val_1;
  FARPROC pFVar2;
  int iStack_c;
  
  if (DAT_10011524 == 0) {
    DAT_1001e87c = LoadLibraryA(PTR_s_magsnd_1001152c);
    if (DAT_1001e87c == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (iStack_c = 0; iStack_c < 0x1b; iStack_c = iStack_c + 1) {
        pFVar2 = GetProcAddress(DAT_1001e87c,(LPCSTR)(iStack_c + 1U & 0xffff));
        ((FARPROC*)&DAT_1001e8a0)[iStack_c] = pFVar2;
        if ((&DAT_1001e8a0)[iStack_c] == (code *)0x0) {
          FreeLibrary(DAT_1001e87c);
          thunk_FUN_10001cdc();
          return 4;
        }
      }
      if ((arg_1 == 0) && ((arg_3 & 2) == 0)) {
        FreeLibrary(DAT_1001e87c);
        thunk_FUN_10001cdc();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_1001e8a0)(arg_1,arg_2,arg_3);
        if (val_1 == 0) {
          DAT_10011528 = 1;
          if ((arg_3 & 2) != 0) {
            DAT_10011520 = 1;
          }
          DAT_10011524 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_1001e87c);
          thunk_FUN_10001cdc();
        }
      }
    }
  }
  else {
    val_1 = 2;
  }
  return val_1;
}

/*
 * Decompiled function: StatWin_FreeSoundDll
 * Entry Point: 1000160f
 * Size: 118 bytes
 */


void StatWin_FreeSoundDll(void)

{
  if (DAT_10011524 != 0) {
    DAT_10011524 = 0;
    if ((DAT_10011528 != 0) && (DAT_10011520 == 0)) {
      (*DAT_1001e8a4)();
    }
    FreeLibrary(DAT_1001e87c);
    thunk_FUN_10001cdc();
    DAT_1001e87c = (HMODULE)0x0;
    DAT_10011520 = 0;
    DAT_10011528 = 0;
  }
  return;
}

/*
 * Decompiled function: StatWin_RegisterWindowClass
 * Entry Point: 10001f30
 * Size: 583 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t StatWin_RegisterWindowClass(HINSTANCE hInstance,int32_t arg_2)

{
  int32_t *ptr_1;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_1c;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10002188;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  switch(arg_2) {
  case 0:
    if (DAT_100117a4 != (int32_t *)0x0) {
      if (DAT_100117a4 != (int32_t *)0x0) {
        thunk_FUN_100041b0(DAT_100117a4,1);
      }
      DAT_100117a4 = (int32_t *)0x0;
    }
    if (DAT_1001178c != 0) {
      thunk_FUN_1000160f();
    }
    if (DAT_10011790 != 0) {
      thunk_FUN_10009766();
    }
    UnregisterClassA(PTR_s_STATWINCLASS_100117a0,DAT_10013150);
    break;
  case 1:
    DAT_1001316c = hInstance;
    ptr_1 = operator_new(0x28);
    local_8 = 0;
    if (ptr_1 == (int32_t *)0x0) {
      local_1c = (int32_t *)0x0;
    }
    else {
      local_1c = thunk_FUN_10004407(ptr_1);
    }
    local_8 = 0xffffffff;
    DAT_100117a4 = local_1c;
    if (local_1c == (int32_t *)0x0) {
      uval_2 = 0;
      goto LAB_10002192;
    }
    val_1 = thunk_FUN_10009640(0,DAT_1001316c,0);
    DAT_10011790 = (uint32_t)(val_1 == 0);
    val_1 = thunk_FUN_100014b0(0,0,3);
    DAT_1001178c = (uint32_t)(val_1 == 0);
    _DAT_10013140 = 3;
    _DAT_10013144 = &LAB_100010fa;
    _DAT_10013148 = 0;
    _DAT_1001314c = 0;
    DAT_10013150 = DAT_1001316c;
    _DAT_10013154 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_10013158 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    _DAT_1001315c = GetStockObject(4);
    _DAT_10013160 = 0;
    _DAT_10013164 = PTR_s_STATWINCLASS_100117a0;
    RegisterClassA((WNDCLASSA *)&DAT_10013140);
    break;
  case 2:
    break;
  case 3:
  }
  uval_2 = 1;
LAB_10002192:
  *unaff_FS_OFFSET = local_10;
  return uval_2;
}

/*
 * Decompiled function: StatWin_SetAssetPath
 * Entry Point: 100021a3
 * Size: 97 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl StatWin_SetAssetPath(int32_t *ptr_1)

{
  int val_1;
  
  val_1 = thunk_FUN_10004512(DAT_100117a4,ptr_1,0);
  if (val_1 == 0) {
    _DAT_10011794 = 1;
    thunk_FUN_100035b2();
    *PTR_s___statwin__10011540 = DAT_1001317c;
    val_1 = 0;
  }
  else {
    _DAT_10011794 = 0;
  }
  return val_1;
}

/*
 * Decompiled function: StatWin_ProcessMessagePump
 * Entry Point: 100023fd
 * Size: 67 bytes
 */


int32_t StatWin_ProcessMessagePump(void)

{
  BOOL BVar1;
  tagMSG local_20;
  
  BVar1 = PeekMessageA(&local_20,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&local_20);
    DispatchMessageA(&local_20);
  }
  return 0;
}

/*
 * Decompiled function: thunk_FUN_1000245c
 * Entry Point: 1000105a
 * Size: 5 bytes
 */


int32_t thunk_FUN_1000245c(void)

{
  BOOL BVar1;
  HWND hWndParent;
  DLGPROC lpDialogFunc;
  LPARAM dwInitParam;
  tagMSG tStack_24;
  int32_t uStack_8;
  
  uStack_8 = 0;
  BVar1 = PeekMessageA(&tStack_24,(HWND)0x0,0,0,1);
  if (BVar1 != 0) {
    TranslateMessage(&tStack_24);
    if ((tStack_24.message == 0x205) && (DAT_10013184 != 0)) {
      dwInitParam = 0;
      lpDialogFunc = (DLGPROC)&LAB_10001019;
      hWndParent = (HWND)thunk_FUN_10001c1a();
      DialogBoxParamA(DAT_1001316c,(LPCSTR)0x65,hWndParent,lpDialogFunc,dwInitParam);
    }
    if ((tStack_24.message == 0x202) || (tStack_24.message == 0x100)) {
      uStack_8 = 1;
    }
    DispatchMessageA(&tStack_24);
  }
  return uStack_8;
}

/*
 * Decompiled function: StatWin_PlayVictorySound
 * Entry Point: 100024fd
 * Size: 397 bytes
 */


void __cdecl StatWin_PlayVictorySound(int arg_1)

{
  int val_1;
  char local_114 [256];
  uint32_t local_14;
  short local_10;
  short local_e;
  int32_t local_c;
  int32_t local_8;
  
  local_14 = (uint32_t)*(uint8_t *)(arg_1 + 0x2d);
  local_8 = 5;
  thunk_FUN_1000432f(local_114,PTR_s___statwin__10011540,
                     (&PTR_s_cball00_avi_100115a8)[*(uint8_t *)(arg_1 + 0x2e)]);
  val_1 = thunk_FUN_100097b0(local_114,&local_c,&local_10,3);
  if (val_1 == 0) {
    thunk_FUN_1000432f(local_114,PTR_DAT_10011544,s_statscrn_wav_10011bb4);
    thunk_FUN_100099ff(*(int32_t *)(DAT_100117a4 + 0xc),local_c);
    thunk_FUN_10009a89(local_c,1);
    local_10 = (short)*(int32_t *)(DAT_100117a4 + 0x14) + DAT_10011554;
    local_e = DAT_10011556 + (short)*(int32_t *)(DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(DAT_10013174,&local_10);
    *DAT_1001e878 = 1;
    thunk_FUN_1000432f(local_114,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
    thunk_FUN_1000308a(local_114);
    thunk_FUN_10009ace(local_c);
    thunk_FUN_10009824(local_c);
    do {
      val_1 = thunk_FUN_10009b0f(local_c);
    } while (val_1 != 0);
    thunk_FUN_10009ace(local_c);
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    thunk_FUN_100097f0(local_c);
    thunk_FUN_100016c1(0xff);
  }
  return;
}

/*
 * Decompiled function: thunk_FUN_1000268a
 * Entry Point: 1000105f
 * Size: 5 bytes
 */


void __cdecl thunk_FUN_1000268a(int arg_1)

{
  int val_1;
  CPrintPreviewState *this;
  HWND hWnd;
  int32_t *unaff_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int *piStack_148;
  char acStack_140 [256];
  int *piStack_40;
  uint32_t uStack_3c;
  short sStack_38;
  short sStack_36;
  int32_t uStack_34;
  int32_t uStack_30;
  DWORD DStack_2c;
  HANDLE pvStack_28;
  int32_t uStack_24;
  int iStack_20;
  int iStack_1c;
  int32_t uStack_18;
  int32_t uStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10002bd1;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_3c = (uint32_t)*(uint8_t *)(arg_1 + 0x2d);
  uStack_24 = 5;
  thunk_FUN_1000432f(acStack_140,PTR_s___statwin__10011540,
                     (&PTR_s_cball00_avi_100115a8)[*(uint8_t *)(arg_1 + 0x2e)]);
  val_1 = thunk_FUN_100097b0(acStack_140,&uStack_30,&sStack_38,1);
  if (val_1 == 0) {
    thunk_FUN_1000432f(acStack_140,PTR_DAT_10011544,s_statscrn_wav_10011bc4);
    thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),uStack_30);
    thunk_FUN_10009a89(uStack_30,1);
    sStack_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + DAT_10011554;
    sStack_36 = DAT_10011556 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(DAT_10013174,&sStack_38);
    uStack_34 = uStack_30;
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      sStack_38 = (short)*(int32_t *)(&DAT_10011688 + uStack_3c * 0x10);
      sStack_36 = (short)*(int32_t *)(&DAT_1001168c + uStack_3c * 0x10);
      thunk_FUN_1000432f(acStack_140,PTR_s___statwin__10011540,
                         (&PTR_s_Whit_hit_avi_10011558)[uStack_3c]);
      val_1 = thunk_FUN_100097b0(acStack_140,&uStack_34,&sStack_38,5);
      if (val_1 == 0) {
        thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),uStack_34);
        thunk_FUN_10009a89(uStack_34,1);
        sStack_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + sStack_38;
        sStack_36 = sStack_36 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
        thunk_FUN_100099ba(uStack_34,&sStack_38);
      }
    }
    pvStack_28 = GetCurrentProcess();
    DStack_2c = GetPriorityClass(pvStack_28);
    thunk_FUN_1000432f(acStack_140,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
    thunk_FUN_1000308a(acStack_140);
    thunk_FUN_10009ace(uStack_30);
    thunk_FUN_10009824(uStack_30);
    *DAT_1001e878 = 1;
    DAT_10013180 = 0;
    while (val_1 = thunk_FUN_10009b0f(uStack_30), val_1 != 0) {
      val_1 = thunk_FUN_1000245c();
      if (val_1 != 0) {
        thunk_FUN_10009865(uStack_30);
        break;
      }
      Sleep(0);
    }
    *DAT_1001e878 = 0;
    thunk_FUN_10009ace(uStack_30);
    this = operator_new(0x18);
    uStack_8 = 0;
    if (this == (CPrintPreviewState *)0x0) {
      piStack_148 = (int *)0x0;
    }
    else {
      piStack_148 = (int *)CPrintPreviewState::CPrintPreviewState(this);
    }
    uStack_8 = 0xffffffff;
    piStack_40 = piStack_148;
    thunk_FUN_10004200(piStack_148,0xff00);
    thunk_FUN_1000432f(acStack_140,PTR_s_statwin__10012ac0,
                       s_wht_mask_bmp_10011d88 + uStack_3c * 0x110);
    val_1 = uStack_3c * 0x110;
    iStack_20 = *(int *)(&DAT_10011e88 + val_1);
    iStack_1c = *(int *)(&DAT_10011e8c + val_1);
    uStack_18 = *(int32_t *)(&DAT_10011e90 + val_1);
    uStack_14 = *(int32_t *)(&DAT_10011e94 + val_1);
    val_1 = (**(code **)*piStack_40)(0,acStack_140,0x18);
    if (val_1 == 1) {
      (**(code **)(*piStack_40 + 0x18))
                (*(int32_t *)((int)DAT_100117a4 + 0xc),
                 *(int *)((int)DAT_100117a4 + 0x14) + iStack_20,
                 *(int *)((int)DAT_100117a4 + 0x18) + iStack_1c,uStack_18,uStack_14,0,0);
      if (piStack_40 != (int *)0x0) {
        thunk_FUN_10004250(piStack_40,1);
      }
      piStack_40 = (int *)0x0;
    }
    val_1 = thunk_FUN_10007b3b(DAT_100117a4,(int *)(&DAT_10011688 + uStack_3c * 0x10),uStack_3c);
    if (val_1 == 0) {
      thunk_FUN_10009a44(*(int32_t *)((int)DAT_100117a4 + 0x10),uStack_34);
      thunk_FUN_10004200(*(void **)((int)DAT_100117a4 + 0x10),0);
    }
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      thunk_FUN_10009824(uStack_34);
      DAT_10013180 = 0;
      while (val_1 = thunk_FUN_10009b0f(uStack_34), val_1 != 0) {
        val_1 = thunk_FUN_1000245c();
        if (val_1 != 0) {
          thunk_FUN_10009865(uStack_34);
          break;
        }
        Sleep(0);
      }
    }
    thunk_FUN_100049cf(DAT_100117a4,arg_1,1);
    thunk_FUN_100017b0(0xff);
    thunk_FUN_10009ace(uStack_34);
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    SetPriorityClass(pvStack_28,DStack_2c);
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      thunk_FUN_100097f0(uStack_34);
    }
    thunk_FUN_100097f0(uStack_30);
    thunk_FUN_100016c1(0xff);
    lParam = 0;
    wParam = 0;
    Msg = 0x12;
    hWnd = (HWND)thunk_FUN_10001c1a();
    SendMessageA(hWnd,Msg,wParam,lParam);
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}

/*
 * Decompiled function: StatWin_CreateStatusWindow
 * Entry Point: 10002be9
 * Size: 335 bytes
 */


void StatWin_CreateStatusWindow(void)

{
  BOOL BVar1;
  char local_134 [256];
  int local_34;
  tagMSG local_30;
  HWND local_14;
  int32_t local_10;
  int local_c;
  HWND local_8;
  
  DAT_10013184 = 1;
  if (DAT_1001178c == 0) {
    local_8 = (HWND)0x0;
  }
  else {
    local_8 = (HWND)thunk_FUN_10001c1a();
  }
  local_c = GetSystemMetrics(0);
  local_34 = GetSystemMetrics(1);
  local_14 = CreateWindowExA(0,PTR_s_STATWINCLASS_100117a0,(LPCSTR)0x0,0x90000000,0,0,local_c,
                             local_34,local_8,(HMENU)0x0,DAT_1001316c,(LPVOID)0x0);
  SetFocus(local_14);
  SetForegroundWindow(local_14);
  thunk_FUN_1000432f(local_134,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
  thunk_FUN_1000308a(local_134);
  ShowWindow(local_14,1);
  UpdateWindow(local_14);
  DAT_10013180 = 0;
  local_10 = 0;
  while (DAT_10013180 == 0) {
    BVar1 = PeekMessageA(&local_30,(HWND)0x0,0,0,1);
    if (BVar1 != 0) {
      TranslateMessage(&local_30);
      DispatchMessageA(&local_30);
    }
  }
  thunk_FUN_100017b0(0xff);
  DestroyWindow(local_14);
  DAT_10013184 = 0;
  return;
}

/*
 * Decompiled function: StatWin_WindowProc
 * Entry Point: 10002d38
 * Size: 532 bytes
 */


LRESULT StatWin_WindowProc(HWND x,uint32_t y,WPARAM width,LPARAM height)

{
  HDC pHVar1;
  LRESULT LVar2;
  
  if (y < 0x15) {
    if (y == 0x14) {
      if (DAT_1001179c != 0) {
        DefWindowProcA(x,0x14,width,height);
        pHVar1 = GetDC(x);
        DAT_10011798 = SetSystemPaletteUse(pHVar1,1);
        ReleaseDC(x,pHVar1);
        DAT_1001179c = 0;
      }
      thunk_FUN_10002f86(x);
    }
    else {
      switch(y) {
      case 1:
        DAT_1001179c = 1;
        LVar2 = DefWindowProcA(x,y,width,height);
        return LVar2;
      case 2:
        pHVar1 = GetDC(x);
        SetSystemPaletteUse(pHVar1,DAT_10011798);
        ReleaseDC(x,pHVar1);
        DAT_1001179c = 1;
        break;
      default:
        goto switchD_10002ed5_caseD_3;
      case 5:
        InvalidateRect(x,(RECT *)0x0,0);
        break;
      case 7:
        break;
      case 8:
        break;
      case 0xf:
        InvalidateRect(x,(RECT *)0x0,0);
      }
    }
  }
  else if (y < 0x203) {
    if ((y != 0x202) && (y != 0x100)) {
switchD_10002ed5_caseD_3:
      LVar2 = DefWindowProcA(x,y,width,height);
      return LVar2;
    }
    DAT_10013180 = 1;
  }
  else if (y == 0x205) {
    DialogBoxParamA(DAT_1001316c,(LPCSTR)0x65,x,(DLGPROC)&LAB_10001019,0);
  }
  else {
    if (y != 0x311) goto switchD_10002ed5_caseD_3;
    InvalidateRect(x,(RECT *)0x0,0);
  }
  if (DAT_100117c8 == 0) {
    LVar2 = 0;
  }
  else {
    LVar2 = DefWindowProcA(x,y,width,height);
  }
  return LVar2;
}

/*
 * Decompiled function: StatWin_DrawDibRender
 * Entry Point: 10002f86
 * Size: 260 bytes
 */


void __cdecl StatWin_DrawDibRender(HWND hwnd)

{
  code *char_ptr_1;
  HDC hDC;
  int32_t uval_2;
  int val_3;
  int32_t uval_4;
  int32_t uval_5;
  int32_t uval_6;
  int32_t uval_7;
  
  hDC = GetDC(hwnd);
  uval_2 = DrawDibOpen();
  if (*(int *)(DAT_100117a4 + 0xc) == 0) {
    val_3 = _CrtDbgReport(2,s_G__NewMagic_tstvid_statwin_cpp_10011bd4,0x302,0,0);
    if (val_3 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  uval_4 = thunk_FUN_100042a0(*(int *)(DAT_100117a4 + 0xc));
  uval_5 = (**(code **)(**(int **)(DAT_100117a4 + 0xc) + 8))();
  uval_6 = (**(code **)(**(int **)(DAT_100117a4 + 0xc) + 0xc))();
  uval_7 = thunk_FUN_100042d0(*(int *)(DAT_100117a4 + 0xc));
  DrawDibDraw(uval_2,hDC,0,0,uval_5,uval_6,uval_4,uval_7,0,0,uval_5,uval_6,0);
  ReleaseDC(hwnd,hDC);
  DrawDibClose(uval_2);
  return;
}
