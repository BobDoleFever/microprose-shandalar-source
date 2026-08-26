/*
 * Decompiled function: __CrtDumpMemoryLeaks
 * Entry Point: 004052f0
 * Size: 132 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtDumpMemoryLeaks
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtDumpMemoryLeaks(void)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int32_t local_38 [2];
  int local_30;
  int local_2c;
  int local_24;
  
  __CrtMemCheckpoint(local_38);
  if (((local_24 == 0) && (local_30 == 0)) &&
     ((((uint8_t)DAT_00412e28 & 0x10) == 0 || (local_2c == 0)))) {
    uval_3 = 0;
  }
  else {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      uval_3 = (*char_ptr_1)();
      return uval_3;
    }
    __CrtMemDumpAllObjectsSince((int32_t *)0x0);
    uval_3 = 1;
  }
  return uval_3;
}


