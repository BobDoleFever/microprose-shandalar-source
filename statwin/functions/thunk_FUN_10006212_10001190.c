/*
 * Decompiled function: thunk_FUN_10006212
 * Entry Point: 10001190
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10006212(void *this,int arg_2,int *ptr_3)

{
  bool flag_1;
  int32_t uval_2;
  CPrintPreviewState *this_00;
  int val_3;
  undefined3 extraout_var;
  int32_t *unaff_FS_OFFSET;
  int *piStack_138;
  char acStack_12c [256];
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int32_t uStack_18;
  int32_t uStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100064e5;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (*(int *)this == 0) {
    uval_2 = 6;
  }
  else {
    iStack_24 = *(int *)(*(int *)this + 0x14 + arg_2 * 4);
    if (iStack_24 == 0) {
      uval_2 = 0;
    }
    else {
      iStack_24 = DeckDll_LoadDeckFile(iStack_24);
      this_00 = operator_new(0x18);
      uStack_8 = 0;
      if (this_00 == (CPrintPreviewState *)0x0) {
        piStack_138 = (int *)0x0;
      }
      else {
        piStack_138 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
      }
      uStack_8 = 0xffffffff;
      thunk_FUN_1000432f(acStack_12c,PTR_s_statwin__10012ac0,
                         s_1skulls_bmp_100122d8 + iStack_24 * 0x110);
      val_3 = (**(code **)*piStack_138)(0,acStack_12c,0x18);
      if (val_3 == 0) {
        if (piStack_138 != (int *)0x0) {
          thunk_FUN_10004250(piStack_138,1);
        }
        uval_2 = 4;
      }
      else {
        thunk_FUN_10004200(piStack_138,0);
        flag_1 = thunk_FUN_10007c74(&iStack_20,(int *)(&DAT_10012a48 + arg_2 * 0x10),ptr_3);
        if (CONCAT31(extraout_var,flag_1) == 0) {
          if (piStack_138 != (int *)0x0) {
            thunk_FUN_10004250(piStack_138,1);
          }
          uval_2 = 7;
        }
        else {
          if (*(int *)(&DAT_10012a48 + arg_2 * 0x10) < iStack_20) {
            iStack_28 = iStack_20 - *(int *)(&DAT_10012a48 + arg_2 * 0x10);
          }
          else {
            iStack_28 = 0;
          }
          if (*(int *)(&DAT_10012a4c + arg_2 * 0x10) < iStack_1c) {
            iStack_2c = iStack_1c - *(int *)(&DAT_10012a4c + arg_2 * 0x10);
          }
          else {
            iStack_2c = 0;
          }
          iStack_20 = iStack_20 - *ptr_3;
          iStack_1c = iStack_1c - ptr_3[1];
          (**(code **)(*piStack_138 + 0x18))
                    (*(int32_t *)((int)this + 0x10),iStack_20,iStack_1c,uStack_18,uStack_14,
                     *(int *)(&DAT_10012a48 + arg_2 * 0x10) + iStack_28,iStack_2c);
          if (piStack_138 != (int *)0x0) {
            thunk_FUN_10004250(piStack_138,1);
          }
          uval_2 = 0;
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_2;
}


