/*
 * sidlib/Kimpic.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 167
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Pic_LoadImageFile
 * Entry Point: 0043d3ff
 * Size: 788 bytes
 */


int32_t
Pic_LoadImageFile(int player_id,int32_t arg_2,int32_t arg_3,char *str_4,uint8_t *arg_5)

{
  char *mode_str;
  int val_1;
  int32_t arg_1_00;
  int32_t arg_2_00;
  int local_414;
  int local_410;
  uint8_t local_40c [1024];
  uint8_t *match_count;
  int slot_idx;
  
  slot_idx = 8;
  str_2 = _strchr(str_4,0x2e);
  val_1 = __strcmpi(&DAT_004f7928,str_2);
  if (val_1 == 0) {
    DAT_00694430 = _fopen(str_4,&DAT_004f7930);
    if (DAT_00694430 == (FILE *)0x0) {
      return 0;
    }
    DAT_00694438 = str_4;
    if (arg_5 == (uint8_t *)0x1) {
      arg_5 = local_40c;
    }
    if (arg_5 == (uint8_t *)0x0) {
      FUN_0044c47a((void *)0x0);
      if (arg_1 < 0) {
        DAT_004ff158 = 0;
      }
      if ((int)DAT_004ff154 % 3 == 0) {
        local_410 = 0;
      }
      else {
        local_410 = 4 - (int)DAT_004ff154 % 3;
      }
      DAT_00516914 = DAT_004ff154 + local_410;
      FUN_0043d1d0(DAT_00516914,DAT_004ff158,slot_idx);
      match_count = *(uint8_t **)(PTR_DAT_004f7914 + 0x18);
      for (DAT_0051691c = 0; DAT_0051691c < DAT_004ff158; DAT_0051691c = DAT_0051691c + 1) {
        FUN_0044c660(match_count);
        match_count = match_count + ((int)(slot_idx + (slot_idx >> 0x1f & 7U)) >> 3) * DAT_00516914;
      }
      _fclose(DAT_00694430);
    }
    else {
      FUN_0044c47a(arg_5 + 6);
      *arg_5 = 0x4d;
      arg_5[1] = 0x31;
      *(int16_t *)(arg_5 + 2) = 0x300;
      arg_5[4] = 0;
      arg_5[5] = 0xff;
    }
  }
  else {
    DAT_00516920 = FUN_0043d799(str_4,0x8000);
    if (DAT_00516920 == -1) {
      File_Load_Assertfile(0,0x4f794c,0xe4,s_Could_not_open_file__s_004f7934);
      *(int32_t *)(PTR_DAT_004f7914 + 8) = 0;
    }
    else {
      Mem_AllocOrFree_0043d7f6(DAT_00516920);
      FUN_006c5000(arg_1_00,arg_2_00,(uint16_t *)arg_5);
      if ((DAT_004ff154 & 3) == 0) {
        local_414 = 0;
      }
      else {
        local_414 = 4 - (DAT_004ff154 & 3);
      }
      DAT_00516914 = DAT_004ff154 + local_414;
      val_1 = FUN_0043d1d0(DAT_004ff154,DAT_004ff158,slot_idx);
      if (val_1 == 0) {
        *(int32_t *)(PTR_DAT_004f7914 + 8) = 0;
      }
      else {
        match_count = *(uint8_t **)(PTR_DAT_004f7914 + 0x18);
        DAT_0051691c = 0;
        while (DAT_0051691c < DAT_004ff158) {
          Mem_AllocOrFree_006c5484(match_count,DAT_004ff154);
          DAT_0051691c = DAT_0051691c + 1;
          match_count = (uint8_t *)((int)match_count +
                            *(int *)(PTR_DAT_004f7914 + 0x2c) +
                            ((int)(slot_idx * DAT_004ff154 +
                                  ((int)(slot_idx * DAT_004ff154) >> 0x1f & 7U)) >> 3));
        }
      }
      FUN_0043d7cc(DAT_00516920);
    }
  }
  return *(int32_t *)(PTR_DAT_004f7914 + 8);
}



/*
 * Decompiled function: Pic_LoadKimPicture
 * Entry Point: 0043d713
 * Size: 134 bytes
 */


int Pic_LoadKimPicture(char *filepath)

{
  char local_1fc [500];
  int slot_idx;
  
  slot_idx = Pic_LoadImageFile(0,0,0,str_1,(uint8_t *)0x0);
  if (slot_idx != 0) {
    CloseHandle(*(HANDLE *)PTR_DAT_004f7914);
  }
  if (DAT_0061815c != 0) {
    _sprintf(local_1fc,s__08X_LoadKimPicture___s___file_m_004f7970,slot_idx,str_1,
             *(int32_t *)PTR_DAT_004f7914);
    OutputDebugStringA(local_1fc);
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0043d799
 * Entry Point: 0043d799
 * Size: 51 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0043d799(char *filepath,int arg2)

{
  int val_1;
  
  val_1 = __open(str_1,arg2);
  _DAT_00516928 = 0xffffffff;
  return val_1;
}



/*
 * Decompiled function: FUN_0043d7cc
 * Entry Point: 0043d7cc
 * Size: 42 bytes
 */


void FUN_0043d7cc(int player_id)

{
  if (arg_1 != DAT_004f791c) {
    __close(arg_1);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043d7f6
 * Entry Point: 0043d7f6
 * Size: 39 bytes
 */


void Mem_AllocOrFree_0043d7f6(int32_t arg_1)

{
  DAT_00516924 = arg_1;
  DAT_0069453c = PTR_DAT_004f7918;
  DAT_00694740 = FUN_0043d81d;
  return;
}



/*
 * Decompiled function: FUN_0043d81d
 * Entry Point: 0043d81d
 * Size: 59 bytes
 */


int FUN_0043d81d(void)

{
  int val_1;
  
  val_1 = __read(DAT_00516924,&g_MasterCardCount,0x200);
  DAT_0069453c = &g_MasterCardCount;
  return val_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043d858
 * Entry Point: 0043d858
 * Size: 11 bytes
 */


void Mem_AllocOrFree_0043d858(void)

{
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_0043d863
 * Entry Point: 0043d863
 * Size: 11 bytes
 */


void Mem_AllocOrFree_0043d863(void)

{
  return;
}



/*
 * Decompiled function: Sound_Init
 * Entry Point: 0043d870
 * Size: 351 bytes
 */


int Sound_Init(int hInst,int32_t hWnd,uint32_t flags)

{
  int val_1;
  FARPROC pFVar2;
  int match_count;
  
  if (DAT_004f79a4 == 0) {
    DAT_006944c8 = LoadLibraryA(PTR_s_magsnd_004f79ac);
    if (DAT_006944c8 == (HMODULE)0x0) {
      val_1 = 4;
    }
    else {
      for (match_count = 0; match_count < 0x1b; match_count = match_count + 1) {
        pFVar2 = GetProcAddress(DAT_006944c8,(LPCSTR)(match_count + 1U & 0xffff));
        (&DAT_006944d0)[match_count] = pFVar2;
        if ((&DAT_006944d0)[match_count] == (code *)0x0) {
          FreeLibrary(DAT_006944c8);
          FUN_0043e09c();
          return 4;
        }
      }
      if ((hInst == 0) && ((flags & 2) == 0)) {
        FreeLibrary(DAT_006944c8);
        FUN_0043e09c();
        val_1 = 5;
      }
      else {
        val_1 = (*DAT_006944d0)(hInst,hWnd,flags);
        if (val_1 == 0) {
          DAT_004f79a8 = 1;
          if ((flags & 2) != 0) {
            DAT_004f79a0 = 1;
          }
          DAT_004f79a4 = 1;
          val_1 = 0;
        }
        else {
          FreeLibrary(DAT_006944c8);
          FUN_0043e09c();
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
 * Decompiled function: CloseSnd
 * Entry Point: 0043d9cf
 * Size: 118 bytes
 */


void CloseSnd(void)

{
  if (DAT_004f79a4 != 0) {
    DAT_004f79a4 = 0;
    if ((DAT_004f79a8 != 0) && (DAT_004f79a0 == 0)) {
      (*DAT_006944d4)();
    }
    FreeLibrary(DAT_006944c8);
    FUN_0043e09c();
    DAT_006944c8 = (HMODULE)0x0;
    DAT_004f79a0 = 0;
    DAT_004f79a8 = 0;
  }
  return;
}



/*
 * Decompiled function: InitSndTrack
 * Entry Point: 0043da45
 * Size: 60 bytes
 */


int32_t InitSndTrack(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if (DAT_004f79a4 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944d8)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



/*
 * Decompiled function: CloseSndTrack
 * Entry Point: 0043da81
 * Size: 52 bytes
 */


int32_t CloseSndTrack(int32_t arg_1)

{
  int32_t uval_1;
  
  if (DAT_004f79a4 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944dc)(arg_1);
  }
  return uval_1;
}



/*
 * Decompiled function: StopSndTrack
 * Entry Point: 0043dab5
 * Size: 45 bytes
 */


int32_t StopSndTrack(void)

{
  int32_t uval_1;
  
  if (DAT_004f79a4 == 0) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944e0)();
  }
  return uval_1;
}



/*
 * Decompiled function: PlaySnd
 * Entry Point: 0043dae2
 * Size: 69 bytes
 */


int32_t PlaySnd(int32_t sound_id,int32_t flags)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944e4)(sound_id,flags);
  }
  return uval_1;
}



/*
 * Decompiled function: PlaySndFile
 * Entry Point: 0043db27
 * Size: 73 bytes
 */


int32_t PlaySndFile(int32_t filename,int32_t loop_flag,int32_t out_handle)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944e8)(filename,loop_flag,out_handle);
  }
  return uval_1;
}



/*
 * Decompiled function: StopSnd
 * Entry Point: 0043db70
 * Size: 65 bytes
 */


int32_t StopSnd(int32_t sound_id)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944ec)(sound_id);
  }
  return uval_1;
}



/*
 * Decompiled function: PauseSnd
 * Entry Point: 0043dbb1
 * Size: 48 bytes
 */


void PauseSnd(void)

{
  if ((DAT_004f79a4 != 0) && (DAT_004f79a4 != 2)) {
    (*DAT_006944f0)();
  }
  return;
}



/*
 * Decompiled function: ResumeSnd
 * Entry Point: 0043dbe1
 * Size: 69 bytes
 */


int32_t ResumeSnd(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944f4)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: SetPitch
 * Entry Point: 0043dc26
 * Size: 69 bytes
 */


int32_t SetPitch(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944f8)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetPitch
 * Entry Point: 0043dc6b
 * Size: 69 bytes
 */


int32_t GetPitch(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_006944fc)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: SetVol
 * Entry Point: 0043dcb0
 * Size: 69 bytes
 */


int32_t SetVol(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694500)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetVol
 * Entry Point: 0043dcf5
 * Size: 69 bytes
 */


int32_t GetVol(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694504)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: SetPan
 * Entry Point: 0043dd3a
 * Size: 69 bytes
 */


int32_t SetPan(int32_t value,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694508)(value,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetPan
 * Entry Point: 0043dd7f
 * Size: 69 bytes
 */


int32_t GetPan(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0069450c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: UpdateSnd
 * Entry Point: 0043ddc4
 * Size: 58 bytes
 */


int32_t UpdateSnd(void)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694510)();
  }
  return uval_1;
}



/*
 * Decompiled function: SetSndMarker
 * Entry Point: 0043ddfe
 * Size: 69 bytes
 */


int32_t SetSndMarker(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694514)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: PlaySndMarker
 * Entry Point: 0043de43
 * Size: 69 bytes
 */


int32_t PlaySndMarker(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694518)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetSndTime
 * Entry Point: 0043de88
 * Size: 65 bytes
 */


int32_t GetSndTime(int32_t arg_1)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694520)(arg_1);
  }
  return uval_1;
}



/*
 * Decompiled function: ResetSnd
 * Entry Point: 0043dec9
 * Size: 69 bytes
 */


int32_t ResetSnd(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0069451c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetSndState
 * Entry Point: 0043df0e
 * Size: 69 bytes
 */


int32_t GetSndState(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694524)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetAVISndBuff
 * Entry Point: 0043df53
 * Size: 66 bytes
 */


int32_t GetAVISndBuff(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_00694528)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: ReleaseAVISndBuff
 * Entry Point: 0043df95
 * Size: 69 bytes
 */


int32_t ReleaseAVISndBuff(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_0069452c)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetSndHWND
 * Entry Point: 0043dfda
 * Size: 55 bytes
 */


int32_t GetSndHWND(void)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_00694530)();
  }
  return uval_1;
}



/*
 * Decompiled function: IsSndLoaded
 * Entry Point: 0043e011
 * Size: 66 bytes
 */


int32_t IsSndLoaded(int32_t arg1,int32_t arg2)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 0;
  }
  else {
    uval_1 = (*DAT_00694534)(arg1,arg2);
  }
  return uval_1;
}



/*
 * Decompiled function: GetLRUSnd
 * Entry Point: 0043e053
 * Size: 73 bytes
 */


int32_t GetLRUSnd(int32_t arg_1,int32_t arg_2,int32_t arg_3)

{
  int32_t uval_1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uval_1 = 4;
  }
  else {
    uval_1 = (*DAT_00694538)(arg_1,arg_2,arg_3);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_0043e09c
 * Entry Point: 0043e09c
 * Size: 58 bytes
 */


void FUN_0043e09c(void)

{
  int slot_idx;
  
  for (slot_idx = 0; slot_idx < 0x1b; slot_idx = slot_idx + 1) {
    (&DAT_006944d0)[slot_idx] = 0;
  }
  return;
}



/*
 * Decompiled function: Ai_AssignCombatDamage
 * Entry Point: 0043e0e0
 * Size: 538 bytes
 */


int32_t
Ai_AssignCombatDamage
          (int32_t *arg_1,uint32_t *arg_2,uint32_t arg_3,int arg_4,uint32_t arg_5,uint32_t arg_6,int32_t arg_7
          ,int arg_8,int32_t arg_9)

{
  int32_t uval_1;
  int val_2;
  uint32_t local_30;
  int32_t local_2c;
  int32_t local_28;
  int32_t local_24;
  int32_t loop_idx;
  int color_idx;
  int32_t target_idx;
  uint32_t card_idx;
  int match_count;
  INT_PTR slot_idx;
  
  if ((arg_1 == (int32_t *)0x0) || (arg_2 == (uint32_t *)0x0)) {
    uval_1 = 0;
  }
  else {
    if (arg_4 == 0) {
      card_idx = arg_3;
    }
    else {
      val_2 = FUN_004491fe(s_Start_of_duel_004f79bc);
      card_idx = (uint32_t)(val_2 == 0);
    }
    if (DAT_0066aaf0 == 0) {
      match_count = 1;
    }
    else {
      if (card_idx == 0) {
        FUN_0043753a(1,1);
        UpdateWindow(DAT_00617438);
      }
      slot_idx = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf4,DAT_00618990,Ai_DuelDialogProc,
                                (LPARAM)&card_idx);
      FUN_0043753a(1,0);
    }
    FUN_004d7946(1);
    FUN_004d7946(0);
    FUN_00451482(0,0x30);
    if (((card_idx == 1) && (match_count != 0)) || ((card_idx == 0 && (match_count == 0)))) {
      local_2c = 1;
    }
    else {
      local_2c = 0;
    }
    local_28 = CardIDFromType(arg_5);
    local_24 = CardIDFromType(arg_6);
    loop_idx = arg_7;
    color_idx = arg_8;
    target_idx = arg_9;
    if (arg_8 != 0) {
      DAT_0060cc60 = 1;
      FUN_004baa8b(DAT_00663df4);
    }
    slot_idx = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe3,DAT_00618990,Ai_StartDuelWndProc,
                              (LPARAM)&local_2c);
    local_30 = (uint32_t)(slot_idx != 0);
    *arg_1 = local_2c;
    *arg_2 = local_30;
    DAT_0060cc60 = 0;
    FUN_004baa8b(DAT_00663df4);
    if (local_30 != 0) {
      PostMessageA(DAT_006152b0,0x40c,0,0);
    }
    UpdateWindow(DAT_00618990);
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: Ai_DuelDialogProc
 * Entry Point: 0043e2fa
 * Size: 2163 bytes
 */


HGDIOBJ Ai_DuelDialogProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam)

