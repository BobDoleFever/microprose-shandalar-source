/*
 * Decompiled function: FUN_004014e0
 * Entry Point: 004014e0
 * Size: 701 bytes
 */
#include "duel.h"


undefined4 FUN_004014e0(int arg_1,int arg_2,int arg_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int height;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      local_18 = 0;
      do {
        local_18 = local_18 + 1;
        if (999 < local_18) {
          local_8 = -1;
          break;
        }
        local_14 = FUN_00439892(2);
        local_8 = FUN_00439892(500);
        local_10 = *(int *)(&DAT_0068f370 + local_8 * 4 + local_14 * 2000);
      } while ((local_10 == -1) || (((&DAT_004ff594)[local_10 * 0x34] & 2) == 0));
      if (local_8 == -1) {
        local_1c = 0;
        while ((local_1c < 2 && (local_8 == -1))) {
          local_18 = 0;
          while (((local_18 < 500 &&
                  (*(int *)(&DAT_0068f370 + local_18 * 4 + local_1c * 2000) != -1)) &&
                 (local_8 == -1))) {
            local_10 = *(int *)(&DAT_0068f370 + local_18 * 4 + local_1c * 2000);
            if (((&DAT_004ff594)[local_10 * 0x34] & 2) != 0) {
              local_8 = local_18;
              local_14 = local_1c;
            }
            local_18 = local_18 + 1;
          }
          local_1c = local_1c + 1;
        }
      }
      if ((local_8 != -1) && (*(int *)(&DAT_0068f370 + local_8 * 4 + local_14 * 2000) != -1)) {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x23);
        }
        iVar3 = Pic_Subsystem_00451291
                          (arg_1,*(int *)(&DAT_0068f370 + local_8 * 4 + local_14 * 2000));
        if (local_14 == 0) {
          *(undefined4 *)(&DAT_006826cc + iVar3 * 0x120 + arg_1 * 0x5b20) = 0;
        }
        else {
          *(undefined4 *)(&DAT_006826cc + iVar3 * 0x120 + arg_1 * 0x5b20) = 0x1000;
        }
        if (iVar3 != -1) {
          FUN_0046f116(local_14,local_8);
          Pic_Subsystem_0042ac1f(arg_1,iVar3);
          cVar1 = (&DAT_004ff597)[local_10 * 0x34];
          iVar3 = arg_1;
          height = arg_2;
          iVar4 = FUN_0049aa14((int)(char)(&DAT_004ff598)[local_10 * 0x34],0,99);
          Mem_AllocOrFree_004afd1c(arg_1,cVar1 + iVar4,iVar3,height);
        }
      }
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


