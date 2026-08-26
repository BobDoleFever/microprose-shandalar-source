/*
 * Decompiled function: getSystemCP
 * Entry Point: 004e3c60
 * Size: 121 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Debug */

UINT __cdecl getSystemCP(UINT arg_1)

{
  DAT_0050a31c = 0;
  if (arg_1 == 0xfffffffe) {
    DAT_0050a31c = 1;
    arg_1 = GetOEMCP();
  }
  else if (arg_1 == 0xfffffffd) {
    DAT_0050a31c = 1;
    arg_1 = GetACP();
  }
  else if (arg_1 == 0xfffffffc) {
    DAT_0050a31c = 1;
    arg_1 = DAT_0050a740;
  }
  return arg_1;
}


