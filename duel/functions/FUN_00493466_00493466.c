/*
 * Decompiled function: FUN_00493466
 * Entry Point: 00493466
 * Size: 681 bytes
 */
#include "duel.h"


int FUN_00493466(int arg_1)

{
  int iVar1;
  int iVar2;
  int local_420;
  int local_41c;
  int local_418;
  int aiStack_404 [256];
  
  local_420 = 0;
  for (local_418 = 0; local_418 < 0x100; local_418 = local_418 + 1) {
    if (*(int *)(&DAT_006656d4 + local_418 * 8) == -1) {
      if (((*(int *)(&DAT_004ff590 + arg_1 * 0x34) == *(int *)(&DAT_006656d0 + local_418 * 8)) &&
          (iVar1 = FUN_00493714(*(int *)(&DAT_006656d0 + local_418 * 8)), iVar1 == 0)) &&
         ((*(uint *)(&DAT_006651c0 + local_418 * 4) & 1 << ((byte)DAT_005f2f50 & 0x1f)) != 0)) {
        local_41c = 0;
        while ((local_41c < 500 &&
               ((((&DAT_004ff594)[(*(uint *)(&deck + local_41c * 4) & 0xfff) * 0x34] & 1) == 0 ||
                (((&DAT_004ff596)[arg_1 * 0x34] &
                 (&DAT_004ff596)[(*(uint *)(&deck + local_41c * 4) & 0xfff) * 0x34]) == 0))))) {
          local_41c = local_41c + 1;
        }
      }
    }
    else {
      iVar1 = FUN_00493714(*(int *)(&DAT_006656d0 + local_418 * 8));
      iVar2 = FUN_00493714(*(int *)(&DAT_006656d4 + local_418 * 8));
      if (((iVar1 == 0) || (iVar2 == 0)) &&
         ((*(uint *)(&DAT_006651c0 + local_418 * 4) & 1 << ((byte)DAT_005f2f50 & 0x1f)) != 0)) {
        if ((*(int *)(&DAT_004ff590 + arg_1 * 0x34) == *(int *)(&DAT_006656d0 + local_418 * 8)) &&
           (iVar2 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
        if ((*(int *)(&DAT_006656d4 + local_418 * 8) == *(int *)(&DAT_004ff590 + arg_1 * 0x34)) &&
           (iVar1 != 0)) {
          aiStack_404[local_420] = local_418;
          local_420 = local_420 + 1;
        }
      }
    }
  }
  if (local_420 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_00439892(local_420);
    iVar1 = aiStack_404[iVar1];
  }
  return iVar1;
}


