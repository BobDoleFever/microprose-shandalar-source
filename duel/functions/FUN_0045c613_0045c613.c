/*
 * Decompiled function: FUN_0045c613
 * Entry Point: 0045c613
 * Size: 430 bytes
 */
#include "duel.h"


undefined4 FUN_0045c613(int x,int y,int width,uint height)

{
  undefined4 uVar1;
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int iVar2;
  undefined4 arg_11;
  int arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  uint arg_14;
  undefined4 arg_14_00;
  uint arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (height == 0xffffffff) {
    height = 2;
  }
  if (width == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 1;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14_00 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11 = 0;
      uVar1 = FUN_004521e2(x,y);
      uVar1 = FUN_0041bcf0((int *)0x0,0,x,2,2,0x200,2,0,0,uVar1,arg_11,arg_12_00,arg_13_00,arg_14_00
                           ,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19);
    }
  }
  else {
    if (width == 0x6d) {
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      arg_17 = 0;
      arg_16 = 1;
      arg_15 = 0;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = -1;
      iVar2 = -1;
      arg_10 = 0;
      arg_9 = 0;
      arg_8 = FUN_004521e2(x,y);
      iVar2 = Action_ValidateTarget_0041e2a2
                        (x,2,height,0x200,2,0,0,arg_8,arg_9,arg_10,iVar2,arg_12,arg_13,arg_14,arg_15
                         ,arg_16,arg_17,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) = local_c;
        *(undefined4 *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) = local_8;
        (&DAT_006827b8)[y * 0x120 + x * 0x5b20] = 1;
        *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


