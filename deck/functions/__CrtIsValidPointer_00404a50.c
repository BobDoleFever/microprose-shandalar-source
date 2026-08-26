/*
 * Decompiled function: __CrtIsValidPointer
 * Entry Point: 00404a50
 * Size: 92 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtIsValidPointer
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl __CrtIsValidPointer(void *ptr_1,UINT_PTR arg_2,int arg_3)

{
  BOOL BVar1;
  
  if (((ptr_1 != (void *)0x0) && (BVar1 = IsBadReadPtr(ptr_1,arg_2), BVar1 == 0)) &&
     ((arg_3 == 0 || (BVar1 = IsBadWritePtr(ptr_1,arg_2), BVar1 == 0)))) {
    return 1;
  }
  return 0;
}


