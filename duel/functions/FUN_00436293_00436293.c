/*
 * Decompiled function: FUN_00436293
 * Entry Point: 00436293
 * Size: 1345 bytes
 */
#include "duel.h"


undefined4 FUN_00436293(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  int local_88;
  uint local_84;
  int local_80;
  undefined *local_7c;
  int local_70 [6];
  int local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  undefined *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c;
  uint local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  int local_c;
  uint local_8;
  
  local_14 = 0;
  local_12 = 0;
  local_10 = 0;
  local_e = 0;
  local_54 = 0;
  local_52 = 0;
  local_50 = 0;
  local_4e = 0;
  local_24 = 0xffff;
  local_22 = 0xffff;
  local_20 = 0xffff;
  local_1e = 0;
  local_3c = 1;
  local_2c = 0;
  local_7c = &DAT_004f46a8 + arg_1 * 0xc0;
  local_18 = arg_5 * 8 + 0x50U >> 2;
  if (DAT_005166dc == 0) {
    for (local_4c = -0x200; (int)local_4c < 0x200; local_4c = local_4c + 1) {
      if (((int)local_4c < 0) || (0xff < (int)local_4c)) {
        if ((int)local_4c < 0) {
          PTR_DAT_004f5428[local_4c] = 0;
        }
        else {
          PTR_DAT_004f5428[local_4c] = 0xff;
        }
      }
      else {
        PTR_DAT_004f5428[local_4c] = (undefined1)local_4c;
      }
    }
    DAT_005166dc = 1;
  }
  if (arg_1 != DAT_004f5430) {
    for (local_4c = 0; local_4c < 0x41; local_4c = local_4c + 1) {
      if (*(int *)(&DAT_006c0560 + local_4c * 4) != 0) {
        FUN_004db150(*(undefined4 *)(&DAT_006c0560 + local_4c * 4));
        *(undefined4 *)(&DAT_006c0560 + local_4c * 4) = 0;
      }
    }
    Palette_AllocErrorDiffusionTable(arg_1,0x6c0560);
    DAT_004f5430 = arg_1;
  }
  for (local_4c = 0; local_4c < 5; local_4c = local_4c + 1) {
    _memset(&DAT_00695f50 + local_4c * 0x8060,0,0x8060);
    local_70[local_4c + 1] = local_4c * 0x8060 + 0x695f78;
  }
  iVar2 = *(int *)(&DAT_004f4630 + arg_1 * 4);
  for (local_58 = 0; local_58 < arg_4; local_58 = local_58 + 1) {
    if (local_3c < 1) {
      local_80 = arg_5 + -1;
      local_1c = -1;
      local_88 = -3;
    }
    else {
      local_80 = 0;
      local_1c = arg_5;
      local_88 = 3;
    }
    local_c = local_80 * 3;
    for (local_4c = local_80; local_4c != local_1c; local_4c = local_4c + local_3c) {
      uVar3 = *(uint *)(local_c + arg_3);
      uVar5 = uVar3 & 0xffffff;
      *(uint *)(local_c + arg_3) = *(uint *)(local_c + arg_3) & 0xff000000;
      psVar6 = (short *)(local_70[1] + local_4c * 8);
      local_8 = (uint)(byte)PTR_DAT_004f5428[(uVar3 & 0xff) + ((int)*psVar6 >> 8)];
      local_38 = (uint)(byte)PTR_DAT_004f5428[(uVar5 >> 8 & 0xff) + ((int)psVar6[1] >> 8)];
      bVar1 = PTR_DAT_004f5428[(uVar5 >> 0x10) + ((int)psVar6[2] >> 8)];
      local_28 = (uint)bVar1 << 0x10 |
                 (uint)(byte)PTR_DAT_004f5428[(uVar5 >> 8 & 0xff) + ((int)psVar6[1] >> 8)] << 8 |
                 (uint)(byte)PTR_DAT_004f5428[(uVar3 & 0xff) + ((int)*psVar6 >> 8)];
      if (local_28 == 0) {
        local_84 = 0;
      }
      else if (local_28 == 0xffffff) {
        local_84 = 0xffffff;
      }
      else {
        local_84 = Mem_AllocOrFree_00436800(local_28);
      }
      *(uint *)(local_c + arg_3) = *(uint *)(local_c + arg_3) | local_84;
      local_40 = local_8 - (local_84 & 0xff);
      local_34 = local_38 - (local_84 >> 8 & 0xff);
      local_30 = local_7c;
      for (local_70[0] = 0; local_70[0] < iVar2; local_70[0] = local_70[0] + 1) {
        local_44 = *(int *)(local_30 + 4);
        local_48 = *(int *)(local_30 + 8);
        iVar4 = *(int *)(local_30 + 0xc);
        psVar6 = (short *)((*(int *)(local_30 + 4) + local_4c) * 8 +
                          local_70[*(int *)(local_30 + 8) + 1]);
        *psVar6 = (short)*(undefined4 *)(iVar4 + local_40 * 4) + *psVar6;
        psVar6[1] = (short)*(undefined4 *)(iVar4 + local_34 * 4) + psVar6[1];
        psVar6[2] = (short)*(undefined4 *)(iVar4 + ((uint)bVar1 - (local_84 >> 0x10 & 0xff)) * 4) +
                    psVar6[2];
        local_30 = local_30 + 0x10;
      }
      local_c = local_c + local_88;
    }
    FUN_00435c74(local_70 + 1,*(int *)(&DAT_004f4658 + arg_1 * 4));
    _memset((void *)(local_70[*(int *)(&DAT_004f4658 + arg_1 * 4)] + -0x28),0,local_18 << 2);
    if (arg_2 != 0) {
      local_3c = -local_3c;
      local_7c = &DAT_004f46a8 + (uint)(local_3c == -1) * 0x6c0 + arg_1 * 0xc0;
    }
    arg_3 = arg_3 + arg_5 * 3 + arg_6;
  }
  return 1;
}


