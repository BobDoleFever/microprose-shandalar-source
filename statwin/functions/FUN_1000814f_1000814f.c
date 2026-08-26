/*
 * Decompiled function: FUN_1000814f
 * Entry Point: 1000814f
 * Size: 688 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_1000814f(void *this,int arg_2)

{
  CPrintPreviewState *this_00;
  int val_1;
  int32_t uval_2;
  int32_t *unaff_FS_OFFSET;
  int *local_150;
  int *local_140;
  char local_13c [256];
  int local_3c;
  int local_34 [9];
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100083fe;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_140 = (int *)0x0;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = 0;
  local_34[5] = 0;
  local_34[6] = 0;
  local_3c = 0;
  do {
    if (4 < local_3c) {
      if ((local_140 != (int *)0x0) && (local_140 != (int *)0x0)) {
        thunk_FUN_10004250(local_140,1);
      }
      uval_2 = 0;
LAB_10008408:
      *unaff_FS_OFFSET = local_10;
      return uval_2;
    }
    local_34[7] = DeckDll_LoadDeckFile(*(int32_t *)(arg_2 + 0x14 + local_3c * 4));
    if (-1 < local_34[7]) {
      if (local_34[local_34[7]] == 0) {
        if ((local_140 != (int *)0x0) && (local_140 != (int *)0x0)) {
          thunk_FUN_10004250(local_140,1);
        }
        this_00 = operator_new(0x18);
        local_8 = 0;
        if (this_00 == (CPrintPreviewState *)0x0) {
          local_150 = (int *)0x0;
        }
        else {
          local_150 = (int *)CPrintPreviewState::CPrintPreviewState(this_00);
        }
        local_8 = 0xffffffff;
        local_140 = local_150;
        thunk_FUN_1000432f(local_13c,PTR_s_statwin__10012ac0,
                           s_1skulls_bmp_100122d8 + local_34[7] * 0x110);
        val_1 = (**(code **)*local_150)(0,local_13c,0x18);
        if (val_1 == 0) {
          uval_2 = 4;
          goto LAB_10008408;
        }
        thunk_FUN_10004200(local_150,0);
        memset(local_34,0,0x1c);
        local_34[local_34[7]] = 1;
      }
      (**(code **)(*local_140 + 0x18))
                (*(int32_t *)((int)this + 0xc),
                 *(int *)(&DAT_10012a48 + local_3c * 0x10) + *(int *)((int)this + 0x14),
                 *(int *)(&DAT_10012a4c + local_3c * 0x10) + *(int *)((int)this + 0x18),
                 *(int32_t *)(&DAT_10012a50 + local_3c * 0x10),
                 *(int32_t *)(&DAT_10012a54 + local_3c * 0x10),
                 *(int32_t *)(&DAT_10012a48 + local_3c * 0x10),0);
      *(int32_t *)(*(int *)this + 0x14 + local_3c * 4) =
           *(int32_t *)(arg_2 + 0x14 + local_3c * 4);
    }
    local_3c = local_3c + 1;
  } while( true );
}


