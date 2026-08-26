/*
 * Decompiled function: FUN_10007805
 * Entry Point: 10007805
 * Size: 780 bytes
 */
#include "statwin.h"


void __fastcall FUN_10007805(int arg_1)

{
  int32_t uval_1;
  int32_t uval_2;
  int val_3;
  CPrintPreviewState *pCVar4;
  int val_5;
  int32_t *unaff_FS_OFFSET;
  int *local_144;
  int *local_134;
  char local_114 [256];
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10007b23;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  for (local_14 = 0; local_14 < 5; local_14 = local_14 + 1) {
    pCVar4 = operator_new(0x18);
    local_8 = 0;
    if (pCVar4 == (CPrintPreviewState *)0x0) {
      local_134 = (int *)0x0;
    }
    else {
      local_134 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar4);
    }
    local_8 = 0xffffffff;
    val_5 = local_14 * 0x110;
    uval_1 = *(int32_t *)(&DAT_1000d6a8 + val_5);
    uval_2 = *(int32_t *)(&DAT_1000d6ac + val_5);
    val_3 = *(int *)(&DAT_1000d6b0 + val_5);
    val_5 = *(int *)(&DAT_1000d6b4 + val_5);
    thunk_FUN_10009e72(local_134,val_3,val_5,0x18);
    (**(code **)(**(int **)(arg_1 + 0xc) + 0x18))(local_134,0,0,val_3,val_5,uval_1,uval_2);
    thunk_FUN_1000432f(local_114,PTR_s_statwin__10012ac0,"S-wmsk.tmp" + local_14 * 0x110);
    (**(code **)(*local_134 + 4))(local_114);
    if (local_134 != (int *)0x0) {
      thunk_FUN_10004250(local_134,1);
    }
    pCVar4 = operator_new(0x18);
    local_8 = 1;
    if (pCVar4 == (CPrintPreviewState *)0x0) {
      local_144 = (int *)0x0;
    }
    else {
      local_144 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar4);
    }
    local_8 = 0xffffffff;
    val_5 = local_14 * 0x110;
    uval_1 = *(int32_t *)(&DAT_1000e698 + val_5);
    uval_2 = *(int32_t *)(&DAT_1000e69c + val_5);
    val_3 = *(int *)(&DAT_1000e6a0 + val_5);
    val_5 = *(int *)(&DAT_1000e6a4 + val_5);
    thunk_FUN_10009e72(local_144,val_3,val_5,0x18);
    (**(code **)(**(int **)(arg_1 + 0xc) + 0x18))(local_144,0,0,val_3,val_5,uval_1,uval_2);
    thunk_FUN_1000432f(local_114,PTR_s_statwin__10012ac0,"W-mmask.tmp" + local_14 * 0x110);
    (**(code **)(*local_144 + 4))(local_114);
    if (local_144 != (int *)0x0) {
      thunk_FUN_10004250(local_144,1);
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


