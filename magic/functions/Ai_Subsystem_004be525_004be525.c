/*
 * Decompiled function: Ai_Subsystem_004be525
 * Entry Point: 004be525
 * Size: 137 bytes
 */
#include "magic.h"


void Ai_Subsystem_004be525(int x,int y,int *width,int *height)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((y - DAT_006498dc) - (x - DAT_006498d8)) * DAT_0052245c;
  iVar2 = DAT_005574ac / 2;
  *width = (((y - DAT_006498dc) + (x - DAT_006498d8)) * DAT_00522458 * 2) / 0x280 + DAT_00557478 / 2
  ;
  *height = DAT_0052d77c + iVar1 / 0x1e0 + iVar2;
  return;
}


