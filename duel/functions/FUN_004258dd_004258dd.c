/*
 * Decompiled function: FUN_004258dd
 * Entry Point: 004258dd
 * Size: 682 bytes
 */
#include "duel.h"


void FUN_004258dd(HDC hdc,RECT *arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int iVar1;
  uint arg_5_00;
  int local_b0 [2];
  uint local_a8;
  int local_a4;
  uint local_a0;
  undefined *local_9c;
  undefined *local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [10];
  undefined1 auStack_6e [10];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_44;
  undefined4 auStack_40 [4];
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (RECT *)0x0)) {
    if ((DAT_0068f0fc == arg_3) && (iVar1 = FUN_00448304(arg_4,arg_5), iVar1 == DAT_006764b4)) {
      FUN_0042043e(hdc,arg_2);
      FUN_00424f7b(hdc,&arg_2->left,0x4f3678,0,1);
    }
    else {
      local_a8 = FUN_004474ec(local_b0,arg_4,arg_5);
      local_8 = local_a8 >> 0x10;
      local_a0 = local_a8 & 0xffff;
      if (DAT_0068f0fc == arg_3) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_0050b208,(uint *)s_Activation_004f3684);
      }
      else {
        DAT_0050b208 = 0;
      }
      local_98 = &DAT_0050b208;
      local_9c = &DAT_0050b208;
      local_94 = 0xffffffff;
      local_90 = 0xffffffff;
      local_8c = 0xffffffff;
      local_88 = 0xffffffff;
      local_84 = 0xffffffff;
      local_80 = 0xffffffff;
      local_7c = 0;
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_78[local_a4] = 0;
      }
      for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
        auStack_6e[local_a4] = 0;
      }
      local_64 = 0xffffffff;
      local_60 = 0;
      local_5c = 0;
      local_58 = 0xffffffff;
      for (local_a4 = 0; local_a4 < 4; local_a4 = local_a4 + 1) {
        auStack_40[local_a4] = 0;
      }
      local_30 = 0xffffffff;
      DAT_0050afa8 = 0;
      local_2c = &DAT_0050afa8;
      local_28 = &DAT_004f3690;
      local_24 = 0;
      local_20 = 0;
      local_44 = 0;
      local_c = 0;
      FUN_00423651(hdc,&arg_2->left,&local_a0,local_8,1);
      FUN_00426181(hdc,&arg_2->left,arg_6,arg_7);
      iVar1 = FUN_00447a88(arg_4,arg_5);
      arg_5_00 = (uint)(iVar1 == arg_4);
      iVar1 = FUN_00447c07(arg_4,arg_5);
      FUN_00424f7b(hdc,&arg_2->left,(int)local_98,iVar1,arg_5_00);
    }
  }
  return;
}


