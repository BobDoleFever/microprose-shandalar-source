/*
 * Decompiled function: Card_DirectDamage_PromptAndDealDamage
 * Entry Point: 004dfb23
 * Size: 529 bytes
 */
#include "magic.h"


undefined4 Card_DirectDamage_PromptAndDealDamage(int x,int y,int width,int height)

{
  undefined4 uVar1;
  uint arg_11;
  uint arg_12;
  uint arg_13;
  int iVar2;
  int arg_15;
  uint arg_16;
  uint arg_17;
  uint arg_18;
  uint arg_19;
  uint arg_20;
  int local_c;
  int local_8;
  
  if ((&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] == '\0') {
    uVar1 = 0;
  }
  else {
    if (width == 0x72) {
      local_c = g_DialogPromptHwnd;
      local_8 = g_DuelArenaHwnd;
    }
    else {
      local_c = x;
      local_8 = y;
    }
    if ((*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20) == -1) &&
       (*(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) == -1)) {
      uVar1 = 0;
    }
    else {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar2 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(x,y);
      iVar2 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x1200,2,0,0,arg_11,arg_12,arg_13,iVar2,arg_15,arg_16,arg_17,arg_18,
                         arg_19,arg_20);
      if (iVar2 == 0) {
        g_ActivePlayer = 1;
        uVar1 = 0;
      }
      else {
        if (*(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20) == -1) {
          Mem_AllocOrFree_0041df33
                    (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),height,local_c,
                     local_8);
        }
        else {
          FUN_0041db67(*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                       *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),height,local_c,
                       local_8);
        }
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


