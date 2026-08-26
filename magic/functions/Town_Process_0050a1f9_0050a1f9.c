/*
 * Decompiled function: Town_Process_0050a1f9
 * Entry Point: 0050a1f9
 * Size: 105 bytes
 */
#include "magic.h"


void Town_Process_0050a1f9(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  Town_Process_00490d7b(1);
  Ai_Subsystem_004c05ba();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_005323a4 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}


