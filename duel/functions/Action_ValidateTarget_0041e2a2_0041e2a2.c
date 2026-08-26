/*
 * Decompiled function: Action_ValidateTarget_0041e2a2
 * Entry Point: 0041e2a2
 * Size: 1736 bytes
 */
#include "duel.h"


int Action_ValidateTarget_0041e2a2
              (int spell_id,uint target_id,uint flags,uint arg_4,uint arg_5,uint arg_6,uint arg_7,
              uint arg_8,uint arg_9,uint arg_10,int arg_11,int arg_12,uint arg_13,uint arg_14,
              uint arg_15,uint arg_16,uint arg_17,undefined *arg_18,undefined4 arg_19,int *arg_20)

{
  int iVar1;
  size_t sVar2;
  undefined *local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  undefined4 local_3ac;
  uint local_3a8 [50];
  char local_2e0 [200];
  int local_218;
  int aiStack_214 [60];
  int local_124;
  int local_120;
  int local_11c;
  int aiStack_118 [60];
  int local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (((spell_id == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
    if ((((byte)DAT_006663f8 & 1) != 0) && ((target_id & 2) != 0)) {
      flags = target_id;
    }
    local_28 = spell_id;
    if ((target_id & 2) == 0) {
      local_18 = target_id & 1;
    }
    else {
      local_18 = 0xffffffff;
    }
    if ((flags & 2) == 0) {
      local_20 = flags & 1;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_1c = arg_5;
    local_24 = arg_9;
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((flags & 2) == 0) {
        if ((flags & 1) == 0) {
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
             (iVar1 = Rules_ParseFilter_0041c0ab
                                (local_11c,local_120,(undefined1 *)0x0,spell_id,(byte)target_id,
                                 (byte)flags,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,
                                 arg_12,arg_13,arg_14,arg_15,arg_16,arg_17), iVar1 != 0)) {
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
        *arg_20 = aiStack_118[DAT_0068f2c8];
        arg_20[1] = aiStack_214[DAT_0068f2c8];
        local_10 = 1;
      }
    }
  }
  else {
    if ((arg_4 == 0) || ((arg_4 & 0x1000) != 0)) {
      if ((target_id & 2) == 0) {
        if ((target_id & 1) == 0) {
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
      if (arg_18 == (undefined *)0x0) {
        Ai_Subsystem_004bc029(arg_5,arg_9,local_14 | local_8);
      }
      DAT_0066ab04 = -1;
      if (arg_18 == (undefined *)0x0) {
        local_3bc = &DAT_005f6810;
      }
      else {
        local_3bc = arg_18;
      }
      local_10 = FUN_00440c1e(0xffffffff,(int)local_3bc,arg_19,0xffffffff,0xffffffff,0xffffffff,
                              0xffffffff,&local_3b8,&local_3b4,local_14,local_8);
      if (local_10 == 0) {
        if ((local_3b8 != -3) && (local_3b8 == -2)) {
          if ((DAT_0066aac4 == -1) && (DAT_0066ab04 == -1)) {
            *arg_20 = local_3b4;
            arg_20[1] = local_3b0;
            local_218 = 0;
          }
          else if ((arg_4 & 0x2000) != 0) {
            *arg_20 = -1;
            arg_20[1] = -3;
            local_218 = 0;
          }
        }
      }
      else {
        iVar1 = Rules_ParseFilter_0041c0ab
                          (local_3b4,local_3b0,local_2e0,spell_id,(byte)target_id,(byte)flags,arg_4,
                           arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,
                           arg_16,arg_17);
        if (iVar1 == 0) {
          local_3ac = 1;
          sVar2 = _strlen(local_2e0);
          if (sVar2 == 0) {
            Mem_AllocOrFree_004d9630(local_3a8,(uint *)s_Illegal_target__004f3024);
          }
          else {
            _sprintf((char *)local_3a8,s_Illegal_target___s___004f300c,local_2e0);
          }
          if (DAT_0066aaf4 != 1) {
            Mem_AllocOrFree_00450eed((undefined *)local_3a8);
            Sleep(2000);
            Mem_AllocOrFree_00450eed(&DAT_004f3034);
          }
        }
        else {
          local_3ac = 0;
          *arg_20 = local_3b4;
          arg_20[1] = local_3b0;
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
    Mem_AllocOrFree_00450eed(&DAT_004f3038);
    Mem_AllocOrFree_004d9630((uint *)&DAT_006679f0,(uint *)&DAT_004f303c);
  }
  return local_10;
}


