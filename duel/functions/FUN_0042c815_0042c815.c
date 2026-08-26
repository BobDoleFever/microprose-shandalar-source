/*
 * Decompiled function: FUN_0042c815
 * Entry Point: 0042c815
 * Size: 425 bytes
 */
#include "duel.h"


void FUN_0042c815(int x,int arg_2,int *arg_3,int height)

{
  ushort uVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
    while ((0 < (int)(&DAT_0068ece0)[local_8] &&
           (0 < *(int *)(&DAT_0068f2e0 + local_8 * 4 + x * 0x20)))) {
      FUN_0042df08(0x68ece0,local_8,1,(int *)0x0,0,x,local_8,arg_2,arg_3);
    }
  }
  while (((0 < DAT_0068ecf8 && (0 < *(int *)(&DAT_0068f2e0 + x * 0x20))) && (height < DAT_0068ecf8))
        ) {
    FUN_0042df08(0x68ece0,6,1,(int *)0x0,0,x,0,arg_2,arg_3);
  }
  local_c = 0;
  while ((local_c < 10 && (*(int *)(&DAT_00666900 + local_c * 4 + x * 0x2c) != -1))) {
    uVar1 = *(ushort *)(&DAT_00666900 + local_c * 4 + x * 0x2c);
    uVar2 = *(uint *)(&DAT_00666900 + local_c * 4 + x * 0x2c);
    while ((0 < *(int *)(&DAT_0068f2e0 + (uint)uVar1 * 4 + x * 0x20) &&
           (0 < (int)(&DAT_0068ece0)[uVar2 >> 0x10]))) {
      FUN_0042df08(0x68ece0,uVar2 >> 0x10,1,(int *)0x0,0,x,(uint)uVar1,arg_2,arg_3);
    }
    local_c = local_c + 1;
  }
  return;
}


