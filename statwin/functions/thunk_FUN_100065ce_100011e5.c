/*
 * Decompiled function: thunk_FUN_100065ce
 * Entry Point: 100011e5
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __fastcall thunk_FUN_100065ce(int *ptr_1)

{
  CPrintPreviewState *this;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int *piStack_14c;
  int *piStack_13c;
  char acStack_138 [256];
  int iStack_38;
  int aiStack_30 [8];
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10006857;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  piStack_13c = (int *)0x0;
  aiStack_30[0] = 0;
  aiStack_30[1] = 0;
  aiStack_30[2] = 0;
  aiStack_30[3] = 0;
  aiStack_30[4] = 0;
  aiStack_30[5] = 0;
  aiStack_30[6] = 0;
  iStack_38 = 0;
  do {
    if (4 < iStack_38) {
      if ((piStack_13c != (int *)0x0) && (piStack_13c != (int *)0x0)) {
        thunk_FUN_10004250(piStack_13c,1);
      }
      uval_2 = 0;
LAB_10006861:
      *unaff_FS_OFFSET = uStack_10;
      return uval_2;
    }
    aiStack_30[7] = DeckDll_LoadDeckFile(*(int32_t *)(*ptr_1 + 0x14 + iStack_38 * 4));
    if (-1 < aiStack_30[7]) {
      if (aiStack_30[aiStack_30[7]] == 0) {
        if ((piStack_13c != (int *)0x0) && (piStack_13c != (int *)0x0)) {
          thunk_FUN_10004250(piStack_13c,1);
        }
        this = operator_new(0x18);
        uStack_8 = 0;
        if (this == (CPrintPreviewState *)0x0) {
          piStack_14c = (int *)0x0;
        }
        else {
          piStack_14c = (int *)CPrintPreviewState::CPrintPreviewState(this);
        }
        uStack_8 = 0xffffffff;
        piStack_13c = piStack_14c;
        thunk_FUN_1000432f(acStack_138,PTR_s_statwin__10012ac0,
                           s_1skulls_bmp_100122d8 + aiStack_30[7] * 0x110);
        val_1 = (**(code **)*piStack_14c)(0,acStack_138,0x18);
        if (val_1 == 0) {
          uval_2 = 4;
          goto LAB_10006861;
        }
        thunk_FUN_10004200(piStack_14c,0);
        memset(aiStack_30,0,0x1c);
        aiStack_30[aiStack_30[7]] = 1;
      }
      (**(code **)(*piStack_13c + 0x18))
                (ptr_1[3],*(int32_t *)(&DAT_10012a48 + iStack_38 * 0x10),
                 *(int32_t *)(&DAT_10012a4c + iStack_38 * 0x10),
                 *(int32_t *)(&DAT_10012a50 + iStack_38 * 0x10),
                 *(int32_t *)(&DAT_10012a54 + iStack_38 * 0x10),
                 *(int32_t *)(&DAT_10012a48 + iStack_38 * 0x10),0);
    }
    iStack_38 = iStack_38 + 1;
  } while( true );
}


