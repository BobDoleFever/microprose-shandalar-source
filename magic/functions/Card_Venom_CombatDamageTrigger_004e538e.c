/*
 * Decompiled function: Card_Venom_CombatDamageTrigger
 * Entry Point: 004e538e
 * Size: 583 bytes
 */
#include "magic.h"


undefined4 Card_Venom_CombatDamageTrigger(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  int arg1;
  int iVar2;
  int local_c;
  
  if ((((arg_3 == 0x1a) && (arg1 = 1 - arg_1, arg_1 != g_DefendingPlayer)) &&
      ((&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    cVar1 = (&g_CardSlot_ColorMask)
            [arg1 * 0x5b20 + (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120];
    if (cVar1 == -1) {
      FUN_00410cc0(arg_1,arg_2,DAT_006b2d84,arg1,
                   (int)(char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20]);
      *(uint *)(&g_CardSlot_Abilities1 +
               arg1 * 0x5b20 + (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120
               ) = *(uint *)(&g_CardSlot_Abilities1 +
                            arg1 * 0x5b20 +
                            (char)(&g_CardSlot_ColorMask)[arg_2 * 0x120 + arg_1 * 0x5b20] * 0x120) |
                   0x8000;
    }
    else {
      for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg1]; local_c = local_c + 1) {
        iVar2 = FUN_00471c32(arg1,local_c);
        if ((iVar2 != 0) && ((&g_CardSlot_ColorMask)[local_c * 0x120 + arg1 * 0x5b20] == cVar1)) {
          FUN_00410cc0(arg_1,arg_2,DAT_006b2d84,arg1,local_c);
          *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg1 * 0x5b20) =
               *(uint *)(&g_CardSlot_Abilities1 + local_c * 0x120 + arg1 * 0x5b20) | 0x8000;
        }
      }
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  return 0;
}


