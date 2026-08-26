/*
 * Decompiled function: FUN_0043d81d
 * Entry Point: 0043d81d
 * Size: 59 bytes
 */
#include "duel.h"


int FUN_0043d81d(void)

{
  int iVar1;
  
  iVar1 = __read(DAT_00516924,&g_MasterCardCount,0x200);
  DAT_0069453c = &g_MasterCardCount;
  return iVar1;
}


