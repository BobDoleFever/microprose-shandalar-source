/*
 * Decompiled function: xtoa
 * Entry Point: 00407c00
 * Size: 181 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 1998 Debug */

void __cdecl xtoa(uint32_t x,char *y,uint32_t width,int height)

{
  char cVar1;
  char *char_ptr_2;
  uint32_t uval_3;
  char *local_c;
  char *local_8;
  
  local_8 = y;
  if (height != 0) {
    *y = '-';
    local_8 = y + 1;
    x = -x;
  }
  local_c = local_8;
  do {
    char_ptr_2 = local_8;
    uval_3 = x % width;
    x = x / width;
    cVar1 = (char)uval_3;
    if (uval_3 < 10) {
      *local_8 = cVar1 + '0';
    }
    else {
      *local_8 = cVar1 + 'W';
    }
    local_8 = local_8 + 1;
  } while (x != 0);
  *local_8 = '\0';
  local_8 = char_ptr_2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}


