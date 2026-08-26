/*
 * Decompiled function: thunk_FUN_10007805
 * Entry Point: 100010af
 * Size: 5 bytes
 */
#include "statwin.h"


void __fastcall thunk_FUN_10007805(int arg_1)

{
  int32_t uval_1;
  int32_t uval_2;
  int val_3;
  CPrintPreviewState *pCVar4;
  int val_5;
  int32_t *unaff_FS_OFFSET;
  int *piStack_144;
  int *piStack_134;
  char acStack_114 [256];
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10007b23;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  for (iStack_14 = 0; iStack_14 < 5; iStack_14 = iStack_14 + 1) {
    pCVar4 = operator_new(0x18);
    uStack_8 = 0;
    if (pCVar4 == (CPrintPreviewState *)0x0) {
      piStack_134 = (int *)0x0;
    }
    else {
      piStack_134 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar4);
    }
    uStack_8 = 0xffffffff;
    val_5 = iStack_14 * 0x110;
    uval_1 = *(int32_t *)(&DAT_1000d6a8 + val_5);
    uval_2 = *(int32_t *)(&DAT_1000d6ac + val_5);
    val_3 = *(int *)(&DAT_1000d6b0 + val_5);
    val_5 = *(int *)(&DAT_1000d6b4 + val_5);
    thunk_FUN_10009e72(piStack_134,val_3,val_5,0x18);
    (**(code **)(**(int **)(arg_1 + 0xc) + 0x18))(piStack_134,0,0,val_3,val_5,uval_1,uval_2);
    thunk_FUN_1000432f(acStack_114,PTR_s_statwin__10012ac0,"S-wmsk.tmp" + iStack_14 * 0x110);
    (**(code **)(*piStack_134 + 4))(acStack_114);
    if (piStack_134 != (int *)0x0) {
      thunk_FUN_10004250(piStack_134,1);
    }
    pCVar4 = operator_new(0x18);
    uStack_8 = 1;
    if (pCVar4 == (CPrintPreviewState *)0x0) {
      piStack_144 = (int *)0x0;
    }
    else {
      piStack_144 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar4);
    }
    uStack_8 = 0xffffffff;
    val_5 = iStack_14 * 0x110;
    uval_1 = *(int32_t *)(&DAT_1000e698 + val_5);
    uval_2 = *(int32_t *)(&DAT_1000e69c + val_5);
    val_3 = *(int *)(&DAT_1000e6a0 + val_5);
    val_5 = *(int *)(&DAT_1000e6a4 + val_5);
    thunk_FUN_10009e72(piStack_144,val_3,val_5,0x18);
    (**(code **)(**(int **)(arg_1 + 0xc) + 0x18))(piStack_144,0,0,val_3,val_5,uval_1,uval_2);
    thunk_FUN_1000432f(acStack_114,PTR_s_statwin__10012ac0,"W-mmask.tmp" + iStack_14 * 0x110);
    (**(code **)(*piStack_144 + 4))(acStack_114);
    if (piStack_144 != (int *)0x0) {
      thunk_FUN_10004250(piStack_144,1);
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}


