/*
 * Decompiled function: FUN_00484e2d
 * Entry Point: 00484e2d
 * Size: 142 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00484e2d(int arg_1,undefined4 arg_2,undefined4 arg_3,int arg_4,undefined4 arg_5)

{
  _DAT_006ab814 = arg_1;
  if (arg_4 == 0) {
    _DAT_006ab81c = 0;
  }
  else {
    _DAT_006ab81c = 0x10;
  }
  _DAT_006ab838 = arg_5;
  DAT_006ab82e = 0xff;
  DAT_006ab82c = (&DAT_0051aebe)[arg_1 * 0x34];
  _DAT_006ab84c = 0x8000000;
  _DAT_006ab834 = 0;
  Mem_AllocOrFree_00484ebb(0,0x4f,arg_2,arg_3);
  _DAT_006ab814 = 0xffffffff;
  return;
}


