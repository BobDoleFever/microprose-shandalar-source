/*
 * Decompiled function: FUN_00439659
 * Entry Point: 00439659
 * Size: 145 bytes
 */
#include "duel.h"


void FUN_00439659(char *arg_1,int y,uint arg_3,int arg_4)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    (&DAT_004f71c4)[y * 0xa0 + local_8 * 2] = 0;
    *(undefined4 *)(&DAT_004f71c0 + local_8 * 8 + y * 0x280) =
         (&DAT_004f71c4)[y * 0xa0 + local_8 * 2];
  }
  Deck_FilterAttributes_00492bd9(arg_1,(int)(&DAT_004f71c0 + y * 0x280),arg_3,arg_4);
  return;
}


