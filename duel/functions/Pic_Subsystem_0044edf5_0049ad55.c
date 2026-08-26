/*
 * Decompiled function: Pic_Subsystem_0044edf5
 * Entry Point: 0049ad55
 * Size: 270 bytes
 */
#include "duel.h"


void Pic_Subsystem_0044edf5(undefined4 arg_1)

{
  undefined4 uVar1;
  uint local_10c [66];
  
  uVar1 = DAT_0068f2c4;
  if (((byte)DAT_00663dfc & 1) == 0) {
    DAT_0068f2c4 = arg_1;
    Mem_AllocOrFree_004d9630(local_10c,(uint *)&DAT_00615350);
    FUN_004d9640(local_10c,(uint *)s__AUTOSAVE_00505960);
    FUN_004d9640(local_10c,(uint *)&DAT_005dcb31);
    FUN_00433caa((char *)local_10c);
  }
  if ((((byte)DAT_00663dfc & 1) != 0) && (DAT_00601618 != 0)) {
    DAT_0068f2c4 = arg_1;
    Mem_AllocOrFree_004d9630(local_10c,(uint *)&DAT_00615350);
    FUN_004d9640(local_10c,(uint *)s__SHANDSAVE_0050596c);
    FUN_004d9640(local_10c,(uint *)&DAT_005dcb31);
    FUN_00433caa((char *)local_10c);
  }
  DAT_0068f2c4 = uVar1;
  return;
}


