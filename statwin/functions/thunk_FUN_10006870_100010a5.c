/*
 * Decompiled function: thunk_FUN_10006870
 * Entry Point: 100010a5
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_10006870(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t *unaff_FS_OFFSET;
  int *piStack_128;
  char acStack_120 [256];
  int *piStack_20;
  int iStack_1c;
  int iStack_18;
  uint8_t bStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10006b25;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  for (iStack_18 = 0; iStack_18 < 5; iStack_18 = iStack_18 + 1) {
    if (*(int *)(arg_2 + iStack_18 * 4) != 0) {
      this_00 = operator_new(0x18);
      uStack_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        piStack_128 = (int *)0x0;
      }
      else {
        piStack_128 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      uStack_8 = 0xffffffff;
      piStack_20 = piStack_128;
      bStack_14 = *(uint8_t *)(*(int *)this + 0x28 + iStack_18);
      if (bStack_14 == 0) {
        if (piStack_128 != (int *)0x0) {
          thunk_FUN_10004250(piStack_128,1);
        }
      }
      else {
        thunk_FUN_1000432f(acStack_120,PTR_s_statwin__10012ac0,"W-mana.bmp" + iStack_18 * 0x110);
        val_1 = (**(code **)*piStack_20)(0,acStack_120,0x18);
        if (val_1 == 0) break;
        iStack_1c = 0;
        for (bStack_14 = bStack_14 & 0x1f; (iStack_1c < 5 && (bStack_14 != 0));
            bStack_14 = bStack_14 - 1) {
          if (bStack_14 != 0) {
            (**(code **)(*piStack_20 + 0x18))
                      (*(int32_t *)((int)this + 0xc),
                       *(int *)(&DAT_1000eae8 + iStack_1c * 0x10 + iStack_18 * 0x50) +
                       *(int *)(&DAT_1000e148 + iStack_18 * 0x110),
                       *(int *)(&DAT_1000eaec + iStack_1c * 0x10 + iStack_18 * 0x50) +
                       *(int *)(&DAT_1000e14c + iStack_18 * 0x110),
                       *(int32_t *)(&DAT_1000eaf0 + iStack_1c * 0x10 + iStack_18 * 0x50),
                       *(int32_t *)(&DAT_1000eaf4 + iStack_1c * 0x10 + iStack_18 * 0x50),
                       *(int32_t *)(&DAT_1000eae8 + iStack_1c * 0x10 + iStack_18 * 0x50),
                       *(int32_t *)(&DAT_1000eaec + iStack_1c * 0x10 + iStack_18 * 0x50));
          }
          iStack_1c = iStack_1c + 1;
        }
        if (piStack_20 != (int *)0x0) {
          thunk_FUN_10004250(piStack_20,1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}


