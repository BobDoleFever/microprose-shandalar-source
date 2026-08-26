/*
 * Decompiled function: getSystemCP
 * Entry Point: 00402910
 * Size: 121 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 1998 Debug */

UINT __cdecl getSystemCP(UINT arg_1)

{
  DAT_00412c84 = 0;
  if (arg_1 == 0xfffffffe) {
    DAT_00412c84 = 1;
    arg_1 = GetOEMCP();
  }
  else if (arg_1 == 0xfffffffd) {
    DAT_00412c84 = 1;
    arg_1 = GetACP();
  }
  else if (arg_1 == 0xfffffffc) {
    DAT_00412c84 = 1;
    arg_1 = DAT_00413088;
  }
  return arg_1;
}


