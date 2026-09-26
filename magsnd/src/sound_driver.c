
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "shandalar/shandalar.h"
int thunk_FUN_1000219c();
int thunk_FUN_1000207f();
int thunk_FUN_10005f0c();
extern int DAT_1000a410;
extern int DAT_1000a428;
int thunk_FUN_1000192c();
int thunk_FUN_100046fb();
int thunk_FUN_1000560f();
int thunk_FUN_100043c4();
int thunk_FUN_10004534();
int thunk_FUN_10005a46();
int thunk_FUN_10006622();
int UnloadSnd();
int thunk_FUN_1000394f();
int thunk_FUN_1000458d();
int thunk_FUN_1000460c();
extern int DAT_1000baa0;
extern int DAT_1000a458;
extern int DAT_1000a424;
extern int DAT_1000a648;
extern int DAT_1000a420;
extern int DAT_1000ba88;
int UnloadAllSnds();
int thunk_FUN_10004665();
int thunk_FUN_10002900();
int thunk_FUN_10004788();

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
 * Decompiled function: Sound_DirectSoundInit
 * Entry Point: 10001240
 * Size: 374 bytes
 */


int32_t __cdecl Sound_DirectSoundInit(int arg_1,int32_t arg_2,uint8_t arg_3)

{
  int32_t uval_1;
  void *val_2;
  uint8_t local_8 [4];
  
  if (((arg_3 & 2) == 0) || (DAT_1000a434 != 0)) {
    if (((arg_3 & 2) == 0) || (DAT_1000a434 == 0)) {
      if ((DAT_1000a434 == 0) && (arg_1 != 0)) {
        val_2 = DirectSoundCreate(0,&DAT_1000ba90,0);
        if (val_2 != 0) {
          return 4;
        }
        val_2 = (**(GhidraCall *)(*DAT_1000ba90 + 0x18))(DAT_1000ba90,arg_1,3);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(GhidraCall *)(*DAT_1000ba90 + 0xc))(DAT_1000ba90,&DAT_1000a440,&DAT_1000a640,0);
        if (val_2 != 0) {
          ReleaseSnd();
          return 4;
        }
        val_2 = (**(GhidraCall *)(*DAT_1000a640 + 0x38))(DAT_1000a640,&DAT_1000a458);
        if (val_2 != 0) {
          (**(GhidraCall *)(*DAT_1000a640 + 0x14))(DAT_1000a640,&DAT_1000a458,0x12,local_8);
        }
        DAT_1000ba88 = arg_1;
        DAT_1000a434 = DAT_1000a434 + 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
      if ((arg_3 & 1) != 0) {
        if (DAT_1000a424 != 0) {
          thunk_FUN_10004788();
        }
        DAT_1000a420 = 0;
      }
      uval_1 = 0;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 4;
  }
  return uval_1;
}

/*
 * Decompiled function: Sound_DirectSoundShutdown
 * Entry Point: 100013b6
 * Size: 114 bytes
 */


void Sound_DirectSoundShutdown(void)

{
  if (DAT_1000a434 != 0) {
    UnloadAllSnds();
    if (DAT_1000a424 != 0) {
      thunk_FUN_10004788();
    }
    (**(GhidraCall *)(*DAT_1000ba90 + 8))(DAT_1000ba90);
    DAT_1000ba90 = (int *)0x0;
    DAT_1000ba88 = 0;
    DAT_1000a434 = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  }
  return;
}

/*
 * Decompiled function: Sound_LockAudioBuffer
 * Entry Point: 100016e4
 * Size: 356 bytes
 */


int32_t __cdecl Sound_LockAudioBuffer(int arg_1)

{
  int32_t uval_1;
  uint32_t local_8;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_10002900(arg_1);
      thunk_FUN_10004665(*(int *)(&DAT_1000a648 + arg_1 * 4));
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) != 0) {
        thunk_FUN_1000458d(*(int *)(&DAT_1000a648 + arg_1 * 4));
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 5 & 1) == 0) {
          thunk_FUN_10005a46(*(int32_t **)(&DAT_1000a648 + arg_1 * 4));
          for (local_8 = 0; local_8 < *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x30);
              local_8 = local_8 + 1) {
            if (*(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4) != 0) {
              thunk_FUN_10005a46(*(int32_t **)
                                  (*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 + local_8 * 4));
            }
          }
        }
      }
      thunk_FUN_10006622(*(void **)(&DAT_1000a648 + arg_1 * 4));
      *(int32_t *)(&DAT_1000a648 + arg_1 * 4) = 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}

