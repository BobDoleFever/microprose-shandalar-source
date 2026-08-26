/*
 * Decompiled function: __mbschr
 * Entry Point: 004eea40
 * Size: 229 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 1998 Debug */

uchar * __cdecl __mbschr(uchar *str_1,uint arg_2)

{
  uchar *puVar1;
  byte bVar2;
  ushort uVar3;
  
  if (DAT_0050a304 == 0) {
    str_1 = (uchar *)_strchr((char *)str_1,arg_2);
  }
  else {
    while( true ) {
      bVar2 = *str_1;
      uVar3 = (ushort)bVar2;
      if (uVar3 == 0) break;
      if (((&DAT_0050a201)[bVar2] & 4) == 0) {
        puVar1 = str_1;
        if (uVar3 == arg_2) break;
      }
      else {
        puVar1 = str_1 + 1;
        if (*puVar1 == '\0') {
          return (uchar *)0x0;
        }
        if (CONCAT11(bVar2,*puVar1) == arg_2) {
          return str_1;
        }
      }
      str_1 = puVar1;
      str_1 = str_1 + 1;
    }
    if (uVar3 != arg_2) {
      str_1 = (uchar *)0x0;
    }
  }
  return str_1;
}


