/*
 * Decompiled function: thunk_FUN_1000e202
 * Entry Point: 1000165e
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_1000e202(uint8_t *arg_1)

{
  int val_1;
  char acStack_134 [256];
  int iStack_34;
  uint8_t bStack_30;
  uint8_t bStack_2f;
  int iStack_20;
  uint32_t uStack_18;
  char acStack_14 [16];
  
  uStack_18 = 3;
  iStack_34 = 0;
  iStack_20 = 0;
  _splitpath((char *)arg_1,acStack_14,acStack_134,(char *)&bStack_30,acStack_14);
  arg_1 = &bStack_30;
  strcat((char *)&bStack_30,acStack_14);
  while( true ) {
    val_1 = (int)(char)*arg_1;
    arg_1 = arg_1 + 1;
    if (val_1 == 0) break;
    if ((uStack_18 & 1) == 0) {
      iStack_20 = uStack_18 * val_1 + iStack_20;
    }
    else {
      iStack_34 = uStack_18 * val_1 + iStack_34;
    }
    uStack_18 = uStack_18 + 1;
  }
  return (int)(char)(bStack_2f ^ bStack_30) << 0x18 | iStack_20 * iStack_34 & 0xffffffU;
}


