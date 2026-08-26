/*
 * Decompiled function: Magic_TriggerCardEvent
 * Entry Point: 00474266
 * Size: 291 bytes
 */
#include "magic.h"


int Magic_TriggerCardEvent(int arg_1,int arg_2,int arg_3,undefined4 arg_4,undefined4 arg_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
    iVar2 = 0;
  }
  else {
    Magic_PayManaCost();
    uVar1 = DAT_006a4920;
    g_ActivePalette = 0;
    g_OverworldPlayerCoordX = arg_1;
    g_OverworldMapGrid = arg_2;
    DAT_007006c8 = arg_4;
    DAT_006b2d5c = arg_5;
    iVar2 = (**(code **)(&DAT_0051aec8 +
                        *(int *)(&g_CardSlot_CardId + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
    if ((((iVar2 != 99) && ((g_PlayerHandCardCount & 0x224) != 0)) &&
        ((arg_3 == 0x74 || (arg_3 == 0x73)))) &&
       (iVar3 = Magic_ResolveSpellStack(arg_1,arg_2), iVar3 == 0)) {
      DAT_006a4920 = uVar1;
      Magic_TapCardForMana();
      return 0;
    }
    DAT_006b2e38 = g_ActivePalette;
    Magic_TapCardForMana();
  }
  return iVar2;
}


