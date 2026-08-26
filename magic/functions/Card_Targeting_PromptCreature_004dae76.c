/*
 * Decompiled function: Card_Targeting_PromptCreature
 * Entry Point: 004dae76
 * Size: 430 bytes
 */
#include "magic.h"


undefined4 Card_Targeting_PromptCreature(int x,int y,int width,uint height)

{
  undefined4 uVar1;
  uint arg_8;
  uint arg_9;
  uint arg_10;
  int iVar2;
  undefined4 arg_11;
  int arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  uint arg_14;
  undefined4 arg_14_00;
  uint arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  undefined1 *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_c;
  undefined4 local_8;
  
  if (height == 0xffffffff) {
    height = 2;
  }
  if (width == 0x73) {
    uVar1 = 0;
    if ((*(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) & 0x20010) == 0) {
      arg_19 = 0;
      arg_18_00 = 1;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15_00 = 0xffffffff;
      arg_14_00 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11 = 0;
      uVar1 = SpellChain_ProcessTriggerEvent(x,y);
      uVar1 = FUN_00403250((int *)0x0,0,x,2,2,0x200,2,0,0,uVar1,arg_11,arg_12_00,arg_13_00,arg_14_00
                           ,arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19);
    }
  }
  else {
    if (width == 0x6d) {
      arg_20 = &local_c;
      uVar1 = 1;
      arg_18 = &g_OverworldGoldAmount;
      arg_17 = 0;
      arg_16 = 1;
      arg_15 = 0;
      arg_14 = 0xffffffff;
      arg_13 = 0xffffffff;
      arg_12 = -1;
      iVar2 = -1;
      arg_10 = 0;
      arg_9 = 0;
      arg_8 = SpellChain_ProcessTriggerEvent(x,y);
      iVar2 = Action_ValidateTarget_00405802
                        (x,2,height,0x200,2,0,0,arg_8,arg_9,arg_10,iVar2,arg_12,arg_13,arg_14,arg_15
                         ,arg_16,arg_17,arg_18,uVar1,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        *(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) = local_c;
        *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) = local_8;
        (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 1;
        *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) =
             *(uint *)(&g_CardSlot_Flags + y * 0x120 + x * 0x5b20) | 0x10;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


