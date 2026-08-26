/*
 * Decompiled function: __onexit
 * Entry Point: 1000bc70
 * Size: 208 bytes
 */
#include "statwin.h"


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __cdecl __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_10013024 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_10013024 = DAT_10013024 + 1;
    }
    else {
      DAT_10013024 = DAT_10013024 + -1;
    }
  }
  if (0 < DAT_10013024) {
    while (0 < DAT_10013028) {
      Sleep(0);
    }
    DAT_10013028 = DAT_10013028 + 1;
  }
  if (DAT_1001e928 == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_1001e928,&DAT_1001e918);
  }
  if (0 < DAT_10013024) {
    DAT_10013028 = DAT_10013028 + -1;
  }
  return local_c;
}


