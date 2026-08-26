/*
 * Decompiled function: __ZeroTail
 * Entry Point: 004eaa60
 * Size: 153 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 1998 Debug */

undefined4 __ZeroTail(int arg1,int arg2)

{
  uint uVar1;
  byte bVar2;
  int local_10;
  byte local_8;
  
  local_10 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(arg2 >> 0x1f);
  local_8 = 0x1f - ((((byte)arg2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  uVar1 = ~(-1 << (local_8 & 0x1f)) & *(uint *)(arg1 + local_10 * 4);
  while( true ) {
    if (uVar1 != 0) {
      return 0;
    }
    local_10 = local_10 + 1;
    if (2 < local_10) break;
    uVar1 = *(uint *)(arg1 + local_10 * 4);
  }
  return 1;
}


