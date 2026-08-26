/*
 * Decompiled function: FUN_0048a07d
 * Entry Point: 0048a07d
 * Size: 330 bytes
 */
#include "duel.h"


undefined4 FUN_0048a07d(int arg1,int arg2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_14;
  
  if ((((&DAT_004ff5a9)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 0x10) == 0)
     || (DAT_0068f0f4 == -1)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (DAT_00681ea4 != 1) {
    if ((!bVar1) && (DAT_006664ec == 0)) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Activate_004fb044);
      FUN_0044a5a4(arg1,arg2);
      if ((DAT_0068eee4 == 0) || (DAT_00676510 != arg1)) {
        local_14 = -2;
      }
      else {
        local_14 = -1;
      }
      FUN_0048e32b(local_14,DAT_0068f2c4,&DAT_005f6810,0x6d);
    }
    FUN_0048dd43();
    uVar3 = DAT_0068edd0;
    uVar2 = DAT_00666754;
    DAT_00666754 = arg1;
    DAT_0068edd0 = arg2;
    FUN_0048e8a8(DAT_00666458,0xd2,s_Tapping_004fb050,0);
    DAT_00666754 = uVar2;
    DAT_0068edd0 = uVar3;
  }
  return 1;
}


