/*
 * Decompiled function: __CrtSetDbgFlag
 * Entry Point: 004dbc40
 * Size: 48 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtSetDbgFlag
   
   Library: Visual Studio 1998 Debug */

int __CrtSetDbgFlag(int arg_1)

{
  int iVar1;
  
  iVar1 = DAT_00509470;
  if (arg_1 != -1) {
    DAT_00509470 = arg_1;
  }
  return iVar1;
}


