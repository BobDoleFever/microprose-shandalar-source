/*
 * Decompiled function: __global_unwind2
 * Entry Point: 00401544
 * Size: 32 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __cdecl __global_unwind2(PVOID arg_1)

{
  RtlUnwind(arg_1,(PVOID)0x40155c,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}


