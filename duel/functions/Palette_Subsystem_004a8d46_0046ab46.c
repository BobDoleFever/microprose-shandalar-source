/*
 * Decompiled function: Palette_Subsystem_004a8d46
 * Entry Point: 0046ab46
 * Size: 658 bytes
 */
#include "duel.h"


undefined4 Palette_Subsystem_004a8d46(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int arg_1_00;
  int local_50c;
  undefined4 local_508 [320];
  int local_8;
  
  if (arg_3 == 0x74) {
    if ((DAT_00676504 == arg_1) && (iVar1 = FUN_0049b309(arg_1,7,3), iVar1 == 0)) {
      return 0;
    }
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 0x6c) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = DAT_00681ea0;
    }
    if (arg_3 == 0x71) {
      for (local_50c = 0; local_50c < *(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20);
          local_50c = local_50c + 1) {
        iVar1 = FUN_00439892(0x10);
        if (*(int *)(&DAT_004f9340 + iVar1 * 4) != 0) {
          arg_1_00 = FUN_0046add8(arg_1,arg_2,(int)local_508,*(uint *)(&DAT_004f9340 + iVar1 * 4));
          if (arg_1_00 == 0) {
            DAT_00681ea4 = 1;
          }
          else {
            local_8 = FUN_00439892(arg_1_00);
            *(undefined4 *)(&DAT_00682718 + arg_2 * 0x120 + arg_1 * 0x5b20) = local_508[local_8 * 2]
            ;
            *(undefined4 *)(&DAT_0068271c + arg_2 * 0x120 + arg_1 * 0x5b20) =
                 local_508[local_8 * 2 + 1];
            (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 1;
          }
        }
        if (DAT_00681ea4 == 1) {
          if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed(s_fizzle_004f941c);
            Sleep(0x5dc);
            Mem_AllocOrFree_00450eed(&DAT_004f9424);
          }
          DAT_00681ea4 = 0;
        }
        else {
          Palette_Subsystem_004a9137(arg_1,arg_2,iVar1);
        }
      }
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x2d);
      }
      (&DAT_006827b8)[arg_2 * 0x120 + arg_1 * 0x5b20] = 0;
      FUN_0046e571(arg_1,arg_2,1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


