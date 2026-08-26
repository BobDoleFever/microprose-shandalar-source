/*
 * Decompiled function: FUN_10002209
 * Entry Point: 10002209
 * Size: 474 bytes
 */
#include "statwin.h"


void __cdecl FUN_10002209(int arg1,int arg2)

{
  int val_1;
  int local_c;
  int local_8;
  
  if (DAT_10011790 == 0) {
    return;
  }
  if (DAT_100117a4[8] == 0) {
    return;
  }
  local_8 = thunk_FUN_10004e94(DAT_100117a4);
  if (local_8 != 0) {
    DAT_100117a4[8] = 0;
    return;
  }
  val_1 = thunk_FUN_1000435f(DAT_100117a4,&arg2,arg1,&local_c);
  if (val_1 == 0) {
    arg2 = 0;
  }
  switch(arg2) {
  case 0:
    thunk_FUN_100049cf(DAT_100117a4,arg1,arg2);
    thunk_FUN_10002be9();
    return;
  case 1:
    if (*(int *)(arg1 + (uint32_t)*(uint8_t *)(arg1 + 0x2d) * 4) == 0) {
      thunk_FUN_1000310f((uint32_t)*(uint8_t *)(arg1 + 0x2d));
      if (*(uint8_t *)(arg1 + 0x2d) < 5) {
        thunk_FUN_100049cf(DAT_100117a4,arg1,arg2);
      }
    }
    else if (DAT_1001154c == 0) {
      thunk_FUN_1000268a(arg1);
    }
    else {
      thunk_FUN_100049cf(DAT_100117a4,arg1,arg2);
      thunk_FUN_10002be9();
    }
    break;
  case 2:
    if (DAT_1001154c == 0) {
      thunk_FUN_1000268a(arg1);
    }
    else {
      thunk_FUN_100049cf(DAT_100117a4,arg1,arg2);
      thunk_FUN_10002be9();
    }
    break;
  case 3:
    thunk_FUN_100049cf(DAT_100117a4,arg1,3);
    thunk_FUN_10002be9();
    break;
  default:
    goto switchD_100023c6_default;
  }
  thunk_FUN_10004afa(DAT_100117a4);
  thunk_FUN_100058cd(DAT_100117a4);
switchD_100023c6_default:
  return;
}


