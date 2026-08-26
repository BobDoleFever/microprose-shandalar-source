/*
 * Decompiled function: FUN_0040c267
 * Entry Point: 0040c267
 * Size: 756 bytes
 */
#include "duel.h"


undefined4 FUN_0040c267(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 == 0x6c) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    FUN_004348b2(s_prompts_txt_004f2770,s_PRIMAL_CLAY_004f2764);
    iVar1 = FUN_0045102d(param_1,param_1,param_2,0xffffffff,0xffffffff,&DAT_006679f0,1);
    iVar2 = FUN_004af68f(*(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120));
    if (iVar2 != -1) {
      if (iVar1 == 0) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 1;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 6;
        (&DAT_004ff595)[iVar2 * 0x34] = 0;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0;
      }
      else if (iVar1 == 1) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 2;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 2;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0x20;
      }
      else if (iVar1 == 2) {
        *(undefined2 *)(&DAT_004ff59a + iVar2 * 0x34) = 3;
        *(undefined2 *)(&DAT_004ff59c + iVar2 * 0x34) = 3;
        *(undefined4 *)(&DAT_004ff5a4 + iVar2 * 0x34) = 0;
      }
      *(int *)(&DAT_006826c8 + param_1 * 0x5b20 + param_2 * 0x120) = iVar2;
      *(undefined4 *)(&DAT_006826c4 + param_1 * 0x5b20 + param_2 * 0x120) =
           *(undefined4 *)(&DAT_006826c8 + param_1 * 0x5b20 + param_2 * 0x120);
      *(uint *)(&DAT_006826fc + param_1 * 0x5b20 + param_2 * 0x120) =
           *(uint *)(&DAT_006826fc + param_1 * 0x5b20 + param_2 * 0x120) | 0x1000000;
    }
  }
  if (((param_3 == 0x3c) && ((DAT_00681eb0._2_1_ & 2) == 0)) &&
     ((param_2 == DAT_00690c48 &&
      ((param_1 == DAT_0068ecb0 && (iVar1 = FUN_0048a33f(param_1,param_2), iVar1 != 0)))))) {
    DAT_0066642c = *(undefined4 *)(&DAT_006826c8 + param_1 * 0x5b20 + param_2 * 0x120);
  }
  if (((param_3 == 0x77) && (param_2 == DAT_00690c48)) && (param_1 == DAT_0068ecb0)) {
    FUN_004af72b(*(undefined4 *)(&DAT_006826c8 + param_1 * 0x5b20 + param_2 * 0x120));
  }
  return 0;
}


