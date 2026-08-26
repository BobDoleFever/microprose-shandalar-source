/*
 * Decompiled function: Pic_Subsystem_00451d90
 * Entry Point: 00451d90
 * Size: 176 bytes
 */
#include "magic.h"


int Pic_Subsystem_00451d90(uint arg1,uint arg2)

{
  bool bVar1;
  int iVar2;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = false;
    iVar2 = FUN_0040a1d2(g_MasterCardCount + -0x29);
    if (((arg1 == 0) || ((arg1 & (byte)(&g_MasterCardColorTable)[iVar2 * 0x34]) != 0)) &&
       ((arg2 == 1 || ((arg2 & (int)(char)(&DAT_0051aebe)[iVar2 * 0x34]) != 0)))) {
      bVar1 = true;
    }
  } while ((!bVar1) && (local_10 = local_10 + 1, local_10 < 999));
  return iVar2;
}


