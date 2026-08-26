/*
 * Decompiled function: _wctomb
 * Entry Point: 004e8a90
 * Size: 198 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Debug */

int __cdecl _wctomb(char *str_1,wchar_t arg_2)

{
  int iVar1;
  undefined2 in_stack_0000000a;
  BOOL local_c [2];
  
  if (str_1 == (char *)0x0) {
    iVar1 = 0;
  }
  else if (DAT_0050a730 == 0) {
    if ((ushort)arg_2 < 0x100) {
      *str_1 = (char)arg_2;
      iVar1 = 1;
    }
    else {
      DAT_00509420 = 0x2a;
      iVar1 = -1;
    }
  }
  else {
    local_c[0] = 0;
    iVar1 = WideCharToMultiByte(DAT_0050a740,0x220,&arg_2,1,str_1,DAT_005096ac,(LPCSTR)0x0,local_c);
    if ((iVar1 == 0) || (local_c[0] != 0)) {
      DAT_00509420 = 0x2a;
      iVar1 = -1;
    }
  }
  return iVar1;
}


