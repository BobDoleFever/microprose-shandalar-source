/*
 * Decompiled function: thunk_FUN_1001a9ec
 * Entry Point: 1000152d
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001a9ec(int *arg_1)

{
  int32_t uval_1;
  int val_2;
  char acStack_170 [264];
  char acStack_68 [100];
  
  if (arg_1 == (int *)0x0) {
    uval_1 = 0;
  }
  else if (*arg_1 == 0) {
    if (arg_1 == &DAT_1013dff4) {
      strcpy(acStack_68,s_CARDBK_Green_1004356c);
    }
    else if (arg_1 == &DAT_1013e034) {
      strcpy(acStack_68,s_CARDBK_White_1004357c);
    }
    else if (arg_1 == &DAT_1013e5f4) {
      strcpy(acStack_68,s_CARDBK_Blue_1004358c);
    }
    else if (arg_1 == &DAT_1013e60c) {
      strcpy(acStack_68,s_CARDBK_Black_10043598);
    }
    else if (arg_1 == &DAT_1013e600) {
      strcpy(acStack_68,s_CARDBK_Red_100435a8);
    }
    else if (arg_1 == &DAT_1013e204) {
      strcpy(acStack_68,s_CARDBK_Gold_100435b4);
    }
    else if (arg_1 == &DAT_1013e5dc) {
      strcpy(acStack_68,s_CARDBK_Artifact_100435c0);
    }
    else if (arg_1 == &DAT_1013e038) {
      strcpy(acStack_68,s_CARDBK_GreenLand_100435d0);
    }
    else if (arg_1 == &DAT_1013e200) {
      strcpy(acStack_68,s_CARDBK_WhiteLand_100435e4);
    }
    else if (arg_1 == &DAT_1013e3b8) {
      strcpy(acStack_68,s_CARDBK_BlueLand_100435f8);
    }
    else if (arg_1 == &DAT_1013e1f4) {
      strcpy(acStack_68,s_CARDBK_BlackLand_10043608);
    }
    else if (arg_1 == &DAT_1013e564) {
      strcpy(acStack_68,s_CARDBK_RedLand_1004361c);
    }
    else if (arg_1 == &DAT_1013e594) {
      strcpy(acStack_68,s_CARDBK_DarklandsLand_1004362c);
    }
    else if (arg_1 == &DAT_1013dff8) {
      strcpy(acStack_68,s_CARDBK_FallenEmpiresLand_10043644);
    }
    else if (arg_1 == &DAT_1013e608) {
      strcpy(acStack_68,s_CARDBK_AntiquitiesLand_10043660);
    }
    else if (arg_1 == &DAT_1013dfe8) {
      strcpy(acStack_68,s_CARDBK_LegendsLand_10043678);
    }
    else if (arg_1 == &DAT_1013e5e4) {
      strcpy(acStack_68,s_CARDBK_ArabianNightsLand_1004368c);
    }
    else if (arg_1 == &DAT_1013e5d8) {
      strcpy(acStack_68,s_CARDBK_Special_100436a8);
    }
    else {
      strcpy(acStack_68,&DAT_100436b8);
    }
    if (acStack_68[0] != '\0') {
      sprintf(acStack_170,s__s__s_pic_100436bc,&DAT_10158890,acStack_68);
      val_2 = thunk_FUN_1003afa3(acStack_170);
      *arg_1 = val_2;
    }
    if (*arg_1 == 0) {
      uval_1 = 0;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = 1;
  }
  return uval_1;
}


