/*
 * Decompiled function: FUN_004010b7
 * Entry Point: 004010b7
 * Size: 46 bytes
 */
#include "duel.h"


void FUN_004010b7(void)

{
  if (DAT_0050abb4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050abb4);
  }
  DAT_0050abb4 = (HGDIOBJ)0x0;
  return;
}


