/*
 * Decompiled function: FUN_100065ce
 * Entry Point: 100065ce
 * Size: 648 bytes
 */
#include "statwin.h"


int32_t __fastcall FUN_100065ce(int *ptr_1)

{
  CPrintPreviewState *this;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int *local_14c;
  int *local_13c;
  char local_138 [256];
  int local_38;
  int local_30 [8];
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10006857;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_13c = (int *)0x0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_38 = 0;
  do {
    if (4 < local_38) {
      if ((local_13c != (int *)0x0) && (local_13c != (int *)0x0)) {
        thunk_FUN_10004250(local_13c,1);
      }
      uval_2 = 0;
LAB_10006861:
      *unaff_FS_OFFSET = local_10;
      return uval_2;
    }
    local_30[7] = DeckDll_LoadDeckFile(*(int32_t *)(*ptr_1 + 0x14 + local_38 * 4));
    if (-1 < local_30[7]) {
      if (local_30[local_30[7]] == 0) {
        if ((local_13c != (int *)0x0) && (local_13c != (int *)0x0)) {
          thunk_FUN_10004250(local_13c,1);
        }
        this = operator_new(0x18);
        local_8 = 0;
        if (this == (CPrintPreviewState *)0x0) {
          local_14c = (int *)0x0;
        }
        else {
          local_14c = (int *)CPrintPreviewState::CPrintPreviewState(this);
        }
        local_8 = 0xffffffff;
        local_13c = local_14c;
        thunk_FUN_1000432f(local_138,PTR_s_statwin__10012ac0,
                           s_1skulls_bmp_100122d8 + local_30[7] * 0x110);
        val_1 = (**(code **)*local_14c)(0,local_138,0x18);
        if (val_1 == 0) {
          uval_2 = 4;
          goto LAB_10006861;
        }
        thunk_FUN_10004200(local_14c,0);
        memset(local_30,0,0x1c);
        local_30[local_30[7]] = 1;
      }
      (**(code **)(*local_13c + 0x18))
                (ptr_1[3],*(int32_t *)(&DAT_10012a48 + local_38 * 0x10),
                 *(int32_t *)(&DAT_10012a4c + local_38 * 0x10),
                 *(int32_t *)(&DAT_10012a50 + local_38 * 0x10),
                 *(int32_t *)(&DAT_10012a54 + local_38 * 0x10),
                 *(int32_t *)(&DAT_10012a48 + local_38 * 0x10),0);
    }
    local_38 = local_38 + 1;
  } while( true );
}


