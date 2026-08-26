/*
 * Decompiled function: Palette_Subsystem_004a155f
 * Entry Point: 004a155f
 * Size: 1541 bytes
 */
#include "magic.h"


void Palette_Subsystem_004a155f(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  byte arg_1;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_f4;
  char local_e8 [52];
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined1 *local_9c;
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
  undefined1 *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_b0 = Ai_Subsystem_004b6023(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (DAT_00695e94 == arg_3) {
      uVar1 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b390,s_Damage___d_0052c208,uVar1);
      arg_1 = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_b4 = FUN_00473cc5(arg_1);
      if (local_b4 == 1) {
        strcat(&DAT_0054b390,s__Black__0052c214);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_0054b390,s__Blue__0052c220);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_0054b390,s__Red__0052c228);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_0054b390,s__Green__0052c230);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_0054b390,s__White__0052c23c);
      }
    }
    else if (DAT_0068a70c == arg_3) {
      iVar2 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b390,s_Hunting___s_0052c248,(&PTR_DAT_00528cc8)[iVar2]);
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809e4 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809ec + local_a0 * 0x14));
    }
    else if (DAT_006ff2dc == arg_3) {
      strcpy(&DAT_0054b390,s_Activation_0052c254);
    }
    else {
      DAT_0054b390 = 0;
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_e8,&DAT_0054b390);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b390,local_e8,iVar2);
    }
    iVar2 = Ai_Subsystem_004b5cbb(local_ac,local_a8);
    if ((iVar2 == 0x361) || (iVar2 == 0x360)) {
      strcpy(&DAT_0054b390,*(char **)(&DAT_006809e4 + iVar2 * 0x14));
    }
    local_98 = &DAT_0054b390;
    local_9c = &DAT_0054b390;
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
    if (DAT_00695e94 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e0 + local_a0 * 0x14));
    }
    else if (DAT_0068a70c == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b3e0,*(char **)(&DAT_006809f0 + local_a0 * 0x14));
    }
    else {
      DAT_0054b3e0 = 0;
    }
    local_2c = &DAT_0054b3e0;
    local_28 = &DAT_0052c260;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    Palette_Subsystem_0049f8cd(hdc,arg_2,&local_a0,local_8,1);
    Palette_Subsystem_004a2401(hdc,arg_2,arg_4,arg_5);
    iVar2 = Ai_Subsystem_004b65bf(arg_4,arg_5);
    uVar3 = (uint)(iVar2 == arg_4);
    iVar2 = Ai_Subsystem_004b673e(arg_4,arg_5);
    Palette_Subsystem_004a11fa(hdc,arg_2,local_98,iVar2,uVar3);
    if (DAT_00695e94 == arg_3) {
      uVar3 = Ai_Subsystem_004b6c5b(arg_4,arg_5);
      local_f4 = 0;
      if ((uVar3 & 0x100000) != 0) {
        local_f4 = 0x100;
      }
      if ((uVar3 & 0x80000) != 0) {
        local_f4 = local_f4 | 0x80;
      }
      if ((DAT_006fe42c != 0) && (local_f4 != 0)) {
        Palette_Subsystem_004a0d00(hdc,arg_2,local_f4);
      }
    }
  }
  return;
}


