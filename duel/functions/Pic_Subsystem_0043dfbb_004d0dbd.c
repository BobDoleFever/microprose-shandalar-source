/*
 * Decompiled function: Pic_Subsystem_0043dfbb
 * Entry Point: 004d0dbd
 * Size: 309 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043dfbb(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ed24 + arg_1 * 0x20) * 0xc;
    }
    if (((arg_3 == 2) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      iVar2 = FUN_0049b309(arg_1,5,2);
      if (iVar2 != 0) {
        DAT_0066642c = DAT_0066642c | 1;
      }
    }
    if ((((arg_3 == 4) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) || (arg_3 == 199)) {
      iVar2 = FUN_0049b309(arg_1,5,2);
      if (iVar2 != 0) {
        iVar2 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Add_life_for_2_white_mana__No_Ye_00508f10,1);
        if (iVar2 != 0) {
          Ai_CalcManaRequirement_004ba890(arg_1,5,2);
          (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] + 1;
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


