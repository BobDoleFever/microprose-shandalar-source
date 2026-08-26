/*
 * Decompiled function: thunk_FUN_1000394f
 * Entry Point: 10001023
 * Size: 5 bytes
 */
#include "magsnd.h"


int __cdecl thunk_FUN_1000394f(int32_t *ptr_1)

{
  int val_1;
  
  ptr_1[1] = ptr_1[1] & 0xfffffffe;
  ptr_1[1] = ptr_1[1] & 0xfffffffd;
  ptr_1[1] = ptr_1[1] & 0xffffffef;
  ptr_1[1] = ptr_1[1] & 0xfffffffb;
  ptr_1[0x74] = 0;
  ptr_1[0x75] = 0;
  ptr_1[0x76] = 0;
  ptr_1[0x77] = 0;
  DAT_1000a438 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    ptr_1[0x67] = ptr_1[0x68];
    mmioSetInfo((HMMIO)ptr_1[0x72],(LPCMMIOINFO)(ptr_1 + 0x60),0);
    val_1 = thunk_FUN_10005f0c(ptr_1,0);
    if (val_1 != 0) {
      return val_1;
    }
  }
  else {
    thunk_FUN_1000630c(ptr_1);
  }
  ptr_1[1] = ptr_1[1] | 0x20;
  return 0;
}


