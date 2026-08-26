/*
 * Decompiled function: FUN_004f3e29
 * Entry Point: 004f3e29
 * Size: 129 bytes
 */
#include "magic.h"


undefined4 FUN_004f3e29(HDC arg_1,int *arg_2,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_34 [4];
  int local_30;
  int local_2c;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  GetObjectA(arg_3,0x18,local_34);
  local_18 = local_30 / 2;
  local_1c = local_2c;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_8 = local_18;
  uVar1 = FUN_004f3eaa(arg_1,arg_2,arg_3,local_18,local_2c,0,0,local_18,0);
  return uVar1;
}


