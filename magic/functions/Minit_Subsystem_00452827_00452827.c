/*
 * Decompiled function: Minit_Subsystem_00452827
 * Entry Point: 00452827
 * Size: 141 bytes
 */
#include "magic.h"


int Minit_Subsystem_00452827(void)

{
  int local_c;
  int local_8;
  
  local_c = 0;
  for (local_8 = 0; local_8 < 0x80; local_8 = local_8 + 1) {
    if ((((*(uint *)(&DAT_0067be00 + local_8 * 100) & 0xff01) == 1) &&
        (1 < *(int *)(&DAT_0067bdf0 + local_8 * 100))) &&
       (*(int *)(&DAT_0067bdf0 + local_8 * 100) < 4)) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}


