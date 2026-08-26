/*
 * Decompiled function: Card_ClockworkBeast_Rewind
 * Entry Point: 004d6c43
 * Size: 319 bytes
 */
#include "magic.h"


undefined4 Card_ClockworkBeast_Rewind(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 1) {
    *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) = *(int *)(&DAT_006ff6a0 + arg_1 * 0x20) + 1;
  }
  if (arg_3 == 0x73) {
    uVar1 = FUN_0040d949(arg_1,4,1);
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0040d949(arg_1,4,1);
      if (iVar2 != 0) {
        Ai_CalcManaRequirement_004ba890(arg_1,4,1);
        if (g_ActivePlayer != 1) {
          *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      iVar2 = FUN_00410cc0(arg_1,arg_2,DAT_006a2854,arg_1,arg_2);
      if (iVar2 != -1) {
        *(short *)(&DAT_006a5f4a + iVar2 * 0x120 + arg_1 * 0x5b20) =
             (short)*(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20);
      }
    }
    if (arg_3 == 0x3a) {
      uVar1 = FUN_0040d949(arg_1,4,1);
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


