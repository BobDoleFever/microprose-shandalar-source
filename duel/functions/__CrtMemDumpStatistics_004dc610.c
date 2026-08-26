/*
 * Decompiled function: __CrtMemDumpStatistics
 * Entry Point: 004dc610
 * Size: 199 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtMemDumpStatistics
   
   Library: Visual Studio 1998 Debug */

void __CrtMemDumpStatistics(int arg_1)

{
  code *pcVar1;
  int iVar2;
  int local_8;
  
  if (arg_1 != 0) {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      iVar2 = __CrtDbgReport(0,0,0,0,"%ld bytes in %ld %hs Blocks.\n");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    iVar2 = __CrtDbgReport(0,0,0,0,"Largest number used: %ld bytes.\n");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    iVar2 = __CrtDbgReport(0,0,0,0,"Total allocations: %ld bytes.\n");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  return;
}


