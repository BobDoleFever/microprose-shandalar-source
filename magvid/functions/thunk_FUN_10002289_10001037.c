/*
 * Decompiled function: thunk_FUN_10002289
 * Entry Point: 10001037
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __thiscall thunk_FUN_10002289(void *this,int arg_2)

{
  int32_t uval_1;
  CPrintPreviewState *this_00;
  uint32_t uval_2;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_40;
  uint8_t auStack_38 [14];
  uint16_t uStack_2a;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100023b6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    if (arg_2 != 0) {
      thunk_FUN_1000b759(*(void **)this,auStack_38);
      this_00 = operator_new(0x18);
      uStack_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        uStack_40 = 0;
      }
      else {
        uStack_40 = CPrintPreviewState::CPrintPreviewState(this_00);
      }
      uStack_8 = 0xffffffff;
      *(int32_t *)((int)this + 4) = uStack_40;
      uval_2 = (uint32_t)uStack_2a;
      pHVar3 = GetActiveWindow();
      val_4 = (**(code **)**(int32_t **)((int)this + 4))(pHVar3,arg_2,uval_2);
      if (val_4 == 0) {
        uval_1 = 0xfffffffb;
        goto LAB_100023c0;
      }
    }
    val_4 = thunk_FUN_1000bac7(*(void **)this,*(int **)((int)this + 4));
    if (val_4 == 0) {
      uval_1 = 0xfffffffb;
    }
    else {
      uval_1 = 0;
    }
  }
  else {
    uval_1 = 0xfffffffc;
  }
LAB_100023c0:
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}


