/*
 * Decompiled function: UpdateSnd
 * Entry Point: 100010f0
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t UpdateSnd(void)

{
  int32_t *u_ptr_1;
  int32_t uval_2;
  int32_t *puStack_c;
  
                    /* 0x10f0  17  UpdateSnd */
  if (DAT_1000a46c == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_1000baa0);
    puStack_c = DAT_1000a418;
    while (puStack_c != (int32_t *)0x0) {
      if ((*(uint8_t *)(puStack_c + 1) & 1) != 0) {
        if (((uint32_t)puStack_c[1] >> 1 & 1) != 0) {
          if ((uint32_t)puStack_c[0x7c] < 6) {
            puStack_c[0x7c] = 0;
          }
          else {
            puStack_c[0x7c] = puStack_c[0x7c] + -5;
          }
          SetVol(puStack_c[4],puStack_c[0x7c]);
        }
        if (((uint32_t)puStack_c[2] >> 5 & 1) == 0) {
          thunk_FUN_10003a41((int)puStack_c);
        }
        else if (((uint32_t)puStack_c[2] >> 6 & 1) == 0) {
          thunk_FUN_1000405a(puStack_c);
        }
      }
      if ((((uint32_t)puStack_c[1] >> 2 & 1) == 0) || (((uint32_t)puStack_c[2] >> 2 & 1) == 0)) {
        puStack_c = (int32_t *)puStack_c[0x7e];
      }
      else {
        u_ptr_1 = (int32_t *)puStack_c[0x80];
        UnloadSnd(puStack_c[4]);
        puStack_c = u_ptr_1;
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


