/*
 * Decompiled function: __CrtMemDifference
 * Entry Point: 00404df0
 * Size: 312 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtMemDifference
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __CrtMemDifference(int32_t *ptr_1,int arg_2,int arg_3)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t local_c;
  int local_8;
  
  local_c = 0;
  if (((ptr_1 == (int32_t *)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
    local_c = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      ptr_1[local_8 + 6] =
           *(int *)(arg_3 + 0x18 + local_8 * 4) - *(int *)(arg_2 + 0x18 + local_8 * 4);
      ptr_1[local_8 + 1] = *(int *)(arg_3 + 4 + local_8 * 4) - *(int *)(arg_2 + 4 + local_8 * 4);
      if (((ptr_1[local_8 + 6] != 0) || (ptr_1[local_8 + 1] != 0)) &&
         ((local_8 != 0 && ((local_8 != 2 || (((uint8_t)DAT_00412e28 & 0x10) != 0)))))) {
        local_c = 1;
      }
    }
    ptr_1[0xb] = *(int *)(arg_3 + 0x2c) - *(int *)(arg_2 + 0x2c);
    ptr_1[0xc] = *(int *)(arg_3 + 0x30) - *(int *)(arg_2 + 0x30);
    *ptr_1 = 0;
  }
  return local_c;
}


