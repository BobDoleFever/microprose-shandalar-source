/*
 * Decompiled function: thunk_FUN_1003197a
 * Entry Point: 100012e9
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t
thunk_FUN_1003197a(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8
                  ,int arg_9)

{
  int32_t uval_1;
  int iStack_30;
  uint8_t auStack_2c [24];
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    iStack_10 = SaveDC(hdc);
    SelectObject(DAT_10046630,arg_3);
    GetObjectA(arg_3,0x18,auStack_2c);
    iStack_8 = *arg_2;
    iStack_c = arg_2[1];
    if (arg_2[2] < *arg_2) {
      iStack_14 = arg_4;
    }
    else {
      iStack_14 = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      iStack_30 = arg_5;
    }
    else {
      iStack_30 = arg_2[3] - arg_2[1];
    }
    thunk_FUN_10031425(DAT_10046630);
    StretchBlt(hdc,iStack_8,iStack_c,iStack_14,iStack_30,DAT_10046630,arg_8,arg_9,arg_4,arg_5,
               0x8800c6);
    thunk_FUN_10031425(DAT_10046630);
    StretchBlt(hdc,iStack_8,iStack_c,iStack_14,iStack_30,DAT_10046630,arg_6,arg_7,arg_4,arg_5,
               0xee0086);
    RestoreDC(hdc,iStack_10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    uval_1 = 1;
  }
  return uval_1;
}


