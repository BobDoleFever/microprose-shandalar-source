/*
 * Decompiled function: FUN_00470ea3
 * Entry Point: 00470ea3
 * Size: 408 bytes
 */
#include "magic.h"


bool FUN_00470ea3(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  uint width;
  int iVar2;
  bool bVar3;
  
  if (((arg_1 == -1) || (arg_2 == -1)) || (arg_3 == -1)) {
    bVar3 = false;
  }
  else {
    iVar1 = *(int *)(&g_CardSlot_CardId + arg_3 * 0x120 + arg_2 * 0x5b20);
    if (iVar1 == -1) {
      bVar3 = false;
    }
    else if (((&g_MasterCardColorTable)[iVar1 * 0x34] & 0x40) == 0) {
      width = FUN_00473cc5((&DAT_0051aebe)[iVar1 * 0x34]);
      iVar2 = FUN_0040dcca(arg_1,arg_3,width,(int)(char)(&DAT_0051aebf)[iVar1 * 0x34]);
      bVar3 = iVar2 != 0;
      if (('\0' < (char)(&DAT_0051aec0)[iVar1 * 0x34]) &&
         (iVar1 = FUN_0040dcca(arg_1,arg_3,7,
                               (int)(char)(&DAT_0051aebf)[iVar1 * 0x34] +
                               (int)(char)(&DAT_0051aec0)[iVar1 * 0x34]), iVar1 == 0)) {
        bVar3 = false;
      }
    }
    else {
      iVar1 = FUN_0040d949(arg_1,6,(int)(char)(&DAT_0051aebf)[iVar1 * 0x34] +
                                   (int)(char)(&DAT_0051aec0)[iVar1 * 0x34]);
      bVar3 = iVar1 != 0;
    }
  }
  return bVar3;
}


