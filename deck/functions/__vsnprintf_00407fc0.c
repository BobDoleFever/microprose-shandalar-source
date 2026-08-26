/*
 * Decompiled function: __vsnprintf
 * Entry Point: 00407fc0
 * Size: 229 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __vsnprintf(char *str_1,size_t arg_2,char *str_3,va_list arg_4)

{
  code *char_ptr_1;
  int val_2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x410d24,0x5a,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_3 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x410d24,0x5b,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = arg_2;
  val_2 = __output(&local_24,(uint8_t *)str_3,(int32_t *)arg_4);
  local_24._cnt = local_24._cnt - 1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return val_2;
}


