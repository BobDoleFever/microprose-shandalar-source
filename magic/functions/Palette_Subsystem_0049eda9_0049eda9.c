/*
 * Decompiled function: Palette_Subsystem_0049eda9
 * Entry Point: 0049eda9
 * Size: 2852 bytes
 */
#include "magic.h"


void Palette_Subsystem_0049eda9(HDC hdc,int *arg_2,int arg_3,int arg_4,int arg_5)

{
  byte arg_1;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  char local_354 [400];
  int local_1c4;
  int local_1c0;
  char local_1bc [100];
  char local_158;
  char local_157;
  undefined1 local_156;
  int local_f4;
  uint local_f0;
  int local_ec;
  char local_e8 [52];
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  uint local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
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
  char *local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_c;
  uint local_8;
  
  if ((hdc != (HDC)0x0) && (arg_2 != (int *)0x0)) {
    local_b0 = Ai_Subsystem_004b6023(&local_ac,arg_4,arg_5);
    local_8 = local_b0 >> 0x10;
    local_a0 = local_b0 & 0xffff;
    if (arg_3 == DAT_00695e94) {
      uVar1 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b928,s_Damage___d_0052c05c,uVar1);
      arg_1 = Ai_Subsystem_004b6356(arg_4,arg_5);
      local_b4 = FUN_00473cc5(arg_1);
      if (local_b4 == 1) {
        strcat(&DAT_0054b928,s__Black__0052c068);
      }
      else if (local_b4 == 2) {
        strcat(&DAT_0054b928,s__Blue__0052c074);
      }
      else if (local_b4 == 4) {
        strcat(&DAT_0054b928,s__Red__0052c07c);
      }
      else if (local_b4 == 3) {
        strcat(&DAT_0054b928,s__Green__0052c084);
      }
      else if (local_b4 == 5) {
        strcat(&DAT_0054b928,s__White__0052c090);
      }
    }
    else if (DAT_0068a70c == arg_3) {
      iVar2 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      sprintf(&DAT_0054b928,s_Hunting___s_0052c09c,(&PTR_DAT_00528cc8)[iVar2]);
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809e4 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809ec + local_a0 * 0x14));
    }
    else {
      DAT_0054b928 = 0;
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_e8,&DAT_0054b928);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b928,local_e8,iVar2);
    }
    local_ec = Ai_Subsystem_004b5cbb(local_ac,local_a8);
    if ((local_ec == 0x361) || (local_ec == 0x360)) {
      strcpy(&DAT_0054b928,*(char **)(&DAT_006809e4 + local_ec * 0x14));
    }
    local_98 = &DAT_0054b928;
    local_9c = &DAT_0054b928;
    local_94 = 0xffffffff;
    local_90 = 0xffffffff;
    local_8c = 0;
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
    if (arg_3 == DAT_00695e94) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e0 + local_a0 * 0x14));
    }
    else if (DAT_0068a70c == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_0068a694 == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809e8 + local_a0 * 0x14));
    }
    else if (DAT_006a2848 == arg_3) {
      strcpy(&DAT_0054b5a0,*(char **)(&DAT_006809f0 + local_a0 * 0x14));
    }
    else {
      DAT_0054b5a0 = '\0';
    }
    Ai_Subsystem_004b68b3(arg_4,arg_5,&DAT_0054b5a0);
    Ai_Subsystem_004b69ba(arg_4,arg_5,&DAT_0054b5a0);
    local_1bc[1] = 0;
    local_1bc[0] = -0x12;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0a8,0,local_1bc);
    local_1bc[0] = -2;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0ac,0,local_1bc);
    local_1bc[0] = -3;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b0,0,local_1bc);
    local_1bc[0] = -5;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b4,0,local_1bc);
    local_1bc[0] = -4;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0b8,0,local_1bc);
    local_1bc[0] = -1;
    FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c0bc,0,local_1bc);
    local_158 = '|';
    local_156 = 0;
    for (local_a4 = 0; local_a4 < 10; local_a4 = local_a4 + 1) {
      local_1bc[0] = (char)local_a4 + -0xf;
      local_157 = (char)local_a4 + '0';
      FUN_004f4a92(&DAT_0054b5a0,&local_158,0,local_1bc);
    }
    Ai_Subsystem_004b650c(arg_4,arg_5,&local_1c0,&local_f4);
    sprintf(local_1bc,s___d___d_0052c0c0,local_1c0,local_f4);
    FUN_004f4a92(&DAT_0054b5a0,s___X___X_0052c0c8,0,local_1bc);
    sprintf(local_1bc,s__0___d_0052c0d0,local_f4);
    FUN_004f4a92(&DAT_0054b5a0,s__0___X_0052c0d8,0,local_1bc);
    sprintf(local_1bc,s___d__0_0052c0e0,local_1c0);
    FUN_004f4a92(&DAT_0054b5a0,s___X__0_0052c0e8,0,local_1bc);
    if (local_a0 == 0x132) {
      local_f0 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      if (local_f0 == 1) {
        strcpy(local_1bc,s_swampwalk_0052c0f0);
      }
      else if (local_f0 == 0x10) {
        strcpy(local_1bc,s_plainswalk_0052c0fc);
      }
      else if (local_f0 == 4) {
        strcpy(local_1bc,s_forestwalk_0052c108);
      }
      else if (local_f0 == 8) {
        strcpy(local_1bc,s_mountainwalk_0052c114);
      }
      else if (local_f0 == 2) {
        strcpy(local_1bc,s_islandwalk_0052c124);
      }
      else {
        strcpy(local_1bc,&DAT_0052c130);
      }
      FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c134,0,local_1bc);
    }
    if (local_a0 == 0x21b) {
      local_f0 = Ai_Subsystem_004b59d9(arg_4,arg_5);
      local_1c4 = 0;
      strcpy(local_1bc,&DAT_0052c138);
      if ((local_f0 & 0x20) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c13c);
        }
        strcat(local_1bc,s_flying_0052c144);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x100) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c14c);
        }
        strcat(local_1bc,s_first_strike_0052c154);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x40) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c164);
        }
        strcat(local_1bc,s_banding_0052c16c);
        local_1c4 = 1;
      }
      if ((local_f0 & 0x80) != 0) {
        if (local_1c4 != 0) {
          strcat(local_1bc,s_and_0052c174);
        }
        strcat(local_1bc,s_trample_0052c17c);
        local_1c4 = 1;
      }
      FUN_004f4a92(&DAT_0054b5a0,&DAT_0052c184,0,local_1bc);
      Ai_Subsystem_004b650c(arg_4,arg_5,&local_1c0,&local_f4);
      sprintf(local_1bc,s___d___d_0052c188,local_1c0,local_f4);
      FUN_004f4a92(&DAT_0054b5a0,s___X___X_0052c190,0,local_1bc);
    }
    if ((DAT_0068a694 == arg_3) && (iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5), 0 < iVar2)) {
      strcpy(local_354,&DAT_0054b5a0);
      iVar2 = Ai_Subsystem_004b649f(arg_4,arg_5);
      Palette_Subsystem_004a2dce(&DAT_0054b5a0,local_354,iVar2);
    }
    if (arg_3 == DAT_00695e94) {
      uVar3 = Ai_Subsystem_004b6c5b(arg_4,arg_5);
      if ((DAT_0054b5a0 != '\0') && (DAT_0054b5a0 != '\n')) {
        strcat(&DAT_0054b5a0,&DAT_0052c198);
      }
      if ((uVar3 & 0x100000) != 0) {
        strcat(&DAT_0054b5a0,s_First_strike_0052c19c);
      }
      if ((uVar3 & 0x80000) != 0) {
        strcat(&DAT_0054b5a0,s_Trample_0052c1ac);
      }
    }
    local_2c = &DAT_0054b5a0;
    local_28 = &DAT_0052c1b4;
    local_24 = 0;
    local_20 = 0;
    local_44 = 0;
    local_c = 0;
    Palette_Subsystem_0049c7c7(hdc,arg_2,&local_a0,local_8,2,DAT_006fe430);
  }
  return;
}


