/*
 * Decompiled function: FUN_00409f99
 * Entry Point: 00409f99
 * Size: 145 bytes
 */
#include "magic.h"


void FUN_00409f99(char *str_1,int y,uint width,int height)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x50; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + y * 0x280) = 0;
    *(undefined4 *)(&DAT_00516cb8 + local_8 * 8 + y * 0x280) =
         *(undefined4 *)(&DAT_00516cbc + local_8 * 8 + y * 0x280);
  }
  Deck_FilterAttributes_00406b4c(str_1,(int)(&DAT_00516cb8 + y * 0x280),width,height);
  return;
}


