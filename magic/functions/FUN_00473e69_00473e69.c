/*
 * Decompiled function: FUN_00473e69
 * Entry Point: 00473e69
 * Size: 157 bytes
 */
#include "magic.h"


undefined4 FUN_00473e69(int arg_1,undefined4 arg_2,int arg_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  Magic_PayManaCost();
  uVar2 = g_PlayerManaPool;
  g_ActivePalette = 0;
  g_OverworldPlayerCoordX = arg_1;
  g_OverworldMapGrid = arg_2;
  DAT_007006c8 = 1 - arg_1;
  DAT_006b2d5c = 0xffffffff;
  if ((arg_3 != 0x7d) && (arg_3 != 0x7e)) {
    g_PlayerManaPool = 0xffffffff;
  }
  Magic_ScanCards(arg_3);
  uVar1 = g_ActivePalette;
  g_OverworldPlayerCoordX = 0xffffffff;
  g_PlayerManaPool = uVar2;
  Magic_TapCardForMana();
  return uVar1;
}


