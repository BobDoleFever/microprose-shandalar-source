/*
 * Decompiled function: FUN_004f391e
 * Entry Point: 004f391e
 * Size: 55 bytes
 */
#include "magic.h"


void FUN_004f391e(char *str_1)

{
  char *pcVar1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  pcVar1 = strrchr(str_1,0x5c);
  *pcVar1 = '\0';
  return;
}


