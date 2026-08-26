/*
 * Decompiled function: Palette_Subsystem_00496ccf
 * Entry Point: 00496ccf
 * Size: 81 bytes
 */
#include "magic.h"


uint Palette_Subsystem_00496ccf(void)

{
  uint uVar1;
  char local_7d4 [2000];
  
  local_7d4[0] = '\0';
  uVar1 = Palette_Color_00495430(local_7d4);
  Rules_ParseFilter_004ffedf();
  DAT_00695ea4 = 1;
  return uVar1 | 1;
}


