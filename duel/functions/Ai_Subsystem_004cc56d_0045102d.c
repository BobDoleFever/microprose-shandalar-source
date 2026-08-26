/*
 * Decompiled function: Ai_Subsystem_004cc56d
 * Entry Point: 0045102d
 * Size: 592 bytes
 */
#include "duel.h"


int Ai_Subsystem_004cc56d(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,uint *arg_6,int arg_7)

{
  int iVar1;
  bool bVar2;
  undefined4 local_274;
  uint local_26c [150];
  int local_14;
  int local_c;
  uint local_8;
  
  if ((((DAT_0066aaf4 != 1) && (-1 < arg_1)) && (-1 < arg_2)) && (-1 < arg_3)) {
    Mem_AllocOrFree_004d9630(local_26c,arg_6);
    DAT_005f6810 = 0;
    if (arg_1 == DAT_00676510) {
      FUN_0044a5a4(arg_2,arg_3);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_004f8608);
    }
    else {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_00666500);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_selects__004f85fc);
      local_8 = 1;
      local_14 = arg_7;
      for (local_c = 0; iVar1 = local_14, local_c < 1000; local_c = local_c + 1) {
        if (((local_8 != 0) && (*(char *)((int)local_26c + local_c) == ' ')) &&
           (local_14 = local_14 + -1, iVar1 == 0)) {
          *(undefined1 *)((int)local_26c + local_c) = 0x3e;
          break;
        }
        bVar2 = *(char *)((int)local_26c + local_c) != '\n';
        if (bVar2) {
          local_8 = 0;
        }
        else {
          local_8 = 1;
        }
        local_8 = (uint)!bVar2;
      }
    }
    FUN_004d9640((uint *)&DAT_005f6810,local_26c);
    if ((*(int *)(&DAT_006826c4 + arg_3 * 0x120 + arg_2 * 0x5b20) == -1) ||
       (*(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_4 * 0x5b20) == -1)) {
      FUN_00451482(1,0xff);
    }
    if ((arg_1 == DAT_00676510) && (DAT_0068f0b0 == 0)) {
      local_274 = 1;
    }
    else {
      local_274 = 0;
    }
    iVar1 = FUN_00446c16(arg_2,arg_3,arg_4,arg_5,&DAT_005f6810,local_274);
    if ((arg_1 == DAT_00676510) && (DAT_0068f0b0 == 0)) {
      arg_7 = iVar1;
    }
  }
  return arg_7;
}


