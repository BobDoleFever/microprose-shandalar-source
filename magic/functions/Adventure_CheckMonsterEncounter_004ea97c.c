/*
 * Decompiled function: Adventure_CheckMonsterEncounter
 * Entry Point: 004ea97c
 * Size: 157 bytes
 */
#include "magic.h"


int Adventure_CheckMonsterEncounter(int arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while( true ) {
    iVar1 = FUN_0040a1d2(DAT_00523524 + -1);
    iVar1 = iVar1 + 1;
    local_c = local_c + 1;
    if (0x3e6 < local_c) break;
    if (((char)(&DAT_00522628)[iVar1 * 0x44] == arg2) &&
       ((arg1 == 0 || ((1 << ((byte)arg1 & 0x1f) & (int)(char)(&DAT_0052262b)[iVar1 * 0x44]) != 0)))
       ) break;
  }
  if (local_c == 999) {
    iVar1 = 0;
  }
  return iVar1;
}


