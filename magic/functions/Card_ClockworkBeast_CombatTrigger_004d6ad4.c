/*
 * Decompiled function: Card_ClockworkBeast_CombatTrigger
 * Entry Point: 004d6ad4
 * Size: 367 bytes
 */
#include "magic.h"


undefined4 Card_ClockworkBeast_CombatTrigger(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  int local_8;
  
  if (((arg_3 == 0x34) && (arg_2 == g_OverworldMapGrid)) && (arg_1 == g_OverworldPlayerCoordX)) {
    cVar1 = FUN_0041d963(arg_1,arg_2,4);
    g_ActivePalette = g_ActivePalette | 0x800 << (cVar1 - 1U & 0x1f);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) &&
     ((arg_2 == g_OverworldMapGrid && (arg_1 == g_OverworldPlayerCoordX)))) {
    iVar3 = FUN_0041d9d2(arg_1,arg_2,5);
    bVar4 = *(int *)(&DAT_0063ee30 + iVar3 * 4 + (1 - arg_1) * 0x20) != 0;
    if (!bVar4) {
      for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
        iVar3 = FUN_00471c32(1 - arg_1,local_8);
        if ((iVar3 != 0) &&
           (cVar1 = (&DAT_006a5f4c)[local_8 * 0x120 + (1 - arg_1) * 0x5b20],
           bVar2 = FUN_0041d9d2(arg_1,arg_2,5), (1 << (bVar2 & 0x1f) & (int)cVar1) != 0)) {
          bVar4 = true;
          break;
        }
      }
    }
    if (bVar4) {
      g_ActivePalette = g_ActivePalette + 1;
    }
  }
  return 0;
}


