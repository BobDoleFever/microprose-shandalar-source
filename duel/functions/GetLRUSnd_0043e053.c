/*
 * Decompiled function: GetLRUSnd
 * Entry Point: 0043e053
 * Size: 73 bytes
 */
#include "duel.h"


undefined4 GetLRUSnd(undefined4 arg_1,undefined4 arg_2,undefined4 arg_3)

{
  undefined4 uVar1;
  
  if ((DAT_004f79a4 == 0) || (DAT_004f79a4 == 2)) {
    uVar1 = 4;
  }
  else {
    uVar1 = (*DAT_00694538)(arg_1,arg_2,arg_3);
  }
  return uVar1;
}


