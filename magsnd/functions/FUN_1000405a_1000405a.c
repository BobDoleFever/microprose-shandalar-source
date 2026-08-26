/*
 * Decompiled function: FUN_1000405a
 * Entry Point: 1000405a
 * Size: 874 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_1000405a(int32_t *ptr_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t local_48;
  int32_t local_44;
  int32_t local_40;
  int32_t local_3c;
  int32_t local_38;
  uint32_t local_34;
  uint32_t local_30;
  uint8_t local_2c [4];
  int32_t local_28;
  int32_t local_24;
  uint32_t local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint32_t local_c;
  uint32_t local_8;
  
  local_28 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_24 = 0;
  local_44 = 0;
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  local_3c = 0;
  (**(code **)(*(int *)ptr_1[0x2f] + 0x10))(ptr_1[0x2f],&local_48,&local_28);
  local_34 = (uint32_t)ptr_1[0x77] % (uint32_t)ptr_1[0x2c];
  if (local_34 < local_48) {
    ptr_1[0x77] = ptr_1[0x77] + (local_48 - local_34);
  }
  else {
    ptr_1[0x77] = ptr_1[0x77] + (ptr_1[0x2c] - local_34);
    ptr_1[0x77] = ptr_1[0x77] + local_48;
  }
  local_30 = local_48 / (uint32_t)ptr_1[0x23];
  local_20 = (uint32_t)ptr_1[0x76] / (uint32_t)ptr_1[0x23];
  if (local_20 != local_30) {
    if (((((uint32_t)ptr_1[1] >> 4 & 1) == 0) || ((uint32_t)ptr_1[0x75] < (uint32_t)ptr_1[0x2c])) &&
       ((((uint32_t)ptr_1[1] >> 1 & 1) == 0 || (ptr_1[0x7c] != 0)))) {
      local_18 = ptr_1[0x23];
      if (((uint32_t)ptr_1[1] >> 4 & 1) == 0) {
        uval_1 = ptr_1[0x74];
        uval_2 = ptr_1[0x24];
        local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                             (ptr_1[0x2f],ptr_1[0x76],local_18,&local_44,&local_8,&local_10,&local_c
                              ,0);
        if (local_14 != 0) {
          return 10;
        }
        AVIStreamRead(*ptr_1,uval_1 / uval_2,local_8 / (uint32_t)ptr_1[0x24],local_44,local_8,local_2c,
                      &local_1c);
        if (local_10 != 0) {
          AVIStreamRead(*ptr_1,local_1c + uval_1 / uval_2,local_c / (uint32_t)ptr_1[0x24],local_10,local_c
                        ,local_2c,&local_1c);
        }
        ptr_1[0x76] = ptr_1[0x76] + local_18;
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + local_18;
        ptr_1[0x75] = ptr_1[0x75] + local_18;
        if ((uint32_t)ptr_1[0x73] <= (uint32_t)ptr_1[0x74]) {
          ptr_1[1] = ptr_1[1] | 0x10;
          ptr_1[0x75] = 0;
        }
        (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],local_44,local_8,local_10,local_c);
        ptr_1[1] = ptr_1[1] & 0xffffff7f;
      }
      else {
        ptr_1[0x75] = ptr_1[0x75] + local_18;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x48))(ptr_1[0x2f]);
      if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      ptr_1[1] = ptr_1[1] & 0xfffffffe;
      ptr_1[1] = ptr_1[1] & 0xfffffffd;
      ptr_1[1] = ptr_1[1] | 4;
      ptr_1[1] = ptr_1[1] & 0xffffffdf;
      ptr_1[0x77] = 0;
    }
  }
  return 0;
}


