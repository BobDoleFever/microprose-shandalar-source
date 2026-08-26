/*
 * Decompiled function: FUN_100059af
 * Entry Point: 100059af
 * Size: 959 bytes
 */
#include "statwin.h"


void __thiscall FUN_100059af(void *this,int arg_2)

{
  CPrintPreviewState *pCVar1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int *local_158;
  int *local_140;
  char local_138 [256];
  int local_38;
  int local_34;
  int32_t local_30;
  int local_2c;
  int32_t local_28;
  int32_t local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10005d7e;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  if (*(int *)this != 0) {
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (*(int *)(arg_2 + local_20 * 4) != 0) {
        pCVar1 = operator_new(0x18);
        local_8 = 0;
        if (pCVar1 == (CPrintPreviewState *)0x0) {
          local_140 = (int *)0x0;
        }
        else {
          local_140 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
        }
        local_8 = 0xffffffff;
        local_1c = local_140;
        thunk_FUN_10004200(local_140,0);
        thunk_FUN_1000432f(local_138,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + local_20 * 0x110);
        val_2 = (**(code **)*local_1c)(0,local_138,0x18);
        if (val_2 == 0) {
          if (local_1c != (int *)0x0) {
            thunk_FUN_10004250(local_1c,1);
          }
          break;
        }
        val_2 = local_20 * 0x110;
        local_30 = *(int32_t *)(&DAT_1000d6a8 + val_2);
        local_2c = *(int *)(&DAT_1000d6ac + val_2);
        local_28 = *(int32_t *)(&DAT_1000d6b0 + val_2);
        local_24 = *(int32_t *)(&DAT_1000d6b4 + val_2);
        (**(code **)(*local_1c + 0x18))
                  (*(int32_t *)((int)this + 0xc),local_30,local_2c,local_28,local_24,0,0);
        if (local_1c != (int *)0x0) {
          thunk_FUN_10004250(local_1c,1);
        }
        pCVar1 = operator_new(0x18);
        local_8 = 1;
        if (pCVar1 == (CPrintPreviewState *)0x0) {
          local_158 = (int *)0x0;
        }
        else {
          local_158 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
        }
        local_8 = 0xffffffff;
        local_18 = local_158;
        thunk_FUN_10004200(local_158,0);
        thunk_FUN_1000432f(local_138,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + local_20 * 0x110);
        val_2 = (**(code **)*local_18)(0,local_138,0x18);
        if (val_2 == 0) {
          if (local_1c != (int *)0x0) {
            thunk_FUN_10004250(local_1c,1);
          }
          break;
        }
        local_14 = *(int *)(&DAT_10012a9c + local_20 * 8);
        local_38 = (*(int *)(*(int *)this + local_20 * 4) * local_14) / 0x1e;
        local_34 = local_14 - local_38;
        val_2 = local_20 * 0x110;
        local_30 = *(int32_t *)(&DAT_1000d158 + val_2);
        local_2c = *(int *)(&DAT_1000d15c + val_2);
        local_28 = *(int32_t *)(&DAT_1000d160 + val_2);
        local_24 = *(int32_t *)(&DAT_1000d164 + val_2);
        (**(code **)(*local_18 + 0x18))
                  (*(int32_t *)((int)this + 0xc),local_30,
                   *(int *)(&DAT_10012a98 + local_20 * 8) + local_2c + local_38,local_28,local_34,0,
                   *(int *)(&DAT_10012a98 + local_20 * 8) + local_38);
        if (local_18 != (int *)0x0) {
          thunk_FUN_10004250(local_18,1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


