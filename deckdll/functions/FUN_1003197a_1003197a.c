/*
 * Decompiled function: FUN_1003197a
 * Entry Point: 1003197a
 * Size: 379 bytes
 */
#include "deckdll.h"


int32_t
FUN_1003197a(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9)

{
  int32_t uval_1;
  int local_30;
  uint8_t local_2c [24];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    local_10 = SaveDC(hdc);
    SelectObject(DAT_10046630,arg_3);
    GetObjectA(arg_3,0x18,local_2c);
    local_8 = *arg_2;
    local_c = arg_2[1];
    if (arg_2[2] < *arg_2) {
      local_14 = arg_4;
    }
    else {
      local_14 = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      local_30 = arg_5;
    }
    else {
      local_30 = arg_2[3] - arg_2[1];
    }
    thunk_FUN_10031425(DAT_10046630);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_10046630,arg_8,arg_9,arg_4,arg_5,0x8800c6);
    thunk_FUN_10031425(DAT_10046630);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_10046630,arg_6,arg_7,arg_4,arg_5,0xee0086);
    RestoreDC(hdc,local_10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    uval_1 = 1;
  }
  return uval_1;
}


