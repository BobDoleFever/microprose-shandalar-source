/*
 * Decompiled function: __forcdecpt
 * Entry Point: 004e6e50
 * Size: 179 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __forcdecpt
   
   Library: Visual Studio 1998 Debug */

void __cdecl __forcdecpt(char *str_1)

{
  char cVar1;
  int iVar2;
  uint local_10;
  char local_c;
  
  iVar2 = _tolower((int)*str_1);
  if (iVar2 != 0x65) {
    do {
      str_1 = str_1 + 1;
      if (DAT_005096ac < 2) {
        local_10 = *(ushort *)(PTR_DAT_005094a0 + *str_1 * 2) & 4;
      }
      else {
        local_10 = __isctype((int)*str_1,4);
      }
    } while (local_10 != 0);
  }
  local_c = *str_1;
  *str_1 = DAT_005096b0;
  do {
    str_1 = str_1 + 1;
    cVar1 = *str_1;
    *str_1 = local_c;
    local_c = cVar1;
  } while (*str_1 != '\0');
  return;
}


