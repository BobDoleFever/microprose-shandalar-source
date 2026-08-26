/*
 * Decompiled function: __mbsnbicoll
 * Entry Point: 004ed6b0
 * Size: 103 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 1998 Debug */

int __cdecl __mbsnbicoll(uchar *str_1,uchar *str_2,size_t arg_3)

{
  int iVar1;
  int unaff_EDI;
  
  if (arg_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ___crtCompareStringA
                      (DAT_0050a308,(LPCWSTR)0x1,(DWORD)str_1,(LPCSTR)arg_3,(int)str_2,(LPCSTR)arg_3
                       ,DAT_0050a304,unaff_EDI);
    if (iVar1 == 0) {
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = iVar1 + -2;
    }
  }
  return iVar1;
}


