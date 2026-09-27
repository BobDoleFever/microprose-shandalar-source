
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
typedef struct timecaps_tag { UINT wPeriodMin; UINT wPeriodMax; } TIMECAPS, timecaps_tag;
int AVIStreamTimeToSample();
int AVIStreamSampleToTime();
extern int local_c;
extern int float10;
int thunk_FUN_10007a85();
int thunk_FUN_10007383();
int AVIStreamRelease();
int timeGetDevCaps();
int thunk_FUN_10007bff();
int thunk_FUN_10004e65();
int thunk_FUN_10001d28();
int thunk_FUN_10007238();
int thunk_FUN_1000785e();
int thunk_FUN_10007b00();
int thunk_FUN_1000735d();
int AVIStreamInfoA();

#define _rand rand
#define _sprintf sprintf
#define _strlen strlen
#define _strcmp strcmp
#define _fopen fopen
#define _fclose fclose
#define _fgets fgets
#define _fscanf fscanf
#define _read read
#define float10 double

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
 * Decompiled function: thunk_FUN_10001740
 * Entry Point: 10001212
 * Size: 5 bytes
 */


int32_t * __fastcall thunk_FUN_10001740(int32_t *ptr_1)

{
  int iStack_8;
  
  *ptr_1 = 0;
  ptr_1[1] = 0;
  ptr_1[2] = 0;
  ptr_1[3] = 0;
  ptr_1[4] = 0;
  ptr_1[5] = 0;
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  ptr_1[8] = 0;
  ptr_1[9] = 0;
  ptr_1[10] = 0;
  ptr_1[0xb] = 0;
  ptr_1[0xc] = 0;
  ptr_1[0xd] = 0;
  ptr_1[0xe] = 0;
  ptr_1[0xf] = 0;
  ptr_1[0x10] = 0;
  ptr_1[0x11] = 0;
  ptr_1[0x12] = 0;
  ptr_1[0x13] = 0;
  ptr_1[0x14] = 0;
  ptr_1[0x15] = 0;
  ptr_1[0x16] = 0;
  ptr_1[0x17] = 0;
  ptr_1[0x18] = 0;
  ptr_1[0x1d] = 0;
  ptr_1[0x1e] = 0;
  ptr_1[0x1f] = 0;
  ptr_1[0x20] = 0;
  ptr_1[0x21] = 0;
  ptr_1[0x22] = 0;
  ptr_1[0x23] = 0;
  ptr_1[0x24] = 0;
  ptr_1[0x25] = 0;
  ptr_1[0x26] = 0;
  for (iStack_8 = 0; iStack_8 < 0x20; iStack_8 = iStack_8 + 1) {
    ptr_1[iStack_8 + 0x27] = 0;
  }
  ptr_1[0x47] = 0;
  ptr_1[0x48] = 0;
  ptr_1[0x49] = 0;
  AVIFileInit();
  return ptr_1;
}

/*
 * Decompiled function: thunk_FUN_10001926
 * Entry Point: 100010c8
 * Size: 5 bytes
 */


void __fastcall thunk_FUN_10001926(int *ptr_1)

{
  thunk_FUN_10001c16(ptr_1);
  thunk_FUN_100019c7((int)ptr_1);
  AVIFileExit();
  return;
}

/*
 * Decompiled function: thunk_FUN_10001951
 * Entry Point: 1000136b
 * Size: 5 bytes
 */


int __thiscall thunk_FUN_10001951(void *this,int32_t arg_2)

{
  int val_1;
  
  if (*(int *)((int)this + 8) != 0) {
    thunk_FUN_100019c7((int)this);
  }
  *(int32_t *)((int)this + 0x10) = 0;
  *(int32_t *)((int)this + 0xc) = *(int32_t *)((int)this + 0x10);
  val_1 = AVIFileOpenA((int)this + 8,arg_2,0x20,0);
  if (val_1 == 0) {
    val_1 = 0;
  }
  else {
    thunk_FUN_100019c7((int)this);
  }
  return val_1;
}

/*
 * Decompiled function: AVI_ReleaseFileStream
 * Entry Point: 100019c7
 * Size: 59 bytes
 */


int32_t __fastcall AVI_ReleaseFileStream(int arg_1)

{
  if (*(int *)(arg_1 + 8) != 0) {
    AVIFileRelease(*(int32_t *)(arg_1 + 8));
    *(int32_t *)(arg_1 + 8) = 0;
  }
  return 0;
}

/*
 * Decompiled function: AVI_GetVideoStreamInfo
 * Entry Point: 10001a02
 * Size: 532 bytes
 */


int __thiscall AVI_GetVideoStreamInfo(void *this,int arg_2,int arg_3)

