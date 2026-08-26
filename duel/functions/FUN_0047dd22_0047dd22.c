/*
 * Decompiled function: FUN_0047dd22
 * Entry Point: 0047dd22
 * Size: 133 bytes
 */
#include "duel.h"


undefined4 FUN_0047dd22(undefined4 arg_1,undefined4 arg_2,int arg_3)

{
  int iVar1;
  
  if ((&DAT_004ff595)[arg_3 * 0x34] == '\b') {
    iVar1 = FUN_004d7d5e(0x21d);
    if (iVar1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 1;
    }
    iVar1 = FUN_004d7d5e(0x21f);
    if (iVar1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 2;
    }
    iVar1 = FUN_004d7d5e(0x220);
    if (iVar1 == arg_3) {
      DAT_00692c70 = DAT_00692c70 | 4;
    }
  }
  return 0;
}


