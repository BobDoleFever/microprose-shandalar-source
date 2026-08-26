/*
 * Decompiled function: FUN_004821cf
 * Entry Point: 004821cf
 * Size: 202 bytes
 */
#include "duel.h"


void FUN_004821cf(void)

{
  int local_8;
  
  if (DAT_005dadac != (HMENU)0x0) {
    DestroyMenu(DAT_005dadac);
  }
  if (DAT_005dada8 != (HMENU)0x0) {
    DestroyMenu(DAT_005dada8);
  }
  DAT_005dadac = (HMENU)0x0;
  DAT_005dada8 = (HMENU)0x0;
  if (DAT_005dade8 != (HCURSOR)0x0) {
    DestroyCursor(DAT_005dade8);
  }
  DAT_005dade8 = (HCURSOR)0x0;
  for (local_8 = 0; local_8 < DAT_005dadd4; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_005dadc8 + local_8 * 4) != 0) {
      DestroyCursor(*(HCURSOR *)(&DAT_005dadc8 + local_8 * 4));
    }
    *(undefined4 *)(&DAT_005dadc8 + local_8 * 4) = 0;
  }
  return;
}


