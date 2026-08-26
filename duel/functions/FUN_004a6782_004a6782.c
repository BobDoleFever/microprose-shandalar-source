/*
 * Decompiled function: FUN_004a6782
 * Entry Point: 004a6782
 * Size: 378 bytes
 */
#include "duel.h"


undefined4 FUN_004a6782(int arg_1,undefined4 arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10 [3];
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x71) {
      iVar2 = FUN_004512d1(arg_1,s_Natural_Selection__005060c0,0,s_See_your_library_005060ac,
                           s_See_opponent_s_library_00506094,(char *)0x0);
      if (iVar2 == 0) {
        local_14 = arg_1;
      }
      else {
        local_14 = 1 - arg_1;
      }
      while( true ) {
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          local_10[local_18] = *(int *)(&DAT_006669f0 + local_18 * 4 + local_14 * 2000);
        }
        Palette_Subsystem_004a5722
                  (arg_1,local_10,3,s_Next_3__R_to_L__library_cards_005060dc,0,&DAT_005060d4);
        iVar2 = FUN_004512d1(arg_1,s_Natural_Selection__00506130,0,s_No_change_00506124,
                             s_Rearrange_these_cards_0050610c,s_Shuffle_deck_005060fc);
        if (iVar2 != 1) break;
        for (local_18 = 0; local_18 < 3; local_18 = local_18 + 1) {
          do {
            iVar2 = FUN_00439892(3);
          } while (local_10[iVar2] == -2);
          *(int *)(&DAT_006669f0 + local_18 * 4 + local_14 * 2000) = local_10[iVar2];
          local_10[iVar2] = -2;
        }
      }
      if (iVar2 == 2) {
        FUN_004d7946(local_14);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


