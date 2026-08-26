/*
 * Decompiled function: FUN_00470b60
 * Entry Point: 00470b60
 * Size: 280 bytes
 */
#include "duel.h"


undefined4 FUN_00470b60(HDC hdc,int *arg_2,HANDLE arg_3)

{
  undefined4 uVar1;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  tagRECT local_20;
  int local_10;
  int local_c;
  int local_8;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (HANDLE)0x0)) {
    uVar1 = 0;
  }
  else {
    local_c = SaveDC(hdc);
    IntersectClipRect(hdc,*arg_2,arg_2[1],arg_2[2],arg_2[3]);
    GetObjectA(arg_3,0x18,local_38);
    for (local_8 = *arg_2; local_8 < arg_2[2]; local_8 = local_8 + local_34) {
      for (local_10 = arg_2[1]; local_10 < arg_2[3]; local_10 = local_10 + local_30) {
        SetRect(&local_20,local_8,local_10,local_8 + -1,local_10 + -1);
        FUN_00470a16(hdc,&local_20.left,arg_3,0,0,local_34,local_30);
      }
    }
    RestoreDC(hdc,local_c);
    uVar1 = 1;
  }
  return uVar1;
}


