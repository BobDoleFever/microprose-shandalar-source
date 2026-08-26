/*
 * Decompiled function: Glue_Subsystem_004d109a
 * Entry Point: 0045283a
 * Size: 3108 bytes
 */
#include "duel.h"


undefined4 Glue_Subsystem_004d109a(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *arg2;
  int local_10;
  
  if (((arg_3 == 0x6c) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) {
    bVar1 = FUN_00439892(5);
    *(int *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0x800 << (bVar1 & 0x1f);
  }
  if (arg_3 == 0x71) {
    *(uint *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826fc + arg_2 * 0x120 + arg_1 * 0x5b20) |
         *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
  }
  if (arg_3 == 0x73) {
    iVar2 = FUN_0049b309(arg_1,5,2);
    if (iVar2 == 0) {
      iVar2 = FUN_0049b309(arg_1,7,1);
      if ((iVar2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    if (arg_3 == 0x6d) {
      iVar2 = FUN_0049b309(arg_1,7,1);
      iVar4 = FUN_0049b309(arg_1,5,2);
      *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      if ((iVar4 != 0) ||
         ((iVar2 != 0 && (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)))) {
        if (iVar4 == 0) {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s__Add_random_power__004f8744);
        }
        else {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Add_random_power__004f8730);
        }
        if ((iVar2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s__Gain_first_strike__004f8770);
        }
        else {
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Gain_first_strike__004f8758);
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f8788);
        if ((DAT_006826b0 == 0) ||
           ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 8) == 0 &&
            ((((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 4) == 0 ||
             (((&DAT_006826cd)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0)))))) {
          if (iVar4 == 0) {
            if ((iVar2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
              local_10 = 2;
            }
            else {
              local_10 = 1;
            }
          }
          else {
            local_10 = 0;
          }
        }
        else if ((iVar2 == 0) || (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0)) {
          if (iVar4 == 0) {
            local_10 = 2;
          }
          else {
            local_10 = 0;
          }
        }
        else {
          local_10 = 1;
        }
        iVar2 = Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,local_10);
        if (iVar2 == 0) {
          if ((iVar4 != 0) && (Ai_CalcManaRequirement_004ba890(arg_1,5,2), DAT_00681ea4 != 1)) {
            *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) {
              *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            }
          }
        }
        else if (iVar2 == 1) {
          Ai_CalcManaRequirement_004ba890(arg_1,0,1);
          if (DAT_00681ea4 != 1) {
            *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_1;
            *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = arg_2;
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
            *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
          }
        }
        else if (iVar2 == 2) {
          DAT_00681ea4 = 1;
        }
      }
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) == -1) {
        DAT_00681ea4 = 1;
      }
      else if (((&DAT_006826f0)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
        uVar5 = FUN_00439892(3);
        *(uint *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(int *)(&DAT_006826e4 +
                     *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                     *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) +
             (uVar5 & 0xff);
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Power_increased_by_004f8794);
        arg2 = (uint *)__itoa(uVar5,&DAT_00522418,10);
        FUN_004d9640((uint *)&DAT_005f6810,arg2);
        Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x2e);
        }
        if ((uVar5 != 0) &&
           (((&DAT_006826e6)
             [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
              *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 8) != 0)) {
          *(uint *)(&DAT_006826e4 +
                   *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                   *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
               *(uint *)(&DAT_006826e4 +
                        *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                        *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) &
               0xfff7ffff;
          iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_0066aaec,DAT_00690af0,DAT_0068efa0);
          if (iVar2 != -1) {
            *(short *)(&DAT_006826d8 + iVar2 * 0x120 + arg_1 * 0x5b20) = (short)uVar5;
            *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            *(undefined4 *)(&DAT_006826f0 + iVar2 * 0x120 + arg_1 * 0x5b20) = 1;
          }
        }
      }
      else if (((&DAT_006826f1)
                [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] & 1) == 0) {
        *(uint *)(&DAT_006826f0 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&DAT_006826f0 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) & 0x1ff800;
        *(uint *)(&DAT_006826f0 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&DAT_006826f0 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) | 0x100;
        (&DAT_006827b8)
        [*(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
         *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120] = 0;
        iVar2 = FUN_004a2b00(DAT_00690af0,DAT_0068efa0,DAT_00667994,DAT_00690af0,DAT_0068efa0);
        if (iVar2 != -1) {
          *(undefined4 *)(&DAT_006826e4 + iVar2 * 0x120 + arg_1 * 0x5b20) = 0x100;
          *(undefined4 *)(&DAT_006826fc + iVar2 * 0x120 + arg_1 * 0x5b20) = 0;
          *(undefined4 *)(&DAT_006826f0 + iVar2 * 0x120 + arg_1 * 0x5b20) = 2;
        }
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x2e);
        }
      }
    }
    if ((((arg_3 == 0x34) && (arg_2 == DAT_00690c48)) && (arg_1 == DAT_0068ecb0)) &&
       (((&DAT_006826cc)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0)) {
      DAT_0066642c = DAT_0066642c |
                     *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x1ff800;
      uVar5 = DAT_0066642c;
      uVar3 = FUN_0048c367((byte)((*(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) &
                                  0x1ff800) >> 10));
      FUN_00464d69(arg_1,arg_2,uVar3);
      DAT_0066642c = uVar5;
    }
    if (((arg_3 == 0x8c) && (arg_2 == DAT_00690c48)) &&
       ((arg_1 == DAT_0068ecb0 && (iVar2 = FUN_0049b309(arg_1,7,1), iVar2 != 0)))) {
      DAT_00693410 = DAT_00693410 | 0x100;
    }
    if ((arg_3 == 0x22) || (arg_3 == 199)) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffeff;
    }
    uVar3 = 0;
  }
  return uVar3;
}


