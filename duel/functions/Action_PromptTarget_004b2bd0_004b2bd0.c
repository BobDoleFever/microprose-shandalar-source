/*
 * Decompiled function: Action_PromptTarget_004b2bd0
 * Entry Point: 004b2bd0
 * Size: 1932 bytes
 */
#include "duel.h"


int Action_PromptTarget_004b2bd0
              (int spell_id,int target_id,int flags,uint arg_4,uint arg_5,int arg_6,undefined4 arg_7
              )

{
  int arg2;
  int iVar1;
  uint uVar2;
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
  
  if ((DAT_00681ea4 == 1) || ((DAT_0066aaf4 == 1 && (spell_id == DAT_00676510)))) {
    local_108 = -1;
  }
  else {
    if (((byte)DAT_006663f8 & 1) != 0) {
      flags = target_id;
    }
    if (((spell_id == DAT_00676510) && (DAT_0066aaf4 != 1)) && (DAT_0068f0b0 == 0)) {
      if ((arg_4 != 0) && (arg_4 != 0xff)) {
        DAT_005f6810 = 0;
        local_104 = FUN_0048d3eb();
        if (local_104 != 0xffffffff) {
          iVar1 = *(int *)(&DAT_0068efa8 + DAT_006764b8 * 8);
          arg2 = *(int *)(&DAT_0068efac + DAT_006764b8 * 8);
          uVar2 = local_104 >> 0x10 & 0xff;
          if (uVar2 == 0x71) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_CASTING__005068c8);
            FUN_0044a5a4(iVar1,arg2);
          }
          if (uVar2 == 0x72) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_ACTIVATING__005068d4);
            FUN_0044a5a4(iVar1,arg2);
          }
          if (uVar2 == 0x7e) {
            Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_PROCESSING__005068e4);
            FUN_0044a5a4(iVar1,arg2);
          }
        }
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_005068f4);
      }
      DAT_0066ab04 = 0xffffffff;
      if (((arg_4 == 0) || (arg_4 == 0xff)) || (arg_4 == 0xfffffffe)) {
        local_210 = 0xffffffff;
      }
      else {
        local_210 = arg_4;
      }
      FUN_00440c1e(target_id,arg_6,arg_7,local_210,arg_5,0xffffffff,0xffffffff,&DAT_0068f2cc,
                   &local_10c,0,0);
      if (local_10c != -1) {
        DAT_0067650c = 0;
      }
      Mem_AllocOrFree_004d9630((uint *)&DAT_006679f0,(uint *)&DAT_005068f8);
      DAT_0068eef0 = local_10c;
    }
    else {
      local_110 = 0;
      for (local_fc = 0; local_fc < 2; local_fc = local_fc + 1) {
        if ((flags == -1) || (local_fc == flags)) {
          for (local_100 = 0; local_100 < (int)(&DAT_00666408)[local_fc]; local_100 = local_100 + 1)
          {
            if (((((arg_4 != 0xfffffffe) &&
                  (*(int *)(&DAT_006826c4 + local_100 * 0x120 + local_fc * 0x5b20) != -1)) &&
                 ((((&DAT_006826cc)[local_100 * 0x120 + local_fc * 0x5b20] & 2) != 0 ||
                  ((spell_id == DAT_00676510 && (DAT_0068f0b0 != 0)))))) &&
                (((int)arg_4 < 1 ||
                 ((arg_4 & (byte)(&DAT_004ff594)
                                 [*(int *)(&DAT_006826c4 + local_100 * 0x120 + local_fc * 0x5b20) *
                                  0x34]) != 0)))) &&
               (((arg_5 == 1 || (arg_5 == 0)) ||
                ((arg_5 & (int)(char)(&DAT_006826dc)[local_100 * 0x120 + local_fc * 0x5b20]) != 0)))
               ) {
              aiStack_f4[local_110] = local_fc;
              aiStack_200[local_110] = local_100;
              local_110 = local_110 + 1;
            }
          }
          if (((int)arg_4 < 1) && ((arg_5 == 1 || (arg_5 == 0)))) {
            aiStack_f4[local_110] = local_fc;
            aiStack_200[local_110] = -1;
            local_110 = local_110 + 1;
          }
        }
      }
      if (local_110 == 0) {
        local_108 = -1;
      }
      else if (spell_id == DAT_00676510) {
        do {
          while( true ) {
            do {
              do {
                local_110 = FUN_00439892(local_110);
                DAT_0068eef0 = aiStack_f4[local_110];
                if (DAT_0068f0b0 == 0) goto LAB_004b30cd;
                DAT_0068f2cc = 0;
                iVar1 = FUN_00439892(0x20);
                if ((iVar1 == 0) || (DAT_0068edd4 != 0)) {
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


