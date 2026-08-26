/*
 * Decompiled function: __CrtIsValidPointer
 * Entry Point: 004dbce0
 * Size: 92 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtIsValidPointer
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtIsValidPointer(void *arg_1,UINT_PTR arg_2,int arg_3)

{
  BOOL BVar1;
  
  if (((arg_1 != (void *)0x0) && (BVar1 = IsBadReadPtr(arg_1,arg_2), BVar1 == 0)) &&
     ((arg_3 == 0 || (BVar1 = IsBadWritePtr(arg_1,arg_2), BVar1 == 0)))) {
    return 1;
  }
  return 0;
}


