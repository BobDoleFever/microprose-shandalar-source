/*
 * Decompiled function: Duel_GetBattlefieldClientRect
 * Entry Point: 004ef05f
 * Size: 252 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Duel_GetBattlefieldClientRect(HWND hwnd)

{
  uint local_18;
  tagRECT local_14;
  
  local_18 = (uint)(DAT_006a4924 != hwnd);
  GetClientRect(hwnd,&local_14);
  *(LONG *)(&DAT_006a3f68 + local_18 * 4) = (local_14.right + -10) - DAT_006a28b0;
  *(undefined4 *)(&DAT_006b2e80 + local_18 * 4) = 10;
  *(undefined4 *)(&DAT_006ff378 + local_18 * 4) = 10;
  *(LONG *)(&DAT_00695f00 + local_18 * 4) = (local_14.bottom + -10) - DAT_006b2e30;
  _DAT_006ff1a4 = 5;
  _DAT_006b3068 = 10;
  DAT_00695ed4 = 5;
  *(int *)(&DAT_006a29d0 + local_18 * 4) =
       (*(int *)(&DAT_006a3f68 + local_18 * 4) + -10) - DAT_006a28b0;
  *(undefined4 *)(&DAT_006a49d8 + local_18 * 4) = 10;
  *(undefined4 *)(&DAT_006b2ff0 + local_18 * 4) = 5;
  *(int *)(&DAT_007006c0 + local_18 * 4) = DAT_006b2e30 / 2;
  return;
}


