/*
 * Decompiled function: __CrtSetReportFile
 * Entry Point: 004dff30
 * Size: 169 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtSetReportFile
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtSetReportFile(int arg1,int arg2)

{
  undefined4 uVar1;
  HANDLE pvVar2;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uVar1 = 0xfffffffe;
  }
  else if (arg2 == -6) {
    uVar1 = *(undefined4 *)(&DAT_00509710 + arg1 * 4);
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_00509710 + arg1 * 4);
    if (arg2 == -4) {
      pvVar2 = GetStdHandle(0xfffffff5);
      *(HANDLE *)(&DAT_00509710 + arg1 * 4) = pvVar2;
    }
    else if (arg2 == -5) {
      pvVar2 = GetStdHandle(0xfffffff4);
      *(HANDLE *)(&DAT_00509710 + arg1 * 4) = pvVar2;
    }
    else {
      *(int *)(&DAT_00509710 + arg1 * 4) = arg2;
    }
  }
  return uVar1;
}


