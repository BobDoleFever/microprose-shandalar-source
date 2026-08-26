/*
 * Decompiled function: FUN_004632c5
 * Entry Point: 004632c5
 * Size: 340 bytes
 */
#include "duel.h"


undefined4 FUN_004632c5(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  
  if (((arg_3 == 0x15) && (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 4) != 0)) &&
     (*(int *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)) {
    *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
    bVar1 = false;
    iVar2 = FUN_0049b309(arg_1,7,2);
    if (iVar2 != 0) {
      iVar2 = FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,s_Pay_2_mana__Lose_3_life__004f8ca0,0);
      if (iVar2 == 0) {
        FUN_0042b6b0(arg_1,0,2);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          bVar1 = true;
        }
      }
    }
    if (!bVar1) {
      Mem_AllocOrFree_004afd1c(arg_1,3,arg_1,arg_2);
    }
  }
  if (arg_3 == 0x22) {
    *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
  }
  return 0;
}


