/*
 * Decompiled function: FUN_1000785e
 * Entry Point: 1000785e
 * Size: 525 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_1000785e(int *ptr_1)

{
  int32_t uval_1;
  int32_t *ptr_1_00;
  int val_2;
  void *buf_ptr_3;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_d4;
  uint8_t local_cc [4];
  int local_c8;
  int local_b0;
  int local_ac;
  int local_a4;
  int32_t local_40;
  uint8_t local_3c [40];
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10007a6c;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if (ptr_1[3] == 0) {
    uval_1 = 0xffffffec;
  }
  else {
    if (*ptr_1 != 0) {
      thunk_FUN_10007a85(ptr_1);
    }
    ptr_1[0xd] = -1;
    AVIStreamInfoA(ptr_1[3],local_cc,0x8c);
    ptr_1[0x11] = local_b0;
    ptr_1[0x15] = ptr_1[0x11];
    ptr_1[0x16] = local_b0 + local_ac + -1;
    ptr_1[0x12] = ptr_1[0x11] + -1;
    AVIStreamReadFormat(ptr_1[3],0,0,&local_14);
    if (local_14 == 0x28) {
      local_40 = AVIStreamReadFormat(ptr_1[3],0,local_3c,&local_14);
      ptr_1_00 = operator_new(0x1b0);
      local_8 = 0;
      if (ptr_1_00 == (int32_t *)0x0) {
        local_d4 = (int32_t *)0x0;
      }
      else {
        local_d4 = thunk_FUN_1000a250(ptr_1_00);
      }
      local_8 = 0xffffffff;
      *ptr_1 = (int)local_d4;
      val_2 = thunk_FUN_1000a30f((void *)*ptr_1,local_c8,local_3c);
      if (val_2 == 0) {
        ptr_1[0x18] = local_a4;
        buf_ptr_3 = malloc(ptr_1[0x18]);
        ptr_1[0x17] = (int)buf_ptr_3;
        if (ptr_1[0x17] == 0) {
          uval_1 = 3;
        }
        else {
          ptr_1[0x10] = 0;
          uval_1 = 0;
        }
      }
      else {
        thunk_FUN_10007a85(ptr_1);
        uval_1 = 0xffffffeb;
      }
    }
    else {
      uval_1 = 0xffffffff;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}


