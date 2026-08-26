/*
 * Decompiled function: FUN_10031697
 * Entry Point: 10031697
 * Size: 330 bytes
 */
#include "deckdll.h"


int32_t FUN_10031697(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int32_t uval_1;
  HGDIOBJ h;
  int local_2c;
  uint8_t local_28 [4];
  int local_24;
  int local_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    h = SelectObject(DAT_10046630,arg_3);
    GetObjectA(arg_3,0x18,local_28);
    local_8 = *arg_2;
    local_c = arg_2[1];
    if (arg_2[2] < *arg_2) {
      local_10 = local_24;
    }
    else {
      local_10 = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      local_2c = local_20;
    }
    else {
      local_2c = arg_2[3] - arg_2[1];
    }
    thunk_FUN_10031425(DAT_10046630);
    if (arg_7 <= local_20) {
      local_20 = arg_7;
    }
    if (arg_6 <= local_24) {
      local_24 = arg_6;
    }
    StretchBlt(hdc,local_8,local_c,local_10,local_2c,DAT_10046630,arg_4,arg_5,local_24,local_20,
               0xcc0020);
    SelectObject(DAT_10046630,h);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    uval_1 = 1;
  }
  return uval_1;
}


