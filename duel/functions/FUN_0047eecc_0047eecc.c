/*
 * Decompiled function: FUN_0047eecc
 * Entry Point: 0047eecc
 * Size: 325 bytes
 */
#include "duel.h"


void FUN_0047eecc(int arg_1,int arg_2,int arg_3)

{
  int *arg_3_00;
  undefined4 local_1c;
  undefined4 local_14;
  
  if (DAT_004f9d4c == 0) {
    local_1c = _malloc(0x32000);
    DAT_00690c5c = local_1c;
    DAT_00690c58 = _malloc(0x32000);
    DAT_004f9d4c = 1;
  }
  else {
    local_1c = DAT_00690c5c;
  }
  arg_3_00 = DAT_00690c58;
  for (local_14 = arg_3; local_14 < arg_2; local_14 = local_14 << 1) {
    FUN_0047f011((int *)arg_1,(int *)(local_14 * local_14 * 4 + arg_1),local_1c,local_14,local_14,
                 local_14 * 2,local_14);
    FUN_0047f011((int *)(local_14 * local_14 * 8 + arg_1),(int *)(local_14 * local_14 * 0xc + arg_1)
                 ,arg_3_00,local_14,local_14,local_14 * 2,local_14);
    FUN_0047f0e6(local_1c,arg_3_00,(int *)arg_1,local_14,local_14 * 2,local_14 * 2,local_14 * 2);
  }
  return;
}


