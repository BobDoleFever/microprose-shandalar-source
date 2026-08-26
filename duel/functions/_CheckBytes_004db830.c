/*
 * Decompiled function: _CheckBytes
 * Entry Point: 004db830
 * Size: 140 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _CheckBytes
   
   Library: Visual Studio 1998 Debug */

undefined4 _CheckBytes(char *str_1,char arg_2,int arg_3)

{
  char *pcVar1;
  char cVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_8;
  
  local_8 = 1;
  while( true ) {
    do {
      iVar4 = arg_3 + -1;
      if (arg_3 == 0) {
        return local_8;
      }
      pcVar1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = pcVar1;
      arg_3 = iVar4;
    } while (cVar2 == arg_2);
    iVar4 = __CrtDbgReport(0,0,0,0,"memory check error at 0x%08X = 0x%02X, should be 0x%02X.\n");
    if (iVar4 == 1) break;
    local_8 = 0;
  }
  pcVar3 = (code *)swi(3);
  uVar5 = (*pcVar3)();
  return uVar5;
}


