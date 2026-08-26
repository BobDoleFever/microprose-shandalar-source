/*
 * Decompiled function: Palette_Subsystem_004a1b64
 * Entry Point: 004a1b64
 * Size: 677 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a1b64
               (HDC hdc,RECT *arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int iVar1;
  uint arg_5_00;
  int local_b0 [2];
  uint local_a8;
  int local_a4;
  uint local_a0;
  undefined *local_9c;
  char *local_98;
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
    if ((DAT_006ff2dc == arg_3) &&
       (iVar1 = Ai_Subsystem_004b6e3b(arg_4,arg_5), iVar1 == DAT_006a3f74)) {
      Palette_Subsystem_0049c6cb(hdc,arg_2);
      Palette_Subsystem_004a11fa(hdc,&arg_2->left,s_Activation_0052c264,0,1);
    }
    else {
      local_a8 = Ai_Subsystem_004b6023(local_b0,arg_4,arg_5);
      local_8 = local_a8 >> 0x10;
      local_a0 = local_a8 & 0xffff;
      if (DAT_006ff2dc == arg_3) {
        strcpy(&DAT_0054b9b0,s_Activation_0052c270);
      }
      else {
        DAT_0054b9b0 = 0;
      }
      local_98 = &DAT_0054b9b0;
      local_9c = &DAT_0054b9b0;
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
      DAT_0054b750 = 0;
      local_2c = &DAT_0054b750;
      local_28 = &DAT_0052c27c;
      local_24 = 0;
      local_20 = 0;
      local_44 = 0;
      local_c = 0;
      Palette_Subsystem_0049f8cd(hdc,&arg_2->left,&local_a0,local_8,1);
      Palette_Subsystem_004a2401(hdc,&arg_2->left,arg_6,arg_7);
      iVar1 = Ai_Subsystem_004b65bf(arg_4,arg_5);
      arg_5_00 = (uint)(iVar1 == arg_4);
      iVar1 = Ai_Subsystem_004b673e(arg_4,arg_5);
      Palette_Subsystem_004a11fa(hdc,&arg_2->left,local_98,iVar1,arg_5_00);
    }
  }
  return;
}


