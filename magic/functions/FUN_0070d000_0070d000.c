/*
 * Decompiled function: FUN_0070d000
 * Entry Point: 0070d000
 * Size: 396 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0070d000(undefined4 arg_1,undefined4 arg_2,ushort *arg_3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  ushort *puVar3;
  ushort *puVar4;
  
  while( true ) {
    puVar3 = DAT_00706500;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
      puVar3 = DAT_00706500;
    }
    DAT_00706500 = puVar3 + 1;
    uVar1 = *puVar3;
    if ((char)uVar1 == 'X') break;
    puVar3 = &DAT_00532860;
    if ((uVar1 == 0x304d) || (uVar1 == 0x314d)) {
      if ((int)arg_3 < 1) {
        puVar3 = (ushort *)&DAT_00532862;
      }
      else if (arg_3 != (ushort *)0x1) {
        puVar3 = arg_3;
      }
    }
    *puVar3 = uVar1;
    puVar4 = puVar3;
    if (PTR_DAT_005327b0 <= DAT_00706500) {
      (*DAT_0067f43c)(arg_2,arg_1);
    }
    uVar1 = *DAT_00706500;
    DAT_00706500 = DAT_00706500 + 1;
    puVar3[1] = uVar1;
    puVar3 = puVar3 + 2;
    for (uVar2 = (uint)(uVar1 >> 1); uVar2 != 0; uVar2 = uVar2 - 1) {
      if (PTR_DAT_005327b0 <= DAT_00706500) {
        (*DAT_0067f43c)();
      }
      uVar1 = *DAT_00706500;
      DAT_00706500 = DAT_00706500 + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    }
    arg_1 = 0;
    if (puVar4 == &DAT_00532860) {
      FUN_0050e8b0(&DAT_00532860);
      arg_1 = extraout_ECX;
      arg_2 = extraout_EDX;
    }
  }
  DAT_00536885 = (byte)(uVar1 >> 8) & 1;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
  }
  puVar3 = DAT_00706500 + 1;
  _DAT_00536868 = (uint)*DAT_00706500;
  if (PTR_DAT_005327b0 <= puVar3) {
    DAT_00706500 = puVar3;
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
    puVar3 = DAT_00706500;
  }
  DAT_00706500 = puVar3 + 1;
  DAT_00536860 = (uint)*puVar3;
  if (PTR_DAT_005327b0 <= DAT_00706500) {
    (*DAT_0067f43c)(arg_2,arg_1,unaff_EBX);
  }
  DAT_00536864 = (uint)*DAT_00706500;
  DAT_00706500 = DAT_00706500 + 1;
  FUN_0070d245(arg_1,arg_2);
  return;
}


