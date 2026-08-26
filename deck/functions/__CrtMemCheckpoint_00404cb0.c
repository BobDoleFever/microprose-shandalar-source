/*
 * Decompiled function: __CrtMemCheckpoint
 * Entry Point: 00404cb0
 * Size: 316 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __CrtMemCheckpoint
   
   Library: Visual Studio 1998 Debug */

void __cdecl __CrtMemCheckpoint(int32_t *ptr_1)

{
  code *char_ptr_1;
  int val_2;
  int32_t *local_c;
  int local_8;
  
  if (ptr_1 == (int32_t *)0x0) {
    val_2 = __CrtDbgReport(0,0,0,0,"%s");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
  }
  else {
    *ptr_1 = DAT_00414334;
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      ptr_1[local_8 + 6] = 0;
      ptr_1[local_8 + 1] = ptr_1[local_8 + 6];
    }
    for (local_c = DAT_00414334; local_c != (int32_t *)0x0; local_c = (int32_t *)*local_c) {
      if ((local_c[5] & 0xffff) < 5) {
        ptr_1[(local_c[5] & 0xffff) + 1] = ptr_1[(local_c[5] & 0xffff) + 1] + 1;
        ptr_1[(local_c[5] & 0xffff) + 6] = ptr_1[(local_c[5] & 0xffff) + 6] + local_c[4];
      }
      else {
        val_2 = __CrtDbgReport(0,0,0,0,"Bad memory block found at 0x%08X.\n");
        if (val_2 == 1) {
          char_ptr_1 = (code *)swi(3);
          (*char_ptr_1)();
          return;
        }
      }
    }
    ptr_1[0xb] = DAT_0041433c;
    ptr_1[0xc] = DAT_00414330;
  }
  return;
}


