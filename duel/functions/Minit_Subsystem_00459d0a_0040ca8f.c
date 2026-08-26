/*
 * Decompiled function: Minit_Subsystem_00459d0a
 * Entry Point: 0040ca8f
 * Size: 1041 bytes
 */
#include "duel.h"


undefined4 Minit_Subsystem_00459d0a(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
    FUN_00468097(arg_1,arg_2,3);
  }
  if (((arg_3 == 0x32) || (arg_3 == 0x33)) && ((DAT_00690c48 == arg_2 && (DAT_0068ecb0 == arg_1))))
  {
    iVar2 = FUN_004680fc(arg_1,arg_2);
    DAT_0066642c = DAT_0066642c + iVar2;
  }
  if (arg_3 == 0x73) {
    bVar1 = false;
    if (((DAT_0068f2c4 == 4) && (DAT_00666458 == arg_1)) && (DAT_00681eb4 == arg_1)) {
      iVar2 = FUN_004680fc(arg_1,arg_2);
      if (*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) < iVar2) {
        bVar1 = true;
      }
      else {
        iVar2 = FUN_0040cea5(arg_1,arg_2);
        if (iVar2 != 0) {
          bVar1 = true;
        }
      }
    }
    if (bVar1) {
      if ((DAT_00676504 == arg_1) && (0 < DAT_0068f2c0)) {
        DAT_00676500 = DAT_00676500 | 3;
      }
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    if (((arg_3 == 0x6d) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      iVar2 = FUN_004680fc(arg_1,arg_2);
      iVar2 = iVar2 - *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
      iVar4 = FUN_0040cea5(arg_1,arg_2);
      if ((iVar2 == 3) || ((iVar2 != 0 && (iVar4 == 0)))) {
        Minit_Subsystem_0045a252(arg_1,arg_2,iVar2);
      }
      else if ((iVar2 == 0) && (iVar4 != 0)) {
        *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
      }
      else if ((iVar2 != 0) && (iVar4 != 0)) {
        iVar4 = Ai_Subsystem_004cc56d
                          (arg_1,arg_1,arg_2,-1,-1,s_Launch_tetravite__Dock_tetravite_004f27b4,0);
        if (iVar4 == 0) {
          Minit_Subsystem_0045a252(arg_1,arg_2,iVar2);
        }
        else {
          *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x100;
        }
      }
    }
    if ((arg_3 == 0x72) &&
       (*(int *)(&DAT_006826c4 +
                *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20 +
                *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120) != -1)) {
      if (((&DAT_006826f1)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0) {
        FUN_0040d1af(arg_1,arg_2);
      }
      else {
        Minit_Subsystem_0045a575(arg_1,arg_2);
      }
    }
    if ((((arg_3 == 0x22) || (arg_3 == 199)) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1))
    {
      *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(undefined4 *)(&DAT_006826f0 + arg_2 * 0x120 + arg_1 * 0x5b20);
    }
    uVar3 = 0;
  }
  return uVar3;
}


