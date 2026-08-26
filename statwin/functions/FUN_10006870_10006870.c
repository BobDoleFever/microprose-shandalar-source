/*
 * Decompiled function: FUN_10006870
 * Entry Point: 10006870
 * Size: 693 bytes
 */
#include "statwin.h"


void __thiscall FUN_10006870(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t *unaff_FS_OFFSET;
  int *local_128;
  char local_120 [256];
  int *local_20;
  int local_1c;
  int local_18;
  uint8_t local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10006b25;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    if (*(int *)(arg_2 + local_18 * 4) != 0) {
      this_00 = operator_new(0x18);
      local_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        local_128 = (int *)0x0;
      }
      else {
        local_128 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      local_8 = 0xffffffff;
      local_20 = local_128;
      local_14 = *(uint8_t *)(*(int *)this + 0x28 + local_18);
      if (local_14 == 0) {
        if (local_128 != (int *)0x0) {
          thunk_FUN_10004250(local_128,1);
        }
      }
      else {
        thunk_FUN_1000432f(local_120,PTR_s_statwin__10012ac0,"W-mana.bmp" + local_18 * 0x110);
        val_1 = (**(code **)*local_20)(0,local_120,0x18);
        if (val_1 == 0) break;
        local_1c = 0;
        for (local_14 = local_14 & 0x1f; (local_1c < 5 && (local_14 != 0)); local_14 = local_14 - 1)
        {
          if (local_14 != 0) {
            (**(code **)(*local_20 + 0x18))
                      (*(int32_t *)((int)this + 0xc),
                       *(int *)(&DAT_1000eae8 + local_1c * 0x10 + local_18 * 0x50) +
                       *(int *)(&DAT_1000e148 + local_18 * 0x110),
                       *(int *)(&DAT_1000eaec + local_1c * 0x10 + local_18 * 0x50) +
                       *(int *)(&DAT_1000e14c + local_18 * 0x110),
                       *(int32_t *)(&DAT_1000eaf0 + local_1c * 0x10 + local_18 * 0x50),
                       *(int32_t *)(&DAT_1000eaf4 + local_1c * 0x10 + local_18 * 0x50),
                       *(int32_t *)(&DAT_1000eae8 + local_1c * 0x10 + local_18 * 0x50),
                       *(int32_t *)(&DAT_1000eaec + local_1c * 0x10 + local_18 * 0x50));
          }
          local_1c = local_1c + 1;
        }
        if (local_20 != (int *)0x0) {
          thunk_FUN_10004250(local_20,1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


