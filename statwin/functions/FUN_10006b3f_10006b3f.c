/*
 * Decompiled function: FUN_10006b3f
 * Entry Point: 10006b3f
 * Size: 423 bytes
 */
#include "statwin.h"


void __thiscall FUN_10006b3f(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t *unaff_FS_OFFSET;
  int *local_130;
  char local_128 [256];
  int32_t local_28;
  int32_t local_24;
  int32_t local_20;
  int32_t local_1c;
  int *local_18;
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10006ce6;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    if (*(int *)(arg_2 + local_14 * 4) != 0) {
      this_00 = operator_new(0x18);
      local_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        local_130 = (int *)0x0;
      }
      else {
        local_130 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      local_8 = 0xffffffff;
      local_18 = local_130;
      thunk_FUN_1000432f(local_128,PTR_s_statwin__10012ac0,"wht-sprt.bmp" + local_14 * 0x110);
      val_1 = (**(code **)*local_18)(0,local_128,0x18);
      if (val_1 == 0) break;
      val_1 = local_14 * 0x110;
      local_28 = *(int32_t *)(&DAT_1000ed78 + val_1);
      local_24 = *(int32_t *)(&DAT_1000ed7c + val_1);
      local_20 = *(int32_t *)(&DAT_1000ed80 + val_1);
      local_1c = *(int32_t *)(&DAT_1000ed84 + val_1);
      thunk_FUN_10004200(local_18,0xff00);
      (**(code **)(*local_18 + 0x18))
                (*(int32_t *)((int)this + 0xc),local_28,local_24,local_20,local_1c,0,0);
      if (local_18 != (int *)0x0) {
        thunk_FUN_10004250(local_18,1);
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


