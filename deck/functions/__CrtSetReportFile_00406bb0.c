/*
 * Decompiled function: __CrtSetReportFile
 * Entry Point: 00406bb0
 * Size: 169 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtSetReportFile
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __CrtSetReportFile(int arg1,int arg2)

{
  int32_t uval_1;
  HANDLE buf_ptr_2;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 0xfffffffe;
  }
  else if (arg2 == -6) {
    uval_1 = *(int32_t *)(&DAT_004138d8 + arg1 * 4);
  }
  else {
    uval_1 = *(int32_t *)(&DAT_004138d8 + arg1 * 4);
    if (arg2 == -4) {
      buf_ptr_2 = GetStdHandle(0xfffffff5);
      *(HANDLE *)(&DAT_004138d8 + arg1 * 4) = buf_ptr_2;
    }
    else if (arg2 == -5) {
      buf_ptr_2 = GetStdHandle(0xfffffff4);
      *(HANDLE *)(&DAT_004138d8 + arg1 * 4) = buf_ptr_2;
    }
    else {
      *(int *)(&DAT_004138d8 + arg1 * 4) = arg2;
    }
  }
  return uval_1;
}


