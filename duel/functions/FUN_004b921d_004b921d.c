/*
 * Decompiled function: FUN_004b921d
 * Entry Point: 004b921d
 * Size: 81 bytes
 */
#include "duel.h"


uint FUN_004b921d(void)

{
  uint uVar1;
  char local_7d4 [2000];
  
  local_7d4[0] = '\0';
  uVar1 = Palette_Color_00495430(local_7d4);
  Rules_ParseFilter_0048111e();
  DAT_0060cc70 = 1;
  return uVar1 | 1;
}


