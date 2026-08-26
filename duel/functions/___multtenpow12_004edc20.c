/*
 * Decompiled function: ___multtenpow12
 * Entry Point: 004edc20
 * Size: 216 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___multtenpow12
   
   Library: Visual Studio 1998 Debug */

void ___multtenpow12(int *arg_1,uint arg_2,int arg_3)

{
  uint uVar1;
  ushort local_18;
  undefined4 uStack_16;
  undefined2 uStack_12;
  undefined4 local_10;
  ushort *local_c;
  undefined *local_8;
  
  local_8 = &DAT_0050a888;
  if (arg_2 != 0) {
    if ((int)arg_2 < 0) {
      arg_2 = -arg_2;
      local_8 = &DAT_0050a9e8;
    }
    uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16);
    if (arg_3 == 0) {
      *(undefined2 *)arg_1 = 0;
      uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16);
    }
    while (arg_2 != 0) {
      local_8 = local_8 + 0x54;
      uVar1 = arg_2 & 7;
      arg_2 = (int)arg_2 >> 3;
      if (uVar1 != 0) {
        local_c = (ushort *)(local_8 + uVar1 * 0xc);
        if (0x7fff < *local_c) {
          local_18 = (ushort)*(undefined4 *)local_c;
          uStack_16._0_2_ = (undefined2)((uint)*(undefined4 *)local_c >> 0x10);
          uStack_16._2_2_ = (undefined2)*(undefined4 *)(local_c + 2);
          uStack_12 = (undefined2)((uint)*(undefined4 *)(local_c + 2) >> 0x10);
          local_10 = *(undefined4 *)(local_c + 4);
          uStack_16 = CONCAT22(uStack_16._2_2_,(undefined2)uStack_16) + -1;
          local_c = &local_18;
        }
        ___ld12mul(arg_1,(int *)local_c);
      }
    }
  }
  return;
}


