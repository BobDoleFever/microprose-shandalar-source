/*
 * Decompiled function: FUN_00478e99
 * Entry Point: 00478e99
 * Size: 1595 bytes
 */
#include "duel.h"


/* WARNING: Removing unreachable block (ram,0x0047943e) */
/* WARNING: Removing unreachable block (ram,0x00479448) */

void FUN_00478e99(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int *arg_7,int *arg_8)

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
  if (arg_2 < DAT_0052297c) {
    iVar2 = (&DAT_00522e70)[arg_2];
    iVar3 = iVar2 + 1;
    local_3c = 1;
    for (local_28 = 0; local_28 < DAT_00522a04; local_28 = local_28 + 1) {
      local_3c = local_3c * iVar3;
    }
    if (arg_6 == 0) {
      if ((DAT_005f2f50 + 1) * 0x100 < local_3c) {
        local_2c = 0;
        local_38 = iVar2;
        local_28 = DAT_00522a04;
        while (local_28 = local_28 + -1, 0 < local_28) {
          if (((int)(&DAT_00522730)[local_28] < local_38) &&
             ((*(byte *)((int)&DAT_00522520 + local_28 * 4 + 1) & 2) == 0)) {
            local_2c = local_2c + (&DAT_00522730)[local_28];
            *(undefined4 *)(&DAT_00522a68 + local_28 * 4 + arg_2 * 0x40) = (&DAT_00522730)[local_28]
            ;
            local_38 = local_38 - (&DAT_00522730)[local_28];
          }
          local_2c = local_2c * iVar3;
        }
        if (local_38 != 0) {
          local_2c = local_2c + local_38;
        }
        *(int *)(&DAT_005228c8 + arg_2 * 4) = local_2c;
        FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
      }
      else {
        if (4999999 < local_3c) {
          local_3c = 5000000;
        }
        for (local_28 = 0; local_28 < local_3c; local_28 = local_28 + 1) {
          local_2c = local_28;
          _memset(&DAT_00522a68 + arg_2 * 0x40,0,0x40);
          local_30 = 0;
          for (local_38 = iVar2; (local_30 < DAT_00522a04 && (0 < local_38));
              local_38 = local_38 - iVar1) {
            iVar1 = local_2c % iVar3;
            *(int *)(&DAT_00522a68 + local_30 * 4 + arg_2 * 0x40) = iVar1;
            local_2c = local_2c / iVar3;
            local_30 = local_30 + 1;
          }
          if (local_38 == 0) {
            *(int *)(&DAT_005228c8 + arg_2 * 4) = local_28;
            FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,0,arg_7,arg_8);
          }
        }
      }
    }
    else {
      local_2c = *(int *)(&DAT_00522800 + arg_2 * 4);
      for (local_30 = 0; local_30 < DAT_00522a04; local_30 = local_30 + 1) {
        local_24 = local_2c % iVar3;
        iVar2 = FUN_00479f9f(iVar1,(&DAT_00522f38)[local_30]);
        if (iVar2 != 0) {
          local_24 = 0;
        }
        if (local_24 != 0) {
          iVar2 = FUN_004af950(iVar1,(&DAT_00522f38)[local_30],local_24,arg_1,(&DAT_005225a0)[arg_2]
                              );
          *(int *)(arg_4 + local_30 * 4) = iVar2;
          if (iVar2 != -1) {
            *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                 *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x40000;
            if ((*(byte *)(&DAT_005224e0 + arg_2) & 0x80) != 0) {
              *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x80000;
            }
            if (arg_5 == 0) {
              *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) =
                   *(uint *)(&DAT_006826f8 + iVar2 * 0x120 + arg_1 * 0x5b20) | 0x100000;
            }
          }
        }
        *(int *)(&DAT_00522a68 + local_30 * 4 + arg_2 * 0x40) = local_24;
        local_2c = local_2c / iVar3;
      }
      FUN_00478e99(arg_1,arg_2 + 1,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8);
    }
  }
  else {
    local_c = 0;
    local_10 = (&DAT_00681ea8)[iVar1];
    for (local_28 = 0; local_28 < DAT_00522a04; local_28 = local_28 + 1) {
      local_1c = 0;
      local_40 = 0;
      for (local_30 = 0; local_30 < DAT_0052297c; local_30 = local_30 + 1) {
        local_40 = local_40 + *(int *)(&DAT_00522a68 + local_28 * 4 + local_30 * 0x40);
        if ((*(byte *)(&DAT_005224e0 + local_30) & 0x80) != 0) {
          local_1c = local_1c + *(int *)(&DAT_00522a68 + local_28 * 4 + local_30 * 0x40);
        }
      }
      if (local_40 < (int)(&DAT_00522730)[local_28]) {
        local_c = local_c + local_40 * 2;
      }
      else {
        local_c = local_c + *(int *)(&DAT_00682700 +
                                    iVar1 * 0x5b20 + (&DAT_00522f38)[local_28] * 0x120) +
                  (local_40 - (&DAT_00522730)[local_28]);
        iVar2 = FUN_0049aa14(local_40 - (&DAT_00522730)[local_28],0,local_1c);
        local_10 = local_10 - iVar2;
      }
    }
    if (local_10 < 1) {
      local_10 = local_10 * -0x18 + 999;
    }
    else {
      local_10 = (((&DAT_00681ea8)[iVar1] - local_10) * 0x30) / local_10;
    }
    local_c = local_c + local_10;
    if (arg_3 == 0) {
      if (*arg_8 < local_c) {
        *arg_8 = local_c;
        for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
          *(undefined4 *)(&DAT_00522800 + local_28 * 4) =
               *(undefined4 *)(&DAT_005228c8 + local_28 * 4);
        }
      }
    }
    else if (local_c < *arg_7) {
      *arg_7 = local_c;
      for (local_28 = 0; local_28 < 0x10; local_28 = local_28 + 1) {
        *(undefined4 *)(&DAT_00522800 + local_28 * 4) =
             *(undefined4 *)(&DAT_005228c8 + local_28 * 4);
      }
    }
  }
  return;
}


