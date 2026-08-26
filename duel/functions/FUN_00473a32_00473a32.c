/*
 * Decompiled function: FUN_00473a32
 * Entry Point: 00473a32
 * Size: 4945 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473a32(int arg_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int aiStack_cc [16];
  uint local_8c;
  int local_88;
  int local_84;
  uint local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int aiStack_58 [16];
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  DAT_00522908 = 1 - arg_1;
  if (DAT_00522a00 == 0) {
    FUN_00431f41(&local_8,&local_18);
    if (DAT_00522908 == 1) {
      DAT_00522f7c = local_8;
    }
    else {
      DAT_00522f7c = local_18;
    }
    DAT_00522f78 = 0;
    DAT_0052297c = 0;
    local_6c = DAT_0066aaf4;
    DAT_0066aaf4 = 1;
    DAT_006c121c = 1;
    FUN_00479952();
    FUN_00430120();
    local_64 = DAT_0068f2d4;
    DAT_0068f2d4 = 0;
    DAT_00522884 = 0;
    _DAT_005226e8 = 0;
    Magic_ScanCards(199);
    Pic_Subsystem_004475a4(arg_1);
    local_88 = FUN_00430911(arg_1);
    local_88 = DAT_0068f2d4 + local_88;
    FUN_00430367();
    DAT_0068f2d4 = local_64;
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_70 * 0x120);
      if (((local_68 != -1) && (((&DAT_006826cc)[arg_1 * 0x5b20 + local_70 * 0x120] & 4) != 0)) &&
         (((&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] == -1 ||
          ((char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] == local_70)))) {
        local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
        local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + arg_1 * 0x3c0);
        (&DAT_005225a0)[DAT_0052297c] = local_70;
        (&DAT_00522e70)[DAT_0052297c] = *(int *)(&DAT_00666730 + arg_1 * 4) + local_78;
        (&DAT_005226f0)[DAT_0052297c] =
             *(int *)(&DAT_00692c84 + local_70 * 0xc + arg_1 * 0x3c0) +
             *(int *)(&DAT_00666738 + arg_1 * 4);
        (&DAT_005224e0)[DAT_0052297c] =
             *(undefined4 *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0);
        iVar2 = FUN_0049b309(arg_1,local_80,1);
        if (iVar2 == 0) {
          (&DAT_005224e0)[DAT_0052297c] = (&DAT_005224e0)[DAT_0052297c] & 0xfffffdff;
        }
        DAT_0069340c = 0;
        FUN_0048c50b(arg_1,local_70,0x8a);
        (&DAT_00522980)[DAT_0052297c] = DAT_0069340c;
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
          iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x39);
          (&DAT_00522e70)[DAT_0052297c] = (&DAT_00522e70)[DAT_0052297c] + iVar2;
        }
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
          iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x3a);
          (&DAT_005226f0)[DAT_0052297c] = (&DAT_005226f0)[DAT_0052297c] + iVar2;
        }
        FUN_00430120();
        local_64 = DAT_0068f2d4;
        DAT_0068f2d4 = 0;
        *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) =
             *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) | 8;
        FUN_0046e571(arg_1,local_70,2);
        Magic_ScanCards(199);
        Pic_Subsystem_004475a4(arg_1);
        local_c = FUN_00430911(arg_1);
        local_c = DAT_0068f2d4 + local_c;
        FUN_00430367();
        DAT_0068f2d4 = local_64;
        iVar2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_68 * 0x34]);
        local_10 = ((iVar2 + (char)(&DAT_004ff597)[local_68 * 0x34]) - local_c) + local_88;
        if ((*(byte *)((int)&DAT_005224e0 + DAT_0052297c * 4 + 1) & 2) != 0) {
          iVar2 = FUN_0049b309(arg_1,local_80,1);
          if (iVar2 == 0) {
            local_10 = local_10 << 1;
          }
          else {
            local_10 = local_10 / 3;
          }
        }
        *(int *)(&DAT_00682700 + arg_1 * 0x5b20 + local_70 * 0x120) = local_10;
        (&DAT_00522eb0)[DAT_0052297c] = local_10;
        (&DAT_005226f0)[DAT_0052297c] =
             (&DAT_005226f0)[DAT_0052297c] -
             (int)*(short *)(&DAT_006826d0 + arg_1 * 0x5b20 + local_70 * 0x120);
        (&DAT_00522778)[DAT_0052297c] = 0;
        if ((&DAT_006827df)[arg_1 * 0x5b20 + local_70 * 0x120] != '\0') {
          _DAT_005226e8 = _DAT_005226e8 | 1 << ((byte)DAT_0052297c & 0x1f);
        }
        DAT_0052297c = DAT_0052297c + 1;
        if ((DAT_0066aaf4 == 1) && (6 < DAT_0052297c)) break;
      }
    }
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[arg_1]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_70 * 0x120);
      if ((((local_68 != -1) && (((&DAT_006826cc)[arg_1 * 0x5b20 + local_70 * 0x120] & 4) != 0)) &&
          ((&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] != -1)) &&
         ((char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] != local_70)) {
        local_5c = -1;
        for (local_74 = 0; local_74 < DAT_0052297c; local_74 = local_74 + 1) {
          if ((int)(char)(&DAT_006826de)[arg_1 * 0x5b20 + local_70 * 0x120] ==
              (&DAT_005225a0)[local_74]) {
            local_5c = local_74;
            break;
          }
        }
        if (local_5c != -1) {
          local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
          (&DAT_005229c0)[DAT_00522f78] = local_70;
          local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + arg_1 * 0x3c0);
          (&DAT_00522e70)[local_5c] = (&DAT_00522e70)[local_5c] + local_78;
          (&DAT_005226f0)[local_5c] =
               (&DAT_005226f0)[local_5c] + *(int *)(&DAT_00692c84 + local_70 * 0xc + arg_1 * 0x3c0);
          local_8c = *(uint *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0) & 0x200 |
                     (&DAT_005224e0)[local_5c] & 0x200;
          (&DAT_005224e0)[local_5c] =
               (&DAT_005224e0)[local_5c] & *(uint *)(&DAT_00692c88 + local_70 * 0xc + arg_1 * 0x3c0)
          ;
          (&DAT_005224e0)[local_5c] = (&DAT_005224e0)[local_5c] | local_8c;
          if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
            iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x39);
            (&DAT_00522e70)[local_5c] = (&DAT_00522e70)[local_5c] + iVar2;
          }
          if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
            iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(arg_1,local_70,0x3a);
            (&DAT_005226f0)[local_5c] = (&DAT_005226f0)[local_5c] + iVar2;
          }
          FUN_00430120();
          local_64 = DAT_0068f2d4;
          DAT_0068f2d4 = 0;
          *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) =
               *(uint *)(&DAT_006826f8 + arg_1 * 0x5b20 + local_70 * 0x120) | 8;
          FUN_0046e571(arg_1,local_70,2);
          Magic_ScanCards(199);
          Pic_Subsystem_004475a4(arg_1);
          local_c = FUN_00430911(arg_1);
          local_c = DAT_0068f2d4 + local_c;
          FUN_00430367();
          DAT_0068f2d4 = local_64;
          iVar2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_68 * 0x34]);
          local_10 = ((iVar2 + (char)(&DAT_004ff597)[local_68 * 0x34]) - local_c) + local_88;
          if ((*(byte *)((int)&DAT_005224e0 + local_5c * 4 + 1) & 2) != 0) {
            iVar2 = FUN_0049b309(arg_1,local_80,1);
            if (iVar2 == 0) {
              local_10 = local_10 << 1;
            }
            else {
              local_10 = local_10 / 3;
            }
          }
          *(int *)(&DAT_00682700 + arg_1 * 0x5b20 + local_70 * 0x120) = local_10;
          if (local_10 < (int)(&DAT_00522eb0)[local_5c]) {
            (&DAT_00522eb0)[local_5c] = local_10;
          }
          (&DAT_005226f0)[local_5c] =
               (&DAT_005226f0)[local_5c] -
               (int)*(short *)(&DAT_006826d0 + arg_1 * 0x5b20 + local_70 * 0x120);
          (&DAT_00522778)[local_5c] = 0;
          if ((&DAT_006827df)[arg_1 * 0x5b20 + local_70 * 0x120] != '\0') {
            _DAT_005226e8 = _DAT_005226e8 | 1 << ((byte)local_5c & 0x1f);
          }
          DAT_00522f78 = DAT_00522f78 + 1;
        }
      }
    }
    local_60 = 0;
    for (local_70 = 0; local_70 < (int)(&DAT_00666408)[DAT_00522908]; local_70 = local_70 + 1) {
      local_68 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      if (((local_68 != -1) && (((&DAT_004ff594)[local_68 * 0x34] & 2) != 0)) &&
         ((((byte)*(undefined4 *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0x12)
           == 2 && ((&DAT_006826de)[DAT_00522908 * 0x5b20 + local_70 * 0x120] == -1)))) {
        aiStack_58[local_60] = local_70;
        local_60 = local_60 + 1;
      }
      if ((DAT_0066aaf4 == 1) && (0xf < local_60)) break;
    }
    if ((DAT_0066aaf4 == 1) && (6 < local_60)) {
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        iVar2 = FUN_00479e13(DAT_00522908,aiStack_58[local_70]);
        aiStack_cc[local_70] = iVar2;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_cc[local_70] < aiStack_cc[local_74]) {
            iVar2 = aiStack_cc[local_70];
            aiStack_cc[local_70] = aiStack_cc[local_74];
            aiStack_cc[local_74] = iVar2;
            iVar2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = iVar2;
          }
        }
      }
      if (6 < local_60) {
        local_60 = 7;
      }
      for (local_70 = 0; local_70 < local_60; local_70 = local_70 + 1) {
        for (local_74 = local_70; local_74 < local_60; local_74 = local_74 + 1) {
          if (aiStack_58[local_74] < aiStack_58[local_70]) {
            iVar2 = aiStack_58[local_70];
            aiStack_58[local_70] = aiStack_58[local_74];
            aiStack_58[local_74] = iVar2;
          }
        }
      }
    }
    DAT_00522a04 = 0;
    for (local_84 = 0; local_84 < local_60; local_84 = local_84 + 1) {
      local_70 = aiStack_58[local_84];
      local_68 = *(int *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      local_80 = FUN_0048c367((&DAT_004ff596)[local_68 * 0x34]);
      *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) | 8;
      local_78 = *(int *)(&DAT_00692c80 + local_70 * 0xc + DAT_00522908 * 0x3c0);
      (&DAT_00522f38)[DAT_00522a04] = local_70;
      (&DAT_00522ef8)[DAT_00522a04] = *(int *)(&DAT_00666730 + DAT_00522908 * 4) + local_78;
      (&DAT_00522730)[DAT_00522a04] =
           *(int *)(&DAT_00692c84 + local_70 * 0xc + DAT_00522908 * 0x3c0) +
           *(int *)(&DAT_00666738 + DAT_00522908 * 4);
      (&DAT_00522520)[DAT_00522a04] =
           *(undefined4 *)(&DAT_00692c88 + local_70 * 0xc + DAT_00522908 * 0x3c0);
      iVar2 = FUN_0049b309(DAT_00522908,local_80,1);
      if (iVar2 == 0) {
        (&DAT_00522520)[DAT_00522a04] = (&DAT_00522520)[DAT_00522a04] & 0xfffffdff;
      }
      DAT_0069340c = 0;
      FUN_0048c50b(DAT_00522908,local_70,0x8b);
      (&DAT_00522910)[DAT_0052297c] = DAT_0069340c;
      if (DAT_00676510 == DAT_00522908) {
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 8) != 0) {
          iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(DAT_00522908,local_70,0x39);
          (&DAT_00522ef8)[DAT_00522a04] = (&DAT_00522ef8)[DAT_00522a04] + iVar2;
        }
        if (((&DAT_004ff5a8)[local_68 * 0x34] & 0x10) != 0) {
          iVar2 = (**(code **)(&DAT_004ff5a0 + local_68 * 0x34))(DAT_00522908,local_70,0x3a);
          (&DAT_00522730)[DAT_00522a04] = (&DAT_00522730)[DAT_00522a04] + iVar2;
        }
      }
      FUN_00430120();
      local_64 = DAT_0068f2d4;
      DAT_0068f2d4 = 0;
      *(uint *)(&DAT_006826f8 + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint *)(&DAT_006826f8 + DAT_00522908 * 0x5b20 + local_70 * 0x120) | 8;
      FUN_0046e571(DAT_00522908,local_70,2);
      Magic_ScanCards(199);
      Pic_Subsystem_004475a4(arg_1);
      local_c = FUN_00430911(arg_1);
      local_c = DAT_0068f2d4 + local_c;
      FUN_00430367();
      DAT_0068f2d4 = 0;
      *(undefined4 *)(&DAT_006826c4 + DAT_00522908 * 0x5b20 + local_70 * 0x120) = 0xffffffff;
      local_14 = FUN_00430911(arg_1);
      local_14 = DAT_0068f2d4 + local_14;
      FUN_00430367();
      DAT_0068f2d4 = local_64;
      local_10 = local_c - local_88;
      if ((*(byte *)((int)&DAT_00522520 + DAT_00522a04 * 4 + 1) & 2) != 0) {
        iVar2 = FUN_0049b309(DAT_00522908,local_80,1);
        if (iVar2 == 0) {
          local_10 = local_10 << 1;
        }
        else {
          local_10 = local_10 / 5;
        }
      }
      (&DAT_00522f80)[DAT_00522a04] = local_10;
      *(int *)(&DAT_00682700 + DAT_00522908 * 0x5b20 + local_70 * 0x120) = local_10;
      (&DAT_00522730)[DAT_00522a04] =
           (&DAT_00522730)[DAT_00522a04] -
           (int)*(short *)(&DAT_006826d0 + DAT_00522908 * 0x5b20 + local_70 * 0x120);
      *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0xfffffff7;
      for (local_74 = 0; local_74 < DAT_0052297c; local_74 = local_74 + 1) {
        iVar2 = FUN_0048b2c9(DAT_00522908,local_70,arg_1,(&DAT_005225a0)[local_74],
                             (&DAT_005224e0)[local_74],DAT_00522f7c);
        if (iVar2 == 0) {
          if (DAT_00522f78 != 0) {
            for (local_7c = 0; local_7c < DAT_00522f78; local_7c = local_7c + 1) {
              if (((int)(char)(&DAT_006826de)[arg_1 * 0x5b20 + (&DAT_005229c0)[local_7c] * 0x120] ==
                   (&DAT_005225a0)[local_70]) &&
                 (iVar2 = FUN_0048b2c9(DAT_00522908,local_70,arg_1,(&DAT_005229c0)[local_7c],
                                       (&DAT_005224e0)[local_74],DAT_00522f7c), iVar2 != 0)) {
                (&DAT_00522778)[local_74] =
                     (&DAT_00522778)[local_74] | 1 << ((byte)DAT_00522a04 & 0x1f);
              }
            }
          }
        }
        else {
          (&DAT_00522778)[local_74] = (&DAT_00522778)[local_74] | 1 << ((byte)DAT_00522a04 & 0x1f);
        }
      }
      if ((&DAT_006827df)[DAT_00522908 * 0x5b20 + local_70 * 0x120] != '\0') {
        DAT_00522884 = DAT_00522884 | 1 << ((byte)DAT_00522a04 & 0x1f);
      }
      *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) =
           *(uint *)(&DAT_006826cc + DAT_00522908 * 0x5b20 + local_70 * 0x120) & 0xfffffff7;
      iVar2 = *(int *)(&DAT_00666718 + DAT_00522908 * 4);
      iVar1 = (&DAT_00522f80)[DAT_00522a04];
      iVar3 = FUN_0049aa14((&DAT_00522730)[DAT_00522a04] + 1,1,99);
      (&DAT_00522560)[DAT_00522a04] = (iVar2 * iVar1) / iVar3;
      DAT_00522a04 = DAT_00522a04 + 1;
      if ((DAT_0066aaf4 == 1) && (6 < DAT_00522a04)) break;
    }
    _memset(&DAT_00522950,0,0x1c);
    _memset(&DAT_00522a08,0,0x1c);
    for (local_70 = 0; local_70 < DAT_0052297c; local_70 = local_70 + 1) {
      for (local_74 = 0; local_74 < DAT_00522a04; local_74 = local_74 + 1) {
        uVar4 = FUN_0048f31a(arg_1,(&DAT_005225a0)[local_70],DAT_00522908,(&DAT_00522f38)[local_74])
        ;
        if ((uVar4 & 1) != 0) {
          *(uint *)(&DAT_00522950 + local_70 * 4) =
               *(uint *)(&DAT_00522950 + local_70 * 4) | 1 << ((byte)local_74 & 0x1f);
        }
        if ((uVar4 & 2) != 0) {
          *(uint *)(&DAT_00522a08 + local_74 * 4) =
               *(uint *)(&DAT_00522a08 + local_74 * 4) | 1 << ((byte)local_70 & 0x1f);
        }
      }
    }
    DAT_0066aaf4 = local_6c;
  }
  DAT_00522a00 = 0;
  DAT_006c121c = 0;
  DAT_00522770 = (&DAT_004f98a8)[DAT_0052297c];
  return;
}


