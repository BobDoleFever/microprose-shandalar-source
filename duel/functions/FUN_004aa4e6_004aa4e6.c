/*
 * Decompiled function: FUN_004aa4e6
 * Entry Point: 004aa4e6
 * Size: 126 bytes
 */
#include "duel.h"


bool FUN_004aa4e6(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  
  if (arg_3 == 0x74) {
    if (arg_1 == DAT_00676510) {
      bVar1 = true;
    }
    else {
      bVar1 = arg_1 != DAT_00666458;
    }
  }
  else {
    if (arg_3 == 0x71) {
      FUN_00467d65(FUN_004aa569,-1);
      FUN_0046e571(arg_1,arg_2,1);
    }
    bVar1 = false;
  }
  return bVar1;
}


