/*
 * Decompiled function: x64toa
 * Entry Point: 004e10d0
 * Size: 216 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _x64toa@20
   
   Library: Visual Studio 1998 Debug
   __stdcall x64toa,20 */

void x64toa(uint arg_1,uint arg_2,char *str_3,uint arg_4,int arg_5)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  longlong lVar4;
  char *local_c;
  char *local_8;
  
  lVar4 = CONCAT44(arg_2,arg_1);
  local_8 = str_3;
  if (arg_5 != 0) {
    *str_3 = '-';
    local_8 = str_3 + 1;
  }
  local_c = local_8;
  do {
    pcVar2 = local_8;
    arg_2 = (uint)((ulonglong)lVar4 >> 0x20);
    arg_1 = (uint)lVar4;
    uVar3 = __aullrem(arg_1,arg_2,arg_4,0);
    lVar4 = __aulldiv(arg_1,arg_2,arg_4,0);
    if (uVar3 < 10) {
      *local_8 = (char)uVar3 + '0';
    }
    else {
      *local_8 = (char)uVar3 + 'W';
    }
    local_8 = local_8 + 1;
  } while (lVar4 != 0);
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


