/*
 * Decompiled function: FUN_100313ee
 * Entry Point: 100313ee
 * Size: 55 bytes
 */
#include "deckdll.h"


void FUN_100313ee(char *str_1)

{
  char *char_ptr_1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  char_ptr_1 = strrchr(str_1,0x5c);
  *char_ptr_1 = '\0';
  return;
}


