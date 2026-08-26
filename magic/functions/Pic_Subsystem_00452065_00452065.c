/*
 * Decompiled function: Pic_Subsystem_00452065
 * Entry Point: 00452065
 * Size: 77 bytes
 */
#include "magic.h"


void Pic_Subsystem_00452065(int arg_1)

{
  int local_8;
  
  while (local_8 = arg_1 + 1, local_8 < 500) {
    (&DAT_0070214c)[local_8] = *(undefined4 *)(&deck + local_8 * 4);
    arg_1 = local_8;
  }
  DAT_0070291c = 0xffffffff;
  return;
}


