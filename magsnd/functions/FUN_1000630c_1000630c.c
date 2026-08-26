/*
 * Decompiled function: FUN_1000630c
 * Entry Point: 1000630c
 * Size: 564 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_1000630c(int32_t *ptr_1)

{
  int32_t uval_1;
  int local_34;
  uint32_t local_30;
  uint8_t local_2c [4];
  uint32_t local_28;
  int local_24;
  uint8_t local_20 [4];
  int local_1c;
  int local_18;
  int32_t local_14;
  int local_10;
  int32_t local_c;
  int local_8;
  
  local_24 = ptr_1[0x25] * ptr_1[0x23];
  local_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                      (ptr_1[0x2f],0,local_24,&local_34,&local_c,&local_18,&local_14,0);
  if (local_8 == 0) {
    if (local_18 == 0) {
      ptr_1[0x76] = 0;
      ptr_1[0x74] = 0;
      ptr_1[0x75] = 0;
      local_1c = local_34;
      local_10 = 0;
      local_28 = (uint32_t)ptr_1[0x23] / (uint32_t)ptr_1[0x24];
      local_8 = 0;
      for (local_30 = 0; local_30 < (uint32_t)ptr_1[0x25]; local_30 = local_30 + 1) {
        AVIStreamRead(*ptr_1,local_10,local_28,local_1c,ptr_1[0x23],local_2c,local_20);
        ptr_1[0x76] = ptr_1[0x76] + ptr_1[0x23];
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + ptr_1[0x23];
        ptr_1[0x75] = ptr_1[0x75] + ptr_1[0x23];
        local_1c = local_1c + ptr_1[0x23];
        local_10 = local_10 + local_28;
      }
      local_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                          (ptr_1[0x2f],local_34,local_c,local_18,local_14);
      if (local_8 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],local_34,local_c,local_18,local_14);
      thunk_FUN_1000681e();
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  else {
    thunk_FUN_1000681e();
    thunk_FUN_10006622(ptr_1);
    uval_1 = 9;
  }
  return uval_1;
}


