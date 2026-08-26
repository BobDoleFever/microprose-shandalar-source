/*
 * Decompiled function: Sound_UnloadSample
 * Entry Point: 1000192c
 * Size: 800 bytes
 */
#include "magsnd.h"


int __cdecl Sound_UnloadSample(int32_t *ptr_1,int *ptr_2)

{
  int val_1;
  int local_1c;
  int *local_18;
  uint32_t local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_c = 0;
  if (((uint32_t)ptr_1[2] >> 1 & 1) == 0) {
    if ((ptr_2 == (int *)0x0) || (((uint32_t)ptr_2[7] >> 1 & 1) == 0)) {
      val_1 = thunk_FUN_100043c4((int)ptr_1,(int *)&local_18);
      if (val_1 != 0) {
        return val_1;
      }
      local_8 = 0;
    }
    else {
      local_18 = (int *)ptr_1[0x2f];
    }
  }
  else {
    if ((*(uint8_t *)(ptr_1 + 1) & 1) != 0) {
      thunk_FUN_10002900(ptr_1[4]);
    }
    if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
       (local_8 = thunk_FUN_100046fb(), local_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return local_8;
    }
    if (DAT_1000a420 != 0) {
      DAT_1000a428 = DAT_1000a428 + 1;
    }
    local_14 = local_14 | 1;
    local_18 = (int *)ptr_1[0x2f];
    if ((((uint32_t)ptr_1[1] >> 5 & 1) == 0) && (local_8 = thunk_FUN_1000394f(ptr_1), local_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return local_8;
    }
  }
  if (ptr_2 == (int *)0x0) {
    local_1c = 0;
    ptr_1[0x7c] = 400;
    local_c = ptr_1[0x1f];
    ptr_1[0x7b] = local_c;
    local_10 = 0;
    ptr_1[0x7a] = 0;
  }
  else {
    local_1c = *ptr_2;
    if (400 < local_1c) {
      local_1c = 400;
    }
    ptr_1[0x7c] = local_1c;
    local_1c = (local_1c * 5 + -2000) * 2;
    if (ptr_2[1] == 0) {
      local_c = ptr_1[0x1f];
    }
    else {
      local_c = ptr_2[1];
    }
    ptr_1[0x7b] = local_c;
    if (ptr_2[2] == 0) {
      local_10 = 0;
    }
    else {
      local_10 = ptr_2[2];
    }
    ptr_1[0x7a] = local_10;
    local_10 = local_10 * 10;
    if ((*(uint8_t *)(ptr_2 + 7) & 1) != 0) {
      local_14 = local_14 | 1;
      ptr_1[2] = ptr_1[2] | 1;
    }
    if (((uint32_t)ptr_2[7] >> 3 & 1) != 0) {
      ptr_1[2] = ptr_1[2] | 4;
    }
  }
  (**(code **)(*local_18 + 0x3c))(local_18,local_1c);
  (**(code **)(*local_18 + 0x44))(local_18,local_c);
  (**(code **)(*local_18 + 0x40))(local_18,local_10);
  (**(code **)(*local_18 + 0x34))(local_18,0);
  val_1 = (**(code **)(*local_18 + 0x30))(local_18,0,0,local_14);
  if (val_1 == 0) {
    ptr_1[1] = ptr_1[1] | 1;
    ptr_1[1] = ptr_1[1] & 0xffffffdf;
    val_1 = 0;
  }
  else {
    val_1 = 9;
  }
  return val_1;
}


