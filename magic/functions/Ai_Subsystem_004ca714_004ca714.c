/*
 * Decompiled function: Ai_Subsystem_004ca714
 * Entry Point: 004ca714
 * Size: 1150 bytes
 */
#include "magic.h"


void Ai_Subsystem_004ca714
               (int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_30;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_8;
  
  iVar1 = 1 - arg_1;
  if (arg_2 < DAT_00559b1c) {
    if (((&g_CardSlot_Flags)[iVar1 * 0x5b20 + (&DAT_0055a050)[arg_2] * 0x120] & 0x10) == 0) {
      iVar3 = (&DAT_0055a010)[arg_2];
      iVar2 = iVar3 + 1;
      local_2c = 1;
      for (local_18 = 0; local_18 < DAT_00559a94; local_18 = local_18 + 1) {
        local_2c = iVar2 * local_2c;
      }
      if (arg_6 == 0) {
        for (local_18 = 0; local_18 < local_2c; local_18 = local_18 + 1) {
          local_1c = local_18;
          local_28 = iVar3;
          for (local_20 = 0; local_20 < DAT_00559a94; local_20 = local_20 + 1) {
            iVar1 = local_1c % iVar2;
            if (((local_2c < 0x101) || (iVar1 < 2)) || (local_28 <= iVar1)) {
              *(int *)(&DAT_00559b80 + local_20 * 4 + arg_2 * 0x40) = iVar1;
              local_1c = local_1c / iVar2;
              local_28 = local_28 - iVar1;
            }
          }
          if (local_28 == 0) {
            *(int *)(&DAT_005599e0 + arg_2 * 4) = local_18;
            Ai_Subsystem_004ca714(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
          }
        }
      }
      else {
        local_1c = *(int *)(&DAT_00559918 + arg_2 * 4);
        for (local_20 = 0; local_20 < DAT_00559a94; local_20 = local_20 + 1) {
          local_14 = local_1c % iVar2;
          iVar3 = Ai_Subsystem_004cb1d6(iVar1,(&DAT_0055a050)[local_20]);
          if (iVar3 != 0) {
            local_14 = 0;
          }
          if (local_14 != 0) {
            iVar3 = FUN_0041db67(arg_1,(&DAT_005596b8)[local_20],local_14,iVar1,
                                 (&DAT_0055a050)[arg_2]);
            *(int *)(arg_4 + local_20 * 4) = iVar3;
            if ((iVar3 != -1) &&
               (*(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + iVar1 * 0x5b20) =
                     *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + iVar1 * 0x5b20) | 0x40000,
               arg_5 == 0)) {
              *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + iVar1 * 0x5b20) =
                   *(uint *)(&g_CardSlot_Abilities1 + iVar3 * 0x120 + iVar1 * 0x5b20) | 0x100000;
            }
          }
          local_1c = local_1c / iVar2;
        }
        Ai_Subsystem_004ca714(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
      }
    }
    else {
      Ai_Subsystem_004ca714(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
    }
  }
  else {
    local_8 = 0;
    for (local_18 = 0; local_18 < DAT_00559a94; local_18 = local_18 + 1) {
      local_30 = 0;
      for (local_20 = 0; local_20 < DAT_00559b1c; local_20 = local_20 + 1) {
        local_30 = local_30 + *(int *)(&DAT_00559b80 + local_18 * 4 + local_20 * 0x40);
      }
      if (local_30 < (int)(&DAT_00559808)[local_18]) {
        local_8 = local_8 + local_30 * 2;
      }
      else {
        local_8 = local_8 + *(int *)(&DAT_006a5f70 +
                                    arg_1 * 0x5b20 + (&DAT_005596b8)[local_18] * 0x120) +
                  (local_30 - (&DAT_00559808)[local_18]);
      }
    }
    if (arg_3 == 0) {
      if (*arg_8 < local_8) {
        *arg_8 = local_8;
        for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
          *(undefined4 *)(&DAT_00559918 + local_18 * 4) =
               *(undefined4 *)(&DAT_005599e0 + local_18 * 4);
        }
      }
    }
    else if (local_8 < *arg_7) {
      *arg_7 = local_8;
      for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
        *(undefined4 *)(&DAT_00559918 + local_18 * 4) =
             *(undefined4 *)(&DAT_005599e0 + local_18 * 4);
      }
    }
  }
  return;
}


