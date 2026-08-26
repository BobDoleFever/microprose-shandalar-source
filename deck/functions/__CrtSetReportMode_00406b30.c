/*
 * Decompiled function: __CrtSetReportMode
 * Entry Point: 00406b30
 * Size: 126 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtSetReportMode
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __CrtSetReportMode(int arg1,uint32_t arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 0xffffffff;
  }
  else if (arg2 == 0xffffffff) {
    uval_1 = *(int32_t *)(&DAT_004138c8 + arg1 * 4);
  }
  else if ((arg2 & 0xfffffff8) == 0) {
    uval_1 = *(int32_t *)(&DAT_004138c8 + arg1 * 4);
    *(uint32_t *)(&DAT_004138c8 + arg1 * 4) = arg2;
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}


