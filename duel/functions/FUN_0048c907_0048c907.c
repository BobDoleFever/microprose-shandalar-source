/*
 * Decompiled function: FUN_0048c907
 * Entry Point: 0048c907
 * Size: 291 bytes
 */
#include "duel.h"


int FUN_0048c907(int arg_1,int arg_2,int arg_3,undefined4 arg_4,undefined4 arg_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) {
    iVar2 = 0;
  }
  else {
    FUN_0048cac9();
    uVar1 = DAT_00676500;
    DAT_0066642c = 0;
    DAT_0068ecb0 = arg_1;
    DAT_00690c48 = arg_2;
    DAT_00690310 = arg_4;
    DAT_0068ecfc = arg_5;
    iVar2 = (**(code **)(&DAT_004ff5a0 +
                        *(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34))
                      (arg_1,arg_2,arg_3);
    if ((((iVar2 != 99) && ((DAT_00681eb0 & 0x224) != 0)) && ((arg_3 == 0x74 || (arg_3 == 0x73))))
       && (iVar3 = FUN_0048ca2a(arg_1,arg_2), iVar3 == 0)) {
      DAT_00676500 = uVar1;
      FUN_0048cb7f();
      return 0;
    }
    DAT_0068edd8 = DAT_0066642c;
    FUN_0048cb7f();
  }
  return iVar2;
}


