/*
 * Decompiled function: __isctype
 * Entry Point: 00407ae0
 * Size: 182 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __isctype
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isctype(int arg1,int arg2)

{
  BOOL BVar1;
  uint32_t uval_2;
  BOOL unaff_EDI;
  uint8_t local_10;
  uint8_t local_f;
  uint8_t local_e;
  LPCSTR local_c;
  uint32_t local_8;
  
  if (arg1 + 1U < 0x101) {
    uval_2 = (uint32_t)*(uint16_t *)(PTR_DAT_00412e58 + arg1 * 2) & arg2;
  }
  else {
    if ((*(uint16_t *)(PTR_DAT_00412e58 + ((uint32_t)arg1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      local_10 = (uint8_t)arg1;
      local_f = 0;
      local_c = (LPCSTR)0x1;
    }
    else {
      local_10 = (uint8_t)((uint32_t)arg1 >> 8);
      local_f = (uint8_t)arg1;
      local_e = 0;
      local_c = (LPCSTR)0x2;
    }
    BVar1 = ___crtGetStringTypeA
                      ((_locale_t)0x1,(DWORD)&local_10,local_c,(int)&local_8,(LPWORD)0x0,0,unaff_EDI
                      );
    if (BVar1 == 0) {
      uval_2 = 0;
    }
    else {
      uval_2 = local_8 & 0xffff & arg2;
    }
  }
  return uval_2;
}


