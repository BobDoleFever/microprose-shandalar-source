/*
 * Decompiled function: Palette_Subsystem_0049c3ac
 * Entry Point: 0049c3ac
 * Size: 794 bytes
 */
#include "magic.h"


undefined4 Palette_Subsystem_0049c3ac(int *arg_1)

{
  undefined4 uVar1;
  int iVar2;
  char local_170 [264];
  char local_68 [100];
  
  if (arg_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else if (*arg_1 == 0) {
    if (arg_1 == &DAT_0054b384) {
      strcpy(local_68,s_CARDBK_Green_0052be84);
    }
    else if (arg_1 == &DAT_0054b3c4) {
      strcpy(local_68,s_CARDBK_White_0052be94);
    }
    else if (arg_1 == &DAT_0054b984) {
      strcpy(local_68,s_CARDBK_Blue_0052bea4);
    }
    else if (arg_1 == &DAT_0054b99c) {
      strcpy(local_68,s_CARDBK_Black_0052beb0);
    }
    else if (arg_1 == &DAT_0054b990) {
      strcpy(local_68,s_CARDBK_Red_0052bec0);
    }
    else if (arg_1 == &DAT_0054b594) {
      strcpy(local_68,s_CARDBK_Gold_0052becc);
    }
    else if (arg_1 == &DAT_0054b96c) {
      strcpy(local_68,s_CARDBK_Artifact_0052bed8);
    }
    else if (arg_1 == &DAT_0054b3c8) {
      strcpy(local_68,s_CARDBK_GreenLand_0052bee8);
    }
    else if (arg_1 == &DAT_0054b590) {
      strcpy(local_68,s_CARDBK_WhiteLand_0052befc);
    }
    else if (arg_1 == &DAT_0054b748) {
      strcpy(local_68,s_CARDBK_BlueLand_0052bf10);
    }
    else if (arg_1 == &DAT_0054b584) {
      strcpy(local_68,s_CARDBK_BlackLand_0052bf20);
    }
    else if (arg_1 == &DAT_0054b8f4) {
      strcpy(local_68,s_CARDBK_RedLand_0052bf34);
    }
    else if (arg_1 == &DAT_0054b924) {
      strcpy(local_68,s_CARDBK_DarklandsLand_0052bf44);
    }
    else if (arg_1 == &DAT_0054b388) {
      strcpy(local_68,s_CARDBK_FallenEmpiresLand_0052bf5c);
    }
    else if (arg_1 == &DAT_0054b998) {
      strcpy(local_68,s_CARDBK_AntiquitiesLand_0052bf78);
    }
    else if (arg_1 == &DAT_0054b378) {
      strcpy(local_68,s_CARDBK_LegendsLand_0052bf90);
    }
    else if (arg_1 == &DAT_0054b974) {
      strcpy(local_68,s_CARDBK_ArabianNightsLand_0052bfa4);
    }
    else if (arg_1 == &DAT_0054b968) {
      strcpy(local_68,s_CARDBK_Special_0052bfc0);
    }
    else {
      strcpy(local_68,&DAT_0052bfd0);
    }
    if (local_68[0] != '\0') {
      sprintf(local_170,s__s__s_pic_0052bfd4,&DAT_006808d0,local_68);
      iVar2 = Pic_Load_00423833(local_170);
      *arg_1 = iVar2;
    }
    if (*arg_1 == 0) {
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