{
  int val_1;
  int32_t local_b4;
  int32_t local_b0;
  int32_t local_ac;
  int32_t local_a8;
  int32_t local_a4;
  int32_t local_a0;
  int32_t local_9c;
  int32_t local_98;
  uint8_t local_94 [20];
  uint32_t local_80;
  uint32_t local_7c;
  int local_8;
  
  if ((*(int *)((int)this + 0xc) != 0) || (*(int *)((int)this + 0x10) != 0)) {
    thunk_FUN_10001c16(this);
  }
  *(int32_t *)((int)this + 0x1c) = 0;
  *(int32_t *)((int)this + 0x18) = *(int32_t *)((int)this + 0x1c);
  *(int *)((int)this + 0x14) = arg_2;
  *(int32_t *)this = 0;
  *(int32_t *)((int)this + 0x74) = 0;
  local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0xc,0x73646976,0);
  if (local_8 == -0x7ffbbf8d) {
    *(int32_t *)((int)this + 0xc) = 0;
    val_1 = -1;
  }
  else {
    local_8 = AVIFileGetStream(*(int32_t *)((int)this + 8),(int)this + 0x10,0x73647561,0);
    if (local_8 == -0x7ffbbf8d) {
      *(int32_t *)((int)this + 0x10) = 0;
    }
    else {
      local_b4 = 400;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0x14;
      thunk_FUN_10004e65(*(int32_t *)((int)this + 0x10),arg_3 + 0x100,&local_b4);
    }
    AVIStreamInfoA(*(int32_t *)((int)this + 0xc),local_94,0x8c);
    *(float *)((int)this + 0x24) = (float)((float10)local_7c / (float10)local_80);
    *(int32_t *)((int)this + 0x20) = *(int32_t *)((int)this + 0x24);
    val_1 = thunk_FUN_1000785e(this);
    if (val_1 == 0) {
      val_1 = 0;
    }
  }
  return val_1;
}

/*
 * Decompiled function: AVI_ReleaseVideoStream
 * Entry Point: 10001c16
 * Size: 120 bytes
 */


int32_t __fastcall AVI_ReleaseVideoStream(int *ptr_1)

{
  thunk_FUN_10001d28(ptr_1);
  thunk_FUN_10007a85(ptr_1);
  thunk_FUN_10007238((int)ptr_1);
  if (ptr_1[3] != 0) {
    AVIStreamRelease(ptr_1[3]);
  }
  if (ptr_1[4] != 0) {
    AVIStreamRelease(ptr_1[4]);
  }
  ptr_1[4] = 0;
  ptr_1[3] = ptr_1[4];
  return 0;
}

/*
 * Decompiled function: AVI_InitTimerPeriod
 * Entry Point: 10001c8e
 * Size: 154 bytes
 */


int32_t __thiscall AVI_InitTimerPeriod(void *this,int arg_2)

{
  int32_t uval_1;
  timecaps_tag local_c;
  
  if (*(int *)((int)this + 0xc) == 0) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x18) = 1;
    timeGetDevCaps(&local_c,8);
    if (local_c.wPeriodMin < 2) {
      local_c.wPeriodMin = 1;
    }
    *(UINT *)((int)this + 0x28) = local_c.wPeriodMin;
    timeBeginPeriod(*(UINT *)((int)this + 0x28));
    *(int32_t *)((int)this + 0x1c) = 0;
    thunk_FUN_10007b00(this,arg_2,-1);
    uval_1 = 0;
  }
  else {
    uval_1 = 0xfffffffc;
  }
  return uval_1;
}

/*
 * Decompiled function: thunk_FUN_10001d28
 * Entry Point: 1000105f
 * Size: 5 bytes
 */


int32_t __fastcall thunk_FUN_10001d28(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 0;
  thunk_FUN_1000735d();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}

/*
 * Decompiled function: AVI_StopPlaybackTimer
 * Entry Point: 10001d71
 * Size: 73 bytes
 */


int32_t __fastcall AVI_StopPlaybackTimer(int32_t *ptr_1)

{
  ptr_1[6] = 0;
  ptr_1[7] = 1;
  thunk_FUN_10007383();
  thunk_FUN_10007bff(ptr_1);
  timeEndPeriod(ptr_1[10]);
  return 0;
}

/*
 * Decompiled function: AVI_SeekFrameToTime
 * Entry Point: 10001dba
 * Size: 264 bytes
 */


int32_t __thiscall AVI_SeekFrameToTime(void *this,int32_t arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(int32_t *)((int)this + 0x44) = arg_2;
    if (*(int *)((int)this + 0x44) < *(int *)((int)this + 0x54)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x54);
    }
    else if (*(int *)((int)this + 0x58) < *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x58);
    }
    if (*(int *)((int)this + 0x54) == *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x48) = 0xffffffff;
      *(int32_t *)((int)this + 0x4c) = 0xffffffff;
      *(int32_t *)((int)this + 0x50) = 0xffffffff;
    }
    if ((*(int *)((int)this + 0x10) != 0) && (*(int *)((int)this + 0x94) != 0)) {
      uval_1 = AVIStreamSampleToTime(*(int32_t *)((int)this + 0xc),arg_2);
      val_2 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0x10),uval_1);
      *(int *)((int)this + 0x98) = val_2 / *(int *)((int)this + 0x94);
    }
    uval_1 = *(int32_t *)((int)this + 0x44);
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}

/*
 * Decompiled function: AVI_GetNextFrameSample
 * Entry Point: 10001ec2
 * Size: 219 bytes
 */


int32_t __thiscall AVI_GetNextFrameSample(void *this,int arg_2)

{
  int32_t uval_1;
  int val_2;
  
  if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x44) + arg_2;
    if (*(int *)((int)this + 0x44) < *(int *)((int)this + 0x54)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x54);
    }
    else if (*(int *)((int)this + 0x58) < *(int *)((int)this + 0x44)) {
      *(int32_t *)((int)this + 0x44) = *(int32_t *)((int)this + 0x58);
    }
    if ((*(int *)((int)this + 0x10) != 0) && (*(int *)((int)this + 0x94) != 0)) {
      uval_1 = AVIStreamSampleToTime
                        (*(int32_t *)((int)this + 0xc),*(int32_t *)((int)this + 0x44));
      val_2 = AVIStreamTimeToSample(*(int32_t *)((int)this + 0x10),uval_1);
      *(int *)((int)this + 0x98) = val_2 / *(int *)((int)this + 0x94);
    }
    uval_1 = *(int32_t *)((int)this + 0x44);
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}
