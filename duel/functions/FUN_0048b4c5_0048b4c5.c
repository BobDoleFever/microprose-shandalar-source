/*
 * Decompiled function: FUN_0048b4c5
 * Entry Point: 0048b4c5
 * Size: 260 bytes
 */
#include "duel.h"


int FUN_0048b4c5(int x,int y,undefined4 arg_3,undefined4 arg_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = *(undefined4 *)(&DAT_006826cc + y * 0x120 + x * 0x5b20);
  uVar1 = (&DAT_006826de)[y * 0x120 + x * 0x5b20];
  *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
       *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) & 0xfffffff7;
  (&DAT_006826de)[y * 0x120 + x * 0x5b20] = 0xff;
  iVar3 = FUN_0048b24e(x,y,arg_3,arg_4);
  if (iVar3 == 0) {
    *(undefined4 *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) = uVar2;
    (&DAT_006826de)[y * 0x120 + x * 0x5b20] = uVar1;
  }
  return iVar3;
}


