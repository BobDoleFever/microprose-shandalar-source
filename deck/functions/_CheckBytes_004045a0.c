/*
 * Decompiled function: _CheckBytes
 * Entry Point: 004045a0
 * Size: 140 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _CheckBytes
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl _CheckBytes(char *str_1,char arg_2,int arg_3)

{
  char *char_ptr_1;
  char cVar2;
  code *char_ptr_3;
  int val_4;
  int32_t uval_5;
  int32_t local_8;
  
  local_8 = 1;
  while( true ) {
    do {
      val_4 = arg_3 + -1;
      if (arg_3 == 0) {
        return local_8;
      }
      char_ptr_1 = str_1 + 1;
      cVar2 = *str_1;
      str_1 = char_ptr_1;
      arg_3 = val_4;
    } while (cVar2 == arg_2);
    val_4 = __CrtDbgReport(0,0,0,0,"memory check error at 0x%08X = 0x%02X, should be 0x%02X.\n");
    if (val_4 == 1) break;
    local_8 = 0;
  }
  char_ptr_3 = (code *)swi(3);
  uval_5 = (*char_ptr_3)();
  return uval_5;
}


