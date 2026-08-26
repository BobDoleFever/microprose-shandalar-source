/*
 * Decompiled function: xtoa
 * Entry Point: 004e0f10
 * Size: 181 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 1998 Debug */

void __cdecl xtoa(uint x,char *str_2,uint width,int height)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *local_c;
  char *local_8;
  
  local_8 = str_2;
  if (height != 0) {
    *str_2 = '-';
    local_8 = str_2 + 1;
    x = -x;
  }
  local_c = local_8;
  do {
    pcVar2 = local_8;
    uVar3 = x % width;
    x = x / width;
    cVar1 = (char)uVar3;
    if (uVar3 < 10) {
      *local_8 = cVar1 + '0';
    }
    else {
      *local_8 = cVar1 + 'W';
    }
    local_8 = local_8 + 1;
  } while (x != 0);
  *local_8 = '\0';
  local_8 = pcVar2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}


