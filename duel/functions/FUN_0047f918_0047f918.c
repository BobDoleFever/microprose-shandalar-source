/*
 * Decompiled function: FUN_0047f918
 * Entry Point: 0047f918
 * Size: 757 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x0047fb79) */
/* WARNING: Removing unreachable block (ram,0x0047fbb3) */
/* WARNING: Removing unreachable block (ram,0x0047fb83) */
/* WARNING: Removing unreachable block (ram,0x0047fa7a) */
/* WARNING: Removing unreachable block (ram,0x0047fa97) */
/* WARNING: Removing unreachable block (ram,0x0047fa84) */

undefined4 * FUN_0047f918(undefined4 *arg_1,int *y,int width,int height)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *arg_1_00;
  int iVar4;
  int iVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int *local_28;
  int local_24;
  
  local_38 = 0;
  local_24 = 0;
  if (y == (int *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar5 = (DAT_004f9d08 - (width * 3) % DAT_004f9d08) % DAT_004f9d08;
    if (arg_1 == (undefined4 *)0x0) {
      arg_1 = _malloc((width * 3 + iVar5) * height + 4);
    }
    puVar3 = arg_1;
    iVar4 = y[7];
    iVar1 = y[8];
    if (y[0x6a] == 0) {
      local_40 = Haar_DecompressWaveletImage(y,(void *)0x0);
    }
    else {
      local_40 = y[0x6b];
    }
    iVar2 = y[7];
    arg_1_00 = _malloc(width << 2);
    local_2c = 0;
    local_28 = arg_1_00;
    for (local_34 = 0; local_34 < width; local_34 = local_34 + 1) {
      *local_28 = (local_2c >> 0xf & 0xfffffffeU) + (local_2c >> 0x10);
      local_2c = local_2c + (iVar4 << 0x10) / width;
      local_28 = local_28 + 1;
    }
    for (local_3c = 0; local_3c < height; local_3c = local_3c + 1) {
      iVar4 = iVar2 * 3 * (local_38 >> 0x10) + local_40;
      if (local_24 == iVar4) {
        FID_conflict__memcpy(arg_1,(void *)((int)arg_1 + (width * -3 - iVar5)),width * 3);
        arg_1 = (undefined4 *)((int)arg_1 + width * 3);
      }
      else {
        local_28 = arg_1_00;
        for (local_34 = 0; local_24 = iVar4, local_34 < width; local_34 = local_34 + 1) {
          *arg_1 = *(undefined4 *)(*local_28 + iVar4);
          arg_1 = (undefined4 *)((int)arg_1 + 3);
          local_28 = local_28 + 1;
        }
      }
      local_38 = local_38 + (iVar1 << 0x10) / height;
      arg_1 = (undefined4 *)((int)arg_1 + iVar5);
    }
    FUN_004db150(arg_1_00);
    if (y[0x6a] == 0) {
      FUN_004db150(local_40);
    }
  }
  return puVar3;
}


