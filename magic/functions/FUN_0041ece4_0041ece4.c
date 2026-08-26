/*
 * Decompiled function: FUN_0041ece4
 * Entry Point: 0041ece4
 * Size: 86 bytes
 */
#include "magic.h"


undefined4 FUN_0041ece4(int arg_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(arg_1 + 0x40);
  DAT_00680770 = 1;
  *(undefined4 *)(arg_1 + 0x40) = 0;
  (**(code **)(arg_1 + 0x24))(arg_1,3);
  DAT_00680770 = 0;
  *(undefined4 *)(arg_1 + 0x40) = 3;
  return uVar1;
}


