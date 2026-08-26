/*
 * Decompiled function: FUN_10007083
 * Entry Point: 10007083
 * Size: 704 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_10007083(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int32_t uval_1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int *local_124;
  char local_11c [256];
  int *local_1c;
  int local_18;
  uint32_t local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10007342;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  this_00 = operator_new(0x18);
  local_8 = 0;
  if (this_00 == (CPrintPreviewState *)0x0) {
    local_124 = (int *)0x0;
  }
  else {
    local_124 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
  }
  local_8 = 0xffffffff;
  local_1c = local_124;
  local_14 = (uint32_t)*(uint8_t *)(*(int *)this + 0x28 + arg_2);
  if (local_14 == 0) {
    if (local_124 != (int *)0x0) {
      thunk_FUN_10004250(local_124,1);
    }
    uval_1 = 7;
  }
  else {
    thunk_FUN_1000432f(local_11c,PTR_s_statwin__10012ac0,"W-mana.bmp" + arg_2 * 0x110);
    val_2 = (**(code **)*local_1c)(0,local_11c,0x18);
    if (val_2 == 0) {
      if (local_1c != (int *)0x0) {
        thunk_FUN_10004250(local_1c,1);
      }
      uval_1 = 6;
    }
    else {
      local_18 = 0;
      for (local_14 = local_14 & 0x1f; (local_18 < 5 && (0 < (int)local_14));
          local_14 = local_14 - 1) {
        (**(code **)(*local_1c + 0x18))
                  (*(int32_t *)((int)this + 0xc),
                   *(int *)(&DAT_1000eae8 + arg_2 * 0x50 + local_18 * 0x10) +
                   *(int *)(&DAT_1000e148 + arg_2 * 0x110) + *(int *)((int)this + 0x14),
                   *(int *)(&DAT_1000eaec + arg_2 * 0x50 + local_18 * 0x10) +
                   *(int *)(&DAT_1000e14c + arg_2 * 0x110) + *(int *)((int)this + 0x18),
                   *(int32_t *)(&DAT_1000eaf0 + arg_2 * 0x50 + local_18 * 0x10),
                   *(int32_t *)(&DAT_1000eaf4 + arg_2 * 0x50 + local_18 * 0x10),
                   *(int32_t *)(&DAT_1000eae8 + arg_2 * 0x50 + local_18 * 0x10),
                   *(int32_t *)(&DAT_1000eaec + arg_2 * 0x50 + local_18 * 0x10));
        local_18 = local_18 + 1;
      }
      if (local_1c != (int *)0x0) {
        thunk_FUN_10004250(local_1c,1);
      }
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}


