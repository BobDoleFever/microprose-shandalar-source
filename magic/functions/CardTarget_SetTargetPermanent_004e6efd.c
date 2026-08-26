/*
 * Decompiled function: CardTarget_SetTargetPermanent
 * Entry Point: 004e6efd
 * Size: 285 bytes
 */
#include "magic.h"


bool CardTarget_SetTargetPermanent(int arg_1,uint arg_2,int arg_3)

{
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  iVar1 = Action_ValidateTarget_00405802
                    (arg_1,2,arg_2,0x200,1,0,0,0,0,0,-1,-1,0xffffffff,0xffffffff,0,0,0,
                     &g_OverworldGoldAmount,1,&local_c);
  if (iVar1 != 0) {
    *(int *)(&g_CardSlot_CombatTarget +
            arg_3 * 0x120 +
            arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) =
         local_c;
    *(undefined4 *)
     (&g_CardSlot_AttachedAura +
     arg_3 * 0x120 +
     arg_1 * 0x5b20 + (char)(&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + arg_1 * 0x5b20] * 8) = local_8;
    (&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_TurnPlayed)[arg_3 * 0x120 + arg_1 * 0x5b20] + '\x01';
  }
  return iVar1 != 0;
}


