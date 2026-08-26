/*
 * Decompiled function: FUN_006c5000
 * Entry Point: 006c5000
 * Size: 396 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_006c5000(undefined4 arg_1,undefined4 arg_2,ushort *arg_3)

{
  ushort uVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 unaff_EBX;
  ushort *puVar3;
  ushort *puVar4;
  
  while( true ) {
    puVar3 = DAT_0069453c;
    if (PTR_DAT_004f7918 <= DAT_0069453c) {
      (*DAT_00694740)(arg_2,arg_1,unaff_EBX);
      puVar3 = DAT_0069453c;
    }
    DAT_0069453c = puVar3 + 1;
    uVar1 = *puVar3;
    if ((char)uVar1 == 'X') break;
    puVar3 = &DAT_004fb154;
    if ((uVar1 == 0x304d) || (uVar1 == 0x314d)) {
      if ((int)arg_3 < 1) {
        puVar3 = (ushort *)&DAT_004fb156;
      }
      else if (arg_3 != (ushort *)0x1) {
        puVar3 = arg_3;
      }
    }
    *puVar3 = uVar1;
    puVar4 = puVar3;
    if (PTR_DAT_004f7918 <= DAT_0069453c) {
      (*DAT_00694740)(arg_2,arg_1);
    }
    uVar1 = *DAT_0069453c;
    DAT_0069453c = DAT_0069453c + 1;
    puVar3[1] = uVar1;
    puVar3 = puVar3 + 2;
    for (uVar2 = (uint)(uVar1 >> 1); uVar2 != 0; uVar2 = uVar2 - 1) {
      if (PTR_DAT_004f7918 <= DAT_0069453c) {
        (*DAT_00694740)();
      }
      uVar1 = *DAT_0069453c;
      DAT_0069453c = DAT_0069453c + 1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    }
    arg_1 = 0;
    if (puVar4 == &DAT_004fb154) {
      Mem_AllocOrFree_0043d858(&DAT_004fb154);
      arg_1 = extraout_ECX;
      arg_2 = extraout_EDX;
    }
  }
  DAT_004ff179 = (byte)(uVar1 >> 8) & 1;
  if (PTR_DAT_004f7918 <= DAT_0069453c) {
    (*DAT_00694740)(arg_2,arg_1,unaff_EBX);
  }
  puVar3 = DAT_0069453c + 1;
  _DAT_004ff15c = (uint)*DAT_0069453c;
  if (PTR_DAT_004f7918 <= puVar3) {
    DAT_0069453c = puVar3;
    (*DAT_00694740)(arg_2,arg_1,unaff_EBX);
    puVar3 = DAT_0069453c;
  }
  DAT_0069453c = puVar3 + 1;
  DAT_004ff154 = (uint)*puVar3;
  if (PTR_DAT_004f7918 <= DAT_0069453c) {
    (*DAT_00694740)(arg_2,arg_1,unaff_EBX);
  }
  DAT_004ff158 = (uint)*DAT_0069453c;
  DAT_0069453c = DAT_0069453c + 1;
  FUN_006c5245(arg_1,arg_2);
  return;
}


