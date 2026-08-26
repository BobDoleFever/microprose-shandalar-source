/*
 * Decompiled function: _atol
 * Entry Point: 004d9b40
 * Size: 282 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _atol
   
   Library: Visual Studio 1998 Debug */

long __cdecl _atol(char *str_1)

{
  byte *pbVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  int local_c;
  uint local_8;
  
  while( true ) {
    if (DAT_005096ac < 2) {
      local_14 = *(ushort *)(PTR_DAT_005094a0 + (uint)(byte)*str_1 * 2) & 8;
    }
    else {
      local_14 = __isctype((uint)(byte)*str_1,8);
    }
    if (local_14 == 0) break;
    str_1 = str_1 + 1;
  }
  uVar2 = (uint)(byte)*str_1;
  if ((uVar2 == 0x2d) || (pbVar1 = (byte *)(str_1 + 1), local_8 = uVar2, uVar2 == 0x2b)) {
    local_8 = (uint)(byte)str_1[1];
    pbVar1 = (byte *)(str_1 + 2);
  }
  str_1 = (char *)pbVar1;
  local_c = 0;
  while( true ) {
    if (DAT_005096ac < 2) {
      local_18 = *(ushort *)(PTR_DAT_005094a0 + local_8 * 2) & 4;
    }
    else {
      local_18 = __isctype(local_8,4);
    }
    if (local_18 == 0) break;
    local_c = (local_8 - 0x30) + local_c * 10;
    local_8 = (uint)(byte)*str_1;
    str_1 = str_1 + 1;
  }
  if (uVar2 == 0x2d) {
    local_c = -local_c;
  }
  return local_c;
}


