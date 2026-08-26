/*
 * Decompiled function: FUN_0047076e
 * Entry Point: 0047076e
 * Size: 54 bytes
 */
#include "duel.h"


void FUN_0047076e(char *str_1)

{
  char *pcVar1;
  
  GetModuleFileNameA((HMODULE)0x0,str_1,0x105);
  pcVar1 = _strrchr(str_1,0x5c);
  *pcVar1 = '\0';
  return;
}


