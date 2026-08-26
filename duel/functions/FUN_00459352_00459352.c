/*
 * Decompiled function: FUN_00459352
 * Entry Point: 00459352
 * Size: 171 bytes
 */
#include "duel.h"


undefined4 FUN_00459352(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x70) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if (iVar1 != 0) {
      iVar1 = FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,s_Regenerate_Living_Wall__Don_t_re_004f8964,0);
      if (iVar1 == 0) {
        FUN_0042b6b0(arg_1,0,1);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          DAT_0066642c = DAT_0066642c + 1;
        }
      }
    }
  }
  return 0;
}


