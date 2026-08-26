/*
 * Decompiled function: __RoundMan
 * Entry Point: 004eabc0
 * Size: 220 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 1998 Debug */

undefined4 __RoundMan(int arg1,int arg2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_14;
  undefined1 local_c;
  
  local_1c = 0;
  local_14 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  bVar2 = (byte)(arg2 >> 0x1f);
  local_c = 0x1f - ((((byte)arg2 ^ bVar2) - bVar2 & 0x1f ^ bVar2) - bVar2);
  if ((1 << (local_c & 0x1f) & *(uint *)(arg1 + local_14 * 4)) != 0) {
    iVar3 = __ZeroTail(arg1,arg2 + 1);
    if (iVar3 == 0) {
      local_1c = __IncMan(arg1,arg2 + -1);
    }
  }
  puVar1 = (uint *)(arg1 + local_14 * 4);
  *puVar1 = *puVar1 & -1 << (local_c & 0x1f);
  while (local_14 = local_14 + 1, local_14 < 3) {
    *(undefined4 *)(arg1 + local_14 * 4) = 0;
  }
  return local_1c;
}


