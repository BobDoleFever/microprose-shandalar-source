/*
 * Decompiled function: FUN_0048a1c7
 * Entry Point: 0048a1c7
 * Size: 262 bytes
 */
#include "duel.h"


undefined4 FUN_0048a1c7(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  
  DAT_006663f4 = 1;
  FUN_0048d878(arg_1,arg_2,0x7e,arg_3,0);
  if (DAT_00681ea4 == 1) {
    FUN_0048e251();
    uVar1 = 0;
  }
  else {
    if (DAT_0066aaf4 != 1) {
      FUN_0048dc9e();
      if (DAT_00676510 != DAT_00681ec4) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_00666500);
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_processes____004fb058);
        FUN_00446c16(arg_1,arg_2,-1,-1,&DAT_005f6810,0);
      }
    }
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Process_004fb068);
    FUN_0044a5a4(arg_1,arg_2);
    uVar1 = FUN_0048dd43();
  }
  DAT_006663f4 = 0;
  return uVar1;
}


