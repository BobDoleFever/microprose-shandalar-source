/*
 * Decompiled function: FUN_0048d00c
 * Entry Point: 0048d00c
 * Size: 788 bytes
 */
#include "duel.h"


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0048d00c(int arg_1)

{
  undefined4 uVar1;
  int iVar2;
  uint local_134 [66];
  int local_2c;
  int local_28 [8];
  uint local_8;
  
  local_28[1] = 300;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = arg_1;
  local_8 = 0;
  if (DAT_0066aaf4 == 1) {
    uVar1 = 0;
  }
  else {
    local_28[0] = arg_1;
    if (arg_1 < 0x14) {
      PlaySnd(arg_1,0);
    }
    else if (arg_1 < 0x1d) {
      iVar2 = IsSndLoaded(arg_1,local_28);
      if (iVar2 == 0) {
        local_2c = GetLRUSnd(local_28,0x14,0x16);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint *)&DAT_0060d4a0);
        FUN_004d9640(local_134,(uint *)&DAT_004fb0ec);
        FUN_004d9640(local_134,(uint *)(&PTR_s_artifact_wav_004fab58)[arg_1]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else if (arg_1 < 0x22) {
      iVar2 = IsSndLoaded(arg_1,local_28);
      if (iVar2 == 0) {
        local_2c = GetLRUSnd(local_28,0x1d,0x1d);
        if (local_2c == 0) {
          CloseSndTrack(local_28[0]);
        }
        else if (local_2c != 1) {
          return 0;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint *)&DAT_0060d4a0);
        FUN_004d9640(local_134,(uint *)&DAT_004fb0f0);
        FUN_004d9640(local_134,(uint *)(&PTR_s_buried_wav_004fab5c)[arg_1]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
      }
      PlaySnd(local_28[0],0);
    }
    else {
      if (0x2f < arg_1) {
        return 0;
      }
      local_28[1] = 400;
      iVar2 = IsSndLoaded(arg_1,local_28);
      if (iVar2 == 0) {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        Mem_AllocOrFree_004d9630(local_134,(uint *)&DAT_0060d4a0);
        FUN_004d9640(local_134,(uint *)&DAT_004fb0f4);
        FUN_004d9640(local_134,(uint *)(&PTR_s_draw_wav_004fab60)[arg_1]);
        InitSndTrack(local_134,local_28[0],local_28 + 1);
        PlaySnd(local_28[0],local_28 + 1);
      }
      else {
        if (arg_1 == 0x2b) {
          local_28[6] = 0xffffffff;
        }
        else {
          local_8 = local_8 | 4;
        }
        PlaySnd(local_28[0],local_28 + 1);
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


