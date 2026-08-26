/*
 * Decompiled function: FUN_004125b3
 * Entry Point: 004125b3
 * Size: 1408 bytes
 */
#include "duel.h"


int FUN_004125b3(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int y;
  int height;
  int local_c;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    DAT_0068f2d4 = DAT_0068f2d4 +
                   ((&DAT_00681ea8)[DAT_00676504] - (&DAT_00681ea8)[DAT_00676510]) * 0x18;
  }
  if ((((DAT_0068f230 == 0xc9) || (arg_3 == 199)) &&
      ((arg_2 == DAT_00690c48 && ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))))) &&
     ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
      (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) != 0))
     )) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      FUN_00467e37(arg_1,arg_2);
      FUN_00451482(0,0x20);
    }
  }
  if (arg_3 == 0x73) {
    if ((((DAT_0068f2c4 == 4) && (iVar2 = FUN_004680fc(arg_1,arg_2), iVar2 != 0)) &&
        (iVar2 = FUN_0049b309(DAT_00681eb4,7,4), iVar2 != 0)) &&
       (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) {
      if (DAT_00681eb4 == DAT_00676510) {
        local_c = 1;
      }
      else {
        if (((int)(&DAT_00681ea8)[DAT_00676504] < (int)(&DAT_00681ea8)[DAT_00676510]) ||
           (iVar2 = FUN_004680fc(arg_1,arg_2), (int)(&DAT_00681ea8)[DAT_00676504] < iVar2)) {
          local_c = 1;
        }
        else {
          local_c = 0;
        }
        if (local_c != 0) {
          DAT_00676500 = DAT_00676500 | 3;
        }
      }
    }
    else {
      local_c = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
      *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) != -1)) {
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
       *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) = 0;
      if (((int)(&DAT_00681ea8)[DAT_00676504] < (int)(&DAT_00681ea8)[DAT_00676510]) ||
         (iVar2 = FUN_004680fc(arg_1,arg_2), (int)(&DAT_00681ea8)[DAT_00676504] < iVar2)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (((DAT_0066aaf4 != 1) && (DAT_0068f0b0 == 0)) && (DAT_00681eb4 != 1)) {
        bVar1 = true;
      }
      if (bVar1) {
        Ai_CalcManaRequirement_004ba890(DAT_00681eb4,0,4);
        if (DAT_00681ea4 == 1) {
          DAT_00681ea4 = -1;
        }
        else {
          FUN_00467eef(DAT_00690af0,DAT_0068efa0);
        }
      }
    }
    if (((DAT_0068f230 == 0xcb) || (arg_3 == 199)) &&
       ((((arg_2 == DAT_00690c48 && ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))) &&
         (DAT_00681ec4 == arg_1)) &&
        (((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0 ||
          (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2) !=
           0)) && (iVar2 = FUN_004680fc(arg_1,arg_2), iVar2 != 0)))))) {
      if (arg_3 == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if ((arg_3 == 0x7e) || (arg_3 == 199)) {
        iVar2 = arg_1;
        height = arg_2;
        y = FUN_004680fc(arg_1,arg_2);
        Mem_AllocOrFree_004afd1c(DAT_00666458,y,iVar2,height);
        iVar2 = FUN_004680fc(arg_1,arg_2);
        Mem_AllocOrFree_004afd1c(1 - DAT_00666458,iVar2,arg_1,arg_2);
      }
    }
    local_c = 0;
  }
  return local_c;
}


