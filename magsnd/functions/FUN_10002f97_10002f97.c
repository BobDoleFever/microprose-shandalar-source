/*
 * Decompiled function: FUN_10002f97
 * Entry Point: 10002f97
 * Size: 335 bytes
 */
#include "magsnd.h"


int32_t FUN_10002f97(void)

{
  int32_t *u_ptr_1;
  int32_t uval_2;
  int32_t *local_c;
  
  if (DAT_1000a46c == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    local_c = DAT_1000a418;
    while (local_c != (int32_t *)0x0) {
      if ((*(uint8_t *)(local_c + 1) & 1) != 0) {
        if (((uint32_t)local_c[1] >> 1 & 1) != 0) {
          if ((uint32_t)local_c[0x7c] < 6) {
            local_c[0x7c] = 0;
          }
          else {
            local_c[0x7c] = local_c[0x7c] + -5;
          }
          SetVol(local_c[4],local_c[0x7c]);
        }
        if (((uint32_t)local_c[2] >> 5 & 1) == 0) {
          thunk_FUN_10003a41((int)local_c);
        }
        else if (((uint32_t)local_c[2] >> 6 & 1) == 0) {
          thunk_FUN_1000405a(local_c);
        }
      }
      if ((((uint32_t)local_c[1] >> 2 & 1) == 0) || (((uint32_t)local_c[2] >> 2 & 1) == 0)) {
        local_c = (int32_t *)local_c[0x7e];
      }
      else {
        u_ptr_1 = (int32_t *)local_c[0x80];
        UnloadSnd(local_c[4]);
        local_c = u_ptr_1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    uval_2 = 0;
  }
  else {
    uval_2 = 0xd;
  }
  return uval_2;
}


