/*
 * Decompiled function: thunk_FUN_1000353c
 * Entry Point: 10001230
 * Size: 5 bytes
 */
#include "statwin.h"


char thunk_FUN_1000353c(void)

{
  char cVar1;
  uint32_t uval_2;
  char acStack_104 [256];
  
  if (DAT_10013168 == 0) {
    uval_2 = thunk_FUN_10003472(s_statwin_water_avi_10011bfc);
    DAT_1001317c = (char)uval_2;
    DAT_10013168 = 1;
  }
  cVar1 = DAT_1001317c;
  if (DAT_10013170 == 0) {
    _getcwd(acStack_104,0x100);
    cVar1 = acStack_104[0];
  }
  return cVar1;
}


