/*
 * Decompiled function: FUN_0041edd4
 * Entry Point: 0041edd4
 * Size: 855 bytes
 */
#include "magic.h"


undefined4 FUN_0041edd4(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_10;
  int local_8;
  
  puVar2 = (undefined4 *)g_DisplaySurfaceScreen;
  puVar3 = &DAT_0067f750;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  for (local_8 = 0; local_8 < 4; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_00519c6c + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f730 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c70 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f740 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c74 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f740 + local_8 * 4);
    *(undefined4 *)(&DAT_00519c78 + local_8 * 0x54) = *(undefined4 *)(&DAT_0067f730 + local_8 * 4);
  }
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    iVar1 = local_8 * 2 + 2;
    *(undefined4 *)(&DAT_00519dbc + local_8 * 0x54) = *(undefined4 *)(&DAT_006782a0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc0 + local_8 * 0x54) = *(undefined4 *)(&DAT_006782d0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc4 + local_8 * 0x54) = *(undefined4 *)(&DAT_006782d0 + iVar1 * 4);
    *(undefined4 *)(&DAT_00519dc8 + local_8 * 0x54) = *(undefined4 *)(&DAT_00678300 + iVar1 * 4);
  }
  if (DAT_00522458 != 0x280) {
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      *(int *)(&DAT_00519c38 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c38 + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519c3c + local_10 * 0x54) =
           (*(int *)(&DAT_00519c3c + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519c40 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c40 + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519c44 + local_10 * 0x54) =
           (*(int *)(&DAT_00519c44 + local_10 * 0x54) * DAT_00522458) / 0x280;
    }
    for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
      *(int *)(&DAT_00519d88 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d88 + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519d8c + local_10 * 0x54) =
           (*(int *)(&DAT_00519d8c + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519d90 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d90 + local_10 * 0x54) * DAT_00522458) / 0x280;
      *(int *)(&DAT_00519d94 + local_10 * 0x54) =
           (*(int *)(&DAT_00519d94 + local_10 * 0x54) * DAT_00522458) / 0x280;
    }
  }
  FUN_0041f17e(0x519c28,4,0);
  FUN_0041f17e(0x519d78,5,0);
  return 1;
}


