/*
 * Decompiled function: FUN_10006212
 * Entry Point: 10006212
 * Size: 724 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_10006212(void *this,int arg_2,int *ptr_3)

{
  bool flag_1;
  int32_t uval_2;
  CPrintPreviewState *this_00;
  int val_3;
  undefined3 extraout_var;
  int32_t *unaff_FS_OFFSET;
  int *local_138;
  char local_12c [256];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100064e5;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if (*(int *)this == 0) {
    uval_2 = 6;
  }
  else {
    local_24 = *(int *)(*(int *)this + 0x14 + arg_2 * 4);
    if (local_24 == 0) {
      uval_2 = 0;
    }
    else {
      local_24 = DeckDll_LoadDeckFile(local_24);
      this_00 = operator_new(0x18);
      local_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        local_138 = (int *)0x0;
      }
      else {
        local_138 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      local_8 = 0xffffffff;
      thunk_FUN_1000432f(local_12c,PTR_s_statwin__10012ac0,s_1skulls_bmp_100122d8 + local_24 * 0x110
                        );
      val_3 = (**(code **)*local_138)(0,local_12c,0x18);
      if (val_3 == 0) {
        if (local_138 != (int *)0x0) {
          thunk_FUN_10004250(local_138,1);
        }
        uval_2 = 4;
      }
      else {
        thunk_FUN_10004200(local_138,0);
        flag_1 = thunk_FUN_10007c74(&local_20,(int *)(&DAT_10012a48 + arg_2 * 0x10),ptr_3);
        if (CONCAT31(extraout_var,flag_1) == 0) {
          if (local_138 != (int *)0x0) {
            thunk_FUN_10004250(local_138,1);
          }
          uval_2 = 7;
        }
        else {
          if (*(int *)(&DAT_10012a48 + arg_2 * 0x10) < local_20) {
            local_28 = local_20 - *(int *)(&DAT_10012a48 + arg_2 * 0x10);
          }
          else {
            local_28 = 0;
          }
          if (*(int *)(&DAT_10012a4c + arg_2 * 0x10) < local_1c) {
            local_2c = local_1c - *(int *)(&DAT_10012a4c + arg_2 * 0x10);
          }
          else {
            local_2c = 0;
          }
          local_20 = local_20 - *ptr_3;
          local_1c = local_1c - ptr_3[1];
          (**(code **)(*local_138 + 0x18))
                    (*(int32_t *)((int)this + 0x10),local_20,local_1c,local_18,local_14,
                     *(int *)(&DAT_10012a48 + arg_2 * 0x10) + local_28,local_2c);
          if (local_138 != (int *)0x0) {
            thunk_FUN_10004250(local_138,1);
          }
          uval_2 = 0;
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_2;
}


