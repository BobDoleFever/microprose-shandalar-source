/*
 * Decompiled function: ___sbh_release_region
 * Entry Point: 004e2230
 * Size: 132 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_release_region
   
   Library: Visual Studio 1998 Debug */

void ___sbh_release_region(undefined **arg_1)

{
  VirtualFree(arg_1[0x204],0,0x8000);
  if (arg_1 == (undefined **)PTR_LOOP_0050a1f4) {
    PTR_LOOP_0050a1f4 = arg_1[1];
  }
  if (arg_1 == &PTR_LOOP_005099e0) {
    DAT_0050a1f0 = 0;
  }
  else {
    *(undefined **)arg_1[1] = *arg_1;
    *(undefined **)(*arg_1 + 4) = arg_1[1];
    HeapFree(DAT_006c1c94,0,arg_1);
  }
  return;
}


