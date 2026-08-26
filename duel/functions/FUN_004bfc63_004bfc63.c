/*
 * Decompiled function: FUN_004bfc63
 * Entry Point: 004bfc63
 * Size: 2028 bytes
 */
#include "duel.h"


undefined4 FUN_004bfc63(int x,int y,int width,int height)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_10;
  
  iVar1 = *(int *)(&DAT_006826f4 + y * 0x120 + x * 0x5b20);
  iVar2 = *(int *)(&DAT_006826f4 + height * 0x120 + width * 0x5b20);
  iVar3 = Pic_Subsystem_00451291(x,*(int *)(&DAT_006826c4 + height * 0x120 + width * 0x5b20));
  if (iVar3 == -1) {
    uVar4 = 0;
  }
  else {
    iVar5 = Pic_Subsystem_00451291(width,*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20));
    if (iVar5 == -1) {
      *(undefined4 *)(&DAT_006826c4 + iVar3 * 0x120 + x * 0x5b20) = 0xffffffff;
      uVar4 = 0;
    }
    else {
      FID_conflict__memcpy
                (&DAT_006826c0 + x * 0x5b20 + iVar3 * 0x120,
                 &DAT_006826c0 + width * 0x5b20 + height * 0x120,0x120);
      FID_conflict__memcpy
                (&DAT_006826c0 + width * 0x5b20 + iVar5 * 0x120,
                 &DAT_006826c0 + x * 0x5b20 + y * 0x120,0x120);
      if (*(int *)(&DAT_004ff590 + *(int *)(&DAT_006826c4 + iVar3 * 0x120 + x * 0x5b20) * 0x34) !=
          0xab) {
        *(uint *)(&DAT_006826cc + iVar3 * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826cc + iVar3 * 0x120 + x * 0x5b20) | 0x30000;
      }
      if (*(int *)(&DAT_004ff590 + *(int *)(&DAT_006826c4 + iVar5 * 0x120 + width * 0x5b20) * 0x34)
          != 0xab) {
        *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) =
             *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) | 0x30000;
      }
      *(uint *)(&DAT_006826cc + iVar3 * 0x120 + x * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar3 * 0x120 + x * 0x5b20) & 0xfffffff3;
      *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) & 0xfffffff3;
      *(int *)(&DAT_00690320 + iVar1 * 4) = width;
      *(int *)(&DAT_00681ee0 + iVar1 * 4) = iVar5;
      *(int *)(&DAT_00690320 + iVar2 * 4) = x;
      *(int *)(&DAT_00681ee0 + iVar2 * 4) = iVar3;
      *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) =
           *(uint *)(&DAT_006826cc + iVar5 * 0x120 + width * 0x5b20) | 0x400000;
      for (local_10 = 0; local_10 < 2; local_10 = local_10 + 1) {
        for (local_1c = 0; local_1c < (int)(&DAT_00666408)[local_10]; local_1c = local_1c + 1) {
          if (((char)(&DAT_006826d2)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&DAT_006826e8 + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&DAT_006826d2)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&DAT_006826e8 + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if (((char)(&DAT_006826d3)[local_1c * 0x120 + local_10 * 0x5b20] == x) &&
             (*(int *)(&DAT_006826ec + local_1c * 0x120 + local_10 * 0x5b20) == y)) {
            (&DAT_006826d3)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)width;
            *(int *)(&DAT_006826ec + local_1c * 0x120 + local_10 * 0x5b20) = iVar5;
          }
          if ((&DAT_006827b8)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&DAT_006827b8)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&DAT_00682718 + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) ==
                   x) && (*(int *)(&DAT_0068271c +
                                  local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) == y)) {
                *(int *)(&DAT_00682718 + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) =
                     width;
                *(int *)(&DAT_0068271c + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) =
                     iVar5;
              }
            }
          }
          if (((char)(&DAT_006826d2)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&DAT_006826e8 + local_1c * 0x120 + local_10 * 0x5b20) == height)) {
            (&DAT_006826d2)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&DAT_006826e8 + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if (((char)(&DAT_006826d3)[local_1c * 0x120 + local_10 * 0x5b20] == width) &&
             (*(int *)(&DAT_006826ec + local_1c * 0x120 + local_10 * 0x5b20) == height)) {
            (&DAT_006826d3)[local_1c * 0x120 + local_10 * 0x5b20] = (undefined1)x;
            *(int *)(&DAT_006826ec + local_1c * 0x120 + local_10 * 0x5b20) = iVar3;
          }
          if ((&DAT_006827b8)[local_1c * 0x120 + local_10 * 0x5b20] != '\0') {
            for (local_20 = 0;
                local_20 < (char)(&DAT_006827b8)[local_1c * 0x120 + local_10 * 0x5b20];
                local_20 = local_20 + 1) {
              if ((*(int *)(&DAT_00682718 + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) ==
                   width) &&
                 (*(int *)(&DAT_0068271c + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) ==
                  height)) {
                *(int *)(&DAT_00682718 + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) = x;
                *(int *)(&DAT_0068271c + local_1c * 0x120 + local_10 * 0x5b20 + local_20 * 8) =
                     iVar3;
              }
            }
          }
        }
      }
      *(undefined4 *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) = 0xffffffff;
      *(undefined4 *)(&DAT_006826c4 + height * 0x120 + width * 0x5b20) = 0xffffffff;
      FUN_0048b64f();
      uVar4 = 1;
    }
  }
  return uVar4;
}


