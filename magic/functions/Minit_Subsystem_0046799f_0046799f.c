/*
 * Decompiled function: Minit_Subsystem_0046799f
 * Entry Point: 0046799f
 * Size: 201 bytes
 */
#include "magic.h"


void Minit_Subsystem_0046799f(void)

{
  int local_8;
  
  if (DAT_00538db4 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db4);
  }
  if (DAT_00538db0 != (HMENU)0x0) {
    DestroyMenu(DAT_00538db0);
  }
  DAT_00538db4 = (HMENU)0x0;
  DAT_00538db0 = (HMENU)0x0;
  if (DAT_00538df0 != (HCURSOR)0x0) {
    DestroyCursor(DAT_00538df0);
  }
  DAT_00538df0 = (HCURSOR)0x0;
  for (local_8 = 0; local_8 < DAT_00538ddc; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_00538dd0 + local_8 * 4) != 0) {
      DestroyCursor(*(HCURSOR *)(&DAT_00538dd0 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_00538dd0 + local_8 * 4) = 0;
  }
  return;
}


