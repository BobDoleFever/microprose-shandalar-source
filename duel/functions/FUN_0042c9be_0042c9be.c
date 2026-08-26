/*
 * Decompiled function: FUN_0042c9be
 * Entry Point: 0042c9be
 * Size: 509 bytes
 */
#include "duel.h"


void FUN_0042c9be(int arg_1,int arg_2,int *arg_3,int arg_4,int *arg_5,int arg_6)

{
  ushort uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    if ((&DAT_0068ece0)[local_8] == -1) {
      while ((0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + arg_1 * 0x20) &&
             ((DAT_00681ea0 < arg_6 || (arg_6 == -1))))) {
        FUN_0042df08(0x68ece0,local_8,1,arg_5,arg_6,arg_1,local_8,arg_2,arg_3);
      }
    }
  }
  if (DAT_0068ecf8 == -1) {
    while (((0 < *(int *)(&DAT_0068f2e0 + arg_1 * 0x20) && (arg_4 < DAT_0068ecf8)) &&
           ((DAT_00681ea0 < arg_6 || (arg_6 == -1))))) {
      FUN_0042df08(0x68ece0,6,1,arg_5,arg_6,arg_1,0,arg_2,arg_3);
    }
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&DAT_00666900 + local_c * 4 + arg_1 * 0x2c) != -1))) {
    uVar1 = *(ushort *)(&DAT_00666900 + local_c * 4 + arg_1 * 0x2c);
    uVar2 = *(uint *)(&DAT_00666900 + local_c * 4 + arg_1 * 0x2c);
    if ((&DAT_0068ece0)[uVar2 >> 0x10] == -1) {
      while ((0 < *(int *)(&DAT_0068f2e0 + (uint)uVar1 * 4 + arg_1 * 0x20) &&
             ((DAT_00681ea0 < arg_6 || (arg_6 == -1))))) {
        FUN_0042df08(0x68ece0,uVar2 >> 0x10,1,arg_5,arg_6,arg_1,(uint)uVar1,arg_2,arg_3);
      }
    }
    local_c = local_c + 1;
  }
  return;
}


