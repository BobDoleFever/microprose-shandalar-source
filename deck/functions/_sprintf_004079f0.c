/*
 * Decompiled function: _sprintf
 * Entry Point: 004079f0
 * Size: 236 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _sprintf(char *str_1,char *str_2,...)

{
  code *char_ptr_1;
  int val_2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x410d08,0x5d,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x410d08,0x5e,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = 0x7fffffff;
  val_2 = __output(&local_24,(uint8_t *)str_2,(int32_t *)&stack0x0000000c);
  local_24._cnt = local_24._cnt + -1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return val_2;
}


