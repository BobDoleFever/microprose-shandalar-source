/*
 * Decompiled function: FUN_1000667b
 * Entry Point: 1000667b
 * Size: 419 bytes
 */
#include "magsnd.h"


int32_t __cdecl FUN_1000667b(int32_t arg_1,int *ptr_2)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int val_3;
  int32_t *puVar4;
  int32_t *puVar5;
  int32_t uStack0000000c;
  int32_t local_fc [4];
  int16_t local_ec;
  int32_t local_e8 [18];
  uint8_t local_a0 [4];
  int local_9c;
  int local_98;
  int32_t local_94;
  int local_90 [8];
  int local_70;
  int local_68;
  int local_60;
  
  local_94 = 0x12;
  AVIStreamInfoA(arg_1,local_90,0x8c);
  if (local_90[0] == 0x73647561) {
    AVIStreamRead(arg_1,0,1,0,0,local_a0,0);
    local_98 = local_60 * local_70;
    AVIStreamReadFormat(arg_1,0,local_fc,&local_94);
    local_ec = 0;
    uStack0000000c = 0xe8;
    local_9c = local_68 * 0xb;
    buf_ptr_2 = thunk_FUN_10006540(DAT_1000ba90,local_9c,local_fc,0xe8);
    *ptr_2 = (int)buf_ptr_2;
    if (*ptr_2 == 0) {
      uval_1 = 9;
    }
    else {
      *(int32_t *)(*ptr_2 + 0x1e0) = 0;
      *(int32_t *)(*ptr_2 + 0x1c8) = 0;
      puVar4 = local_e8;
      puVar5 = (int32_t *)(*ptr_2 + 0x180);
      for (val_3 = 0x12; val_3 != 0; val_3 = val_3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(int *)(*ptr_2 + 0x1cc) = local_98;
      *(int32_t *)*ptr_2 = arg_1;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 0x20;
      *(uint32_t *)(*ptr_2 + 8) = *(uint32_t *)(*ptr_2 + 8) | 2;
      *(int *)(*ptr_2 + 0x8c) = local_68;
      *(int *)(*ptr_2 + 0x90) = local_60;
      *(int32_t *)(*ptr_2 + 0x94) = 0xb;
      *(int32_t *)(*ptr_2 + 0x1dc) = 0;
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 8;
  }
  return uval_1;
}


