/*
 * Decompiled function: FUN_00412237
 * Entry Point: 00412237
 * Size: 467 bytes
 */
#include "duel.h"


undefined4 FUN_00412237(int x,int y,int width,int height)

{
  byte bVar1;
  int iVar2;
  
  if (((width == 0x6c) && (DAT_00690c48 == y)) && (DAT_0068ecb0 == x)) {
    DAT_0068f2d4 = DAT_0068f2d4 + *(int *)(&DAT_0068ef50 + height * 4 + DAT_00676504 * 0x20) * 0xc;
  }
  if (((DAT_0068f230 == 0xd3) && (DAT_00690c48 == y)) &&
     ((DAT_0068ecb0 == x &&
      ((DAT_00681ec4 == x && (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x20) == 0)))))) {
    iVar2 = FUN_0049b309(x,7,1);
    if (iVar2 != 0) {
      bVar1 = FUN_004af7bb(x,y,height);
      if (((1 << (bVar1 & 0x1f) &
           (int)(char)(&DAT_006826dd)[DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20]) != 0) &&
         ((&DAT_004ff594)
          [*(int *)(&DAT_006826c4 + DAT_0068edd0 * 0x120 + DAT_00666754 * 0x5b20) * 0x34] != '\x01')
         ) {
        if (width == 0x7d) {
          if (DAT_00676504 == x) {
            DAT_0066642c = DAT_0066642c | 2;
          }
          else {
            DAT_0066642c = DAT_0066642c | 1;
          }
        }
        if (width == 0x7e) {
          Ai_CalcManaRequirement_004ba890(x,0,1);
          if ((DAT_00681ea4 != 1) &&
             ((&DAT_00681ea8)[x] = (&DAT_00681ea8)[x] + 1, DAT_00676504 == x)) {
            DAT_0068f2d4 = DAT_0068f2d4 + -0x18;
          }
        }
      }
    }
  }
  return 0;
}


