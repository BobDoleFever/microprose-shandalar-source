/*
 * Decompiled function: FUN_1003162f
 * Entry Point: 1003162f
 * Size: 104 bytes
 */
#include "deckdll.h"


int32_t FUN_1003162f(int arg_1,int arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_1c [4];
  int local_18;
  int local_14;
  
  if (((arg_1 == 0) || (arg_2 == 0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,local_1c);
    uval_1 = thunk_FUN_10031697((HDC)arg_1,(int *)arg_2,arg_3,0,0,local_18,local_14);
  }
  return uval_1;
}


