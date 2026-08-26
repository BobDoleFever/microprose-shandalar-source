/*
 * Decompiled function: FUN_0045247b
 * Entry Point: 0045247b
 * Size: 959 bytes
 */
#include "duel.h"


undefined4 FUN_0045247b(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  byte local_8;
  
  if (((((DAT_0068f230 == 0xc9) || (arg_3 == 199)) && (arg_2 == DAT_00690c48)) &&
      ((arg_1 == DAT_0068ecb0 && (arg_1 == DAT_00666458)))) && (DAT_00681ec4 == arg_1)) {
    if (arg_3 == 0x7d) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if ((arg_3 == 0x7e) || (arg_3 == 199)) {
      if (DAT_0066aaf4 != 1) {
        FUN_0048d00c(0x29);
      }
      iVar2 = FUN_00439892(5);
      local_8 = (byte)(iVar2 + 1);
      (&DAT_006826dd)[arg_2 * 0x120 + arg_1 * 0x5b20] = (char)(1 << (local_8 & 0x1f));
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_changes_color_to_004f8708);
      puVar3 = (uint *)Mem_AllocOrFree_0048c420(iVar2 + 1);
      FUN_004d9640((uint *)&DAT_005f6810,puVar3);
      FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
    }
  }
  if (arg_3 == 0x73) {
    if ((*(int *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) == 0) &&
       (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  else {
    if ((arg_3 == 0x6d) && (iVar2 = FUN_0049b309(arg_1,7,2), iVar2 != 0)) {
      FUN_0042b6b0(arg_1,0,2);
    }
    if (arg_3 == 0x72) {
      if (*(int *)(&DAT_006826c4 +
                  *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                  *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) == -1) {
        DAT_00681ea4 = 1;
      }
      else {
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x29);
        }
        iVar2 = FUN_00439892(5);
        local_8 = (byte)(iVar2 + 1);
        (&DAT_006826dd)
        [*(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
         *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20] =
             (char)(1 << (local_8 & 0x1f));
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_changes_color_to_004f871c);
        puVar3 = (uint *)Mem_AllocOrFree_0048c420(iVar2 + 1);
        FUN_004d9640((uint *)&DAT_005f6810,puVar3);
        FUN_0045102d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
        *(uint *)(&DAT_006826e4 +
                 *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                 *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) =
             *(uint *)(&DAT_006826e4 +
                      *(int *)(&DAT_006827b4 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x120 +
                      *(int *)(&DAT_006827b0 + arg_2 * 0x120 + arg_1 * 0x5b20) * 0x5b20) |
             1 << ((byte)DAT_00666458 & 0x1f);
      }
    }
    if ((arg_2 == DAT_00690c48) && (arg_1 == DAT_0068ecb0)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      *(undefined4 *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
    }
    uVar4 = 0;
  }
  return uVar4;
}


