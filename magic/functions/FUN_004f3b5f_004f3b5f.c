/*
 * Decompiled function: FUN_004f3b5f
 * Entry Point: 004f3b5f
 * Size: 104 bytes
 */
#include "magic.h"


undefined4 FUN_004f3b5f(int arg_1,int arg_2,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  
  if (((arg_1 == 0) || (arg_2 == 0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,local_1c);
    uVar1 = FUN_004f3bc7((HDC)arg_1,(int *)arg_2,arg_3,0,0,local_18,local_14);
  }
  return uVar1;
}


