/*
 * Decompiled function: FUN_004a44c8
 * Entry Point: 004a44c8
 * Size: 437 bytes
 */
#include "duel.h"


bool FUN_004a44c8(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int local_8;
  
  if (arg_3 == 0x73) {
    if ((DAT_00676504 == arg_1) && ((&DAT_00681ea8)[arg_1] == 1)) {
      bVar1 = false;
    }
    else {
      bVar1 = 0 < (int)(&DAT_00681ea8)[arg_1];
    }
  }
  else {
    if (arg_3 == 0x6d) {
      bVar1 = false;
      while ((!bVar1 && (DAT_00681ea4 != 1))) {
        local_8 = FUN_0045139b(arg_1,s_Spend_how_much_life_for_generic_m_00506038,1);
        if (local_8 < 0) {
          DAT_00681ea4 = 1;
        }
        else if ((int)(&DAT_00681ea8)[arg_1] < local_8) {
          if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed(s_Illegal_Amount___must_be_between_00506060);
            Sleep(2000);
            Mem_AllocOrFree_00450eed(&DAT_00506090);
          }
        }
        else {
          bVar1 = true;
        }
      }
      if (DAT_00681ea4 != 1) {
        FUN_0049b2c1(arg_1,0,local_8);
        (&DAT_00681ea8)[arg_1] = (&DAT_00681ea8)[arg_1] - local_8;
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      FUN_0046e571(arg_1,arg_2,1);
    }
    if (((arg_3 == 0x7f) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      FUN_0049b1a9(arg_1,0,(&DAT_00681ea8)[arg_1]);
    }
    bVar1 = false;
  }
  return bVar1;
}


