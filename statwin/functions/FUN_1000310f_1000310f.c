/*
 * Decompiled function: FUN_1000310f
 * Entry Point: 1000310f
 * Size: 466 bytes
 */
#include "statwin.h"


void FUN_1000310f(int arg_1)

{
  int val_1;
  int32_t *unaff_FS_OFFSET;
  char local_134 [256];
  short local_34;
  short local_32;
  int local_30;
  int32_t local_2c;
  CPrintPreviewState local_28 [24];
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100032ea;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(local_28);
  local_8 = 0;
  thunk_FUN_1000432f(local_134,PTR_s_statwin__10012ac0,(&PTR_s_room_wht_bmp_10011588)[arg_1]);
  local_30 = thunk_FUN_10003303((CFontDialog *)local_28,local_134);
  if (local_30 != 0) {
    local_8 = 0xffffffff;
    FUN_100032e1();
    FUN_100032f4();
    return;
  }
  thunk_FUN_1000432f(local_134,PTR_s___statwin__10011540,(&PTR_s_bubbles_avi_10011570)[arg_1]);
  val_1 = thunk_FUN_100097b0(local_134,&local_2c,&local_34,1);
  if (val_1 == 0) {
    thunk_FUN_100099ff(local_28,local_2c);
    thunk_FUN_10009a89(local_2c,0);
    local_34 = (short)*(int32_t *)(&DAT_10011728 + arg_1 * 0x10) +
               (short)*(int32_t *)(DAT_100117a4 + 0x14);
    local_32 = (short)*(int32_t *)(&DAT_1001172c + arg_1 * 0x10) +
               (short)*(int32_t *)(DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(local_2c,&local_34);
    thunk_FUN_10009ace(local_2c);
    thunk_FUN_10009824(local_2c);
    while (val_1 = thunk_FUN_10009b0f(local_2c), val_1 != 0) {
      thunk_FUN_100023fd();
      Sleep(500);
    }
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    thunk_FUN_100097f0(local_2c);
    local_8 = 0xffffffff;
    FUN_100032e1();
    FUN_100032f4();
    return;
  }
  local_8 = 0xffffffff;
  FUN_100032e1();
  FUN_100032f4();
  return;
}


