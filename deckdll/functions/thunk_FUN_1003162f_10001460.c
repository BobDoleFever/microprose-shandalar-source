/*
 * Decompiled function: thunk_FUN_1003162f
 * Entry Point: 10001460
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1003162f(int arg_1,int arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t auStack_1c [4];
  int iStack_18;
  int iStack_14;
  
  if (((arg_1 == 0) || (arg_2 == 0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    GetObjectA(arg_3,0x18,auStack_1c);
    uval_1 = thunk_FUN_10031697((HDC)arg_1,(int *)arg_2,arg_3,0,0,iStack_18,iStack_14);
  }
  return uval_1;
}


