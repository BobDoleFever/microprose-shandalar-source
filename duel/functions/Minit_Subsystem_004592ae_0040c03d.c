/*
 * Decompiled function: Minit_Subsystem_004592ae
 * Entry Point: 0040c03d
 * Size: 554 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_004592ae(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,6);
    if (((iVar1 == 0) || (*(int *)(&DAT_0066aad0 + arg_1 * 4) == 0)) ||
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else if (arg_3 == 0x90) {
    FUN_0043071d(0);
    uVar2 = 0;
  }
  else {
    if ((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,6), iVar1 != 0)) {
      Ai_CalcManaRequirement_004ba890(arg_1,0,6);
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Pick_a_permanent_004f2750);
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)DAT_0068eef0;
      if (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
    }
    if ((arg_3 == 0x72) && (*(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
      Pic_Subsystem_0044895f
                ((int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20],
                 *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20));
      (&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0xff;
      *(int *)(&DAT_006826e8 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           (int)(char)(&DAT_006826d2)[arg_2 * 0x120 + arg_1 * 0x5b20];
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    uVar2 = 0;
  }
  return uVar2;
}


