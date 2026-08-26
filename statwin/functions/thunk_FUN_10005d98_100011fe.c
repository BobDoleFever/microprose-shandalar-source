/*
 * Decompiled function: thunk_FUN_10005d98
 * Entry Point: 100011fe
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_10005d98(void *this,int arg_2,int *ptr_3)

{
  bool flag_1;
  int32_t uval_2;
  CPrintPreviewState *pCVar3;
  int val_4;
  undefined3 extraout_var;
  int32_t *unaff_FS_OFFSET;
  int *piStack_164;
  int *piStack_154;
  char acStack_14c [256];
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int *piStack_3c;
  int *piStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int32_t uStack_28;
  int32_t uStack_24;
  int iStack_20;
  int iStack_1c;
  int32_t uStack_18;
  int32_t uStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100061f7;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (*(int *)this == 0) {
    uval_2 = 6;
  }
  else {
    iStack_20 = 0;
    iStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    pCVar3 = operator_new(0x18);
    uStack_8 = 0;
    if (pCVar3 == (CPrintPreviewState *)0x0) {
      piStack_154 = (int *)0x0;
    }
    else {
      piStack_154 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar3);
    }
    uStack_8 = 0xffffffff;
    piStack_3c = piStack_154;
    thunk_FUN_10004200(piStack_154,0);
    thunk_FUN_1000432f(acStack_14c,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + arg_2 * 0x110);
    val_4 = (**(code **)*piStack_3c)(0,acStack_14c,0x18);
    if (val_4 == 0) {
      if (piStack_3c != (int *)0x0) {
        thunk_FUN_10004250(piStack_3c,1);
      }
      uval_2 = 4;
    }
    else {
      val_4 = arg_2 * 0x110;
      iStack_20 = *(int *)(&DAT_1000d6a8 + val_4);
      iStack_1c = *(int *)(&DAT_1000d6ac + val_4);
      uStack_18 = *(int32_t *)(&DAT_1000d6b0 + val_4);
      uStack_14 = *(int32_t *)(&DAT_1000d6b4 + val_4);
      pCVar3 = operator_new(0x18);
      uStack_8 = 1;
      if (pCVar3 == (CPrintPreviewState *)0x0) {
        piStack_164 = (int *)0x0;
      }
      else {
        piStack_164 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar3);
      }
      uStack_8 = 0xffffffff;
      piStack_38 = piStack_164;
      thunk_FUN_10004200(piStack_164,0);
      thunk_FUN_1000432f(acStack_14c,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + arg_2 * 0x110);
      val_4 = (**(code **)*piStack_38)(0,acStack_14c,0x18);
      if (val_4 == 0) {
        if (piStack_38 != (int *)0x0) {
          thunk_FUN_10004250(piStack_38,1);
        }
        if (piStack_3c != (int *)0x0) {
          thunk_FUN_10004250(piStack_3c,1);
        }
        uval_2 = 4;
      }
      else {
        iStack_34 = *(int *)(&DAT_10012a9c + arg_2 * 8);
        iStack_4c = (*(int *)(*(int *)this + arg_2 * 4) * iStack_34) / 0x1e;
        iStack_48 = iStack_34 - iStack_4c;
        (**(code **)(*piStack_38 + 0x18))
                  (piStack_3c,0,*(int *)(&DAT_10012a98 + arg_2 * 8) + iStack_4c,uStack_18,iStack_48,
                   0,*(int *)(&DAT_10012a98 + arg_2 * 8) + iStack_4c);
        if (piStack_38 != (int *)0x0) {
          thunk_FUN_10004250(piStack_38,1);
        }
        flag_1 = thunk_FUN_10007c74(&iStack_30,&iStack_20,ptr_3);
        if (CONCAT31(extraout_var,flag_1) == 0) {
          if (piStack_3c != (int *)0x0) {
            thunk_FUN_10004250(piStack_3c,1);
          }
          uval_2 = 7;
        }
        else {
          if (iStack_20 < iStack_30) {
            iStack_40 = iStack_30 - iStack_20;
          }
          else {
            iStack_40 = 0;
          }
          if (iStack_1c < iStack_2c) {
            iStack_44 = iStack_2c - iStack_1c;
          }
          else {
            iStack_44 = 0;
          }
          iStack_30 = iStack_30 - *ptr_3;
          iStack_2c = iStack_2c - ptr_3[1];
          (**(code **)(*piStack_3c + 0x18))
                    (*(int32_t *)((int)this + 0x10),iStack_30,iStack_2c,uStack_28,uStack_24,
                     iStack_40,iStack_44);
          if (piStack_3c != (int *)0x0) {
            thunk_FUN_10004250(piStack_3c,1);
          }
          uval_2 = 0;
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_2;
}


