/*
 * Decompiled function: thunk_FUN_1000310f
 * Entry Point: 1000113b
 * Size: 5 bytes
 */
#include "statwin.h"


void thunk_FUN_1000310f(int arg_1)

{
  int val_1;
  int32_t *unaff_FS_OFFSET;
  char acStack_134 [256];
  short sStack_34;
  short sStack_32;
  int iStack_30;
  int32_t uStack_2c;
  CPrintPreviewState aCStack_28 [24];
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100032ea;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_28);
  uStack_8 = 0;
  thunk_FUN_1000432f(acStack_134,PTR_s_statwin__10012ac0,(&PTR_s_room_wht_bmp_10011588)[arg_1]);
  iStack_30 = thunk_FUN_10003303((CFontDialog *)aCStack_28,acStack_134);
  if (iStack_30 != 0) {
    uStack_8 = 0xffffffff;
    FUN_100032e1();
    FUN_100032f4();
    return;
  }
  thunk_FUN_1000432f(acStack_134,PTR_s___statwin__10011540,(&PTR_s_bubbles_avi_10011570)[arg_1]);
  val_1 = thunk_FUN_100097b0(acStack_134,&uStack_2c,&sStack_34,1);
  if (val_1 == 0) {
    thunk_FUN_100099ff(aCStack_28,uStack_2c);
    thunk_FUN_10009a89(uStack_2c,0);
    sStack_34 = (short)*(int32_t *)(&DAT_10011728 + arg_1 * 0x10) +
                (short)*(int32_t *)(DAT_100117a4 + 0x14);
    sStack_32 = (short)*(int32_t *)(&DAT_1001172c + arg_1 * 0x10) +
                (short)*(int32_t *)(DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(uStack_2c,&sStack_34);
    thunk_FUN_10009ace(uStack_2c);
    thunk_FUN_10009824(uStack_2c);
    while (val_1 = thunk_FUN_10009b0f(uStack_2c), val_1 != 0) {
      thunk_FUN_100023fd();
      Sleep(500);
    }
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    thunk_FUN_100097f0(uStack_2c);
    uStack_8 = 0xffffffff;
    FUN_100032e1();
    FUN_100032f4();
    return;
  }
  uStack_8 = 0xffffffff;
  FUN_100032e1();
  FUN_100032f4();
  return;
}


