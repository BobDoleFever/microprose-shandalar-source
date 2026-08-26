/*
 * Decompiled function: FUN_006c5392
 * Entry Point: 006c5392
 * Size: 242 bytes
 */
#include "duel.h"


undefined4 __fastcall FUN_006c5392(undefined4 arg_1,uint arg_2,undefined4 arg_3)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint extraout_ECX;
  uint uVar4;
  ushort *unaff_ESI;
  ushort *puVar5;
  
  uVar3 = DAT_004ff17a;
  if (&stack0x00000000 == (undefined1 *)0x4ff57b) {
    uVar4 = DAT_004ff174 >> (0x10 - DAT_004ff178 & 0x1f);
    for (bVar2 = DAT_004ff178; (char)bVar2 < DAT_004ff16a; bVar2 = bVar2 + 0x10) {
      puVar5 = unaff_ESI;
      if (PTR_DAT_004f7918 <= unaff_ESI) {
        (*DAT_00694740)();
        puVar5 = DAT_0069453c;
      }
      unaff_ESI = puVar5 + 1;
      DAT_004ff174 = (uint)*puVar5;
      uVar4 = uVar4 | DAT_004ff174 << (bVar2 & 0x1f);
    }
    DAT_004ff178 = bVar2 - DAT_004ff16a;
    uVar4 = uVar4 & DAT_004ff16c;
    uVar3 = uVar4;
    if ((int)arg_2 <= (int)uVar4) {
      uVar4 = DAT_004ff17a;
      uVar3 = arg_2;
    }
    while( true ) {
      iVar1 = uVar4 * 3;
      if (*(short *)((int)&DAT_004fb154 + iVar1) == -1) break;
      uVar4 = CONCAT22((short)(uVar4 >> 0x10),*(short *)((int)&DAT_004fb154 + iVar1));
      arg_3 = CONCAT31((int3)((uint)iVar1 >> 8),(&DAT_004fb156)[iVar1]);
    }
    DAT_004ff17e = (&DAT_004fb156)[iVar1];
    (&DAT_004fb156)[arg_2 * 3] = DAT_004ff17e;
    *(short *)((int)&DAT_004fb154 + arg_2 * 3) = (short)DAT_004ff17a;
    if ((int)DAT_004ff16c < (int)(arg_2 + 1)) {
      DAT_004ff16a = DAT_004ff16a + '\x01';
      DAT_004ff16c = DAT_004ff16c << 1 | 1;
    }
    if (DAT_004ff16b < DAT_004ff16a) {
      FUN_006c52b5();
      uVar3 = extraout_ECX;
    }
  }
  DAT_004ff17a = uVar3;
                    /* WARNING: Treating indirect jump as return */
  return arg_3;
}


