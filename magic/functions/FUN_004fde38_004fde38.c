/*
 * Decompiled function: FUN_004fde38
 * Entry Point: 004fde38
 * Size: 314 bytes
 */
#include "magic.h"


undefined4 FUN_004fde38(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1)
        {
          iVar2 = FUN_00471c32(local_8,local_c);
          if ((iVar2 != 0) &&
             (((&g_MasterCardColorTable)
               [*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) * 0x34] & 1) != 0)
             ) {
            iVar2 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20);
            iVar3 = FUN_0041d963(arg_1,arg_2,5);
            if (*(int *)(&g_MasterCardTypeTable + iVar2 * 0x34) ==
                *(int *)(&DAT_006ff2bc + iVar3 * 4)) {
              Pic_Subsystem_0044867e(local_8,local_c,2);
            }
          }
        }
      }
      Pic_Subsystem_0044867e(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


