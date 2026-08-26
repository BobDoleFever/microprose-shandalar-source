/*
 * Decompiled function: FUN_0042ed60
 * Entry Point: 0042ed60
 * Size: 3718 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0042ed60(int arg_1)

{
  uint uVar1;
  int iVar2;
  uint local_9c;
  uint auStack_98 [20];
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if ((DAT_0066aaf4 == 1) || (DAT_0067650c != 0)) {
    local_30 = 1 - arg_1;
    local_c = 0;
    local_38 = 0;
    local_8 = 0;
    local_28 = 0;
    local_9c = 0;
    local_34 = 2;
    if (((DAT_00681eb0 & 1) == 0) && (0 < (&DAT_0068ee78)[arg_1] + DAT_006668f8)) {
      for (local_2c = 0; (int)local_2c < (int)(&DAT_00666408)[arg_1]; local_2c = local_2c + 1) {
        if (*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120) != -1) {
          if ((((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 2) != 0) &&
             (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34] &
              2) != 0)) {
            local_34 = local_34 | 0x7c;
          }
          if (((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0) {
            if ((((&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34] & 1) != 0) &&
               (local_8 = 1, (&DAT_006826dc)[arg_1 * 0x5b20 + local_2c * 0x120] != '\0')) {
              local_38 = local_38 + 1;
            }
            if ((&DAT_004ff598)[*(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120) * 0x34]
                == -1) {
              local_38 = local_38 + 99;
            }
            local_c = local_c + 1;
          }
        }
      }
      if (local_8 != 0) {
        local_10 = 0;
        local_8 = 0;
        for (local_2c = 0; (int)local_2c < (int)(&DAT_00666408)[arg_1]; local_2c = local_2c + 1) {
          local_20 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120);
          if ((local_20 != -1) && (((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0)
             ) {
            local_40 = (uint)(char)(&DAT_004ff596)[local_20 * 0x34];
            if ((((&DAT_004ff594)[local_20 * 0x34] & 1) != 0) &&
               (local_9c = local_9c | local_40, local_40 == 0)) {
              local_10 = 1;
            }
            if ((local_34 & (byte)(&DAT_004ff594)[local_20 * 0x34]) != 0) {
              for (local_48 = 1; local_48 < 6; local_48 = local_48 + 1) {
                if ((local_40 & 1 << ((byte)local_48 & 0x1f)) != 0) {
                  if (*(int *)(&DAT_0068ef50 + local_48 * 4 + arg_1 * 0x20) + 1 ==
                      (int)(char)(&DAT_004ff597)[local_20 * 0x34]) {
                    local_28 = local_28 | 1 << ((byte)local_48 & 0x1f);
                  }
                  if (*(int *)(&DAT_0068ef50 + local_48 * 4 + arg_1 * 0x20) + 1 <
                      (int)(char)(&DAT_004ff597)[local_20 * 0x34]) {
                    local_8 = local_8 | 1 << ((byte)local_48 & 0x1f);
                  }
                  iVar2 = Mem_AllocOrFree_004d9810((int)(char)(&DAT_004ff598)[local_20 * 0x34]);
                  if (*(int *)(&DAT_0068ef6c + arg_1 * 0x20) <
                      iVar2 + (char)(&DAT_004ff597)[local_20 * 0x34]) {
                    local_8 = local_8 | 0xff;
                  }
                }
              }
            }
          }
        }
        local_3c = 999;
        local_24 = local_9c;
        for (local_2c = 0; (int)local_2c < 6; local_2c = local_2c + 1) {
          if (0 < *(int *)(&DAT_0068f320 + local_2c * 4 + arg_1 * 0x20)) {
            local_8 = local_8 | 1 << ((byte)local_2c & 0x1f);
          }
          if (((local_9c & 1 << ((byte)local_2c & 0x1f)) != 0) &&
             (*(int *)(&DAT_0068ef50 + local_2c * 4 + arg_1 * 0x20) -
              *(int *)(&DAT_0068f320 + local_2c * 4 + arg_1 * 0x20) < local_3c)) {
            local_3c = *(int *)(&DAT_0068ef50 + local_2c * 4 + arg_1 * 0x20) -
                       *(int *)(&DAT_0068f320 + local_2c * 4 + arg_1 * 0x20);
            local_24 = 1 << ((byte)local_2c & 0x1f);
          }
        }
        if (local_9c == 0) {
          if ((DAT_0066aaf4 != 1) && (local_10 != 0)) {
            DAT_004f3c6c = 1;
            FUN_004307b2();
          }
          local_40 = 99;
        }
        else {
          local_18 = local_24;
          if ((local_8 & local_9c) != 0) {
            local_18 = local_8 & local_9c;
          }
          local_34 = local_28 & local_9c;
          uVar1 = local_34;
          if ((local_34 == 0) && (uVar1 = local_18, local_10 != 0)) {
            local_40 = 0xffffffff;
          }
          else {
            do {
              local_18 = uVar1;
              local_40 = FUN_00439892(7);
              uVar1 = local_18;
            } while ((local_18 & 1 << ((byte)local_40 & 0x1f)) == 0);
          }
          if (DAT_0066aaf4 == 1) {
            DAT_0068f2c8 = local_40;
            DAT_0068f0bc = 0xffffffff;
            iVar2 = FUN_00439892(4);
            if ((iVar2 == 0) && (DAT_0066aadc == 0)) {
              DAT_0068f2c8 = 0xfffffffe;
            }
            if ((((local_28 == 0) && (local_8 == 0)) && (local_10 == 0)) &&
               ((local_c < 7 && (3 < *(int *)(&DAT_0068ef6c + arg_1 * 0x20) - local_38)))) {
              DAT_0068f2c8 = 0xfffffffe;
            }
          }
          else {
            DAT_004f3c6c = 1;
            FUN_004307b2();
            local_40 = DAT_0068f2c8;
          }
        }
        local_44 = 0xffffffff;
        for (local_2c = 0; (int)local_2c < (int)(&DAT_00666408)[arg_1]; local_2c = local_2c + 1) {
          local_20 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120);
          if (((((local_20 != -1) &&
                (((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x12) == 0)) &&
               (((&DAT_004ff594)[local_20 * 0x34] & 1) != 0)) &&
              ((((local_40 == 0xffffffff &&
                 ((&DAT_006826dc)[arg_1 * 0x5b20 + local_2c * 0x120] == '\0')) ||
                ((1 << ((byte)local_40 & 0x1f) &
                 (int)(char)(&DAT_006826dc)[arg_1 * 0x5b20 + local_2c * 0x120]) != 0)) ||
               (local_9c == 0)))) && ((local_44 == 0xffffffff || (4 < local_20)))) {
            local_44 = local_2c;
          }
        }
        if ((DAT_0066aaf4 == 1) && ((local_9c != 0 || (local_10 != 0)))) {
          if (DAT_0068f2c8 == 0xfffffffe) {
            DAT_0068f0bc = 0xffffffff;
          }
          else {
            DAT_0068f0bc = arg_1 << 8 | local_44 | 0x1000;
          }
          DAT_004f3c6c = 1;
          FUN_0043064a();
          if (DAT_0068f2c8 != 0xfffffffe) {
            if (0xf < DAT_0066aae4) {
              DAT_0066aae4 = DAT_0066aae4 + -1;
            }
            *(undefined4 *)(&DAT_0068ef00 + DAT_0066aae4 * 4) =
                 *(undefined4 *)(&DAT_006826c4 + local_44 * 0x120 + arg_1 * 0x5b20);
            *(uint *)(&DAT_00666770 + DAT_0066aae4 * 4) = local_44;
            DAT_0066aae4 = DAT_0066aae4 + 1;
          }
        }
        if (DAT_0068f2c8 != 0xfffffffe) {
          return local_44;
        }
        if ((local_9c == 0) && (local_10 == 0)) {
          return local_44;
        }
        DAT_00681eb0 = DAT_00681eb0 | 1;
      }
    }
    local_1c = 0;
    _DAT_0050cb78 = 2;
    _DAT_00511e00 = 0x20;
    if (0x16 < DAT_0068f2c4) {
      _DAT_0050cb78 = 4;
      _DAT_00511e00 = 0x40;
    }
    if (DAT_0068f2c4 < 0x15) {
      _DAT_0050cb78 = 1;
      _DAT_00511e00 = 0x10;
    }
    if (0x1d < DAT_0068f2c4) {
      _DAT_0050cb78 = 8;
      _DAT_00511e00 = 0xffffff80;
    }
    if (DAT_0068f2c4 == 0x1f) {
      _DAT_0050cb78 = 0xf;
      _DAT_00511e00 = 0xfffffff0;
    }
    for (local_2c = 0; (int)local_2c < (int)(&DAT_00666408)[arg_1]; local_2c = local_2c + 1) {
      local_20 = *(int *)(&DAT_006826c4 + arg_1 * 0x5b20 + local_2c * 0x120);
      if (local_20 != -1) {
        if (((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 2) == 0) {
          if (((_DAT_0050cb78 & (int)(char)(&DAT_004ff5ad)[local_20 * 0x34]) != 0) &&
             (((&DAT_004ff594)[local_20 * 0x34] & 0x7e) != 0)) {
            local_40 = FUN_0048c367((&DAT_004ff596)[local_20 * 0x34]);
            iVar2 = FUN_004895b4(arg_1,arg_1,local_2c);
            if ((iVar2 != 0) &&
               ((((&DAT_004ff594)[local_20 * 0x34] & 0x3c) == 0 ||
                (iVar2 = (**(code **)(&DAT_004ff5a0 + local_20 * 0x34))(arg_1,local_2c,0x74),
                iVar2 != 0)))) {
              auStack_98[local_1c] = local_2c;
              local_1c = local_1c + 1;
            }
          }
        }
        else if ((((((&DAT_006826cc)[arg_1 * 0x5b20 + local_2c * 0x120] & 0x34) == 0) &&
                  ((*(uint *)(&DAT_004ff5a8 + local_20 * 0x34) & 0x1003) != 0x1000)) &&
                 ((_DAT_00511e00 & (int)(char)(&DAT_004ff5ad)[local_20 * 0x34]) != 0)) &&
                (iVar2 = FUN_0048c907(arg_1,local_2c,0x73,1 - arg_1,0xffffffff), iVar2 != 0)) {
          auStack_98[local_1c] = local_2c;
          local_1c = local_1c + 1;
        }
      }
    }
    if (local_1c == 0) {
      DAT_0066aae0 = -1;
      DAT_004f3c70 = 0;
      if (DAT_0066aadc == 1) {
        DAT_0068ef94 = -1;
      }
      uVar1 = 0xffffffff;
    }
    else {
      if (DAT_0066aaf4 == 1) {
        if (DAT_00667990 == -9999) {
          DAT_006663f8 = 0;
        }
        if ((DAT_0068dd00 == 0x19) && (local_1c < 3)) {
          DAT_006663f8 = DAT_006663f8 | 1;
        }
      }
      auStack_98[local_1c] = 0xffffffff;
      local_1c = local_1c + 1;
      if (DAT_0066aaf4 == 1) {
        if ((DAT_0066aae0 == -1) || (DAT_0066aadc != 0)) {
          DAT_0068f2c8 = FUN_00439892(local_1c);
          if (DAT_0066aadc != 0) {
            DAT_0068f2c8 = local_1c - 1;
            if (DAT_0066aadc == 1) {
              iVar2 = FUN_0049aa14(local_1c * local_1c,10,0x14);
              DAT_0068ef94 = iVar2 * (DAT_005f2f50 + 1) * 5;
            }
            DAT_0066aadc = -1;
          }
          DAT_0068f0bc = (-(uint)((*(uint *)(&DAT_006826cc +
                                            arg_1 * 0x5b20 + auStack_98[DAT_0068f2c8] * 0x120) & 2)
                                 == 0) & 0xfffff000) + 0x2000 | auStack_98[DAT_0068f2c8] |
                         (arg_1 == 0) - 1 & 0x100;
          DAT_004f3c6c = 2;
          FUN_0043064a();
        }
        else {
          local_14 = Mem_AllocOrFree_004308cf();
          uVar1 = DAT_004f3c70;
          if ((DAT_004f3c70 == 0) && (DAT_0066aae0 < local_14)) {
            DAT_0066aae0 = local_14;
          }
          if (local_14 == DAT_0066aae0) {
            DAT_0068f2c8 = DAT_004f3c70;
            DAT_004f3c70 = DAT_004f3c70 + 1;
            if (local_1c + -1 <= (int)uVar1) {
              DAT_0066aae0 = DAT_0066aae0 + 1;
              DAT_004f3c70 = 0;
            }
          }
          if (DAT_0066aae0 < local_14) {
            DAT_0068f2c8 = local_1c - 1;
          }
          if (local_14 < DAT_0066aae0) {
            DAT_004f3c6c = 2;
            FUN_004307b2();
            Mem_AllocOrFree_004308e4();
            if (local_1c <= (int)DAT_0068f2c8) {
              DAT_0068f2c8 = local_1c - 1;
            }
          }
          DAT_0068f0bc = (-(uint)((*(uint *)(&DAT_006826cc +
                                            arg_1 * 0x5b20 + auStack_98[DAT_0068f2c8] * 0x120) & 2)
                                 == 0) & 0xfffff000) + 0x2000 | auStack_98[DAT_0068f2c8] |
                         (arg_1 == 0) - 1 & 0x100;
          DAT_004f3c6c = 2;
          FUN_0043064a();
          if ((local_1c - 1U == DAT_0068f2c8) && (local_14 < DAT_0066aae0)) {
            DAT_0066aae0 = -1;
            DAT_004f3c70 = 0;
          }
        }
      }
      else {
        DAT_004f3c6c = 2;
        FUN_004307b2();
        if (local_1c <= (int)DAT_0068f2c8) {
          DAT_0068f2c8 = local_1c - 1;
        }
      }
      if (auStack_98[DAT_0068f2c8] != 0xffffffff) {
        if (0xf < DAT_0066aae4) {
          DAT_0066aae4 = DAT_0066aae4 + -1;
        }
        *(undefined4 *)(&DAT_0068ef00 + DAT_0066aae4 * 4) =
             *(undefined4 *)(&DAT_006826c4 + arg_1 * 0x5b20 + auStack_98[DAT_0068f2c8] * 0x120);
        *(uint *)(&DAT_00666770 + DAT_0066aae4 * 4) = auStack_98[DAT_0068f2c8];
        DAT_0066aae4 = DAT_0066aae4 + 1;
      }
      uVar1 = auStack_98[DAT_0068f2c8];
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


