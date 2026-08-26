/*
 * Decompiled function: Minit_Subsystem_00456552
 * Entry Point: 00456552
 * Size: 133 bytes
 */
#include "magic.h"


undefined4 Minit_Subsystem_00456552(undefined4 arg_1,undefined4 arg_2,int arg_3)

{
  int iVar1;
  
  if ((&DAT_0051aebd)[arg_3 * 0x34] == '\b') {
    iVar1 = Pic_Subsystem_0045268f(0x21d);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 1;
    }
    iVar1 = Pic_Subsystem_0045268f(0x21f);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 2;
    }
    iVar1 = Pic_Subsystem_0045268f(0x220);
    if (iVar1 == arg_3) {
      DAT_00679ecc = DAT_00679ecc | 4;
    }
  }
  return 0;
}


