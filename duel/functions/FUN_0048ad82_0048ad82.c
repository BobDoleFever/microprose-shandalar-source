/*
 * Decompiled function: FUN_0048ad82
 * Entry Point: 0048ad82
 * Size: 510 bytes
 */
#include "duel.h"


undefined4 FUN_0048ad82(int arg1,int arg2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = DAT_00681ea4;
  iVar3 = DAT_0066642c;
  if (((((&DAT_004ff595)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] == '\0') &&
       (((&DAT_006826f9)[arg2 * 0x120 + arg1 * 0x5b20] & 8) == 0)) ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34] & 2) == 0))
     || (((*(uint *)(&DAT_006826cc + arg2 * 0x120 + arg1 * 0x5b20) & 0x10010) != 0 ||
         (((&DAT_006826f9)[arg2 * 0x120 + arg1 * 0x5b20] & 0x80) != 0)))) {
    uVar2 = 0;
    DAT_0066642c = iVar3;
    DAT_00681ea4 = uVar1;
  }
  else {
    DAT_0066642c = 0;
    (**(code **)(&DAT_004ff5a0 + *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20) * 0x34))
              (arg1,arg2,0x79);
    if (DAT_0066642c == 0) {
      DAT_0066642c = iVar3;
      DAT_00681ea4 = uVar1;
      if (DAT_00676504 == arg1) {
        FUN_0048cac9();
        DAT_0066642c = 0;
        DAT_0068ecb0 = arg1;
        DAT_00690c48 = arg2;
        FUN_00467d65(FUN_004c1610,-1);
        iVar3 = DAT_0066642c;
        FUN_0048cb7f();
        if (iVar3 != 0) {
          return 0;
        }
      }
      if ((*(int *)(&DAT_006663e8 + (1 - arg1) * 4) != 0) &&
         (iVar3 = FUN_0048c50b(arg1,arg2,0x79), iVar3 != 0)) {
        return 0;
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
      DAT_0066642c = iVar3;
      DAT_00681ea4 = uVar1;
    }
  }
  return uVar2;
}


