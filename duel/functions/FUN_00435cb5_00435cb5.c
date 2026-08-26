/*
 * Decompiled function: FUN_00435cb5
 * Entry Point: 00435cb5
 * Size: 441 bytes
 */
#include "duel.h"


undefined4 FUN_00435cb5(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int local_14;
  int local_10;
  
  iVar1 = *(int *)(&DAT_004f4680 + arg1 * 4);
  for (local_10 = 0; local_10 < *(int *)(&DAT_004f4630 + arg1 * 4); local_10 = local_10 + 1) {
    iVar2 = *(int *)(&DAT_004f46a8 + local_10 * 0x10 + arg1 * 0xc0);
    if (*(int *)(arg2 + iVar2 * 4) == 0) {
      pvVar3 = _malloc(0x800);
      *(void **)(arg2 + iVar2 * 4) = pvVar3;
      if (*(int *)(arg2 + iVar2 * 4) == 0) {
        __assert((uint *)s_deltas_EVal_____NULL_004f5488,
                 (uint *)s_D__Newmagic_sources_NedCard_Pale_004f5460,0x4fd);
      }
      for (local_14 = -0x100; local_14 < 0x100; local_14 = local_14 + 1) {
        *(int *)(*(int *)(arg2 + iVar2 * 4) + 0x400 + local_14 * 4) =
             ((iVar2 * local_14 + (iVar1 >> 1)) * 0x100) / *(int *)(&DAT_004f4680 + arg1 * 4);
      }
      *(int *)(&DAT_004f46b4 + local_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + iVar2 * 4) + 0x3fc;
    }
    else {
      *(int *)(&DAT_004f46b4 + local_10 * 0x10 + arg1 * 0xc0) = *(int *)(arg2 + iVar2 * 4) + 0x400;
    }
  }
  for (local_10 = 0; local_10 < *(int *)(&DAT_004f4630 + arg1 * 4); local_10 = local_10 + 1) {
    *(int *)(&DAT_004f4d74 + local_10 * 0x10 + arg1 * 0xc0) =
         *(int *)(arg2 + *(int *)(&DAT_004f4d68 + local_10 * 0x10 + arg1 * 0xc0) * 4) + 0x3fc;
  }
  return 0;
}


