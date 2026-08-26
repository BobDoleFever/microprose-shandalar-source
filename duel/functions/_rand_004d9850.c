/*
 * Decompiled function: _rand
 * Entry Point: 004d9850
 * Size: 65 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Debug */

int __cdecl _rand(void)

{
  DAT_005093d0 = DAT_005093d0 * 0x343fd + 0x269ec3;
  return DAT_005093d0 >> 0x10 & 0x7fff;
}