{
  size_t len_1;
  WPARAM wParam_00;
  HGDIOBJ buf_ptr_2;
  HBRUSH hbr;
  HWND pHVar3;
  BOOL BVar4;
  HWND pHVar5;
  int val_6;
  int val_7;
  int val_8;
  int iVar9;
  tagSIZE *ptVar10;
  UINT UVar11;
  LPARAM lParam_00;
  char local_24c [200];
  int local_184;
  HWND local_180;
  tagRECT local_17c;
  COLORREF local_16c;
  HWND local_168;
  HWND local_164;
  int local_160;
  HWND local_15c;
  HWND local_158;
  HWND local_154;
  uint32_t local_150;
  HDC local_14c;
  int local_148;
  int local_144;
  HGDIOBJ local_140;
  tagSIZE local_13c;
  char local_134 [200];
  char local_6c [100];
  HWND slot_idx;
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 2) {
      FUN_0043ec34((int)DAT_00516af8,(int)DAT_005169d4,(int)DAT_00516adc);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_168 = lParam;
      pHVar3 = GetFocus();
      if (pHVar3 == (HWND)local_168[5].unused) {
        local_16c = DAT_005169c8;
      }
      else {
        local_16c = DAT_00516a6c;
      }
      FUN_00472317((int)local_168,DAT_005169d4,DAT_00516adc,DAT_005169d4,local_16c,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      local_180 = wParam;
      FUN_004707a4((HDC)wParam);
      GetClientRect(hwnd,&local_17c);
      if (DAT_00516af8 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_180,&local_17c,hbr);
      }
      else {
        FUN_004709ae((int)local_180,(int)&local_17c,DAT_00516af8);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      slot_idx = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadStartDuel2Backdrop
                (&DAT_00516af8,&DAT_00516aec,&DAT_005169d4,&DAT_00516adc,&DAT_00516a6c,&DAT_005169c8
                );
      FUN_00448412(local_6c);
      if (slot_idx->unused == 1) {
        _sprintf(local_134,s__s_won_the_toss_004f79cc,local_6c);
        SetDlgItemTextA(hwnd,0x485,local_134);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x486);
        ShowWindow(pHVar3,iVar9);
        iVar9 = 0;
        pHVar3 = GetDlgItem(hwnd,0x487);
        ShowWindow(pHVar3,iVar9);
        SetFocus(hwnd);
        SetTimer(hwnd,1,1000,(TIMERPROC)0x0);
      }
      else {
        _sprintf(local_134,s_You_won_the_coin_toss__004f79dc);
        SetDlgItemTextA(hwnd,0x485,local_134);
        _sprintf(local_134,s_Would_you_like_to__004f79f4);
        SetDlgItemTextA(hwnd,0x488,local_134);
        pHVar3 = GetDlgItem(hwnd,0x486);
        SetFocus(pHVar3);
        SendMessageA(hwnd,0x401,0x486,0);
      }
      local_14c = GetDC(hwnd);
      FUN_004707a4(local_14c);
      local_140 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x486,0x31,0,0);
      SelectObject(local_14c,local_140);
      GetDlgItemTextA(hwnd,0x486,local_134,200);
      ptVar10 = &local_13c;
      len_1 = _strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,len_1,ptVar10);
      local_144 = local_13c.cx;
      local_148 = (local_13c.cy * 5) / 2;
      GetDlgItemTextA(hwnd,0x487,local_134,200);
      ptVar10 = &local_13c;
      len_1 = _strlen(local_134);
      GetTextExtentPoint32A(local_14c,local_134,len_1,ptVar10);
      if (local_13c.cx <= local_144) {
        local_13c.cx = local_144;
      }
      iVar9 = local_13c.cx + local_13c.cy * 2;
      UVar11 = 6;
      val_7 = 0;
      val_6 = 0;
      pHVar5 = (HWND)0x0;
      val_8 = local_148;
      local_144 = iVar9;
      pHVar3 = GetDlgItem(hwnd,0x486);
      SetWindowPos(pHVar3,pHVar5,val_6,val_7,iVar9,val_8,UVar11);
      UVar11 = 6;
      val_7 = 0;
      val_6 = 0;
      pHVar5 = (HWND)0x0;
      iVar9 = local_144;
      val_8 = local_148;
      pHVar3 = GetDlgItem(hwnd,0x487);
      SetWindowPos(pHVar3,pHVar5,val_6,val_7,iVar9,val_8,UVar11);
      ReleaseDC(hwnd,local_14c);
      FUN_00472552(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x102) {
LAB_0043ea12:
      pHVar3 = GetDlgItem(hwnd,0x486);
      BVar4 = IsWindowVisible(pHVar3);
      if (BVar4 == 0) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
        return (HGDIOBJ)0x1;
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_15c = wParam;
      FUN_004707a4((HDC)wParam);
      local_164 = lParam;
      local_160 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_15c,1);
      SetTextColor((HDC)local_15c,DAT_00516aec);
      buf_ptr_2 = GetStockObject(5);
      return buf_ptr_2;
    }
    if (uMsg == 0x111) {
      local_150 = (uint32_t)wParam & 0xffff;
      if ((0x485 < local_150) && (local_150 < 0x488)) {
        slot_idx = (HWND)GetWindowLongA(hwnd,8);
        if (local_150 == 0x486) {
          *(int32_t *)((int)slot_idx + 4) = 1;
        }
        else {
          *(int32_t *)((int)slot_idx + 4) = 0;
        }
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      if (wParam == (HWND)0x1) {
        KillTimer(hwnd,1);
        local_184 = FUN_00439892(2);
        slot_idx = (HWND)GetWindowLongA(hwnd,8);
        *(int *)((int)slot_idx + 4) = local_184;
        if (local_184 == 0) {
          _sprintf(local_24c,s_and_has_chosen_to_draw_first__004f7a20);
        }
        else {
          _sprintf(local_24c,s_and_will_play_first__004f7a08);
        }
        SetDlgItemTextA(hwnd,0x488,local_24c);
        iVar9 = 5;
        pHVar3 = GetDlgItem(hwnd,0x488);
        ShowWindow(pHVar3,iVar9);
        SetTimer(hwnd,2,3000,(TIMERPROC)0x0);
      }
      else if (wParam == (HWND)0x2) {
        KillTimer(hwnd,2);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg < 0x205) {
    if ((uMsg == 0x204) || (uMsg == 0x201)) goto LAB_0043ea12;
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      buf_ptr_2 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,wParam,lParam);
      return buf_ptr_2;
    }
    if (uMsg == 0x4c8) {
      local_154 = wParam;
      local_158 = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_154 != (HWND)0x0) {
        InvalidateRect(local_154,(RECT *)0x0,1);
      }
      if (local_158 != (HWND)0x0) {
        InvalidateRect(local_158,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: Ai_LoadStartDuel2Backdrop
 * Entry Point: 0043eb81
 * Size: 179 bytes
 */


void Ai_LoadStartDuel2Backdrop
               (int32_t *arg_1,int32_t *out_buffer,int32_t *arg_3,int32_t *arg_4,
               int32_t *arg_5,int32_t *arg_6)

{
  int32_t uval_1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel2_pic_004f7a40,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7a58,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_3 = uval_1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7a7c,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_4 = uval_1;
  *arg_5 = 0x1000001;
  *arg_6 = 0x10000bf;
  return;
}



/*
 * Decompiled function: FUN_0043ec34
 * Entry Point: 0043ec34
 * Size: 77 bytes
 */


void FUN_0043ec34(int player_id,int card_slot,int event_type)

{
  if (arg_1 != 0) {
    FUN_00471395((HANDLE)arg_1);
  }
  if (arg_2 != 0) {
    FUN_00471395((HANDLE)arg_2);
  }
  if (arg_3 != 0) {
    FUN_00471395((HANDLE)arg_3);
  }
  return;
}



/*
 * Decompiled function: Ai_StartDuelWndProc
 * Entry Point: 0043ec81
 * Size: 3683 bytes
 */


HGDIOBJ Ai_StartDuelWndProc(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  size_t len_1;
  int val_2;
  int val_3;
  WPARAM wParam_00;
  HGDIOBJ pvVar4;
  BOOL BVar5;
  HBRUSH hbr;
  HWND pHVar6;
  HDC hdc;
  LONG Y;
  int val_7;
  tagSIZE *ptVar8;
  LPARAM lParam_00;
  tagRECT *ptVar9;
  tagPAINTSTRUCT local_280;
  tagRECT local_240;
  uint32_t local_230;
  uint32_t local_22c;
  tagRECT local_228;
  tagRECT local_218;
  HWND local_208;
  tagRECT local_204;
  int local_1f4;
  COLORREF local_1f0;
  HWND local_1ec;
  HWND local_1e8;
  int local_1e4;
  HWND local_1e0;
  HWND local_1dc;
  HWND local_1d8;
  uint32_t local_1d4 [25];
  uint32_t local_170;
  tagRECT local_16c;
  HDC local_15c;
  int local_158;
  int local_154;
  HGDIOBJ local_150;
  tagRECT local_14c;
  tagSIZE local_13c;
  uint32_t local_134 [50];
  char local_6c [100];
  HWND slot_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_208 = wParam;
      FUN_004707a4((HDC)wParam);
      GetClientRect(hwnd,&local_204);
      if (DAT_00516a9c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect((HDC)local_208,&local_204,hbr);
      }
      else {
        FUN_004709ae((int)local_208,(int)&local_204,DAT_00516a9c);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      pHVar6 = GetDlgItem(hwnd,0x413);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x418);
      UpdateWindow(pHVar6);
      pHVar6 = GetDlgItem(hwnd,0x417);
      UpdateWindow(pHVar6);
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      hdc = BeginPaint(hwnd,&local_280);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        if (*(int *)((int)slot_idx + 8) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x470);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (int32_t *)(&DAT_00618ac0 + *(int *)((int)slot_idx + 8) * 0x98),0,2,0);
        }
        if (*(int *)((int)slot_idx + 4) != -1) {
          ptVar9 = &local_240;
          pHVar6 = GetDlgItem(hwnd,0x46f);
          GetWindowRect(pHVar6,ptVar9);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_240,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_240.left,
                     (int32_t *)(&DAT_00618ac0 + *(int *)((int)slot_idx + 4) * 0x98),0,2,0);
        }
        EndPaint(hwnd,&local_280);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      BringWindowToTop(DAT_006152b0);
      slot_idx = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      val_7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x46f);
      ShowWindow(pHVar6,val_7);
      val_7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x470);
      ShowWindow(pHVar6,val_7);
      DAT_00516a98 = 0;
      Ai_LoadStartDuelBackdrop
                (&DAT_00516a9c,&DAT_00516b08,&DAT_00516ac4,&DAT_0051697c,&DAT_00516970,&DAT_00516a94
                 ,&DAT_00516a7c);
      FUN_00448412(local_6c);
      if (slot_idx->unused == 1) {
        _sprintf((char *)local_134,s__s_will_start_first_004f7aa4,local_6c);
        SetDlgItemTextA(hwnd,0x413,(LPCSTR)local_134);
      }
      else {
        SetDlgItemTextA(hwnd,0x413,s_You_will_take_the_first_turn_004f7ab8);
      }
      _sprintf((char *)local_134,s__s_ante__004f7ad8,local_6c);
      SetDlgItemTextA(hwnd,0x417,(LPCSTR)local_134);
      Mem_AllocOrFree_004d9630(local_134,(uint32_t *)s_Your_ante__004f7ae4);
      SetDlgItemTextA(hwnd,0x418,(LPCSTR)local_134);
      if (slot_idx[4].unused == 0) {
        _sprintf((char *)local_134,s__s_did_not_take_a_mulligan_004f7b6c,local_6c);
        SetDlgItemTextA(hwnd,0x414,(LPCSTR)local_134);
      }
      else {
        if (slot_idx[4].unused == 1) {
          _sprintf((char *)local_134,s__s_has_no_land_and_chose_to_take_004f7af0,local_6c);
        }
        else if (slot_idx[4].unused == 2) {
          _sprintf((char *)local_134,s__s_has_all_land_and_will_take_a_m_004f7b1c,local_6c);
        }
        else {
          _sprintf((char *)local_134,s__s_has_chosen_to_take_a_mulligan_004f7b48,local_6c);
        }
        SetDlgItemTextA(hwnd,0x414,(LPCSTR)local_134);
      }
      if (slot_idx[4].unused == 0) {
        if (slot_idx[3].unused == 0) {
          val_7 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,val_7);
          pHVar6 = GetDlgItem(hwnd,1);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,1,0);
        }
        else {
          val_7 = 5;
          pHVar6 = GetDlgItem(hwnd,0x415);
          ShowWindow(pHVar6,val_7);
          pHVar6 = GetDlgItem(hwnd,0x415);
          SetFocus(pHVar6);
          SendMessageA(hwnd,0x401,0x415,0);
        }
      }
      else {
        val_7 = 5;
        pHVar6 = GetDlgItem(hwnd,0x415);
        ShowWindow(pHVar6,val_7);
        pHVar6 = GetDlgItem(hwnd,0x415);
        SetFocus(pHVar6);
        SendMessageA(hwnd,0x401,0x415,0);
      }
      val_7 = 0;
      pHVar6 = GetDlgItem(hwnd,0x416);
      ShowWindow(pHVar6,val_7);
      slot_idx[6].unused = 0;
      local_15c = GetDC(hwnd);
      FUN_004707a4(local_15c);
      local_150 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x415,0x31,0,0);
      SelectObject(local_15c,local_150);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,0x415);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,0x415,(LPSTR)local_134,200);
      ptVar8 = &local_13c;
      len_1 = _strlen((char *)local_134);
      GetTextExtentPoint32A(local_15c,(LPCSTR)local_134,len_1,ptVar8);
      val_2 = local_13c.cy * 2 + local_13c.cx;
      val_3 = (local_13c.cy * 5) / 2;
      val_7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - val_2 / 2);
      BVar5 = 1;
      Y = local_14c.top;
      local_158 = val_3;
      local_154 = val_2;
      local_14c.left = val_7;
      pHVar6 = GetDlgItem(hwnd,0x415);
      MoveWindow(pHVar6,val_7,Y,val_2,val_3,BVar5);
      ptVar9 = &local_14c;
      pHVar6 = GetDlgItem(hwnd,1);
      GetWindowRect(pHVar6,ptVar9);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
      GetDlgItemTextA(hwnd,1,(LPSTR)local_134,200);
      ptVar8 = &local_13c;
      len_1 = _strlen((char *)local_134);
      GetTextExtentPoint32A(local_15c,(LPCSTR)local_134,len_1,ptVar8);
      val_2 = local_13c.cy * 2 + local_13c.cx;
      val_3 = (local_13c.cy * 5) / 2;
      val_7 = local_14c.left + ((local_14c.right - local_14c.left) / 2 - val_2 / 2);
      BVar5 = 1;
      local_158 = val_3;
      local_154 = val_2;
      local_14c.left = val_7;
      pHVar6 = GetDlgItem(hwnd,1);
      MoveWindow(pHVar6,val_7,local_14c.top,val_2,val_3,BVar5);
      if (slot_idx[1].unused == -1) {
        val_7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        ShowWindow(pHVar6,val_7);
        val_7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x417);
        ShowWindow(pHVar6,val_7);
      }
      if (slot_idx[2].unused == -1) {
        val_7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x470);
        ShowWindow(pHVar6,val_7);
        val_7 = 0;
        pHVar6 = GetDlgItem(hwnd,0x418);
        ShowWindow(pHVar6,val_7);
      }
      ReleaseDC(hwnd,local_15c);
      FUN_00472552(hwnd);
      if ((slot_idx[4].unused != 0) || (slot_idx[3].unused != 0)) {
        GetWindowRect(hwnd,&local_16c);
        SetWindowPos(hwnd,(HWND)0x0,5,local_16c.top,0,0,5);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x2b) {
      local_1ec = lParam;
      pHVar6 = GetFocus();
      if (pHVar6 == (HWND)local_1ec[5].unused) {
        local_1f0 = DAT_00516a7c;
      }
      else {
        local_1f0 = DAT_00516a94;
      }
      local_1f4 = 0;
      pHVar6 = GetDlgItem(hwnd,0x415);
      BVar5 = IsWindowVisible(pHVar6);
      if (BVar5 == 0) {
        local_1f0 = DAT_00516a94;
        local_1f4 = 1;
      }
      FUN_00472317((int)local_1ec,DAT_00516ac4,DAT_0051697c,DAT_00516970,local_1f0,local_1f4);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_1e0 = wParam;
      FUN_004707a4((HDC)wParam);
      local_1e8 = lParam;
      local_1e4 = GetDlgCtrlID(lParam);
      SetBkMode((HDC)local_1e0,1);
      SetTextColor((HDC)local_1e0,DAT_00516b08);
      pvVar4 = GetStockObject(5);
      return pvVar4;
    }
    if (uMsg == 0x111) {
      local_170 = (uint32_t)wParam & 0xffff;
      if (local_170 != 0) {
        if (local_170 < 3) {
          slot_idx = (HWND)GetWindowLongA(hwnd,8);
          FUN_0043fbce((int)DAT_00516a9c,(int)DAT_00516ac4,(int)DAT_0051697c,(int)DAT_00516970);
          EndDialog(hwnd,*(INT_PTR *)((int)slot_idx + 0x18));
        }
        else if (local_170 == 0x415) {
          slot_idx = (HWND)GetWindowLongA(hwnd,8);
          *(int32_t *)((int)slot_idx + 0x18) = 1;
          BVar5 = 0;
          pHVar6 = GetDlgItem(hwnd,0x415);
          EnableWindow(pHVar6,BVar5);
          val_7 = 0;
          pHVar6 = GetDlgItem(hwnd,1);
          ShowWindow(pHVar6,val_7);
          if (*(int *)((int)slot_idx + 0x10) == 0) {
            Sleep(500);
            FUN_00448412((char *)local_1d4);
            if (*(int *)((int)slot_idx + 0x14) == 0) {
              FUN_004d9640(local_1d4,(uint32_t *)s_decided_not_to_take_a_mulligan_004f7ba4);
            }
            else {
              FUN_004d9640(local_1d4,(uint32_t *)s_will_also_take_a_mulligan_004f7b88);
            }
            SetDlgItemTextA(hwnd,0x416,(LPCSTR)local_1d4);
            val_7 = 5;
            pHVar6 = GetDlgItem(hwnd,0x416);
            ShowWindow(pHVar6,val_7);
            if (*(int *)((int)slot_idx + 0x14) != 0) {
              SendMessageA(DAT_00663df4,0x40c,0,0);
            }
          }
          SetTimer(hwnd,1,2000,(TIMERPROC)0x0);
        }
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x113) {
      FUN_0043fbce((int)DAT_00516a9c,(int)DAT_00516ac4,(int)DAT_0051697c,(int)DAT_00516970);
      EndDialog(hwnd,1);
      return (HGDIOBJ)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pvVar4 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,wParam,lParam);
        return pvVar4;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HGDIOBJ)0x1;
        }
        if (uMsg != 0x204) {
          return (HGDIOBJ)0x0;
        }
      }
      local_230 = (uint32_t)lParam & 0xffff;
      local_22c = (uint32_t)lParam >> 0x10;
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
        ptVar9 = &local_218;
        pHVar6 = GetDlgItem(hwnd,0x46f);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_218,2);
        ptVar9 = &local_228;
        pHVar6 = GetDlgItem(hwnd,0x470);
        GetWindowRect(pHVar6,ptVar9);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_228,2);
        if ((*(int *)((int)slot_idx + 4) == -1) ||
           (pt.y = local_22c, pt.x = local_230, BVar5 = PtInRect(&local_218,pt), BVar5 == 0)) {
          if ((*(int *)((int)slot_idx + 8) != -1) &&
             (pt_00.y = local_22c, pt_00.x = local_230, BVar5 = PtInRect(&local_228,pt_00),
             BVar5 != 0)) {
            SendMessageA(DAT_006152e0,0x401,*(WPARAM *)((int)slot_idx + 8),0);
          }
        }
        else {
          SendMessageA(DAT_006152e0,0x401,*(WPARAM *)((int)slot_idx + 4),0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x4c8) {
      local_1d8 = wParam;
      local_1dc = lParam;
      if (wParam != (HWND)0x0) {
        lParam_00 = 0;
        wParam_00 = GetDlgCtrlID(wParam);
        SendMessageA(hwnd,0x401,wParam_00,lParam_00);
      }
      if (local_1d8 != (HWND)0x0) {
        InvalidateRect(local_1d8,(RECT *)0x0,1);
      }
      if (local_1dc != (HWND)0x0) {
        InvalidateRect(local_1dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: Ai_LoadStartDuelBackdrop
 * Entry Point: 0043faee
 * Size: 224 bytes
 */


void Ai_LoadStartDuelBackdrop
               (int32_t *arg_1,int32_t *out_buffer,int32_t *arg_3,int32_t *arg_4,
               int32_t *arg_5,int32_t *arg_6,int32_t *arg_7)

{
  int32_t uval_1;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_StartDuel_pic_004f7bc4,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonNormal_p_004f7bdc,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_3 = uval_1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDepresse_004f7c00,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_4 = uval_1;
  _sprintf(local_10c,s__s_WINBK_StartDuelButtonDisabled_004f7c28,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_5 = uval_1;
  *arg_6 = 0x1000001;
  *arg_7 = 0x10000bf;
  return;
}



/*
 * Decompiled function: FUN_0043fbce
 * Entry Point: 0043fbce
 * Size: 99 bytes
 */


void FUN_0043fbce(int x,int y,int width,int height)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
  }
  if (y != 0) {
    FUN_00471395((HANDLE)y);
  }
  if (width != 0) {
    FUN_00471395((HANDLE)width);
  }
  if (height != 0) {
    FUN_00471395((HANDLE)height);
  }
  return;
}



/*
 * Decompiled function: Ai_ScoreBoardPermanents
 * Entry Point: 0043fc31
 * Size: 298 bytes
 */


void Ai_ScoreBoardPermanents(int player_id)

{
  int val_1;
  uint32_t local_918 [75];
  int32_t local_7ec;
  int32_t local_7e8;
  int32_t local_7e4;
  int32_t local_7e0 [500];
  int32_t card_idx;
  int32_t match_count;
  
  KillTimer(DAT_00618990,DAT_00663610);
  val_1 = FUN_00448799(local_7e0,0);
  if (val_1 == 0) {
    match_count = 0xffffffff;
  }
  else {
    match_count = local_7e0[0];
  }
  val_1 = FUN_00448799(local_7e0,1);
  if (val_1 == 0) {
    card_idx = 0xffffffff;
  }
  else {
    card_idx = local_7e0[0];
  }
  if (arg_1 == 0) {
    FUN_00448412((char *)local_918);
    FUN_004d9640(local_918,(uint32_t *)&DAT_004f7c50);
  }
  else if (arg_1 == 1) {
    Mem_AllocOrFree_004d9630(local_918,(uint32_t *)s_You_won__004f7c58);
  }
  else {
    Mem_AllocOrFree_004d9630(local_918,(uint32_t *)s_The_duel_is_a_draw_004f7c64);
  }
  local_7ec = 0;
  local_7e8 = match_count;
  local_7e4 = card_idx;
  DialogBoxParamA(DAT_00664680,(LPCSTR)0xf6,DAT_00618990,Ai_DuelMainWndProc,(LPARAM)local_918);
  return;
}



/*
 * Decompiled function: Ai_CalculateCombatOdds
 * Entry Point: 0043fd5b
 * Size: 241 bytes
 */


INT_PTR Ai_CalculateCombatOdds
                  (int32_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4,
                  int32_t arg_5)

{
  int val_1;
  INT_PTR IVar2;
  char local_918 [300];
  int32_t local_7ec;
  int32_t local_7e8;
  int32_t local_7e4;
  int32_t local_7e0 [500];
  int32_t card_idx;
  int32_t match_count;
  
  KillTimer(DAT_00618990,DAT_00663610);
  val_1 = FUN_00448799(local_7e0,0);
  if (val_1 == 0) {
    match_count = 0xffffffff;
  }
  else {
    match_count = local_7e0[0];
  }
  val_1 = FUN_00448799(local_7e0,1);
  if (val_1 == 0) {
    card_idx = 0xffffffff;
  }
  else {
    card_idx = local_7e0[0];
  }
  _sprintf(local_918,s__s_That_was_round__d_Your_record_004f7c78,arg_1,arg_2,arg_3,arg_4,arg_5);
  local_7ec = 1;
  local_7e8 = match_count;
  local_7e4 = card_idx;
  IVar2 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf6,DAT_00618990,Ai_DuelMainWndProc,
                          (LPARAM)local_918);
  return IVar2;
}



/*
 * Decompiled function: Ai_DuelMainWndProc
 * Entry Point: 0043fe4c
 * Size: 2918 bytes
 */


HGDIOBJ Ai_DuelMainWndProc(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  POINT pt;
  POINT pt_00;
  HGDIOBJ buf_ptr_1;
  HBRUSH hbr;
  int val_2;
  BOOL BVar3;
  HWND pHVar4;
  HDC hdc;
  int val_5;
  tagRECT *ptVar6;
  tagPAINTSTRUCT local_1b4;
  int local_174;
  tagRECT local_170;
  int local_160;
  int local_15c;
  WPARAM local_158;
  uint32_t local_154;
  uint32_t local_150;
  tagRECT local_14c;
  tagRECT local_13c;
  WPARAM local_12c;
  tagRECT local_128;
  tagRECT local_118;
  HDC local_108;
  tagRECT local_104;
  COLORREF local_f4;
  HWND local_f0;
  HWND local_ec;
  int local_e8;
  HDC local_e4;
  HWND local_dc;
  HDC local_d8;
  WPARAM local_d4;
  uint32_t local_d0 [50];
  HWND slot_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_108 = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_104);
      if (DAT_00516afc == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_108,&local_104,hbr);
      }
      else {
        FUN_004709ae((int)local_108,(int)&local_104,DAT_00516afc);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0xf) {
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      pHVar4 = GetDlgItem(hwnd,0x48f);
      UpdateWindow(pHVar4);
      FUN_0044897a(&local_160,(int32_t *)0x0);
      if (local_160 == 0) {
        pHVar4 = GetDlgItem(hwnd,0x48d);
        UpdateWindow(pHVar4);
      }
      else {
        pHVar4 = GetDlgItem(hwnd,0x48e);
        UpdateWindow(pHVar4);
      }
      hdc = BeginPaint(hwnd,&local_1b4);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        if (local_160 == 0) {
          local_15c = *(int *)((int)slot_idx + 0x130);
          local_174 = 0x491;
        }
        else {
          local_15c = *(int *)((int)slot_idx + 0x134);
          local_174 = 0x490;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(int32_t *)(&DAT_00618ac0 + local_15c * 0x98),0,0x12,0);
        }
        if (local_160 == 0) {
          local_15c = *(int *)((int)slot_idx + 0x134);
          local_174 = 0x490;
        }
        else {
          local_15c = *(int *)((int)slot_idx + 0x130);
          local_174 = 0x491;
        }
        if (local_15c != -1) {
          ptVar6 = &local_170;
          pHVar4 = GetDlgItem(hwnd,local_174);
          GetWindowRect(pHVar4,ptVar6);
          MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_170,2);
          Palette_Subsystem_0049c7c7
                    (hdc,&local_170.left,(int32_t *)(&DAT_00618ac0 + local_15c * 0x98),0,0x12,0);
        }
        EndPaint(hwnd,&local_1b4);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x103) {
    if (uMsg == 0x102) {
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      if ((*(int *)((int)slot_idx + 300) == 0) &&
         (((wParam == (HDC)0xd || (wParam == (HDC)0x20)) || (wParam == (HDC)0x1b)))) {
        FUN_00440a9c((int)DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x2b) {
      local_f0 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_f0[5].unused) {
        local_f4 = DAT_005169dc;
      }
      else {
        local_f4 = DAT_0051696c;
      }
      if (DAT_005f77ec == 0) {
        local_f4 = DAT_0051696c;
      }
      FUN_00471f45((int)local_f0,DAT_00516a04,DAT_00516994,DAT_00516ab0,local_f4,0);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_0044016c:
      local_e4 = wParam;
      FUN_004707a4(wParam);
      local_ec = lParam;
      local_e8 = GetDlgCtrlID(lParam);
      if ((local_e8 != 0x493) && (local_e8 != 0x494)) {
        SetTextColor(local_e4,DAT_005169d8);
        SetBkMode(local_e4,1);
        buf_ptr_1 = GetStockObject(5);
        return buf_ptr_1;
      }
      pHVar4 = GetFocus();
      if (pHVar4 == local_ec) {
        SetTextColor(local_e4,DAT_005169dc);
      }
      else {
        SetTextColor(local_e4,DAT_00516974);
      }
      SetBkMode(local_e4,1);
      buf_ptr_1 = GetStockObject(5);
      return buf_ptr_1;
    }
    if (uMsg == 0x110) {
      slot_idx = lParam;
      SetWindowLongA(hwnd,8,(LONG)lParam);
      Ai_LoadEndDuelBackdrop
                (&DAT_00516afc,&DAT_005169d8,&DAT_00516974,(int *)&DAT_00516a04,(int *)&DAT_00516994
                 ,(int *)&DAT_00516ab0,&DAT_0051696c,&DAT_005169dc);
      val_5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x490);
      ShowWindow(pHVar4,val_5);
      val_5 = 0;
      pHVar4 = GetDlgItem(hwnd,0x491);
      ShowWindow(pHVar4,val_5);
      FUN_00448412((char *)local_d0);
      FUN_004d9640(local_d0,(uint32_t *)s_next_draw__004f7ca8);
      SetDlgItemTextA(hwnd,0x48e,(LPCSTR)local_d0);
      Mem_AllocOrFree_004d9630(local_d0,(uint32_t *)s_Your_next_draw__004f7cb4);
      SetDlgItemTextA(hwnd,0x48d,(LPCSTR)local_d0);
      SetDlgItemTextA(hwnd,0x48f,(LPCSTR)slot_idx);
      if (slot_idx[0x4b].unused == 0) {
        val_5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x493);
        ShowWindow(pHVar4,val_5);
        val_5 = 0;
        pHVar4 = GetDlgItem(hwnd,0x494);
        ShowWindow(pHVar4,val_5);
      }
      else {
        if (DAT_005f77ec == 0) {
          val_5 = 0;
          pHVar4 = GetDlgItem(hwnd,0x493);
          ShowWindow(pHVar4,val_5);
          SetDlgItemTextA(hwnd,0x494,&DAT_004f7ce0);
          local_d4 = 0x494;
        }
        else {
          local_d4 = 0x493;
          SetDlgItemTextA(hwnd,0x493,s_Next_Round_004f7cc4);
          SetDlgItemTextA(hwnd,0x494,s_Quit_Gauntlet_004f7cd0);
        }
        pHVar4 = GetDlgItem(hwnd,local_d4);
        SetFocus(pHVar4);
        SendMessageA(hwnd,0x401,local_d4,0);
        FUN_00472552(hwnd);
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      if (((uint32_t)wParam & 0xffff) == 0x493) {
        FUN_00440a9c((int)DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(hwnd,4);
      }
      else if ((((uint32_t)wParam & 0xffff) == 0x494) || (((uint32_t)wParam & 0xffff) == 2)) {
        FUN_00440a9c((int)DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(hwnd,0);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004404b6:
      local_154 = (uint32_t)lParam & 0xffff;
      local_150 = (uint32_t)lParam >> 0x10;
      slot_idx = (HWND)GetWindowLongA(hwnd,8);
      if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
        local_12c = *(WPARAM *)((int)slot_idx + 0x130);
        ptVar6 = &local_14c;
        pHVar4 = GetDlgItem(hwnd,0x491);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_14c,2);
        local_158 = *(WPARAM *)((int)slot_idx + 0x134);
        ptVar6 = &local_13c;
        pHVar4 = GetDlgItem(hwnd,0x490);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_13c,2);
        if ((local_12c == 0xffffffff) ||
           (pt.y = local_150, pt.x = local_154, BVar3 = PtInRect(&local_14c,pt), BVar3 == 0)) {
          if ((local_158 != 0xffffffff) &&
             (pt_00.y = local_150, pt_00.x = local_154, BVar3 = PtInRect(&local_13c,pt_00),
             BVar3 != 0)) {
            SendMessageA(DAT_006152e0,0x401,local_158,0);
          }
        }
        else {
          SendMessageA(DAT_006152e0,0x401,local_12c,0);
        }
      }
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x138) goto LAB_0044016c;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004404b6;
    if (uMsg == 0x201) {
      GetWindowRect(hwnd,&local_118);
      SendMessageA(hwnd,0x112,0xf012,0);
      GetWindowRect(hwnd,&local_128);
      val_5 = Mem_AllocOrFree_004d9810(local_128.top - local_118.top);
      val_2 = Mem_AllocOrFree_004d9810(local_128.left - local_118.left);
      if ((val_5 + val_2 < 6) &&
         (slot_idx = (HWND)GetWindowLongA(hwnd,8), *(int *)((int)slot_idx + 300) == 0)) {
        FUN_00440a9c((int)DAT_00516afc,DAT_00516a04,DAT_00516994,DAT_00516ab0);
        EndDialog(hwnd,1);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      buf_ptr_1 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return buf_ptr_1;
    }
    if (uMsg == 0x4c8) {
      local_d8 = wParam;
      local_dc = lParam;
      if (wParam != (HDC)0x0) {
        SendMessageA(hwnd,0x401,(WPARAM)wParam,0);
      }
      if (local_d8 != (HDC)0x0) {
        InvalidateRect((HWND)local_d8,(RECT *)0x0,1);
      }
      if (local_dc != (HWND)0x0) {
        InvalidateRect(local_dc,(RECT *)0x0,1);
      }
      return (HGDIOBJ)0x0;
    }
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: Ai_LoadEndDuelBackdrop
 * Entry Point: 004409b7
 * Size: 229 bytes
 */


void Ai_LoadEndDuelBackdrop
               (int32_t *arg_1,int32_t *out_buffer,int32_t *arg_3,int *arg_4,int *arg_5,
               int *arg_6,int32_t *arg_7,int32_t *arg_8)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_EndDuel_pic_004f7ce4,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0x1000040;
  *arg_3 = 0x1000040;
  pHVar2 = CreateSolidBrush(0x100001a);
  *arg_4 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x100008c);
  *arg_5 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000001);
  *arg_6 = (int)pHVar3;
  *arg_7 = 0x1000040;
  *arg_8 = 0x10000bf;
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_5 = (int)pvVar4;
  }
  if (*arg_6 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_6 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_00440a9c
 * Entry Point: 00440a9c
 * Size: 93 bytes
 */


void FUN_00440a9c(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}



/*
 * Decompiled function: FUN_00440af9
 * Entry Point: 00440af9
 * Size: 293 bytes
 */


int32_t FUN_00440af9(int arg1,int arg2)

{
  uint32_t slot_idx;
  
  KillTimer(DAT_00618990,DAT_00663610);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if ((DAT_005f77e8 != arg1) || (DAT_006152e4 != arg2)) {
    slot_idx = slot_idx | 1;
  }
  DAT_005f77e8 = arg1;
  DAT_006152e4 = arg2;
  DAT_00617370 = DAT_006826b0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (slot_idx != 0) {
    SendMessageA(DAT_006152ec,0x432,0,0);
    UpdateWindow(DAT_006152ec);
    SendMessageA(DAT_006152e8,0x432,0,0);
    UpdateWindow(DAT_006152e8);
  }
  if ((arg2 == 0x15) && (arg1 == 1)) {
    DAT_006152b4 = 0;
  }
  if ((arg2 == 0x15) && (DAT_006826b0 != 0)) {
    FUN_0049793e(DAT_00618ab0);
  }
  if (arg2 == 0x1e) {
    FUN_0049793e(DAT_00618ab0);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00440c1e
 * Entry Point: 00440c1e
 * Size: 737 bytes
 */


LRESULT FUN_00440c1e(int32_t arg_1,int card_slot,int32_t arg_3,int32_t arg_4,int32_t arg_5,
                    int32_t arg_6,int32_t arg_7,int *arg_8,int32_t *arg_9,int32_t arg_10
                    ,int32_t arg_11)

{
  POINT Point;
  POINT Point_00;
  BOOL BVar1;
  tagPOINT local_1e4;
  HWND local_1dc;
  DWORD local_1d8;
  tagPOINT local_1d4;
  HWND local_1cc;
  uint32_t local_1c8 [50];
  int local_100;
  int32_t local_fc;
  int32_t local_f8;
  LRESULT local_f0;
  int32_t local_ec;
  int32_t local_e8;
  int32_t local_e4;
  int32_t local_e0;
  int32_t local_dc;
  int32_t local_d8;
  uint32_t local_d4 [50];
  int32_t match_count;
  int32_t slot_idx;
  
  if (arg_2 == 0) {
    Mem_AllocOrFree_004d9630(local_1c8,(uint32_t *)&DAT_004f7cfc);
  }
  else {
    Mem_AllocOrFree_004d9630(local_1c8,(uint32_t *)arg_2);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (DAT_0060d490 != -1) {
    DAT_0060d490 = -1;
    BVar1 = IsWindowVisible(DAT_006152ec);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006152e8,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006152ec,(RECT *)0x0,1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  FUN_00451482(0,0xff);
  GetCursorPos(&local_1d4);
  Point.y = local_1d4.y;
  Point.x = local_1d4.x;
  local_1cc = WindowFromPoint(Point);
  SendMessageA(local_1cc,0x20,(WPARAM)local_1cc,0x2000001);
  local_ec = arg_1;
  local_e8 = arg_4;
  local_e4 = arg_5;
  local_e0 = arg_6;
  local_dc = arg_7;
  match_count = arg_10;
  slot_idx = arg_11;
  Mem_AllocOrFree_004d9630(local_d4,local_1c8);
  local_d8 = arg_3;
  local_f0 = SendMessageA(DAT_00618990,0x403,(WPARAM)&local_ec,(LPARAM)&local_100);
  *arg_8 = local_100;
  *arg_9 = local_fc;
  arg_9[1] = local_f8;
  FUN_00446a07((char *)0x0);
  if (local_100 != -5) {
    GetCursorPos(&local_1e4);
    Point_00.y = local_1e4.y;
    Point_00.x = local_1e4.x;
    local_1dc = WindowFromPoint(Point_00);
    SendMessageA(local_1dc,0x20,(WPARAM)local_1dc,0x2000001);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (DAT_0068f2cc == -2) {
      if (DAT_0066ab04 == -1) {
        DAT_0060d490 = -1;
        DAT_0060cc74 = 0xffffffff;
      }
      else {
        DAT_0060cc74 = DAT_0066aac4;
        DAT_0060d490 = DAT_0066ab04;
      }
    }
    else {
      DAT_0060d490 = -1;
      DAT_0060cc74 = 0xffffffff;
    }
    BVar1 = IsWindowVisible(DAT_006152ec);
    if (BVar1 == 0) {
      InvalidateRect(DAT_006152e8,(RECT *)0x0,1);
    }
    else {
      InvalidateRect(DAT_006152ec,(RECT *)0x0,1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    return local_f0;
  }
  local_1d8 = 0;
  PostMessageA(DAT_00618990,0x401,0,0);
                    /* WARNING: Subroutine does not return */
  ExitThread(local_1d8);
}



/*
 * Decompiled function: FUN_00440eff
 * Entry Point: 00440eff
 * Size: 35 bytes
 */


void FUN_00440eff(void)

{
  SendMessageA(DAT_00618990,0x464,0xff,0);
  return;
}



/*
 * Decompiled function: Ai_EvaluateCreatureCast
 * Entry Point: 00440f22
 * Size: 445 bytes
 */


INT_PTR Ai_EvaluateCreatureCast
                  (int *arg_1,int card_slot,int event_type,int32_t arg_4,int arg_5,uint32_t *arg_6)

{
  INT_PTR IVar1;
  int32_t uval_2;
  int32_t local_690;
  int32_t auStack_68c [200];
  int32_t auStack_36c [200];
  int local_4c;
  uint32_t local_48;
  int local_44;
  uint32_t local_40 [3];
  int local_34;
  WNDCLASSA local_30;
  
  if (((arg_3 < 1) || (arg_1 == (int *)0x0)) || (*arg_1 == -1)) {
    IVar1 = -1;
  }
  else {
    local_30.style = 0;
    local_30.lpfnWndProc = UI_WndProc_0044233e;
    local_30.cbClsExtra = 0;
    local_30.cbWndExtra = 0xc;
    local_30.hInstance = DAT_00664680;
    local_30.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    local_30.hbrBackground = (HBRUSH)0x6;
    local_30.lpszMenuName = (LPCSTR)0x0;
    local_30.lpszClassName = s_ShowListCard_004f7d00;
    RegisterClassA(&local_30);
    local_690 = arg_4;
    for (local_34 = 0; (local_34 < arg_3 && (arg_1[local_34] != -1)); local_34 = local_34 + 1) {
      uval_2 = CardIDFromType(arg_1[local_34] & 0xfff);
      auStack_68c[local_34] = uval_2;
    }
    local_4c = local_34;
    local_48 = (uint32_t)(arg_2 != 0);
    if (local_48 != 0) {
      for (local_34 = 0; local_34 < local_4c; local_34 = local_34 + 1) {
        auStack_36c[local_34] = *(int32_t *)(arg_2 + local_34 * 4);
      }
    }
    local_44 = arg_5;
    if (arg_5 == 0) {
      Mem_AllocOrFree_004d9630(local_40,arg_6);
    }
    else {
      Mem_AllocOrFree_004d9630(local_40,(uint32_t *)&DAT_004f7d10);
    }
    IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe9,DAT_00618990,Ai_EvaluateSpellCast,
                            (LPARAM)&local_690);
  }
  return IVar1;
}



/*
 * Decompiled function: Ai_EvaluateSpellCast
 * Entry Point: 004410df
 * Size: 4321 bytes
 */


LRESULT Ai_EvaluateSpellCast(HWND hwnd,uint32_t y,HDC hdc,int32_t *arg_4)

{
  uint32_t uval_1;
  int val_2;
  DWORD dwStyle;
  int cx;
  int val_3;
  int val_4;
  LRESULT LVar5;
  HGDIOBJ pvVar6;
  HDC hdc_00;
  size_t c;
  BOOL bMenu;
  UINT uFlags;
  tagSIZE *psizl;
  LONG local_15c;
  LONG local_154;
  tagRECT local_150;
  tagSIZE local_140;
  int local_138;
  tagRECT local_134;
  CHAR local_124 [100];
  HDC local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  LONG local_ac;
  uint32_t local_a8;
  tagRECT local_a4;
  tagRECT local_94;
  HDC local_84;
  tagRECT local_80;
  uint32_t local_70;
  int local_6c;
  uint32_t local_68;
  int local_64;
  tagRECT local_60;
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t local_48;
  LONG local_44;
  int32_t *local_40;
  LONG local_3c;
  HWND local_38;
  int32_t local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  int target_idx;
  tagRECT player_idx;
  
  if (y < 0x15) {
    if (y == 0x14) {
      local_84 = hdc;
      FUN_004707a4(hdc);
      GetClientRect(hwnd,&local_80);
      FillRect(local_84,&local_80,DAT_00516ac8);
      return 1;
    }
    if (y == 0x10) {
LAB_00441443:
      local_3c = GetWindowLongA(hwnd,8);
      if (local_3c == 0) {
        FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
        EndDialog(hwnd,-1);
      }
      return 1;
    }
  }
  else if (y < 0xa2) {
    if (y == 0xa1) {
      if (hdc == (HDC)0xc8) {
        SendMessageA(hwnd,0x10,0,0);
        local_15c = 0;
      }
      else {
        local_15c = DefWindowProcA(hwnd,0xa1,(WPARAM)hdc,(LPARAM)arg_4);
      }
      SetWindowLongA(hwnd,0,local_15c);
      return 1;
    }
    if (y == 0x84) {
      local_154 = DefWindowProcA(hwnd,0x84,(WPARAM)hdc,(LPARAM)arg_4);
      if ((local_154 == 8) || (local_154 == 2)) {
        hdc_00 = GetDC((HWND)0x0);
        psizl = &local_140;
        c = _strlen((char *)((int)DAT_005169cc + 0x650));
        GetTextExtentPoint32A(hdc_00,(LPCSTR)((int)DAT_005169cc + 0x650),c,psizl);
        ReleaseDC((HWND)0x0,hdc_00);
        GetClientRect(hwnd,&local_150);
        MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_150,2);
        if (local_150.right - local_140.cx <= (int)((uint32_t)arg_4 & 0xffff)) {
          local_154 = 200;
        }
      }
      SetWindowLongA(hwnd,0,local_154);
      return 1;
    }
    if ((0x84 < y) && (y < 0x87)) {
      local_ac = GetWindowLongA(hwnd,8);
      GetWindowRect(hwnd,&local_94);
      OffsetRect(&local_94,-local_94.left,-local_94.top);
      if ((local_94.right != local_94.left) && (local_94.bottom != local_94.top)) {
        if (y == 0x85) {
          DefWindowProcA(hwnd,0x85,(WPARAM)hdc,(LPARAM)arg_4);
        }
        local_a8 = (uint32_t)(y != 0x85);
        local_c0 = GetWindowDC(hwnd);
        if (local_c0 != (HDC)0x0) {
          FUN_004707a4(local_c0);
          GetWindowRect(hwnd,&local_94);
          GetClientRect(hwnd,&local_134);
          MapWindowPoints(hwnd,(HWND)0x0,(LPPOINT)&local_134,2);
          OffsetRect(&local_134,-local_94.left,-local_94.top);
          OffsetRect(&local_94,-local_94.left,-local_94.top);
          GetWindowTextA(hwnd,local_124,100);
          local_138 = local_134.left - local_94.left;
          local_b4 = local_94.bottom - local_134.bottom;
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -1,local_b8);
          SelectObject(local_c0,DAT_00516998);
          local_b8 = 1;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,(local_94.right - local_138) + 1,local_b8);
            local_b8 = local_b8 + 1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_b4 + -1;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = 0;
          MoveToEx(local_c0,0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom + -1);
          SelectObject(local_c0,DAT_00516998);
          local_b0 = 1;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + 1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = local_134.left + -1;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b0 = local_94.right + -1;
          MoveToEx(local_c0,local_b0,0,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_94.bottom);
          SelectObject(local_c0,DAT_0051699c);
          local_b0 = local_94.right + -2;
          for (local_bc = 1; local_bc <= local_138 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,local_b0,1,(LPPOINT)0x0);
            LineTo(local_c0,local_b0,local_94.bottom + -1);
            local_b0 = local_b0 + -1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b0 = local_94.right - local_138;
          MoveToEx(local_c0,local_b0,local_b4 + -1,(LPPOINT)0x0);
          LineTo(local_c0,local_b0,local_134.bottom + 1);
          pvVar6 = GetStockObject(7);
          SelectObject(local_c0,pvVar6);
          local_b8 = local_94.bottom + -1;
          MoveToEx(local_c0,0,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right,local_b8);
          SelectObject(local_c0,DAT_0051699c);
          local_b8 = local_94.bottom + -2;
          for (local_bc = 1; local_bc <= local_b4 + -2; local_bc = local_bc + 1) {
            MoveToEx(local_c0,1,local_b8,(LPPOINT)0x0);
            LineTo(local_c0,local_94.right + -1,local_b8);
            local_b8 = local_b8 + -1;
          }
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_94.bottom - local_b4;
          MoveToEx(local_c0,local_138 + -1,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right + -2,local_b8);
          SelectObject(local_c0,DAT_00516acc);
          local_b8 = local_134.top + -1;
          MoveToEx(local_c0,local_134.left,local_b8,(LPPOINT)0x0);
          LineTo(local_c0,local_94.right - local_138,local_b8);
          SetRect(&local_a4,local_134.left,local_b4,local_94.right - local_138,local_134.top + -1);
          FillRect(local_c0,&local_a4,DAT_00516a8c);
          SetTextColor(local_c0,DAT_00516af0);
          SetBkMode(local_c0,1);
          local_a4.left = local_a4.left + 5;
          DrawTextA(local_c0,local_124,-1,&local_a4,0x24);
          if (local_ac == 0) {
            DrawTextA(local_c0,(LPCSTR)((int)DAT_005169cc + 0x650),-1,&local_a4,0x26);
          }
          ReleaseDC(hwnd,local_c0);
        }
        SetWindowLongA(hwnd,0,local_a8);
        return 1;
      }
      LVar5 = DefWindowProcA(hwnd,y,(WPARAM)hdc,(LPARAM)arg_4);
      return LVar5;
    }
  }
  else if (y < 0x111) {
    if (y == 0x110) {
      local_34 = 1;
      DAT_005169cc = arg_4;
      SetWindowLongA(hwnd,8,arg_4[0x193]);
      DAT_00516a98 = 0;
      FUN_004421e2((int *)&DAT_00516ac8,(int *)&DAT_00516998,(int *)&DAT_00516acc,
                   (int *)&DAT_0051699c,(int *)&DAT_00516a8c,&DAT_00516af0);
      SetWindowTextA(hwnd,(LPCSTR)*DAT_005169cc);
      local_30 = DAT_005169cc[0x191];
      DAT_005169a4 = (DAT_0061534c * 2) / 3;
      DAT_00516b04 = (DAT_0061898c * 2) / 3;
      DAT_00516978 = 8;
      DAT_00516968 = 8;
      local_2c = 6;
      if (local_30 % 6 == 1) {
        local_2c = 5;
      }
      target_idx = local_30 / local_2c;
      if (0 < local_30 % local_2c) {
        target_idx = target_idx + 1;
      }
      color_idx = 4;
      SetRect(&player_idx,0,0,(DAT_005169a4 + 8) * local_2c + 8,(DAT_00516b04 + 8) * target_idx + 8);
      uval_1 = GetWindowLongA(hwnd,-0x10);
      SetWindowLongA(hwnd,-0x10,uval_1 & 0xffdfffff);
      if (color_idx < target_idx) {
        uval_1 = GetWindowLongA(hwnd,-0x10);
        SetWindowLongA(hwnd,-0x10,uval_1 | 0x200000);
        SetScrollRange(hwnd,1,0,player_idx.bottom -
                                ((DAT_00516b04 + DAT_00516968) * color_idx + DAT_00516968),1);
        SetScrollPos(hwnd,1,0,1);
        player_idx.bottom = (DAT_00516b04 + DAT_00516968) * color_idx + player_idx.top + DAT_00516968;
        val_2 = GetSystemMetrics(2);
        player_idx.right = player_idx.right + val_2;
      }
      bMenu = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&player_idx,dwStyle,bMenu);
      uFlags = 4;
      val_2 = player_idx.bottom - player_idx.top;
      cx = player_idx.right - player_idx.left;
      val_3 = GetSystemMetrics(1);
      val_3 = (val_3 - (player_idx.bottom - player_idx.top)) / 2;
      val_4 = GetSystemMetrics(0);
      SetWindowPos(hwnd,(HWND)0x0,(val_4 - (player_idx.right - player_idx.left)) / 2,val_3,cx,val_2,
                   uFlags);
      loop_idx = DAT_00516978;
      local_24 = DAT_00516968;
      GetClientRect(hwnd,&player_idx);
      for (local_28 = 0; local_28 < (int)DAT_005169cc[0x191]; local_28 = local_28 + 1) {
        local_38 = CreateWindowExA(0,s_ShowListCard_004f7d20,s_List_Card_004f7d14,0x50000000,
                                   loop_idx,local_24,DAT_005169a4,DAT_00516b04,hwnd,
                                   (HMENU)(local_28 + 10),DAT_00664680,
                                   (LPVOID)DAT_005169cc[local_28 + 1]);
        if (DAT_005169cc[0x192] != 0) {
          SendMessageA(local_38,0x414,1,DAT_005169cc[local_28 + 0xc9]);
        }
        loop_idx = loop_idx + DAT_00516978 + DAT_005169a4;
        if (player_idx.right < loop_idx + DAT_005169a4) {
          local_24 = local_24 + DAT_00516b04 + DAT_00516968;
          loop_idx = DAT_00516978;
        }
      }
      SetFocus(hwnd);
      return 0;
    }
    if (y == 0x100) {
      if (hdc == (HDC)0x22) {
        SendMessageA(hwnd,0x115,3,0);
      }
      else if (hdc == (HDC)0x21) {
        SendMessageA(hwnd,0x115,2,0);
      }
      else if (hdc == (HDC)0x28) {
        SendMessageA(hwnd,0x115,1,0);
      }
      else if (hdc == (HDC)0x26) {
        SendMessageA(hwnd,0x115,0,0);
      }
      else if (hdc == (HDC)0x1b) {
        SendMessageA(hwnd,0x10,0,0);
      }
      return 1;
    }
  }
  else if (y < 0x116) {
    if (y == 0x115) {
      local_70 = GetScrollPos(hwnd,1);
      GetScrollRange(hwnd,1,(LPINT)&local_68,(LPINT)&local_50);
      GetClientRect(hwnd,&local_60);
      local_6c = DAT_00516b04 + DAT_00516968;
      local_64 = local_60.bottom - DAT_00516968;
      switch((uint32_t)hdc & 0xffff) {
      case 0:
        local_4c = local_70 - local_6c;
        break;
      case 1:
        local_4c = local_6c + local_70;
        break;
      case 2:
      case 4:
      case 5:
        local_4c = (uint32_t)hdc >> 0x10;
        break;
      case 3:
        local_4c = local_70 + local_64;
        break;
      default:
        local_4c = local_70;
      }
      if ((int)local_4c < (int)local_68) {
        local_4c = local_68;
      }
      if ((int)local_50 < (int)local_4c) {
        local_4c = local_50;
      }
      ScrollWindow(hwnd,0,-(local_4c - local_70),(RECT *)0x0,(RECT *)0x0);
      SetScrollPos(hwnd,1,local_4c,1);
      return 1;
    }
    if (y == 0x111) {
      local_48 = (uint32_t)hdc & 0xffff;
      local_40 = arg_4;
      local_44 = GetWindowLongA(hwnd,8);
      if ((local_48 == 2) || (local_48 == 1)) {
        if (local_44 == 0) {
          FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
          EndDialog(hwnd,-1);
        }
      }
      else if (local_40 != (int32_t *)0x0) {
        FUN_004422cf(DAT_00516ac8,DAT_00516998,DAT_00516acc,DAT_0051699c,DAT_00516a8c);
        EndDialog(hwnd,local_48 - 10);
      }
      return 1;
    }
  }
  else {
    if (y == 0x201) goto LAB_00441443;
    if ((0x30e < y) && (y < 0x312)) {
      LVar5 = FUN_00472b60(hwnd,y,(HWND)hdc,arg_4);
      return LVar5;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004421e2
 * Entry Point: 004421e2
 * Size: 237 bytes
 */


void FUN_004421e2(int *arg_1,int *arg_2,int *arg_3,int *arg_4,int *arg_5,int32_t *arg_6)

{
  HBRUSH pHVar1;
  HPEN pHVar2;
  HGDIOBJ buf_ptr_3;
  
  pHVar1 = CreateSolidBrush(0x10000c7);
  *arg_1 = (int)pHVar1;
  pHVar2 = CreatePen(0,0,0x1000086);
  *arg_2 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x100001d);
  *arg_3 = (int)pHVar2;
  pHVar2 = CreatePen(0,0,0x10000c9);
  *arg_4 = (int)pHVar2;
  pHVar1 = CreateSolidBrush(0x100000f);
  *arg_5 = (int)pHVar1;
  *arg_6 = 0x1000090;
  if (*arg_1 == 0) {
    buf_ptr_3 = GetStockObject(2);
    *arg_1 = (int)buf_ptr_3;
  }
  if (*arg_2 == 0) {
    buf_ptr_3 = GetStockObject(6);
    *arg_2 = (int)buf_ptr_3;
  }
  if (*arg_3 == 0) {
    buf_ptr_3 = GetStockObject(6);
    *arg_3 = (int)buf_ptr_3;
  }
  if (*arg_4 == 0) {
    buf_ptr_3 = GetStockObject(7);
    *arg_4 = (int)buf_ptr_3;
  }
  if (*arg_5 == 0) {
    buf_ptr_3 = GetStockObject(2);
    *arg_5 = (int)buf_ptr_3;
  }
  return;
}



/*
 * Decompiled function: FUN_004422cf
 * Entry Point: 004422cf
 * Size: 111 bytes
 */


void FUN_004422cf(HGDIOBJ arg_1,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4,HGDIOBJ arg_5)

{
  if (arg_1 != (HGDIOBJ)0x0) {
    DeleteObject(arg_1);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  if (arg_5 != (HGDIOBJ)0x0) {
    DeleteObject(arg_5);
  }
  return;
}



/*
 * Decompiled function: UI_WndProc_0044233e
 * Entry Point: 0044233e
 * Size: 1024 bytes
 */


LRESULT UI_WndProc_0044233e(HWND hwnd,uint32_t uMsg,WPARAM wParam,LONG *lParam)

{
  HWND pHVar1;
  uint32_t uval_2;
  HWND hWnd;
  HBRUSH hbr;
  HDC hdc;
  LRESULT LVar3;
  UINT Msg;
  tagPAINTSTRUCT local_60;
  tagRECT loop_idx;
  WPARAM card_idx;
  LONG *match_count;
  WPARAM slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,0);
      card_idx = GetWindowLongA(hwnd,8);
      match_count = (LONG *)GetWindowLongA(hwnd,4);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(hwnd,&loop_idx);
      hbr = GetStockObject(4);
      FillRect(DAT_0060157c,&loop_idx,hbr);
      if (DAT_0068f108 == slot_idx) {
        FUN_0042043e(DAT_0060157c,&loop_idx);
      }
      else {
        FUN_00423651(DAT_0060157c,&loop_idx.left,(int32_t *)(&DAT_00618ac0 + slot_idx * 0x98),0,0)
        ;
      }
      if (card_idx != 0) {
        FUN_00423e55(DAT_0060157c,&loop_idx.left,match_count);
      }
      hdc = BeginPaint(hwnd,&local_60);
      if (hdc != (HDC)0x0) {
        FUN_004707a4(hdc);
        BitBlt(hdc,0,0,loop_idx.right,loop_idx.bottom,DAT_0060157c,0,0,0xcc0020);
        EndPaint(hwnd,&local_60);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = *lParam;
      SetWindowLongA(hwnd,0,slot_idx);
      card_idx = 0;
      match_count = (LONG *)0x0;
      SetWindowLongA(hwnd,8,0);
      SetWindowLongA(hwnd,4,(LONG)match_count);
      return 0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      pHVar1 = GetParent(hwnd);
      SendMessageA(pHVar1,uMsg,wParam,(LPARAM)lParam);
      return 0;
    }
    if (uMsg == 0x87) {
      return 4;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        LVar3 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
        return LVar3;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          pHVar1 = hwnd;
          uval_2 = GetDlgCtrlID(hwnd);
          uval_2 = uval_2 & 0xffff | 0x10000;
          Msg = 0x111;
          hWnd = GetParent(hwnd);
          SendMessageA(hWnd,Msg,uval_2,(LPARAM)pHVar1);
          return 0;
        }
        if (uMsg != 0x204) goto LAB_00442673;
      }
      if ((((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) &&
         (slot_idx = GetWindowLongA(hwnd,0), DAT_00516a98 != hwnd)) {
        SendMessageA(DAT_006152e0,0x401,slot_idx,0);
        DAT_00516a98 = hwnd;
      }
      return 0;
    }
    if (uMsg == 0x414) {
      card_idx = wParam;
      match_count = lParam;
      SetWindowLongA(hwnd,8,wParam);
      SetWindowLongA(hwnd,4,(LONG)match_count);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (uMsg == 0x437) {
      slot_idx = GetWindowLongA(hwnd,0);
      if (DAT_00663e24 != 2) {
        SendMessageA(DAT_006152e0,0x401,slot_idx,0);
      }
      return 0;
    }
  }
LAB_00442673:
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,(LPARAM)lParam);
  return LVar3;
}



/*
 * Decompiled function: Mem_AllocOrFree_0044274a
 * Entry Point: 0044274a
 * Size: 19 bytes
 */


void Mem_AllocOrFree_0044274a(void)

{
  return;
}



/*
 * Decompiled function: FUN_00442839
 * Entry Point: 00442839
 * Size: 137 bytes
 */


void FUN_00442839(uint32_t arg_1,int card_slot,int event_type)

{
  BOOL BVar1;
  WPARAM WVar2;
  int *lParam;
  LPARAM lParam_00;
  int match_count;
  int slot_idx;
  
  match_count = arg_2;
  slot_idx = arg_3;
  BVar1 = IsWindowVisible(DAT_006152e0);
  if (BVar1 != 0) {
    if ((arg_2 == -1) || (arg_3 == -1)) {
      lParam_00 = 0;
      WVar2 = CardIDFromType(arg_1);
      SendMessageA(DAT_006152e0,0x401,WVar2,lParam_00);
    }
    else {
      lParam = &match_count;
      WVar2 = CardIDFromType(arg_1);
      SendMessageA(DAT_006152e0,0x401,WVar2,(LPARAM)lParam);
    }
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004428c2
 * Entry Point: 004428c2
 * Size: 16 bytes
 */


void Mem_AllocOrFree_004428c2(void)

{
  return;
}



/*
 * Decompiled function: FUN_004428d2
 * Entry Point: 004428d2
 * Size: 452 bytes
 */


INT_PTR FUN_004428d2(int player_id,int32_t arg_2,INT_PTR arg_3,char *str_4,char *str_5,char *str_6)

{
  bool flag_1;
  bool flag_2;
  bool flag_3;
  int32_t loop_idx;
  INT_PTR color_idx;
  uint32_t target_idx;
  char *player_idx;
  char *card_idx;
  char *match_count;
  
  if (arg_1 == 0) {
    loop_idx = arg_2;
    target_idx = (uint32_t)(arg_3 != -1);
    player_idx = str_4;
    card_idx = str_5;
    match_count = str_6;
    if ((str_4 == (char *)0x0) || (*str_4 == '\0')) {
      flag_1 = false;
    }
    else {
      flag_1 = true;
    }
    if ((str_5 == (char *)0x0) || (*str_5 == '\0')) {
      flag_2 = false;
    }
    else {
      flag_2 = true;
    }
    if ((str_6 == (char *)0x0) || (*str_6 == '\0')) {
      flag_3 = false;
    }
    else {
      flag_3 = true;
    }
    if (((flag_1) || (flag_2)) || (flag_3)) {
      if (arg_3 < 0) {
        arg_3 = 0;
      }
      if (2 < arg_3) {
        arg_3 = 2;
      }
      if ((arg_3 == 0) && (!flag_1)) {
        arg_3 = 1;
      }
      if ((arg_3 == 1) && (!flag_2)) {
        arg_3 = 2;
      }
      if ((arg_3 == 2) && (!flag_3)) {
        arg_3 = 0;
      }
      if ((arg_3 == 0) && (!flag_1)) {
        arg_3 = 1;
      }
      color_idx = arg_3;
      arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe4,DAT_00618990,UI_DialogProc_00442a9b,
                              (LPARAM)&loop_idx);
    }
  }
  return arg_3;
}



/*
 * Decompiled function: UI_DialogProc_00442a9b
 * Entry Point: 00442a9b
 * Size: 924 bytes
 */


HWND UI_DialogProc_00442a9b(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam)

{
  UINT UVar1;
  LONG LVar2;
  HWND pHVar3;
  int val_4;
  INT_PTR match_count;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HWND)0x0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x429,(LPCSTR)*lParam);
      if (lParam[2] == 0) {
        val_4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42a);
        ShowWindow(pHVar3,val_4);
      }
      if ((lParam[3] == 0) || (*(char *)lParam[3] == '\0')) {
        val_4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42d);
        ShowWindow(pHVar3,val_4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42d,(LPCSTR)lParam[3]);
      }
      if ((lParam[4] == 0) || (*(char *)lParam[4] == '\0')) {
        val_4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42c);
        ShowWindow(pHVar3,val_4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42c,(LPCSTR)lParam[4]);
      }
      if ((lParam[5] == 0) || (*(char *)lParam[5] == '\0')) {
        val_4 = 0;
        pHVar3 = GetDlgItem(hwnd,0x42b);
        ShowWindow(pHVar3,val_4);
      }
      else {
        SetDlgItemTextA(hwnd,0x42b,(LPCSTR)lParam[5]);
      }
      if (lParam[1] == 0) {
        CheckDlgButton(hwnd,0x42d,(uint32_t)(lParam[1] == 0));
      }
      else if (lParam[1] == 1) {
        CheckDlgButton(hwnd,0x42c,(uint32_t)(lParam[1] == 1));
      }
      else {
        CheckDlgButton(hwnd,0x42b,(uint32_t)(lParam[1] == 2));
      }
      pHVar3 = GetDlgItem(hwnd,1);
      SetFocus(pHVar3);
      return (HWND)0x0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 1) {
        UVar1 = IsDlgButtonChecked(hwnd,0x42d);
        if (UVar1 != 0) {
          match_count = 0;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42c);
        if (UVar1 != 0) {
          match_count = 1;
        }
        UVar1 = IsDlgButtonChecked(hwnd,0x42b);
        if (UVar1 != 0) {
          match_count = 2;
        }
        EndDialog(hwnd,match_count);
      }
      else if ((wParam & 0xffff) == 0x42a) {
        LVar2 = GetWindowLongA(hwnd,8);
        CheckDlgButton(hwnd,0x42d,(uint32_t)(LVar2 == 0));
        CheckDlgButton(hwnd,0x42c,(uint32_t)(LVar2 == 1));
        CheckDlgButton(hwnd,0x42b,(uint32_t)(LVar2 == 2));
        pHVar3 = GetDlgItem(hwnd,1);
        pHVar3 = SetFocus(pHVar3);
        return pHVar3;
      }
      return (HWND)0x1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    pHVar3 = (HWND)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
    return pHVar3;
  }
  return (HWND)0x0;
}



