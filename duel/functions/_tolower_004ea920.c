/*
 * Decompiled function: _tolower
 * Entry Point: 004ea920
 * Size: 313 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Debug */

int __cdecl _tolower(int arg_1)

{
  int iVar1;
  BOOL unaff_ESI;
  int unaff_EDI;
  uint local_14;
  ushort local_10 [2];
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  LPCSTR local_8;
  
  if (DAT_0050a730 == (_locale_t)0x0) {
    if ((0x40 < arg_1) && (arg_1 < 0x5b)) {
      arg_1 = arg_1 + 0x20;
    }
  }
  else {
    if (arg_1 < 0x100) {
      if (DAT_005096ac < 2) {
        local_14 = *(ushort *)(PTR_DAT_005094a0 + arg_1 * 2) & 1;
      }
      else {
        local_14 = __isctype(arg_1,1);
      }
      if (local_14 == 0) {
        return arg_1;
      }
    }
    if ((*(ushort *)(PTR_DAT_005094a0 + ((uint)arg_1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      local_c = (undefined1)arg_1;
      local_b = 0;
      local_8 = (LPCSTR)0x1;
    }
    else {
      local_c = (undefined1)((uint)arg_1 >> 8);
      local_b = (undefined1)arg_1;
      local_a = 0;
      local_8 = (LPCSTR)0x2;
    }
    iVar1 = ___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)&local_c,local_8,(int)local_10,
                               (LPSTR)0x3,0,unaff_EDI,unaff_ESI);
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        arg_1 = (int)(byte)local_10[0];
      }
      else {
        arg_1 = (int)local_10[0];
      }
    }
  }
  return arg_1;
}


