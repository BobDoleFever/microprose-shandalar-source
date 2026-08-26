/*
 * Decompiled function: thunk_FUN_1000785e
 * Entry Point: 100011db
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __fastcall thunk_FUN_1000785e(int *ptr_1)

{
  int32_t uval_1;
  int32_t *ptr_1_00;
  int val_2;
  void *buf_ptr_3;
  int32_t *unaff_FS_OFFSET;
  int32_t *puStack_d4;
  uint8_t auStack_cc [4];
  int iStack_c8;
  int iStack_b0;
  int iStack_ac;
  int iStack_a4;
  int32_t uStack_40;
  uint8_t auStack_3c [40];
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10007a6c;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (ptr_1[3] == 0) {
    uval_1 = 0xffffffec;
  }
  else {
    if (*ptr_1 != 0) {
      thunk_FUN_10007a85(ptr_1);
    }
    ptr_1[0xd] = -1;
    AVIStreamInfoA(ptr_1[3],auStack_cc,0x8c);
    ptr_1[0x11] = iStack_b0;
    ptr_1[0x15] = ptr_1[0x11];
    ptr_1[0x16] = iStack_b0 + iStack_ac + -1;
    ptr_1[0x12] = ptr_1[0x11] + -1;
    AVIStreamReadFormat(ptr_1[3],0,0,&iStack_14);
    if (iStack_14 == 0x28) {
      uStack_40 = AVIStreamReadFormat(ptr_1[3],0,auStack_3c,&iStack_14);
      ptr_1_00 = operator_new(0x1b0);
      uStack_8 = 0;
      if (ptr_1_00 == (int32_t *)0x0) {
        puStack_d4 = (int32_t *)0x0;
      }
      else {
        puStack_d4 = thunk_FUN_1000a250(ptr_1_00);
      }
      uStack_8 = 0xffffffff;
      *ptr_1 = (int)puStack_d4;
      val_2 = thunk_FUN_1000a30f((void *)*ptr_1,iStack_c8,auStack_3c);
      if (val_2 == 0) {
        ptr_1[0x18] = iStack_a4;
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
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}


