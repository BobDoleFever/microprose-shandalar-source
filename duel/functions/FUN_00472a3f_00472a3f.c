/*
 * Decompiled function: FUN_00472a3f
 * Entry Point: 00472a3f
 * Size: 190 bytes
 */
#include "duel.h"


undefined4 FUN_00472a3f(HWND hwnd,int arg_2,int arg_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  
  if ((arg_2 == 0) || (arg_3 < 1)) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_004729bc(arg_2,arg_3);
    if (iVar2 == -1) {
      uVar1 = 0;
    }
    else {
      SetWindowPos(*(HWND *)(arg_2 + iVar2 * 4),hwnd,0,0,0,0,3);
      if (iVar2 + 1 < arg_3) {
        local_c = iVar2 * 4 + 4 + arg_2;
      }
      else {
        local_c = 0;
      }
      FUN_00472a3f(*(HWND *)(arg_2 + iVar2 * 4),local_c,arg_3 - (iVar2 + 1));
      uVar1 = 1;
    }
  }
  return uVar1;
}


