/*
 * Decompiled function: thunk_FUN_10007d32
 * Entry Point: 1000121c
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10007d32(void *this,int arg_2)

{
  CPrintPreviewState *pCVar1;
  int val_2;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int *piStack_154;
  int *piStack_13c;
  char acStack_134 [256];
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int32_t uStack_24;
  int32_t uStack_20;
  int *piStack_1c;
  int *piStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100080cc;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  pCVar1 = operator_new(0x18);
  uStack_8 = 0;
  if (pCVar1 == (CPrintPreviewState *)0x0) {
    piStack_13c = (int *)0x0;
  }
  else {
    piStack_13c = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
  }
  uStack_8 = 0xffffffff;
  piStack_1c = piStack_13c;
  thunk_FUN_10004200(piStack_13c,0);
  thunk_FUN_1000432f(acStack_134,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
  val_2 = (**(code **)*piStack_1c)(0,acStack_134,0x18);
  if (val_2 == 0) {
    if (piStack_1c != (int *)0x0) {
      thunk_FUN_10004250(piStack_1c,1);
    }
    uval_3 = 4;
  }
  else {
    val_2 = arg_2 * 0x110;
    iStack_2c = *(int *)(&DAT_1000d6a8 + val_2);
    iStack_28 = *(int *)(&DAT_1000d6ac + val_2);
    uStack_24 = *(int32_t *)(&DAT_1000d6b0 + val_2);
    uStack_20 = *(int32_t *)(&DAT_1000d6b4 + val_2);
    (**(code **)(*piStack_1c + 0x18))
              (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + iStack_2c,
               *(int *)((int)this + 0x18) + iStack_28,uStack_24,uStack_20,0,0);
    if (piStack_1c != (int *)0x0) {
      thunk_FUN_10004250(piStack_1c,1);
    }
    pCVar1 = operator_new(0x18);
    uStack_8 = 1;
    if (pCVar1 == (CPrintPreviewState *)0x0) {
      piStack_154 = (int *)0x0;
    }
    else {
      piStack_154 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
    }
    uStack_8 = 0xffffffff;
    piStack_18 = piStack_154;
    thunk_FUN_10004200(piStack_154,0);
    thunk_FUN_1000432f(acStack_134,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
    val_2 = (**(code **)*piStack_18)(0,acStack_134,0x18);
    if (val_2 == 0) {
      if (piStack_18 != (int *)0x0) {
        thunk_FUN_10004250(piStack_18,1);
      }
      uval_3 = 4;
    }
    else {
      iStack_14 = *(int *)(&DAT_10012a9c + arg_2 * 8);
      iStack_34 = (*(int *)(*(int *)this + arg_2 * 4) * iStack_14) / 0x1e;
      iStack_30 = iStack_14 - iStack_34;
      val_2 = arg_2 * 0x110;
      iStack_2c = *(int *)(&DAT_1000d158 + val_2);
      iStack_28 = *(int *)(&DAT_1000d15c + val_2);
      uStack_24 = *(int32_t *)(&DAT_1000d160 + val_2);
      uStack_20 = *(int32_t *)(&DAT_1000d164 + val_2);
      (**(code **)(*piStack_18 + 0x18))
                (*(int32_t *)((int)this + 0xc),*(int *)((int)this + 0x14) + iStack_2c,
                 *(int *)(&DAT_10012a98 + arg_2 * 8) + *(int *)((int)this + 0x18) + iStack_28 +
                 iStack_34,uStack_24,iStack_30,0,*(int *)(&DAT_10012a98 + arg_2 * 8) + iStack_34);
      if (piStack_18 != (int *)0x0) {
        thunk_FUN_10004250(piStack_18,1);
      }
      uval_3 = 0;
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_3;
}


