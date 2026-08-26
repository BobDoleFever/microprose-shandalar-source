/*
 * Decompiled function: Pic_Subsystem_0043b424
 * Entry Point: 004ce22a
 * Size: 710 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043b424(int arg_1,int arg_2,int arg_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *arg2;
  int local_28;
  int local_20;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar2 = 1;
  }
  else {
    if (((arg_3 == 2) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      DAT_0066642c = DAT_0066642c | 2;
    }
    if (arg_3 == 0x6c) {
      iVar5 = *(int *)(&DAT_0068edfc + arg_1 * 0x20);
      iVar3 = FUN_0049aa14(*(int *)(&DAT_0068ee80 + arg_1 * 4),1,99);
      iVar1 = *(int *)(&DAT_0068edfc + (1 - arg_1) * 0x20);
      iVar4 = FUN_0049aa14(*(int *)(&DAT_0068ee70 + (5 - arg_1) * 4),1,99);
      DAT_0068f2d4 = DAT_0068f2d4 + ((iVar5 * 0xc) / iVar3 - (iVar1 * 0xc) / iVar4);
    }
    if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
      local_10 = 999;
      local_20 = 0;
      local_14 = 0xffffffff;
      for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
        for (local_c = 0; local_c < (int)(&DAT_00666408)[local_8]; local_c = local_c + 1) {
          iVar5 = FUN_0048a33f(local_8,local_c);
          if ((iVar5 != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) * 0x34]
              & 2) != 0)) {
            iVar5 = FUN_0048b81a(local_8,local_c,0x32,0xffffffff);
            if (iVar5 < local_10) {
              local_14 = local_8 * 0x100 + local_c;
              local_20 = 0;
              local_10 = iVar5;
            }
            if (iVar5 == local_10) {
              local_20 = local_20 + 1;
            }
          }
        }
      }
      if (local_20 == 1) {
        FUN_0046e571((int)local_14 >> 8,local_14 & 0xff,1);
      }
      if (1 < local_20) {
        do {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Lowest_power_is_00508d6c);
          arg2 = (uint *)__itoa(local_10,&DAT_005dce10,10);
          FUN_004d9640((uint *)&DAT_005f6810,arg2);
          local_18 = -1;
          if (local_28 != -1) {
            local_18 = FUN_0048b81a(DAT_0068eef0,local_28,0x32,0xffffffff);
          }
        } while (local_18 != local_10);
        FUN_0046e571(DAT_0068eef0,local_28,1);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


