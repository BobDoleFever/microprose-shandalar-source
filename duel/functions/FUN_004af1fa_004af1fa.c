/*
 * Decompiled function: FUN_004af1fa
 * Entry Point: 004af1fa
 * Size: 1173 bytes
 */
#include "duel.h"


undefined4 FUN_004af1fa(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint arg_11;
  undefined4 arg_11_00;
  uint arg_12;
  undefined4 arg_12_00;
  uint arg_13;
  undefined4 arg_13_00;
  undefined4 arg_14;
  undefined4 arg_15;
  uint arg_16;
  undefined4 arg_16_00;
  uint arg_17;
  undefined4 arg_17_00;
  uint arg_18;
  undefined4 arg_18_00;
  uint arg_19;
  undefined4 arg_19_00;
  uint arg_20;
  int local_508;
  undefined4 local_504 [320];
  
  if (arg_3 == 0x74) {
    if ((DAT_00676504 == arg_1) && (iVar1 = FUN_0049b309(arg_1,7,3), iVar1 == 0)) {
      uVar2 = 0;
    }
    else {
      arg_19_00 = 0;
      arg_18_00 = 0;
      arg_17_00 = 0;
      arg_16_00 = 0xffffffff;
      arg_15 = 0xffffffff;
      arg_14 = 0xffffffff;
      arg_13_00 = 0xffffffff;
      arg_12_00 = 0;
      arg_11_00 = 0;
      uVar2 = FUN_004521e2(arg_1,arg_2);
      uVar2 = FUN_0041bcf0((int *)0x0,0,arg_1,2,2,0x200,2,0,0,uVar2,arg_11_00,arg_12_00,arg_13_00,
                           arg_14,arg_15,arg_16_00,arg_17_00,arg_18_00,arg_19_00);
    }
  }
  else {
    if ((((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) &&
       (iVar1 = FUN_004699cd(arg_1,arg_2,(int)local_504), iVar1 != 0)) {
      for (local_508 = 0; local_508 < DAT_00681ea0; local_508 = local_508 + 1) {
        iVar3 = FUN_00439892(iVar1);
        *(undefined4 *)
         (&DAT_00682718 +
         arg_2 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8)
             = local_504[iVar3 * 2];
        *(undefined4 *)
         (&DAT_0068271c +
         arg_2 * 0x120 + arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8)
             = local_504[iVar3 * 2 + 1];
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] + '\x01';
      }
    }
    if (arg_3 == 0x71) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2c);
        Sleep(0xdac);
      }
      while ((&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] != '\0') {
        (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] =
             (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] + -1;
        arg_20 = 0;
        arg_19 = 0;
        arg_18 = 0;
        arg_17 = 0xffffffff;
        arg_16 = 0xffffffff;
        iVar3 = -1;
        iVar1 = -1;
        arg_13 = 0;
        arg_12 = 0;
        arg_11 = FUN_004521e2(arg_1,arg_2);
        iVar1 = Rules_ParseFilter_0041c0ab
                          (*(int *)(&DAT_00682718 +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8),
                           *(int *)(&DAT_0068271c +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8),
                           (undefined1 *)0x0,arg_1,2,2,0x200,2,0,0,arg_11,arg_12,arg_13,iVar1,iVar3,
                           arg_16,arg_17,arg_18,arg_19,arg_20);
        if (iVar1 != 0) {
          *(short *)(&DAT_006826da +
                    *(int *)(&DAT_0068271c +
                            arg_2 * 0x120 +
                            arg_1 * 0x5b20 +
                            (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x120 +
                    *(int *)(&DAT_00682718 +
                            arg_2 * 0x120 +
                            arg_1 * 0x5b20 +
                            (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20) =
               *(short *)(&DAT_006826da +
                         *(int *)(&DAT_0068271c +
                                 arg_2 * 0x120 +
                                 arg_1 * 0x5b20 +
                                 (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x120
                         + *(int *)(&DAT_00682718 +
                                   arg_2 * 0x120 +
                                   arg_1 * 0x5b20 +
                                   (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) *
                           0x5b20) + -1;
          *(int *)(&DAT_0068270c +
                  *(int *)(&DAT_0068271c +
                          arg_2 * 0x120 +
                          arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8
                          ) * 0x120 +
                  *(int *)(&DAT_00682718 +
                          arg_2 * 0x120 +
                          arg_1 * 0x5b20 + (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8
                          ) * 0x5b20) =
               *(int *)(&DAT_0068270c +
                       *(int *)(&DAT_0068271c +
                               arg_2 * 0x120 +
                               arg_1 * 0x5b20 +
                               (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x120 +
                       *(int *)(&DAT_00682718 +
                               arg_2 * 0x120 +
                               arg_1 * 0x5b20 +
                               (char)(&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] * 8) * 0x5b20)
               + 0x1000000;
          if (DAT_0066aaf4 != 1) {
            FUN_0048d00c(0x2b);
          }
        }
      }
      FUN_0046e571(arg_1,arg_2,2);
    }
    uVar2 = 0;
  }
  return uVar2;
}


