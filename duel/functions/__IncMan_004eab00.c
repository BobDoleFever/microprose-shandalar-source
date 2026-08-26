/*
 * Decompiled function: __IncMan
 * Entry Point: 004eab00
 * Size: 179 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 1998 Debug */

int __IncMan(int arg1,int arg2)

{
  byte bVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_8;
  
  local_10 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  bVar1 = (byte)(arg2 >> 0x1f);
  local_8 = 0x1f - ((((byte)arg2 ^ bVar1) - bVar1 & 0x1f ^ bVar1) - bVar1);
  local_14 = ___addl(*(uint *)(arg1 + local_10 * 4),1 << (local_8 & 0x1f),
                     (uint *)(local_10 * 4 + arg1));
  while ((local_10 = local_10 + -1, -1 < local_10 && (local_14 != 0))) {
    local_14 = ___addl(*(uint *)(arg1 + local_10 * 4),1,(uint *)(local_10 * 4 + arg1));
  }
  return local_14;
}


