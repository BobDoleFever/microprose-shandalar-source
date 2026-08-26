/*
 * Decompiled function: __ms_p5_mp_test_fdiv
 * Entry Point: 004e6df0
 * Size: 86 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 1998 Debug */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if ((hModule != (HMODULE)0x0) &&
     (pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent"), pFVar1 != (FARPROC)0x0)) {
    (*pFVar1)(0);
    return;
  }
  __ms_p5_test_fdiv();
  return;
}


