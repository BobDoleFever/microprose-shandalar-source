/*
 * Decompiled function: _getenv
 * Entry Point: 004eb9c0
 * Size: 227 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _getenv
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _getenv(char *str_1)

{
  int iVar1;
  size_t arg_3;
  size_t sVar2;
  int *local_c;
  
  local_c = DAT_00509448;
  if ((DAT_00509448 == (int *)0x0) && (DAT_00509450 != 0)) {
    iVar1 = ___wtomb_environ();
    if (iVar1 != 0) {
      return (char *)0x0;
    }
    local_c = DAT_00509448;
  }
  DAT_00509448 = local_c;
  if ((local_c != (int *)0x0) && (str_1 != (char *)0x0)) {
    arg_3 = _strlen(str_1);
    for (; *local_c != 0; local_c = local_c + 1) {
      sVar2 = _strlen((char *)*local_c);
      if (((arg_3 < sVar2) && (*(char *)(arg_3 + *local_c) == '=')) &&
         (iVar1 = __mbsnbicoll((uchar *)*local_c,(uchar *)str_1,arg_3), iVar1 == 0)) {
        return (char *)(arg_3 + 1 + *local_c);
      }
    }
  }
  return (char *)0x0;
}


