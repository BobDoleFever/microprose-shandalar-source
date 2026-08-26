/*
 * Decompiled function: FUN_0047fc0d
 * Entry Point: 0047fc0d
 * Size: 106 bytes
 */
#include "duel.h"


bool FUN_0047fc0d(HWND hwnd,int *y,DWORD arg_3,DWORD arg_4)

{
  void *arg_2;
  
  if (y != (int *)0x0) {
    arg_2 = (void *)FUN_0047f918((undefined4 *)0x0,y,arg_3,arg_4);
    FUN_0047f750(hwnd,arg_2,0,0,arg_3,arg_4);
    FUN_004db150(arg_2);
  }
  return y != (int *)0x0;
}


