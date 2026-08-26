/*
 * Decompiled function: Mana_Init_0045e430
 * Entry Point: 004111bc
 * Size: 1568 bytes
 */
#include "duel.h"


undefined4 Mana_Init_0045e430(int x,int y,int width,int arg_4)

{
  undefined4 uVar1;
  int iVar2;
  int local_78;
  char local_74 [100];
  int local_10;
  int local_c;
  int local_8;
  
  if (width == 0x73) {
    if (((((&DAT_006826ce)[y * 0x120 + x * 0x5b20] & 3) == 0) ||
        (((&DAT_004ff594)[*(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34] & 2) == 0)) &&
       (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    if ((width == 0x6d) && (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      local_8 = FUN_004680fc(x,y);
      if ((DAT_0068f220 == 0) && (iVar2 = FUN_0049b309(x,7,local_8 + 3), iVar2 != 0)) {
        Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_Tap_to_get_mana__004f29b0);
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Charge_battery__add_counter___004f29c4);
        FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_Cancel__004f29e4);
        if ((DAT_0068f2c4 == 0x1f) && (1 - x == DAT_00666458)) {
          local_10 = 1;
        }
        else {
          local_10 = 0;
        }
        local_c = Ai_Subsystem_004cc56d(x,x,y,-1,-1,&DAT_005f6810,local_10);
      }
      else {
        local_c = 0;
      }
      *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = 0;
      if (local_c == 0) {
        FUN_0049b235(x,arg_4,1);
        local_8 = FUN_004680fc(x,y);
        if (local_8 != 0) {
          if (((x == 1) || (DAT_0066aaf4 == 1)) || (DAT_0068f0b0 != 0)) {
            if (DAT_0066aaf4 == 1) {
              local_78 = FUN_00439892(local_8 + 1);
              DAT_0068f2c8 = local_78;
              FUN_0043064a();
            }
            else {
              FUN_004307b2();
              local_78 = DAT_0068f2c8;
            }
          }
          else {
            _sprintf(local_74,s__s_How_many_counters_do_you_wish_004f29f0,
                     *(undefined4 *)
                      (&DAT_00618ac4 +
                      *(int *)(&DAT_004ff590 +
                              *(int *)(&DAT_006826c4 + y * 0x120 + x * 0x5b20) * 0x34) * 0x98),
                     local_8);
            local_78 = FUN_0045139b(x,local_74,0);
          }
          if (local_78 == -1) {
            DAT_00681ea4 = 1;
          }
          else {
            if (local_8 < local_78) {
              local_78 = local_8;
            }
            FUN_0049b2c1(x,arg_4,local_78);
            FUN_0046801f(x,y,local_78);
          }
        }
        if (DAT_00681ea4 == 1) {
          FUN_0049b277(x,arg_4,1);
        }
        else {
          *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = 0;
          *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
               *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
          DAT_0068f0f4 = arg_4;
        }
      }
      else if (local_c == 1) {
        *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
             *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) | 0x10;
        Ai_CalcManaRequirement_004ba890(x,0,2);
        if (DAT_00681ea4 == 1) {
          *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) =
               *(uint *)(&DAT_006826cc + y * 0x120 + x * 0x5b20) & 0xffffffef;
        }
        if (DAT_00681ea4 != 1) {
          *(undefined4 *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) = 1;
          DAT_0068f0f4 = -1;
        }
      }
      else if (local_c == 2) {
        DAT_00681ea4 = 1;
      }
    }
    if ((width == 0x72) && (*(int *)(&DAT_006826e4 + y * 0x120 + x * 0x5b20) == 1)) {
      FUN_00467e37(DAT_00690af0,DAT_0068efa0);
      *(undefined4 *)
       (&DAT_006826e4 +
       *(int *)(&DAT_006827b4 + y * 0x120 + x * 0x5b20) * 0x120 +
       *(int *)(&DAT_006827b0 + y * 0x120 + x * 0x5b20) * 0x5b20) = 0;
    }
    if (((width == 0x7f) && (DAT_00690c48 == y)) &&
       ((DAT_0068ecb0 == x && (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)))) {
      FUN_0049b1a9(x,arg_4,1);
      iVar2 = FUN_004680fc(x,y);
      FUN_0049b1a9(x,arg_4,iVar2);
    }
    if (((width == 0x8f) && (*(int *)(&DAT_0068f2f4 + x * 0x20) != 0)) &&
       (((&DAT_006826cc)[y * 0x120 + x * 0x5b20] & 0x10) == 0)) {
      DAT_0066642c = DAT_0066642c | 1;
    }
    if ((width == 199) && (DAT_00676504 == x)) {
      iVar2 = FUN_004680fc(x,y);
      DAT_0068f2d4 = DAT_0068f2d4 + iVar2 * 0xc;
    }
    uVar1 = 0;
  }
  return uVar1;
}


