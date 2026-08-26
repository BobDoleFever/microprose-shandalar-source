/*
 * Decompiled function: FUN_00420120
 * Entry Point: 00420120
 * Size: 793 bytes
 */
#include "duel.h"


undefined4 FUN_00420120(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_170 [264];
  char local_68 [100];
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else if (*param_1 == 0) {
    if (param_1 == &DAT_0050abdc) {
      FUN_004d9630(local_68,s_CARDBK_Green_004f3298);
    }
    else if (param_1 == &DAT_0050ac1c) {
      FUN_004d9630(local_68,s_CARDBK_White_004f32a8);
    }
    else if (param_1 == &DAT_0050b1dc) {
      FUN_004d9630(local_68,s_CARDBK_Blue_004f32b8);
    }
    else if (param_1 == &DAT_0050b1f4) {
      FUN_004d9630(local_68,s_CARDBK_Black_004f32c4);
    }
    else if (param_1 == &DAT_0050b1e8) {
      FUN_004d9630(local_68,s_CARDBK_Red_004f32d4);
    }
    else if (param_1 == &DAT_0050adec) {
      FUN_004d9630(local_68,s_CARDBK_Gold_004f32e0);
    }
    else if (param_1 == &DAT_0050b1c4) {
      FUN_004d9630(local_68,s_CARDBK_Artifact_004f32ec);
    }
    else if (param_1 == &DAT_0050ac20) {
      FUN_004d9630(local_68,s_CARDBK_GreenLand_004f32fc);
    }
    else if (param_1 == &DAT_0050ade8) {
      FUN_004d9630(local_68,s_CARDBK_WhiteLand_004f3310);
    }
    else if (param_1 == &DAT_0050afa0) {
      FUN_004d9630(local_68,s_CARDBK_BlueLand_004f3324);
    }
    else if (param_1 == &DAT_0050addc) {
      FUN_004d9630(local_68,s_CARDBK_BlackLand_004f3334);
    }
    else if (param_1 == &DAT_0050b14c) {
      FUN_004d9630(local_68,s_CARDBK_RedLand_004f3348);
    }
    else if (param_1 == &DAT_0050b17c) {
      FUN_004d9630(local_68,s_CARDBK_DarklandsLand_004f3358);
    }
    else if (param_1 == &DAT_0050abe0) {
      FUN_004d9630(local_68,s_CARDBK_FallenEmpiresLand_004f3370);
    }
    else if (param_1 == &DAT_0050b1f0) {
      FUN_004d9630(local_68,s_CARDBK_AntiquitiesLand_004f338c);
    }
    else if (param_1 == &DAT_0050abd0) {
      FUN_004d9630(local_68,s_CARDBK_LegendsLand_004f33a4);
    }
    else if (param_1 == &DAT_0050b1cc) {
      FUN_004d9630(local_68,s_CARDBK_ArabianNightsLand_004f33b8);
    }
    else if (param_1 == &DAT_0050b1c0) {
      FUN_004d9630(local_68,s_CARDBK_Special_004f33d4);
    }
    else {
      FUN_004d9630(local_68,&DAT_004f33e4);
    }
    if (local_68[0] != '\0') {
      _sprintf(local_170,s__s__s_pic_004f33e8,&DAT_005f7800,local_68);
      iVar2 = FUN_0043d713(local_170);
      *param_1 = iVar2;
    }
    if (*param_1 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


