/*
 * Decompiled function: FUN_10005d98
 * Entry Point: 10005d98
 * Size: 1104 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_10005d98(void *this,int arg_2,int *ptr_3)

{
  bool flag_1;
  int32_t uval_2;
  CPrintPreviewState *pCVar3;
  int val_4;
  undefined3 extraout_var;
  int32_t *unaff_FS_OFFSET;
  int *local_164;
  int *local_154;
  char local_14c [256];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int32_t local_28;
  int32_t local_24;
  int local_20;
  int local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100061f7;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if (*(int *)this == 0) {
    uval_2 = 6;
  }
  else {
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    pCVar3 = operator_new(0x18);
    local_8 = 0;
    if (pCVar3 == (CPrintPreviewState *)0x0) {
      local_154 = (int *)0x0;
    }
    else {
      local_154 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar3);
    }
    local_8 = 0xffffffff;
    local_3c = local_154;
    thunk_FUN_10004200(local_154,0);
    thunk_FUN_1000432f(local_14c,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
    val_4 = (**(code **)*local_3c)(0,local_14c,0x18);
    if (val_4 == 0) {
      if (local_3c != (int *)0x0) {
        thunk_FUN_10004250(local_3c,1);
      }
      uval_2 = 4;
    }
    else {
      val_4 = arg_2 * 0x110;
      local_20 = *(int *)(&DAT_1000d6a8 + val_4);
      local_1c = *(int *)(&DAT_1000d6ac + val_4);
      local_18 = *(int32_t *)(&DAT_1000d6b0 + val_4);
      local_14 = *(int32_t *)(&DAT_1000d6b4 + val_4);
      pCVar3 = operator_new(0x18);
      local_8 = 1;
      if (pCVar3 == (CPrintPreviewState *)0x0) {
        local_164 = (int *)0x0;
      }
      else {
        local_164 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar3);
      }
      local_8 = 0xffffffff;
      local_38 = local_164;
      thunk_FUN_10004200(local_164,0);
      thunk_FUN_1000432f(local_14c,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
      val_4 = (**(code **)*local_38)(0,local_14c,0x18);
      if (val_4 == 0) {
        if (local_38 != (int *)0x0) {
          thunk_FUN_10004250(local_38,1);
        }
        if (local_3c != (int *)0x0) {
          thunk_FUN_10004250(local_3c,1);
        }
        uval_2 = 4;
      }
      else {
        local_34 = *(int *)(&DAT_10012a9c + arg_2 * 8);
        local_4c = (*(int *)(*(int *)this + arg_2 * 4) * local_34) / 0x1e;
        local_48 = local_34 - local_4c;
        (**(code **)(*local_38 + 0x18))
                  (local_3c,0,*(int *)(&DAT_10012a98 + arg_2 * 8) + local_4c,local_18,local_48,0,
                   *(int *)(&DAT_10012a98 + arg_2 * 8) + local_4c);
        if (local_38 != (int *)0x0) {
          thunk_FUN_10004250(local_38,1);
        }
        flag_1 = thunk_FUN_10007c74(&local_30,&local_20,ptr_3);
        if (CONCAT31(extraout_var,flag_1) == 0) {
          if (local_3c != (int *)0x0) {
            thunk_FUN_10004250(local_3c,1);
          }
          uval_2 = 7;
        }
        else {
          if (local_20 < local_30) {
            local_40 = local_30 - local_20;
          }
          else {
            local_40 = 0;
          }
          if (local_1c < local_2c) {
            local_44 = local_2c - local_1c;
          }
          else {
            local_44 = 0;
          }
          local_30 = local_30 - *ptr_3;
          local_2c = local_2c - ptr_3[1];
          (**(code **)(*local_3c + 0x18))
                    (*(int32_t *)((int)this + 0x10),local_30,local_2c,local_28,local_24,local_40,
                     local_44);
          if (local_3c != (int *)0x0) {
            thunk_FUN_10004250(local_3c,1);
          }
          uval_2 = 0;
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_2;
}