/*
 * Decompiled function: FUN_00442e3c
 * Entry Point: 00442e3c
 * Size: 87 bytes
 */


INT_PTR FUN_00442e3c(int player_id,int32_t arg_2,INT_PTR arg_3)

{
  int32_t card_idx;
  INT_PTR match_count;
  
  if (arg_1 == 0) {
    card_idx = arg_2;
    match_count = arg_3;
    arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xe5,DAT_00618990,UI_DialogProc_00442e98,
                            (LPARAM)&card_idx);
  }
  return arg_3;
}



/*
 * Decompiled function: UI_DialogProc_00442e98
 * Entry Point: 00442e98
 * Size: 355 bytes
 */


int32_t UI_DialogProc_00442e98(HWND hwnd,uint32_t uMsg,uint32_t wParam,int32_t *lParam)

{
  HWND pHVar1;
  int32_t uval_2;
  
  if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return 0;
    }
    if (uMsg == 0x110) {
      SetWindowLongA(hwnd,8,lParam[1]);
      SetDlgItemTextA(hwnd,0x42e,(LPCSTR)*lParam);
      if (lParam[1] == 1) {
        pHVar1 = GetDlgItem(hwnd,6);
        SetFocus(pHVar1);
      }
      else {
        pHVar1 = GetDlgItem(hwnd,7);
        SetFocus(pHVar1);
      }
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 6) {
        EndDialog(hwnd,1);
      }
      else if ((wParam & 0xffff) == 7) {
        EndDialog(hwnd,0);
      }
      return 1;
    }
  }
  else if ((0x30e < uMsg) && (uMsg < 0x312)) {
    uval_2 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
    return uval_2;
  }
  return 0;
}



