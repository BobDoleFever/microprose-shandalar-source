/*
 * Decompiled function: Pic_Subsystem_0044edf5
 * Entry Point: 0044edf5
 * Size: 270 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044edf5(undefined4 arg_1)

{
  undefined4 uVar1;
  char local_10c [264];
  
  uVar1 = g_ScWillyScore;
  if (((byte)DAT_006fe410 & 1) == 0) {
    g_ScWillyScore = arg_1;
    strcpy(local_10c,&DAT_006a28c0);
    strcat(local_10c,s__AUTOSAVE_00523ba0);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  if ((((byte)DAT_006fe410 & 1) != 0) && (DAT_0068a718 != 0)) {
    g_ScWillyScore = arg_1;
    strcpy(local_10c,&DAT_006a28c0);
    strcat(local_10c,s__SHANDSAVE_00523bac);
    strcat(local_10c,&DAT_00538c21);
    FUN_0048e122(local_10c);
  }
  g_ScWillyScore = uVar1;
  return;
}


