/*
 * Decompiled function: __mbctoupper
 * Entry Point: 004eefd0
 * Size: 188 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __mbctoupper
   
   Library: Visual Studio 1998 Debug */

uint __cdecl __mbctoupper(uint arg_1)

{
  int iVar1;
  BOOL unaff_ESI;
  int unaff_EDI;
  byte local_c;
  byte local_b;
  byte local_8;
  undefined1 local_7;
  
  if (arg_1 < 0x100) {
    if ((0x60 < (int)arg_1) && ((int)arg_1 < 0x7b)) {
      arg_1 = arg_1 - 0x20;
    }
  }
  else {
    local_8 = (byte)(arg_1 >> 8);
    local_7 = (undefined1)arg_1;
    if ((((&DAT_0050a201)[local_8] & 4) != 0) &&
       (iVar1 = ___crtLCMapStringA(DAT_0050a308,(LPCWSTR)0x200,(DWORD)&local_8,(LPCSTR)0x2,
                                   (int)&local_c,(LPSTR)0x2,DAT_0050a304,unaff_EDI,unaff_ESI),
       iVar1 != 0)) {
      arg_1 = (uint)local_b + (uint)local_c * 0x100;
    }
  }
  return arg_1;
}


