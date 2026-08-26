/*
 * Decompiled function: __CrtMemDumpStatistics
 * Entry Point: 00405380
 * Size: 199 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtMemDumpStatistics
   
   Library: Visual Studio 1998 Debug */

void __cdecl __CrtMemDumpStatistics(int arg_1)

{
  code *char_ptr_1;
  int val_2;
  int local_8;
  
  if (arg_1 != 0) {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      val_2 = __CrtDbgReport(0,0,0,0,"%ld bytes in %ld %hs Blocks.\n");
      if (val_2 == 1) {
        char_ptr_1 = (code *)swi(3);
        (*char_ptr_1)();
        return;
      }
    }
    val_2 = __CrtDbgReport(0,0,0,0,"Largest number used: %ld bytes.\n");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    val_2 = __CrtDbgReport(0,0,0,0,"Total allocations: %ld bytes.\n");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  return;
}


