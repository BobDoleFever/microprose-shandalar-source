/*
 * Decompiled function: FUN_004628db
 * Entry Point: 004628db
 * Size: 385 bytes
 */
#include "duel.h"


undefined4 FUN_004628db(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 local_8;
  
  if ((arg_3 == 0x73) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    local_8 = FUN_004593fd(arg_1,arg_2,0x73,0,0);
    iVar1 = FUN_004680fc(arg_1,arg_2);
    if (iVar1 == 0) {
      local_8 = 0;
    }
  }
  else if ((arg_3 == 0x6d) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    local_8 = FUN_004593fd(arg_1,arg_2,0x6d,0,0);
    FUN_0046801f(arg_1,arg_2,1);
  }
  else if ((arg_3 == 0x72) && ((DAT_00681eb0._1_1_ & 2) != 0)) {
    local_8 = FUN_004593fd(arg_1,arg_2,0x72,0,0);
  }
  else {
    if (((DAT_0068f230 == 0xcd) || (arg_3 == 199)) &&
       ((((arg_2 == DAT_00690c48 && (arg_1 == DAT_0068ecb0)) && (DAT_0068eeac != 0)) &&
        (DAT_00681ec4 == arg_1)))) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        FUN_00467f65(arg_1,arg_2,DAT_0068eeac);
      }
    }
    local_8 = 0;
  }
  return local_8;
}


