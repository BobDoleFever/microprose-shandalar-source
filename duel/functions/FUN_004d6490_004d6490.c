/*
 * Decompiled function: FUN_004d6490
 * Entry Point: 004d6490
 * Size: 310 bytes
 */
#include "duel.h"


void FUN_004d6490(int arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
    if (*(int *)(&DAT_006826c4 + local_c * 0x120 + arg1 * 0x5b20) != -1) {
      bVar1 = false;
      local_10 = 0;
      while ((local_10 < 0x50 && (!bVar1))) {
        iVar2 = CardTypeFromID(*(int *)(&DAT_004f71c0 + local_10 * 8 + arg2 * 0x280));
        if (iVar2 == *(int *)(&DAT_006826c4 + local_c * 0x120 + arg1 * 0x5b20)) {
          (&DAT_004f71c4)[arg2 * 0xa0 + local_10 * 2] =
               (&DAT_004f71c4)[arg2 * 0xa0 + local_10 * 2] + 1;
          bVar1 = true;
        }
        local_10 = local_10 + 1;
      }
      *(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + arg1 * 0x5b20) = 0xffffffff;
    }
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    iVar2 = FUN_004396ea(arg2);
    Pic_Subsystem_00451291(arg1,iVar2);
  }
  return;
}


