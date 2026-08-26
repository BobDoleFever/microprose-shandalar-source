/*
 * Decompiled function: FUN_00448071
 * Entry Point: 00448071
 * Size: 179 bytes
 */
#include "duel.h"


int FUN_00448071(int arg_1,int arg_2,void *arg_3)

{
  int iVar1;
  
  iVar1 = FUN_00446de2(arg_1,arg_2);
  if (iVar1 == 0) {
    if (arg_3 == (void *)0x0) {
      iVar1 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
      iVar1 = (int)(char)(&DAT_00601718)[arg_1 * 0x5b20 + arg_2 * 0x120];
      FID_conflict__memcpy(arg_3,(void *)(arg_2 * 0x120 + arg_1 * 0x5b20 + 0x601678),0xa0);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00601560);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


