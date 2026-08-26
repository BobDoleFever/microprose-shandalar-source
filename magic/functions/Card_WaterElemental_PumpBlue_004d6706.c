/*
 * Decompiled function: Card_WaterElemental_PumpBlue
 * Entry Point: 004d6706
 * Size: 313 bytes
 */
#include "magic.h"


undefined4 Card_WaterElemental_PumpBlue(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int arg_2_00;
  int arg_3_00;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) = *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
       (iVar1 = FUN_0040d949(arg_1,4,1), iVar1 != 0)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0040d949(arg_1,4,1), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,4,1);
    }
    if ((arg_3 == 0x72) && (iVar1 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,arg_1,arg_2), iVar1 != -1)
       ) {
      *(undefined2 *)(&DAT_006a5f48 + iVar1 * 0x120 + arg_1 * 0x5b20) = 1;
    }
    if (arg_3 == 0x39) {
      arg_3_00 = 1;
      arg_2_00 = 0;
      iVar1 = FUN_0040d949(arg_1,4,1);
      uVar2 = FUN_0040a305(iVar1,arg_2_00,arg_3_00);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


