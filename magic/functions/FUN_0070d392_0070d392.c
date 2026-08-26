/*
 * Decompiled function: FUN_0070d392
 * Entry Point: 0070d392
 * Size: 242 bytes
 */
#include "magic.h"


undefined4 __fastcall FUN_0070d392(undefined4 arg_1,uint arg_2,undefined4 arg_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint extraout_ECX;
  uint uVar4;
  ushort *unaff_ESI;
  ushort *puVar5;
  
  uVar3 = DAT_00536886;
  if (&stack0x00000000 == (undefined1 *)0x536c87) {
    uVar4 = DAT_00536880 >> (0x10 - DAT_00536884 & 0x1f);
    for (bVar2 = DAT_00536884; (char)bVar2 < DAT_00536876; bVar2 = bVar2 + 0x10) {
      puVar5 = unaff_ESI;
      if (PTR_DAT_005327b0 <= unaff_ESI) {
        (*DAT_0067f43c)();
        puVar5 = DAT_00706500;
      }
      unaff_ESI = puVar5 + 1;
      DAT_00536880 = (uint)*puVar5;
      uVar4 = uVar4 | DAT_00536880 << (bVar2 & 0x1f);
    }
    DAT_00536884 = bVar2 - DAT_00536876;
    uVar4 = uVar4 & DAT_00536878;
    uVar3 = uVar4;
    if ((int)arg_2 <= (int)uVar4) {
      uVar4 = DAT_00536886;
      uVar3 = arg_2;
    }
    while( true ) {
      iVar1 = uVar4 * 3;
      if (*(short *)((int)&DAT_00532860 + iVar1) == -1) break;
      uVar4 = CONCAT22((short)(uVar4 >> 0x10),*(short *)((int)&DAT_00532860 + iVar1));
      arg_3 = CONCAT31((int3)((uint)iVar1 >> 8),(&DAT_00532862)[iVar1]);
    }
    DAT_0053688a = (&DAT_00532862)[iVar1];
    (&DAT_00532862)[arg_2 * 3] = DAT_0053688a;
    *(short *)((int)&DAT_00532860 + arg_2 * 3) = (short)DAT_00536886;
    if ((int)DAT_00536878 < (int)(arg_2 + 1)) {
      DAT_00536876 = DAT_00536876 + '\x01';
      DAT_00536878 = DAT_00536878 << 1 | 1;
    }
    if (DAT_00536877 < DAT_00536876) {
      FUN_0070d2b5();
      uVar3 = extraout_ECX;
    }
  }
  DAT_00536886 = uVar3;
                    /* WARNING: Treating indirect jump as return */
  return arg_3;
}


