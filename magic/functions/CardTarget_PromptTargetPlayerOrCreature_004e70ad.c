/*
 * Decompiled function: CardTarget_PromptTargetPlayerOrCreature
 * Entry Point: 004e70ad
 * Size: 300 bytes
 */
#include "magic.h"


bool CardTarget_PromptTargetPlayerOrCreature(int arg_1,uint arg_2,int arg_3)

{
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int iVar1;
  int arg_12;
  uint arg_13;
  uint arg_14;
  uint arg_15;
  uint arg_16;
  uint arg_17;
  undefined1 *arg_18;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (arg_2 == 0xffffffff) {
    arg_2 = 2;
  }
  arg_20 = &local_c;
  arg_19 = 1;
  arg_18 = &g_OverworldGoldAmount;
  arg_17 = 0;
  arg_16 = 0;
  arg_15 = 0;
  arg_14 = 0xffffffff;
  arg_13 = 0xffffffff;
  arg_12 = -1;
  iVar1 = -1;
  arg_10 = 0;
  arg_9 = 0;
  arg_8 = SpellChain_ProcessTriggerEvent(arg_1,arg_3);
  iVar1 = Action_ValidateTarget_00405802
                    (arg_1,2,arg_2,0x200,0x40,0,0,arg_8,arg_9,arg_10,iVar1,arg_12,arg_13,arg_14,
                     arg_15,arg_16,arg_17,arg_18,arg_19,arg_20);
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


