/*
 * Decompiled function: thunk_FUN_1000814f
 * Entry Point: 1000114a
 * Size: 5 bytes
 */
#include "statwin.h"


int32_t __thiscall thunk_FUN_1000814f(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int *piStack_150;
  int *piStack_140;
  char acStack_13c [256];
  int iStack_3c;
  int aiStack_34 [9];
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_100083fe;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  piStack_140 = (int *)0x0;
  aiStack_34[0] = 0;
  aiStack_34[1] = 0;
  aiStack_34[2] = 0;
  aiStack_34[3] = 0;
  aiStack_34[4] = 0;
  aiStack_34[5] = 0;
  aiStack_34[6] = 0;
  iStack_3c = 0;
  do {
    if (4 < iStack_3c) {
      if ((piStack_140 != (int *)0x0) && (piStack_140 != (int *)0x0)) {
        thunk_FUN_10004250(piStack_140,1);
      }
      uval_2 = 0;
LAB_10008408:
      *unaff_FS_OFFSET = uStack_10;
      return uval_2;
    }
    aiStack_34[7] = DeckDll_LoadDeckFile(*(int32_t *)(arg_2 + 0x14 + iStack_3c * 4));
    if (-1 < aiStack_34[7]) {
      if (aiStack_34[aiStack_34[7]] == 0) {
        if ((piStack_140 != (int *)0x0) && (piStack_140 != (int *)0x0)) {
          thunk_FUN_10004250(piStack_140,1);
        }
        this_00 = operator_new(0x18);
        uStack_8 = 0;
        if (this_00 == (CPrintPreviewState *)0x0) {
          piStack_150 = (int *)0x0;
        }
        else {
          piStack_150 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
        }
        uStack_8 = 0xffffffff;
        piStack_140 = piStack_150;
        thunk_FUN_1000432f(acStack_13c,PTR_s_statwin__10012ac0,
                           s_1skulls_bmp_100122d8 + aiStack_34[7] * 0x110);
        val_1 = (**(code **)*piStack_150)(0,acStack_13c,0x18);
        if (val_1 == 0) {
          uval_2 = 4;
          goto LAB_10008408;
        }
        thunk_FUN_10004200(piStack_150,0);
        memset(aiStack_34,0,0x1c);
        aiStack_34[aiStack_34[7]] = 1;
      }
      (**(code **)(*piStack_140 + 0x18))
                (*(int32_t *)((int)this + 0xc),
                 *(int *)(&DAT_10012a48 + iStack_3c * 0x10) + *(int *)((int)this + 0x14),
                 *(int *)(&DAT_10012a4c + iStack_3c * 0x10) + *(int *)((int)this + 0x18),
                 *(int32_t *)(&DAT_10012a50 + iStack_3c * 0x10),
                 *(int32_t *)(&DAT_10012a54 + iStack_3c * 0x10),
                 *(int32_t *)(&DAT_10012a48 + iStack_3c * 0x10),0);
      *(int32_t *)(*(int *)this + 0x14 + iStack_3c * 4) =
           *(int32_t *)(arg_2 + 0x14 + iStack_3c * 4);
    }
    iStack_3c = iStack_3c + 1;
  } while( true );
}


