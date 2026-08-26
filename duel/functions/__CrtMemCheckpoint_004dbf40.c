/*
 * Decompiled function: __CrtMemCheckpoint
 * Entry Point: 004dbf40
 * Size: 316 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtMemCheckpoint
   
   Library: Visual Studio 1998 Debug */

void __CrtMemCheckpoint(undefined4 *arg_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *local_c;
  int local_8;
  
  if (arg_1 == (undefined4 *)0x0) {
    iVar2 = __CrtDbgReport(0,0,0,0,"%s");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  else {
    *arg_1 = DAT_005edac8;
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      arg_1[local_8 + 6] = 0;
      arg_1[local_8 + 1] = arg_1[local_8 + 6];
    }
    for (local_c = DAT_005edac8; local_c != (undefined4 *)0x0; local_c = (undefined4 *)*local_c) {
      if ((local_c[5] & 0xffff) < 5) {
        arg_1[(local_c[5] & 0xffff) + 1] = arg_1[(local_c[5] & 0xffff) + 1] + 1;
        arg_1[(local_c[5] & 0xffff) + 6] = arg_1[(local_c[5] & 0xffff) + 6] + local_c[4];
      }
      else {
        iVar2 = __CrtDbgReport(0,0,0,0,"Bad memory block found at 0x%08X.\n");
        if (iVar2 == 1) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
    }
    arg_1[0xb] = DAT_005edad0;
    arg_1[0xc] = DAT_005edac4;
  }
  return;
}


