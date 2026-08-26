/*
 * Decompiled function: FUN_00413baa
 * Entry Point: 00413baa
 * Size: 343 bytes
 */
#include "magic.h"


undefined4 FUN_00413baa(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int arg1;
  int iVar2;
  int local_c;
  
  if (arg_3 == 0x89) {
    CardQuery_ForEachPermanent(FUN_00413d01,-1);
  }
  if ((((arg_3 == 0x22) || (arg_3 == 199)) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    arg1 = 1 - arg_1;
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg1]; local_c = local_c + 1) {
      iVar1 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + arg1 * 0x5b20);
      iVar2 = FUN_00471c32(arg1,local_c);
      if (((iVar2 != 0) && (((&g_MasterCardColorTable)[iVar1 * 0x34] & 2) != 0)) &&
         (((&DAT_0051aebd)[iVar1 * 0x34] != '\0' &&
          ((*(uint *)(&g_CardSlot_Flags + local_c * 0x120 + arg1 * 0x5b20) & 0x30040) == 0)))) {
        Pic_Subsystem_0044867e(arg1,local_c,2);
      }
    }
    Pic_Subsystem_0044867e(arg_1,arg_2,2);
  }
  return 0;
}


