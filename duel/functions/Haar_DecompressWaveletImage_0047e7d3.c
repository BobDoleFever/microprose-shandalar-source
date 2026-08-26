/*
 * Decompiled function: Haar_DecompressWaveletImage
 * Entry Point: 0047e7d3
 * Size: 1106 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * Haar_DecompressWaveletImage(int *arg1,void *arg2)

{
  int arg_7;
  int arg_3;
  int arg_2;
  int arg_4;
  int *arg_2_00;
  int *arg_1;
  int *arg_1_00;
  bool bVar1;
  void *local_50;
  int local_4c;
  int local_48;
  int local_34;
  int local_2c;
  int local_8;
  
  if (DAT_005237c8 == 0) {
    for (local_4c = -0x400; local_4c < 0x401; local_4c = local_4c + 1) {
      if ((local_4c < 0) || (0xf8 < local_4c)) {
        if (local_4c < 10) {
          PTR_DAT_004f9d40[local_4c] = 0;
        }
        else {
          PTR_DAT_004f9d40[local_4c] = 0xff;
        }
      }
      else {
        PTR_DAT_004f9d40[local_4c] = (char)((local_4c * 0xff) / 0xf8);
      }
    }
    DAT_005237c8 = 1;
  }
  bVar1 = arg2 != (void *)0x0;
  if (bVar1) {
    FUN_004d7f60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  else {
    arg2 = _malloc(arg1[0x24] + 2000);
    FUN_004d7f60(arg2,(int)(arg1[0x24] + 2000 + (arg1[0x24] + 2000 >> 0x1f & 3U)) >> 2);
  }
  _DAT_00692c64 = FUN_0047f4b0((int)arg2,arg1);
  if (arg1[10] == 1) {
    local_8 = 1;
  }
  else if (arg1[10] == 4) {
    local_8 = 2;
  }
  else if (arg1[10] == 0x10) {
    local_8 = 4;
  }
  else {
    Assert_Handler_00499950(0,0x4f9d9c,0x15e,s_wavelet_pieces_has_illegal_value_004f9d74);
  }
  arg_7 = arg1[7];
  arg_2 = arg1[7] / local_8;
  arg_3 = arg1[9];
  arg_4 = arg1[8] / local_8;
  for (local_48 = 0; local_48 < arg1[10]; local_48 = local_48 + 1) {
    local_34 = arg_4;
    local_2c = arg_2;
    if (*arg1 != 0) {
      local_34 = (arg_4 / local_8) / (int)((arg1[10] == 1) + 1);
      local_2c = (arg_2 / local_8) / (int)((arg1[10] == 1) + 1);
    }
    arg_2_00 = (int *)((arg_2 * arg_2 + local_2c * local_2c * 2 + 0x40) * local_48 * 4 + (int)arg2);
    arg_1 = arg_2_00 + arg_2 * arg_2 + 0x20;
    arg_1_00 = arg_1 + local_2c * local_2c + 0x20;
    FUN_0047eecc((int)arg_2_00,arg_2,arg_3);
    FUN_0047eecc((int)arg_1,local_2c,arg_3);
    FUN_0047eecc((int)arg_1_00,local_2c,arg_3);
    if (local_48 < arg1[10] / 2) {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg_2,(int)arg_1,(int)arg_1_00,
                                      local_2c,local_2c,*arg1);
    }
    else if (arg1[10] < 2) {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg_4,(int)arg_1,(int)arg_1_00,
                                      local_2c,local_34,*arg1);
    }
    else {
      local_50 = (void *)FUN_0047f1e7(&DAT_00523980,arg_2_00,arg_2,arg1[8] - arg_2,(int)arg_1,
                                      (int)arg_1_00,local_2c,local_34,*arg1);
    }
    if (arg1[10] < 2) {
      if (!bVar1) {
        FUN_004db150(arg2);
      }
      arg2 = local_50;
    }
    else {
      FUN_0047ec25((int)arg2,(int)local_50,(arg_7 / local_8) * (local_48 % local_8),
                   (arg_7 / local_8) * (local_48 / local_8),arg_2,arg_2,arg_7);
      FUN_004db150(local_50);
    }
  }
  return arg2;
}


