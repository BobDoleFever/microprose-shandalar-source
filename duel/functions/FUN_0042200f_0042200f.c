/*
 * Decompiled function: FUN_0042200f
 * Entry Point: 0042200f
 * Size: 682 bytes
 */
#include "duel.h"


void FUN_0042200f(int arg_1,char arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  if (((arg_1 != 0) && (-0x13 < arg_2)) && (arg_2 < '\0')) {
    GetObjectA(DAT_0050b204,0x18,local_3c);
    local_20 = local_34;
    local_24 = local_34;
    local_8 = local_38 - local_34;
    if (arg_2 == -0x10) {
      local_1c = 0;
    }
    else if (arg_2 == -0xf) {
      local_1c = local_34;
    }
    else if (arg_2 == -0xe) {
      local_1c = local_34 * 2;
    }
    else if (arg_2 == -0xd) {
      local_1c = local_34 * 3;
    }
    else if (arg_2 == -0xc) {
      local_1c = local_34 << 2;
    }
    else if (arg_2 == -0xb) {
      local_1c = local_34 * 5;
    }
    else if (arg_2 == -10) {
      local_1c = local_34 * 6;
    }
    else if (arg_2 == -9) {
      local_1c = local_34 * 7;
    }
    else if (arg_2 == -8) {
      local_1c = local_34 << 3;
    }
    else if (arg_2 == -7) {
      local_1c = local_34 * 9;
    }
    else if (arg_2 == -6) {
      local_1c = local_34 * 10;
    }
    else if (arg_2 == -0x11) {
      local_1c = local_34 * 0xb;
    }
    else if (arg_2 == -5) {
      local_1c = local_34 * 0xc;
    }
    else if (arg_2 == -4) {
      local_1c = local_34 * 0xd;
    }
    else if (arg_2 == -3) {
      local_1c = local_34 * 0xe;
    }
    else if (arg_2 == -2) {
      local_1c = local_34 * 0xf;
    }
    else if (arg_2 == -1) {
      local_1c = local_34 << 4;
    }
    else if (arg_2 == -0x12) {
      local_1c = local_34 * 0x11;
    }
    SetRect(&local_18,arg_3,arg_4,arg_5 + arg_3,arg_6 + arg_4);
    FUN_00470cfa((HDC)arg_1,&local_18.left,DAT_0050b204,local_20,local_24,local_1c,0,local_8,0);
  }
  return;
}


