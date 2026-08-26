/*
 * Decompiled function: __onexit
 * Entry Point: 00513c80
 * Size: 208 bytes
 */
#include "magic.h"


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_00536d50 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_00536d50 = DAT_00536d50 + 1;
    }
    else {
      DAT_00536d50 = DAT_00536d50 + -1;
    }
  }
  if (0 < DAT_00536d50) {
    while (0 < DAT_00536d54) {
      Sleep(0);
    }
    DAT_00536d54 = DAT_00536d54 + 1;
  }
  if (DAT_0070ac9c == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_0070ac9c,&DAT_0070ac98);
  }
  if (0 < DAT_00536d50) {
    DAT_00536d54 = DAT_00536d54 + -1;
  }
  return local_c;
}


