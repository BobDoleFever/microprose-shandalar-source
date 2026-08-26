/*
 * Decompiled function: FUN_004328ba
 * Entry Point: 004328ba
 * Size: 329 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004328ba(int arg_1)

{
  int iVar1;
  uint local_8;
  
  DAT_00515e80 = 1;
  iVar1 = Mem_AllocOrFree_00432c72();
  if (iVar1 == -1) {
    iVar1 = -1;
  }
  else {
    if (arg_1 == -1) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_004f4458);
      _DAT_0068f0c0 = 0;
      for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
        s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(local_8);
        iVar1 = FUN_00432a0b(s_D_MAGIC0_SVE_004f4350,1);
        if (iVar1 != 0) {
          _DAT_0068f0c0 = _DAT_0068f0c0 | 1 << ((byte)local_8 & 0x1f);
        }
      }
      DAT_006669e0 = 0;
      if ((_DAT_0068f0c0 & 1) == 0) {
        DAT_006669e0 = -1;
      }
    }
    else {
      DAT_006669e0 = arg_1;
    }
    if (DAT_006669e0 != -1) {
      s_D_MAGIC0_SVE_004f4350[7] = FUN_00432860(DAT_006669e0);
      iVar1 = FUN_00432a0b(s_D_MAGIC0_SVE_004f4350,0);
      if (iVar1 == 0) {
        DAT_006669e0 = -1;
      }
    }
    iVar1 = DAT_006669e0;
    if (DAT_006669e0 == -1) {
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
  }
  return iVar1;
}


