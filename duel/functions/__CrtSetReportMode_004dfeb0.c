/*
 * Decompiled function: __CrtSetReportMode
 * Entry Point: 004dfeb0
 * Size: 126 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtSetReportMode
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtSetReportMode(int arg1,uint arg2)

{
  undefined4 uVar1;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uVar1 = 0xffffffff;
  }
  else if (arg2 == 0xffffffff) {
    uVar1 = *(undefined4 *)(&DAT_00509700 + arg1 * 4);
  }
  else if ((arg2 & 0xfffffff8) == 0) {
    uVar1 = *(undefined4 *)(&DAT_00509700 + arg1 * 4);
    *(uint *)(&DAT_00509700 + arg1 * 4) = arg2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


