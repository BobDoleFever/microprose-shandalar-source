/*
 * Decompiled function: FUN_10007d32
 * Entry Point: 10007d32
 * Size: 907 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_10007d32(void *this,int arg_2)

{
  CPrintPreviewState *pCVar1;
  int val_2;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int *local_154;
  int *local_13c;
  char local_134 [256];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int32_t local_24;
  int32_t local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100080cc;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  pCVar1 = operator_new(0x18);
  local_8 = 0;
  if (pCVar1 == (CPrintPreviewState *)0x0) {
    local_13c = (int *)0x0;
  }
  else {
    local_13c = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
  }
  local_8 = 0xffffffff;
  local_1c = local_13c;
  thunk_FUN_10004200(local_13c,0);
  thunk_FUN_1000432f(local_134,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
  val_2 = (**(code **)*local_1c)(0,local_134,0x18);
  if (val_2 == 0) {
    if (local_1c != (int *)0x0) {
      thunk_FUN_10004250(local_1c,1);
    }
    uval_3 = 4;
  }
  else {
    val_2 = arg_2 * 0x110;
    local_2c = *(int *)(&DAT_1000d6a8 + val_2);
    local_28 = *(int *)(&DAT_1000d6ac + val_2);
    local_24 = *(int32_t *)(&DAT_1000d6b0 + val_2);
    local_20 = *(int32_t *)(&DAT_1000d6b4 + val_2);
    (**(code **)(*local_1c + 0x18))
              (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + local_2c,
               *(int *)((int)this + 0x18) + local_28,local_24,local_20,0,0);
    if (local_1c != (int *)0x0) {
      thunk_FUN_10004250(local_1c,1);
    }
    pCVar1 = operator_new(0x18);
    local_8 = 1;
    if (pCVar1 == (CPrintPreviewState *)0x0) {
      local_154 = (int *)0x0;
    }
    else {
      local_154 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
    }
    local_8 = 0xffffffff;
    local_18 = local_154;
    thunk_FUN_10004200(local_154,0);
    thunk_FUN_1000432f(local_134,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
    val_2 = (**(code **)*local_18)(0,local_134,0x18);
    if (val_2 == 0) {
      if (local_18 != (int *)0x0) {
        thunk_FUN_10004250(local_18,1);
      }
      uval_3 = 4;
    }
    else {
      local_14 = *(int *)(&DAT_10012a9c + arg_2 * 8);
      local_34 = (*(int *)(*(int *)this + arg_2 * 4) * local_14) / 0x1e;
      local_30 = local_14 - local_34;
      val_2 = arg_2 * 0x110;
      local_2c = *(int *)(&DAT_1000d158 + val_2);
      local_28 = *(int *)(&DAT_1000d15c + val_2);
      local_24 = *(int32_t *)(&DAT_1000d160 + val_2);
      local_20 = *(int32_t *)(&DAT_1000d164 + val_2);
      (**(code **)(*local_18 + 0x18))
                (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + local_2c,
                 *(int *)(&DAT_10012a98 + arg_2 * 8) + *(int *)((int)this + 0x18) + local_28 +
                 local_34,local_24,local_30,0,*(int *)(&DAT_10012a98 + arg_2 * 8) + local_34);
      if (local_18 != (int *)0x0) {
        thunk_FUN_10004250(local_18,1);
      }
      uval_3 = 0;
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_3;
}


