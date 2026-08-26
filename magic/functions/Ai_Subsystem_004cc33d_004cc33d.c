/*
 * Decompiled function: Ai_Subsystem_004cc33d
 * Entry Point: 004cc33d
 * Size: 135 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Ai_Subsystem_004cc33d(int arg_1,int arg_2,undefined4 arg_3)

{
  if (arg_2 == 0) {
    _DAT_006ab81c = 0;
  }
  else {
    _DAT_006ab81c = 0x10;
  }
  _DAT_006ab838 = arg_3;
  DAT_006ab82e = 0xff;
  DAT_006ab82c = (&DAT_0051aebe)[arg_1 * 0x34];
  _DAT_006ab84c = *(undefined4 *)(&DAT_0051aecc + arg_1 * 0x34);
  _DAT_006ab814 = 0xffffffff;
  return 0x4f;
}


