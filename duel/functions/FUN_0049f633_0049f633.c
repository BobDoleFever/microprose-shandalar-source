/*
 * Decompiled function: FUN_0049f633
 * Entry Point: 0049f633
 * Size: 100 bytes
 */
#include "duel.h"


void FUN_0049f633(int arg_1)

{
  char cVar1;
  size_t sVar2;
  int local_10;
  
  if (arg_1 != -1) {
    local_10 = 0;
    sVar2 = _strlen(&DAT_005f6810);
    do {
      cVar1 = (&DAT_00507370)[arg_1 * 0x44 + local_10];
      (&DAT_005f6810)[local_10 + sVar2] = cVar1;
      local_10 = local_10 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


