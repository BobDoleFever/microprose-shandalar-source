/*
 * Decompiled function: __isctype
 * Entry Point: 004de160
 * Size: 182 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __isctype
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isctype(int arg1,int arg2)

{
  BOOL BVar1;
  uint uVar2;
  BOOL unaff_EDI;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  LPCSTR local_c;
  uint local_8;
  
  if (arg1 + 1U < 0x101) {
    uVar2 = (uint)*(ushort *)(PTR_DAT_005094a0 + arg1 * 2) & arg2;
  }
  else {
    if ((*(ushort *)(PTR_DAT_005094a0 + ((uint)arg1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      local_10 = (undefined1)arg1;
      local_f = 0;
      local_c = (LPCSTR)0x1;
    }
    else {
      local_10 = (undefined1)((uint)arg1 >> 8);
      local_f = (undefined1)arg1;
      local_e = 0;
      local_c = (LPCSTR)0x2;
    }
    BVar1 = ___crtGetStringTypeA
                      ((_locale_t)0x1,(DWORD)&local_10,local_c,(int)&local_8,(LPWORD)0x0,0,unaff_EDI
                      );
    if (BVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = local_8 & 0xffff & arg2;
    }
  }
  return uVar2;
}


