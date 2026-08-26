/*
 * Decompiled function: FUN_004d42d8
 * Entry Point: 004d42d8
 * Size: 686 bytes
 */
#include "duel.h"


undefined4 FUN_004d42d8(int arg_1,int arg_2,int arg_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0068f2d4 = DAT_0068f2d4 + (&DAT_0068ef54)[(1 - arg_1) * 8] * 5 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (DAT_0068ecd0 == -1) {
        uVar2 = 0;
      }
      else {
        if ((((byte)DAT_00681eb0 & 0x20) != 0) &&
           (iVar3 = FUN_0049b68d(arg_1,arg_2,3,2), iVar3 != 0)) {
          uVar10 = 0;
          uVar9 = 0;
          uVar8 = 2;
          uVar7 = 0xffffffff;
          uVar6 = 0xffffffff;
          iVar5 = -1;
          iVar3 = -1;
          uVar4 = 0;
          bVar1 = FUN_004af7bb(arg_1,arg_2,1);
          iVar3 = Rules_ParseFilter_0041c0ab
                            (DAT_0068ecd0,DAT_0068eccc,(undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,
                             1 << (bVar1 & 0x1f),uVar4,iVar3,iVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
          if (iVar3 != 0) {
            return 99;
          }
        }
        uVar2 = 0;
      }
    }
    else {
      if (((arg_3 == 0x6d) && (iVar3 = FUN_0049b68d(arg_1,arg_2,3,2), iVar3 != 0)) &&
         ((DAT_0068ecd0 != -1 && (FUN_0042ecaf(arg_1,arg_2,3,2), DAT_00681ea4 != 1)))) {
        *(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068ecd0;
        *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_0068eccc;
      }
      if (arg_3 == 0x72) {
        uVar10 = 0;
        uVar9 = 0;
        uVar8 = 2;
        uVar7 = 0xffffffff;
        uVar6 = 0xffffffff;
        iVar5 = -1;
        iVar3 = -1;
        uVar4 = 0;
        bVar1 = FUN_004af7bb(arg_1,arg_2,1);
        iVar3 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                           *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),
                           (undefined1 *)0x0,arg_1,2,2,0,0,0,0,0,1 << (bVar1 & 0x1f),uVar4,iVar3,
                           iVar5,uVar6,uVar7,uVar8,uVar9,uVar10);
        if (iVar3 == 0) {
          DAT_00681ea4 = 1;
        }
        else {
          FUN_0046e571(*(int *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20),
                       *(int *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20),1);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}


