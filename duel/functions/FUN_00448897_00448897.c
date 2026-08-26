/*
 * Decompiled function: FUN_00448897
 * Entry Point: 00448897
 * Size: 227 bytes
 */
#include "duel.h"


void FUN_00448897(int x,int *y,int width,int *height)

{
  undefined4 uVar1;
  int local_8;
  
  if ((((x != 0) && (y != (int *)0x0)) && (width != 0)) && (height != (int *)0x0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    *y = DAT_006152dc;
    for (local_8 = 0; local_8 < DAT_006152dc; local_8 = local_8 + 1) {
      uVar1 = CardIDFromType(*(uint *)(&DAT_00664640 + local_8 * 4));
      *(undefined4 *)(x + local_8 * 4) = uVar1;
    }
    *height = DAT_00664db4;
    for (local_8 = 0; local_8 < DAT_00664db4; local_8 = local_8 + 1) {
      uVar1 = CardIDFromType(*(uint *)(&DAT_00664d50 + local_8 * 4));
      *(undefined4 *)(width + local_8 * 4) = uVar1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
  }
  return;
}


