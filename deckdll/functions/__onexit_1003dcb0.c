/*
 * Decompiled function: __onexit
 * Entry Point: 1003dcb0
 * Size: 208 bytes
 */
#include "deckdll.h"


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t local_c;
  char local_8;
  
  if (DAT_1004bda4 == 0) {
    DVar1 = GetVersion();
    local_8 = (char)DVar1;
    if ((local_8 == '\x03') && ((int)DVar1 < 0)) {
      DAT_1004bda4 = DAT_1004bda4 + 1;
    }
    else {
      DAT_1004bda4 = DAT_1004bda4 + -1;
    }
  }
  if (0 < DAT_1004bda4) {
    while (0 < DAT_1004bda8) {
      Sleep(0);
    }
    DAT_1004bda8 = DAT_1004bda8 + 1;
  }
  if (DAT_10215208 == -1) {
    local_c = _onexit(arg_1);
  }
  else {
    local_c = (_onexit_t)__dllonexit(arg_1,&DAT_10215208,&DAT_102151f8);
  }
  if (0 < DAT_1004bda4) {
    DAT_1004bda8 = DAT_1004bda8 + -1;
  }
  return local_c;
}


