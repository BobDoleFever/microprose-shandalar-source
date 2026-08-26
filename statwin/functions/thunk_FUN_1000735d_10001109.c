/*
 * Decompiled function: thunk_FUN_1000735d
 * Entry Point: 10001109
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_1000735d(void *this,int arg_2)

{
  int val_1;
  CPrintPreviewState *pCVar2;
  int32_t *unaff_FS_OFFSET;
  int *piStack_17c;
  int *piStack_168;
  char acStack_15c [256];
  CPrintPreviewState aCStack_5c [24];
  CPrintPreviewState aCStack_44 [24];
  int *piStack_2c;
  int *piStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int iStack_8;
  
  iStack_8 = 0xffffffff;
  puStack_c = &LAB_100077ea;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_5c);
  iStack_8 = 0;
  CPrintPreviewState::CPrintPreviewState(aCStack_44);
  iStack_8._0_1_ = 1;
  val_1 = arg_2 * 0x110;
  iStack_24 = *(int *)(&DAT_1000ed78 + val_1);
  iStack_20 = *(int *)(&DAT_1000ed7c + val_1);
  iStack_1c = *(int *)(&DAT_1000ed80 + val_1);
  iStack_18 = *(int *)(&DAT_1000ed84 + val_1);
  thunk_FUN_10004200(aCStack_44,0xff00);
  thunk_FUN_1000432f(acStack_15c,PTR_s_statwin__10012ac0,"wht-sprt.bmp" + arg_2 * 0x110);
  val_1 = thunk_FUN_1000a2e4(aCStack_44,(HWND)0x0,acStack_15c,0x18);
  if (val_1 == 0) {
    iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
    FUN_100077d8();
    iStack_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  thunk_FUN_1000ad09(aCStack_44,*(CFontDialog **)((int)this + 0xc),
                     *(int *)((int)this + 0x14) + iStack_24,*(int *)((int)this + 0x18) + iStack_20,
                     iStack_1c,iStack_18,0,0);
  pCVar2 = operator_new(0x18);
  iStack_8._0_1_ = 2;
  if (pCVar2 == (CPrintPreviewState *)0x0) {
    piStack_168 = (int *)0x0;
  }
  else {
    piStack_168 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar2);
  }
  iStack_8._0_1_ = 1;
  piStack_2c = piStack_168;
  thunk_FUN_10004200(piStack_168,0);
  thunk_FUN_1000432f(acStack_15c,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
  val_1 = (**(code **)*piStack_2c)(0,acStack_15c,0x18);
  if (val_1 == 0) {
    iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
    FUN_100077d8();
    iStack_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  val_1 = arg_2 * 0x110;
  iStack_24 = *(int *)(&DAT_1000d6a8 + val_1);
  iStack_20 = *(int *)(&DAT_1000d6ac + val_1);
  iStack_1c = *(int *)(&DAT_1000d6b0 + val_1);
  iStack_18 = *(int *)(&DAT_1000d6b4 + val_1);
  (**(code **)(*piStack_2c + 0x18))
            (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + iStack_24,
             *(int *)((int)this + 0x18) + iStack_20,iStack_1c,iStack_18,0,0);
  if (piStack_2c != (int *)0x0) {
    thunk_FUN_10004250(piStack_2c,1);
  }
  pCVar2 = operator_new(0x18);
  iStack_8._0_1_ = 3;
  if (pCVar2 == (CPrintPreviewState *)0x0) {
    piStack_17c = (int *)0x0;
  }
  else {
    piStack_17c = (int *)CPrintPreviewState::CPrintPreviewState(pCVar2);
  }
  iStack_8._0_1_ = 1;
  piStack_28 = piStack_17c;
  thunk_FUN_10004200(piStack_17c,0);
  thunk_FUN_1000432f(acStack_15c,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
  val_1 = (**(code **)*piStack_28)(0,acStack_15c,0x18);
  if (val_1 == 0) {
    iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
    FUN_100077d8();
    iStack_8 = 0xffffffff;
    FUN_100077e1();
    FUN_100077f4();
    return;
  }
  iStack_14 = *(int *)(&DAT_1000d164 + arg_2 * 0x110) -
              (*(int *)(*(int *)this + arg_2 * 4) * *(int *)(&DAT_1000d164 + arg_2 * 0x110)) / 0x1e;
  val_1 = arg_2 * 0x110;
  iStack_24 = *(int *)(&DAT_1000d158 + val_1);
  iStack_20 = *(int *)(&DAT_1000d15c + val_1);
  iStack_1c = *(int *)(&DAT_1000d160 + val_1);
  iStack_18 = *(int *)(&DAT_1000d164 + val_1);
  (**(code **)(*piStack_28 + 0x18))
            (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + iStack_24,
             *(int *)((int)this + 0x18) + iStack_20 + iStack_14,iStack_1c,iStack_18 - iStack_14,0,
             iStack_14);
  if (piStack_28 != (int *)0x0) {
    thunk_FUN_10004250(piStack_28,1);
  }
  iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
  FUN_100077d8();
  iStack_8 = 0xffffffff;
  FUN_100077e1();
  FUN_100077f4();
  return;
}


