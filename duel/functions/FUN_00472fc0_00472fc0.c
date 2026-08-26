/*
 * Decompiled function: FUN_00472fc0
 * Entry Point: 00472fc0
 * Size: 2674 bytes
 */
#include "duel.h"


void FUN_00472fc0(int arg_1)

{
  int iVar1;
  undefined4 uVar2;
  int arg_1_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_14;
  
  arg_1_00 = 1 - arg_1;
  _memset(&DAT_00692c80,0,0x780);
  for (local_14 = 0; local_14 < (int)(&DAT_00666408)[arg_1]; local_14 = local_14 + 1) {
    if ((*(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[local_14 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1 * 0x5b20);
      iVar3 = (int)(char)(&DAT_006826d2)[local_14 * 0x120 + arg_1 * 0x5b20];
      iVar1 = *(int *)(&DAT_006826e8 + local_14 * 0x120 + arg_1 * 0x5b20);
      if ((*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (iVar4 = FUN_0049b309(iVar3,3,1), iVar4 != 0)) {
        *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (iVar4 = FUN_0049b309(iVar3,4,3), iVar4 != 0)) {
        *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        iVar4 = FUN_0049b309(iVar3,4,1);
        *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      *(uint *)(&DAT_006826fc + local_14 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826fc + local_14 * 0x120 + arg_1 * 0x5b20) | 0xe000000;
      uVar2 = *(undefined4 *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20);
      if (arg_1 == DAT_00676504) {
        if (((&DAT_006826cd)[local_14 * 0x120 + arg_1 * 0x5b20] & 0x20) == 0) {
          *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20) | 0x14;
        }
        else {
          *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20) =
               *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20) | 4;
        }
      }
      DAT_00693404 = FUN_0048b81a(arg_1,local_14,0x32,0xffffffff);
      DAT_00693414 = FUN_0048b81a(arg_1,local_14,0x33,0xffffffff);
      DAT_00693410 = FUN_0048b81a(arg_1,local_14,0x34,0xffffffff);
      uVar5 = FUN_0048c367((&DAT_004ff596)[iVar6 * 0x34]);
      if (((DAT_00693410 & 0x200) != 0) && (iVar6 = FUN_0049b309(arg_1,uVar5,1), iVar6 == 0)) {
        DAT_00693410 = DAT_00693410 & 0xfffffdff;
      }
      if (arg_1 == DAT_00676510) {
        FUN_0048c50b(arg_1,local_14,0x8c);
      }
      *(int *)(&DAT_00692c80 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_00692c80 + local_14 * 0xc + arg_1 * 0x3c0) + DAT_00693404;
      *(int *)(&DAT_00692c84 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(int *)(&DAT_00692c84 + local_14 * 0xc + arg_1 * 0x3c0) + DAT_00693414;
      *(uint *)(&DAT_00692c88 + local_14 * 0xc + arg_1 * 0x3c0) =
           *(uint *)(&DAT_00692c88 + local_14 * 0xc + arg_1 * 0x3c0) | DAT_00693410;
      *(undefined4 *)(&DAT_006826cc + local_14 * 0x120 + arg_1 * 0x5b20) = uVar2;
    }
  }
  DAT_00693400 = 0;
  for (local_14 = 0; local_14 < (int)(&DAT_00666408)[arg_1_00]; local_14 = local_14 + 1) {
    if ((*(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1_00 * 0x5b20) != -1) &&
       (((&DAT_006826cc)[local_14 * 0x120 + arg_1_00 * 0x5b20] & 2) != 0)) {
      iVar6 = *(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1_00 * 0x5b20);
      iVar3 = (int)(char)(&DAT_006826d2)[local_14 * 0x120 + arg_1_00 * 0x5b20];
      iVar1 = *(int *)(&DAT_006826e8 + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if ((*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_0043ebbf) &&
         (iVar4 = FUN_0049b309(iVar3,3,1), iVar4 != 0)) {
        *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      else if ((*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_0043f51d) &&
              (iVar4 = FUN_0049b309(iVar3,4,3), iVar4 != 0)) {
        *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(uint *)(&DAT_00692c88 + iVar1 * 0xc + iVar3 * 0x3c0) | 0x200;
        *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) =
             *(uint *)(&DAT_006826fc + iVar1 * 0x120 + iVar3 * 0x5b20) | 0x200;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00435abf) {
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00436f60) {
        iVar4 = FUN_0049b309(iVar3,4,1);
        *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      else if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == Pic_Subsystem_00436500) {
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c80 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
        iVar4 = FUN_0049b309(iVar3,5,1);
        *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) =
             *(int *)(&DAT_00692c84 + iVar1 * 0xc + iVar3 * 0x3c0) + iVar4;
      }
      *(uint *)(&DAT_006826fc + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&DAT_006826fc + local_14 * 0x120 + arg_1_00 * 0x5b20) | 0xe000000;
      uVar2 = *(undefined4 *)(&DAT_006826cc + local_14 * 0x120 + arg_1_00 * 0x5b20);
      *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1_00 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_14 * 0x120 + arg_1_00 * 0x5b20) | 8;
      DAT_00693404 = FUN_0048b81a(arg_1_00,local_14,0x32,0xffffffff);
      DAT_00693414 = FUN_0048b81a(arg_1_00,local_14,0x33,0xffffffff);
      DAT_00693410 = FUN_0048b81a(arg_1_00,local_14,0x34,0xffffffff);
      uVar5 = FUN_0048c367((&DAT_004ff596)[iVar6 * 0x34]);
      if (((DAT_00693410 & 0x200) != 0) && (iVar6 = FUN_0049b309(arg_1_00,uVar5,1), iVar6 == 0)) {
        DAT_00693410 = DAT_00693410 & 0xfffffdff;
      }
      if (DAT_00676510 == arg_1_00) {
        FUN_0048c50b(arg_1_00,local_14,0x8c);
      }
      *(int *)(&DAT_00692c80 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_00692c80 + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_00693404;
      *(int *)(&DAT_00692c84 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(int *)(&DAT_00692c84 + local_14 * 0xc + arg_1_00 * 0x3c0) + DAT_00693414;
      *(uint *)(&DAT_00692c88 + local_14 * 0xc + arg_1_00 * 0x3c0) =
           *(uint *)(&DAT_00692c88 + local_14 * 0xc + arg_1_00 * 0x3c0) | DAT_00693410;
      *(undefined4 *)(&DAT_006826cc + local_14 * 0x120 + arg_1_00 * 0x5b20) = uVar2;
      iVar6 = *(int *)(&DAT_006826c4 + local_14 * 0x120 + arg_1_00 * 0x5b20);
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == FUN_004d2b76) {
        DAT_00693400 = DAT_00693400 | 2;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == FUN_004d2c1b) {
        DAT_00693400 = DAT_00693400 | 4;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == FUN_004d2c52) {
        DAT_00693400 = DAT_00693400 | 8;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == FUN_004d2be4) {
        DAT_00693400 = DAT_00693400 | 0x10;
      }
      if (*(code **)(&DAT_004ff5a0 + iVar6 * 0x34) == FUN_004d2bad) {
        DAT_00693400 = DAT_00693400 | 0x20;
      }
    }
  }
  if (DAT_00693400 == 0) {
    DAT_00693408 = 0;
  }
  else {
    DAT_00693408 = FUN_0049b309(arg_1_00,7,0);
  }
  FUN_0048b64f();
  return;
}


