/*
 * Decompiled function: __atoi64
 * Entry Point: 004d9c80
 * Size: 324 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __atoi64
   
   Library: Visual Studio 1998 Debug */

longlong __cdecl __atoi64(char *str_1)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  uint local_1c;
  uint local_18;
  uint local_10;
  int local_c;
  uint local_8;
  
  while( true ) {
    if (DAT_005096ac < 2) {
      local_18 = *(ushort *)(PTR_DAT_005094a0 + (uint)(byte)*str_1 * 2) & 8;
    }
    else {
      local_18 = __isctype((uint)(byte)*str_1,8);
    }
    if (local_18 == 0) break;
    str_1 = str_1 + 1;
  }
  uVar2 = (uint)(byte)*str_1;
  if ((uVar2 == 0x2d) || (pbVar1 = (byte *)(str_1 + 1), local_8 = uVar2, uVar2 == 0x2b)) {
    local_8 = (uint)(byte)str_1[1];
    pbVar1 = (byte *)(str_1 + 2);
  }
  str_1 = (char *)pbVar1;
  lVar3 = 0;
  while( true ) {
    local_c = (int)((ulonglong)lVar3 >> 0x20);
    local_10 = (uint)lVar3;
    if (DAT_005096ac < 2) {
      local_1c = *(ushort *)(PTR_DAT_005094a0 + local_8 * 2) & 4;
    }
    else {
      local_1c = __isctype(local_8,4);
    }
    if (local_1c == 0) break;
    lVar3 = __allmul(local_10,local_c,10,0);
    lVar3 = lVar3 + (int)(local_8 - 0x30);
    local_8 = (uint)(byte)*str_1;
    str_1 = str_1 + 1;
  }
  if (uVar2 == 0x2d) {
    lVar3 = CONCAT44(-(local_c + (uint)(local_10 != 0)),-local_10);
  }
  return lVar3;
}


