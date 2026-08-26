/*
 * Decompiled function: Glue_Subsystem_004e00e7
 * Entry Point: 00461874
 * Size: 718 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004e00e7(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((((arg_3 == 0x84) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
      ((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 && (arg_1 == DAT_00666458))))
     && (arg_1 == DAT_00681eb4)) {
    *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
    (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if (arg_3 == 1) {
    *(int *)(&DAT_0068f328 + arg_1 * 0x20) = *(int *)(&DAT_0068f328 + arg_1 * 0x20) + 1;
  }
  FUN_00461715(arg_1,arg_2,arg_3);
  if (((arg_3 == 0x82) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] =
         (&DAT_006827ce)[arg_1 * 0x5b20 + arg_2 * 0x120] + '\x03';
  }
  if ((((DAT_0068f230 == 0xca) && (arg_1 == DAT_00666458)) &&
      ((arg_2 == DAT_00690c48 && ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00681ec4)))))) &&
     (((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0)) {
    iVar1 = FUN_0049b309(arg_1,2,3);
    if (iVar1 != 0) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 0x7e) {
        iVar1 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Untap_Island_Fish__Don_t_untap__004f8c40,0);
        if (iVar1 == 0) {
          Ai_CalcManaRequirement_004ba890(arg_1,2,3);
          if (DAT_00681ea4 == 1) {
            DAT_00681ea4 = -1;
          }
          else {
            *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
                 *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffef;
          }
        }
      }
    }
  }
  return 0;
}


