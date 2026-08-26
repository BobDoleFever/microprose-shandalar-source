/*
 * Decompiled function: __CrtMemDifference
 * Entry Point: 004dc080
 * Size: 312 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __CrtMemDifference
   
   Library: Visual Studio 1998 Debug */

undefined4 __CrtMemDifference(undefined4 *arg_1,int arg_2,int arg_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  if (((arg_1 == (undefined4 *)0x0) || (arg_2 == 0)) || (arg_3 == 0)) {
    iVar2 = __CrtDbgReport(0,0,0,0,"%s");
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    local_c = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      arg_1[local_8 + 6] =
           *(int *)(arg_3 + 0x18 + local_8 * 4) - *(int *)(arg_2 + 0x18 + local_8 * 4);
      arg_1[local_8 + 1] = *(int *)(arg_3 + 4 + local_8 * 4) - *(int *)(arg_2 + 4 + local_8 * 4);
      if (((arg_1[local_8 + 6] != 0) || (arg_1[local_8 + 1] != 0)) &&
         ((local_8 != 0 && ((local_8 != 2 || (((byte)DAT_00509470 & 0x10) != 0)))))) {
        local_c = 1;
      }
    }
    arg_1[0xb] = *(int *)(arg_3 + 0x2c) - *(int *)(arg_2 + 0x2c);
    arg_1[0xc] = *(int *)(arg_3 + 0x30) - *(int *)(arg_2 + 0x30);
    *arg_1 = 0;
  }
  return local_c;
}


