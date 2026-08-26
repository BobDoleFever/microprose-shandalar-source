/*
 * Decompiled function: Town_Process_00509fd4
 * Entry Point: 00509fd4
 * Size: 145 bytes
 */
#include "magic.h"


void Town_Process_00509fd4(void)

{
  int iVar1;
  
  iVar1 = DAT_0062680c;
  FUN_0040eeb4(DAT_00626604,DAT_0062680c);
  *(undefined4 *)(&DAT_0067be48 + iVar1 * 100) = DAT_00641020;
  Ai_Subsystem_004c05ba();
  FUN_0040a566();
  Ai_Subsystem_004c3c5c(1);
  FUN_0040a95d(s_village_pic_00532308 + ((*(int *)(&DAT_0067bdf0 + iVar1 * 100) == 1) - 1 & 0xc));
  DAT_006265fc = 0xfffffffe;
  return;
}


