/*
 * Decompiled function: FUN_004612b0
 * Entry Point: 004612b0
 * Size: 529 bytes
 */
#include "duel.h"


undefined4 FUN_004612b0(int x,int y,int width,int arg_4)

{
  undefined4 uVar1;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  int local_c;
  int local_8;
  
  if ((&DAT_006827b8)[y * 0x120 + x * 0x5b20] == '\0') {
    uVar1 = 0;
  }
  else {
    if (width == 0x72) {
      local_c = DAT_00690af0;
      local_8 = DAT_0068efa0;
    }
    else {
      local_c = x;
      local_8 = y;
    }
    if ((*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) == -1) &&
       (*(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) == -1)) {
      uVar1 = 0;
    }
    else {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = FUN_004521e2(x,y);
      iVar2 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                         *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),(undefined1 *)0x0,x,2,2,
                         0x1200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,arg_16,arg_17,arg_18,arg_19,
                         arg_20);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
        uVar1 = 0;
      }
      else {
        if (*(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) == -1) {
          Mem_AllocOrFree_004afd1c
                    (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),arg_4,local_c,local_8);
        }
        else {
          FUN_004af950(*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                       *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),arg_4,local_c,local_8);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


