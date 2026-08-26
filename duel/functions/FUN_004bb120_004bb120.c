/*
 * Decompiled function: FUN_004bb120
 * Entry Point: 004bb120
 * Size: 1278 bytes
 */
#include "duel.h"


undefined4 FUN_004bb120(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  
  if (arg_3 == 0x74) {
    uVar3 = 1;
  }
  else {
    if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (iVar4 = FUN_00404b06(arg_1,*(int *)(&DAT_006826c4 + arg_2 * 0x120 + arg_1 * 0x5b20),arg_1),
       iVar4 == 0)) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x30;
    }
    if ((((DAT_0068f230 == 0xcf) && (DAT_0068f2c4 == 10)) &&
        ((DAT_00666458 == DAT_00681ec4 && ((DAT_00690c48 == arg_2 && (DAT_0068ecb0 == arg_1)))))) &&
       (DAT_00681ec4 == arg_1)) {
      if (arg_3 == 0x7d) {
        if (DAT_00676504 == arg_1) {
          if (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) == 0) {
            *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 2;
            local_c = 0;
            bVar1 = false;
            while ((local_c < (int)(&DAT_00666408)[DAT_00676510] && (!bVar1))) {
              iVar4 = *(int *)(&DAT_006826c4 + local_c * 0x120 + DAT_00676510 * 0x5b20);
              if (((iVar4 != -1) &&
                  (((((&DAT_006826cc)[local_c * 0x120 + DAT_00676510 * 0x5b20] & 2) != 0 &&
                    (((&DAT_004ff594)[iVar4 * 0x34] & 2) != 0)) &&
                   (((&DAT_006826fc)[local_c * 0x120 + DAT_00676510 * 0x5b20] & 0x20) == 0)))) &&
                 (((iVar5 = DAT_00676510 * 0x5b20, cVar2 = FUN_004af74c(arg_1,arg_2,2),
                   (*(uint *)(&DAT_006826fc + local_c * 0x120 + iVar5) & 1 << (cVar2 - 1U & 0x1f))
                   == 0 && ((&DAT_004ff595)[iVar4 * 0x34] == '\0')) &&
                  (((&DAT_006826f9)[local_c * 0x120 + DAT_00676510 * 0x5b20] & 8) == 0)))) {
                bVar1 = true;
              }
              local_c = local_c + 1;
            }
            if ((bVar1) && (iVar4 = FUN_00439892(8 - (&DAT_0068ee78)[arg_1]), iVar4 == 0)) {
              *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
            }
          }
          if (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) != 0) {
            DAT_0066642c = DAT_0066642c | 2;
          }
        }
        else {
          DAT_0066642c = DAT_0066642c | 1;
        }
      }
      if (arg_3 == 0x7e) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
        *(undefined4 *)(&DAT_006663e8 + arg_1 * 4) = 1;
        iVar4 = FUN_004a2b00(arg_1,arg_2,DAT_00681ec8,-1,-1);
        if (iVar4 != -1) {
          *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) | 0x400020;
          cVar2 = FUN_004af74c(arg_1,arg_2,2);
          *(uint *)(&DAT_006826e4 + iVar4 * 0x120 + arg_1 * 0x5b20) =
               1 << (cVar2 - 1U & 0x1f) | 0x20;
          if (((&DAT_006826f8)[arg_2 * 0x120 + arg_1 * 0x5b20] & 2) != 0) {
            *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826f8 + iVar4 * 0x120 + arg_1 * 0x5b20) | 2;
            for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
              (&DAT_006827bf)[local_10 + arg_1 * 0x5b20 + iVar4 * 0x120] =
                   (&DAT_006827bf)[local_10 + arg_1 * 0x5b20 + arg_2 * 0x120];
            }
          }
        }
        DAT_0068ef90 = 1;
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1))
    {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}


