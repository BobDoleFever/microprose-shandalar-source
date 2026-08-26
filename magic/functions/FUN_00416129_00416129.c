/*
 * Decompiled function: FUN_00416129
 * Entry Point: 00416129
 * Size: 249 bytes
 */
#include "magic.h"


undefined4 FUN_00416129(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_c = 0; local_c < 2; local_c = local_c + 1) {
        for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[local_c]; local_8 = local_8 + 1)
        {
          iVar2 = FUN_00471c32(local_c,local_8);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) * 0x34] & 2) != 0)
             ) {
            FUN_00410cc0(arg_1,arg_2,DAT_006ff374,local_c,local_8);
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


