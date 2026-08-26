/*
 * Decompiled function: FUN_0048b64f
 * Entry Point: 0048b64f
 * Size: 459 bytes
 */
#include "duel.h"


void FUN_0048b64f(void)

{
  short sVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      if ((((&DAT_006826cc)[local_8 * 0x5b20 + local_c * 0x120] & 2) != 0) &&
         (*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_c * 0x120) != -1)) {
        *(uint *)(&DAT_006826fc + local_8 * 0x5b20 + local_c * 0x120) =
             *(uint *)(&DAT_006826fc + local_8 * 0x5b20 + local_c * 0x120) | 0xf000000;
        FUN_0048b81a(local_8,local_c,0x3c,0xffffffff);
      }
    }
  }
  FUN_00451995();
  FUN_00451760();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
      iVar2 = FUN_0048a33f(local_8,local_c);
      if (((iVar2 != 0) &&
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_8 * 0x5b20 + local_c * 0x120) * 0x34] & 2
           ) != 0)) &&
         (sVar1 = *(short *)(&DAT_006826d0 + local_8 * 0x5b20 + local_c * 0x120),
         iVar2 = FUN_0048b81a(local_8,local_c,0x33,0xffffffff), sVar1 < iVar2)) {
        FUN_0048b81a(local_8,local_c,0x32,0xffffffff);
      }
    }
  }
  return;
}