/*
 * Decompiled function: FUN_00443000
 * Entry Point: 00443000
 * Size: 94 bytes
 */


INT_PTR FUN_00443000(int player_id,int32_t arg_2,INT_PTR arg_3)

{
  int32_t player_idx;
  INT_PTR card_idx;
  int32_t match_count;
  
  if (arg_1 == 0) {
    player_idx = arg_2;
    card_idx = arg_3;
    match_count = 0;
    arg_3 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdc,DAT_00618990,UI_DialogProc_00443063,
                            (LPARAM)&player_idx);
  }
  return arg_3;
}



/*
 * Decompiled function: UI_DialogProc_00443063
 * Entry Point: 00443063
 * Size: 1344 bytes
 */


HGDIOBJ UI_DialogProc_00443063(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  HDC hDC;
  HGDIOBJ buf_ptr_1;
  HWND pHVar2;
  int val_3;
  HBRUSH hbr;
  code *dwNewLong;
  tagRECT local_44;
  COLORREF local_34;
  HWND local_30;
  HWND local_2c;
  int local_28;
  HDC local_24;
  HWND loop_idx;
  HWND color_idx;
  UINT target_idx;
  UINT player_idx;
  int card_idx;
  uint32_t match_count;
  HWND slot_idx;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_30 = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_30[5].unused) {
        local_34 = DAT_00516ab8;
      }
      else {
        local_34 = DAT_00516988;
      }
      FUN_00471f45((int)local_30,DAT_00516980,DAT_00516a78,DAT_00516a00,local_34,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_44);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      val_3 = SaveDC(DAT_0060157c);
      hDC = DAT_0060157c;
      if (DAT_00516b0c == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(hDC,&local_44,hbr);
      }
      else {
        FUN_004709ae((int)DAT_0060157c,(int)&local_44,DAT_00516b0c);
      }
      RestoreDC(DAT_0060157c,val_3);
      GetClientRect(hwnd,&local_44);
      BitBlt(wParam,0,0,local_44.right,local_44.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_24 = wParam;
      FUN_004707a4(wParam);
      local_2c = lParam;
      local_28 = GetDlgCtrlID(lParam);
      SetBkMode(local_24,1);
      SetTextColor(local_24,DAT_00516aa0);
      buf_ptr_1 = GetStockObject(5);
      return buf_ptr_1;
    }
    if (uMsg == 0x110) {
      slot_idx = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Pic_Load_WinbkQuestn
                (&DAT_00516b0c,&DAT_00516aa0,(int *)&DAT_00516980,(int *)&DAT_00516a78,
                 (int *)&DAT_00516a00,&DAT_00516988,&DAT_00516ab8);
      SetDlgItemTextA(hwnd,0x41a,(LPCSTR)slot_idx->unused);
      if (slot_idx[2].unused == 0) {
        val_3 = 0;
        pHVar2 = GetDlgItem(hwnd,0x41b);
        ShowWindow(pHVar2,val_3);
      }
      SendMessageA(hwnd,0x401,1,0);
      SetDlgItemInt(hwnd,0x419,slot_idx[1].unused,0);
      dwNewLong = FUN_004435ad;
      val_3 = -4;
      pHVar2 = GetDlgItem(hwnd,0x419);
      DAT_006944c4 = SetWindowLongA(pHVar2,val_3,(LONG)dwNewLong);
      pHVar2 = GetDlgItem(hwnd,0x419);
      SetFocus(pHVar2);
      SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
      FUN_00472552(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      match_count = (uint32_t)wParam & 0xffff;
      if (match_count == 1) {
        player_idx = GetDlgItemInt(hwnd,0x419,&card_idx,0);
        if (card_idx == 0) {
          pHVar2 = GetDlgItem(hwnd,0x419);
          SetFocus(pHVar2);
          SendDlgItemMessageA(hwnd,0x419,0xb1,0,-1);
        }
        else {
          FUN_00443727((int)DAT_00516b0c,DAT_00516980,DAT_00516a78,DAT_00516a00);
          EndDialog(hwnd,player_idx);
        }
      }
      else if (match_count == 2) {
        FUN_00443727((int)DAT_00516b0c,DAT_00516980,DAT_00516a78,DAT_00516a00);
        EndDialog(hwnd,-1);
      }
      else if (match_count == 0x41b) {
        target_idx = GetWindowLongA(hwnd,8);
        SetDlgItemInt(hwnd,0x419,target_idx,0);
        pHVar2 = GetDlgItem(hwnd,0x419);
        SetFocus(pHVar2);
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      buf_ptr_1 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return buf_ptr_1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    color_idx = (HWND)wParam;
    loop_idx = lParam;
    pHVar2 = GetDlgItem(hwnd,2);
    if (pHVar2 == color_idx) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (color_idx != (HWND)0x0) {
      InvalidateRect(color_idx,(RECT *)0x0,1);
    }
    if (loop_idx != (HWND)0x0) {
      InvalidateRect(loop_idx,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: FUN_004435ad
 * Entry Point: 004435ad
 * Size: 148 bytes
 */


LRESULT FUN_004435ad(HWND hwnd,UINT y,uint32_t width,LPARAM arg_4)

{
  LRESULT LVar1;
  
  if (y == 0x102) {
    if (((width < 0x30) || (0x39 < width)) && (width != 8)) {
      LVar1 = 0;
    }
    else {
      LVar1 = CallWindowProcA(DAT_006944c4,hwnd,0x102,width,arg_4);
    }
  }
  else {
    LVar1 = CallWindowProcA(DAT_006944c4,hwnd,y,width,arg_4);
  }
  return LVar1;
}



/*
 * Decompiled function: Pic_Load_WinbkQuestn
 * Entry Point: 0044364b
 * Size: 220 bytes
 */


void Pic_Load_WinbkQuestn
               (int32_t *arg_1,int32_t *out_buffer,int *arg_3,int *arg_4,int *arg_5,
               int32_t *arg_6,int32_t *arg_7)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_QuestN_pic_004f7d30,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0x100009a;
  pHVar2 = CreateSolidBrush(0x100001c);
  *arg_3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x1000072);
  *arg_4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000ca);
  *arg_5 = (int)pHVar3;
  *arg_6 = 0x100009a;
  *arg_7 = 0x10000bf;
  if (*arg_3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_3 = (int)pvVar4;
  }
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_5 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_00443727
 * Entry Point: 00443727
 * Size: 93 bytes
 */


void FUN_00443727(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}



/*
 * Decompiled function: FUN_00443784
 * Entry Point: 00443784
 * Size: 698 bytes
 */


INT_PTR FUN_00443784(int player_id,int32_t arg_2,int32_t arg_3,int arg_4,uint32_t arg_5)

{
  char cVar1;
  INT_PTR loop_idx;
  int32_t color_idx;
  int target_idx;
  uint32_t player_idx;
  int32_t card_idx;
  uint32_t match_count;
  INT_PTR slot_idx;
  
  cVar1 = (arg_5 & 2) != 0;
  if ((arg_5 & 0x20) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 8) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 0x10) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 4) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if ((arg_5 & 1) != 0) {
    cVar1 = cVar1 + '\x01';
  }
  if (cVar1 == '\0') {
    loop_idx = -1;
  }
  else if (cVar1 == '\x01') {
    if ((arg_5 & 2) == 0) {
      if ((arg_5 & 0x20) == 0) {
        if ((arg_5 & 8) == 0) {
          if ((arg_5 & 0x10) == 0) {
            if ((arg_5 & 4) == 0) {
              loop_idx = slot_idx;
              if ((arg_5 & 1) != 0) {
                slot_idx = 0;
                loop_idx = slot_idx;
              }
            }
            else {
              slot_idx = 2;
              loop_idx = slot_idx;
            }
          }
          else {
            slot_idx = 4;
            loop_idx = slot_idx;
          }
        }
        else {
          slot_idx = 3;
          loop_idx = slot_idx;
        }
      }
      else {
        slot_idx = 5;
        loop_idx = slot_idx;
      }
    }
    else {
      slot_idx = 1;
      loop_idx = slot_idx;
    }
  }
  else {
    if ((((((arg_4 == 1) && ((arg_5 & 2) == 0)) || ((arg_4 == 5 && ((arg_5 & 0x20) == 0)))) ||
         ((arg_4 == 3 && ((arg_5 & 8) == 0)))) || ((arg_4 == 4 && ((arg_5 & 0x10) == 0)))) ||
       ((((arg_4 == 2 && ((arg_5 & 4) == 0)) || ((arg_4 == 0 && ((arg_5 & 1) == 0)))) ||
        ((arg_4 < 0 || (5 < arg_4)))))) {
      if ((arg_5 & 0x20) == 0) {
        if ((arg_5 & 4) == 0) {
          if ((arg_5 & 2) == 0) {
            if ((arg_5 & 0x10) == 0) {
              if ((arg_5 & 8) == 0) {
                if ((arg_5 & 1) != 0) {
                  arg_4 = 0;
                }
              }
              else {
                arg_4 = 3;
              }
            }
            else {
              arg_4 = 4;
            }
          }
          else {
            arg_4 = 1;
          }
        }
        else {
          arg_4 = 2;
        }
      }
      else {
        arg_4 = 5;
      }
    }
    loop_idx = arg_4;
    if (arg_1 == 0) {
      color_idx = arg_2;
      target_idx = arg_4;
      player_idx = (uint32_t)(arg_4 != -1);
      card_idx = arg_3;
      match_count = arg_5;
      loop_idx = DialogBoxParamA(DAT_00664680,(LPCSTR)0xde,DAT_00618990,UI_DialogProc_004b257c,
                                 (LPARAM)&color_idx);
      if (loop_idx == -1) {
        loop_idx = -1;
      }
      else if (loop_idx == -2) {
        loop_idx = -1;
      }
    }
  }
  return loop_idx;
}



/*
 * Decompiled function: UI_DialogProc_004b257c
 * Entry Point: 00443a43
 * Size: 3381 bytes
 */


HGDIOBJ UI_DialogProc_004b257c(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  HDC hDC;
  HGDIOBJ buf_ptr_1;
  int val_2;
  HBRUSH pHVar3;
  HWND pHVar4;
  BOOL BVar5;
  tagRECT *ptVar6;
  tagRECT local_48;
  COLORREF local_38;
  HWND local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  HWND local_24;
  HWND loop_idx;
  uint32_t color_idx;
  tagRECT target_idx;
  HWND slot_idx;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_34 = lParam;
      pHVar4 = GetFocus();
      if (pHVar4 == (HWND)local_34[5].unused) {
        local_38 = DAT_0051698c;
      }
      else {
        local_38 = DAT_00516b20;
      }
      FUN_00471f45((int)local_34,DAT_00516ad8,DAT_00516aac,DAT_00516a74,local_38,0);
      return (HGDIOBJ)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_48);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      val_2 = SaveDC(DAT_0060157c);
      hDC = DAT_0060157c;
      if (DAT_00516ad4 == (HANDLE)0x0) {
        pHVar3 = GetStockObject(2);
        FillRect(hDC,&local_48,pHVar3);
      }
      else {
        FUN_004709ae((int)DAT_0060157c,(int)&local_48,DAT_00516ad4);
      }
      FUN_00444a85(&local_48,hwnd,DAT_00516b18);
      if (DAT_00516a70 == (HANDLE)0x0) {
        pHVar3 = CreateSolidBrush(0x2908c52);
        FrameRect(hDC,&local_48,pHVar3);
        DeleteObject(pHVar3);
      }
      else {
        FUN_004709ae((int)hDC,(int)&local_48,DAT_00516a70);
      }
      pHVar4 = GetDlgItem(hwnd,0x422);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c4);
      }
      pHVar4 = GetDlgItem(hwnd,0x423);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b8);
      }
      pHVar4 = GetDlgItem(hwnd,0x424);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x420);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b4);
      }
      pHVar4 = GetDlgItem(hwnd,0x425);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169c0);
      }
      pHVar4 = GetDlgItem(hwnd,0x426);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169bc);
      }
      pHVar4 = GetDlgItem(hwnd,0x427);
      BVar5 = IsWindowVisible(pHVar4);
      if (BVar5 != 0) {
        ptVar6 = &local_48;
        pHVar4 = GetDlgItem(hwnd,0x421);
        GetWindowRect(pHVar4,ptVar6);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_48,2);
        FUN_00470c78(hDC,&local_48,DAT_005169b0);
      }
      RestoreDC(DAT_0060157c,val_2);
      GetClientRect(hwnd,&local_48);
      BitBlt(wParam,0,0,local_48.right,local_48.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_28 = wParam;
      FUN_004707a4(wParam);
      local_30 = lParam;
      local_2c = GetDlgCtrlID(lParam);
      SetBkMode(local_28,1);
      if (local_2c == 0x489) {
        SetTextColor(local_28,DAT_005169f4);
      }
      else {
        SetTextColor(local_28,DAT_00516b10);
      }
      buf_ptr_1 = GetStockObject(5);
      return buf_ptr_1;
    }
    if (uMsg == 0x110) {
      slot_idx = lParam;
      SetWindowLongA(hwnd,8,lParam[1].unused);
      Ai_CalcManaRequirement_004b32d1
                (&DAT_00516ad4,&DAT_005169f4,&DAT_00516a70,&DAT_005169b0,&DAT_00516b10,
                 (int *)&DAT_00516ad8,(int *)&DAT_00516aac,(int *)&DAT_00516a74,&DAT_00516b20,
                 &DAT_0051698c);
      SetDlgItemTextA(hwnd,0x489,(LPCSTR)slot_idx->unused);
      if (slot_idx[2].unused == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x428);
        ShowWindow(pHVar4,val_2);
      }
      pHVar4 = GetDlgItem(hwnd,1);
      SetFocus(pHVar4);
      SendMessageA(hwnd,0x401,1,0);
      DAT_00516b18 = slot_idx[1].unused;
      if (slot_idx[3].unused == 0) {
        SetDlgItemTextA(hwnd,0x424,s__Swamp_004f7d44);
        SetDlgItemTextA(hwnd,0x423,s__Island_004f7d4c);
        SetDlgItemTextA(hwnd,0x426,s__Forest_004f7d54);
        SetDlgItemTextA(hwnd,0x425,s__Mountain_004f7d5c);
        SetDlgItemTextA(hwnd,0x422,s__Plains_004f7d68);
        SetDlgItemTextA(hwnd,0x427,s_Generic___X__004f7d70);
      }
      if ((slot_idx[4].unused & 2) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x420);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x424);
        ShowWindow(pHVar4,val_2);
      }
      if ((slot_idx[4].unused & 4) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41e);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x423);
        ShowWindow(pHVar4,val_2);
      }
      if ((slot_idx[4].unused & 8) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41d);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x426);
        ShowWindow(pHVar4,val_2);
      }
      if ((slot_idx[4].unused & 0x10) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41f);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x425);
        ShowWindow(pHVar4,val_2);
      }
      if ((slot_idx[4].unused & 0x20) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x41c);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x422);
        ShowWindow(pHVar4,val_2);
      }
      if ((slot_idx[4].unused & 1) == 0) {
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x421);
        ShowWindow(pHVar4,val_2);
        val_2 = 0;
        pHVar4 = GetDlgItem(hwnd,0x427);
        ShowWindow(pHVar4,val_2);
      }
      FUN_00472552(hwnd);
      return (HGDIOBJ)0x0;
    }
    if (uMsg == 0x111) {
      color_idx = (uint32_t)wParam & 0xffff;
      if (color_idx < 0x41d) {
        if (color_idx == 0x41c) {
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 5;
          FUN_00444a85(&target_idx,hwnd,5);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
        }
        else if ((color_idx != 0) && (color_idx < 3)) {
          FUN_004449cf((int)DAT_00516ad4,(int)DAT_00516a70,0x5169b0,DAT_00516ad8,DAT_00516aac,
                       DAT_00516a74);
          if (color_idx == 1) {
            EndDialog(hwnd,DAT_00516b18);
          }
          else {
            EndDialog(hwnd,-2);
          }
        }
      }
      else {
        switch(color_idx) {
        case 0x41d:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 3;
          FUN_00444a85(&target_idx,hwnd,3);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41e:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 2;
          FUN_00444a85(&target_idx,hwnd,2);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x41f:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 4;
          FUN_00444a85(&target_idx,hwnd,4);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x420:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 1;
          FUN_00444a85(&target_idx,hwnd,1);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x421:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = 0;
          FUN_00444a85(&target_idx,hwnd,0);
          InvalidateRect(hwnd,&target_idx,0);
          if ((uint32_t)wParam >> 0x10 == 5) {
            pHVar4 = GetDlgItem(hwnd,1);
            SendMessageA(hwnd,0x111,0x10000,(LPARAM)pHVar4);
          }
          break;
        case 0x428:
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,1);
          DAT_00516b18 = GetWindowLongA(hwnd,8);
          FUN_00444a85(&target_idx,hwnd,DAT_00516b18);
          InvalidateRect(hwnd,&target_idx,0);
          pHVar4 = GetDlgItem(hwnd,1);
          SetFocus(pHVar4);
        }
      }
      return (HGDIOBJ)0x1;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      buf_ptr_1 = (HGDIOBJ)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return buf_ptr_1;
    }
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HGDIOBJ)0x0;
    }
  }
  else if (uMsg == 0x4c8) {
    loop_idx = (HWND)wParam;
    local_24 = lParam;
    pHVar4 = GetDlgItem(hwnd,2);
    if (pHVar4 == loop_idx) {
      SendMessageA(hwnd,0x401,2,0);
    }
    else {
      SendMessageA(hwnd,0x401,1,0);
    }
    if (loop_idx != (HWND)0x0) {
      InvalidateRect(loop_idx,(RECT *)0x0,1);
    }
    if (local_24 != (HWND)0x0) {
      InvalidateRect(local_24,(RECT *)0x0,1);
    }
    return (HGDIOBJ)0x0;
  }
  return (HGDIOBJ)0x0;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b32d1
 * Entry Point: 004447aa
 * Size: 549 bytes
 */


void Ai_CalcManaRequirement_004b32d1
               (int32_t *arg_1,int32_t *out_buffer,int32_t *arg_3,int32_t *arg_4,
               int32_t *arg_5,int *arg_6,int *arg_7,int *arg_8,int32_t *arg_9,
               int32_t *arg_10)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_QuestMana_pic_004f7d80,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0x1000031;
  _sprintf(local_10c,s__s_WINBK_QuestManaSelection_pic_004f7d98,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_3 = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_Black_pic_004f7db8,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  arg_4[1] = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_White_pic_004f7dd0,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  arg_4[5] = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_Green_pic_004f7de8,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  arg_4[3] = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_Blue_pic_004f7e00,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  arg_4[2] = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_Red_pic_004f7e18,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  arg_4[4] = uval_1;
  _sprintf(local_10c,s__s_QUESTMANA_Gray_pic_004f7e30,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_4 = uval_1;
  *arg_5 = 0x1000031;
  pHVar2 = CreateSolidBrush(0x10000c6);
  *arg_6 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000c2);
  *arg_7 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x10000c8);
  *arg_8 = (int)pHVar3;
  *arg_9 = 0x1000031;
  *arg_10 = 0x10000bf;
  if (*arg_6 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_6 = (int)pvVar4;
  }
  if (*arg_7 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_7 = (int)pvVar4;
  }
  if (*arg_8 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_8 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_004449cf
 * Entry Point: 004449cf
 * Size: 182 bytes
 */


void FUN_004449cf(int player_id,int card_slot,int event_type,HGDIOBJ arg_4,HGDIOBJ arg_5,HGDIOBJ arg_6)

{
  int32_t slot_idx;
  
  if (arg_1 != 0) {
    FUN_00471395((HANDLE)arg_1);
  }
  if (arg_2 != 0) {
    FUN_00471395((HANDLE)arg_2);
  }
  for (slot_idx = 0; slot_idx < 6; slot_idx = slot_idx + 1) {
    if (*(int *)(arg_3 + slot_idx * 4) != 0) {
      FUN_00471395(*(HANDLE *)(arg_3 + slot_idx * 4));
    }
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  if (arg_5 != (HGDIOBJ)0x0) {
    DeleteObject(arg_5);
  }
  if (arg_6 != (HGDIOBJ)0x0) {
    DeleteObject(arg_6);
  }
  return;
}



/*
 * Decompiled function: FUN_00444a85
 * Entry Point: 00444a85
 * Size: 451 bytes
 */


void FUN_00444a85(LPRECT arg_1,HWND hwnd,int event_type)

{
  HWND pHVar1;
  tagRECT *ptVar2;
  tagRECT local_24;
  tagRECT player_idx;
  
  if (arg_1 != (LPRECT)0x0) {
    if (arg_3 == 5) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41c);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x422);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 2) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41e);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x423);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 1) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x420);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x424);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 4) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41f);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x425);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 3) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41d);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x426);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 0) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x421);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &player_idx;
      pHVar1 = GetDlgItem(hwnd,0x427);
      GetWindowRect(pHVar1,ptVar2);
    }
    UnionRect(arg_1,&local_24,&player_idx);
    InflateRect(arg_1,0,10);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)arg_1,2);
  }
  return;
}



/*
 * Decompiled function: FUN_00444c48
 * Entry Point: 00444c48
 * Size: 193 bytes
 */


INT_PTR FUN_00444c48(int player_id,int32_t *arg_2,int32_t arg_3,int arg_4,uint32_t arg_5)

{
  INT_PTR IVar1;
  int32_t color_idx;
  int target_idx;
  uint32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  
  if (arg_1 == 0) {
    color_idx = arg_3;
    target_idx = arg_4;
    player_idx = arg_5;
    card_idx = *arg_2;
    match_count = arg_2[1];
    IVar1 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xea,DAT_00618990,UI_DialogProc_004b3847,
                            (LPARAM)&color_idx);
    if (IVar1 == -1) {
      IVar1 = -1;
    }
    else if (IVar1 == -2) {
      IVar1 = -1;
    }
  }
  else if (((arg_5 & 0xffff) == 0) && (arg_4 == 0)) {
    IVar1 = 0;
  }
  else {
    IVar1 = 1;
  }
  return IVar1;
}



/*
 * Decompiled function: UI_DialogProc_004b3847
 * Entry Point: 00444d18
 * Size: 2369 bytes
 */


HBRUSH UI_DialogProc_004b3847(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam)

