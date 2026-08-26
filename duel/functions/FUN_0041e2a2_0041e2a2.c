/*
 * Decompiled function: FUN_0041e2a2
 * Entry Point: 0041e2a2
 * Size: 1736 bytes
 */
#include "duel.h"


int FUN_0041e2a2(int param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
                undefined4 param_14,undefined4 param_15,undefined4 param_16,undefined4 param_17,
                undefined *param_18,undefined4 param_19,int *param_20)

{
  int iVar1;
  size_t sVar2;
  undefined *local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  undefined4 local_3ac;
  char local_3a8 [200];
  char local_2e0 [200];
  int local_218;
  int aiStack_214 [60];
  int local_124;
  int local_120;
  int local_11c;
  int aiStack_118 [60];
  int local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((param_1 == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
    if ((((byte)DAT_006663f8 & 1) != 0) && ((param_2 & 2) != 0)) {
      param_3 = param_2;
    }
    local_28 = param_1;
    if ((param_2 & 2) == 0) {
      local_18 = param_2 & 1;
    }
    else {
      local_18 = 0xffffffff;
    }
    if ((param_3 & 2) == 0) {
      local_20 = param_3 & 1;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_1c = param_5;
    local_24 = param_9;
    if ((param_4 == 0) || ((param_4 & 0x1000) != 0)) {
      if ((param_3 & 2) == 0) {
        if ((param_3 & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    if (DAT_00681ea4 == 1) {
      local_10 = 0;
    }
    else {
      local_124 = 0;
      for (local_11c = 0; local_11c < 2; local_11c = local_11c + 1) {
        for (local_120 = 0; local_120 < (int)(&DAT_00666408)[local_11c]; local_120 = local_120 + 1)
        {
          if ((*(int *)(&DAT_006826c4 + local_120 * 0x120 + local_11c * 0x5b20) != -1) &&
             (iVar1 = FUN_0041c0ab(local_11c,local_120,0,param_1,param_2,param_3,param_4,param_5,
                                   param_6,param_7,param_8,param_9,param_10,param_11,param_12,
                                   param_13,param_14,param_15,param_16,param_17), iVar1 != 0)) {
            aiStack_118[local_124] = local_11c;
            aiStack_214[local_124] = local_120;
            local_124 = local_124 + 1;
          }
        }
      }
      if (local_14 != 0) {
        aiStack_118[local_124] = 1;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_8 != 0) {
        aiStack_118[local_124] = 0;
        aiStack_214[local_124] = -1;
        local_124 = local_124 + 1;
      }
      if (local_124 == 0) {
        local_10 = 0;
      }
      else {
        if (DAT_0066aaf4 == 1) {
          DAT_0068f2c8 = FUN_00439892(local_124);
          DAT_0068f0bc = CONCAT31((int3)((aiStack_118[DAT_0068f2c8] == 0) - 1 >> 8),
                                  (char)aiStack_214[DAT_0068f2c8]) & 0x1ff | 0x4000;
          DAT_004f3c6c = 3;
          FUN_0043064a();
        }
        else {
          DAT_004f3c6c = 3;
          FUN_004307b2();
          if ((DAT_0068f2c8 == 99) || (local_124 <= DAT_0068f2c8)) {
            DAT_0068f2c8 = FUN_00439892(local_124);
          }
        }
        DAT_0068eef0 = aiStack_118[DAT_0068f2c8];
        *param_20 = aiStack_118[DAT_0068f2c8];
        param_20[1] = aiStack_214[DAT_0068f2c8];
        local_10 = 1;
      }
    }
  }
  else {
    if ((param_4 == 0) || ((param_4 & 0x1000) != 0)) {
      if ((param_2 & 2) == 0) {
        if ((param_2 & 1) == 0) {
          local_8 = 1;
          local_14 = 0;
        }
        else {
          local_8 = 0;
          local_14 = 1;
        }
      }
      else {
        local_8 = 1;
        local_14 = 1;
      }
    }
    else {
      local_8 = 0;
      local_14 = 0;
    }
    local_c = FUN_004a2a2f();
    local_218 = 1;
    while (local_218 != 0) {
      if (param_18 == (undefined *)0x0) {
        FUN_0041de10(param_5,param_9,local_14 | local_8);
      }
      DAT_0066ab04 = -1;
      if (param_18 == (undefined *)0x0) {
        local_3bc = &DAT_005f6810;
      }
      else {
        local_3bc = param_18;
      }
      local_10 = FUN_00440c1e(0xffffffff,local_3bc,param_19,0xffffffff,0xffffffff,0xffffffff,
                              0xffffffff,&local_3b8,&local_3b4,local_14,local_8);
      if (local_10 == 0) {
        if ((local_3b8 != -3) && (local_3b8 == -2)) {
          if ((DAT_0066aac4 == -1) && (DAT_0066ab04 == -1)) {
            *param_20 = local_3b4;
            param_20[1] = local_3b0;
            local_218 = 0;
          }
          else if ((param_4 & 0x2000) != 0) {
            *param_20 = -1;
            param_20[1] = -3;
            local_218 = 0;
          }
        }
      }
      else {
        iVar1 = FUN_0041c0ab(local_3b4,local_3b0,local_2e0,param_1,param_2,param_3,param_4,param_5,
                             param_6,param_7,param_8,param_9,param_10,param_11,param_12,param_13,
                             param_14,param_15,param_16,param_17);
        if (iVar1 == 0) {
          local_3ac = 1;
          sVar2 = _strlen(local_2e0);
          if (sVar2 == 0) {
            FUN_004d9630(local_3a8,s_Illegal_target__004f3024);
          }
          else {
            _sprintf(local_3a8,s_Illegal_target___s___004f300c,local_2e0);
          }
          if (DAT_0066aaf4 != 1) {
            FUN_00450eed(local_3a8);
            Sleep(2000);
            FUN_00450eed(&DAT_004f3034);
          }
        }
        else {
          local_3ac = 0;
          *param_20 = local_3b4;
          param_20[1] = local_3b0;
          local_218 = 0;
        }
      }
    }
    if (local_c == 0) {
      FUN_004a2a87();
    }
    if (local_10 != 0) {
      DAT_0067650c = 0;
    }
    FUN_00450eed(&DAT_004f3038);
    FUN_004d9630(&DAT_006679f0,&DAT_004f303c);
  }
  return local_10;
}


