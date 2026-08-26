/*
 * Decompiled function: thunk_FUN_10031697
 * Entry Point: 100016e0
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t
thunk_FUN_10031697(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  int32_t uval_1;
  HGDIOBJ h;
  int iStack_2c;
  uint8_t auStack_28 [4];
  int iStack_24;
  int iStack_20;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uval_1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    h = SelectObject(DAT_10046630,arg_3);
    GetObjectA(arg_3,0x18,auStack_28);
    iStack_8 = *arg_2;
    iStack_c = arg_2[1];
    if (arg_2[2] < *arg_2) {
      iStack_10 = iStack_24;
    }
    else {
      iStack_10 = arg_2[2] - *arg_2;
    }
    if (arg_2[3] < arg_2[1]) {
      iStack_2c = iStack_20;
    }
    else {
      iStack_2c = arg_2[3] - arg_2[1];
    }
    thunk_FUN_10031425(DAT_10046630);
    if (arg_7 <= iStack_20) {
      iStack_20 = arg_7;
    }
    if (arg_6 <= iStack_24) {
      iStack_24 = arg_6;
    }
    StretchBlt(hdc,iStack_8,iStack_c,iStack_10,iStack_2c,DAT_10046630,arg_4,arg_5,iStack_24,
               iStack_20,0xcc0020);
    SelectObject(DAT_10046630,h);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1013eb78);
    uval_1 = 1;
  }
  return uval_1;
}