{
  HBRUSH pHVar1;
  HWND pHVar2;
  int nCmdShow;
  BOOL BVar3;
  tagRECT *ptVar4;
  tagRECT local_58;
  HWND local_48;
  int local_44;
  tagRECT local_40;
  COLORREF local_30;
  HWND local_2c;
  HWND local_28;
  int local_24;
  HWND loop_idx;
  HWND target_idx;
  HWND player_idx;
  uint32_t card_idx;
  int32_t match_count;
  HWND slot_idx;
  
  if (uMsg < 0x2c) {
    if (uMsg == 0x2b) {
      local_2c = lParam;
      pHVar2 = GetFocus();
      if (pHVar2 == (HWND)local_2c[5].unused) {
        local_30 = DAT_00516b1c;
      }
      else if ((local_2c[4].unused & 2) == 0) {
        local_30 = DAT_005169fc;
      }
      else {
        local_30 = 0x10000c6;
      }
      FUN_00471f45((int)local_2c,DAT_00516aa8,DAT_005169ec,DAT_00516a90,local_30,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      local_48 = wParam;
      FUN_004707a4((HDC)wParam);
      GetClientRect(hwnd,&local_40);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      local_44 = SaveDC(DAT_0060157c);
      local_48 = (HWND)DAT_0060157c;
      if (DAT_005169e8 == (HANDLE)0x0) {
        pHVar1 = GetStockObject(2);
        FillRect((HDC)local_48,&local_40,pHVar1);
      }
      else {
        FUN_004709ae((int)DAT_0060157c,(int)&local_40,DAT_005169e8);
      }
      if (DAT_005169f0 != 0xffffffff) {
        ptVar4 = &local_40;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_40,2);
        FUN_004215c2((HDC)local_48,&local_40.left,(int)(&DAT_00618ac0 + DAT_005169f0 * 0x98),
                     DAT_005169e0,DAT_005169e4,0x11,DAT_00663e10);
      }
      RestoreDC(DAT_0060157c,local_44);
      local_48 = wParam;
      GetClientRect(hwnd,&local_40);
      BitBlt((HDC)local_48,0,0,local_40.right,local_40.bottom,DAT_0060157c,0,0,0xcc0020);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x136) {
    if (uMsg == 0x135) {
LAB_00445207:
      loop_idx = wParam;
      FUN_004707a4((HDC)wParam);
      local_28 = lParam;
      local_24 = GetDlgCtrlID(lParam);
      if ((local_24 != 0x498) && (local_24 != 0x499)) {
        pHVar2 = GetFocus();
        if (pHVar2 == local_28) {
          SetTextColor((HDC)loop_idx,DAT_00516b1c);
        }
        else {
          SetTextColor((HDC)loop_idx,DAT_00516af4);
        }
        SetBkMode((HDC)loop_idx,1);
        pHVar1 = GetStockObject(5);
        return pHVar1;
      }
      SetTextColor((HDC)loop_idx,DAT_00516af4);
      SetBkMode((HDC)loop_idx,1);
      return DAT_00516aa8;
    }
    if (uMsg == 0x110) {
      slot_idx = lParam;
      Pic_Load_WinbkChangetext
                (&DAT_005169e8,&DAT_00516af4,(int *)&DAT_00516aa8,(int *)&DAT_005169ec,
                 (int *)&DAT_00516a90,&DAT_005169fc,&DAT_00516b1c);
      SetWindowTextA(hwnd,(LPCSTR)slot_idx->unused);
      DAT_005169e0 = slot_idx[3].unused;
      DAT_005169e4 = slot_idx[4].unused;
      DAT_005169f0 = FUN_00447184(DAT_005169e0,DAT_005169e4);
      nCmdShow = 0;
      pHVar2 = GetDlgItem(hwnd,0x474);
      ShowWindow(pHVar2,nCmdShow);
      if (slot_idx[2].unused == 0) {
        SetDlgItemTextA(hwnd,0x431,s__Black_004f7e48);
        SetDlgItemTextA(hwnd,0x430,s_Bl_ue_004f7e50);
        SetDlgItemTextA(hwnd,0x433,s__Green_004f7e58);
        SetDlgItemTextA(hwnd,0x432,&DAT_004f7e60);
        SetDlgItemTextA(hwnd,0x42f,s__White_004f7e68);
        SetDlgItemTextA(hwnd,0x436,s__Black_004f7e70);
        SetDlgItemTextA(hwnd,0x435,s_Bl_ue_004f7e78);
        SetDlgItemTextA(hwnd,0x438,s__Green_004f7e80);
        SetDlgItemTextA(hwnd,0x437,&DAT_004f7e88);
        SetDlgItemTextA(hwnd,0x434,s__White_004f7e90);
      }
      CheckDlgButton(hwnd,0x42f,1);
      CheckRadioButton(hwnd,0x42f,0x433,0x42f);
      CheckDlgButton(hwnd,0x438,1);
      CheckRadioButton(hwnd,0x434,0x438,0x438);
      SetWindowLongA(hwnd,8,(uint32_t)(uint16_t)slot_idx[2].unused << 0x10 | 0x820);
      pHVar2 = GetDlgItem(hwnd,1);
      SetFocus(pHVar2);
      SendMessageA(hwnd,0x401,1,0);
      FUN_00472552(hwnd);
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x111) {
      card_idx = (uint32_t)wParam & 0xffff;
      match_count = GetWindowLongA(hwnd,8);
      if (card_idx == 1) {
        FUN_0044573a((int)DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
        EndDialog(hwnd,match_count);
      }
      else if (card_idx == 2) {
        FUN_0044573a((int)DAT_005169e8,DAT_00516aa8,DAT_005169ec,DAT_00516a90);
        EndDialog(hwnd,-2);
      }
      else {
        if (card_idx == 0x431) {
          match_count = match_count & 0xffffff02 | 2;
        }
        else if (card_idx == 0x42f) {
          match_count = match_count & 0xffffff20 | 0x20;
        }
        else if (card_idx == 0x433) {
          match_count = match_count & 0xffffff08 | 8;
        }
        else if (card_idx == 0x430) {
          match_count = match_count & 0xffffff04 | 4;
        }
        else if (card_idx == 0x432) {
          match_count = match_count & 0xffffff10 | 0x10;
        }
        else if (card_idx == 0x436) {
          match_count = match_count & 0xffff02ff | 0x200;
        }
        else if (card_idx == 0x434) {
          match_count = match_count & 0xffff20ff | 0x2000;
        }
        else if (card_idx == 0x438) {
          match_count = match_count & 0xffff08ff | 0x800;
        }
        else if (card_idx == 0x435) {
          match_count = match_count & 0xffff04ff | 0x400;
        }
        else if (card_idx == 0x437) {
          match_count = match_count & 0xffff10ff | 0x1000;
        }
        SetWindowLongA(hwnd,8,match_count);
        if ((((char)match_count == '\0') || (match_count._1_1_ == 0)) ||
           ((uint32_t)match_count._1_1_ == (match_count & 0xff))) {
          BVar3 = 0;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
        else {
          BVar3 = 1;
          pHVar2 = GetDlgItem(hwnd,1);
          EnableWindow(pHVar2,BVar3);
        }
      }
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x201) {
    if (uMsg == 0x200) {
LAB_004454c1:
      if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
        ptVar4 = &local_58;
        pHVar2 = GetDlgItem(hwnd,0x474);
        GetWindowRect(pHVar2,ptVar4);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_58,2);
        if ((DAT_005169f0 != 0xffffffff) &&
           (BVar3 = PtInRect(&local_58,
                             (POINT)(CONCAT44((uint32_t)lParam >> 0x10,lParam) & 0xffffffff0000ffff)),
           BVar3 != 0)) {
          SendMessageA(DAT_006152e0,0x401,DAT_005169f0,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x138) goto LAB_00445207;
  }
  else if (uMsg < 0x205) {
    if (uMsg == 0x204) goto LAB_004454c1;
    if (uMsg == 0x201) {
      SendMessageA(hwnd,0x112,0xf012,0);
      return (HBRUSH)0x0;
    }
  }
  else if (0x30e < uMsg) {
    if (uMsg < 0x312) {
      pHVar1 = (HBRUSH)FUN_00472b60(hwnd,uMsg,wParam,lParam);
      return pHVar1;
    }
    if (uMsg == 0x4c8) {
      player_idx = wParam;
      target_idx = lParam;
      pHVar2 = GetDlgItem(hwnd,2);
      if (pHVar2 == player_idx) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (player_idx != (HWND)0x0) {
        InvalidateRect(player_idx,(RECT *)0x0,1);
      }
      if (target_idx != (HWND)0x0) {
        InvalidateRect(target_idx,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}



/*
 * Decompiled function: Pic_Load_WinbkChangetext
 * Entry Point: 0044565e
 * Size: 220 bytes
 */


void Pic_Load_WinbkChangetext
               (int32_t *arg_1,int32_t *out_buffer,int *arg_3,int *arg_4,int *arg_5,
               int32_t *arg_6,int32_t *arg_7)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_ChangeText_pic_004f7e98,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0x1000098;
  pHVar2 = CreateSolidBrush(0x1000076);
  *arg_3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x10000b3);
  *arg_4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x100004e);
  *arg_5 = (int)pHVar3;
  *arg_6 = 0x1000098;
  *arg_7 = 0x10000bf;
  if (*arg_3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_3 = (int)pvVar4;
  }
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_5 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_0044573a
 * Entry Point: 0044573a
 * Size: 93 bytes
 */


void FUN_0044573a(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00445797
 * Entry Point: 00445797
 * Size: 11 bytes
 */


void Mem_AllocOrFree_00445797(void)

{
  return;
}



/*
 * Decompiled function: FUN_004457a2
 * Entry Point: 004457a2
 * Size: 1891 bytes
 */


uint32_t FUN_004457a2(void)

{
  int val_1;
  int val_2;
  uint32_t uval_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  int32_t uval_7;
  uint32_t uval_8;
  uint32_t uVar9;
  uint32_t uVar10;
  uint32_t uVar11;
  int card_idx;
  int match_count;
  uint32_t slot_idx;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  slot_idx = _memcmp(&DAT_00601620,&DAT_006826c0,0xb640);
  FID_conflict__memcpy(&DAT_00601620,&DAT_006826c0,0xb640);
  if ((DAT_00666408 != DAT_00615458) || (DAT_0061545c != DAT_0066640c)) {
    slot_idx = 1;
  }
  DAT_00615458 = DAT_00666408;
  DAT_0061545c = DAT_0066640c;
  if ((DAT_00681ea8 != DAT_00616a00) || (DAT_00681eac != DAT_00664a50)) {
    slot_idx = 1;
  }
  DAT_00616a00 = DAT_00681ea8;
  DAT_00664a50 = DAT_00681eac;
  if ((DAT_006668f0 != DAT_0060cc80) || (DAT_006668f4 != DAT_00664dac)) {
    slot_idx = 1;
  }
  DAT_0060cc80 = DAT_006668f0;
  DAT_00664dac = DAT_006668f4;
  uval_3 = _memcmp(&DAT_006152c0,&DAT_0068f2e0,0x1c);
  uval_4 = _memcmp(&DAT_0060cc90,&DAT_0068f300,0x1c);
  FID_conflict__memcpy(&DAT_006152c0,&DAT_0068f2e0,0x1c);
  FID_conflict__memcpy(&DAT_0060cc90,&DAT_0068f300,0x1c);
  uval_5 = _memcmp(&DAT_0060ccc0,&DAT_0068f370,2000);
  uval_6 = _memcmp(&DAT_00662e40,&DAT_0068fb40,2000);
  DAT_00664a54 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_0068f370 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_0068f370 + match_count * 4));
    (&DAT_0060ccc0)[DAT_00664a54] = uval_7;
    DAT_00664a54 = DAT_00664a54 + 1;
  }
  DAT_00664d94 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_0068fb40 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_0068fb40 + match_count * 4));
    (&DAT_00662e40)[DAT_00664d94] = uval_7;
    DAT_00664d94 = DAT_00664d94 + 1;
  }
  uval_8 = _memcmp(&DAT_00663e70,&DAT_0068dd10,2000);
  uVar9 = _memcmp(&DAT_00617980,&DAT_0068e4e0,2000);
  DAT_00664b68 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_0068dd10 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_0068dd10 + match_count * 4));
    (&DAT_00663e70)[DAT_00664b68] = uval_7;
    DAT_00664b68 = DAT_00664b68 + 1;
  }
  DAT_00618948 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_0068e4e0 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_0068e4e0 + match_count * 4));
    (&DAT_00617980)[DAT_00618948] = uval_7;
    DAT_00618948 = DAT_00618948 + 1;
  }
  uVar10 = _memcmp(&DAT_00618170,&DAT_006669f0,2000);
  uVar11 = _memcmp(&DAT_00663620,&DAT_006671c0,2000);
  slot_idx = slot_idx | uval_3 | uval_4 | uval_5 | uval_6 | uval_8 | uVar9 | uVar10 | uVar11;
  DAT_00618944 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_006669f0 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_006669f0 + match_count * 4));
    (&DAT_00618170)[DAT_00618944] = uval_7;
    DAT_00618944 = DAT_00618944 + 1;
  }
  DAT_00618980 = 0;
  for (match_count = 0; (match_count < 500 && (*(int *)(&DAT_006671c0 + match_count * 4) != -1));
      match_count = match_count + 1) {
    uval_7 = CardIDFromType(*(uint32_t *)(&DAT_006671c0 + match_count * 4));
    (&DAT_00663620)[DAT_00618980] = uval_7;
    DAT_00618980 = DAT_00618980 + 1;
  }
  DAT_00618984 = 0;
  for (match_count = 0; ((&DAT_0068efb0)[match_count * 2] != -1 && (match_count < 0x20)); match_count = match_count + 1)
  {
    if (*(int *)(&DAT_00666460 + match_count * 4) != 0) {
      val_1 = (&DAT_0068efb0)[match_count * 2];
      val_2 = *(int *)(&DAT_0068efb4 + match_count * 8);
      (&DAT_00615470)[DAT_00618984 * 0x2b] = val_1;
      (&DAT_00615474)[DAT_00618984 * 0x2b] = val_2;
      (&DAT_00615518)[DAT_00618984 * 0x2b] =
           (int)(char)(&DAT_006827b8)[val_2 * 0x120 + val_1 * 0x5b20];
      for (card_idx = 0; card_idx < (char)(&DAT_006827b8)[val_2 * 0x120 + val_1 * 0x5b20];
          card_idx = card_idx + 1) {
        *(int32_t *)(&DAT_00615478 + card_idx * 8 + DAT_00618984 * 0xac) =
             *(int32_t *)(&DAT_00682718 + val_2 * 0x120 + val_1 * 0x5b20 + card_idx * 8);
        *(int32_t *)(&DAT_0061547c + card_idx * 8 + DAT_00618984 * 0xac) =
             *(int32_t *)(&DAT_0068271c + val_2 * 0x120 + val_1 * 0x5b20 + card_idx * 8);
      }
      DAT_00618984 = DAT_00618984 + 1;
    }
  }
  DAT_006152dc = 0;
  for (match_count = 0; (match_count < 0x10 && ((&DAT_0068ed90)[match_count] != -1)); match_count = match_count + 1) {
    DAT_006152dc = DAT_006152dc + 1;
  }
  FID_conflict__memcpy(&DAT_00664640,&DAT_0068ed90,0x40);
  DAT_00664db4 = 0;
  for (match_count = 0; (match_count < 0x10 && ((&DAT_0068ed50)[match_count] != -1)); match_count = match_count + 1) {
    DAT_00664db4 = DAT_00664db4 + 1;
  }
  FID_conflict__memcpy(&DAT_00664d50,&DAT_0068ed50,0x40);
  for (match_count = 0; match_count < 0x26; match_count = match_count + 1) {
    if (*(int *)(&DAT_006667c0 + match_count * 4) != *(int *)(&DAT_00664690 + match_count * 4)) {
      slot_idx = slot_idx | 1;
    }
    if (*(int *)(&DAT_00666858 + match_count * 4) != *(int *)(&DAT_00617390 + match_count * 4)) {
      slot_idx = slot_idx | 1;
    }
    *(uint32_t *)(&DAT_00664690 + match_count * 4) = *(uint32_t *)(&DAT_006667c0 + match_count * 4) & 1;
    *(uint32_t *)(&DAT_00617390 + match_count * 4) = *(uint32_t *)(&DAT_00666858 + match_count * 4) & 1;
  }
  if (DAT_0068edd4 != DAT_005f76d8) {
    slot_idx = 1;
  }
  DAT_005f76d8 = DAT_0068edd4;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return slot_idx;
}



/*
 * Decompiled function: Ai_EvalAttackCandidate_004b4a3f
 * Entry Point: 00445f05
 * Size: 2404 bytes
 */


void Ai_EvalAttackCandidate_004b4a3f(int32_t arg1,uint32_t arg2)

