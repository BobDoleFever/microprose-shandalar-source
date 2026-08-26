/*
 * Decompiled function: SetVidBackgroundToBMP
 * Entry Point: 10001163
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl SetVidBackgroundToBMP(int *ptr_1,int32_t arg_2,int arg_3)

{
  LPARAM *ptr_1_00;
  int32_t uval_1;
  int val_2;
  CPrintPreviewState *this;
  int32_t *unaff_FS_OFFSET;
  LPARAM LStack_20;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
                    /* 0x1163  9  SetVidBackgroundToBMP */
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100032d7;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
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
      uStack_8 = 0;
      if (this == (CPrintPreviewState *)0x0) {
        LStack_20 = 0;
      }
      else {
        LStack_20 = CPrintPreviewState::CPrintPreviewState(this);
      }
      uStack_8 = 0xffffffff;
      ptr_1_00[0x14] = LStack_20;
      thunk_FUN_100089e8((void *)ptr_1_00[0x14],ptr_1,arg_2);
      thunk_FUN_100066d7(ptr_1_00);
      thunk_FUN_10006a43(ptr_1_00);
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}


