/*
 * Decompiled function: Ai_Subsystem_004be43f
 * Entry Point: 004be43f
 * Size: 92 bytes
 */
#include "magic.h"


void Ai_Subsystem_004be43f(int x,int y,int *width,int *height)

{
  int iVar1;
  
  iVar1 = (y - x) * DAT_0052245c;
  *width = ((y + x) * DAT_00522458 * 2) / 0x280;
  *height = iVar1 / 0x1e0;
  return;
}


