/*
 * Decompiled function: _tolower
 * Entry Point: 0040b3d0
 * Size: 313 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Debug */

int __cdecl _tolower(int arg_1)

{
  int val_1;
  BOOL unaff_ESI;
  int unaff_EDI;
  uint32_t local_14;
  uint16_t local_10 [2];
  uint8_t local_c;
  uint8_t local_b;
  uint8_t local_a;
  LPCSTR local_8;
  
  if (DAT_00413078 == (_locale_t)0x0) {
    if ((0x40 < arg_1) && (arg_1 < 0x5b)) {
      arg_1 = arg_1 + 0x20;
    }
  }
  else {
    if (arg_1 < 0x100) {
      if (DAT_00413904 < 2) {
        local_14 = *(uint16_t *)(PTR_DAT_00412e58 + arg_1 * 2) & 1;
      }
      else {
        local_14 = __isctype(arg_1,1);
      }
      if (local_14 == 0) {
        return arg_1;
      }
    }
    if ((*(uint16_t *)(PTR_DAT_00412e58 + ((uint32_t)arg_1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      local_c = (uint8_t)arg_1;
      local_b = 0;
      local_8 = (LPCSTR)0x1;
    }
    else {
      local_c = (uint8_t)((uint32_t)arg_1 >> 8);
      local_b = (uint8_t)arg_1;
      local_a = 0;
      local_8 = (LPCSTR)0x2;
    }
    val_1 = ___crtLCMapStringA(DAT_00413078,(LPCWSTR)0x100,(DWORD)&local_c,local_8,(int)local_10,
                               (LPSTR)0x3,0,unaff_EDI,unaff_ESI);
    if (val_1 != 0) {
      if (val_1 == 1) {
        arg_1 = (int)(uint8_t)local_10[0];
      }
      else {
        arg_1 = (int)local_10[0];
      }
    }
  }
  return arg_1;
}


