/*
 * Decompiled function: FUN_0048b24e
 * Entry Point: 0048b24e
 * Size: 123 bytes
 */
#include "duel.h"


undefined4 FUN_0048b24e(int x,int arg_2,int arg_3,int arg_4)

{
  uint arg_5;
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  
  arg_5 = FUN_0048b81a(arg_3,arg_4,0x34,0xffffffff);
  FUN_00431f41(&local_8,&local_c);
  if (x == 1) {
    local_10 = local_8;
  }
  else {
    local_10 = local_c;
  }
  uVar1 = FUN_0048b2c9(x,arg_2,arg_3,arg_4,arg_5,local_10);
  return uVar1;
}


