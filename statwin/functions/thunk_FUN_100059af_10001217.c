/*
 * Decompiled function: thunk_FUN_100059af
 * Entry Point: 10001217
 * Size: 5 bytes
 */
#include "statwin.h"


void __thiscall thunk_FUN_100059af(void *this,int arg_2)

{
  CPrintPreviewState *pCVar1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int *piStack_158;
  int *piStack_140;
  char acStack_138 [256];
  int iStack_38;
  int iStack_34;
  int32_t uStack_30;
  int iStack_2c;
  int32_t uStack_28;
  int32_t uStack_24;
  int iStack_20;
  int *piStack_1c;
  int *piStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10005d7e;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  if (*(int *)this != 0) {
    uStack_30 = 0;
    iStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    for (iStack_20 = 0; iStack_20 < 5; iStack_20 = iStack_20 + 1) {
      if (*(int *)(arg_2 + iStack_20 * 4) != 0) {
        pCVar1 = operator_new(0x18);
        uStack_8 = 0;
        if (pCVar1 == (CPrintPreviewState *)0x0) {
          piStack_140 = (int *)0x0;
        }
        else {
          piStack_140 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
        }
        uStack_8 = 0xffffffff;
        piStack_1c = piStack_140;
        thunk_FUN_10004200(piStack_140,0);
        thunk_FUN_1000432f(acStack_138,PTR_s_statwin__10012ac0,"S-wwizy.bmp" + iStack_20 * 0x110);
        val_2 = (**(code **)*piStack_1c)(0,acStack_138,0x18);
        if (val_2 == 0) {
          if (piStack_1c != (int *)0x0) {
            thunk_FUN_10004250(piStack_1c,1);
          }
          break;
        }
        val_2 = iStack_20 * 0x110;
        uStack_30 = *(int32_t *)(&DAT_1000d6a8 + val_2);
        iStack_2c = *(int *)(&DAT_1000d6ac + val_2);
        uStack_28 = *(int32_t *)(&DAT_1000d6b0 + val_2);
        uStack_24 = *(int32_t *)(&DAT_1000d6b4 + val_2);
        (**(code **)(*piStack_1c + 0x18))
                  (*(int32_t *)((int)this + 0xc),uStack_30,iStack_2c,uStack_28,uStack_24,0,0);
        if (piStack_1c != (int *)0x0) {
          thunk_FUN_10004250(piStack_1c,1);
        }
        pCVar1 = operator_new(0x18);
        uStack_8 = 1;
        if (pCVar1 == (CPrintPreviewState *)0x0) {
          piStack_158 = (int *)0x0;
        }
        else {
          piStack_158 = (int *)CPrintPreviewState::CPrintPreviewState(pCVar1);
        }
        uStack_8 = 0xffffffff;
        piStack_18 = piStack_158;
        thunk_FUN_10004200(piStack_158,0);
        thunk_FUN_1000432f(acStack_138,PTR_s_statwin__10012ac0,"S-wwizr.bmp" + iStack_20 * 0x110);
        val_2 = (**(code **)*piStack_18)(0,acStack_138,0x18);
        if (val_2 == 0) {
          if (piStack_1c != (int *)0x0) {
            thunk_FUN_10004250(piStack_1c,1);
          }
          break;
        }
        iStack_14 = *(int *)(&DAT_10012a9c + iStack_20 * 8);
        iStack_38 = (*(int *)(*(int *)this + iStack_20 * 4) * iStack_14) / 0x1e;
        iStack_34 = iStack_14 - iStack_38;
        val_2 = iStack_20 * 0x110;
        uStack_30 = *(int32_t *)(&DAT_1000d158 + val_2);
        iStack_2c = *(int *)(&DAT_1000d15c + val_2);
        uStack_28 = *(int32_t *)(&DAT_1000d160 + val_2);
        uStack_24 = *(int32_t *)(&DAT_1000d164 + val_2);
        (**(code **)(*piStack_18 + 0x18))
                  (*(int32_t *)((int)this + 0xc),uStack_30,
                   *(int *)(&DAT_10012a98 + iStack_20 * 8) + iStack_2c + iStack_38,uStack_28,
                   iStack_34,0,*(int *)(&DAT_10012a98 + iStack_20 * 8) + iStack_38);
        if (piStack_18 != (int *)0x0) {
          thunk_FUN_10004250(piStack_18,1);
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}


