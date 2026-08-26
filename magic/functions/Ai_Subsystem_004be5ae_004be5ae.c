/*
 * Decompiled function: Ai_Subsystem_004be5ae
 * Entry Point: 004be5ae
 * Size: 149 bytes
 */
#include "magic.h"


void Ai_Subsystem_004be5ae(int x,int y,int *width,int *height)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (((y - DAT_0052d77c) - DAT_005574ac / 2) * 0x1e0) / DAT_0052245c;
  iVar2 = ((x - DAT_00557478 / 2) * 0x280) / DAT_00522458 >> 1;
  *width = DAT_006498d8 + (iVar2 - iVar1) / 2;
  *height = DAT_006498dc + (iVar2 + iVar1) / 2;
  return;
}


