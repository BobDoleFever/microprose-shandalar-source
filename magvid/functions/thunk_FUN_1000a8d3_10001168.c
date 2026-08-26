/*
 * Decompiled function: thunk_FUN_1000a8d3
 * Entry Point: 10001168
 * Size: 5 bytes
 */
#include "magvid.h"


int __thiscall thunk_FUN_1000a8d3(void *this,int arg_2)

{
  int val_1;
  HDC pHVar2;
  CPrintPreviewState *this_00;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_24;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_1000aba6;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if ((*(int *)this == 0) || (arg_2 == 0)) {
    val_1 = -1;
  }
  else {
    *(int *)((int)this + 4) = arg_2;
    pHVar2 = CreateCompatibleDC(*(HDC *)((int)this + 4));
    *(HDC *)((int)this + 0x1a0) = pHVar2;
    val_1 = FUN_1000ac38(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                         *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                         *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                         *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                         *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                         *(int32_t *)((int)this + 0x38));
    if (val_1 == 0) {
      DAT_100275d0 = 1;
      FUN_1000abc1(*(int32_t *)this,0,*(int32_t *)((int)this + 0x14),0,
                   *(int32_t *)((int)this + 0x1c),*(int32_t *)((int)this + 0x20),
                   *(int32_t *)((int)this + 0x24),*(int32_t *)((int)this + 0x28),
                   *(int32_t *)((int)this + 0x18),0,*(int32_t *)((int)this + 0x2c),
                   *(int32_t *)((int)this + 0x30),*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38));
      if (*(int *)((int)this + 0x180) != 0) {
        this_00 = operator_new(0x18);
        uStack_8 = 0;
        if (this_00 == (CPrintPreviewState *)0x0) {
          uStack_24 = 0;
        }
        else {
          uStack_24 = CPrintPreviewState::CPrintPreviewState(this_00);
        }
        uStack_8 = 0xffffffff;
        *(int32_t *)((int)this + 0x17c) = uStack_24;
        if ((*(int *)((int)this + 0x17c) == 0) || (DAT_100275d0 == 0)) {
          if (*(int *)((int)this + 0x17c) != 0) {
            thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                               *(int32_t *)((int)this + 400));
          }
        }
        else {
          thunk_FUN_100089e8(*(void **)((int)this + 0x17c),*(int **)((int)this + 0x18),
                             *(int32_t *)((int)this + 0x19c));
        }
        (**(code **)(**(int **)((int)this + 0x180) + 0x18))
                  (*(int32_t *)((int)this + 0x17c),0,0,*(int32_t *)((int)this + 0x34),
                   *(int32_t *)((int)this + 0x38),*(int32_t *)((int)this + 0x3c),
                   *(int32_t *)((int)this + 0x40));
      }
      if (DAT_100275d0 != 0) {
        DrawDibBegin(*(int32_t *)((int)this + 8),0,*(int32_t *)((int)this + 0x44),
                     *(int32_t *)((int)this + 0x48),*(int32_t *)((int)this + 0x18),
                     *(int32_t *)((int)this + 0x34),*(int32_t *)((int)this + 0x38),0);
        uval_3 = ftol();
        DrawDibStart(*(int32_t *)((int)this + 8),uval_3);
      }
      SetStretchBltMode(*(HDC *)((int)this + 4),3);
      *(int32_t *)((int)this + 0x10) = 1;
      val_1 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return val_1;
}