/*
 * Decompiled function: Sound_UnlockAudioBuffer
 * Entry Point: 10001848
 * Size: 75 bytes
 */


int32_t Sound_UnlockAudioBuffer(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  while (DAT_1000a410 != 0) {
    UnloadSnd(*(int *)(DAT_1000a410 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return 0;
}

/*
 * Decompiled function: Sound_SetChannelVolume
 * Entry Point: 10001893
 * Size: 153 bytes
 */


int32_t __cdecl Sound_SetChannelVolume(int arg1,int *arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0x110) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      thunk_FUN_1000192c(*(int32_t **)(&DAT_1000a648 + arg1 * 4),arg2);
      *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) =
           *(int *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0xc) + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}

/*
 * Decompiled function: thunk_FUN_1000192c
 * Entry Point: 100010d7
 * Size: 5 bytes
 */


int __cdecl thunk_FUN_1000192c(int32_t *ptr_1,int *ptr_2)

{
  int val_1;
  int iStack_1c;
  int *piStack_18;
  uint32_t uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uStack_14 = 0;
  iStack_c = 0;
  if (((uint32_t)ptr_1[2] >> 1 & 1) == 0) {
    if ((ptr_2 == (int *)0x0) || (((uint32_t)ptr_2[7] >> 1 & 1) == 0)) {
      val_1 = thunk_FUN_100043c4((int)ptr_1,(int *)&piStack_18);
      if (val_1 != 0) {
        return val_1;
      }
      iStack_8 = 0;
    }
    else {
      piStack_18 = (int *)ptr_1[0x2f];
    }
  }
  else {
    if ((*(uint8_t *)(ptr_1 + 1) & 1) != 0) {
      thunk_FUN_10002900(ptr_1[4]);
    }
    if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
       (iStack_8 = thunk_FUN_100046fb(), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
    if (DAT_1000a420 != 0) {
      DAT_1000a428 = DAT_1000a428 + 1;
    }
    uStack_14 = uStack_14 | 1;
    piStack_18 = (int *)ptr_1[0x2f];
    if ((((uint32_t)ptr_1[1] >> 5 & 1) == 0) && (iStack_8 = thunk_FUN_1000394f(ptr_1), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
  }
  if (ptr_2 == (int *)0x0) {
    iStack_1c = 0;
    ptr_1[0x7c] = 400;
    iStack_c = ptr_1[0x1f];
    ptr_1[0x7b] = iStack_c;
    iStack_10 = 0;
    ptr_1[0x7a] = 0;
  }
  else {
    iStack_1c = *ptr_2;
    if (400 < iStack_1c) {
      iStack_1c = 400;
    }
    ptr_1[0x7c] = iStack_1c;
    iStack_1c = (iStack_1c * 5 + -2000) * 2;
    if (ptr_2[1] == 0) {
      iStack_c = ptr_1[0x1f];
    }
    else {
      iStack_c = ptr_2[1];
    }
    ptr_1[0x7b] = iStack_c;
    if (ptr_2[2] == 0) {
      iStack_10 = 0;
    }
    else {
      iStack_10 = ptr_2[2];
    }
    ptr_1[0x7a] = iStack_10;
    iStack_10 = iStack_10 * 10;
    if ((*(uint8_t *)(ptr_2 + 7) & 1) != 0) {
      uStack_14 = uStack_14 | 1;
      ptr_1[2] = ptr_1[2] | 1;
    }
    if (((uint32_t)ptr_2[7] >> 3 & 1) != 0) {
      ptr_1[2] = ptr_1[2] | 4;
    }
  }
  (**(GhidraCall *)(*piStack_18 + 0x3c))(piStack_18,iStack_1c);
  (**(GhidraCall *)(*piStack_18 + 0x44))(piStack_18,iStack_c);
  (**(GhidraCall *)(*piStack_18 + 0x40))(piStack_18,iStack_10);
  (**(GhidraCall *)(*piStack_18 + 0x34))(piStack_18,0);
  val_1 = (**(GhidraCall *)(*piStack_18 + 0x30))(piStack_18,0,0,uStack_14);
  if (val_1 == 0) {
    ptr_1[1] = ptr_1[1] | 1;
    ptr_1[1] = ptr_1[1] & 0xffffffdf;
    val_1 = 0;
  }
  else {
    val_1 = 9;
  }
  return val_1;
}

/*
 * Decompiled function: Sound_SetChannelPanning
 * Entry Point: 10001c4c
 * Size: 1075 bytes
 */


int __cdecl Sound_SetChannelPanning(LPSTR arg_1,int arg_2,int *ptr_3)

{
  uint8_t local_1c [4];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t local_8;
  
  local_8 = 0;
  local_18 = 0;
  local_10 = 0;
  if ((arg_2 < 0x100) && (-1 < arg_2)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_2 * 4) == 0) {
      local_c = thunk_FUN_1000560f(arg_1,(int *)(&DAT_1000a648 + arg_2 * 4));
      if (local_c == 0) {
        thunk_FUN_1000460c(*(int *)(&DAT_1000a648 + arg_2 * 4));
        thunk_FUN_10004534(*(int *)(&DAT_1000a648 + arg_2 * 4));
        if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
           (local_c = thunk_FUN_100046fb(), local_c != 0)) {
          UnloadSnd(arg_2);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
        else {
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x10) = arg_2;
          if (ptr_3 == (int *)0x0) {
            local_18 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = 400;
            local_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
            local_14 = 0;
            *(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = 0;
          }
          else {
            local_18 = *ptr_3;
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = local_18;
            if (400 < local_18) {
              local_18 = 400;
            }
            local_18 = (local_18 * 5 + -2000) * 2;
            if (ptr_3[1] == 0) {
              local_10 = *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x7c);
            }
            else {
              local_10 = ptr_3[1];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
            if (ptr_3[2] == 0) {
              local_14 = 0;
            }
            else {
              local_14 = ptr_3[2];
            }
            *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = local_14;
            local_14 = local_14 * 10;
            if ((*(uint8_t *)(ptr_3 + 7) & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 1;
            }
            if (((uint32_t)ptr_3[7] >> 3 & 1) != 0) {
              *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
                   *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 4;
            }
          }
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 8) | 2;
          (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x3c))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_18);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1f0) = local_18;
          (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x44))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_10);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1ec) = local_10;
          (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x40))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),local_14);
          *(int *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1e8) = local_14;
          thunk_FUN_10005f0c(*(int32_t **)(&DAT_1000a648 + arg_2 * 4),0);
          (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x30))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),0,0,1);
          (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc) + 0x10))
                    (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 0xbc),
                     *(int *)(&DAT_1000a648 + arg_2 * 4) + 0x1d8,local_1c);
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_2 * 4) + 4) | 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          local_c = 0;
        }
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_c = 2;
    }
  }
  else {
    local_c = 5;
  }
  return local_c;
}

