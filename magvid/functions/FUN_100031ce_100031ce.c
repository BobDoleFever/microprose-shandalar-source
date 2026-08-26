/*
 * Decompiled function: FUN_100031ce
 * Entry Point: 100031ce
 * Size: 267 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100031ce(int *ptr_1,int32_t arg_2,int arg_3)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  int val_2;
  CPrintPreviewState *this;
  int32_t *unaff_FS_OFFSET;
  LPARAM local_20;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100032d7;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((arg_3 < 0) || (2 < arg_3)) {
    uval_1 = 2;
  }
  else {
    ptr_1_00 = *(LPARAM **)(&DAT_10010868 + arg_3 * 4);
    if (ptr_1_00 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[2] < 0) {
        val_2 = abs(ptr_1[2]);
        ptr_1[2] = val_2;
      }
      this = operator_new(0x18);
      local_8 = 0;
      if (this == (CPrintPreviewState *)0x0) {
        local_20 = 0;
      }
      else {
        local_20 = CPrintPreviewState::CPrintPreviewState(this);
      }
      local_8 = 0xffffffff;
      ptr_1_00[0x14] = local_20;
      thunk_FUN_100089e8((void *)ptr_1_00[0x14],ptr_1,arg_2);
      thunk_FUN_100066d7(ptr_1_00);
      thunk_FUN_10006a43(ptr_1_00);
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}


