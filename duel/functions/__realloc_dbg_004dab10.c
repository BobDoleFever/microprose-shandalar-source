/*
 * Decompiled function: __realloc_dbg
 * Entry Point: 004dab10
 * Size: 55 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __realloc_dbg
   
   Library: Visual Studio 1998 Debug */

undefined4 __realloc_dbg(int arg_1,uint arg_2,uint arg_3,int arg_4,int arg_5)

{
  undefined4 uVar1;
  
  uVar1 = realloc_help(arg_1,arg_2,arg_3,arg_4,arg_5,1);
  return uVar1;
}


