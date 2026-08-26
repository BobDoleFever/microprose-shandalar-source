/*
 * Decompiled function: FUN_10002289
 * Entry Point: 10002289
 * Size: 295 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_10002289(void *this,int arg_2)

{
  int32_t uval_1;
  CPrintPreviewState *this_00;
  uint32_t uval_2;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t local_40;
  uint8_t local_38 [14];
  uint16_t local_2a;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100023b6;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if ((*(int *)((int)this + 0xc) == 0) || (*(int *)this == 0)) {
    uval_1 = 0xffffffff;
  }
  else if (*(int *)((int)this + 0x18) == 0) {
    if (arg_2 != 0) {
      thunk_FUN_1000b759(*(void **)this,local_38);
      this_00 = operator_new(0x18);
      local_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        local_40 = 0;
      }
      else {
        local_40 = CPrintPreviewState::CPrintPreviewState(this_00);
      }
      local_8 = 0xffffffff;
      *(int32_t *)((int)this + 4) = local_40;
      uval_2 = (uint32_t)local_2a;
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
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}


