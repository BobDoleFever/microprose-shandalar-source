/*
 * Decompiled function: x_ismbbtype
 * Entry Point: 004e7b80
 * Size: 110 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Debug */

undefined4 __cdecl x_ismbbtype(byte arg_1,uint arg_2,byte arg_3)

{
  uint local_8;
  
  if ((arg_3 & (&DAT_0050a201)[arg_1]) == 0) {
    if (arg_2 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(ushort *)(&DAT_005094aa + (uint)arg_1 * 2) & arg_2;
    }
    if (local_8 == 0) {
      return 0;
    }
  }
  return 1;
}


