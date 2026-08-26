/*
 * Decompiled function: Pic_Subsystem_0043e0f6
 * Entry Point: 004d0ef2
 * Size: 1696 bytes
 */
#include "duel.h"


undefined4 Pic_Subsystem_0043e0f6(int arg_1,int arg_2,int arg_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int local_2a8;
  int local_2a4;
  int local_2a0;
  int local_29c;
  int local_298;
  int local_294;
  int local_290;
  int local_28c;
  int aiStack_288 [160];
  int local_8;
  
  if (arg_3 == 0x74) {
    uVar1 = 1;
  }
  else {
    if (arg_3 == 0x6c) {
      DAT_0068f2d4 = DAT_0068f2d4 + 0x18;
    }
    if (arg_3 == 0x73) {
      if (((DAT_0068f2c4 == 4) && (((&DAT_006826e4)[arg_2 * 0x120 + arg_1 * 0x5b20] & 1) == 0)) &&
         (DAT_00666458 == DAT_00681eb4)) {
        *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006827d4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x101;
        DAT_00676500 = DAT_00676500 | 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      if (((arg_3 == 4) && (DAT_00690c48 == arg_2)) && (DAT_0068ecb0 == arg_1)) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) | 1;
        DAT_006664ec = 1;
        DAT_0066642c = DAT_0066642c | 1;
      }
      if (arg_3 == 0x86) {
        if (DAT_0066aaf4 == 1) {
          return 0;
        }
        for (local_290 = 0; local_290 < 2; local_290 = local_290 + 1) {
          local_294 = 0;
          for (local_8 = 0; local_8 < (int)(&DAT_00666408)[local_290]; local_8 = local_8 + 1) {
            if (((*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_290 * 0x5b20) != -1) &&
                (((&DAT_006826cc)[local_8 * 0x120 + local_290 * 0x5b20] & 2) != 0)) &&
               ((((&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + local_8 * 0x120 + local_290 * 0x5b20) * 0x34] & 0x43) !=
                 0 && (iVar4 = local_8 * 0x120, uVar2 = FUN_004521e2(arg_1,arg_2),
                      (*(uint *)(&DAT_006826fc + iVar4 + local_290 * 0x5b20) & uVar2) == 0)))) {
              aiStack_288[local_294 + local_290 * 0x50] = local_8;
              local_294 = local_294 + 1;
            }
          }
          if (DAT_00676510 == local_290) {
            local_2a8 = local_294;
          }
          else {
            local_2a4 = local_294;
          }
        }
        if (DAT_00666458 == DAT_00676510) {
          if (local_2a8 < 1) {
            DAT_00681ea4 = 1;
          }
          else {
            iVar4 = FUN_00439892(local_2a8);
            local_298 = aiStack_288[iVar4 + DAT_00676510 * 0x50];
            local_28c = 0;
            local_29c = 0;
            local_294 = FUN_00439892(local_2a4);
            while ((local_28c == 0 && (local_29c < local_2a4))) {
              local_2a0 = aiStack_288[local_294 + DAT_00676504 * 0x50];
              if (((&DAT_004ff594)
                   [*(int *)(&DAT_006826c4 + local_298 * 0x120 + DAT_00676510 * 0x5b20) * 0x34] &
                  (&DAT_004ff594)
                  [*(int *)(&DAT_006826c4 + local_2a0 * 0x120 + DAT_00676504 * 0x5b20) * 0x34]) == 0
                 ) {
                local_294 = (local_294 + 1) % local_2a4;
                local_29c = local_29c + 1;
              }
              else {
                local_28c = 1;
              }
            }
            if (local_28c != 1) {
              DAT_00681ea4 = 1;
            }
          }
        }
        else if (local_2a4 < 1) {
          DAT_00681ea4 = 1;
        }
        else {
          iVar4 = FUN_00439892(local_2a4);
          local_2a0 = aiStack_288[iVar4 + DAT_00676504 * 0x50];
          local_28c = 0;
          local_29c = 0;
          local_294 = FUN_00439892(local_2a8);
          while ((local_28c == 0 && (local_29c < local_2a8))) {
            local_298 = aiStack_288[local_294 + DAT_00676510 * 0x50];
            if (((&DAT_004ff594)
                 [*(int *)(&DAT_006826c4 + local_298 * 0x120 + DAT_00676510 * 0x5b20) * 0x34] &
                (&DAT_004ff594)
                [*(int *)(&DAT_006826c4 + local_2a0 * 0x120 + DAT_00676504 * 0x5b20) * 0x34]) == 0)
            {
              local_294 = (local_294 + 1) % local_2a8;
              local_29c = local_29c + 1;
            }
            else {
              local_28c = 1;
            }
          }
          if (local_28c != 1) {
            DAT_00681ea4 = 1;
          }
        }
        if ((local_28c == 1) && (DAT_00681ea4 != 1)) {
          Mem_AllocOrFree_004d9630((uint *)&DAT_005f6810,(uint *)s_is_swapping_00508f38);
          puVar3 = (uint *)Ai_Subsystem_004b8e4d(DAT_00676510,local_298);
          FUN_004d9640((uint *)&DAT_005f6810,puVar3);
          FUN_004d9640((uint *)&DAT_005f6810,(uint *)s_for_00508f48);
          puVar3 = (uint *)Ai_Subsystem_004b8e4d(DAT_00676504,local_2a0);
          FUN_004d9640((uint *)&DAT_005f6810,puVar3);
          Ai_Subsystem_004cc56d(arg_1,arg_1,arg_2,-1,-1,&DAT_005f6810,0);
          FUN_004bfc63(DAT_00676510,local_298,DAT_00676504,local_2a0);
        }
        if (DAT_00681ea4 != 1) {
          FUN_0048d00c(0x2a);
        }
      }
      if (arg_3 == 0x22) {
        *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) =
             *(uint *)(&DAT_006826e4 + arg_2 * 0x120 + arg_1 * 0x5b20) & 0xfffffffe;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}


