/*
 * Decompiled function: FUN_004479d5
 * Entry Point: 004479d5
 * Size: 161 bytes
 */
#include "duel.h"


void FUN_004479d5(int x,int y,int *width,int *height)

{
  int iVar1;
  
  if (((width != (int *)0x0) && (height != (int *)0x0)) && (iVar1 = FUN_00446de2(x,y), iVar1 == 0))
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *width = (int)*(short *)(&DAT_00601638 + y * 0x120 + x * 0x5b20);
    *height = (int)*(short *)(&DAT_0060163a + y * 0x120 + x * 0x5b20);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}


