/*
 * Decompiled function: _ctime
 * Entry Point: 004de5a0
 * Size: 63 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _ctime
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _ctime(time_t *ptr_1)

{
  tm *ptr_1_00;
  char *pcVar1;
  
  ptr_1_00 = _localtime(ptr_1);
  if (ptr_1_00 == (tm *)0x0) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = _asctime(ptr_1_00);
  }
  return pcVar1;
}


