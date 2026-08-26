/*
 * Decompiled function: FUN_00433caa
 * Entry Point: 00433caa
 * Size: 155 bytes
 */
#include "duel.h"


void FUN_00433caa(char *str_1)

{
  DAT_00515e88 = __open(str_1,0x8301,0x80);
  if (DAT_00515e88 != -1) {
    DAT_00515e80 = 0;
    FUN_00433bb6(&DAT_0060cc64,4);
    FUN_00432e04();
    FUN_00433bb6(&_PlayerFace,4);
    FUN_00433bb6(&_OpponFace,4);
    FUN_00433bb6(&DAT_00664b90,0x32);
    FUN_00433bb6(&DAT_006015b0,0x32);
    __close(DAT_00515e88);
  }
  return;
}


