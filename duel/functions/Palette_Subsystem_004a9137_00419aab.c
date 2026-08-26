/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 00419aab
 * Size: 563 bytes
 */
#include "duel.h"


undefined4 Palette_Subsystem_004a9137(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (arg_3 == 0x73) {
    iVar1 = FUN_0049b309(arg_1,7,1);
    if (((iVar1 == 0) ||
        ((((&DAT_006826ce)[arg_2 * 0x120 + arg_1 * 0x5b20] & 3) != 0 &&
         (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) !=
          0)))) || (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) != 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (iVar1 = FUN_0049b309(arg_1,7,1), iVar1 != 0)) &&
       (Ai_CalcManaRequirement_004ba890(arg_1,0,1), DAT_00681ea4 != 1)) {
      FUN_0046e571(arg_1,arg_2,3);
    }
    if (arg_3 == 0x72) {
      if (arg_1 == DAT_00676510) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Heads_Tails_004f2c10);
      }
      else {
        Mem_AllocOrFree_004d9630
                  ((uint *)&DAT_005f6810,(uint *)s_Call_the_coin_flip__Heads_Tails_004f2c20);
      }
      iVar1 = FUN_00439892(1);
      iVar1 = Ai_Subsystem_004cc56d(1 - arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,iVar1);
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)&DAT_004f2c44);
      iVar3 = FUN_004491fe(s_Bottle_of_Suleiman_004f2c48);
      if (iVar3 == iVar1) {
        Mem_AllocOrFree_004afd1c(arg_1,5,DAT_00690af0,DAT_0068efa0);
      }
      else {
        iVar1 = FUN_004d7d5e(0x37a);
        iVar1 = Pic_Subsystem_00451291(arg_1,iVar1);
        if (iVar1 != -1) {
          Pic_Subsystem_0042ac1f(arg_1,iVar1);
          *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar1 * 0x120 + arg_1 * 0x5b20) | 0x10;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


