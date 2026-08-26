/*
 * Decompiled function: Palette_Subsystem_004a75bd
 * Entry Point: 004a75bd
 * Size: 147 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a75bd(int arg_1)

{
  int arg2;
  int local_c;
  int local_8;
  
  local_8 = 0;
  while ((local_8 < 500 && (*(int *)(&DAT_0069e730 + local_8 * 4 + arg_1 * 2000) != -1))) {
    local_8 = local_8 + 1;
  }
  arg2 = FUN_0040a1d2(local_8);
  local_c = Palette_Subsystem_004a7650(arg_1,arg2);
  if (local_c == 0) {
    local_c = Palette_Subsystem_004a7650(arg_1,0);
  }
  return local_c;
}


