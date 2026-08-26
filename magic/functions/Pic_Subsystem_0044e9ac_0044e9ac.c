/*
 * Decompiled function: Pic_Subsystem_0044e9ac
 * Entry Point: 0044e9ac
 * Size: 497 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044e9ac(void)

{
  undefined1 uVar1;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x12; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x12; local_10 = local_10 + 1) {
      uVar1 = FUN_0040a1d2(0x10);
      (&DAT_0067a6c0)[local_10 + local_8 * 0x13] = uVar1;
    }
    (&DAT_0067a6d2)[local_8 * 0x13] = (&DAT_0067a6c0)[local_8 * 0x13];
  }
  for (local_10 = 0; local_10 < 0x12; local_10 = local_10 + 1) {
    (&DAT_0067a816)[local_10] = (&DAT_0067a6c0)[local_10];
  }
  for (local_8 = 0; local_8 < 0x11; local_8 = local_8 + 1) {
    for (local_10 = 0; local_10 < 0x11; local_10 = local_10 + 1) {
      for (local_c = 1; local_c < 9; local_c = local_c + 1) {
      }
      (&DAT_0067a830)[local_10 + local_8 * 0x13] = (&DAT_0067a6c0)[local_10 + local_8 * 0x13];
    }
  }
  for (local_8 = 0; local_8 < 0x11; local_8 = local_8 + 1) {
    (&DAT_0067a840)[local_8 * 0x13] = (&DAT_0067a830)[local_8 * 0x13];
  }
  for (local_10 = 0; local_10 < 0x11; local_10 = local_10 + 1) {
    (&DAT_0067a960)[local_10] = (&DAT_0067a830)[local_10];
  }
  return;
}


