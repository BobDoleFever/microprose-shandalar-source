/*
 * Decompiled function: Ai_Subsystem_004ca0d9
 * Entry Point: 004ca0d9
 * Size: 1595 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x004ca67e) */
/* WARNING: Removing unreachable block (ram,0x004ca688) */

void Ai_Subsystem_004ca0d9
               (int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_10;
  int local_c;
  
  iVar1 = 1 - arg_1;
  if (arg_2 < DAT_00559a94) {
    iVar2 = (&DAT_00559f88)[arg_2];
    iVar3 = iVar2 + 1;
    local_3c = 1;
    for (local_28 = 0; local_28 < DAT_00559b1c; local_28 = local_28 + 1) {
      local_3c = iVar3 * local_3c;
    }
    if (arg_6 == 0) {
      if ((DAT_0067f380 + 1) * 0x100 < local_3c) {
        local_2c = 0;
        local_38 = iVar2;
        local_28 = DAT_00559b1c;
        while (local_28 = local_28 + -1, 0 < local_28) {
          if (((int)(&DAT_00559848)[local_28] < local_38) &&
             ((*(byte *)((int)&DAT_00559638 + local_28 * 4 + 1) & 2) == 0)) {
            local_2c = local_2c + (&DAT_00559848)[local_28];
            *(undefined4 *)(&DAT_00559b80 + local_28 * 4 + arg_2 * 0x40) = (&DAT_00559848)[local_28]
            ;
            local_38 = local_38 - (&DAT_00559848)[local_28];
          }
          local_2c = local_2c * iVar3;
        }
        if (local_38 != 0) {
          local_2c = local_2c + local_38;
        }
        *(int *)(&DAT_005599e0 + arg_2 * 4) = local_2c;
        Ai_Subsystem_004ca0d9(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
      }
      else {
        if (4999999 < local_3c) {
          local_3c = 5000000;
        }
        for (local_28 = 0; local_28 < local_3c; local_28 = local_28 + 1) {
          local_2c = local_28;
          memset(&DAT_00559b80 + arg_2 * 0x40,0,0x40);
          local_30 = 0;
          for (local_38 = iVar2; (local_30 < DAT_00559b1c && (0 < local_38));
              local_38 = local_38 - iVar1) {
            iVar1 = local_2c % iVar3;
            *(int *)(&DAT_00559b80 + local_30 * 4 + arg_2 * 0x40) = iVar1;
            local_2c = local_2c / iVar3;
            local_30 = local_30 + 1;
          }
          if (local_38 == 0) {
            *(int *)(&DAT_005599e0 + arg_2 * 4) = local_28;
            Ai_Subsystem_004ca0d9(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
          }
        }
      }
    }
    else {
      local_2c = *(int *)(&DAT_00559918 + arg_2 * 4);
      for (local_30 = 0; local_30 < DAT_00559b1c; local_30 = local_30 + 1) {
        local_24 = local_2c % iVar3;
        iVar2 = Ai_Subsystem_004cb1d6(iVar1,(&DAT_0055a050)[local_30]);
        if (iVar2 != 0) {
          local_24 = 0;
        }
        if (local_24 != 0) {
          iVar2 = FUN_0041db67(iVar1,(&DAT_0055a050)[local_30],local_24,arg_1,(&DAT_005596b8)[arg_2]
                              );
          *(int *)(arg_4 + local_30 * 4) = iVar2;
          if (iVar2 != -1) {
            *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) =
                 *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) | 0x40000;
            if ((*(byte *)(&DAT_005595f8 + arg_2) & 0x80) != 0) {
              *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) =
                   *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) | 0x80000;
            }
            if (arg_5 == 0) {
              *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) =
                   *(uint *)(&g_CardSlot_Abilities1 + arg_1 * 0x5b20 + iVar2 * 0x120) | 0x100000;
            }
          }
        }
        *(int *)(&DAT_00559b80 + local_30 * 4 + arg_2 * 0x40) = local_24;
        local_2c = local_2c / iVar3;
      }
      Ai_Subsystem_004ca0d9(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
    }
  }
  else {
    local_c = 0;
    local_10 = (&g_PlayerCreatureCount)[iVar1];
    for (local_28 = 0; local_28 < DAT_00559b1c; local_28 = local_28 + 1) {
      local_1c = 0;
      local_40 = 0;
      for (local_30 = 0; local_30 < DAT_00559a94; local_30 = local_30 + 1) {
        local_40 = local_40 + *(int *)(&DAT_00559b80 + local_28 * 4 + local_30 * 0x40);
        if ((*(byte *)(&DAT_005595f8 + local_30) & 0x80) != 0) {
          local_1c = local_1c + *(int *)(&DAT_00559b80 + local_28 * 4 + local_30 * 0x40);
        }
      }
      if (local_40 < (int)(&DAT_00559848)[local_28]) {
        local_c = local_c + local_40 * 2;
      }
      else {
        local_c = local_c + *(int *)(&DAT_006a5f70 +
                                    iVar1 * 0x5b20 + (&DAT_0055a050)[local_28] * 0x120) +
                  (local_40 - (&DAT_00559848)[local_28]);
        iVar2 = FUN_0040a305(local_40 - (&DAT_00559848)[local_28],0,local_1c);
        local_10 = local_10 - iVar2;
      }
    }
    if (local_10 < 1) {
      local_10 = local_10 * -0x18 + 999;
    }
    else {
      local_10 = (((&g_PlayerCreatureCount)[iVar1] - local_10) * 0x30) / local_10;
    }
    local_c = local_c + local_10;
    if (arg_3 == 0) {
      if (*arg_8 < local_c) {
        *arg_8 = local_c;
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(undefined4 *)(&DAT_00559918 + local_28 * 4) =
               *(undefined4 *)(&DAT_005599e0 + local_28 * 4);
        }
      }
    }
    else if (local_c < *arg_7) {
      *arg_7 = local_c;
      for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
        *(undefined4 *)(&DAT_00559918 + local_28 * 4) =
             *(undefined4 *)(&DAT_005599e0 + local_28 * 4);
      }
    }
  }
  return;
}


