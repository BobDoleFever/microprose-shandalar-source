/*
 * Decompiled function: FUN_100318f9
 * Entry Point: 100318f9
 * Size: 129 bytes
 */
#include "deckdll.h"


int32_t FUN_100318f9(HDC arg_1,int *arg_2,HANDLE arg_3)

{
  int32_t uval_1;
  uint8_t local_34 [4];
  int local_30;
  int local_2c;
  int local_1c;
  int local_18;
  int32_t local_14;
  int32_t local_10;
  int32_t local_c;
  int local_8;
  
  GetObjectA(arg_3,0x18,local_34);
  local_18 = local_30 / 2;
  local_1c = local_2c;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_8 = local_18;
  uval_1 = thunk_FUN_1003197a(arg_1,arg_2,arg_3,local_18,local_2c,0,0,local_18,0);
  return uval_1;
}


