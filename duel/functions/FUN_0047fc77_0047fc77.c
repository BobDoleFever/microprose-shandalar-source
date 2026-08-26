/*
 * Decompiled function: FUN_0047fc77
 * Entry Point: 0047fc77
 * Size: 1831 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x00480068) */
/* WARNING: Removing unreachable block (ram,0x0047fe45) */

uint * FUN_0047fc77(uint *x,int *y,int width,int height)

{
  int iVar1;
  int iVar2;
  uint *local_5054;
  uint local_5050 [4096];
  int local_1050;
  int local_104c;
  int local_1048;
  int local_1044;
  uint local_1040;
  int local_103c;
  uint *local_1038;
  int local_1034;
  uint *local_1030;
  undefined4 local_102c;
  uint *local_1028;
  int local_1024;
  int local_1020;
  size_t local_101c;
  int local_1018;
  undefined4 local_1014;
  byte *local_1010;
  uint local_100c [1016];
  undefined4 uStackY_2c;
  
  Mem_AllocOrFree_004ddee0();
  local_1034 = 0;
  local_1048 = 0;
  local_102c = 0;
  local_1030 = local_5050;
  local_1038 = local_100c;
  local_1040 = (uint)(x != (uint *)0x0);
  if (y == (int *)0x0) {
    local_5054 = (uint *)0x0;
  }
  else {
    local_1018 = y[7] << 0x10;
    local_1024 = y[8] << 0x10;
    iVar1 = local_1018 / width;
    iVar2 = local_1024 / height;
    if (y[0x6a] == 0) {
      local_1050 = Haar_DecompressWaveletImage(y,&DAT_00523980);
    }
    else {
      local_1050 = y[0x6b];
    }
    local_103c = y[7];
    local_1014 = 0;
    local_1020 = (DAT_004f9d08 - (width * 3) % DAT_004f9d08) % DAT_004f9d08;
    if (x == (uint *)0x0) {
      local_5054 = (uint *)&DAT_0059e180;
    }
    else {
      local_5054 = x;
    }
    local_1034 = 0;
    for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
      *local_1030 = local_1034 >> 8;
      local_1034 = local_1034 + iVar1;
      local_1030 = local_1030 + 1;
    }
    x = local_5054;
    if (y[8] < height) {
      x = (uint *)((int)local_5054 + (height - y[8]) * (width * 3 + local_1020));
    }
    local_1028 = x;
    for (local_104c = 0; local_104c < y[8]; local_104c = local_104c + 1) {
      local_1030 = local_5050;
      for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
        local_1010 = (byte *)(((int)*local_1030 >> 8) * 3 + local_103c * 3 * local_104c + local_1050
                             );
        *(byte *)x = (char)(((uint)local_1010[3] - (uint)*local_1010) * (*local_1030 & 0xff) >> 8) +
                     *local_1010;
        *(byte *)((int)x + 1) =
             (char)(((uint)local_1010[4] - (uint)local_1010[1]) * (*local_1030 & 0xff) >> 8) +
             local_1010[1];
        *(byte *)((int)x + 2) =
             (char)(((uint)local_1010[5] - (uint)local_1010[2]) * (*local_1030 & 0xff) >> 8) +
             local_1010[2];
        x = (uint *)((int)x + 3);
        local_1030 = local_1030 + 1;
      }
      x = (uint *)((int)x + local_1020);
    }
    local_1048 = 0;
    for (local_1044 = 0; local_1044 < height; local_1044 = local_1044 + 1) {
      *local_1038 = local_1048 >> 8;
      local_1048 = local_1048 + iVar2;
      local_1038 = local_1038 + 1;
    }
    local_101c = width * 3 + local_1020;
    if (height < y[8]) {
      FID_conflict__memcpy
                (local_5050,(uint *)((y[8] + -1) * local_101c + (int)local_5054),local_101c);
    }
    for (local_1044 = 0; local_1044 < width; local_1044 = local_1044 + 1) {
      x = (uint *)(local_1044 * 3 + (int)local_5054);
      local_1038 = local_100c;
      for (local_104c = 0; local_104c < height + -1; local_104c = local_104c + 1) {
        iVar1 = y[8] + -2;
        if ((int)*local_1038 >> 8 <= y[8] + -2) {
          iVar1 = (int)*local_1038 >> 8;
        }
        local_1010 = (byte *)((int)local_1028 + iVar1 * local_101c + local_1044 * 3);
        *(byte *)x = (char)(((uint)local_1010[local_101c] - (uint)*local_1010) *
                            (*local_1038 & 0xff) >> 8) + *local_1010;
        *(byte *)((int)x + 1) =
             (char)(((uint)local_1010[local_101c + 1] - (uint)local_1010[1]) * (*local_1038 & 0xff)
                   >> 8) + local_1010[1];
        *(byte *)((int)x + 2) =
             (char)(((uint)local_1010[local_101c + 2] - (uint)local_1010[2]) * (*local_1038 & 0xff)
                   >> 8) + local_1010[2];
        local_1038 = local_1038 + 1;
        x = (uint *)((int)x + local_101c);
      }
    }
    if (height < y[8]) {
      FID_conflict__memcpy
                ((uint *)((height + -1) * local_101c + (int)local_5054),local_5050,local_101c);
    }
    else {
      _memset((uint *)((height + -1) * local_101c + (int)local_5054),0,local_101c);
    }
    iVar1 = (4 - (width * 3) % 4) % 4;
    if (DAT_004f4628 == 0) {
      FUN_00435551(local_5054,height,width,iVar1);
    }
    else if (DAT_00664c30 == 0x10) {
      uStackY_2c = 0x48034f;
      FUN_00436293(DAT_004f4628,DAT_004f462c,(int)local_5054,height,width,iVar1);
    }
    else if (DAT_00664c30 == 8) {
      uStackY_2c = 0x48038b;
      FUN_004356cf(DAT_004f4628,DAT_004f462c,local_5054,height,width,iVar1);
    }
  }
  return local_5054;
}


