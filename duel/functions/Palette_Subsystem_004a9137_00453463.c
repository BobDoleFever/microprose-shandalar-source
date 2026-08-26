/*
 * Decompiled function: Palette_Subsystem_004a9137
 * Entry Point: 00453463
 * Size: 332 bytes
 */
#include "duel.h"


bool Palette_Subsystem_004a9137(int arg_1,int arg_2,int arg_3)

{
  int arg_5;
  bool bVar1;
  
  if (arg_3 == 0x73) {
    bVar1 = (*(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0;
  }
  else {
    if (arg_3 == 0x6d) {
      *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    }
    if (arg_3 == 0x72) {
      arg_5 = FUN_00487ce1(arg_1);
      Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,arg_1,arg_5,s_Sinbad_draws____004f87a8,0);
      if (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_5 * 0x120 + arg_1 * 0x5b20) * 0x34] & 1) ==
          0) {
        FUN_0046f02d(arg_1,arg_5);
        *(undefined4 *)(&DAT_006826c4 + arg_5 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
        (&DAT_0068ee78)[arg_1] = (&DAT_0068ee78)[arg_1] + -1;
        if (DAT_0066aaf4 != 1) {
          FUN_0048d00c(0x18);
        }
      }
    }
    bVar1 = false;
  }
  return bVar1;
}


