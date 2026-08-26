/*
 * Decompiled function: thunk_FUN_100318f9
 * Entry Point: 1000123f
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100318f9(HDC arg_1,int *arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t auStack_34 [4];
  int iStack_30;
  int iStack_2c;
  int iStack_1c;
  int iStack_18;
  int32_t uStack_14;
  int32_t uStack_10;
  int32_t uStack_c;
  int iStack_8;
  
  GetObjectA(arg_3,0x18,auStack_34);
  iStack_18 = iStack_30 / 2;
  iStack_1c = iStack_2c;
  uStack_10 = 0;
  uStack_c = 0;
  uStack_14 = 0;
  iStack_8 = iStack_18;
  uval_1 = thunk_FUN_1003197a(arg_1,arg_2,arg_3,iStack_18,iStack_2c,0,0,iStack_18,0);
  return uval_1;
}


