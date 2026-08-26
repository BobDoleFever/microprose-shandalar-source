/*
 * Decompiled function: FUN_004beda5
 * Entry Point: 004beda5
 * Size: 2442 bytes
 */
#include "duel.h"


undefined4 FUN_004beda5(int x,int y,int width,uint height)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 arg_11;
  int iVar6;
  undefined4 arg_12;
  uint uVar7;
  undefined4 arg_13;
  uint uVar8;
  undefined4 arg_14;
  uint uVar9;
  undefined4 arg_15;
  uint uVar10;
  undefined4 arg_16;
  uint uVar11;
  undefined4 arg_17;
  undefined *arg_18;
  undefined4 arg_18_00;
  undefined4 arg_19;
  int *arg_20;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (width == 0x74) {
    arg_19 = 0;
    arg_18_00 = 0;
    arg_17 = 0;
    arg_16 = 0xffffffff;
    arg_15 = 0xffffffff;
    arg_14 = 0xffffffff;
    arg_13 = 0xffffffff;
    arg_12 = 0;
    arg_11 = 0;
    uVar1 = FUN_004521e2(x,y);
    uVar1 = FUN_0041bcf0((int *)0x0,0,x,2,2,0x200,height,0,0,uVar1,arg_11,arg_12,arg_13,arg_14,
                         arg_15,arg_16,arg_17,arg_18_00,arg_19);
  }
  else {
    if (((width == 0x6c) && (DAT_00690c48 == y)) && (DAT_0068ecb0 == x)) {
      arg_20 = &local_14;
      uVar1 = 1;
      arg_18 = &DAT_006679f0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(x,y);
      iVar5 = Action_ValidateTarget_0041e2a2
                        (x,2,1 - x,0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,
                         uVar10,uVar11,arg_18,uVar1,arg_20);
      if (iVar5 == 0) {
        DAT_00681ea4 = 1;
      }
      else {
        *(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) = local_14;
        *(undefined4 *)(&DAT_0068271c + y * 0x120 + x * 0x5b20) = local_10;
        (&DAT_006827b8)[y * 0x120 + x * 0x5b20] = 1;
      }
    }
    if (width == 0x71) {
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar8 = 0xffffffff;
      uVar7 = 0xffffffff;
      iVar6 = -1;
      iVar5 = -1;
      uVar4 = 0;
      uVar3 = 0;
      uVar2 = FUN_004521e2(x,y);
      iVar5 = Rules_ParseFilter_0041c0ab
                        (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20),
                         *(int *)(&DAT_0068271c + y * 0x120 + x * 0x5b20),(undefined1 *)0x0,x,2,2,
                         0x200,height,0,0,uVar2,uVar3,uVar4,iVar5,iVar6,uVar7,uVar8,uVar9,uVar10,
                         uVar11);
      if (iVar5 == 0) {
        FUN_0046e571(x,y,1);
        DAT_00681ea4 = 1;
      }
      else {
        (&DAT_006826d2)[y * 0x120 + x * 0x5b20] = (&DAT_00682718)[y * 0x120 + x * 0x5b20];
        *(undefined4 *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) =
             *(undefined4 *)(&DAT_0068271c + y * 0x120 + x * 0x5b20);
        for (local_c = 0; local_c < 2; local_c = local_c + 1) {
          for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_c]; local_8 = local_8 + 1) {
            if ((((*(int *)(&DAT_004ff590 +
                           *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34) ==
                   0x2c) ||
                 (*(int *)(&DAT_004ff590 +
                          *(int *)(&DAT_006826c4 + local_8 * 0x120 + local_c * 0x5b20) * 0x34) ==
                  0xea)) &&
                ((((&DAT_006826cc)[local_8 * 0x120 + local_c * 0x5b20] & 2) != 0 &&
                 (((&DAT_006826d2)[local_8 * 0x120 + local_c * 0x5b20] ==
                   (&DAT_006826d2)[y * 0x120 + x * 0x5b20] &&
                  (*(int *)(&DAT_006826e8 + local_8 * 0x120 + local_c * 0x5b20) ==
                   *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20))))))) &&
               (((&DAT_006826fb)[local_8 * 0x120 + local_c * 0x5b20] & 1) != 0)) {
              *(uint *)(&DAT_006826f8 + local_8 * 0x120 + local_c * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + local_8 * 0x120 + local_c * 0x5b20) & 0xfeffffff;
              (&DAT_006826d3)[y * 0x120 + x * 0x5b20] = (undefined1)local_c;
              *(int *)(&DAT_006826ec + y * 0x120 + x * 0x5b20) = local_8;
            }
          }
        }
        *(uint *)(&DAT_006826f8 + y * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826f8 + y * 0x120 + x * 0x5b20) | 0x1000000;
        if (*(int *)(&DAT_00682718 + y * 0x120 + x * 0x5b20) != x) {
          local_8 = FUN_004bf853((int)(char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20],
                                 *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20));
          (&DAT_006826d2)[y * 0x120 + x * 0x5b20] = (undefined1)x;
          *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) = local_8;
        }
      }
      (&DAT_006827b8)[y * 0x120 + x * 0x5b20] = 0;
    }
    if (((((DAT_0068f230 == 0xd4) && (DAT_00690c48 == y)) && (DAT_0068ecb0 == x)) &&
        (((&DAT_006826d2)[y * 0x120 + x * 0x5b20] != -1 &&
         (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1)))) &&
       ((DAT_00666754 == x && ((DAT_0068edd0 == y && (x == DAT_00681ec4)))))) {
      if (width == 0x7d) {
        DAT_0066642c = DAT_0066642c | 2;
      }
      if (width == 0x7e) {
        if (((&DAT_006826fb)[y * 0x120 + x * 0x5b20] & 1) == 0) {
          FUN_00467d65(FUN_004bf72f,-1);
        }
        else if ((&DAT_006826d3)[y * 0x120 + x * 0x5b20] == -1) {
          if ((*(int *)(&DAT_006826c4 +
                       *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) * 0x120 +
                       (char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] * 0x5b20) != -1) &&
             (((((&DAT_006826ce)
                 [*(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) != 0 &&
               ((char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] == DAT_00676510)) ||
              ((((&DAT_006826ce)
                 [*(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20) * 0x120 +
                  (char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] * 0x5b20] & 0x40) == 0 &&
               ((char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20] == DAT_00676504)))))) {
            FUN_004bf853((int)(char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20],
                         *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20));
          }
        }
        else {
          *(uint *)(&DAT_006826f8 +
                   *(int *)(&DAT_006826ec + y * 0x120 + x * 0x5b20) * 0x120 +
                   (char)(&DAT_006826d3)[y * 0x120 + x * 0x5b20] * 0x5b20) =
               *(uint *)(&DAT_006826f8 +
                        *(int *)(&DAT_006826ec + y * 0x120 + x * 0x5b20) * 0x120 +
                        (char)(&DAT_006826d3)[y * 0x120 + x * 0x5b20] * 0x5b20) | 0x1000000;
          if ((&DAT_006826d3)[y * 0x120 + x * 0x5b20] != (&DAT_006826d2)[y * 0x120 + x * 0x5b20]) {
            FUN_004bf853((int)(char)(&DAT_006826d2)[y * 0x120 + x * 0x5b20],
                         *(int *)(&DAT_006826e8 + y * 0x120 + x * 0x5b20));
          }
        }
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}


