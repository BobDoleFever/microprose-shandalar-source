/*
 * Decompiled function: __onexit
 * Entry Point: 1000cc70
 * Size: 208 bytes
 */
#include "magvid.h"


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __cdecl __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_10010730 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10010730 = DAT_10010730 + 1;
    }
    else {
      DAT_10010730 = DAT_10010730 + -1;
    }
  }
  if (0 < DAT_10010730) {
    while (0 < DAT_10010734) {
      Sleep(0);
    }
    DAT_10010734 = DAT_10010734 + 1;
  }
  if (DAT_10032d04 == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_10032d04,&DAT_10032cf4);
  }
  if (0 < DAT_10010730) {
    DAT_10010734 = DAT_10010734 + -1;
  }
  return local_c;
}


