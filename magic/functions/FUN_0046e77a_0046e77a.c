/*
 * Decompiled function: FUN_0046e77a
 * Entry Point: 0046e77a
 * Size: 424 bytes
 */
#include "magic.h"


void FUN_0046e77a(char *arg1,int arg2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  Mem_AllocOrFree_00510e20(1,arg1);
  iVar1 = Surface_GetPixel(1,1,0xc);
  local_c = 4;
  for (local_10 = 2; local_10 < DAT_00522458; local_10 = local_10 + 1) {
    iVar2 = Surface_GetPixel(1,local_10,0xd);
    if (iVar2 == iVar1) {
      local_c = local_10;
      break;
    }
  }
  local_8 = 0x10;
  *(undefined4 *)(&DAT_00677990 + arg2 * 4) = 0;
  local_14 = 0xd;
  do {
    if (DAT_0052245c <= local_14) {
LAB_0046e877:
      for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
        for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
          uVar3 = Sprite_EncodeFromSurface
                            (1,(local_c + -1) * local_10 + 2,(local_8 + -0xc) * local_14 + 0xd,
                             local_c - 2U,local_8 + -0xd);
          *(undefined4 *)(&g_OverworldFoodAmount + arg2 * 0xb4 + local_14 * 0x14 + local_10 * 4) =
               uVar3;
        }
      }
      *(uint *)(&DAT_006783f0 + arg2 * 4) = local_c - 2U;
      *(int *)(&DAT_00678470 + arg2 * 4) = local_8 + -0xd;
      return;
    }
    iVar2 = Surface_GetPixel(1,1,local_14);
    if (iVar2 != iVar1) {
      *(int *)(&DAT_00677990 + arg2 * 4) = local_14 + -0xd;
    }
    iVar2 = Surface_GetPixel(1,2,local_14);
    if (iVar2 == iVar1) {
      local_8 = local_14;
      goto LAB_0046e877;
    }
    local_14 = local_14 + 1;
  } while( true );
}


