/*
 * Decompiled function: Ai_Subsystem_004be49b
 * Entry Point: 004be49b
 * Size: 138 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Ai_Subsystem_004be49b(int x,int y,int *width,int *height)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((y - _DAT_00641880) - (x - _DAT_0064187c)) * DAT_0052245c;
  iVar2 = DAT_005574ac / 2;
  *width = (((y - _DAT_00641880) + (x - _DAT_0064187c)) * DAT_00522458 * 2) / 0x280 +
           DAT_00557478 / 2;
  *height = iVar1 / 0x1e0 + iVar2 + DAT_0052d77c;
  return;
}


