/*
 * Decompiled function: FUN_004b1ed2
 * Entry Point: 004b1ed2
 * Size: 253 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b1ed2(HWND hwnd)

{
  uint local_18;
  tagRECT local_14;
  
  local_18 = (uint)(DAT_00617378 != hwnd);
  GetClientRect(hwnd,&local_14);
  *(LONG *)(&DAT_006169f8 + local_18 * 4) = (local_14.right + -10) - DAT_0061534c;
  *(undefined4 *)(&DAT_00618998 + local_18 * 4) = 10;
  *(undefined4 *)(&DAT_00664bf8 + local_18 * 4) = 10;
  *(LONG *)(&DAT_0060ccb0 + local_18 * 4) = (local_14.bottom + -10) - DAT_0061898c;
  _DAT_00664a58 = 5;
  _DAT_00618ab4 = 10;
  DAT_0060cc7c = 5;
  *(int *)(&DAT_00615460 + local_18 * 4) =
       (*(int *)(&DAT_006169f8 + local_18 * 4) + -10) - DAT_0061534c;
  *(undefined4 *)(&DAT_00617428 + local_18 * 4) = 10;
  *(undefined4 *)(&DAT_00618aa8 + local_18 * 4) = 5;
  *(int *)(&DAT_00664da0 + local_18 * 4) = DAT_0061898c / 2;
  return;
}


