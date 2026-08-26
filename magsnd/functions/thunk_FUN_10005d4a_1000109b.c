/*
 * Decompiled function: thunk_FUN_10005d4a
 * Entry Point: 1000109b
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_10005d4a(int arg1,int arg2)

{
  uint16_t uval_1;
  int val_2;
  int val_3;
  
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  uval_1 = *(uint16_t *)(arg1 + 0x84);
  val_2 = *(int *)(arg1 + 0x1e0);
  val_3 = thunk_FUN_10006e80(arg1 + 0x180);
  mmioSeek(*(HMMIO *)(arg1 + 0x1c8),((uint32_t)uval_1 * arg2 + val_2) - val_3,1);
  mmioGetInfo(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  mmioAdvance(*(HMMIO *)(arg1 + 0x1c8),(LPMMIOINFO)(arg1 + 0x180),0);
  return 0;
}


