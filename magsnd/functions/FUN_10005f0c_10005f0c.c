/*
 * Decompiled function: FUN_10005f0c
 * Entry Point: 10005f0c
 * Size: 1024 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_10005f0c(int32_t *ptr_1,int arg_2)

{
  int32_t uval_1;
  int local_4c;
  int local_44;
  HPSTR local_40;
  int local_3c;
  int local_38;
  int32_t local_34;
  size_t local_30;
  HPSTR local_2c;
  int local_28;
  int local_24;
  int local_20;
  int32_t local_1c;
  int32_t local_18;
  int local_14;
  int local_10;
  int local_c;
  int32_t local_8;
  
  local_40 = (HPSTR)0x0;
  local_1c = 0;
  local_2c = (HPSTR)0x0;
  local_8 = 0;
  local_18 = 0;
  local_34 = 0;
  local_38 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    thunk_FUN_10005d4a((int)ptr_1,arg_2);
  }
  local_3c = (uint32_t)*(uint16_t *)(ptr_1 + 0x21) * arg_2;
  local_28 = ptr_1[0x73];
  local_4c = local_28 - local_3c;
  local_30 = 0x10000;
  if ((local_3c < 0) || (local_28 < local_3c)) {
    uval_1 = 5;
  }
  else {
    local_20 = local_3c;
    local_c = local_3c;
    local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                         (ptr_1[0x2f],0,0x10000,&local_40,&local_8,&local_1c,&local_18,0);
    if (local_14 == 0) {
      local_2c = local_40;
      local_14 = 0;
      while (local_38 == 0) {
        if (local_4c < (int)local_30) {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            local_10 = mmioRead((HMMIO)ptr_1[0x72],local_2c,local_4c);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,local_2c,local_4c,&local_10,0);
          }
          local_2c = local_2c + local_10;
          local_30 = local_30 - local_10;
          local_4c = 0;
          local_20 = ptr_1[0x73];
          if ((*(uint8_t *)(ptr_1 + 2) & 1) == 0) {
            memset(local_2c,0,local_30);
            local_38 = 1;
          }
          else {
            if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
              thunk_FUN_10005d4a((int)ptr_1,0);
            }
            local_20 = 0;
            local_4c = ptr_1[0x73];
            local_c = 0;
          }
        }
        else {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            local_10 = mmioRead((HMMIO)ptr_1[0x72],local_2c,local_30);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,local_2c,0x10000,&local_10,&local_44);
          }
          local_30 = local_30 - local_10;
          local_c = local_c + local_10;
          local_4c = local_4c - local_10;
          local_20 = local_20 + local_10;
          arg_2 = arg_2 + local_44;
          local_38 = 1;
        }
      }
      mmioGetInfo((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        mmioAdvance((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      }
      else {
        thunk_FUN_10006830(ptr_1,arg_2);
      }
      local_24 = local_4c;
      if (0xffff < local_4c) {
        local_24 = 0x10000;
      }
      ptr_1[0x74] = ptr_1[0x73] - (local_4c - local_24);
      ptr_1[0x75] = ptr_1[0x73] - local_4c;
      ptr_1[0x76] = 0;
      local_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                           (ptr_1[0x2f],local_40,local_8,local_1c,local_18);
      if (local_14 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        thunk_FUN_10005a46(ptr_1);
      }
      else {
        thunk_FUN_1000681e();
      }
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  return uval_1;
}


