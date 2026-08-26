/*
 * Decompiled function: thunk_FUN_100046fb
 * Entry Point: 1000106e
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t thunk_FUN_100046fb(void)

{
  MMRESULT MVar1;
  int32_t uval_2;
  
  MVar1 = timeGetDevCaps((LPTIMECAPS)&DAT_1000ba98,8);
  if (MVar1 == 0) {
    timeBeginPeriod(DAT_1000a480);
    DAT_1000ba94 = timeSetEvent(DAT_1000a480,DAT_1000ba98,&LAB_1000110e,0x1000ba88,1);
    if (DAT_1000ba94 == 0) {
      timeEndPeriod(DAT_1000a480);
      uval_2 = 0xc;
    }
    else {
      DAT_1000a424 = 1;
      uval_2 = 0;
    }
  }
  else {
    uval_2 = 0xc;
  }
  return uval_2;
}


