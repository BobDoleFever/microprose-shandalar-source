/*
 * Decompiled function: thunk_FUN_10007083
 * Entry Point: 10001023
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10007083(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int32_t uval_1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int *piStack_124;
  char acStack_11c [256];
  int *piStack_1c;
  int iStack_18;
  uint32_t uStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10007342;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  this_00 = operator_new(0x18);
  uStack_8 = 0;
  if (this_00 == (CPrintPreviewState *)0x0) {
    piStack_124 = (int *)0x0;
  }
  else {
    piStack_124 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
  }
  uStack_8 = 0xffffffff;
  piStack_1c = piStack_124;
  uStack_14 = (uint32_t)*(uint8_t *)(*(int *)this + 0x28 + arg_2);
  if (uStack_14 == 0) {
    if (piStack_124 != (int *)0x0) {
      thunk_FUN_10004250(piStack_124,1);
    }
    uval_1 = 7;
  }
  else {
    thunk_FUN_1000432f(acStack_11c,PTR_s_statwin__10012ac0,"W-mana.bmp" + arg_2 * 0x110);
    val_2 = (**(code **)*piStack_1c)(0,acStack_11c,0x18);
    if (val_2 == 0) {
      if (piStack_1c != (int *)0x0) {
        thunk_FUN_10004250(piStack_1c,1);
      }
      uval_1 = 6;
    }
    else {
      iStack_18 = 0;
      for (uStack_14 = uStack_14 & 0x1f; (iStack_18 < 5 && (0 < (int)uStack_14));
          uStack_14 = uStack_14 - 1) {
        (**(code **)(*piStack_1c + 0x18))
                  (*(int32_t *)((int)this + 0xc),
                   *(int *)(&DAT_1000eae8 + arg_2 * 0x50 + iStack_18 * 0x10) +
                   *(int *)(&DAT_1000e148 + arg_2 * 0x110) + *(int *)((int)this + 0x14),
                   *(int *)(&DAT_1000eaec + arg_2 * 0x50 + iStack_18 * 0x10) +
                   *(int *)(&DAT_1000e14c + arg_2 * 0x110) + *(int *)((int)this + 0x18),
                   *(int32_t *)(&DAT_1000eaf0 + arg_2 * 0x50 + iStack_18 * 0x10),
                   *(int32_t *)(&DAT_1000eaf4 + arg_2 * 0x50 + iStack_18 * 0x10),
                   *(int32_t *)(&DAT_1000eae8 + arg_2 * 0x50 + iStack_18 * 0x10),
                   *(int32_t *)(&DAT_1000eaec + arg_2 * 0x50 + iStack_18 * 0x10));
        iStack_18 = iStack_18 + 1;
      }
      if (piStack_1c != (int *)0x0) {
        thunk_FUN_10004250(piStack_1c,1);
      }
      uval_1 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}


