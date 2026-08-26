/*
 * Decompiled function: FUN_00454a2b
 * Entry Point: 00454a2b
 * Size: 158 bytes
 */
#include "duel.h"


undefined4 FUN_00454a2b(int arg_1,int arg_2,int arg_3)

{
  uint uVar1;
  
  if ((((arg_3 == 0x78) && (arg_2 == DAT_0068ecfc)) && (arg_1 == DAT_00690310)) &&
     ((&DAT_004ff595)[*(int *)(&DAT_006826c4 + DAT_00690c48 * 0x120 + DAT_0068ecb0 * 0x5b20) * 0x34]
      != '\0')) {
    uVar1 = FUN_0048b81a(DAT_0068ecb0,DAT_00690c48,0x34,0xffffffff);
    if ((uVar1 & 0x20) == 0) {
      DAT_0066642c = 1;
    }
  }
  return 0;
}


