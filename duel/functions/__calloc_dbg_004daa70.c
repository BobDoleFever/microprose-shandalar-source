/*
 * Decompiled function: __calloc_dbg
 * Entry Point: 004daa70
 * Size: 110 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __calloc_dbg
   
   Library: Visual Studio 1998 Debug */

undefined1 * __calloc_dbg(int arg_1,int arg_2,undefined4 arg_3,undefined4 arg_4,undefined4 arg_5)

{
  undefined1 *puVar1;
  undefined1 *local_10;
  
  puVar1 = (undefined1 *)__malloc_dbg(arg_2 * arg_1,arg_3,arg_4,arg_5);
  if (puVar1 != (undefined1 *)0x0) {
    for (local_10 = puVar1; local_10 < puVar1 + arg_2 * arg_1; local_10 = local_10 + 1) {
      *local_10 = 0;
    }
  }
  return puVar1;
}


