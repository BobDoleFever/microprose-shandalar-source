/*
 * Decompiled function: FUN_004d7460
 * Entry Point: 004d7460
 * Size: 176 bytes
 */
#include "duel.h"


int FUN_004d7460(uint arg1,uint arg2)

{
  bool bVar1;
  int iVar2;
  int local_10;
  
  local_10 = 0;
  do {
    bVar1 = false;
    iVar2 = FUN_00439892(DAT_00665ed0 + -0x29);
    if (((arg1 == 0) || ((arg1 & (byte)(&DAT_004ff594)[iVar2 * 0x34]) != 0)) &&
       ((arg2 == 1 || ((arg2 & (int)(char)(&DAT_004ff596)[iVar2 * 0x34]) != 0)))) {
      bVar1 = true;
    }
  } while ((!bVar1) && (local_10 = local_10 + 1, local_10 < 999));
  return iVar2;
}


