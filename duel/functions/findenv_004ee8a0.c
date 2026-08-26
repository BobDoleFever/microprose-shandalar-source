/*
 * Decompiled function: findenv
 * Entry Point: 004ee8a0
 * Size: 155 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 1998 Debug */

int __cdecl findenv(uchar *str_1,size_t arg2)

{
  int iVar1;
  int *local_8;
  
  local_8 = DAT_00509448;
  while( true ) {
    if (*local_8 == 0) {
      return -((int)local_8 - (int)DAT_00509448 >> 2);
    }
    iVar1 = __mbsnbicoll(str_1,(uchar *)*local_8,arg2);
    if ((iVar1 == 0) &&
       ((*(char *)(arg2 + *local_8) == '=' || (*(char *)(arg2 + *local_8) == '\0')))) break;
    local_8 = local_8 + 1;
  }
  return (int)local_8 - (int)DAT_00509448 >> 2;
}


