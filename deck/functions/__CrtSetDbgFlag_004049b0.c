/*
 * Decompiled function: __CrtSetDbgFlag
 * Entry Point: 004049b0
 * Size: 48 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtSetDbgFlag
   
   Library: Visual Studio 1998 Debug */

int __cdecl __CrtSetDbgFlag(int arg_1)

{
  int val_1;
  
  val_1 = DAT_00412e28;
  if (arg_1 != -1) {
    DAT_00412e28 = arg_1;
  }
  return val_1;
}


