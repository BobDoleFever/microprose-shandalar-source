/*
 * Decompiled function: FUN_00472905
 * Entry Point: 00472905
 * Size: 261 bytes
 */
#include "magic.h"


undefined4 FUN_00472905(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  DAT_006a5f20 = 0;
  DAT_00626810 = 0;
  for (local_8 = 0; local_8 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_8 = local_8 + 1) {
    iVar1 = FUN_00471c32(arg_1,local_8);
    if (iVar1 != 0) {
      if (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_8 * 0x120] & 4) == 0) {
        if (((&DAT_006a5f3d)[arg_1 * 0x5b20 + local_8 * 0x120] & 0x80) != 0) {
          iVar1 = FUN_004726c5(arg_1,local_8);
          if (iVar1 != 0) {
            DAT_00626810 = DAT_00626810 + 1;
          }
        }
      }
      else {
        DAT_006a5f20 = 1;
      }
    }
  }
  if ((DAT_006a5f20 == 0) && (DAT_00626810 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


