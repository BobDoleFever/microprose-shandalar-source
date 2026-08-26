/*
 * Decompiled function: SellPrice
 * Entry Point: 0050a8ae
 * Size: 273 bytes
 */
#include "magic.h"


int SellPrice(int arg_1)

{
  undefined4 arg_1_00;
  int iVar1;
  int local_8;
  
                    /* 0x10a8ae  7  SellPrice */
  arg_1_00 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + DAT_0061e0fc * 100),
                          *(int *)(&DAT_0067bdf8 + DAT_0061e0fc * 100));
  iVar1 = Adventure_GetLocationEncounterIndex(arg_1_00);
  local_8 = FUN_0050a9bf(arg_1);
  local_8 = (*(int *)(&DAT_0067bdf0 + DAT_0061e0fc * 100) + 2) * local_8;
  if (((char)(&DAT_0051aebe)[arg_1 * 0x34] != iVar1) && ((&DAT_0051aebe)[arg_1 * 0x34] != '\0')) {
    iVar1 = Pic_Subsystem_004521a6(iVar1,(int)(char)(&DAT_0051aebe)[arg_1 * 0x34],3);
    if (iVar1 == 0) {
      local_8 = (local_8 * 3) / 2;
    }
    else {
      local_8 = (local_8 * 4) / 3;
    }
  }
  return (local_8 / 0x32) * 5;
}


