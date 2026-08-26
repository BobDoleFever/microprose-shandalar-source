/*
 * Decompiled function: FUN_004895b4
 * Entry Point: 004895b4
 * Size: 408 bytes
 */
#include "duel.h"


bool FUN_004895b4(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint width;
  int iVar2;
  bool bVar3;
  
  if (((arg_1 == -1) || (arg_2 == -1)) || (arg_3 == -1)) {
    bVar3 = false;
  }
  else {
    iVar1 = *(int *)(&DAT_006826c4 + arg_2 * 0x5b20 + arg_3 * 0x120);
    if (iVar1 == -1) {
      bVar3 = false;
    }
    else if (((&DAT_004ff594)[iVar1 * 0x34] & 0x40) == 0) {
      width = FUN_0048c367((&DAT_004ff596)[iVar1 * 0x34]);
      iVar2 = FUN_0049b68d(arg_1,arg_3,width,(int)(char)(&DAT_004ff597)[iVar1 * 0x34]);
      bVar3 = iVar2 != 0;
      if (('\0' < (char)(&DAT_004ff598)[iVar1 * 0x34]) &&
         (iVar1 = FUN_0049b68d(arg_1,arg_3,7,
                               (int)(char)(&DAT_004ff597)[iVar1 * 0x34] +
                               (int)(char)(&DAT_004ff598)[iVar1 * 0x34]), iVar1 == 0)) {
        bVar3 = false;
      }
    }
    else {
      iVar1 = FUN_0049b309(arg_1,6,(int)(char)(&DAT_004ff597)[iVar1 * 0x34] +
                                   (int)(char)(&DAT_004ff598)[iVar1 * 0x34]);
      bVar3 = iVar1 != 0;
    }
  }
  return bVar3;
}


