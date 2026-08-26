/*
 * Decompiled function: FUN_1000735d
 * Entry Point: 1000735d
 * Size: 1115 bytes
 */
#include "statwin.h"


void __thiscall FUN_1000735d(void *this,int arg_2)

{
  int val_1;
  CPrintPreviewState *pCVar2;
  int32_t *unaff_FS_OFFSET;
  int *local_17c;
  int *local_168;
  char local_15c [256];
  CPrintPreviewState local_5c [24];
  CPrintPreviewState local_44 [24];
  int *local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100077ea;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(local_5c);
  local_8 = 0;
  CPrintPreviewState::CPrintPreviewState(local_44);
  local_8._0_1_ = 1;
  val_1 = arg_2 * 0x110;
  local_24 = *(int *)(&DAT_1000ed78 + val_1);
  local_20 = *(int *)(&DAT_1000ed7c + val_1);
  local_1c = *(int *)(&DAT_1000ed80 + val_1);
  local_18 = *(int *)(&DAT_1000ed84 + val_1);
  thunk_FUN_10004200(local_44,0xff00);
  thunk_FUN_1000432f(local_15c,PTR_s_statwin__10012ac0,"wht-sprt.bmp" + arg_2 * 0x110);
  val_1 = thunk_FUN_1000a2e4(local_44,(HWND)0x0,local_15c,0x18);
  if (val_1 == 0) {
    local_8 = (uint32_t)local_8._1_3_ << 8;
    FUN_100077d8();
    local_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  thunk_FUN_1000ad09(local_44,*(CFontDialog **)((int)this + 0xc),
                     *(int *)((int)this + 0x14) + local_24,*(int *)((int)this + 0x18) + local_20,
                     local_1c,local_18,0,0);
  pCVar2 = operator_new(0x18);
  local_8._0_1_ = 2;
  if (pCVar2 == (CPrintPreviewState *)0x0) {
    local_168 = (int *)0x0;
  }
  else {
    local_168 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar2);
  }
  local_8._0_1_ = 1;
  local_2c = local_168;
  thunk_FUN_10004200(local_168,0);
  thunk_FUN_1000432f(local_15c,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
  val_1 = (**(code **)*local_2c)(0,local_15c,0x18);
  if (val_1 == 0) {
    local_8 = (uint32_t)local_8._1_3_ << 8;
    FUN_100077d8();
    local_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  val_1 = arg_2 * 0x110;
  local_24 = *(int *)(&DAT_1000d6a8 + val_1);
  local_20 = *(int *)(&DAT_1000d6ac + val_1);
  local_1c = *(int *)(&DAT_1000d6b0 + val_1);
  local_18 = *(int *)(&DAT_1000d6b4 + val_1);
  (**(code **)(*local_2c + 0x18))
            (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + local_24,
             *(int *)((int)this + 0x18) + local_20,local_1c,local_18,0,0);
  if (local_2c != (int *)0x0) {
    thunk_FUN_10004250(local_2c,1);
  }
  pCVar2 = operator_new(0x18);
  local_8._0_1_ = 3;
  if (pCVar2 == (CPrintPreviewState *)0x0) {
    local_17c = (int *)0x0;
  }
  else {
    local_17c = (int *)CPrintPreviewState::CPrintPreviewState(pCVar2);
  }
  local_8._0_1_ = 1;
  local_28 = local_17c;
  thunk_FUN_10004200(local_17c,0);
  thunk_FUN_1000432f(local_15c,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
  val_1 = (**(code **)*local_28)(0,local_15c,0x18);
  if (val_1 == 0) {
    local_8 = (uint32_t)local_8._1_3_ << 8;
    FUN_100077d8();
    local_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  local_14 = *(int *)(&DAT_1000d164 + arg_2 * 0x110) -
             (*(int *)(*(int *)this + arg_2 * 4) * *(int *)(&DAT_1000d164 + arg_2 * 0x110)) / 0x1e;
  val_1 = arg_2 * 0x110;
  local_24 = *(int *)(&DAT_1000d158 + val_1);
  local_20 = *(int *)(&DAT_1000d15c + val_1);
  local_1c = *(int *)(&DAT_1000d160 + val_1);
  local_18 = *(int *)(&DAT_1000d164 + val_1);
  (**(code **)(*local_28 + 0x18))
            (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + local_24,
             *(int *)((int)this + 0x18) + local_20 + local_14,local_1c,local_18 - local_14,0,
             local_14);
  if (local_28 != (int *)0x0) {
    thunk_FUN_10004250(local_28,1);
  }
  local_8 = (uint32_t)local_8._1_3_ << 8;
  FUN_100077d8();
  local_8 = 0xffffffff;
  FUN_100077e1();
  FUN_100077f4();
  return;
}


