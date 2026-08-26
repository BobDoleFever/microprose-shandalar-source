/*
 * Decompiled function: FUN_00476a80
 * Entry Point: 00476a80
 * Size: 142 bytes
 */
#include "magic.h"


void FUN_00476a80(void)

{
  int iVar1;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[local_8]; local_c = local_c + 1) {
      iVar1 = FUN_00471c32(local_8,local_c);
      if (iVar1 != 0) {
        *(undefined4 *)(&g_CardSlot_SpecialState + local_c * 0x120 + local_8 * 0x5b20) = 0;
      }
    }
  }
  return;
}


