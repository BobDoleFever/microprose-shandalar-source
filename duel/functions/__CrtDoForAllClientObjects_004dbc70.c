/*
 * Decompiled function: __CrtDoForAllClientObjects
 * Entry Point: 004dbc70
 * Size: 105 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtDoForAllClientObjects
   
   Library: Visual Studio 1998 Debug */

void __CrtDoForAllClientObjects(undefined *arg1,undefined4 arg2)

{
  undefined4 *local_8;
  
  if (((byte)DAT_00509470 & 1) != 0) {
    for (local_8 = DAT_005edac8; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      if ((local_8[5] & 0xffff) == 4) {
        (*(code *)arg1)(local_8 + 8,arg2);
      }
    }
  }
  return;
}