/*
 * Decompiled function: Sound_PlayWaveSample
 * Entry Point: 10002389
 * Size: 237 bytes
 */


int __cdecl Sound_PlayWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    ptr_1 = *(int32_t **)(&DAT_1000a648 + arg1 * 4);
    if (ptr_1 == (int32_t *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 1;
    }
    else if ((ptr_1[0xc] == 0) || ((uint32_t)ptr_1[0xc] < arg2)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      local_8 = 5;
    }
    else {
      if (ptr_1[arg2 + 0xd] == 0) {
        local_8 = thunk_FUN_1000207f(ptr_1,arg2);
      }
      else {
        local_8 = thunk_FUN_1000219c((int)ptr_1,arg2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    }
  }
  else {
    local_8 = 5;
  }
  return local_8;
}

/*
 * Decompiled function: Sound_StopWaveSample
 * Entry Point: 10002476
 * Size: 549 bytes
 */


int __cdecl Sound_StopWaveSample(int arg1,uint32_t arg2)

{
  int32_t *ptr_1;
  int val_1;
  int local_24;
  int32_t local_20;
  int32_t local_1c;
  uint32_t local_8;
  
  if ((arg1 < 0x100) && (-1 < arg1)) {
    if (((int)arg2 < 0x11) && (-1 < (int)arg2)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      val_1 = *(int *)(&DAT_1000a648 + arg1 * 4);
      if (val_1 == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 1;
      }
      else if ((*(int *)(val_1 + 0x30) == 0) || (*(uint32_t *)(val_1 + 0x30) < arg2)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        val_1 = 5;
      }
      else {
        ptr_1 = *(int32_t **)(val_1 + 0x34 + arg2 * 4);
        if (ptr_1 == (int32_t *)0x0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else if (((uint32_t)ptr_1[1] >> 5 & 1) == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          val_1 = 1;
        }
        else {
          if ((*(uint8_t *)(val_1 + 4) & 1) != 0) {
            thunk_FUN_10002900(arg1);
          }
          ptr_1[0x7c] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1f0);
          local_24 = ptr_1[0x7c];
          ptr_1[0x7b] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1ec);
          local_20 = ptr_1[0x7b];
          ptr_1[0x7a] = *(int32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x1e8);
          local_1c = ptr_1[0x7a];
          local_8 = ptr_1[2] & 1 | local_8 & 0xfffffffe;
          val_1 = thunk_FUN_1000192c(ptr_1,&local_24);
          if (val_1 == 0) {
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 0x40;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 0x18) = arg2 - 1;
            *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) =
                 *(uint32_t *)(*(int *)(&DAT_1000a648 + arg1 * 4) + 4) | 1;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
        }
      }
    }
    else {
      val_1 = 5;
    }
  }
  else {
    val_1 = 5;
  }
  return val_1;
}

