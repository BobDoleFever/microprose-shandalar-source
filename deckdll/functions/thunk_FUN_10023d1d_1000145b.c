/*
 * Decompiled function: thunk_FUN_10023d1d
 * Entry Point: 1000145b
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_10023d1d(uint8_t *arg1,int arg2)

{
  uint8_t arg_1;
  int arg_3;
  uint32_t uStack_10;
  int iStack_c;
  uint32_t uStack_8;
  
  uStack_8 = uStack_8 & 0xffffff00;
  iStack_c = 0;
  while (iStack_c < arg2) {
    arg_1 = *arg1;
    uStack_8 = CONCAT31(uStack_8._1_3_,arg_1);
    if ((arg2 - iStack_c == 1) || (arg1[1] != arg_1)) {
      thunk_FUN_10023e33(arg_1);
      iStack_c = iStack_c + 1;
      arg1 = arg1 + 1;
    }
    else {
      arg_3 = arg2 - iStack_c;
      if (0x3e < arg_3) {
        arg_3 = 0x3f;
      }
      uStack_10 = thunk_FUN_10023e82(arg_1,(char *)arg1,arg_3);
      iStack_c = iStack_c + uStack_10;
      arg1 = arg1 + uStack_10;
      uStack_10 = uStack_10 | 0xc0;
      fwrite(&uStack_10,1,1,DAT_1013f728);
      fwrite(&uStack_8,1,1,DAT_1013f728);
    }
  }
  if (iStack_c < DAT_10140772) {
    uStack_8 = (uint32_t)uStack_8._1_3_ << 8;
    fwrite(&uStack_8,1,1,DAT_1013f728);
  }
  return 1;
}


