/*
 * Decompiled function: FUN_0045ffcf
 * Entry Point: 0045ffcf
 * Size: 967 bytes
 */
#include "duel.h"


undefined4 FUN_0045ffcf(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
  }
  if (((arg_3 == 0x82) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827c8 + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xfffffffc;
  }
  if (((arg_3 == 0x84) && (arg_2 == DAT_00690c48)) &&
     ((arg_1 == DAT_0068ecb0 &&
      (((((&DAT_006826cc)[arg_1 * 0x5b20 + arg_2 * 0x120] & 0x10) != 0 && (arg_1 == DAT_00666458))
       && (arg_1 == DAT_00681eb4)))))) {
    *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
         *(uint *)(&DAT_006827d4 + arg_1 * 0x5b20 + arg_2 * 0x120) | 0x10;
  }
  if ((arg_3 == 0x88) &&
     (iVar1 = FUN_004af74c(arg_1,arg_2,2), *(int *)(&DAT_0068ef50 + iVar1 * 4 + arg_1 * 0x20) < 2))
  {
    DAT_0066642c = DAT_0066642c | 1;
  }
  if (arg_3 == 1) {
    iVar1 = Glue_Subsystem_004dec09(arg_1,arg_2,1);
    if (iVar1 == 0) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    else {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + arg_2 * 0x120) & 0xffffffef;
    }
  }
  if ((arg_3 == 0x79) && (*(int *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)) {
    iVar1 = FUN_004af74c(arg_1,arg_2,2);
    if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + arg_1 * 0x20) < 2) {
      DAT_0066642c = 1;
    }
  }
  else {
    if ((((DAT_0068f230 == 0xdc) &&
         ((((DAT_0068f2c4 == 0x15 && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
          ((DAT_00681ec4 == DAT_00666458 &&
           (*(int *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) == 0)))))) &&
        (arg_1 == DAT_00666754)) && (arg_2 == DAT_0068edd0)) {
      iVar1 = FUN_004af74c(arg_1,arg_2,2);
      if (*(int *)(&DAT_0068ef50 + iVar1 * 4 + arg_1 * 0x20) < 2) {
        DAT_00666428 = 1;
      }
      else {
        if (arg_3 == 0x7d) {
          DAT_0066642c = DAT_0066642c | 2;
        }
        if (arg_3 == 0x7e) {
          iVar1 = Glue_Subsystem_004dec09(arg_1,arg_2,0);
          if (iVar1 == 0) {
            DAT_00666428 = 1;
            DAT_00681ea4 = 0;
          }
          else {
            *(undefined4 *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 1;
          }
        }
      }
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120) = 0;
      *(undefined4 *)(&DAT_006826e4 + arg_1 * 0x5b20 + arg_2 * 0x120) =
           *(undefined4 *)(&DAT_006826f0 + arg_1 * 0x5b20 + arg_2 * 0x120);
    }
  }
  return 0;
}


