/*
 * Decompiled function: thunk_FUN_10006d86
 * Entry Point: 1000100f
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_10006d86(void *this,int arg_2)

{
  int val_1;
  int32_t *unaff_FS_OFFSET;
  char acStack_180 [256];
  CPrintPreviewState aCStack_80 [24];
  CPrintPreviewState aCStack_68 [24];
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  CPrintPreviewState aCStack_40 [24];
  CPrintPreviewState aCStack_28 [24];
  int32_t uStack_10;
  uint8_t *puStack_c;
  int iStack_8;
  
  iStack_8 = 0xffffffff;
  puStack_c = &LAB_10007068;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_80);
  iStack_8 = 0;
  CPrintPreviewState::CPrintPreviewState(aCStack_28);
  iStack_8._0_1_ = 1;
  val_1 = arg_2 * 0x110;
  iStack_50 = *(int *)(&DAT_10011e88 + val_1);
  iStack_4c = *(int *)(&DAT_10011e8c + val_1);
  iStack_48 = *(int *)(&DAT_10011e90 + val_1);
  iStack_44 = *(int *)(&DAT_10011e94 + val_1);
  thunk_FUN_10004200(aCStack_28,0xff00);
  thunk_FUN_1000432f(acStack_180,PTR_s_statwin__10012ac0,s_wht_mask_bmp_10011d88 + arg_2 * 0x110);
  val_1 = thunk_FUN_1000a2e4(aCStack_28,(HWND)0x0,acStack_180,0x18);
  if (val_1 == 0) {
    iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
    FUN_10007056();
    iStack_8 = 0xffffffff;
    FUN_1000705f();
    FUN_10007072();
    return;
  }
  thunk_FUN_1000ad09(aCStack_28,*(CFontDialog **)((int)this + 0xc),
                     *(int *)((int)this + 0x14) + iStack_50,*(int *)((int)this + 0x18) + iStack_4c,
                     iStack_48,iStack_44,0,0);
  CPrintPreviewState::CPrintPreviewState(aCStack_40);
  iStack_8._0_1_ = 2;
  val_1 = arg_2 * 0x110;
  iStack_50 = *(int *)(&DAT_1000dbf8 + val_1);
  iStack_4c = *(int *)(&DAT_1000dbfc + val_1);
  iStack_48 = *(int *)(&DAT_1000dc00 + val_1);
  iStack_44 = *(int *)(&DAT_1000dc04 + val_1);
  thunk_FUN_1000432f(acStack_180,PTR_s_statwin__10012ac0,"S-wmsk.tmp" + arg_2 * 0x110);
  thunk_FUN_1000a2e4(aCStack_40,(HWND)0x0,acStack_180,0x18);
  thunk_FUN_1000ad09(aCStack_40,*(CFontDialog **)((int)this + 0xc),
                     *(int *)((int)this + 0x14) + iStack_50,*(int *)((int)this + 0x18) + iStack_4c,
                     iStack_48,iStack_44,0,0);
  CPrintPreviewState::CPrintPreviewState(aCStack_68);
  iStack_8._0_1_ = 3;
  val_1 = arg_2 * 0x110;
  iStack_50 = *(int *)(&DAT_1000e698 + val_1);
  iStack_4c = *(int *)(&DAT_1000e69c + val_1);
  iStack_48 = *(int *)(&DAT_1000e6a0 + val_1);
  iStack_44 = *(int *)(&DAT_1000e6a4 + val_1);
  thunk_FUN_1000432f(acStack_180,PTR_s_statwin__10012ac0,"W-mmask.tmp" + arg_2 * 0x110);
  thunk_FUN_1000a2e4(aCStack_68,(HWND)0x0,acStack_180,0x18);
  thunk_FUN_1000ad09(aCStack_68,*(CFontDialog **)((int)this + 0xc),
                     *(int *)((int)this + 0x14) + iStack_50,*(int *)((int)this + 0x18) + iStack_4c,
                     iStack_48,iStack_44,0,0);
  iStack_8._0_1_ = 2;
  FUN_10007044();
  iStack_8._0_1_ = 1;
  FUN_1000704d();
  iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
  FUN_10007056();
  iStack_8 = 0xffffffff;
  FUN_1000705f();
  FUN_10007072();
  return;
}


