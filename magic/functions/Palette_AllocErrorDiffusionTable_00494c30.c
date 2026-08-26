/*
 * Decompiled function: Palette_AllocErrorDiffusionTable
 * Entry Point: 00494c30
 * Size: 311 bytes
 */
#include "magic.h"


undefined4 Palette_AllocErrorDiffusionTable(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *local_10;
  int local_c;
  
  iVar5 = *(int *)(&DAT_0052a210 + arg1 * 4);
  local_c = 0;
  if (0 < *(int *)(&DAT_0052a1c0 + arg1 * 4)) {
    local_10 = (int *)(&DAT_0052a244 + arg1 * 0xc0);
    do {
      iVar1 = local_10[-3];
      iVar2 = *(int *)(arg2 + iVar1 * 4);
      if (iVar2 == 0) {
        pvVar3 = malloc(0x800);
        *(void **)(arg2 + iVar1 * 4) = pvVar3;
        if (pvVar3 == (void *)0x0) {
          assert(s_deltas_EVal_____NULL_0052afe0,s_G__NewMagic_sources_NedCard_Pale_0052aff8,0x4fd);
        }
        iVar6 = -0x400;
        iVar2 = ((iVar5 >> 1) + iVar1 * -0x100) * 0x100;
        do {
          iVar6 = iVar6 + 4;
          *(int *)(*(int *)(arg2 + iVar1 * 4) + 0x3fc + iVar6) =
               iVar2 / *(int *)(&DAT_0052a210 + arg1 * 4);
          iVar2 = iVar2 + iVar1 * 0x100;
        } while (iVar6 < 0x400);
        iVar2 = *(int *)(arg2 + iVar1 * 4) + 0x3fc;
      }
      else {
        iVar2 = iVar2 + 0x400;
      }
      *local_10 = iVar2;
      local_10 = local_10 + 4;
      local_c = local_c + 1;
    } while (local_c < *(int *)(&DAT_0052a1c0 + arg1 * 4));
  }
  iVar5 = *(int *)(&DAT_0052a1c0 + arg1 * 4);
  if (0 < iVar5) {
    piVar4 = (int *)(&DAT_0052a904 + arg1 * 0xc0);
    do {
      iVar5 = iVar5 + -1;
      *piVar4 = *(int *)(arg2 + piVar4[-3] * 4) + 0x3fc;
      piVar4 = piVar4 + 4;
    } while (iVar5 != 0);
  }
  return 0;
}


