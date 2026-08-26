/*
 * Decompiled function: __CrtDumpMemoryLeaks
 * Entry Point: 004dc580
 * Size: 132 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtDumpMemoryLeaks
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtDumpMemoryLeaks(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38 [2];
  int local_30;
  int local_2c;
  int local_24;
  
  __CrtMemCheckpoint(local_38);
  if (((local_24 == 0) && (local_30 == 0)) &&
     ((((byte)DAT_00509470 & 0x10) == 0 || (local_2c == 0)))) {
    uVar3 = 0;
  }
  else {
    iVar2 = __CrtDbgReport(0,0,0,0,"%s");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    __CrtMemDumpAllObjectsSince((undefined4 *)0x0);
    uVar3 = 1;
  }
  return uVar3;
}


