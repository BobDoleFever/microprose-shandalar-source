/*
 * Decompiled function: Pic_Subsystem_0042a0d6
 * Entry Point: 0042a0d6
 * Size: 243 bytes
 */
#include "magic.h"


void Pic_Subsystem_0042a0d6(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  int iVar2;
  
  if (((arg_3 == 0x7f) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
    iVar1 = FUN_0041d9d2(arg_1,arg_2,5);
    *(int *)(&DAT_006330d0 + iVar1 * 4) = *(int *)(&DAT_006330d0 + iVar1 * 4) + 3;
  }
  if ((((arg_3 != 0x74) && ((arg_3 == 0x6c || (arg_3 == 199)))) && (g_OverworldMapGrid == arg_2)) &&
     (g_OverworldPlayerCoordX == arg_1)) {
    iVar1 = FUN_0041d9d2(arg_1,arg_2,5);
    iVar1 = *(int *)(&DAT_0063ee30 + iVar1 * 4 + (1 - arg_1) * 0x20);
    iVar2 = FUN_0041d9d2(arg_1,arg_2,5);
    g_SpellStackDepth =
         g_SpellStackDepth +
         ((iVar1 + *(int *)(&DAT_0063ee30 + iVar2 * 4 + arg_1 * 0x20) * -2) * 3 + 3) * 4;
  }
  return;
}


