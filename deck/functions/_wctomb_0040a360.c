/*
 * Decompiled function: _wctomb
 * Entry Point: 0040a360
 * Size: 198 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Debug */

int __cdecl _wctomb(char *str_1,wchar_t arg_2)

{
  int val_1;
  int16_t stack_arg;
  BOOL local_c [2];
  
  if (str_1 == (char *)0x0) {
    val_1 = 0;
  }
  else if (DAT_00413078 == 0) {
    if ((uint16_t)arg_2 < 0x100) {
      *str_1 = (char)arg_2;
      val_1 = 1;
    }
    else {
      _DAT_00412a6c = 0x2a;
      val_1 = -1;
    }
  }
  else {
    local_c[0] = 0;
    val_1 = WideCharToMultiByte(DAT_00413088,0x220,&arg_2,1,str_1,DAT_00413904,(LPCSTR)0x0,local_c);
    if ((val_1 == 0) || (local_c[0] != 0)) {
      _DAT_00412a6c = 0x2a;
      val_1 = -1;
    }
  }
  return val_1;
}


