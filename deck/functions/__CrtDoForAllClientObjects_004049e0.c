/*
 * Decompiled function: __CrtDoForAllClientObjects
 * Entry Point: 004049e0
 * Size: 105 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtDoForAllClientObjects
   
   Library: Visual Studio 1998 Debug */

void __cdecl __CrtDoForAllClientObjects(uint8_t *ptr_1,int32_t arg_2)

{
  int32_t *local_8;
  
  if (((uint8_t)DAT_00412e28 & 1) != 0) {
    for (local_8 = DAT_00414334; local_8 != (int32_t *)0x0; local_8 = (int32_t *)*local_8) {
      if ((local_8[5] & 0xffff) == 4) {
        (*(code *)ptr_1)(local_8 + 8,arg_2);
      }
    }
  }
  return;
}


