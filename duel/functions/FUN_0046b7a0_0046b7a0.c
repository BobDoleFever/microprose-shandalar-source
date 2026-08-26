/*
 * Decompiled function: FUN_0046b7a0
 * Entry Point: 0046b7a0
 * Size: 4139 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0046b7a0(int arg1,uint *arg2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int local_84;
  int local_7c;
  int local_78;
  byte local_74;
  int local_70;
  uint local_68 [16];
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((int)(&DAT_00681ea8)[DAT_00676510] < 1) {
    *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
         *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) | 2;
  }
  local_18 = 0;
  if (((DAT_0066aaf4 != 1) && (DAT_00666458 == DAT_0066aac4)) && (DAT_0066ab04 == DAT_0068f2c4)) {
    DAT_0068eee4 = 0;
  }
  if (arg1 == 1) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_0042aa48(DAT_0068f2c4);
  }
  Mem_AllocOrFree_004d9630(local_68,arg2);
  uVar3 = DAT_00681eb4;
  uVar2 = DAT_00681eb0;
  local_14 = arg1;
  DAT_00681eb4 = arg1;
  local_24 = arg1;
  DAT_0068edd4 = 1;
  DAT_006826b4 = DAT_0068ef98 & 0x30;
  _DAT_0068f368 = 0;
  DAT_00666740 = DAT_00666740 + 1;
  if (DAT_00666740 < DAT_00681ed0) {
    DAT_00681ed0 = 0;
  }
  _DAT_0052243c = 2;
  _DAT_00522440 = 0x20;
  if (0x16 < DAT_0068f2c4) {
    _DAT_0052243c = 4;
    _DAT_00522440 = 0x40;
  }
  if (DAT_0068f2c4 < 0x15) {
    _DAT_0052243c = 1;
    _DAT_00522440 = 0x10;
  }
  if (0x1d < DAT_0068f2c4) {
    _DAT_0052243c = 8;
    _DAT_00522440 = 0xffffff80;
  }
  if (DAT_0068f2c4 == 0x1f) {
    _DAT_0052243c = 0xf;
    _DAT_00522440 = 0xfffffff0;
  }
  if ((DAT_00676504 == arg1) && (DAT_0068efb0 == DAT_00676510)) {
    _DAT_0052243c = 0xf;
    _DAT_00522440 = 0xfffffff0;
  }
  if (((((DAT_0066aaf4 == 1) || (DAT_0067650c != 0)) ||
       ((DAT_0068f230 != -1 && (DAT_00676504 == DAT_00681ec4)))) || (DAT_00666744 == 4)) ||
     ((DAT_00676504 == arg1 && ((DAT_00681eb0 & 0x200) != 0)))) {
    local_84 = FUN_0046c7d0(arg1);
    local_14 = DAT_0068eef0;
  }
  else {
    local_84 = -1;
  }
  local_20 = 0;
  if ((local_84 != -1) && (iVar4 = FUN_0046e4c9(local_14,local_84,0x7d,local_24), iVar4 == 2)) {
    FUN_0048a1c7(local_14,local_84,local_24);
    local_84 = -1;
    FUN_00451482(0,0xff);
  }
  if (local_84 != -1) {
    _DAT_0068f0d4 = *(int *)(&DAT_006826c4 + local_84 * 0x120 + local_14 * 0x5b20);
    local_1c = _DAT_0068f0d4;
    if (((&DAT_006826cc)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
      iVar4 = FUN_00488598(local_14,local_84);
      if (iVar4 != 0) {
        if ((&DAT_004ff594)[local_1c * 0x34] == ' ') {
          DAT_006826b4 = DAT_0068ef98 & 0x20;
        }
        local_20 = 1;
        FUN_00451482(0,0xff);
        if ((DAT_0066aaf4 != 1) && (iVar4 = FUN_00439892(3), iVar4 == 0)) {
          FUN_004d7e29(s_Didn_t_expect_that__did_ya__004f9660);
        }
      }
    }
    else {
      if (((*(int *)(&DAT_00682710 + local_84 * 0x120 + local_14 * 0x5b20) == DAT_0068f230) &&
          (DAT_00666760 != (code *)0x0)) && (DAT_0068f230 != -1)) {
        if (DAT_00666760 != (code *)0x0) {
          (*DAT_00666760)(local_14,local_84);
        }
      }
      else {
        FUN_0048c907(local_14,local_84,0x73,1 - local_14,0xffffffff);
        iVar4 = FUN_0048974c(local_14,local_84);
        if (iVar4 != 0) {
          FUN_0048a07d(local_14,local_84);
        }
        DAT_00681ea4 = 0;
      }
      local_20 = 1;
      FUN_00451482(0,0xff);
    }
  }
  local_28 = 0;
  local_8 = 0;
  local_7c = -1;
  if ((DAT_0066aaf4 != 1) || ((DAT_0068f230 != -1 && (DAT_00676510 == DAT_00681ec4)))) {
    if ((DAT_00676510 == DAT_00681ec4) && (DAT_0068f230 != -1)) {
      for (local_24 = 0; local_24 < 2; local_24 = local_24 + 1) {
        for (local_70 = 0; local_70 < (int)(&DAT_00666408)[local_24]; local_70 = local_70 + 1) {
          if ((((&DAT_006826cc)[local_24 * 0x5b20 + local_70 * 0x120] & 2) != 0) &&
             (iVar4 = FUN_0046e4c9(local_24,local_70,0x7d,arg1), iVar4 != 0)) {
            if (iVar4 == 2) {
              local_7c = local_70;
              local_c = local_24;
              local_14 = local_24;
              local_8 = local_8 + 1;
            }
            else {
              local_74 = (byte)iVar4;
              local_28 = local_28 | 1 << (local_74 & 0x1f);
            }
          }
          if (((((DAT_00666440 & 1) != 0) &&
               (*(int *)(&DAT_00682710 + local_24 * 0x5b20 + local_70 * 0x120) == DAT_0068f230)) &&
              (local_24 == DAT_00681ec4)) && (DAT_0068f230 != -1)) {
            local_28 = local_28 | 4;
            local_7c = local_70;
            local_c = local_24;
            local_14 = local_24;
            local_8 = local_8 + 1;
          }
        }
      }
    }
    if (local_7c == -1) {
      if (DAT_0066aaf4 == 1) goto LAB_0046c78c;
      if ((DAT_0068f230 == 0xca) && (*(int *)(&DAT_006667d0 + DAT_00666458 * 0x98) == 0)) {
        DAT_00666440 = 0;
      }
      if ((DAT_0068f230 == 0xce) && (*(int *)(&DAT_006667e8 + DAT_00666458 * 0x98) == 0)) {
        DAT_00666440 = 0;
      }
    }
    if (((local_7c != -1) || (local_28 != 0)) || (((DAT_00666440 & 1) != 0 && (DAT_0068ef98 != 0))))
    {
      DAT_00676500 = 0;
      DAT_00666440 = 0;
      local_78 = 0;
      for (local_70 = 0; local_70 < (int)(&DAT_00666408)[DAT_00676510]; local_70 = local_70 + 1) {
        if (((*(int *)(&DAT_006826c4 + local_70 * 0x120 + DAT_00676510 * 0x5b20) != -1) &&
            (((((&DAT_006827d4)[local_70 * 0x120 + DAT_00676510 * 0x5b20] & 1) != 0 ||
              (((&DAT_006827d4)[local_70 * 0x120 + DAT_00676510 * 0x5b20] & 0x10) != 0)) ||
             ((iVar4 = FUN_0048ca2a(DAT_00676510,local_70), iVar4 == 0 &&
              (DAT_00676510 == DAT_00681eb4)))))) &&
           (((uVar5 = FUN_0046cc45(DAT_00676510,local_70), 1 < (int)uVar5 ||
             ((((DAT_00666404 != 0 || (DAT_00666458 != DAT_00676510)) && ((uVar5 & 2) != 0)) ||
              ((DAT_00676500 & 2) != 0)))) &&
            (((DAT_00676510 != DAT_00681ec4 || (DAT_0068f230 == -1)) ||
             ((uVar5 != 2 || ((DAT_00676500 & 2) != 0)))))))) {
          if (((DAT_00676500 & 2) == 0) && (uVar5 != 2)) {
            if (uVar5 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
          }
          else {
            local_7c = local_70;
            local_c = DAT_00676510;
            local_8 = local_8 + 1;
          }
          DAT_00676500 = DAT_00676500 & 0xfffffffd;
        }
      }
      if (DAT_00666744 == 4) {
        for (local_70 = 0; local_70 < (int)(&DAT_00666408)[1 - DAT_00676510];
            local_70 = local_70 + 1) {
          if (((*(int *)(&DAT_006826c4 + local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20) != -1) &&
              (((((&DAT_006827d4)[local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20] & 1) != 0 ||
                (((&DAT_006827d4)[local_70 * 0x120 + (1 - DAT_00676510) * 0x5b20] & 0x10) != 0)) ||
               (iVar4 = FUN_0048ca2a(1 - DAT_00676510,local_70), iVar4 == 0)))) &&
             (iVar4 = FUN_0046cc45(1 - DAT_00676510,local_70), (DAT_00676500 & 2) != 0)) {
            local_7c = local_70;
            local_c = 1 - DAT_00676510;
            local_8 = local_8 + 1;
            DAT_00676500 = DAT_00676500 & 0xfffffffd;
            if (iVar4 == 2) {
              local_28 = local_28 | 4;
            }
            else {
              local_28 = local_28 | 2;
            }
            break;
          }
        }
      }
      if ((local_28 & 2) != 0) {
        local_18 = 1;
      }
    }
  }
  if (((local_18 != 0) || (local_10 != 0)) || (local_8 != 0)) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Triggered_effects_____004f967c);
    if (((DAT_006826b4 & 0x10) == 0) || (DAT_0068ecd0 != -1)) {
      if ((DAT_006826b4 & 0x20) != 0) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Interrupts_____004f96a8);
      }
    }
    else {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Fast_Effects_____004f9694);
    }
    if (DAT_0068f230 != -1) {
      Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Triggered_effects_____004f96b8);
    }
    FUN_004d9640((uint *)&DAT_005f6810,local_68);
    if ((DAT_0068eee4 == 0) || ((local_28 & 2) != 0)) {
      if (((((local_10 == 0) && ((DAT_00666404 == 0 || (DAT_0068f230 != -1)))) &&
           ((local_18 == 0 || (DAT_0068f230 == -1)))) &&
          ((DAT_004fac20 == 0 || ((local_28 & 6) == 0)))) &&
         (((local_8 <= (int)(uint)((local_28 & 2) == 0) && ((local_28 & 4) == 0)) ||
          ((((local_78 == 0 && (iVar4 = FUN_0042a99c(), iVar4 != 0)) || (DAT_0068f230 == 0xd6)) ||
           ((local_7c != -1 && (DAT_00666740 == DAT_00681ed0)))))))) {
        local_84 = local_7c;
        local_14 = local_c;
        _DAT_0068f368 = 1;
      }
      else {
        DAT_00690314 = 1;
        DAT_0066aac4 = -1;
        DAT_00681ed0 = 0;
        bVar1 = false;
        while (!bVar1) {
          if (DAT_0066aaf4 == 1) {
            local_84 = local_7c;
            bVar1 = true;
            DAT_0068f2cc = -1;
          }
          else {
            local_84 = Action_PromptTarget_004b2bd0(DAT_00676510,-1,DAT_00676510,0xff,0,0x5f6810,2);
            local_14 = DAT_0068eef0;
            if (-1 < local_84) {
              *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) =
                   *(uint *)(&DAT_006667c0 + DAT_0068f2c4 * 4 + DAT_00666458 * 0x98) | 2;
            }
          }
          if (DAT_0068f2cc == -3) {
            bVar1 = false;
          }
          else if (DAT_0068f2cc == -2) {
            bVar1 = true;
            local_84 = -1;
            DAT_00666758 = DAT_00666758 & 0xfffffffd;
            if (DAT_0068f230 != -1) {
              DAT_0066aac4 = DAT_00666458;
              DAT_0066ab04 = DAT_0068f2c4;
              DAT_0068f2cc = 0;
            }
            if (local_8 != 0) {
              DAT_00681ed0 = DAT_00666740;
              DAT_0068eee4 = 1;
              _DAT_0068f368 = 1;
              DAT_0066ab04 = -1;
              DAT_0066aac4 = -1;
            }
          }
          else if (DAT_0068f2cc == 0) {
            if ((local_14 == -1) || (local_84 == -1)) {
              if ((local_14 != -1) && (local_84 == -1)) {
                bVar1 = false;
              }
            }
            else {
              bVar1 = true;
            }
          }
        }
      }
    }
    else {
      local_84 = local_7c;
      local_14 = local_c;
      if (local_7c != -1) {
        _DAT_0068f368 = 1;
      }
    }
    DAT_005f6810 = 0;
    if ((local_84 != -1) &&
       ((DAT_00676510 == local_14 ||
        (((((&DAT_006826cc)[local_84 * 0x120 + local_14 * 0x5b20] & 2) != 0 &&
          (iVar4 = FUN_0046e4c9(local_14,local_84,0x7d,DAT_00676510), iVar4 != 0)) ||
         (DAT_00666744 == 4)))))) {
      local_1c = *(int *)(&DAT_006826c4 + local_84 * 0x120 + local_14 * 0x5b20);
      iVar4 = FUN_0046cc45(local_14,local_84);
      if (iVar4 == 0) {
        iVar4 = FUN_0042b120(local_14,local_84);
        if (iVar4 != 0) {
          FUN_0042b213(local_14,local_84);
        }
      }
      else {
        if (((&DAT_006826cc)[local_84 * 0x120 + local_14 * 0x5b20] & 2) == 0) {
          FUN_00488598(local_14,local_84);
          if ((&DAT_004ff594)[local_1c * 0x34] == ' ') {
            DAT_006826b4 = DAT_0068ef98 & 0x20;
          }
          iVar4 = FUN_00439892(3);
          if (iVar4 == 0) {
            FUN_004d7e29(s_I_knew_that_was_coming__004f96d0);
          }
        }
        else {
          iVar4 = FUN_0046e4c9(local_14,local_84,0x7d,DAT_00676510);
          if (iVar4 == 0) {
            if (((*(int *)(&DAT_00682710 + local_84 * 0x120 + local_14 * 0x5b20) == DAT_0068f230) &&
                (DAT_00666760 != (code *)0x0)) && (DAT_0068f230 != -1)) {
              if (DAT_00666760 != (code *)0x0) {
                (*DAT_00666760)(local_14,local_84);
              }
            }
            else {
              iVar4 = FUN_0048974c(local_14,local_84);
              if (((iVar4 != 0) && (FUN_0048a07d(local_14,local_84), DAT_00681ea4 != 1)) &&
                 (DAT_0066aaf4 != 1)) {
                FUN_0048d00c(0x1c);
              }
              DAT_00681ea4 = 0;
            }
          }
          else {
            FUN_0048a1c7(local_14,local_84,DAT_00676510);
          }
        }
        FUN_00451482(0,0xff);
        local_20 = local_20 | 2;
      }
      local_20 = local_20 | 2;
    }
    DAT_00666440 = 1;
    _DAT_0068f368 = 0;
  }
LAB_0046c78c:
  if (local_20 == 0) {
    DAT_006826b4 = DAT_0068ef98 & 0x30;
  }
  DAT_0068edd4 = 0;
  DAT_00681eb4 = uVar3;
  DAT_00681eb0 = uVar2;
  DAT_00666740 = DAT_00666740 + -1;
  return local_20;
}


