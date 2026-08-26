/*
 * Decompiled function: FUN_1003b02a
 * Entry Point: 1003b02a
 * Size: 52 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_1003b02a(char *str_1,int arg2)

{
  int val_1;
  
  val_1 = _open(str_1,arg2);
  _DAT_1013ec80 = 0xffffffff;
  return val_1;
}


