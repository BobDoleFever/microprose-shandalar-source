/*
 * Decompiled function: FUN_10008085
 * Entry Point: 10008085
 * Size: 693 bytes
 */
#include "deckdll.h"


int FUN_10008085(int arg_1,int arg_2,POINT *arg_3)

{
  BOOL BVar1;
  int val_2;
  int val_3;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int aiStack_d0 [50];
  int local_8;
  
  local_d8 = 0;
  local_8 = 0;
  while ((local_d8 < arg_2 && (local_8 == 0))) {
    BVar1 = PtInRect((RECT *)(local_d8 * 0x10 + arg_1),*arg_3);
    if (BVar1 == 0) {
      val_2 = abs(arg_3->x - *(int *)(local_d8 * 0x10 + 8 + arg_1));
      val_3 = abs(arg_3->x - *(int *)(local_d8 * 0x10 + arg_1));
      if (val_3 < val_2) {
        val_2 = abs(arg_3->x - *(int *)(local_d8 * 0x10 + arg_1));
        aiStack_d0[local_d8 * 2] = val_2;
      }
      else {
        val_2 = abs(arg_3->x - *(int *)(local_d8 * 0x10 + 8 + arg_1));
        aiStack_d0[local_d8 * 2] = val_2;
      }
      val_2 = abs(arg_3->y - *(int *)(local_d8 * 0x10 + 4 + arg_1));
      val_3 = abs(arg_3->y - *(int *)(local_d8 * 0x10 + 0xc + arg_1));
      if (val_2 < val_3) {
        val_2 = abs(arg_3->y - *(int *)(local_d8 * 0x10 + 4 + arg_1));
        aiStack_d0[local_d8 * 2 + 1] = val_2;
      }
      else {
        val_2 = abs(arg_3->y - *(int *)(local_d8 * 0x10 + 0xc + arg_1));
        aiStack_d0[local_d8 * 2 + 1] = val_2;
      }
    }
    else {
      local_d4 = local_d8;
      local_8 = 1;
    }
    local_d8 = local_d8 + 1;
  }
  if (local_8 == 0) {
    local_e0 = 1000;
    for (local_d8 = 0; local_d8 < arg_2; local_d8 = local_d8 + 1) {
      if (aiStack_d0[local_d8 * 2] < local_e0) {
        local_e0 = aiStack_d0[local_d8 * 2];
        local_d4 = local_d8;
        local_dc = aiStack_d0[local_d8 * 2 + 1];
      }
      else if ((aiStack_d0[local_d8 * 2] == local_e0) && (aiStack_d0[local_d8 * 2 + 1] < local_dc))
      {
        local_dc = aiStack_d0[local_d8 * 2 + 1];
        local_d4 = local_d8;
      }
    }
  }
  return local_d4;
}


