/*
 * Decompiled function: _DllMain@12
 * Entry Point: 100073f0
 * Size: 56 bytes
 */
#include "magsnd.h"


/* Library Function - Single Match
    _DllMain@12
   
   Library: Visual Studio 1998 Debug */

int32_t _DllMain_12(HMODULE arg_1,int arg_2)

{
  if ((arg_2 == 1) && (DAT_1000bf70 == 0)) {
    DisableThreadLibraryCalls(arg_1);
  }
  return 1;
}


