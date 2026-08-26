/*
 * Decompiled function: FUN_004491fe
 * Entry Point: 004491fe
 * Size: 175 bytes
 */
#include "duel.h"


int FUN_004491fe(uint *arg_1)

{
  uint uVar1;
  uint uVar2;
  uint local_70 [25];
  int local_c;
  INT_PTR local_8;
  
  KillTimer(DAT_00618990,DAT_00663610);
  uVar1 = _rand();
  uVar2 = (int)uVar1 >> 0x1f;
  local_c = ((uVar1 ^ uVar2) - uVar2 & 1 ^ uVar2) - uVar2;
  if (DAT_0066aaf4 != 1) {
    Mem_AllocOrFree_004d9630(local_70,arg_1);
    local_8 = DialogBoxParamA(DAT_00664680,(LPCSTR)0xf0,DAT_00618990,Ai_Subsystem_004b7de8,
                              (LPARAM)local_70);
    InvalidateRect(DAT_00617378,(RECT *)0x0,1);
    InvalidateRect(DAT_00618988,(RECT *)0x0,1);
    StopSnd(0x2f);
  }
  return local_c;
}


