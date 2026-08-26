/*
 * Decompiled function: FUN_00474d83
 * Entry Point: 00474d83
 * Size: 6885 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00474d83(int arg_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_47c;
  int local_478;
  int local_474;
  int local_470;
  int local_46c [7];
  int local_450 [9];
  uint local_42c;
  int local_428;
  int local_424;
  int local_420;
  int aiStack_41c [16];
  int aiStack_3dc [16];
  undefined4 local_39c [16];
  char acStack_35c [84];
  uint local_308 [16];
  int local_2c8;
  uint local_2c4;
  uint local_2c0;
  int local_2bc;
  int local_2b8;
  uint local_2b4;
  int local_2b0;
  int local_2ac;
  int local_2a8;
  uint local_2a4;
  undefined4 local_2a0;
  int local_29c;
  undefined4 local_298 [16];
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  int local_248;
  int aiStack_244 [16];
  int local_204;
  uint local_200;
  int aiStack_1fc [14];
  int aiStack_1c4 [18];
  int local_17c;
  int aiStack_178 [16];
  int local_138;
  char acStack_134 [80];
  int local_e4;
  int aiStack_e0 [16];
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88 [16];
  undefined4 local_48 [16];
  uint local_8;
  
  FUN_00472fc0(arg_1);
  local_2a0 = DAT_005ef980;
  DAT_005ef980 = 2;
  local_24c = DAT_0066aaf4;
  if (DAT_0066aaf4 == 1) {
    DAT_006663f8 = DAT_006663f8 ^ 2;
  }
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
    *(uint *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0xfffffffb;
  }
  Magic_ScanCards(0x15);
  local_2c4 = 0;
  local_29c = 0;
  local_248 = 0;
  local_8c = 0;
  local_254 = 0;
  local_8 = 0xffffffff;
  _memset(local_46c,0,0x40);
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&DAT_006826c4 + local_2a8 * 0x120 + arg_1 * 0x5b20);
    if ((((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
        ((*(uint *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) & 0x20012) == 2)) &&
       (iVar2 = FUN_0048ad82(arg_1,local_2a8), iVar2 != 0)) {
      if (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
        local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
      }
      if ((((DAT_006663f8 & 2) == 0) ||
          (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0)) ||
         (((&DAT_00692c88)[local_2a8 * 0xc + arg_1 * 0x3c0] & 0x40) == 0)) {
        iVar2 = FUN_00479c07(arg_1,local_2a8);
        aiStack_e0[local_254] = iVar2;
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
        *(uint *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826cc + local_2a8 * 0x120 + arg_1 * 0x5b20) | 4;
      }
      else {
        local_29c = local_29c + *(int *)(&DAT_00692c80 + local_2a8 * 0xc + arg_1 * 0x3c0);
        local_8 = local_8 & *(uint *)(&DAT_00692c88 + local_2a8 * 0xc + arg_1 * 0x3c0);
        local_2c4 = local_2c4 | *(uint *)(&DAT_00692c88 + local_2a8 * 0xc + arg_1 * 0x3c0) & 0x200;
        aiStack_244[local_248] = local_2a8;
        local_248 = local_248 + 1;
      }
    }
  }
  local_8 = local_8 | local_2c4;
  if (7 < local_254) {
    local_470 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1) {
      local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
      if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
         (((&DAT_006826cc)[DAT_00522908 * 0x5b20 + local_2a8 * 0x120] & 0x12) != 0)) {
        local_470 = local_470 + 1;
      }
    }
    for (local_2a8 = 0; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = 0;
    }
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      aiStack_178[local_2a8] = *(int *)(&DAT_00692c80 + local_46c[local_2a8] * 0xc + arg_1 * 0x3c0);
    }
    while (local_470 != 0) {
      local_47c = 0;
      local_478 = 0;
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        if (local_47c < aiStack_178[local_2a8]) {
          local_47c = aiStack_178[local_2a8];
          local_478 = local_2a8;
        }
      }
      aiStack_178[local_478] = 0;
      local_470 = local_470 + -1;
    }
    local_474 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      local_474 = local_474 + aiStack_178[local_2a8];
    }
    if ((int)(&DAT_00681ea8)[1 - arg_1] <= local_474) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
      }
      DAT_006826b0 = (1 << ((byte)local_254 & 0x1f)) - 1;
      return DAT_006826b0;
    }
  }
  if (7 < local_254) {
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      for (local_2b8 = local_2a8; local_2b8 < local_254; local_2b8 = local_2b8 + 1) {
        if (aiStack_e0[local_2a8] < aiStack_e0[local_2b8]) {
          iVar2 = aiStack_e0[local_2a8];
          aiStack_e0[local_2a8] = aiStack_e0[local_2b8];
          aiStack_e0[local_2b8] = iVar2;
          iVar2 = local_46c[local_2a8];
          local_46c[local_2a8] = local_46c[local_2b8];
          local_46c[local_2b8] = iVar2;
          uVar3 = 1 << ((byte)local_2a8 & 0x1f) & local_8c;
          uVar1 = local_8c & ~(1 << ((byte)local_2a8 & 0x1f));
          local_8c = uVar1 & ~(1 << ((byte)local_2b8 & 0x1f));
          if (uVar3 != 0) {
            local_8c = local_8c | 1 << ((byte)local_2b8 & 0x1f);
          }
          if ((1 << ((byte)local_2b8 & 0x1f) & uVar1) != 0) {
            local_8c = local_8c | 1 << ((byte)local_2a8 & 0x1f);
          }
        }
      }
    }
    if (6 < local_254) {
      local_254 = 7;
    }
    for (local_2a8 = 7; local_2a8 < 0x10; local_2a8 = local_2a8 + 1) {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
    }
    _memset(local_450,0,0x24);
    local_8c = 0;
    local_254 = 0;
    for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[arg_1]; local_2a8 = local_2a8 + 1) {
      if (((&DAT_006826cc)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 4) != 0) {
        if (((&DAT_006826cd)[local_2a8 * 0x120 + arg_1 * 0x5b20] & 0x80) != 0) {
          local_8c = local_8c | 1 << ((byte)local_254 & 0x1f);
        }
        local_46c[local_254] = local_2a8;
        local_254 = local_254 + 1;
      }
    }
  }
  FUN_00473a32(arg_1);
  FID_conflict__memcpy(local_88,&DAT_00522e70,0x40);
  FID_conflict__memcpy(local_48,&DAT_005226f0,0x40);
  FID_conflict__memcpy(local_308,&DAT_005224e0,0x40);
  FID_conflict__memcpy(local_298,&DAT_00522eb0,0x40);
  FID_conflict__memcpy(local_39c,&DAT_00522778,0x40);
  FID_conflict__memcpy(&DAT_005227c0,&DAT_00522980,0x40);
  FID_conflict__memcpy(&DAT_00522660,&DAT_00522910,0x40);
  FUN_00430120();
  DAT_0066aaf4 = 1;
  Magic_ScanCards(199);
  DAT_0066aaf4 = local_24c;
  for (local_2a8 = 0; local_2a8 < 8; local_2a8 = local_2a8 + 1) {
    *(undefined4 *)(&DAT_0068ed10 + local_2a8 * 4 + DAT_00522908 * 0x20) =
         *(undefined4 *)(&DAT_0068ef50 + local_2a8 * 4 + DAT_00522908 * 0x20);
  }
  local_e4 = 0;
  local_90 = 0;
  for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1) {
    local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
    if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
       (((&DAT_006826cc)[DAT_00522908 * 0x5b20 + local_2a8 * 0x120] & 2) != 0)) {
      aiStack_41c[local_90] = *(int *)(&DAT_00692c80 + local_2a8 * 0xc + DAT_00522908 * 0x3c0);
      aiStack_3dc[local_90] = *(int *)(&DAT_00692c84 + local_2a8 * 0xc + DAT_00522908 * 0x3c0);
      if (((&DAT_004ff5a8)[local_204 * 0x34] & 8) != 0) {
        iVar2 = (**(code **)(&DAT_004ff5a0 + local_204 * 0x34))(DAT_00522908,local_2a8,0x39);
        aiStack_41c[local_90] = aiStack_41c[local_90] + iVar2;
      }
      if (((&DAT_004ff5a8)[local_204 * 0x34] & 0x10) != 0) {
        iVar2 = (**(code **)(&DAT_004ff5a0 + local_204 * 0x34))(DAT_00522908,local_2a8,0x3a);
        aiStack_3dc[local_90] = aiStack_3dc[local_90] + iVar2;
      }
      if (local_e4 < aiStack_3dc[local_90]) {
        local_e4 = aiStack_3dc[local_90];
      }
      acStack_35c[local_2a8] = (char)local_90;
      local_90 = local_90 + 1;
    }
  }
  local_420 = -1;
  for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
    if (((local_420 == -1) && (local_88[local_2a8] < local_e4)) &&
       ((local_e4 <= local_88[local_2a8] + local_29c &&
        ((local_308[local_2a8] & local_8) == local_308[local_2a8])))) {
      local_88[local_2a8] = local_88[local_2a8] + local_29c;
      local_420 = local_46c[local_2a8];
    }
  }
  local_17c = 0;
  for (local_2b8 = 0; local_2b8 < (int)(&DAT_00666408)[arg_1]; local_2b8 = local_2b8 + 1) {
    if (((*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
        (((&DAT_006826cc)[local_2b8 * 0x120 + arg_1 * 0x5b20] & 2) != 0)) &&
       (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34] & 2)
        != 0)) {
      aiStack_178[local_17c] = *(int *)(&DAT_00692c80 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_1fc[local_17c] = *(int *)(&DAT_00692c84 + local_2b8 * 0xc + arg_1 * 0x3c0);
      aiStack_e0[local_17c] = (aiStack_178[local_17c] + 1) * (aiStack_1fc[local_17c] + 1);
      for (local_2c0 = 0; (int)local_2c0 < DAT_0052297c; local_2c0 = local_2c0 + 1) {
        if ((&DAT_005225a0)[local_2c0] == local_2b8) {
          aiStack_e0[local_17c] = (&DAT_00522eb0)[local_2c0];
        }
      }
      acStack_134[local_2b8] = (char)local_17c;
      local_17c = local_17c + 1;
    }
  }
  FUN_00430367();
  local_258 = 9999;
  FUN_00431f41(&local_2b4,(uint *)0x0);
  local_2c0 = 0;
  do {
    if (1 << ((byte)local_254 & 0x1f) <= (int)local_2c0) {
      for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
        if ((local_2a4 & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
               *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
          FUN_0048ad82(arg_1,local_46c[local_2a8]);
          if (((local_248 != 0) && (local_420 == -1)) &&
             ((local_308[local_2a8] & local_8) == local_308[local_2a8])) {
            local_420 = local_46c[local_2a8];
          }
        }
      }
      if (((local_248 == 0) || (local_420 == -1)) ||
         (((&DAT_006826cc)[local_420 * 0x120 + arg_1 * 0x5b20] & 4) == 0)) {
        if ((local_248 != 0) && (local_e4 == 0)) {
          for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
            *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
                 *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
            FUN_0048ad82(arg_1,aiStack_244[local_2a8]);
          }
          local_2a4 = 1;
        }
      }
      else {
        for (local_2a8 = 0; local_2a8 < local_248; local_2a8 = local_2a8 + 1) {
          (&DAT_006826de)[arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120] = (undefined1)local_420;
          *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) =
               *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + aiStack_244[local_2a8] * 0x120) | 4;
          FUN_0048ad82(arg_1,aiStack_244[local_2a8]);
        }
        (&DAT_006826de)[local_420 * 0x120 + arg_1 * 0x5b20] = (undefined1)local_420;
      }
      DAT_005ef980 = local_2a0;
      DAT_006826b0 = local_2a4;
      return local_2a4;
    }
    local_2bc = 1;
    DAT_0052297c = 0;
    _DAT_005226e8 = 0;
    for (local_2a8 = 0; local_2a8 < local_254; local_2a8 = local_2a8 + 1) {
      *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
           *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) & 0xfffffffb;
      local_2b0 = *(int *)(&DAT_004ff590 +
                          *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) *
                          0x34);
      if ((local_2c0 & 1 << ((byte)local_2a8 & 0x1f)) == 0) {
        if ((local_2b0 == 0x19f) || (local_2b0 == 0x84)) {
          local_2bc = 0;
        }
        if ((local_8c & 1 << ((byte)local_2a8 & 0x1f)) != 0) {
          local_2bc = 0;
        }
      }
      else {
        *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) =
             *(uint *)(&DAT_006826cc + arg_1 * 0x5b20 + local_46c[local_2a8] * 0x120) | 4;
        (&DAT_005225a0)[DAT_0052297c] = local_46c[local_2a8];
        (&DAT_00522e70)[DAT_0052297c] = local_88[local_2a8];
        (&DAT_005226f0)[DAT_0052297c] = local_48[local_2a8];
        (&DAT_005224e0)[DAT_0052297c] = local_308[local_2a8];
        (&DAT_00522eb0)[DAT_0052297c] = local_298[local_2a8];
        (&DAT_00522778)[DAT_0052297c] = local_39c[local_2a8];
        (&DAT_00522980)[DAT_0052297c] = *(undefined4 *)(&DAT_005227c0 + local_2a8 * 4);
        (&DAT_00522910)[DAT_0052297c] = *(undefined4 *)(&DAT_00522660 + local_2a8 * 4);
        if ((local_2b0 == 0x28) || (local_2b0 == 0x98)) {
          _DAT_005226e8 = _DAT_005226e8 | 1 << ((byte)DAT_0052297c & 0x1f);
        }
        DAT_0052297c = DAT_0052297c + 1;
      }
    }
    if (local_2bc != 0) {
      DAT_00522a00 = 1;
      FUN_00476868(arg_1);
      FUN_00430120();
      DAT_0066aaf4 = 1;
      Magic_ScanCards(199);
      DAT_0066aaf4 = local_24c;
      local_2ac = 0;
      for (local_98 = 0; local_98 < 8; local_98 = local_98 + 1) {
        aiStack_1c4[local_98 * 2 + 3] = -1;
      }
      for (local_2a8 = 0; local_2a8 < (int)(&DAT_00666408)[DAT_00522908]; local_2a8 = local_2a8 + 1)
      {
        local_204 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_2a8 * 0x120);
        if (((local_204 != -1) && (((&DAT_004ff594)[local_204 * 0x34] & 2) != 0)) &&
           ((*(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_2a8 * 0x120) & 0x402) != 0)) {
          local_90 = (int)acStack_35c[local_2a8];
          local_428 = aiStack_41c[acStack_35c[local_2a8]];
          local_2b8 = 0;
LAB_00476070:
          if (local_2b8 < 8) {
            if (local_428 <= aiStack_1c4[local_2b8 * 2 + 3]) goto LAB_0047606a;
            for (local_98 = 7; local_2b8 < local_98; local_98 = local_98 + -1) {
              aiStack_1c4[local_98 * 2 + 2] = aiStack_1c4[local_98 * 2];
              aiStack_1c4[local_98 * 2 + 3] = aiStack_1c4[local_98 * 2 + 1];
            }
            aiStack_1c4[local_2b8 * 2 + 2] = local_2a8;
            aiStack_1c4[local_2b8 * 2 + 3] = local_428;
          }
        }
      }
      local_98 = 0;
      while ((local_98 < 8 && (aiStack_1c4[local_98 * 2 + 3] != -1))) {
        local_2a8 = aiStack_1c4[local_98 * 2 + 2];
        local_200 = FUN_0048b81a(DAT_00522908,local_2a8,0x34,0xffffffff);
        local_90 = (int)acStack_35c[local_2a8];
        local_428 = aiStack_41c[local_90];
        local_424 = aiStack_3dc[local_90];
        local_2c8 = 0;
        local_42c = 0;
        local_17c = 0;
        local_9c = 0x7fff;
        for (local_2b8 = 0; local_2b8 < (int)(&DAT_00666408)[arg_1]; local_2b8 = local_2b8 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) != -1) &&
              ((*(uint *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) & 0x402) != 0)) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + local_2b8 * 0x120 + arg_1 * 0x5b20) * 0x34]
              & 2) != 0)) {
            local_17c = (int)acStack_134[local_2b8];
            local_a0 = aiStack_178[local_17c];
            local_138 = aiStack_1fc[local_17c];
            iVar4 = local_2b8 * 0x120;
            iVar2 = FUN_0048af80(arg_1,local_2b8);
            if (((*(uint *)(&DAT_006826cc + iVar4 + arg_1 * 0x5b20) & (-(uint)(iVar2 == 0) & 4) + 8)
                 == 0) &&
               (iVar2 = FUN_0048b2c9(arg_1,local_2b8,DAT_00522908,local_2a8,local_200,local_2b4),
               uVar1 = local_42c, iVar2 != 0)) {
              local_42c = local_42c | 1;
              if ((local_428 < local_138) || (local_424 <= local_a0)) {
                local_42c = uVar1 | 3;
                *(uint *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) =
                     *(uint *)(&DAT_006826cc + local_2b8 * 0x120 + arg_1 * 0x5b20) | 8;
                break;
              }
              if (aiStack_e0[local_17c] < local_9c) {
                local_9c = aiStack_e0[local_17c];
                local_2c8 = local_2b8;
              }
            }
          }
        }
        if ((local_42c & 2) == 0) {
          iVar2 = *(int *)(&DAT_00666710 + arg_1 * 4) * local_428 * 0x18;
          iVar2 = iVar2 + (iVar2 >> 0x1f & 3U);
          iVar4 = FUN_0049aa14((&DAT_00681ea8)[arg_1] + 1,1,99);
          local_250 = (int)(CONCAT44(iVar2 >> 0x1f,iVar2 >> 2) / (longlong)iVar4);
          if (local_42c != 0) {
            local_94 = (int)(*(int *)(&DAT_00666718 + arg_1 * 4) * local_9c +
                            (*(int *)(&DAT_00666718 + arg_1 * 4) * local_9c >> 0x1f & 7U)) >> 3;
            if (local_94 <= local_250) {
              DAT_00522ef0 = DAT_00522ef0 + local_94;
              *(uint *)(&DAT_006826cc + local_2c8 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826cc + local_2c8 * 0x120 + arg_1 * 0x5b20) | 8;
              goto LAB_0047613a;
            }
          }
          local_2ac = local_2ac + local_428;
          DAT_00522ef0 = DAT_00522ef0 + local_250;
        }
LAB_0047613a:
        local_98 = local_98 + 1;
      }
      FUN_00430367();
      if ((((int)(&DAT_00681ea8)[arg_1] <= local_2ac) && (0 < (int)(&DAT_00681ea8)[arg_1])) &&
         (0 < (int)(&DAT_00681ea8)[1 - arg_1])) {
        DAT_00522ef0 = DAT_00522ef0 + ((local_2ac - (&DAT_00681ea8)[arg_1]) + 2) * 0x80;
        DAT_00522ef0 = DAT_00522ef0 + DAT_00522880;
      }
      if (DAT_00522ef0 < local_258) {
        local_258 = DAT_00522ef0;
        local_2a4 = local_2c0;
      }
    }
    local_2c0 = local_2c0 + 1;
  } while( true );
LAB_0047606a:
  local_2b8 = local_2b8 + 1;
  goto LAB_00476070;
}


