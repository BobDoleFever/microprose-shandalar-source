
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
extern int DAT_0070550c;
extern int DAT_007039e4;
extern int DAT_00705504;
extern int DAT_007039e0;
extern int DAT_00705500;
extern int DAT_007045e4;
extern int DAT_00705508;
extern int DAT_007039e8;
extern int DAT_0070a130;
extern int DAT_00532804;
extern int DAT_0070a880;
extern int DAT_007051e0;
extern int DAT_00532550;
extern int DAT_0070a890;
extern int g_DisplaySurfaceWork;
extern int PTR_DAT_00532560;
int Surface_GetPixelValue();
extern int DAT_00617580;
extern int DAT_0062314c;
extern int FUN_00472d0a;
extern int DAT_00680774;
extern int FUN_004f5ec4;
extern int DAT_0070a850;
extern BITMAPINFO *DAT_00622930;
extern int DAT_005f76d0;
int GetWindowLongA();
int GetWindowThreadProcessId();

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
 * Decompiled function: GDI_DrawBitmapToHDC
 * Entry Point: 004709ae
 * Size: 104 bytes
 */


undefined4 GDI_DrawBitmapToHDC(int hdc,int point,HANDLE hBitmap)

{
  undefined4 uVar1;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  
  if (((hdc == 0) || (point == 0)) || (hBitmap == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    GetObjectA(hBitmap,0x18,local_1c);
    uVar1 = FUN_00470a16((HDC)hdc,(int *)point,hBitmap,0,0,local_18,local_14);
  }
  return uVar1;
}

/*
 * Decompiled function: GDI_DestroyDIBSection
 * Entry Point: 00471395
 * Size: 145 bytes
 */


void GDI_DestroyDIBSection(HANDLE hDIBSection)

{
  char local_254 [500];
  HANDLE local_60;
  undefined1 local_5c [20];
  int local_48;
  HANDLE local_10;
  int local_c;
  int local_8;
  
  if (hDIBSection != (HANDLE)0x0) {
    GetObjectA(hDIBSection,0x54,local_5c);
    local_60 = local_10;
    local_8 = local_48 + local_c;
    DeleteObject(hDIBSection);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_254,s__08x_DestroyDIBSection__file_map_004f9804,hDIBSection,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}

/*
 * Decompiled function: GDI_DestroyDIBSection_Magic
 * Entry Point: 004f4548
 * Size: 146 bytes
 */


void GDI_DestroyDIBSection_Magic(HANDLE hDIBSection)

{
  char local_254 [500];
  HANDLE local_60;
  undefined1 local_5c [20];
  int local_48;
  HANDLE local_10;
  int local_c;
  int local_8;
  
  if (hDIBSection != (HANDLE)0x0) {
    GetObjectA(hDIBSection,0x54,local_5c);
    local_60 = local_10;
    local_8 = local_48 + local_c;
    DeleteObject(hDIBSection);
    if (local_60 != (HANDLE)0x0) {
      CloseHandle(local_60);
    }
  }
  if (DAT_006b157c != 0) {
    sprintf(local_254,s__08x_DestroyDIBSection__file_map_00530204,hDIBSection,local_60);
    OutputDebugStringA(local_254);
  }
  return;
}

/*
 * Decompiled function: GDI_RealizeAndFlushPalette
 * Entry Point: 004707a4
 * Size: 79 bytes
 */


void GDI_RealizeAndFlushPalette(HDC hdc)

{
  SelectPalette(hdc,DAT_005f76d0,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_00617580);
  SetStretchBltMode(hdc,3);
  return;
}

/*
 * Decompiled function: GDI_RealizeAndFlushPalette_Magic
 * Entry Point: 004f3955
 * Size: 79 bytes
 */


void GDI_RealizeAndFlushPalette_Magic(HDC hdc)

{
  SelectPalette(hdc,DAT_00680774,0);
  RealizePalette(hdc);
  GdiFlush();
  SetDIBColorTable(hdc,0,0x100,(RGBQUAD *)&DAT_006a4b70);
  SetStretchBltMode(hdc,3);
  return;
}

/*
 * Decompiled function: GDI_RealizePaletteTree
 * Entry Point: 00472b60
 * Size: 421 bytes
 */


undefined4 GDI_RealizePaletteTree(HWND hwnd,uint y,HWND param_3,undefined4 arg_4)

{
  uint uVar1;
  UINT UVar2;
  HDC hdc;
  undefined4 uVar3;
  HWND local_38;
  uint local_34;
  HWND local_30;
  undefined4 local_2c;
  DWORD local_1c;
  HDC local_18;
  DWORD local_14;
  DWORD local_10;
  HWND local_c;
  DWORD local_8;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_005f76d0);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_005f76d0,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uVar3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar3 = 0;
  }
  else {
    local_c = param_3;
    if (hwnd != param_3) {
      local_14 = GetWindowThreadProcessId(param_3,&local_8);
      local_1c = GetWindowThreadProcessId(hwnd,&local_10);
      if (local_10 == local_8) {
        uVar1 = GetWindowLongA(hwnd,-0x10);
        if ((uVar1 & 0x40000000) == 0) {
          local_18 = GetDC(hwnd);
          SelectPalette(local_18,DAT_005f76d0,1);
          UVar2 = RealizePalette(local_18);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,local_18);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      local_38 = hwnd;
      local_34 = y;
      local_30 = param_3;
      local_2c = arg_4;
      EnumChildWindows(hwnd,FUN_00472d0a,(LPARAM)&local_38);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/*
 * Decompiled function: GDI_RealizePaletteTree_Magic
 * Entry Point: 004f5d1a
 * Size: 421 bytes
 */


undefined4 GDI_RealizePaletteTree_Magic(HWND hwnd,uint y,HWND param_3,undefined4 arg_4)

{
  uint uVar1;
  UINT UVar2;
  HDC hdc;
  undefined4 uVar3;
  HWND local_38;
  uint local_34;
  HWND local_30;
  undefined4 local_2c;
  DWORD local_1c;
  HDC local_18;
  DWORD local_14;
  DWORD local_10;
  HWND local_c;
  DWORD local_8;
  
  if (y == 0x30f) {
    UnrealizeObject(DAT_00680774);
    hdc = GetDC(hwnd);
    SelectPalette(hdc,DAT_00680774,0);
    UVar2 = RealizePalette(hdc);
    if (UVar2 != 0) {
      InvalidateRect(hwnd,(RECT *)0x0,1);
    }
    ReleaseDC(hwnd,hdc);
    uVar3 = 1;
  }
  else if ((y < 0x310) || (0x311 < y)) {
    uVar3 = 0;
  }
  else {
    local_c = param_3;
    if (hwnd != param_3) {
      local_14 = GetWindowThreadProcessId(param_3,&local_8);
      local_1c = GetWindowThreadProcessId(hwnd,&local_10);
      if (local_10 == local_8) {
        uVar1 = GetWindowLongA(hwnd,-0x10);
        if ((uVar1 & 0x40000000) == 0) {
          local_18 = GetDC(hwnd);
          SelectPalette(local_18,DAT_00680774,1);
          UVar2 = RealizePalette(local_18);
          if (UVar2 != 0) {
            InvalidateRect(hwnd,(RECT *)0x0,1);
          }
          ReleaseDC(hwnd,local_18);
        }
      }
      else {
        InvalidateRect(hwnd,(RECT *)0x0,1);
      }
    }
    if (y == 0x311) {
      local_38 = hwnd;
      local_34 = y;
      local_30 = param_3;
      local_2c = arg_4;
      EnumChildWindows(hwnd,FUN_004f5ec4,(LPARAM)&local_38);
    }
    uVar3 = 0;
  }
  return uVar3;
}

/*
 * Decompiled function: Surface_BlitToDevice
 * Entry Point: 0050dce0
 * Size: 853 bytes
 */


void Surface_BlitToDevice(int *arg_1,uint arg_2,int arg_3,uint arg_4,DWORD arg_5,int *arg_6,int arg_7,
                 int arg_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  RGBQUAD *pRVar11;
  undefined8 *arg_2_00;
  RGBQUAD *pRVar12;
  undefined8 *arg_2_01;
  int local_4;
  
  iVar1 = (&DAT_0070a850)[*arg_1];
  iVar2 = (&DAT_0070a850)[*arg_6];
  if (DAT_0062314c == 0) {
    DAT_00622930 = (BITMAPINFO *)0;
    DAT_0062314c = 1;
  }
  (DAT_00622930->bmiHeader).biWidth = *(LONG *)(iVar1 + 0x20);
  if (arg_3 == 0) {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  else {
    (DAT_00622930->bmiHeader).biHeight = *(LONG *)(iVar1 + 0x24);
  }
  if (*arg_6 == 0) {
    if (((arg_2 & 7) == 0) && (DAT_00532550 != 0)) {
      if (DAT_0070a880 != 8) {
        pRVar11 = (RGBQUAD *)&DAT_0070a890;
        pRVar12 = DAT_00622930->bmiColors;
        for (iVar10 = 0x100; iVar10 != 0; iVar10 = iVar10 + -1) {
          *pRVar12 = *pRVar11;
          pRVar11 = pRVar11 + 1;
          pRVar12 = pRVar12 + 1;
        }
      }
      arg_2_00 = (undefined8 *)(arg_3 * *(int *)(iVar1 + 0x20) + arg_2 + *(int *)(iVar1 + 0x18));
      arg_2_01 = (undefined8 *)
                 ((arg_3 + arg_5 + -1) * *(int *)(iVar1 + 0x20) + arg_2 + *(int *)(iVar1 + 0x18));
      local_4 = (int)arg_5 / 2;
      if (0 < local_4) {
        do {
          Mem_AllocOrFree_004f1e20((undefined8 *)PTR_DAT_00532560,arg_2_00,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_00,arg_2_01,arg_4);
          Mem_AllocOrFree_004f1e20(arg_2_01,(undefined8 *)PTR_DAT_00532560,arg_4);
          arg_2_00 = (undefined8 *)((int)arg_2_00 + *(int *)(iVar1 + 0x20));
          arg_2_01 = (undefined8 *)((int)arg_2_01 - *(int *)(iVar1 + 0x20));
          local_4 = local_4 + -1;
        } while (local_4 != 0);
      }
      SetDIBitsToDevice(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,arg_2,arg_3,0,
                        *(UINT *)(iVar1 + 0x24),*(void **)(iVar1 + 0x18),DAT_00622930,
                        (uint)(DAT_0070a880 == 8));
      return;
    }
  }
  else if ((*arg_1 != 0) && (*(int *)(iVar1 + 0x28) == *(int *)(iVar2 + 0x28))) {
    if ((iVar1 == iVar2) && (arg_8 < arg_3)) {
      iVar10 = 0;
      if ((int)arg_5 < 1) {
        return;
      }
      do {
        iVar3 = *(int *)(iVar1 + 0x20) * *(int *)(iVar1 + 0x28);
        iVar4 = arg_3 + iVar10;
        iVar5 = arg_2 * *(int *)(iVar1 + 0x28);
        iVar6 = *(int *)(iVar2 + 0x20) * *(int *)(iVar2 + 0x28);
        iVar7 = arg_8 + iVar10;
        iVar10 = iVar10 + 1;
        iVar8 = arg_7 * *(int *)(iVar2 + 0x28);
        iVar9 = arg_4 * *(int *)(iVar2 + 0x28);
        memmove((void *)((*(int *)(iVar2 + 0x2c) + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3)) *
                         iVar7 + ((int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3) + *(int *)(iVar2 + 0x18)
                        ),
                (void *)((*(int *)(iVar1 + 0x2c) + ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3)) *
                         iVar4 + ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + *(int *)(iVar1 + 0x18)
                        ),(int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3);
      } while (iVar10 < (int)arg_5);
      return;
    }
    iVar10 = arg_5 - 1;
    if (iVar10 < 0) {
      return;
    }
    do {
      iVar3 = *(int *)(iVar1 + 0x20) * *(int *)(iVar1 + 0x28);
      iVar4 = arg_2 * *(int *)(iVar1 + 0x28);
      iVar5 = *(int *)(iVar2 + 0x20) * *(int *)(iVar2 + 0x28);
      iVar6 = arg_7 * *(int *)(iVar2 + 0x28);
      iVar7 = arg_4 * *(int *)(iVar2 + 0x28);
      memmove((void *)((*(int *)(iVar2 + 0x2c) + ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3)) *
                       (arg_8 + iVar10) + ((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) +
                      *(int *)(iVar2 + 0x18)),
              (void *)((*(int *)(iVar1 + 0x2c) + ((int)(iVar3 + (iVar3 >> 0x1f & 7U)) >> 3)) *
                       (arg_3 + iVar10) + ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) +
                      *(int *)(iVar1 + 0x18)),(int)(iVar7 + (iVar7 >> 0x1f & 7U)) >> 3);
      iVar10 = iVar10 + -1;
    } while (-1 < iVar10);
    return;
  }
  BitBlt(*(HDC *)(iVar2 + 4),arg_7,arg_8,arg_4,arg_5,*(HDC *)(iVar1 + 4),arg_2,arg_3,0xcc0020);
  return;
}

/*
 * Decompiled function: Surface_GetPixelColor
 * Entry Point: 0040c761
 * Size: 95 bytes
 */


uint Surface_GetPixelColor(int x,int y)

{
  uint uVar1;
  
  if ((0x3f < x) || (x < 0)) {
    x = 0;
  }
  if ((0x3f < y) || (y < 0)) {
    y = 0;
  }
  uVar1 = Surface_GetPixelValue((int *)g_DisplaySurfaceWork,x,y);
  return uVar1 & 0xf;
}

/*
 * Decompiled function: Surface_TransformPoint
 * Entry Point: 005112b0
 * Size: 747 bytes
 */


int Surface_TransformPoint(short arg1,short arg2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10 [4];
  
  iVar6 = (int)arg2;
  iVar1 = (int)(0x4000 / (longlong)iVar6);
  if (DAT_0070a880 != 8) {
    return (uint)(ushort)((ulonglong)(0x4000 / (longlong)iVar6) >> 0x10) << 0x10;
  }
  puVar2 = &DAT_0070a130;
  puVar8 = &DAT_007051e0;
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  local_2c = (int)arg1;
  local_28 = local_2c;
  local_24 = local_2c;
  puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&local_2c);
  local_1c = *puVar2;
  local_18 = puVar2[1];
  local_14 = puVar2[2];
  sVar7 = 0;
  FUN_0050e8b0((short *)&DAT_0070a130);
  do {
    iVar5 = (int)sVar7;
    pbVar9 = (byte *)(iVar5 * 3 + DAT_00532804);
    (&DAT_00705500)[iVar5 * 4] = (uint)*pbVar9;
    (&DAT_00705504)[iVar5 * 4] = (uint)pbVar9[1];
    (&DAT_00705508)[iVar5 * 4] = (uint)pbVar9[2];
    puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&DAT_00705500 + iVar5 * 4);
    (&DAT_007039e0)[iVar5 * 3] = *puVar2;
    (&DAT_007039e4)[iVar5 * 3] = puVar2[1];
    (&DAT_007039e8)[iVar5 * 3] = puVar2[2];
    iVar4 = (local_18 - (&DAT_007039e4)[iVar5 * 3]) / iVar6;
    (&DAT_007045e4)[iVar5 * 3] = iVar4;
    if ((int)(&DAT_007039e4)[iVar5 * 3] < local_18) {
      iVar3 = 0x1000;
    }
    else {
      iVar3 = -0x1000;
    }
    sVar7 = sVar7 + 1;
    (&DAT_007045e4)[iVar5 * 3] = iVar3 / iVar6 + iVar4;
  } while (sVar7 < 0x100);
  local_3e = 1;
  if (0 < arg2) {
    do {
      sVar7 = 0;
      do {
        iVar6 = (int)sVar7;
        if (local_14 == 0) {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007039e4)[iVar6 * 3];
          local_30 = (&DAT_007039e8)[iVar6 * 3] - iVar1;
          (&DAT_007039e8)[iVar6 * 3] = local_30;
        }
        else {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007045e4)[iVar6 * 3] * (int)local_3e + (&DAT_007039e4)[iVar6 * 3];
          if (0xfbf < local_34) {
            local_34 = 0xfc0;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          iVar4 = iVar1;
          if (local_14 < (int)(&DAT_007039e8)[iVar6 * 3]) {
            iVar4 = -iVar1;
          }
          (&DAT_007039e8)[iVar6 * 3] = (&DAT_007039e8)[iVar6 * 3] + iVar4;
          local_30 = (&DAT_007039e8)[iVar6 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        if (local_30 < 1) {
          local_30 = 0;
        }
        iVar4 = (int)sVar7;
        sVar7 = sVar7 + 1;
        puVar2 = (undefined4 *)FUN_00511120(local_10,&local_38);
        (&DAT_00705500)[iVar4 * 4] = *puVar2;
        (&DAT_00705504)[iVar4 * 4] = puVar2[1];
        iVar6 = iVar4 * 3;
        (&DAT_00705508)[iVar4 * 4] = puVar2[2];
        (&DAT_0070550c)[iVar4 * 4] = puVar2[3];
        *(undefined1 *)(DAT_00532804 + iVar6) = *(undefined1 *)(&DAT_00705500 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 1 + iVar6) = *(undefined1 *)(&DAT_00705504 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 2 + iVar6) = *(undefined1 *)(&DAT_00705508 + iVar4 * 4);
      } while (sVar7 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + 1;
    } while (local_3e <= arg2);
  }
  sVar7 = 0;
  do {
    iVar1 = (int)sVar7;
    sVar7 = sVar7 + 1;
    iVar1 = iVar1 * 3;
    *(undefined1 *)(DAT_00532804 + iVar1) = (undefined1)local_2c;
    *(undefined1 *)(DAT_00532804 + 1 + iVar1) = (undefined1)local_28;
    *(undefined1 *)(DAT_00532804 + 2 + iVar1) = (undefined1)local_24;
  } while (sVar7 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  iVar1 = FUN_0050d560(0,0);
  return iVar1;
}
