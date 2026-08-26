/*
 * Decompiled function: FUN_0042aa48
 * Entry Point: 0042aa48
 * Size: 287 bytes
 */
#include "duel.h"


bool FUN_0042aa48(int arg_1)

{
  int iVar1;
  bool bVar2;
  int local_c;
  
  if (DAT_0066aaf4 == 1) {
    bVar2 = false;
  }
  else if (DAT_0068eee4 == 0) {
    iVar1 = FUN_0046d140();
    if (iVar1 == 0) {
      bVar2 = false;
    }
    else if (DAT_00666424 == 0) {
      bVar2 = false;
    }
    else {
      if ((arg_1 < 2) || (5 < arg_1)) {
        if ((arg_1 < 0x20) || (0x25 < arg_1)) {
          if ((arg_1 < 2) || (5 < arg_1)) {
            local_c = arg_1;
          }
          else {
            local_c = 4;
          }
        }
        else {
          local_c = 0x20;
        }
      }
      else {
        local_c = 4;
      }
      bVar2 = DAT_0066ab04 == local_c;
      if ((DAT_0066ab04 == -1) && (((&DAT_006667c0)[local_c * 4 + DAT_00666458 * 0x98] & 1) != 0)) {
        bVar2 = true;
      }
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


