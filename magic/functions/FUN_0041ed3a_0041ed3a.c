/*
 * Decompiled function: FUN_0041ed3a
 * Entry Point: 0041ed3a
 * Size: 76 bytes
 */
#include "magic.h"


undefined4 FUN_0041ed3a(int arg_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(arg_1 + 0x40);
  *(undefined4 *)(arg_1 + 0x40) = 0;
  DAT_00680770 = 1;
  (**(code **)(arg_1 + 0x24))(arg_1,0);
  DAT_00680770 = 0;
  return uVar1;
}


