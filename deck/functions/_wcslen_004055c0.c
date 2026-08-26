/*
 * Decompiled function: _wcslen
 * Entry Point: 004055c0
 * Size: 66 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _wcslen
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _wcslen(wchar_t *str_1)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *local_8;
  
  local_8 = str_1;
  do {
    pwVar1 = local_8 + 1;
    wVar2 = *local_8;
    local_8 = pwVar1;
  } while (wVar2 != L'\0');
  return ((int)pwVar1 - (int)str_1 >> 1) - 1;
}


