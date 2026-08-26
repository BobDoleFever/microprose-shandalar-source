/*
 * Decompiled function: FUN_0048b2c9
 * Entry Point: 0048b2c9
 * Size: 508 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x0048b3c3) */

bool FUN_0048b2c9(int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,uint arg_5,uint arg_6)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  
  if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) == 0) {
    bVar2 = false;
  }
  else if ((*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) == -1) ||
          (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x18) != 0)) {
    bVar2 = false;
  }
  else if ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0) ||
          (iVar3 = FUN_0048af80(arg_1,arg_2), iVar3 != 0)) {
    if (((arg_5 & 0x20) == 0) ||
       (uVar4 = FUN_0048b81a(arg_1,arg_2,0x34,0xffffffff), (uVar4 & 0x420) != 0)) {
      if (((arg_5 & 0x1ff800) == 0) ||
         (cVar1 = FUN_0048c367((&DAT_006826dd)[arg_2 * 0x120 + arg_1 * 0x5b20]),
         (arg_5 & 0x800 << (cVar1 - 1U & 0x1f)) == 0)) {
        if ((arg_6 & arg_5 & 0x1f) == 0) {
          FUN_0048cac9();
          DAT_0068ecb0 = arg_1;
          DAT_00690c48 = arg_2;
          DAT_00690310 = arg_3;
          DAT_0068ecfc = arg_4;
          DAT_0066642c = 0;
          Magic_ScanCards(0x78);
          bVar2 = DAT_0066642c < 1;
          FUN_0048cb7f();
        }
        else {
          bVar2 = false;
        }
      }
      else {
        bVar2 = false;
      }
    }
    else {
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