/*
 * Decompiled function: Sound_GetChannelStatus
 * Entry Point: 1000269b
 * Size: 522 bytes
 */


int32_t __cdecl Sound_GetChannelStatus(int arg_1)

{
  int32_t uval_1;
  int *i_ptr_2;
  int val_3;
  int local_10;
  
  if ((arg_1 < 0x110) && (-1 < arg_1)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    if (*(int *)(&DAT_1000a648 + arg_1 * 4) == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 1;
    }
    else {
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) >> 6 & 1) == 0) {
        if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
          val_3 = (**(GhidraCall *)(**(int **)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc) + 0x48))
                            (*(int32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0xbc));
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
        }
        else {
          *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
               *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) | 2;
        }
      }
      else {
        val_3 = *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x38 +
                        *(int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 0x18) * 4);
        if (val_3 == 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
          return 1;
        }
        *(uint32_t *)(val_3 + 4) = *(uint32_t *)(val_3 + 4) | 2;
      }
      if ((*(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 8) >> 1 & 1) == 0) {
        local_10 = 0;
        while ((local_10 < 0x10 &&
               (i_ptr_2 = (int *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + local_10 * 0xc + 0xc0),
               *i_ptr_2 != 0))) {
          val_3 = (**(GhidraCall *)(*(int *)*i_ptr_2 + 0x48))(*i_ptr_2);
          if (val_3 != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
            return 9;
          }
          local_10 = local_10 + 1;
        }
        *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) =
             *(uint32_t *)(*(int *)(&DAT_1000a648 + arg_1 * 4) + 4) & 0xfffffffe;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 5;
  }
  return uval_1;
}

/*
 * Decompiled function: Sound_SetMasterVolume
 * Entry Point: 100028a5
 * Size: 91 bytes
 */


void Sound_SetMasterVolume(void)

{
  int local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  for (local_8 = DAT_1000a410; local_8 != 0; local_8 = *(int *)(local_8 + 0x200)) {
    StopSnd(*(int *)(local_8 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
  return;
}
