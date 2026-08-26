/*
 * Decompiled function: Pic_Subsystem_0043452e
 * Entry Point: 0043452e
 * Size: 123 bytes
 */
#include "magic.h"


undefined4 Pic_Subsystem_0043452e(int x,int arg_2,int arg_3,int arg_4)

{
  uint arg_5;
  undefined4 uVar1;
  uint local_10;
  uint local_c;
  uint local_8;
  
  arg_5 = FUN_00473179(arg_3,arg_4,0x34,0xffffffff);
  Ai_FilterValidBlockers(&local_8,&local_c);
  if (x == 1) {
    local_10 = local_8;
  }
  else {
    local_10 = local_c;
  }
  uVar1 = FUN_00472c0c(x,arg_2,arg_3,arg_4,arg_5,local_10);
  return uVar1;
}


