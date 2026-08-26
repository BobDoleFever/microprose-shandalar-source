/*
 * Decompiled function: Ai_Subsystem_004bd563
 * Entry Point: 004bd563
 * Size: 71 bytes
 */
#include "magic.h"


bool Ai_Subsystem_004bd563(int arg1,int arg2)

{
  int iVar1;
  
  iVar1 = DAT_0052d5cc;
  if (0 < DAT_0052d5cc) {
    *(int *)(&DAT_00556b28 + (DAT_0052d5cc + -1) * 0x1c + arg1 * 4) =
         *(int *)(&DAT_00556b28 + (DAT_0052d5cc + -1) * 0x1c + arg1 * 4) + arg2;
  }
  return 0 < iVar1;
}


