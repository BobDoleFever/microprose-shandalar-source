/*
 * Decompiled function: Pic_Subsystem_0043b7c9
 * Entry Point: 0043b7c9
 * Size: 677 bytes
 */
#include "magic.h"


void Pic_Subsystem_0043b7c9(int x,int y,int width,uint height)

{
  undefined4 arg_10;
  int iVar1;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  int arg_15;
  undefined4 arg_15_00;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  
  if (width == 0x74) {
    arg_19_00 = 0;
    arg_18_00 = 0;
    arg_17_00 = 0;
    arg_16_00 = 0xffffffff;
    arg_15_00 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13_00 = 0xffffffff;
    arg_12_00 = 0;
    arg_11_00 = 0;
    arg_10 = SpellChain_ProcessTriggerEvent(x,y);
    FUN_00403250((int *)0x0,0,x,2,2,0x200,2,0,0,arg_10,arg_11_00,arg_12_00,arg_13_00,arg_14,
                 arg_15_00,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
  }
  else {
    if (((width == 0x6c) && (g_OverworldMapGrid == y)) && (g_OverworldPlayerCoordX == x)) {
      iVar1 = CardTarget_PromptTargetCreature(x,x,y);
      if (iVar1 == 0) {
        g_ActivePlayer = 1;
      }
      else {
        g_ActivePlayer = 0;
      }
    }
    if (width == 0x71) {
      arg_20 = 0;
      arg_19 = 0;
      arg_18 = 0;
      arg_17 = 0xffffffff;
      arg_16 = 0xffffffff;
      arg_15 = -1;
      iVar1 = -1;
      arg_13 = 0;
      arg_12 = 0;
      arg_11 = SpellChain_ProcessTriggerEvent(x,y);
      iVar1 = Rules_ParseFilter_0040360b
                        (*(int *)(&g_CardSlot_CombatTarget + y * 0x120 + x * 0x5b20),
                         *(int *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20),(char *)0x0,x,2
                         ,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,arg_15,arg_16,arg_17,arg_18,
                         arg_19,arg_20);
      if (iVar1 == 0) {
        Pic_Subsystem_0044867e(x,y,1);
        g_ActivePlayer = 1;
      }
      else {
        (&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] =
             (&g_CardSlot_CombatTarget)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&g_CardSlot_AttachedAura + y * 0x120 + x * 0x5b20);
      }
      (&g_CardSlot_TurnPlayed)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((*(int *)(&g_CardSlot_OriginalCardId + y * 0x120 + x * 0x5b20) == g_OverworldMapGrid) &&
        ((char)(&g_CardSlot_Toughness)[y * 0x120 + x * 0x5b20] == g_OverworldPlayerCoordX)) &&
       ((g_OverworldMapGrid != -1 &&
        ((((&g_CardSlot_Flags)[y * 0x120 + x * 0x5b20] & 0x20) == 0 && (width == 0x34)))))) {
      g_ActivePalette = g_ActivePalette | height;
    }
  }
  return;
}