{
  HBRUSH pHVar1;
  int val_2;
  BOOL BVar3;
  uint32_t uval_4;
  HWND local_50;
  HWND local_4c;
  int local_48;
  HWND local_44;
  HWND local_40;
  HWND local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  uint32_t target_idx;
  int player_idx;
  int card_idx;
  uint32_t match_count;
  WPARAM slot_idx;
  
  pHVar1 = GetStockObject(0);
  FUN_00471e86(s_CD_struct_004f7eb0,0xff0000,pHVar1);
  KillTimer(DAT_00618990,DAT_00663610);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (DAT_00601584 != DAT_0068f0f8) {
    DAT_00601584 = DAT_0068f0f8;
    InvalidateRect(DAT_006152ec,(RECT *)0x0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  card_idx = FUN_004457a2();
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
    for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
      val_2 = FUN_00447184(player_idx,local_24);
      if (val_2 == DAT_0068f108) {
        *(uint32_t *)(&DAT_0060162c + local_24 * 0x120 + player_idx * 0x5b20) =
             *(uint32_t *)(&DAT_0060162c + local_24 * 0x120 + player_idx * 0x5b20) & 0xfffffffd;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if ((arg2 == 0) || ((arg2 & 0x30) != 0)) {
    if (card_idx != 0) {
      for (player_idx = 0; player_idx < 2; player_idx = player_idx + 1) {
        for (local_24 = 0; local_24 < 0x50; local_24 = local_24 + 1) {
          local_30 = player_idx;
          local_2c = local_24;
          loop_idx = FUN_004471f7(player_idx,local_24);
          color_idx = FUN_00447114(player_idx,local_24);
          local_28 = FUN_00447184(player_idx,local_24);
          target_idx = FUN_00448124(player_idx,local_24);
          match_count = FUN_004472ad(player_idx,local_24);
          if (((color_idx == -1) || (((target_idx & 0x10000) != 0 && (DAT_00663e1c == 0)))) ||
             ((DAT_0068f104 == color_idx && (val_2 = FUN_00446ea2(player_idx,local_24), val_2 == 0))))
          {
            SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_006152e0,0x40b,(WPARAM)&local_30,0);
            BVar3 = IsWindowVisible(DAT_00618ab0);
            if ((BVar3 != 0) || (val_2 = FUN_00448af2(), val_2 != 0)) {
              SendMessageA(DAT_00618ab0,0x403,(WPARAM)&local_30,0);
              SendMessageA(DAT_00618ab0,0x402,(WPARAM)&local_30,0);
            }
          }
          else if (loop_idx == 2) {
            SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
            SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
          }
          else if (DAT_0068eee0 != color_idx) {
            if (loop_idx == 1) {
              SendMessageA(DAT_006152b0,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_00663df4,0x40b,(WPARAM)&local_30,0);
              if (((match_count & 0x10) == 0) ||
                 ((local_28 < DAT_00666720 &&
                  ((*(int *)(&DAT_00618ad4 + local_28 * 0x98) != 2 ||
                   (*(int *)(&DAT_00618ad8 + local_28 * 0x98) == 0xda)))))) {
                if (player_idx == 0) {
                  local_44 = DAT_00618988;
                  local_3c = DAT_00617378;
                }
                else {
                  local_44 = DAT_00617378;
                  local_3c = DAT_00618988;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
              }
              else {
                FUN_0044743d(&local_38,player_idx,local_24);
                while (((uval_4 = FUN_004472ad(local_38,local_34), (uval_4 & 0x10) != 0 &&
                        (local_28 = FUN_00447184(local_38,local_34), local_28 != -1)) &&
                       ((DAT_00666720 <= local_28 ||
                        ((*(int *)(&DAT_00618ad4 + local_28 * 0x98) == 2 &&
                         (*(int *)(&DAT_00618ad8 + local_28 * 0x98) != 0xda))))))) {
                  FUN_0044743d(&local_38,local_38,local_34);
                }
                if (local_38 == 0) {
                  local_44 = DAT_00618988;
                  local_3c = DAT_00617378;
                }
                else {
                  local_44 = DAT_00617378;
                  local_3c = DAT_00618988;
                }
                SendMessageA(local_44,0x40b,(WPARAM)&local_30,0);
                SendMessageA(local_3c,0x40a,(WPARAM)&local_30,0);
                val_2 = FUN_004994f8(DAT_00618ab0,&local_38,(int32_t *)0x0,&local_40,
                                     (int32_t *)0x0);
                if (val_2 != 0) {
                  SendMessageA(DAT_00618ab0,0x406,(WPARAM)&local_30,(LPARAM)local_40);
                  SendMessageA(DAT_00618ab0,0x410,(WPARAM)local_40,0);
                  slot_idx = 1;
                  val_2 = FUN_004b26c4(local_3c,&local_38,(int32_t *)0x0,&local_40);
                  if (((val_2 != 0) && (BVar3 = IsWindowVisible(local_40), BVar3 == 0)) &&
                     (val_2 = FUN_004b26c4(local_3c,&local_30,(int32_t *)0x0,&local_40),
                     val_2 != 0)) {
                    ShowWindow(local_40,0);
                  }
                }
              }
            }
            else if (loop_idx == 0) {
              SendMessageA(DAT_00617378,0x40b,(WPARAM)&local_30,0);
              SendMessageA(DAT_00618988,0x40b,(WPARAM)&local_30,0);
              if (player_idx == 0) {
                local_4c = DAT_00663df4;
              }
              else {
                local_4c = DAT_006152b0;
              }
              SendMessageA(local_4c,0x40b,(WPARAM)&local_30,0);
              if (player_idx == 0) {
                local_50 = DAT_006152b0;
              }
              else {
                local_50 = DAT_00663df4;
              }
              SendMessageA(local_50,0x40a,(WPARAM)&local_30,0);
            }
          }
        }
      }
    }
    SendMessageA(DAT_00617378,0x400,0,0);
    SendMessageA(DAT_00618988,0x400,0,0);
    pHVar1 = GetStockObject(1);
    FUN_00471e86(s_Align_Attack_Spell_004f7ebc,0xff0000,pHVar1);
    FUN_0044897a((int32_t *)0x0,&local_48);
    if ((local_48 < 0x15) || (0x1d < local_48)) {
      SendMessageA(DAT_00618ab0,0x40c,0,0);
    }
    else {
      SendMessageA(DAT_00618ab0,0x412,slot_idx,0);
    }
    SendMessageA(DAT_00663df0,0x412,0,0);
  }
  SendMessageA(DAT_00617378,0x412,0,0);
  SendMessageA(DAT_00618988,0x412,0,0);
  if ((arg2 == 0) || ((arg2 & 0x20) != 0)) {
    pHVar1 = GetStockObject(2);
    FUN_00471e86(s_Refresh_004f7ed0,0xff0000,pHVar1);
    SendMessageA(DAT_006152b0,0x432,0,0);
    SendMessageA(DAT_00663df4,0x432,0,0);
    SendMessageA(DAT_00617378,0x432,0,0);
    SendMessageA(DAT_00618988,0x432,0,0);
    BVar3 = IsWindowVisible(DAT_00618ab0);
    if (BVar3 != 0) {
      SendMessageA(DAT_00618ab0,0x432,0,0);
      UpdateWindow(DAT_00618ab0);
    }
    BVar3 = IsWindowVisible(DAT_00663df0);
    if (BVar3 != 0) {
      SendMessageA(DAT_00663df0,0x432,0,0);
      UpdateWindow(DAT_00663df0);
    }
    SendMessageA(DAT_006152e0,0x432,0,0);
  }
  SendMessageA(DAT_00618160,0x432,0,0);
  SendMessageA(DAT_00664c28,0x432,0,0);
  SendMessageA(DAT_00618950,0x432,0,0);
  SendMessageA(DAT_00664c34,0x432,0,0);
  SendMessageA(DAT_00663e68,0x432,0,0);
  SendMessageA(DAT_00664c04,0x432,0,0);
  SendMessageA(DAT_00618978,0x432,0,0);
  SendMessageA(DAT_0061737c,0x432,0,0);
  pHVar1 = GetStockObject(0);
  FUN_00471e86(&DAT_004f7ed8,0xff0000,pHVar1);
  UpdateWindow(DAT_00618990);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00446869
 * Entry Point: 00446869
 * Size: 37 bytes
 */


void Mem_AllocOrFree_00446869(void)

{
  return;
}



/*
 * Decompiled function: FUN_0044688e
 * Entry Point: 0044688e
 * Size: 39 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t FUN_0044688e(void)

{
  _DAT_006944c0 = GetTickCount();
  _DAT_0060d494 = 0;
  return 0;
}



/*
 * Decompiled function: FUN_004468b5
 * Entry Point: 004468b5
 * Size: 64 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint32_t FUN_004468b5(void)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  return ((DVar1 - _DAT_006944c0) - _DAT_0060d494) / 0x37;
}



/*
 * Decompiled function: Mem_AllocOrFree_004468f5
 * Entry Point: 004468f5
 * Size: 16 bytes
 */


void Mem_AllocOrFree_004468f5(void)

{
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00446905
 * Entry Point: 00446905
 * Size: 16 bytes
 */


void Mem_AllocOrFree_00446905(void)

{
  return;
}



/*
 * Decompiled function: Ai_Subsystem_004b544d
 * Entry Point: 00446915
 * Size: 180 bytes
 */


int32_t Ai_Subsystem_004b544d(void)

{
  LRESULT LVar1;
  int val_2;
  int match_count [2];
  
  if ((DAT_0068f0b0 == 0) && (LVar1 = SendMessageA(DAT_00618ab0,0x411,0,0), LVar1 != 0)) {
    if (DAT_006152b4 == 0) {
      do {
        val_2 = Action_ValidateTarget_0041e2a2
                          (0,0,1,0x200,2,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0x10,
                           s_Choose_defenders_004f7edc,2,match_count);
      } while (val_2 != 0);
    }
    SendMessageA(DAT_00618ab0,0x412,0,0);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004469c9
 * Entry Point: 004469c9
 * Size: 62 bytes
 */


void FUN_004469c9(uint8_t *arg_1)

{
  char *slot_idx;
  
  if (arg_1 == (uint8_t *)0x0) {
    slot_idx = &DAT_004f7ef0;
  }
  else {
    slot_idx = arg_1;
  }
  FUN_004b7b63(DAT_00664d90,slot_idx,0);
  return;
}



/*
 * Decompiled function: FUN_00446a07
 * Entry Point: 00446a07
 * Size: 527 bytes
 */


void FUN_00446a07(char *filepath)

{
  int val_1;
  int local_28;
  tagPOINT local_24;
  int color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  char *slot_idx;
  
  if (str_1 == (char *)0x0) {
    slot_idx = &DAT_004f7ef4;
  }
  else {
    slot_idx = str_1;
  }
  if (DAT_00663e24 != 0) {
    if (*slot_idx == '\0') {
      ShowWindow(DAT_0060cc6c,0);
      SetWindowTextA(DAT_0060cc6c,slot_idx);
    }
    else {
      card_idx = GetSystemMetrics(0);
      match_count = GetSystemMetrics(1);
      if (DAT_00663e04 == 0) {
        val_1 = GetSystemMetrics(1);
        if ((val_1 * 3) / 100 < 0x13) {
          local_28 = 0x12;
        }
        else {
          val_1 = GetSystemMetrics(1);
          local_28 = (val_1 * 3) / 100;
        }
        color_idx = FUN_00471cf1(DAT_0060cc6c,(int)slot_idx);
        color_idx = color_idx + local_28 * 2;
        player_idx = (card_idx - (card_idx * 0x14) / 100) - color_idx;
        target_idx = (match_count - local_28) / 2;
      }
      else {
        val_1 = GetSystemMetrics(1);
        if ((val_1 * 2) / 100 < 0xd) {
          local_28 = 0xc;
        }
        else {
          val_1 = GetSystemMetrics(1);
          local_28 = (val_1 * 2) / 100;
        }
        color_idx = FUN_00471cf1(DAT_0060cc6c,(int)slot_idx);
        color_idx = color_idx + local_28 * 2;
        GetCursorPos(&local_24);
        val_1 = GetSystemMetrics(0xe);
        local_24.y = local_24.y + val_1;
        if (card_idx < local_24.x + color_idx) {
          local_24.x = card_idx - color_idx;
        }
        if (match_count < local_24.y + local_28) {
          local_24.y = match_count - local_28;
        }
        player_idx = local_24.x;
        target_idx = local_24.y;
      }
      SetWindowPos(DAT_0060cc6c,(HWND)0x0,player_idx,target_idx,color_idx,local_28,4);
      SetWindowTextA(DAT_0060cc6c,slot_idx);
      ShowWindow(DAT_0060cc6c,5);
      BringWindowToTop(DAT_0060cc6c);
    }
  }
  return;
}



/*
 * Decompiled function: FUN_00446c16
 * Entry Point: 00446c16
 * Size: 252 bytes
 */


int FUN_00446c16(int player_id,int card_slot,int event_type,int arg_4,int32_t arg_5,int32_t arg_6)

{
  int val_1;
  INT_PTR IVar2;
  int loop_idx;
  int color_idx;
  int target_idx;
  int player_idx;
  int32_t card_idx;
  int32_t match_count;
  
  KillTimer(DAT_00618990,DAT_00663610);
  if (arg_4 == 0xff) {
    arg_4 = -1;
  }
  if ((arg_1 != -1) && (arg_2 != -1)) {
    val_1 = FUN_00447184(arg_1,arg_2);
    if (val_1 == -1) {
      FUN_004457a2();
    }
  }
  if ((arg_3 != -1) && (arg_4 != -1)) {
    val_1 = FUN_00447184(arg_3,arg_4);
    if (val_1 == -1) {
      FUN_004457a2();
    }
  }
  loop_idx = arg_1;
  color_idx = arg_2;
  target_idx = arg_3;
  player_idx = arg_4;
  card_idx = arg_5;
  match_count = arg_6;
  IVar2 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xdf,DAT_00618990,Palette_Subsystem_0049608e,
                          (LPARAM)&loop_idx);
  if (IVar2 == 0) {
    val_1 = -1;
  }
  else {
    val_1 = IVar2 + -1;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00446d17
 * Entry Point: 00446d17
 * Size: 139 bytes
 */


int32_t FUN_00446d17(void)

{
  if (DAT_0066aaf4 != 1) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    FID_conflict__memcpy(&DAT_006152c0,&DAT_0068f2e0,0x1c);
    FID_conflict__memcpy(&DAT_0060cc90,&DAT_0068f300,0x1c);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    SendMessageA(DAT_00618950,0x432,0,0);
    SendMessageA(DAT_00664c34,0x432,0,0);
  }
  return 0;
}



/*
 * Decompiled function: FUN_00446da2
 * Entry Point: 00446da2
 * Size: 64 bytes
 */


void FUN_00446da2(int player_id)

{
  int32_t slot_idx;
  
  if (arg_1 == 0) {
    slot_idx = DAT_00663e68;
  }
  else {
    slot_idx = DAT_00664c04;
  }
  SendMessageA(slot_idx,0x400,0,0);
  return;
}



/*
 * Decompiled function: FUN_00446de2
 * Entry Point: 00446de2
 * Size: 78 bytes
 */


int32_t FUN_00446de2(int arg1,int arg2)

{
  int32_t uval_1;
  
  if ((arg1 == 0) || (arg1 == 1)) {
    if ((arg2 < 0) || (0x50 < arg2)) {
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00446e30
 * Entry Point: 00446e30
 * Size: 114 bytes
 */


uint32_t FUN_00446e30(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(uint32_t *)(&DAT_00601658 + arg2 * 0x120 + arg1 * 0x5b20) & 0xff00;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00446ea2
 * Entry Point: 00446ea2
 * Size: 109 bytes
 */


int32_t FUN_00446ea2(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601644 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00446f0f
 * Entry Point: 00446f0f
 * Size: 114 bytes
 */


uint32_t FUN_00446f0f(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(uint32_t *)(&DAT_0060166c + arg1 * 0x5b20 + arg2 * 0x120) & 0xff;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00446f81
 * Entry Point: 00446f81
 * Size: 183 bytes
 */


void FUN_00446f81(int player_id,int card_slot,uint32_t *arg_3,uint32_t *arg_4,uint32_t *arg_5)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg_1,arg_2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_3 = (uint32_t)(uint8_t)(&DAT_0060166d)[arg_2 * 0x120 + arg_1 * 0x5b20];
    *arg_4 = (*(uint32_t *)(&DAT_0060166c + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xff0000) >> 0x10;
    *arg_5 = *(uint32_t *)(&DAT_0060166c + arg_2 * 0x120 + arg_1 * 0x5b20) >> 0x18;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}



/*
 * Decompiled function: FUN_00447038
 * Entry Point: 00447038
 * Size: 110 bytes
 */


int FUN_00447038(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)(char)(&DAT_0060163e)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004470a6
 * Entry Point: 004470a6
 * Size: 110 bytes
 */


int FUN_004470a6(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)*(short *)(&DAT_00601630 + arg1 * 0x5b20 + arg2 * 0x120);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00447114
 * Entry Point: 00447114
 * Size: 112 bytes
 */


int32_t FUN_00447114(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601624 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0xffffffff;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00447184
 * Entry Point: 00447184
 * Size: 110 bytes
 */


int32_t FUN_00447184(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    val_1 = FUN_00447114(arg1,arg2);
    if (val_1 == -1) {
      uval_2 = 0xffffffff;
    }
    else {
      uval_2 = *(int32_t *)(&DAT_004ff590 + val_1 * 0x34);
    }
  }
  else {
    uval_2 = 0xffffffff;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004471f7
 * Entry Point: 004471f7
 * Size: 182 bytes
 */


int32_t FUN_004471f7(int arg1,int arg2)

{
  int val_1;
  int32_t slot_idx;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 2) == 0) {
      if (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) == 0) {
        slot_idx = 0;
      }
      else {
        slot_idx = 2;
      }
    }
    else {
      slot_idx = 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004472ad
 * Entry Point: 004472ad
 * Size: 400 bytes
 */


uint8_t FUN_004472ad(int arg1,int arg2)

{
  int val_1;
  uint8_t flag_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    flag_2 = ((&DAT_0060162e)[arg2 * 0x120 + arg1 * 0x5b20] & 3) != 0;
    if ((((&DAT_0060162c)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) != 0) &&
       (((&DAT_004ff594)[*(int *)(&DAT_00601624 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x47) != 4
       )) {
      flag_2 = flag_2 | 2;
    }
    if (((&DAT_0060162c)[arg2 * 0x120 + arg1 * 0x5b20] & 4) != 0) {
      flag_2 = flag_2 | 4;
    }
    if ((&DAT_0060163e)[arg2 * 0x120 + arg1 * 0x5b20] != -1) {
      flag_2 = flag_2 | 8;
    }
    if (((&DAT_00601632)[arg2 * 0x120 + arg1 * 0x5b20] != -1) &&
       (*(int *)(&DAT_00601648 + arg2 * 0x120 + arg1 * 0x5b20) != -1)) {
      flag_2 = flag_2 | 0x10;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    flag_2 = 0;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_0044743d
 * Entry Point: 0044743d
 * Size: 175 bytes
 */


void FUN_0044743d(int *arg_1,int card_slot,int event_type)

{
  int val_1;
  
  if (arg_1 != (int *)0x0) {
    val_1 = FUN_00446de2(arg_2,arg_3);
    if (val_1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      *arg_1 = (int)(char)(&DAT_00601632)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_00601648 + arg_3 * 0x120 + arg_2 * 0x5b20);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      *arg_1 = -1;
      arg_1[1] = -1;
    }
  }
  return;
}



/*
 * Decompiled function: FUN_004474ec
 * Entry Point: 004474ec
 * Size: 280 bytes
 */


int32_t FUN_004474ec(int *arg_1,int card_slot,int event_type)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg_2,arg_3);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_00601633)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0060164c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uval_2 = *(int32_t *)(&DAT_00601664 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    if (arg_1 != (int *)0x0) {
      *arg_1 = (int)(char)(&DAT_00601633)[arg_3 * 0x120 + arg_2 * 0x5b20];
      arg_1[1] = *(int *)(&DAT_0060164c + arg_3 * 0x120 + arg_2 * 0x5b20);
    }
    uval_2 = 0xffffffff;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00447604
 * Entry Point: 00447604
 * Size: 108 bytes
 */


uint8_t FUN_00447604(int arg1,int arg2)

{
  uint8_t uval_1;
  int val_2;
  
  val_2 = FUN_00446de2(arg1,arg2);
  if (val_2 == 0) {
    val_2 = FUN_00447114(arg1,arg2);
    if (val_2 == -1) {
      uval_1 = 0;
    }
    else {
      uval_1 = (&DAT_004ff594)[val_2 * 0x34];
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00447675
 * Entry Point: 00447675
 * Size: 110 bytes
 */


int FUN_00447675(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)*(short *)(&DAT_00601634 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004476e3
 * Entry Point: 004476e3
 * Size: 110 bytes
 */


int FUN_004476e3(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)*(short *)(&DAT_00601636 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00447751
 * Entry Point: 00447751
 * Size: 206 bytes
 */


uint32_t FUN_00447751(int arg1,int arg2)

{
  int val_1;
  uint32_t slot_idx;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    slot_idx = *(uint32_t *)(&DAT_0060165c + arg1 * 0x5b20 + arg2 * 0x120);
    if ((((&DAT_0060165e)[arg1 * 0x5b20 + arg2 * 0x120] & 0x20) != 0) &&
       (((&DAT_0060162c)[arg1 * 0x5b20 + arg2 * 0x120] & 4) != 0)) {
      slot_idx = slot_idx | 0x40;
    }
    if (slot_idx == 0xffffffff) {
      slot_idx = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0044781f
 * Entry Point: 0044781f
 * Size: 110 bytes
 */


int FUN_0044781f(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)(char)(&DAT_0060163d)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_0044788d
 * Entry Point: 0044788d
 * Size: 110 bytes
 */


int FUN_0044788d(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)(char)(&DAT_0060163c)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_004478fb
 * Entry Point: 004478fb
 * Size: 109 bytes
 */


int32_t FUN_004478fb(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_0060162c + arg1 * 0x5b20 + arg2 * 0x120);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00447968
 * Entry Point: 00447968
 * Size: 109 bytes
 */


int32_t FUN_00447968(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601650 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004479d5
 * Entry Point: 004479d5
 * Size: 161 bytes
 */


void FUN_004479d5(int x,int y,int *width,int *height)

{
  int val_1;
  
  if (((width != (int *)0x0) && (height != (int *)0x0)) && (val_1 = FUN_00446de2(x,y), val_1 == 0))
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *width = (int)*(short *)(&DAT_00601638 + y * 0x120 + x * 0x5b20);
    *height = (int)*(short *)(&DAT_0060163a + y * 0x120 + x * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00447a76
 * Entry Point: 00447a76
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00447a76(void)

{
  return 0;
}



/*
 * Decompiled function: FUN_00447a88
 * Entry Point: 00447a88
 * Size: 100 bytes
 */


uint32_t FUN_00447a88(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  uint32_t slot_idx;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    uval_2 = FUN_004478fb(arg1,arg2);
    slot_idx = (uint32_t)((uval_2 & 0x1000) != 0);
  }
  else {
    slot_idx = 0xffffffff;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00447aec
 * Entry Point: 00447aec
 * Size: 115 bytes
 */


uint32_t FUN_00447aec(int arg1,int arg2)

{
  int val_1;
  uint32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    val_1 = FUN_00447114(arg1,arg2);
    if (val_1 == -1) {
      uval_2 = 0;
    }
    else {
      uval_2 = *(uint32_t *)(&DAT_004ff5a8 + val_1 * 0x34) & 0x1000;
    }
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00447b5f
 * Entry Point: 00447b5f
 * Size: 168 bytes
 */


bool FUN_00447b5f(int arg1,int arg2)

{
  int val_1;
  bool flag_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    val_1 = FUN_00447114(arg1,arg2);
    if (val_1 == -1) {
      flag_2 = false;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      flag_2 = ((&DAT_00601658)[arg1 * 0x5b20 + arg2 * 0x120] & 6) != 0;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_00447c07
 * Entry Point: 00447c07
 * Size: 109 bytes
 */


int32_t FUN_00447c07(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601674 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00447c74
 * Entry Point: 00447c74
 * Size: 132 bytes
 */


bool FUN_00447c74(int arg1,int arg2)

{
  int val_1;
  bool flag_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    flag_2 = ((&DAT_0060162e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x20) != 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_00447cf8
 * Entry Point: 00447cf8
 * Size: 132 bytes
 */


bool FUN_00447cf8(int arg1,int arg2)

{
  int val_1;
  bool flag_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    flag_2 = ((&DAT_0060162e)[arg2 * 0x120 + arg1 * 0x5b20] & 0x10) == 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    flag_2 = false;
  }
  return flag_2;
}



/*
 * Decompiled function: FUN_00447d7c
 * Entry Point: 00447d7c
 * Size: 263 bytes
 */


void FUN_00447d7c(int player_id,int card_slot,char *arg_3)

{
  int slot_idx;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (slot_idx = 1; slot_idx < 6; slot_idx = slot_idx + 1) {
    if (*(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + slot_idx) != '\0') {
      FUN_004718de(arg_3,(char *)(slot_idx * 10 + 0x6c1260),1,
                   &DAT_006c1220 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + slot_idx) * 10);
      FUN_004718de(arg_3,(char *)(slot_idx * 10 + 0x6c1320),1,
                   &DAT_006c1220 +
                   *(char *)(arg_1 * 0x5b20 + arg_2 * 0x120 + 0x601719 + slot_idx) * 10);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}



/*
 * Decompiled function: Ai_Subsystem_004b69ba
 * Entry Point: 00447e83
 * Size: 494 bytes
 */


void Ai_Subsystem_004b69ba(int player_id,int card_slot,char *arg_3)

{
  uint32_t local_30 [5];
  int color_idx;
  uint32_t target_idx [5];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  for (color_idx = 1; color_idx < 6; color_idx = color_idx + 1) {
    if (*(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + color_idx) != '\0') {
      FUN_004718de(arg_3,(char *)(color_idx * 10 + 0x6c12e0),1,
                   &DAT_006c1360 +
                   *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + color_idx) * 10);
      FUN_004718de(arg_3,(char *)(color_idx * 10 + 0x6c12a0),1,
                   &DAT_006c1360 +
                   *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + color_idx) * 10);
      FUN_004718de(arg_3,s_PLAINSs_004f7f00,1,s_PLAINS_004f7ef8);
      Mem_AllocOrFree_004d9630(local_30,(uint32_t *)(color_idx * 10 + 0x6c12e0));
      FUN_004d9640(local_30,(uint32_t *)&DAT_004f7f08);
      Mem_AllocOrFree_004d9630
                (target_idx,(uint32_t *)(&DAT_006c1360 +
                                  *(char *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x60171f + color_idx) *
                                  10));
      FUN_004d9640(target_idx,(uint32_t *)&DAT_004f7f10);
      FUN_004718de(arg_3,(char *)local_30,1,(char *)target_idx);
      Mem_AllocOrFree_004d9630(local_30,(uint32_t *)(color_idx * 10 + 0x6c12a0));
      FUN_004d9640(local_30,(uint32_t *)&DAT_004f7f18);
      FUN_004718de(arg_3,(char *)local_30,1,(char *)target_idx);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}



/*
 * Decompiled function: FUN_00448071
 * Entry Point: 00448071
 * Size: 179 bytes
 */


int FUN_00448071(int player_id,int card_slot,void *arg_3)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg_1,arg_2);
  if (val_1 == 0) {
    if (arg_3 == (void *)0x0) {
      val_1 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      val_1 = (int)(char)(&DAT_00601718)[arg_1 * 0x5b20 + arg_2 * 0x120];
      FID_conflict__memcpy(arg_3,(void *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x601678),0xa0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00448124
 * Entry Point: 00448124
 * Size: 109 bytes
 */


int32_t FUN_00448124(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601658 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00448191
 * Entry Point: 00448191
 * Size: 109 bytes
 */


int32_t FUN_00448191(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601728 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_004481fe
 * Entry Point: 004481fe
 * Size: 112 bytes
 */


int32_t FUN_004481fe(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601620 + arg1 * 0x5b20 + arg2 * 0x120);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0xffffffff;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_0044826e
 * Entry Point: 0044826e
 * Size: 150 bytes
 */


void FUN_0044826e(int32_t *arg_1,int card_slot,int event_type)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg_2,arg_3);
  if ((val_1 == 0) && (arg_1 != (int32_t *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_1 = *(int32_t *)(&DAT_00601710 + arg_3 * 0x120 + arg_2 * 0x5b20);
    arg_1[1] = *(int32_t *)(&DAT_00601714 + arg_3 * 0x120 + arg_2 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}



/*
 * Decompiled function: FUN_00448304
 * Entry Point: 00448304
 * Size: 112 bytes
 */


int32_t FUN_00448304(int arg1,int arg2)

{
  int val_1;
  int32_t uval_2;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_2 = *(int32_t *)(&DAT_00601620 + arg2 * 0x120 + arg1 * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    uval_2 = 0xffffffff;
  }
  return uval_2;
}



/*
 * Decompiled function: FUN_00448374
 * Entry Point: 00448374
 * Size: 110 bytes
 */


int FUN_00448374(int arg1,int arg2)

{
  int val_1;
  
  val_1 = FUN_00446de2(arg1,arg2);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    val_1 = (int)(char)(&DAT_00601640)[arg2 * 0x120 + arg1 * 0x5b20];
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_004483e2
 * Entry Point: 004483e2
 * Size: 48 bytes
 */


int32_t Mem_AllocOrFree_004483e2(int player_id)

{
  int32_t uval_1;
  
  if ((arg_1 == 0) || (arg_1 == 1)) {
    uval_1 = 0;
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00448412
 * Entry Point: 00448412
 * Size: 93 bytes
 */


void FUN_00448412(char *filepath)

{
  char *match_count;
  char *slot_idx;
  
  if (str_1 != (char *)0x0) {
    slot_idx = str_1;
  }
  for (match_count = &DAT_00664b90; (*match_count != '\0' && (*match_count != '-')); match_count = match_count + 1) {
    *slot_idx = *match_count;
    slot_idx = slot_idx + 1;
  }
  *slot_idx = '\0';
  return;
}



/*
 * Decompiled function: FUN_0044846f
 * Entry Point: 0044846f
 * Size: 102 bytes
 */


int32_t FUN_0044846f(int player_id)

{
  int val_1;
  int32_t slot_idx;
  
  val_1 = Mem_AllocOrFree_004483e2(arg_1);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 == 0) {
      slot_idx = DAT_00616a00;
    }
    else {
      slot_idx = DAT_00664a50;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004484d5
 * Entry Point: 004484d5
 * Size: 102 bytes
 */


int32_t FUN_004484d5(int player_id)

{
  int val_1;
  int32_t slot_idx;
  
  val_1 = Mem_AllocOrFree_004483e2(arg_1);
  if (val_1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    if (arg_1 == 0) {
      slot_idx = DAT_0060cc80;
    }
    else {
      slot_idx = DAT_00664dac;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  else {
    slot_idx = 0;
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0044853b
 * Entry Point: 0044853b
 * Size: 140 bytes
 */


int32_t FUN_0044853b(void *arg1,int arg2)

{
  int32_t uval_1;
  int val_2;
  
  if (arg1 == (void *)0x0) {
    uval_1 = 0;
  }
  else {
    val_2 = Mem_AllocOrFree_004483e2(arg2);
    if (val_2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        FID_conflict__memcpy(arg1,&DAT_006152c0,0x1c);
      }
      else {
        FID_conflict__memcpy(arg1,&DAT_0060cc90,0x1c);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_004485c7
 * Entry Point: 004485c7
 * Size: 140 bytes
 */


int32_t FUN_004485c7(void *arg_1,int card_slot,int event_type)

{
  int32_t uval_1;
  int val_2;
  
  if (arg_1 == (void *)0x0) {
    uval_1 = 0;
  }
  else {
    val_2 = FUN_00446de2(arg_2,arg_3);
    if (val_2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      FID_conflict__memcpy(arg_1,&DAT_00601620 + arg_2 * 0x5b20 + arg_3 * 0x120,0x120);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      uval_1 = 1;
    }
    else {
      uval_1 = 0;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00448653
 * Entry Point: 00448653
 * Size: 163 bytes
 */


int32_t FUN_00448653(void *arg1,int arg2)

{
  int val_1;
  int32_t slot_idx;
  
  if (arg1 == (void *)0x0) {
    slot_idx = 0;
  }
  else {
    val_1 = Mem_AllocOrFree_004483e2(arg2);
    if (val_1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        slot_idx = DAT_00664a54;
      }
      else {
        slot_idx = DAT_00664d94;
      }
      FID_conflict__memcpy(arg1,(void *)((int)&DAT_0060ccc0 + ((arg2 == 0) - 1 & 0x56180)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_004486f6
 * Entry Point: 004486f6
 * Size: 163 bytes
 */


int32_t FUN_004486f6(void *arg1,int arg2)

{
  int val_1;
  int32_t slot_idx;
  
  if (arg1 == (void *)0x0) {
    slot_idx = 0;
  }
  else {
    val_1 = Mem_AllocOrFree_004483e2(arg2);
    if (val_1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        slot_idx = DAT_00664b68;
      }
      else {
        slot_idx = DAT_00618948;
      }
      FID_conflict__memcpy(arg1,(void *)((int)&DAT_00663e70 + ((arg2 == 0) - 1 & 0xfffb3b10)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_00448799
 * Entry Point: 00448799
 * Size: 163 bytes
 */


int32_t FUN_00448799(void *arg1,int arg2)

{
  int val_1;
  int32_t slot_idx;
  
  if (arg1 == (void *)0x0) {
    slot_idx = 0;
  }
  else {
    val_1 = Mem_AllocOrFree_004483e2(arg2);
    if (val_1 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      if (arg2 == 0) {
        slot_idx = DAT_00618944;
      }
      else {
        slot_idx = DAT_00618980;
      }
      FID_conflict__memcpy(arg1,(void *)((int)&DAT_00618170 + ((arg2 == 0) - 1 & 0x4b4b0)),2000);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
    else {
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: FUN_0044883c
 * Entry Point: 0044883c
 * Size: 91 bytes
 */


int32_t FUN_0044883c(void *arg_1)

{
  int32_t uval_1;
  
  if (arg_1 == (void *)0x0) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    uval_1 = DAT_00618984;
    FID_conflict__memcpy(arg_1,&DAT_00615470,0x1580);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return uval_1;
}



/*
 * Decompiled function: FUN_00448897
 * Entry Point: 00448897
 * Size: 227 bytes
 */


void FUN_00448897(int x,int *y,int width,int *height)

{
  int32_t uval_1;
  int slot_idx;
  
  if ((((x != 0) && (y != (int *)0x0)) && (width != 0)) && (height != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *y = DAT_006152dc;
    for (slot_idx = 0; slot_idx < DAT_006152dc; slot_idx = slot_idx + 1) {
      uval_1 = CardIDFromType(*(uint32_t *)(&DAT_00664640 + slot_idx * 4));
      *(int32_t *)(x + slot_idx * 4) = uval_1;
    }
    *height = DAT_00664db4;
    for (slot_idx = 0; slot_idx < DAT_00664db4; slot_idx = slot_idx + 1) {
      uval_1 = CardIDFromType(*(uint32_t *)(&DAT_00664d50 + slot_idx * 4));
      *(int32_t *)(width + slot_idx * 4) = uval_1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}



/*
 * Decompiled function: FUN_0044897a
 * Entry Point: 0044897a
 * Size: 73 bytes
 */


void FUN_0044897a(int32_t *arg1,int32_t *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg1 != (int32_t *)0x0) {
    *arg1 = DAT_005f77e8;
  }
  if (arg2 != (int32_t *)0x0) {
    *arg2 = DAT_006152e4;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}



/*
 * Decompiled function: FUN_004489c3
 * Entry Point: 004489c3
 * Size: 117 bytes
 */


void FUN_004489c3(void *arg1,int arg2)

{
  int val_1;
  
  if ((arg1 != (void *)0x0) && (val_1 = Mem_AllocOrFree_004483e2(arg2), val_1 == 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    FID_conflict__memcpy(arg1,&DAT_00664690 + ((arg2 == 0) - 1 & 0xfffb2d00),0x98);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}



/*
 * Decompiled function: FUN_00448a38
 * Entry Point: 00448a38
 * Size: 53 bytes
 */


void FUN_00448a38(int32_t *arg_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg_1 != (int32_t *)0x0) {
    *arg_1 = DAT_00601584;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}



/*
 * Decompiled function: FUN_00448a6d
 * Entry Point: 00448a6d
 * Size: 52 bytes
 */


int32_t FUN_00448a6d(void)

{
  int32_t uval_1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  uval_1 = DAT_005f76d8;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return uval_1;
}



/*
 * Decompiled function: FUN_00448aa1
 * Entry Point: 00448aa1
 * Size: 81 bytes
 */


bool FUN_00448aa1(int32_t *arg_1)

{
  if (arg_1 != (int32_t *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *arg_1 = DAT_00615458;
    arg_1[1] = DAT_0061545c;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return arg_1 != (int32_t *)0x0;
}



/*
 * Decompiled function: FUN_00448af2
 * Entry Point: 00448af2
 * Size: 52 bytes
 */


int32_t FUN_00448af2(void)

{
  int32_t uval_1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  uval_1 = DAT_00617370;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return uval_1;
}



/*
 * Decompiled function: FUN_00448b26
 * Entry Point: 00448b26
 * Size: 73 bytes
 */


void FUN_00448b26(int32_t *arg1,int32_t *arg2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  if (arg1 != (int32_t *)0x0) {
    *arg1 = DAT_0060cc74;
  }
  if (arg2 != (int32_t *)0x0) {
    *arg2 = DAT_0060d490;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  return;
}



/*
 * Decompiled function: FUN_00448b6f
 * Entry Point: 00448b6f
 * Size: 423 bytes
 */


int FUN_00448b6f(void *arg_1,int y,int width,int height)

{
  int val_1;
  int local_8ac;
  uint32_t local_8a4 [50];
  int local_7dc [500];
  int match_count;
  int slot_idx;
  
  if ((((arg_1 == (void *)0x0) || (y == 0)) || (width == 0)) || (height == 0)) {
    local_8ac = 0;
  }
  else {
    FID_conflict__memcpy(local_7dc,arg_1,y << 2);
    match_count = 0;
    local_8ac = 0;
    while ((match_count == 0 && (local_8ac < height))) {
      do {
        if (local_8ac == 0) {
          Mem_AllocOrFree_004d9630(local_8a4,(uint32_t *)&DAT_006679f0);
        }
        else if (local_8ac == 1) {
          Mem_AllocOrFree_004d9630(local_8a4,(uint32_t *)&DAT_00667aea);
        }
        else {
          Mem_AllocOrFree_004d9630(local_8a4,(uint32_t *)&DAT_00667be4);
        }
        val_1 = Ai_EvaluateCreatureCast(local_7dc,0,y,local_8a4,0,&DAT_004f7f20);
        if (val_1 == -1) {
          match_count = 1;
        }
        else if (local_7dc[val_1] < 5) {
          slot_idx = 1;
          *(int *)(width + local_8ac * 4) = val_1;
          local_8ac = local_8ac + 1;
          local_7dc[val_1] = DAT_006764b4;
        }
        else {
          slot_idx = 0;
        }
      } while ((match_count == 0) && (slot_idx == 0));
    }
  }
  return local_8ac;
}



/*
 * Decompiled function: FUN_00448d16
 * Entry Point: 00448d16
 * Size: 74 bytes
 */


void FUN_00448d16(int32_t arg1,int32_t arg2)

{
  int32_t card_idx;
  int32_t match_count;
  
  if (DAT_0066aaf4 != 1) {
    card_idx = arg1;
    match_count = arg2;
    DialogBoxParamA(DAT_00664680,(LPCSTR)0xf3,DAT_00618990,Ai_CalcManaRequirement_004b7897,
                    (LPARAM)&card_idx);
  }
  return;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b7897
 * Entry Point: 00448d60
 * Size: 1177 bytes
 */


int32_t Ai_CalcManaRequirement_004b7897(HWND hwnd,uint32_t uMsg,HDC wParam,int32_t lParam)

{
  int32_t uval_1;
  HBRUSH hbr;
  HWND pHVar2;
  int val_3;
  tagRECT *ptVar4;
  char local_2b4 [200];
  HDC local_1ec;
  HGDIOBJ local_1e8;
  tagRECT local_1e4;
  uint32_t local_1d4 [50];
  char local_10c [264];
  
  if (uMsg < 0x101) {
    if (uMsg == 0x100) {
LAB_004490d7:
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x14) {
      local_1ec = wParam;
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_1e4);
      if (DAT_00516964 == (HANDLE)0x0) {
        hbr = GetStockObject(2);
        FillRect(local_1ec,&local_1e4,hbr);
      }
      else {
        FUN_004709ae((int)local_1ec,(int)&local_1e4,DAT_00516964);
      }
      local_1e8 = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x496,0x31,0,0);
      SelectObject(local_1ec,local_1e8);
      SetBkMode(local_1ec,1);
      SetTextColor(local_1ec,DAT_00516990);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x496);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      SetTextColor(local_1ec,DAT_00516aa4);
      DrawTextA(local_1ec,s_Mana_Burn__004f7f40,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00516990);
      DrawTextA(local_1ec,s_Mana_Burn__004f7f4c,-1,&local_1e4,1);
      ptVar4 = &local_1e4;
      pHVar2 = GetDlgItem(hwnd,0x484);
      GetWindowRect(pHVar2,ptVar4);
      MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_1e4,2);
      if (*DAT_00516b00 == 0) {
        Mem_AllocOrFree_004d9630(local_1d4,(uint32_t *)&DAT_004f7f58);
      }
      else {
        FUN_00448412((char *)local_1d4);
      }
      if (*DAT_00516b00 == 0) {
        _sprintf(local_2b4,s__s_lose__d_life_004f7f5c,local_1d4,DAT_00516b00[1]);
      }
      else {
        _sprintf(local_2b4,s__s_loses__d_life_004f7f6c,local_1d4,DAT_00516b00[1]);
      }
      SetTextColor(local_1ec,DAT_00516aa4);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      OffsetRect(&local_1e4,-2,-2);
      SetTextColor(local_1ec,DAT_00516990);
      DrawTextA(local_1ec,local_2b4,-1,&local_1e4,1);
      return 1;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
LAB_004490fb:
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
    if (uMsg == 0x110) {
      DAT_00516b00 = (int *)lParam;
      _sprintf(local_10c,s__s_WINBK_ManaBurn_pic_004f7f28,&DAT_006189a0);
      DAT_00516964 = (HANDLE)Pic_LoadKimPicture(local_10c);
      DAT_00516990 = 0x100009a;
      DAT_00516aa4 = 0x10000c9;
      val_3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x496);
      ShowWindow(pHVar2,val_3);
      val_3 = 0;
      pHVar2 = GetDlgItem(hwnd,0x484);
      ShowWindow(pHVar2,val_3);
      SetTimer(hwnd,1,3000,(TIMERPROC)0x0);
      return 1;
    }
    if (uMsg == 0x111) goto LAB_004490d7;
    if (uMsg == 0x113) {
      FUN_00471395(DAT_00516964);
      EndDialog(hwnd,0);
      return 1;
    }
  }
  else {
    if (uMsg == 0x204) goto LAB_004490fb;
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      uval_1 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return uval_1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004491fe
 * Entry Point: 004491fe
 * Size: 175 bytes
 */


int FUN_004491fe(uint32_t *arg_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t local_70 [25];
  int match_count;
  INT_PTR slot_idx;
  
  KillTimer(DAT_00618990,DAT_00663610);
  uval_1 = _rand();
  uval_2 = (int)uval_1 >> 0x1f;
  match_count = ((uval_1 ^ uval_2) - uval_2 & 1 ^ uval_2) - uval_2;
  if (DAT_0066aaf4 != 1) {
    Mem_AllocOrFree_004d9630(local_70,arg_1);
    slot_idx = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf0,DAT_00618990,UI_PlayCoinTossAvi,
                              (LPARAM)local_70);
    InvalidateRect(DAT_00617378,(RECT *)0x0,1);
    InvalidateRect(DAT_00618988,(RECT *)0x0,1);
    StopSnd(0x2f);
  }
  return match_count;
}



/*
 * Decompiled function: UI_PlayCoinTossAvi
 * Entry Point: 004492ad
 * Size: 1276 bytes
 */


HBRUSH UI_PlayCoinTossAvi(HWND hwnd,uint32_t uMsg,HDC wParam,HWND lParam)

{
  size_t c;
  int X;
  HWND hWnd;
  DWORD dwStyle;
  UINT_PTR UVar1;
  HBRUSH pHVar2;
  int Y;
  int nWidth;
  int nHeight;
  tagSIZE *psizl;
  BOOL BVar3;
  tagRECT local_148;
  HWND local_138;
  int local_134;
  HDC local_130;
  char local_12c [264];
  HDC local_24;
  HGDIOBJ loop_idx;
  tagRECT color_idx;
  tagSIZE match_count;
  
  if (uMsg < 0x11) {
    if (uMsg == 0x10) {
LAB_00449583:
      KillTimer(hwnd,2);
      SendMessageA(DAT_004f79b8,0x10,0,0);
      EndDialog(hwnd,0);
      return (HBRUSH)0x1;
    }
    if (uMsg == 2) {
      FUN_004497d2(DAT_005169a0);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x101) {
    if (uMsg == 0x100) {
      if (lParam == (HWND)0x20d) {
        KillTimer(hwnd,2);
        SendMessageA(DAT_004f79b8,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0x14) {
      FUN_004707a4(wParam);
      GetClientRect(hwnd,&local_148);
      FillRect(wParam,&local_148,DAT_005169a0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      DAT_00516ae8 = lParam;
      FUN_004497ae(&DAT_005169a0,&DAT_00516ae4);
      SetDlgItemTextA(hwnd,0x48a,(LPCSTR)DAT_00516ae8);
      loop_idx = (HGDIOBJ)SendDlgItemMessageA(hwnd,0x48a,0x31,0,0);
      local_24 = GetDC(hwnd);
      SelectObject(local_24,loop_idx);
      psizl = &match_count;
      c = _strlen((char *)DAT_00516ae8);
      GetTextExtentPoint32A(local_24,(LPCSTR)DAT_00516ae8,c,psizl);
      ReleaseDC(hwnd,local_24);
      GetClientRect(hwnd,&color_idx);
      nWidth = match_count.cx + match_count.cy;
      nHeight = match_count.cy + 5;
      BVar3 = 1;
      Y = 0x14;
      X = (color_idx.right - nWidth) / 2;
      match_count.cx = nWidth;
      match_count.cy = nHeight;
      hWnd = GetDlgItem(hwnd,0x48a);
      MoveWindow(hWnd,X,Y,nWidth,nHeight,BVar3);
      if (DAT_00516ae8[0x19].unused == 0) {
        _sprintf(local_12c,s__s_COINTOSS_Heads_AVI_004f7f98,&DAT_006189a0);
      }
      else {
        _sprintf(local_12c,s__s_COINTOSS_Tails_AVI_004f7f80,&DAT_006189a0);
      }
      DAT_004f79b8 = (HWND)MCIWndCreateA(hwnd,DAT_00664680,0x50000102,local_12c);
      GetWindowRect(DAT_004f79b8,&color_idx);
      BVar3 = 0;
      dwStyle = GetWindowLongA(hwnd,-0x10);
      AdjustWindowRect(&color_idx,dwStyle,BVar3);
      MoveWindow(hwnd,color_idx.left,color_idx.top,color_idx.right - color_idx.left,
                 color_idx.bottom - color_idx.top,1);
      UVar1 = SetTimer(hwnd,1,10,(TIMERPROC)0x0);
      if (UVar1 == 0) {
        PostMessageA(hwnd,0x113,1,0);
      }
      SetTimer(hwnd,2,15000,(TIMERPROC)0x0);
      SetFocus(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x102) goto LAB_00449583;
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_130 = wParam;
      FUN_004707a4(wParam);
      local_138 = lParam;
      local_134 = GetDlgCtrlID(lParam);
      SetBkMode(local_130,1);
      SetTextColor(local_130,DAT_00516ae4);
      return DAT_005169a0;
    }
    if (uMsg == 0x113) {
      KillTimer(hwnd,(UINT_PTR)wParam);
      if (wParam == (HDC)0x1) {
        SendMessageA(DAT_004f79b8,0x806,0,0);
        FUN_0048d00c(0x2f);
        SetFocus(hwnd);
      }
      else {
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg == 0x210) {
      if ((((uint32_t)wParam & 0xffff) == 0x201) || (((uint32_t)wParam & 0xffff) == 0x204)) {
        KillTimer(hwnd,2);
        SendMessageA(DAT_004f79b8,0x808,0,0);
        SendMessageA(DAT_004f79b8,0x10,0,0);
        EndDialog(hwnd,0);
      }
      return (HBRUSH)0x1;
    }
    if ((0x30e < uMsg) && (uMsg < 0x312)) {
      pHVar2 = (HBRUSH)FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return pHVar2;
    }
  }
  return (HBRUSH)0x0;
}



/*
 * Decompiled function: FUN_004497ae
 * Entry Point: 004497ae
 * Size: 36 bytes
 */


void FUN_004497ae(int32_t *arg1,int32_t *arg2)

{
  HBRUSH pHVar1;
  
  pHVar1 = CreateSolidBrush(0x100000d);
  *arg1 = pHVar1;
  *arg2 = 0x10000bf;
  return;
}



/*
 * Decompiled function: FUN_004497d2
 * Entry Point: 004497d2
 * Size: 31 bytes
 */


void FUN_004497d2(HGDIOBJ arg_1)

{
  if (arg_1 != (HGDIOBJ)0x0) {
    DeleteObject(arg_1);
  }
  return;
}



/*
 * Decompiled function: FUN_004497f1
 * Entry Point: 004497f1
 * Size: 234 bytes
 */


int32_t
FUN_004497f1(int player_id,int card_slot,int32_t arg_3,int32_t arg_4,int32_t *arg_5,
            int32_t *arg_6,int32_t *arg_7)

{
  int32_t uval_1;
  INT_PTR IVar2;
  int32_t loop_idx;
  int32_t color_idx;
  int32_t target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int32_t match_count;
  
  if (arg_1 == 1) {
    uval_1 = 0;
  }
  else if ((((arg_1 == -1) || (arg_2 == -1)) || (arg_5 == (int32_t *)0x0)) ||
          ((arg_6 == (int32_t *)0x0 || (arg_7 == (int32_t *)0x0)))) {
    uval_1 = 0;
  }
  else {
    loop_idx = arg_3;
    color_idx = arg_4;
    target_idx = *arg_5;
    player_idx = *arg_6;
    match_count = CardIDFromType(arg_2);
    IVar2 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xef,DAT_00618990,UI_DialogProc_004b8421,
                            (LPARAM)&loop_idx);
    if (IVar2 == -1) {
      uval_1 = 0;
    }
    else if (IVar2 == -2) {
      uval_1 = 0;
    }
    else {
      *arg_5 = target_idx;
      *arg_6 = player_idx;
      *arg_7 = card_idx;
      uval_1 = 1;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: UI_DialogProc_004b8421
 * Entry Point: 004498e5
 * Size: 2209 bytes
 */


HBRUSH UI_DialogProc_004b8421(HWND hwnd,uint32_t uMsg,HWND wParam,HWND lParam)

{
  POINT pt;
  uint32_t uval_1;
  UINT UVar2;
  int32_t uval_3;
  HBRUSH pHVar4;
  HDC hdc;
  HWND pHVar5;
  int nCmdShow;
  BOOL BVar6;
  tagRECT *ptVar7;
  tagPAINTSTRUCT local_118;
  tagRECT local_d8;
  uint32_t local_c8;
  uint32_t local_c4;
  tagRECT local_c0;
  HWND local_b0;
  tagRECT local_ac;
  COLORREF local_9c;
  HWND local_98;
  HWND local_94;
  int local_90;
  HWND local_8c;
  HWND local_84;
  HWND local_80;
  uint32_t local_7c;
  UINT local_78;
  UINT local_74;
  HWND local_70;
  char local_6c [100];
  UINT slot_idx;
  
  if (uMsg < 0x15) {
    if (uMsg == 0x14) {
      local_b0 = wParam;
      FUN_004707a4((HDC)wParam);
      GetClientRect(hwnd,&local_ac);
      if (DAT_00516ad0 == (HANDLE)0x0) {
        pHVar4 = GetStockObject(3);
        FillRect((HDC)local_b0,&local_ac,pHVar4);
      }
      else {
        FUN_004709ae((int)local_b0,(int)&local_ac,DAT_00516ad0);
      }
      return (HBRUSH)0x1;
    }
    if (uMsg == 0xf) {
      hdc = BeginPaint(hwnd,&local_118);
      if ((hdc != (HDC)0x0) && (FUN_004707a4(hdc), DAT_00516984 != 0xffffffff)) {
        ptVar7 = &local_d8;
        pHVar5 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar5,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_d8,2);
        Palette_Subsystem_0049c7c7
                  (hdc,&local_d8.left,(int32_t *)(&DAT_00618ac0 + DAT_00516984 * 0x98),0,0x11,0);
      }
      EndPaint(hwnd,&local_118);
      return (HBRUSH)0x0;
    }
  }
  else if (uMsg < 0x111) {
    if (uMsg == 0x110) {
      DAT_00516ac0 = lParam;
      DAT_00516984 = lParam[5].unused;
      nCmdShow = 0;
      pHVar5 = GetDlgItem(hwnd,0x475);
      ShowWindow(pHVar5,nCmdShow);
      _sprintf(local_6c,s__max__d__004f7fb0,DAT_00516ac0->unused);
      SetDlgItemTextA(hwnd,0x478,local_6c);
      _sprintf(local_6c,s__max__d__004f7fbc,DAT_00516ac0[1].unused);
      SetDlgItemTextA(hwnd,0x47b,local_6c);
      CardScript_Fireball
                (&DAT_00516ad0,&DAT_00516ae0,(int *)&DAT_00516960,(int *)&DAT_005169f8,
                 (int *)&DAT_00516ab4,&DAT_005169d0,&DAT_00516b14);
      SendDlgItemMessageA(hwnd,0x476,0x465,0,(uint32_t)(uint16_t)DAT_00516ac0->unused);
      SendDlgItemMessageA(hwnd,0x47a,0x465,0,(uint32_t)(uint16_t)DAT_00516ac0[1].unused);
      SendDlgItemMessageA(hwnd,0x476,0x467,0,(uint32_t)(uint16_t)DAT_00516ac0[2].unused);
      SendDlgItemMessageA(hwnd,0x47a,0x467,0,(uint32_t)(uint16_t)DAT_00516ac0[3].unused);
      slot_idx = FUN_0044a2c4(DAT_00516ac0[2].unused,DAT_00516ac0[3].unused);
      SetDlgItemInt(hwnd,0x47c,slot_idx,1);
      pHVar5 = GetDlgItem(hwnd,1);
      SetFocus(pHVar5);
      SendMessageA(hwnd,0x401,1,0);
      local_70 = GetDlgItem(hwnd,1);
      uval_1 = GetWindowLongA(local_70,-0x10);
      SetWindowLongA(local_70,-0x10,uval_1 | 0x800000);
      FUN_00472552(hwnd);
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x2b) {
      local_98 = lParam;
      pHVar5 = GetFocus();
      if (pHVar5 == (HWND)local_98[5].unused) {
        local_9c = DAT_00516b14;
      }
      else {
        local_9c = DAT_005169d0;
      }
      FUN_00471f45((int)local_98,DAT_00516960,DAT_005169f8,DAT_00516ab4,local_9c,0);
      return (HBRUSH)0x1;
    }
  }
  else if (uMsg < 0x139) {
    if (uMsg == 0x138) {
      local_8c = wParam;
      FUN_004707a4((HDC)wParam);
      local_94 = lParam;
      local_90 = GetDlgCtrlID(lParam);
      pHVar5 = GetFocus();
      if (pHVar5 == local_94) {
        SetTextColor((HDC)local_8c,DAT_00516b14);
      }
      else {
        SetTextColor((HDC)local_8c,DAT_00516ae0);
      }
      if (((local_90 != 0x47c) && (local_90 != 0x49a)) && (local_90 != 0x49b)) {
        SetBkMode((HDC)local_8c,1);
        pHVar4 = GetStockObject(5);
        return pHVar4;
      }
      SetBkMode((HDC)local_8c,1);
      return DAT_00516960;
    }
    if (uMsg == 0x111) {
      local_7c = (uint32_t)wParam & 0xffff;
      if (local_7c == 1) {
        UVar2 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        *(UINT *)((int)DAT_00516ac0 + 8) = UVar2;
        local_74 = *(int *)((int)DAT_00516ac0 + 8);
        UVar2 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        *(UINT *)((int)DAT_00516ac0 + 0xc) = UVar2;
        local_78 = *(int *)((int)DAT_00516ac0 + 0xc);
        uval_3 = FUN_0044a2c4(local_74,local_78);
        *(int32_t *)((int)DAT_00516ac0 + 0x10) = uval_3;
        FUN_0044a267((int)DAT_00516ad0,DAT_00516960,DAT_005169f8,DAT_00516ab4);
        EndDialog(hwnd,1);
      }
      else if (local_7c == 2) {
        FUN_0044a267((int)DAT_00516ad0,DAT_00516960,DAT_005169f8,DAT_00516ab4);
        EndDialog(hwnd,-2);
      }
      else if (((local_7c == 0x477) || (local_7c == 0x479)) && ((uint32_t)wParam >> 0x10 == 0x400)) {
        local_74 = GetDlgItemInt(hwnd,0x477,(BOOL *)0x0,0);
        local_78 = GetDlgItemInt(hwnd,0x479,(BOOL *)0x0,0);
        SetDlgItemInt(hwnd,0x49a,local_74 - (local_78 - 1),1);
        SetDlgItemInt(hwnd,0x49b,local_78 - 1,1);
        BVar6 = 1;
        UVar2 = FUN_0044a2c4(local_74,local_78);
        SetDlgItemInt(hwnd,0x47c,UVar2,BVar6);
      }
      return (HBRUSH)0x1;
    }
  }
  else {
    if (uMsg < 0x312) {
      if (0x30e < uMsg) {
        pHVar4 = (HBRUSH)FUN_00472b60(hwnd,uMsg,wParam,lParam);
        return pHVar4;
      }
      if (uMsg != 0x200) {
        if (uMsg == 0x201) {
          SendMessageA(hwnd,0x112,0xf012,0);
          return (HBRUSH)0x0;
        }
        if (uMsg != 0x204) {
          return (HBRUSH)0x0;
        }
      }
      local_c8 = (uint32_t)lParam & 0xffff;
      local_c4 = (uint32_t)lParam >> 0x10;
      if (((uMsg == 0x200) && (DAT_00663e24 != 2)) || ((uMsg == 0x204 && (DAT_00663e24 == 2)))) {
        ptVar7 = &local_c0;
        pHVar5 = GetDlgItem(hwnd,0x475);
        GetWindowRect(pHVar5,ptVar7);
        MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)&local_c0,2);
        if ((DAT_00516984 != 0xffffffff) &&
           (pt.y = local_c4, pt.x = local_c8, BVar6 = PtInRect(&local_c0,pt), BVar6 != 0)) {
          SendMessageA(DAT_006152e0,0x401,DAT_00516984,0);
        }
      }
      return (HBRUSH)0x0;
    }
    if (uMsg == 0x4c8) {
      local_80 = wParam;
      local_84 = lParam;
      pHVar5 = GetDlgItem(hwnd,2);
      if (pHVar5 == local_80) {
        SendMessageA(hwnd,0x401,2,0);
      }
      else {
        SendMessageA(hwnd,0x401,1,0);
      }
      if (local_80 != (HWND)0x0) {
        InvalidateRect(local_80,(RECT *)0x0,1);
      }
      if (local_84 != (HWND)0x0) {
        InvalidateRect(local_84,(RECT *)0x0,1);
      }
      return (HBRUSH)0x0;
    }
  }
  return (HBRUSH)0x0;
}



/*
 * Decompiled function: CardScript_Fireball
 * Entry Point: 0044a18b
 * Size: 220 bytes
 */


void CardScript_Fireball
               (int32_t *arg_1,int32_t *out_buffer,int *arg_3,int *arg_4,int *arg_5,
               int32_t *arg_6,int32_t *arg_7)

{
  int32_t uval_1;
  HBRUSH pHVar2;
  HPEN pHVar3;
  HGDIOBJ pvVar4;
  char local_10c [264];
  
  _sprintf(local_10c,s__s_WINBK_Fireball_pic_004f7fc8,&DAT_006189a0);
  uval_1 = Pic_LoadKimPicture(local_10c);
  *arg_1 = uval_1;
  *out_buffer = 0x10000b6;
  pHVar2 = CreateSolidBrush(0x10000e5);
  *arg_3 = (int)pHVar2;
  pHVar3 = CreatePen(0,0,0x1000025);
  *arg_4 = (int)pHVar3;
  pHVar3 = CreatePen(0,0,0x1000002);
  *arg_5 = (int)pHVar3;
  *arg_6 = 0x1000001;
  *arg_7 = 0x10000bf;
  if (*arg_3 == 0) {
    pvVar4 = GetStockObject(2);
    *arg_3 = (int)pvVar4;
  }
  if (*arg_4 == 0) {
    pvVar4 = GetStockObject(6);
    *arg_4 = (int)pvVar4;
  }
  if (*arg_5 == 0) {
    pvVar4 = GetStockObject(7);
    *arg_5 = (int)pvVar4;
  }
  return;
}



/*
 * Decompiled function: FUN_0044a267
 * Entry Point: 0044a267
 * Size: 93 bytes
 */


void FUN_0044a267(int x,HGDIOBJ arg_2,HGDIOBJ arg_3,HGDIOBJ arg_4)

{
  if (x != 0) {
    FUN_00471395((HANDLE)x);
  }
  if (arg_2 != (HGDIOBJ)0x0) {
    DeleteObject(arg_2);
  }
  if (arg_3 != (HGDIOBJ)0x0) {
    DeleteObject(arg_3);
  }
  if (arg_4 != (HGDIOBJ)0x0) {
    DeleteObject(arg_4);
  }
  return;
}



/*
 * Decompiled function: FUN_0044a2c4
 * Entry Point: 0044a2c4
 * Size: 80 bytes
 */


int FUN_0044a2c4(int arg1,int arg2)

{
  int32_t slot_idx;
  
  if ((arg1 == 0) || (arg2 == 0)) {
    slot_idx = 0;
  }
  else {
    slot_idx = (arg1 - (arg2 + -1)) / arg2;
    if (slot_idx < 1) {
      slot_idx = 0;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: Ai_Subsystem_004b8e4d
 * Entry Point: 0044a314
 * Size: 656 bytes
 */


uint8_t * Ai_Subsystem_004b8e4d(int arg1,int arg2)

{
  uint32_t arg_1;
  int val_1;
  uint32_t local_4c [13];
  int target_idx;
  int player_idx;
  uint32_t card_idx;
  uint8_t *match_count;
  int slot_idx;
  
  match_count = (uint8_t *)0x0;
  slot_idx = FUN_00450725(arg1,arg2);
  if (slot_idx != -1) {
    if (slot_idx == DAT_0068f0fc) {
      arg_1 = Mem_AllocOrFree_004506c7(arg1,arg2);
      slot_idx = CardIDFromType(arg_1);
    }
    card_idx = (uint32_t)*(uint16_t *)(&DAT_00682704 + arg2 * 0x120 + arg1 * 0x5b20);
    player_idx = (int)(char)(&DAT_006826d3)[arg2 * 0x120 + arg1 * 0x5b20];
    target_idx = *(int *)(&DAT_006826ec + arg2 * 0x120 + arg1 * 0x5b20);
    if (slot_idx == DAT_00666720) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00516a08,(uint32_t *)s_Damage_004f7fe0);
    }
    else if (slot_idx == DAT_00666450) {
      _sprintf(&DAT_00516a08,s_Hunting___s_004f7fe8,
               (&PTR_DAT_004f5500)[*(int *)(&DAT_006826e4 + arg2 * 0x120 + arg1 * 0x5b20)]);
    }
    else if (slot_idx == DAT_00666444) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00516a08,*(uint32_t **)(&DAT_005f7914 + card_idx * 0x14));
    }
    else if (slot_idx == DAT_0066aae8) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00516a08,*(uint32_t **)(&DAT_005f791c + card_idx * 0x14));
    }
    else {
      DAT_00516a08 = '\0';
    }
    if ((slot_idx == DAT_00666444) && (0 < *(int *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20))) {
      Mem_AllocOrFree_004d9630(local_4c,(uint32_t *)&DAT_00516a08);
      FUN_00426b51(&DAT_00516a08,(char *)local_4c,
                   *(int *)(&DAT_006826f0 + arg2 * 0x120 + arg1 * 0x5b20));
    }
    val_1 = FUN_00450725(player_idx,target_idx);
    if ((val_1 == 0x361) || (val_1 == 0x360)) {
      Mem_AllocOrFree_004d9630((uint32_t *)&DAT_00516a08,*(uint32_t **)(&DAT_005f7914 + val_1 * 0x14));
    }
    if (DAT_00516a08 == '\0') {
      match_count = *(uint8_t **)(&DAT_00618ac4 + slot_idx * 0x98);
    }
    else {
      match_count = &DAT_00516a08;
    }
  }
  return match_count;
}



/*
 * Decompiled function: FUN_0044a5a4
 * Entry Point: 0044a5a4
 * Size: 60 bytes
 */


void FUN_0044a5a4(int arg1,int arg2)

{
  uint32_t *arg2_00;
  
  arg2_00 = (uint32_t *)Ai_Subsystem_004b8e4d(arg1,arg2);
  if (arg2_00 != (uint32_t *)0x0) {
    FUN_004d9640((uint32_t *)&DAT_005f6810,arg2_00);
  }
  return;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b9120
 * Entry Point: 0044a5e0
 * Size: 238 bytes
 */


int32_t Ai_CalcManaRequirement_004b9120(LPCSTR str_1)

{
  ATOM AVar1;
  LOGFONTA *lplf;
  uint32_t local_138 [66];
  int32_t local_30;
  WNDCLASSA local_2c;
  
  local_30 = 1;
  local_2c.style = 0xb;
  local_2c.lpfnWndProc = Ai_CalcManaRequirement_004b9284;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  if (AVar1 == 0) {
    local_30 = 0;
  }
  DAT_00516b48 = CreatePopupMenu();
  Mem_AllocOrFree_004d9630(local_138,(uint32_t *)&DAT_006189a0);
  FUN_004d9640(local_138,(uint32_t *)s__WINBK_ManaPool_pic_004f7ff4);
  DAT_00516b50 = Pic_LoadKimPicture((char *)local_138);
  lplf = (LOGFONTA *)FUN_00472731(s_ManaPool_004f8008,0);
  DAT_00516b4c = CreateFontIndirectA(lplf);
  return local_30;
}



/*
 * Decompiled function: FUN_0044a6ce
 * Entry Point: 0044a6ce
 * Size: 118 bytes
 */


void FUN_0044a6ce(void)

{
  if (DAT_00516b48 != (HMENU)0x0) {
    DestroyMenu(DAT_00516b48);
  }
  DAT_00516b48 = (HMENU)0x0;
  if (DAT_00516b50 != (HANDLE)0x0) {
    FUN_00471395(DAT_00516b50);
  }
  DAT_00516b50 = (HANDLE)0x0;
  if (DAT_00516b4c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00516b4c);
  }
  DAT_00516b4c = (HGDIOBJ)0x0;
  return;
}



/*
 * Decompiled function: Ai_CalcManaRequirement_004b9284
 * Entry Point: 0044a744
 * Size: 5167 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT Ai_CalcManaRequirement_004b9284(HWND hwnd,uint32_t uMsg,uint32_t wParam,uint32_t lParam)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  POINT pt_09;
  POINT pt_10;
  POINT pt_11;
  POINT pt_12;
  POINT pt_13;
  bool flag_1;
  UINT dwMilliseconds;
  BOOL BVar2;
  int val_3;
  HBRUSH pHVar4;
  LRESULT LVar5;
  int local_508;
  tagPOINT local_500;
  char local_4f8 [100];
  tagRECT local_494;
  int local_484;
  int local_480;
  uint32_t local_47c [3];
  tagPOINT local_470;
  tagRECT local_468;
  int local_458 [4];
  int local_448;
  int local_444;
  int local_440;
  uint32_t local_43c [66];
  CHAR local_334 [8];
  int local_32c;
  COLORREF local_328 [7];
  HDC local_30c;
  tagPAINTSTRUCT local_308;
  int local_2c8;
  int local_2c4;
  tagRECT local_2c0;
  tagRECT local_2b0;
  COLORREF local_2a0;
  int local_29c [7];
  uint32_t local_280;
  uint32_t local_27c;
  tagMSG local_278;
  tagRECT local_25c;
  BOOL local_24c;
  int local_248;
  int local_244;
  int local_240;
  tagRECT local_23c;
  uint32_t local_22c;
  uint32_t local_228 [66];
  ULONG_PTR local_120;
  int local_11c;
  int local_118;
  int local_114;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  uint32_t local_100 [25];
  int local_9c;
  uint32_t local_98;
  uint32_t local_94;
  int local_90;
  uint32_t local_8c [3];
  uint32_t local_80;
  tagRECT local_7c;
  uint32_t local_6c [25];
  int *slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = (int *)GetWindowLongA(hwnd,0);
      FUN_0044853b(local_458,(uint32_t)(hwnd != DAT_00618950));
      if (((((*slot_idx != local_458[0]) || (slot_idx[1] != local_458[1])) ||
           (slot_idx[2] != local_458[2])) ||
          ((slot_idx[4] != local_448 || (slot_idx[3] != local_458[3])))) ||
         ((slot_idx[5] != local_444 || (slot_idx[6] != local_440)))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
      GetClientRect(hwnd,&local_2b0);
      local_30c = DAT_0060157c;
      local_2c8 = SaveDC(DAT_0060157c);
      if (DAT_00516b50 == (HANDLE)0x0) {
        Mem_AllocOrFree_004d9630(local_43c,(uint32_t *)&DAT_006189a0);
        FUN_004d9640(local_43c,(uint32_t *)s__WINBK_ManaPool_pic_004f8080);
        DAT_00516b50 = (HANDLE)Pic_LoadKimPicture((char *)local_43c);
      }
      if (DAT_00516b50 == (HANDLE)0x0) {
        pHVar4 = GetStockObject(1);
        FillRect(local_30c,&local_2b0,pHVar4);
      }
      else {
        FUN_004709ae((int)local_30c,(int)&local_2b0,DAT_00516b50);
      }
      SelectObject(local_30c,DAT_00516b4c);
      SetBkMode(local_30c,1);
      SetTextAlign(local_30c,6);
      local_32c = (local_2b0.right * 0x28) / 100;
      SetMapMode(local_30c,8);
      FUN_0044bb84(&local_2c0,hwnd,1);
      SetWindowExtEx(local_30c,local_2c0.right - local_2c0.left,0x28,(LPSIZE)0x0);
      SetViewportExtEx(local_30c,local_2c0.right - local_2c0.left,local_2c0.bottom - local_2c0.top,
                       (LPSIZE)0x0);
      local_2a0 = 0x10000c9;
      local_328[1] = 0x10000c8;
      local_328[2] = 0x100005d;
      local_328[3] = 0x1000026;
      local_328[4] = 0x100001e;
      local_328[5] = 0x10000bf;
      local_328[0] = 0x10000c5;
      local_328[6] = 0x10000d0;
      local_2c4 = 0;
      do {
        if (6 < local_2c4) {
          RestoreDC(DAT_0060157c,local_2c8);
          local_30c = BeginPaint(hwnd,&local_308);
          if (local_30c != (HDC)0x0) {
            FUN_004707a4(local_30c);
            GetClientRect(hwnd,&local_2b0);
            if (DAT_00601580 != 0) {
              pHVar4 = GetStockObject(0);
              FillRect(local_30c,&local_2b0,pHVar4);
              Sleep(200);
            }
            BitBlt(local_30c,0,0,local_2b0.right,local_2b0.bottom,DAT_0060157c,0,0,0xcc0020);
            EndPaint(hwnd,&local_308);
            *slot_idx = local_458[0];
            slot_idx[1] = local_458[1];
            slot_idx[2] = local_458[2];
            slot_idx[4] = local_448;
            slot_idx[3] = local_458[3];
            slot_idx[5] = local_444;
            slot_idx[6] = local_440;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00664b70);
          return 0;
        }
        wsprintfA(local_334,&DAT_004f8094,local_458[local_2c4]);
        FUN_0044bb84(&local_2c0,hwnd,local_2c4);
        DPtoLP(local_30c,(LPPOINT)&local_2c0,2);
        if (local_2c4 == 6) {
          BVar2 = IsRectEmpty(&local_2c0);
          if (BVar2 == 0) goto LAB_0044b32b;
        }
        else {
          local_2c0.left = local_2c0.left + local_32c;
LAB_0044b32b:
          SetTextColor(local_30c,local_2a0);
          val_3 = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left + 1,local_2c0.top + 1,local_334,val_3);
          SetTextColor(local_30c,local_328[local_2c4]);
          val_3 = lstrlenA(local_334);
          TextOutA(local_30c,local_2c0.left,local_2c0.top,local_334,val_3);
        }
        local_2c4 = local_2c4 + 1;
      } while( true );
    }
    if (uMsg == 1) {
      slot_idx = _malloc(0x1c);
      slot_idx[6] = 0;
      slot_idx[5] = slot_idx[6];
      slot_idx[3] = slot_idx[5];
      slot_idx[4] = slot_idx[3];
      slot_idx[2] = slot_idx[4];
      slot_idx[1] = slot_idx[2];
      *slot_idx = slot_idx[1];
      SetWindowLongA(hwnd,0,(LONG)slot_idx);
      if (slot_idx == (int32_t *)0x0) {
        return -1;
      }
      return 0;
    }
    if (uMsg == 2) {
      slot_idx = (int *)GetWindowLongA(hwnd,0);
      FUN_004db150(slot_idx);
      return 0;
    }
  }
  else if (uMsg < 0x21) {
    if (uMsg == 0x20) {
      LVar5 = UI_WndProc_00471df6(hwnd,0x20,wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x14) {
      return 1;
    }
  }
  else if (uMsg < 0x118) {
    if (uMsg == 0x117) {
      flag_1 = false;
      for (local_480 = 0; local_480 < 7; local_480 = local_480 + 1) {
        if ((&DAT_0068ece0)[local_480] != 0) {
          flag_1 = true;
        }
      }
      if ((((DAT_00618158 != 0) && (flag_1)) &&
          ((DAT_00664780 == 0xffffffff || (DAT_00664780 == DAT_006663fc)))) &&
         ((((DAT_00664784 == -1 || (DAT_00664784 == 0)) || (DAT_00664784 == 1)) &&
          ((((DAT_00664788 == -1 || (DAT_00664788 == 0)) || (DAT_00664788 == DAT_006764bc)) &&
           (((DAT_0066478c == 0xffffffff || (DAT_0066478c == DAT_006663fc)) &&
            ((DAT_00664790 == 0xffffffff || ((DAT_00664790 & 1) != 0)))))))))) {
        GetCursorPos(&local_500);
        MapWindowPoints((HWND)0x0,hwnd,&local_500,1);
        local_484 = -1;
        FUN_0044bb84(&local_494,hwnd,1);
        pt_07.y = local_500.y;
        pt_07.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_07);
        if (BVar2 != 0) {
          local_484 = 1;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)s_black_004f8098);
        }
        FUN_0044bb84(&local_494,hwnd,5);
        pt_08.y = local_500.y;
        pt_08.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_08);
        if (BVar2 != 0) {
          local_484 = 5;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)s_white_004f80a0);
        }
        FUN_0044bb84(&local_494,hwnd,2);
        pt_09.y = local_500.y;
        pt_09.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_09);
        if (BVar2 != 0) {
          local_484 = 2;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)&DAT_004f80a8);
        }
        FUN_0044bb84(&local_494,hwnd,3);
        pt_10.y = local_500.y;
        pt_10.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_10);
        if (BVar2 != 0) {
          local_484 = 3;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)s_green_004f80b0);
        }
        FUN_0044bb84(&local_494,hwnd,4);
        pt_11.y = local_500.y;
        pt_11.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_11);
        if (BVar2 != 0) {
          local_484 = 4;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)&DAT_004f80b8);
        }
        FUN_0044bb84(&local_494,hwnd,0);
        pt_12.y = local_500.y;
        pt_12.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_12);
        if (BVar2 != 0) {
          local_484 = 0;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)&DAT_004f80bc);
        }
        FUN_0044bb84(&local_494,hwnd,6);
        pt_13.y = local_500.y;
        pt_13.x = local_500.x;
        BVar2 = PtInRect(&local_494,pt_13);
        if (BVar2 != 0) {
          local_484 = 0;
          Mem_AllocOrFree_004d9630(local_47c,(uint32_t *)s_artifact_004f80c4);
        }
        if (local_484 != -1) {
          _sprintf(local_4f8,s_Spend_1_mana___s_004f80d0,local_47c);
          AppendMenuA(DAT_00516b48,0,local_484 + 0x65,local_4f8);
        }
      }
      val_3 = GetMenuItemCount(DAT_00516b48);
      if (0 < val_3) {
        AppendMenuA(DAT_00516b48,0x800,0,(LPCSTR)0x0);
      }
      AppendMenuA(DAT_00516b48,0,100,s_Help____004f80e4);
      return 0;
    }
    if (uMsg == 0x111) {
      if ((wParam & 0xffff) == 100) {
        local_120 = 0x7ea;
        Mem_AllocOrFree_004d9630(local_228,(uint32_t *)&DAT_005f76e0);
        FUN_004d9640(local_228,(uint32_t *)s__duel_hlp_004f8074);
        WinHelpA(DAT_00618990,(LPCSTR)local_228,1,local_120);
      }
      else {
        local_22c = wParam & 0xffff;
        if (100 < local_22c) {
          DAT_006663fc = (uint32_t)(hwnd != DAT_00618950);
          DAT_006764bc = local_22c - 0x65;
          DAT_0066643c = 0;
          _DAT_00516b38 = 0xfffffffd;
          _DAT_00516b3c = 0xffffffff;
          _DAT_00516b40 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516b38);
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x202) {
    if (uMsg == 0x201) {
      if (DAT_00618158 != 0) {
        dwMilliseconds = GetDoubleClickTime();
        Sleep(dwMilliseconds);
        local_24c = PeekMessageA(&local_278,hwnd,0x203,0x203,0);
        FUN_0044853b(local_29c,(uint32_t)(hwnd != DAT_00618950));
        GetClientRect(hwnd,&local_23c);
        local_280 = lParam & 0xffff;
        local_27c = lParam >> 0x10;
        local_248 = local_23c.bottom / 6;
        DAT_006663fc = (uint32_t)(hwnd != DAT_00618950);
        DAT_006764bc = -1;
        local_240 = local_248;
        for (local_244 = 0; local_244 < 7; local_244 = local_244 + 1) {
          FUN_0044bb84(&local_25c,hwnd,local_244);
          pt_06.y = local_27c;
          pt_06.x = local_280;
          BVar2 = PtInRect(&local_25c,pt_06);
          if ((BVar2 != 0) && (0 < local_29c[local_244])) {
            DAT_006764bc = local_244;
          }
        }
        if ((((DAT_006764bc != -1) && (DAT_00618158 != 0)) &&
            ((DAT_00664780 == 0xffffffff || (DAT_00664780 == DAT_006663fc)))) &&
           ((DAT_00664790 == 0xffffffff || ((DAT_00664790 & 1) != 0)))) {
          DAT_0066643c = local_24c;
          _DAT_00516b28 = 0xfffffffd;
          _DAT_00516b2c = 0xffffffff;
          _DAT_00516b30 = 0xffffffff;
          PostMessageA(DAT_00618990,0x464,0,0x516b28);
        }
      }
      return 0;
    }
    if (uMsg == 0x11f) {
      if ((wParam >> 0x10 == 0xffff) && (lParam == 0)) {
        local_508 = GetMenuItemCount(DAT_00516b48);
        while (local_508 != 0) {
          DeleteMenu(DAT_00516b48,0,0x400);
          local_508 = local_508 + -1;
        }
      }
      return 0;
    }
  }
  else if (uMsg < 0x312) {
    if (0x30e < uMsg) {
      LVar5 = FUN_00472b60(hwnd,uMsg,(HWND)wParam,lParam);
      return LVar5;
    }
    if (uMsg == 0x204) {
      local_470.x = lParam & 0xffff;
      local_470.y = lParam >> 0x10;
      ClientToScreen(hwnd,&local_470);
      SetRect(&local_468,local_470.x,local_470.y,local_470.x + 1,local_470.y + 1);
      TrackPopupMenu(DAT_00516b48,2,local_470.x,local_470.y,0,hwnd,&local_468);
      return 0;
    }
  }
  else {
    if (uMsg == 0x432) {
      slot_idx = (int *)GetWindowLongA(hwnd,0);
      FUN_0044853b(&local_11c,(uint32_t)(hwnd != DAT_00618950));
      if ((((*slot_idx != local_11c) || (slot_idx[1] != local_118)) || (slot_idx[2] != local_114)) ||
         (((slot_idx[4] != local_10c || (slot_idx[3] != local_110)) ||
          ((slot_idx[5] != local_108 || (slot_idx[6] != local_104)))))) {
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
    if (uMsg == 0x437) {
      local_98 = lParam & 0xffff;
      local_94 = lParam >> 0x10;
      local_9c = -2;
      FUN_0044bb84(&local_7c,hwnd,1);
      pt.y = local_94;
      pt.x = local_98;
      BVar2 = PtInRect(&local_7c,pt);
      if (BVar2 != 0) {
        local_9c = 1;
      }
      FUN_0044bb84(&local_7c,hwnd,5);
      pt_00.y = local_94;
      pt_00.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_00);
      if (BVar2 != 0) {
        local_9c = 5;
      }
      FUN_0044bb84(&local_7c,hwnd,2);
      pt_01.y = local_94;
      pt_01.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_01);
      if (BVar2 != 0) {
        local_9c = 2;
      }
      FUN_0044bb84(&local_7c,hwnd,3);
      pt_02.y = local_94;
      pt_02.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_02);
      if (BVar2 != 0) {
        local_9c = 3;
      }
      FUN_0044bb84(&local_7c,hwnd,4);
      pt_03.y = local_94;
      pt_03.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_03);
      if (BVar2 != 0) {
        local_9c = 4;
      }
      FUN_0044bb84(&local_7c,hwnd,0);
      pt_04.y = local_94;
      pt_04.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_04);
      if (BVar2 != 0) {
        local_9c = 0;
      }
      FUN_0044bb84(&local_7c,hwnd,6);
      pt_05.y = local_94;
      pt_05.x = local_98;
      BVar2 = PtInRect(&local_7c,pt_05);
      if (BVar2 != 0) {
        local_9c = 6;
      }
      local_80 = (uint32_t)(hwnd != DAT_00618950);
      if (local_80 == 0) {
        Mem_AllocOrFree_004d9630(local_6c,(uint32_t *)&DAT_004f8014);
      }
      else {
        FUN_00448412((char *)local_6c);
      }
      FUN_004d9640(local_6c,(uint32_t *)s_mana_pool_004f801c);
      if (local_9c == 1) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Black_004f8028);
      }
      else if (local_9c == 5) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_White_004f8030);
      }
      else if (local_9c == 2) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)&DAT_004f8038);
      }
      else if (local_9c == 3) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Green_004f8040);
      }
      else if (local_9c == 4) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)&DAT_004f8048);
      }
      else if (local_9c == 0) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)&DAT_004f804c);
      }
      else if (local_9c == 6) {
        Mem_AllocOrFree_004d9630(local_8c,(uint32_t *)s_Artifact_004f8054);
      }
      if (((local_9c == 0) || (local_9c == 1)) ||
         ((local_9c == 5 ||
          ((((local_9c == 3 || (local_9c == 4)) || (local_9c == 2)) || (local_9c == 6)))))) {
        _sprintf((char *)local_100,s__s__amount_of__s_004f8060,local_6c,local_8c);
        local_90 = 1;
      }
      else {
        local_90 = 0;
      }
      if (local_90 == 0) {
        return 0;
      }
      Mem_AllocOrFree_004d9630((uint32_t *)wParam,local_100);
      return local_90;
    }
  }
  LVar5 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar5;
}



/*
 * Decompiled function: FUN_0044bb84
 * Entry Point: 0044bb84
 * Size: 475 bytes
 */


void FUN_0044bb84(LPRECT arg_1,HWND hwnd,int event_type)

{
  uint8_t local_48 [24];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int loop_idx;
  int color_idx;
  tagRECT target_idx;
  int slot_idx;
  
  FUN_0044853b(local_48,(uint32_t)(hwnd != DAT_00618950));
  GetClientRect(hwnd,&target_idx);
  loop_idx = (target_idx.bottom * 5) / 100;
  local_28 = (target_idx.bottom * 0x91) / 1000;
  local_24 = (target_idx.bottom * 0x14) / 1000;
  if (arg_3 == 1) {
    local_2c = 0;
  }
  else if (arg_3 == 2) {
    local_2c = 1;
  }
  else if (arg_3 == 3) {
    local_2c = 2;
  }
  else if (arg_3 == 4) {
    local_2c = 3;
  }
  else if (arg_3 == 5) {
    local_2c = 4;
  }
  else if (arg_3 == 0) {
    local_2c = 5;
  }
  else if (arg_3 == 6) {
    local_2c = 5;
  }
  else {
    local_2c = -1;
  }
  if (local_2c == -1) {
    SetRect(arg_1,0,0,0,0);
  }
  else {
    slot_idx = (local_24 + local_28) * local_2c + loop_idx;
    color_idx = slot_idx + local_28;
    SetRect(arg_1,target_idx.left,slot_idx,target_idx.right,color_idx);
    if (local_30 == 0) {
      if (arg_3 == 6) {
        SetRect(arg_1,0,0,0,0);
      }
    }
    else if (arg_3 == 0) {
      arg_1->right = arg_1->right - (target_idx.right - target_idx.left) / 2;
    }
    else if (arg_3 == 6) {
      arg_1->left = arg_1->left + ((target_idx.right - target_idx.left) * 2) / 3;
    }
  }
  return;
}



/*
 * Decompiled function: UI_RegisterClass_0044bd60
 * Entry Point: 0044bd60
 * Size: 132 bytes
 */


bool UI_RegisterClass_0044bd60(LPCSTR str_1)

{
  ATOM AVar1;
  WNDCLASSA local_2c;
  
  local_2c.style = 3;
  local_2c.lpfnWndProc = UI_WndProc_0044bde4;
  local_2c.cbClsExtra = 0;
  local_2c.cbWndExtra = 4;
  local_2c.hInstance = DAT_00664680;
  local_2c.hIcon = (HICON)0x0;
  local_2c.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_2c.hbrBackground = (HBRUSH)0x6;
  local_2c.lpszMenuName = (LPCSTR)0x0;
  local_2c.lpszClassName = str_1;
  AVar1 = RegisterClassA(&local_2c);
  return AVar1 != 0;
}



/*
 * Decompiled function: UI_WndProc_0044bde4
 * Entry Point: 0044bde4
 * Size: 1003 bytes
 */


LRESULT UI_WndProc_0044bde4(HWND hwnd,uint32_t uMsg,WPARAM wParam,uint32_t lParam)

{
  POINT pt;
  BOOL BVar1;
  UINT UVar2;
  size_t c;
  LRESULT LVar3;
  char local_f8 [100];
  int local_94;
  HDC local_90;
  int local_8c;
  tagPAINTSTRUCT local_88;
  tagPALETTEENTRY local_48;
  HBRUSH local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  uint32_t local_28;
  uint32_t local_24;
  int loop_idx;
  tagRECT color_idx;
  int match_count;
  UINT slot_idx;
  
  if (uMsg < 0x10) {
    if (uMsg == 0xf) {
      slot_idx = GetWindowLongA(hwnd,DAT_004f80ec);
      local_90 = BeginPaint(hwnd,&local_88);
      if (local_90 != (HDC)0x0) {
        FUN_004707a4(local_90);
        GetClientRect(hwnd,&local_40);
        DAT_004f80f0 = ((local_40.right - local_40.left) + -0x100) / 2;
        DAT_004f80f4 = ((local_40.bottom - local_40.top) + -0x100) / 2;
        for (local_8c = 0; local_8c < 0x10; local_8c = local_8c + 1) {
          for (local_94 = 0; local_94 < 0x10; local_94 = local_94 + 1) {
            local_44 = CreateSolidBrush(local_8c * 0x10 + local_94 & 0xffffU | 0x1000000);
            SetRect(&local_40,local_94 << 4,local_8c << 4,(local_94 + 1) * 0x10,
                    (local_8c + 1) * 0x10);
            OffsetRect(&local_40,DAT_004f80f0,DAT_004f80f4);
            FillRect(local_90,&local_40,local_44);
            DeleteObject(local_44);
          }
        }
        UVar2 = GetPaletteEntries(DAT_005f76d0,slot_idx,1,&local_48);
        if (UVar2 == 0) {
          _sprintf(local_f8,s___3d__not_in_palette_004f8114,slot_idx);
        }
        else {
          _sprintf(local_f8,s___3d___3d__3d__3d_004f80f8,slot_idx,(uint32_t)local_48.peRed,
                   (uint32_t)local_48.peGreen,(uint32_t)local_48.peBlue);
        }
        c = _strlen(local_f8);
        TextOutA(local_90,0,0,local_f8,c);
        EndPaint(hwnd,&local_88);
      }
      return 0;
    }
    if (uMsg == 1) {
      slot_idx = 0;
      SetWindowLongA(hwnd,DAT_004f80ec,0);
      return 0;
    }
  }
  else {
    if (uMsg == 0x10) {
      ShowWindow(hwnd,0);
      return 0;
    }
    if (uMsg == 0x200) {
      slot_idx = GetWindowLongA(hwnd,DAT_004f80ec);
      local_28 = lParam & 0xffff;
      local_24 = lParam >> 0x10;
      match_count = 0;
      loop_idx = 0;
      while ((loop_idx < 0x10 && (match_count == 0))) {
        local_2c = 0;
        while ((local_2c < 0x10 && (match_count == 0))) {
          SetRect(&color_idx,local_2c << 4,loop_idx << 4,(local_2c + 1) * 0x10,(loop_idx + 1) * 0x10)
          ;
          OffsetRect(&color_idx,DAT_004f80f0,DAT_004f80f4);
          pt.y = local_24;
          pt.x = local_28;
          BVar1 = PtInRect(&color_idx,pt);
          if (BVar1 != 0) {
            match_count = 1;
            local_30 = loop_idx * 0x10 + local_2c;
          }
          local_2c = local_2c + 1;
        }
        loop_idx = loop_idx + 1;
      }
      if ((match_count != 0) && (slot_idx != local_30)) {
        slot_idx = local_30;
        SetWindowLongA(hwnd,DAT_004f80ec,local_30);
        InvalidateRect(hwnd,(RECT *)0x0,0);
      }
      return 0;
    }
  }
  LVar3 = DefWindowProcA(hwnd,uMsg,wParam,lParam);
  return LVar3;
}



