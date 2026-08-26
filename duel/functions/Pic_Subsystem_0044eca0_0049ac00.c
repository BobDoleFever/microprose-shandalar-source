/*
 * Decompiled function: Pic_Subsystem_0044eca0
 * Entry Point: 0049ac00
 * Size: 341 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Pic_Subsystem_0044eca0(void)

{
  size_t sVar1;
  uint *puVar2;
  
  DAT_0060cc64 = 0xd;
  Mem_AllocOrFree_004d9630((uint *)&DAT_005dcb30,(uint *)s___SVG_00505930);
  Mem_AllocOrFree_004d9630((uint *)&DAT_005dcb40,(uint *)s_MTG_Gauntlet_Save_Game_00505938);
  puVar2 = (uint *)&DAT_005dcb30;
  sVar1 = _strlen(&DAT_005dcb40);
  FUN_004d9640((uint *)(sVar1 + 0x5dcb41),puVar2);
  puVar2 = (uint *)&DAT_00505950;
  sVar1 = _strlen(&DAT_005dcb40);
  FUN_004d9640((uint *)(sVar1 + 0x5dcb41),puVar2);
  Mem_AllocOrFree_004d9630((uint *)&DAT_005dcbb8,(uint *)&DAT_005dcb30);
  _DAT_00615300 = 0x4c;
  _DAT_00615304 = DAT_00618990;
  _DAT_00615308 = 0;
  _DAT_0061530c = &DAT_005dcb40;
  _DAT_00615310 = 0;
  _DAT_00615314 = 0;
  _DAT_00615318 = 0;
  DAT_0061531c = &DAT_005dcbb8;
  _DAT_00615320 = 0x104;
  _DAT_00615324 = &DAT_005dcb10;
  _DAT_00615328 = 0x1e;
  _DAT_0061532c = &DAT_00615350;
  _DAT_00615330 = s_Save_Game_00505954;
  _DAT_00615334 = 0x2a000c;
  _DAT_00615338 = 0;
  _DAT_0061533a = 0;
  _DAT_0061533c = &DAT_005dcb30;
  _DAT_00615340 = 0;
  _DAT_00615344 = 0;
  _DAT_00615348 = 0;
  return;
}


