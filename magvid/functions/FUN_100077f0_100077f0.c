/*
 * Decompiled function: FUN_100077f0
 * Entry Point: 100077f0
 * Size: 110 bytes
 */
#include "magvid.h"


void __cdecl FUN_100077f0(HWND hwnd,LPCSTR arg_2)

{
  int val_1;
  va_list arglist;
  CHAR local_104 [256];
  
  lstrcpyA(local_104,s_IVIPLAY__10010624);
  arglist = &stack0x0000000c;
  val_1 = lstrlenA(local_104);
  wvsprintfA(local_104 + val_1,arg_2,arglist);
  lstrcatA(local_104,&DAT_10010630);
  SetWindowTextA(hwnd,local_104);
  return;
}


