/*
 * Decompiled function: __onexit
 * Entry Point: 100072d0
 * Size: 208 bytes
 */
#include "magsnd.h"


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __cdecl __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_1000a534 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1000a534 = DAT_1000a534 + 1;
    }
    else {
      DAT_1000a534 = DAT_1000a534 + -1;
    }
  }
  if (0 < DAT_1000a534) {
    while (0 < DAT_1000a538) {
      Sleep(0);
    }
    DAT_1000a538 = DAT_1000a538 + 1;
  }
  if (DAT_1000bf6c == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_1000bf6c,&DAT_1000bf5c);
  }
  if (0 < DAT_1000a534) {
    DAT_1000a538 = DAT_1000a538 + -1;
  }
  return local_c;
}


