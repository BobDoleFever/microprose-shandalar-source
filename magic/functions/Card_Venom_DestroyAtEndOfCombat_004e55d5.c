/*
 * Decompiled function: Card_Venom_DestroyAtEndOfCombat
 * Entry Point: 004e55d5
 * Size: 568 bytes
 */
#include "magic.h"


undefined4 Card_Venom_DestroyAtEndOfCombat(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_10;
  
  arg1 = 1 - arg_1;
  if (((arg_3 == 0x77) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    if ((arg_1 == g_DefendingPlayer) &&
       (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x44) != 0)) {
      for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
        if (((char)(&g_CardSlot_ColorMask)[local_10 * 0x120 + arg1 * 0x5b20] == arg_2) &&
           (((&g_MasterCardColorTable)
             [*(int *)(&g_CardSlot_CardId + local_10 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) != 0)) {
          Pic_Subsystem_0044867e(arg1,local_10,4);
        }
      }
    }
    if ((arg_1 != g_DefendingPlayer) &&
       ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) {
      cVar1 = (&g_CardSlot_ColorMask)
              [arg1 * 0x5b20 + (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120
              ];
      if (cVar1 == -1) {
        Pic_Subsystem_0044867e
                  (arg1,(int)(char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20],4);
      }
      else {
        for (local_10 = 0; local_10 < 0x50; local_10 = local_10 + 1) {
          iVar2 = FUN_00471c32(arg1,local_10);
          if ((iVar2 != 0) && ((&g_CardSlot_ColorMask)[local_10 * 0x120 + arg1 * 0x5b20] == cVar1))
          {
            Pic_Subsystem_0044867e(arg1,local_10,4);
          }
        }
      }
    }
  }
  return 0;
}


