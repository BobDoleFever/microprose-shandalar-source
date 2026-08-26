/*
 * Decompiled function: FUN_0048c367
 * Entry Point: 0048c367
 * Size: 121 bytes
 */
#include "duel.h"


undefined4 FUN_0048c367(byte arg_1)

{
  undefined4 uVar1;
  
  if ((arg_1 & 2) == 0) {
    if ((arg_1 & 4) == 0) {
      if ((arg_1 & 8) == 0) {
        if ((arg_1 & 0x10) == 0) {
          if ((arg_1 & 0x20) == 0) {
            uVar1 = 0;
          }
          else {
            uVar1 = 5;
          }
        }
        else {
          uVar1 = 4;
        }
      }
      else {
        uVar1 = 3;
      }
    }
    else {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


