/*
 * Decompiled function: FUN_004f3eaa
 * Entry Point: 004f3eaa
 * Size: 379 bytes
 */
#include "magic.h"


undefined4
FUN_004f3eaa(HDC hdc,int *arg_2,HANDLE arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9)

{
  undefined4 uVar1;
  int local_30;
  undefined1 local_2c [24];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    local_10 = SaveDC(hdc);
    SelectObject(DAT_00530180,arg_3);
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
    FUN_004f3955(DAT_00530180);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_00530180,arg_8,arg_9,arg_4,arg_5,0x8800c6);
    FUN_004f3955(DAT_00530180);
    StretchBlt(hdc,local_8,local_c,local_14,local_30,DAT_00530180,arg_6,arg_7,arg_4,arg_5,0xee0086);
    RestoreDC(hdc,local_10);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0061d838);
    uVar1 = 1;
  }
  return uVar1;
}


