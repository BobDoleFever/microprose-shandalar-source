/*
 * Decompiled function: FUN_004b2bd0
 * Entry Point: 004b2bd0
 * Size: 1932 bytes
 */
#include "duel.h"


int FUN_004b2bd0(int param_1,int param_2,int param_3,uint param_4,uint param_5,undefined4 param_6,
                undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint local_210;
  int aiStack_200 [60];
  int local_110;
  int local_10c;
  int local_108;
  uint local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int aiStack_f4 [60];
  
  if ((DAT_00681ea4 == 1) || ((DAT_0066aaf4 == 1 && (param_1 == DAT_00676510)))) {
    local_108 = -1;
  }
  else {
    if (((byte)DAT_006663f8 & 1) != 0) {
      param_3 = param_2;
    }
    if (((param_1 == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
      if ((param_4 != 0) && (param_4 != 0xff)) {
        DAT_005f6810 = 0;
        local_104 = FUN_0048d3eb();
        if (local_104 != 0xffffffff) {
          uVar1 = *(undefined4 *)(&DAT_0068efa8 + DAT_006764b8 * 8);
          uVar2 = *(undefined4 *)(&DAT_0068efac + DAT_006764b8 * 8);
          uVar4 = local_104 >> 0x10 & 0xff;
          if (uVar4 == 0x71) {
            FUN_004d9630(&DAT_005f6810,s_CASTING__005068c8);
            FUN_0044a5a4(uVar1,uVar2);
          }
          if (uVar4 == 0x72) {
            FUN_004d9630(&DAT_005f6810,s_ACTIVATING__005068d4);
            FUN_0044a5a4(uVar1,uVar2);
          }
          if (uVar4 == 0x7e) {
            FUN_004d9630(&DAT_005f6810,s_PROCESSING__005068e4);
            FUN_0044a5a4(uVar1,uVar2);
          }
        }
        FUN_004d9640(&DAT_005f6810,&DAT_005068f4);
      }
      DAT_0066ab04 = 0xffffffff;
      if (((param_4 == 0) || (param_4 == 0xff)) || (param_4 == 0xfffffffe)) {
        local_210 = 0xffffffff;
      }
      else {
        local_210 = param_4;
      }
      FUN_00440c1e(param_2,param_6,param_7,local_210,param_5,0xffffffff,0xffffffff,&DAT_0068f2cc,
                   &local_10c,0,0);
      if (local_10c != -1) {
        DAT_0067650c = 0;
      }
      FUN_004d9630(&DAT_006679f0,&DAT_005068f8);
      DAT_0068eef0 = local_10c;
    }
    else {
      local_110 = 0;
      for (local_fc = 0; local_fc < 2; local_fc = local_fc + 1) {
        if ((param_3 == -1) || (local_fc == param_3)) {
          for (local_100 = 0; local_100 < (int)(&DAT_00666408)[local_fc]; local_100 = local_100 + 1)
          {
            if (((((param_4 != 0xfffffffe) &&
                  (*(int *)(&DAT_006826c4 + local_100 * 0x120 + local_fc * 0x5b20) != -1)) &&
                 ((((&DAT_006826cc)[local_100 * 0x120 + local_fc * 0x5b20] & 2) != 0 ||
                  ((param_1 == DAT_00676510 && (DAT_0068f0b0 != 0)))))) &&
                (((int)param_4 < 1 ||
                 ((param_4 &
                  (byte)(&DAT_004ff594)
                        [*(int *)(&DAT_006826c4 + local_100 * 0x120 + local_fc * 0x5b20) * 0x34]) !=
                  0)))) &&
               (((param_5 == 1 || (param_5 == 0)) ||
                ((param_5 & (int)(char)(&DAT_006826dc)[local_100 * 0x120 + local_fc * 0x5b20]) != 0)
                ))) {
              aiStack_f4[local_110] = local_fc;
              aiStack_200[local_110] = local_100;
              local_110 = local_110 + 1;
            }
          }
          if (((int)param_4 < 1) && ((param_5 == 1 || (param_5 == 0)))) {
            aiStack_f4[local_110] = local_fc;
            aiStack_200[local_110] = -1;
            local_110 = local_110 + 1;
          }
        }
      }
      if (local_110 == 0) {
        local_108 = -1;
      }
      else if (param_1 == DAT_00676510) {
        do {
          while( true ) {
            do {
              do {
                local_110 = FUN_00439892(local_110);
                DAT_0068eef0 = aiStack_f4[local_110];
                if (DAT_0068f0b0 == 0) goto LAB_004b30cd;
                DAT_0068f2cc = 0;
                iVar3 = FUN_00439892(0x20);
                if ((iVar3 == 0) || (DAT_0068edd4 != 0)) {
                  DAT_0066aac4 = 0xffffffff;
                  DAT_0066ab04 = 0xffffffff;
                  DAT_0068f2cc = 0xfffffffe;
                  return -1;
                }
              } while (DAT_00676510 != DAT_0068eef0);
              local_f8 = *(int *)(&DAT_006826c4 +
                                 DAT_0068eef0 * 0x5b20 + aiStack_200[local_110] * 0x120);
            } while (((((&DAT_004ff594)[local_f8 * 0x34] & 1) != 0) &&
                     (((&DAT_006826cc)[DAT_0068eef0 * 0x5b20 + aiStack_200[local_110] * 0x120] & 2)
                      != 0)) ||
                    ((((&DAT_004ff594)[local_f8 * 0x34] & 2) != 0 &&
                     (((&DAT_006826cc)[DAT_0068eef0 * 0x5b20 + aiStack_200[local_110] * 0x120] & 4)
                      != 0))));
            if ((DAT_0068f2c4 < 0x15) || (0x1d < DAT_0068f2c4)) break;
            if ((((&DAT_004ff594)[local_f8 * 0x34] & 2) != 0) &&
               (((&DAT_006826cc)[DAT_0068eef0 * 0x5b20 + aiStack_200[local_110] * 0x120] & 2) != 0))
            goto LAB_004b30cd;
          }
        } while ((((&DAT_004ff594)[local_f8 * 0x34] & 0x4b) == 0) ||
                (((&DAT_006826cc)[DAT_0068eef0 * 0x5b20 + aiStack_200[local_110] * 0x120] & 2) != 0)
                );
LAB_004b30cd:
        local_108 = aiStack_200[local_110];
      }
      else {
        if (DAT_0066aaf4 == 1) {
          DAT_0068f2c8 = FUN_00439892(local_110);
          DAT_0068f0bc = CONCAT31((int3)((aiStack_f4[DAT_0068f2c8] == 0) - 1 >> 8),
                                  (char)aiStack_200[DAT_0068f2c8]) & 0x1ff | 0x4000;
          FUN_0043064a();
        }
        else {
          FUN_004307b2();
          if (DAT_0068f2c8 == 99) {
            DAT_0068f2c8 = FUN_00439892(local_110);
          }
        }
        DAT_0068eef0 = aiStack_f4[DAT_0068f2c8];
        local_108 = aiStack_200[DAT_0068f2c8];
      }
    }
  }
  return local_108;
}


