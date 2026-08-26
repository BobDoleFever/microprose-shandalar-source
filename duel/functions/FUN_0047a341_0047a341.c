/*
 * Decompiled function: FUN_0047a341
 * Entry Point: 0047a341
 * Size: 779 bytes
 */
#include "duel.h"


void FUN_0047a341(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  uint *puVar1;
  char *str_5;
  char *str_4;
  int iVar2;
  char *str_6;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049b1a9(arg_1,local_8,1);
      }
    }
  }
  if (arg_3 == 0x71) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049aed0(arg_1,local_8,1);
      }
    }
  }
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    if ((arg_4 == DAT_00666748) || (DAT_00666748 == 0)) {
      local_c = arg_4;
    }
    else if (arg_5 == DAT_00666748) {
      local_c = arg_5;
    }
    else {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Which_mana__1__004f9a2c);
      puVar1 = (uint *)Mem_AllocOrFree_0048c420(arg_4);
      FUN_004d9640((uint *)&DAT_005f6810,puVar1);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f9a3c);
      puVar1 = (uint *)Mem_AllocOrFree_0048c420(arg_5);
      FUN_004d9640((uint *)&DAT_005f6810,puVar1);
      str_6 = (char *)0x0;
      str_5 = (char *)Mem_AllocOrFree_0048c420(arg_5);
      str_4 = (char *)Mem_AllocOrFree_0048c420(arg_4);
      iVar2 = FUN_004512d1(arg_1,s_Which_type_of_mana_to_produce__004f9a44,0,str_4,str_5,str_6);
      if (iVar2 == 0) {
        local_c = arg_4;
      }
      else {
        local_c = arg_5;
      }
    }
    FUN_0049b235(arg_1,local_c,1);
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006826dc)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0049b1eb(arg_1,local_8,1);
      }
    }
    *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    DAT_0068f0f4 = local_c;
  }
  return;
}


