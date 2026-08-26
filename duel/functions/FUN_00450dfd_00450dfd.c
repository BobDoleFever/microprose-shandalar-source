/*
 * Decompiled function: FUN_00450dfd
 * Entry Point: 00450dfd
 * Size: 135 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00450dfd(int arg_1,int arg_2,undefined4 arg_3)

{
  if (arg_2 == 0) {
    _DAT_00687fac = 0;
  }
  else {
    _DAT_00687fac = 0x10;
  }
  _DAT_00687fc8 = arg_3;
  DAT_00687fbe = 0xff;
  DAT_00687fbc = (&DAT_004ff596)[arg_1 * 0x34];
  _DAT_00687fdc = *(undefined4 *)(&DAT_004ff5a4 + arg_1 * 0x34);
  _DAT_00687fa4 = 0xffffffff;
  return 0x4f;
}


