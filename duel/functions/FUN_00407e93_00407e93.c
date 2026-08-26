/*
 * Decompiled function: FUN_00407e93
 * Entry Point: 00407e93
 * Size: 380 bytes
 */
#include "duel.h"


undefined4 FUN_00407e93(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      if ((DAT_00676510 == arg_1) && (DAT_0066aaf4 != 1)) {
        local_8 = Palette_Subsystem_004a5722
                            (arg_1,(int *)(&DAT_0068f370 + arg_1 * 2000),500,
                             s_Pick_a_creature_004f261c,1,&DAT_004f2618);
      }
      else {
        local_8 = FUN_0040800f(arg_1,2);
      }
      if (((local_8 != -1) && (*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) != -1)) &&
         (((&DAT_004ff594)[*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) * 0x34] & 2) != 0))
      {
        iVar2 = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000));
        if (iVar2 != -1) {
          *(undefined4 *)(&DAT_006826cc + iVar2 * 0x120 + arg_1 * 0x5b20) = 0x30002;
        }
        *(undefined4 *)(&DAT_0068f370 + local_8 * 4 + arg_1 * 2000) = 0xffffffff;
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}


