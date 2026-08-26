/*
 * Decompiled function: __open
 * Entry Point: 004dd290
 * Size: 67 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __open
   
   Library: Visual Studio 1998 Debug */

int __cdecl __open(char *filename,int arg_2,...)

{
  int iVar1;
  undefined4 in_stack_0000000c;
  
  iVar1 = __sopen(filename,arg_2,0x40,in_stack_0000000c);
  return iVar1;
}


