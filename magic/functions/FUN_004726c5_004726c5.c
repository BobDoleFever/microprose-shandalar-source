/*
 * Decompiled function: FUN_004726c5
 * Entry Point: 004726c5
 * Size: 510 bytes
 */
#include "magic.h"


undefined4 FUN_004726c5(int arg1,int arg2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = g_ActivePlayer;
  iVar3 = g_ActivePalette;
  if (((((&DAT_0051aebd)[*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] == '\0'
        ) && (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0)) ||
      (((&g_MasterCardColorTable)
        [*(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0)) ||
     (((*(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0x10010) != 0 ||
      (((&DAT_006a5f69)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0)))) {
    uVar2 = 0;
    g_ActivePalette = iVar3;
    g_ActivePlayer = uVar1;
  }
  else {
    g_ActivePalette = 0;
    (**(code **)(&DAT_0051aec8 + *(int *)(&g_CardSlot_CardId + arg2 * 0x120 + arg1 * 0x5b20) * 0x34)
    )(arg1,arg2,0x79);
    if (g_ActivePalette == 0) {
      g_ActivePalette = iVar3;
      g_ActivePlayer = uVar1;
      if (g_ActivePlayerPriority == arg1) {
        Magic_PayManaCost();
        g_ActivePalette = 0;
        g_OverworldPlayerCoordX = arg1;
        g_OverworldMapGrid = arg2;
        CardQuery_ForEachPermanent(Pic_Subsystem_0042e80e,-1);
        iVar3 = g_ActivePalette;
        Magic_TapCardForMana();
        if (iVar3 != 0) {
          return 0;
        }
      }
      if ((*(int *)(&DAT_00680780 + (1 - arg1) * 4) != 0) &&
         (iVar3 = FUN_00473e69(arg1,arg2,0x79), iVar3 != 0)) {
        return 0;
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
      g_ActivePalette = iVar3;
      g_ActivePlayer = uVar1;
    }
  }
  return uVar2;
}


