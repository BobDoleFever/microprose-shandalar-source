/*
 * Decompiled function: FUN_0048cc29
 * Entry Point: 0048cc29
 * Size: 945 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048cc29(void)

{
  byte arg_1;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int local_c;
  
  for (local_10 = 0; local_10 < 8; local_10 = local_10 + 1) {
    *(undefined4 *)(&DAT_0068f340 + local_10 * 4) = 0;
    *(undefined4 *)(&DAT_0068f320 + local_10 * 4) = *(undefined4 *)(&DAT_0068f340 + local_10 * 4);
    *(undefined4 *)(&DAT_0068ee40 + local_10 * 4) = *(undefined4 *)(&DAT_0068f320 + local_10 * 4);
    *(undefined4 *)(&DAT_0068ee20 + local_10 * 4) = *(undefined4 *)(&DAT_0068ee40 + local_10 * 4);
    *(undefined4 *)(&DAT_0068ee00 + local_10 * 4) = *(undefined4 *)(&DAT_0068ee20 + local_10 * 4);
    *(undefined4 *)(&DAT_0068ede0 + local_10 * 4) = *(undefined4 *)(&DAT_0068ee00 + local_10 * 4);
  }
  DAT_0066aad4 = 0;
  _DAT_0066aad0 = 0;
  DAT_006664f4 = 0;
  _DAT_006664f0 = 0;
  DAT_00681ebc = 0;
  _DAT_00681eb8 = 0;
  for (local_10 = 0; local_10 < 0x18; local_10 = local_10 + 1) {
    *(undefined4 *)(&DAT_0068ee70 + local_10 * 4) = 0;
  }
  _DAT_0068ee70 = DAT_00681ea8;
  DAT_0068ee74 = DAT_00681eac;
  for (local_c = 0; local_c < 2; local_c = local_c + 1) {
    (&DAT_0068ee78)[local_c] = 0;
    for (local_10 = 0; local_10 < (int)(&DAT_00666408)[local_c]; local_10 = local_10 + 1) {
      iVar1 = FUN_0048a33f(local_c,local_10);
      if (iVar1 == 0) {
        if (*(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_10 * 0x120) != -1) {
          (&DAT_0068ee78)[local_c] = (&DAT_0068ee78)[local_c] + 1;
        }
      }
      else {
        iVar1 = *(int *)(&DAT_006826c4 + local_c * 0x5b20 + local_10 * 0x120);
        arg_1 = (&DAT_004ff596)[iVar1 * 0x34];
        if (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0) {
          iVar2 = FUN_0048b81a(local_c,local_10,0x32,0xffffffff);
          iVar3 = FUN_0048b81a(local_c,local_10,0x33,0xffffffff);
          iVar4 = FUN_0048c367(arg_1);
          *(int *)(&DAT_0068ede0 + iVar4 * 4 + local_c * 0x20) =
               *(int *)(&DAT_0068ede0 + iVar4 * 4 + local_c * 0x20) + iVar2;
          *(int *)(&DAT_0068edfc + local_c * 0x20) =
               *(int *)(&DAT_0068edfc + local_c * 0x20) + iVar2;
          iVar2 = FUN_0048c367(arg_1);
          *(int *)(&DAT_0068ee20 + iVar2 * 4 + local_c * 0x20) =
               *(int *)(&DAT_0068ee20 + iVar2 * 4 + local_c * 0x20) + iVar3;
          *(int *)(&DAT_0068ee3c + local_c * 0x20) =
               *(int *)(&DAT_0068ee3c + local_c * 0x20) + iVar3;
          *(int *)(&DAT_00681eb8 + local_c * 4) = *(int *)(&DAT_00681eb8 + local_c * 4) + 1;
        }
        *(uint *)(&DAT_0066aad0 + local_c * 4) =
             *(uint *)(&DAT_0066aad0 + local_c * 4) | (uint)(byte)(&DAT_004ff594)[iVar1 * 0x34];
        if (((&DAT_004ff594)[iVar1 * 0x34] & 2) != 0) {
          *(int *)(&DAT_0068ee80 + local_c * 4) = *(int *)(&DAT_0068ee80 + local_c * 4) + 1;
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 0x40) != 0) {
          (&DAT_0068ee88)[local_c] = (&DAT_0068ee88)[local_c] + 1;
        }
        if (((&DAT_004ff594)[iVar1 * 0x34] & 4) != 0) {
          *(int *)(&DAT_0068ee90 + local_c * 4) = *(int *)(&DAT_0068ee90 + local_c * 4) + 1;
        }
      }
    }
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      if (*(int *)(&DAT_0068f370 + local_10 * 4 + local_c * 2000) != -1) {
        *(uint *)(&DAT_006664f0 + local_c * 4) =
             *(uint *)(&DAT_006664f0 + local_c * 4) |
             (uint)(byte)(&DAT_004ff594)
                         [*(int *)(&DAT_0068f370 + local_10 * 4 + local_c * 2000) * 0x34];
      }
    }
  }
  return;
}


