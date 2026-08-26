/*
 * Decompiled function: FUN_0048e306
 * Entry Point: 0048e306
 * Size: 1882 bytes
 */
#include "magic.h"


void FUN_0048e306(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int arg2;
  int iVar5;
  uint uVar6;
  undefined4 arg_1;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_10;
  int local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0xf; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0067eff8 + local_8 * 0x30) = 0xffffffff;
    *(undefined4 *)(&DAT_0067eff4 + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067eff8 + local_8 * 0x30);
    *(undefined4 *)(&DAT_0067eff0 + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067eff4 + local_8 * 0x30);
    *(undefined4 *)(&DAT_0067f018 + local_8 * 0x30) = 0xffffffff;
    *(undefined4 *)(&DAT_0067f01c + local_8 * 0x30) =
         *(undefined4 *)(&DAT_0067f018 + local_8 * 0x30);
  }
  for (local_2c = 0; local_2c < g_MasterCardCount + -0x29; local_2c = local_2c + 1) {
    if (((&DAT_0051aed1)[local_2c * 0x34] & 1) != 0) {
      do {
        iVar4 = FUN_0040a1d2(10);
        iVar4 = iVar4 + 5;
      } while (*(int *)(&DAT_0067eff8 + iVar4 * 0x30) != -1);
      if (*(int *)(&DAT_0067eff0 + iVar4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff0 + iVar4 * 0x30) = local_2c;
      }
      else if (*(int *)(&DAT_0067eff4 + iVar4 * 0x30) == -1) {
        *(int *)(&DAT_0067eff4 + iVar4 * 0x30) = local_2c;
      }
      else {
        *(int *)(&DAT_0067eff8 + iVar4 * 0x30) = local_2c;
      }
    }
  }
  local_8 = 0;
  do {
    if (0xe < local_8) {
      return;
    }
    do {
      do {
        do {
          iVar4 = FUN_0040a1d2(0x40);
          arg2 = FUN_0040a1d2(0x40);
          iVar5 = FUN_0040c761(iVar4,arg2);
        } while (iVar5 == 0);
        uVar6 = FUN_0040c7c0(iVar4,arg2);
      } while ((uVar6 & 0x30) != 0);
      local_28 = 0xff;
      for (local_20 = 0; local_20 < 0x80; local_20 = local_20 + 1) {
        if ((local_8 < 5) && (*(int *)(&DAT_0067bdf0 + local_20 * 100) == 4)) {
          arg_1 = FUN_0040c761(*(int *)(&DAT_0067bdf4 + local_20 * 100),
                               *(int *)(&DAT_0067bdf8 + local_20 * 100));
          iVar5 = Adventure_GetLocationEncounterIndex(arg_1);
          if (iVar5 == 1 << ((char)local_8 + 1U & 0x1f)) {
            local_10 = local_20;
          }
        }
        if (((1 < *(int *)(&DAT_0067bdf0 + local_20 * 100)) &&
            (*(int *)(&DAT_0067bdf0 + local_20 * 100) != 4)) &&
           (iVar5 = FUN_0040a36f(*(int *)(&DAT_0067bdf4 + local_20 * 100) - iVar4,
                                 *(int *)(&DAT_0067bdf8 + local_20 * 100) - arg2), iVar5 < local_28)
           ) {
          local_24 = local_20;
          local_28 = iVar5;
        }
      }
      for (local_20 = 0; local_20 < local_8; local_20 = local_20 + 1) {
        iVar5 = FUN_0040a36f(*(int *)(&DAT_0067f000 + local_20 * 0x30) - iVar4,
                             *(int *)(&DAT_0067f004 + local_20 * 0x30) - arg2);
        if (iVar5 < local_28) {
          local_28 = iVar5;
        }
      }
    } while (local_28 < 4);
    FUN_0040c81c(0x40,iVar4,arg2);
    *(int *)(&DAT_0067f000 + local_8 * 0x30) = iVar4;
    *(int *)(&DAT_0067f004 + local_8 * 0x30) = arg2;
    *(int *)(&DAT_0067f008 + local_8 * 0x30) = local_24;
    cVar3 = FUN_0040a1d2(5);
    (&DAT_0067f00c)[local_8 * 0x30] = cVar3 + '\x01';
    (&DAT_0067f00d)[local_8 * 0x30] = 2;
    if (local_8 < 5) {
      (&DAT_0067f00c)[local_8 * 0x30] = (char)local_8 + '\x01';
      (&DAT_0067f00d)[local_8 * 0x30] = 0x81;
      *(undefined4 *)(&DAT_0067f000 + local_8 * 0x30) =
           *(undefined4 *)(&DAT_0067bdf4 + local_10 * 100);
      *(undefined4 *)(&DAT_0067f004 + local_8 * 0x30) =
           *(undefined4 *)(&DAT_0067bdf8 + local_10 * 100);
    }
    bVar1 = (&DAT_0067f00d)[local_8 * 0x30];
    iVar4 = FUN_0040a1d2(2);
    if (iVar4 + 1 < (int)(uint)bVar1) {
      local_c = 0;
      for (local_20 = 0; local_20 < (int)(uint)(byte)(&DAT_0067f00d)[local_8 * 0x30];
          local_20 = local_20 + 1) {
        local_c = local_c + local_20 * 2 + 4;
      }
    }
    else {
      if ((byte)(&DAT_0067f00d)[local_8 * 0x30] < 2) {
        local_c = 0x10;
      }
      else {
        local_c = 0x1c;
      }
      (&DAT_0067f00d)[local_8 * 0x30] = (&DAT_0067f00d)[local_8 * 0x30] | 0x80;
    }
    if (*(int *)(&DAT_0067eff4 + local_8 * 0x30) == -1) {
      local_c = (local_c * 3) / 2;
    }
    if (*(int *)(&DAT_0067eff8 + local_8 * 0x30) != -1) {
      local_c = (local_c * 2) / 3;
    }
    bVar1 = (&DAT_0067f00d)[local_8 * 0x30];
    bVar2 = (&DAT_0067f00d)[local_8 * 0x30];
    iVar4 = FUN_0040a1d2(2);
    *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
         *(undefined4 *)
          (&DAT_00527e9c + ((((bVar1 & 0xc0) == 0) - 1 & 4) + (bVar2 & 0x7f) + iVar4) * 4);
    *(undefined4 *)(&DAT_0067f014 + local_8 * 0x30) = 1;
    switch((int)(local_c + (local_c >> 0x1f & 3U)) >> 2) {
    case 0:
    case 1:
    case 2:
      (&DAT_0067f00d)[local_8 * 0x30] = (&DAT_0067f00d)[local_8 * 0x30] + '\x01';
    case 3:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      cVar3 = FUN_0040a1d2(5);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      break;
    case 4:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      break;
    case 5:
      cVar3 = FUN_0040a1d2(5);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1 << (cVar3 + 4U & 0x1f);
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) = 0xffffffff;
      break;
    case 6:
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) = 0xffffffff;
    }
    if ((((&DAT_0067f015)[local_8 * 0x30] & 1) != 0) ||
       ((((&DAT_0067f00d)[local_8 * 0x30] & 0x3f) < 2 &&
        (((&DAT_0067f014)[local_8 * 0x30] & 0x20) != 0)))) {
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527e8c + (char)(&DAT_0067f00c)[local_8 * 0x30] * 4);
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffedf;
    }
    if (((&DAT_0067f00d)[local_8 * 0x30] & 0x7f) == 1) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) =
           *(uint *)(&DAT_0067f014 + local_8 * 0x30) & 0xfffffffe;
    }
    if (local_8 < 5) {
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) = *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 1;
      *(uint *)(&DAT_0067f014 + local_8 * 0x30) = *(uint *)(&DAT_0067f014 + local_8 * 0x30) | 2;
      *(undefined4 *)(&DAT_0067effc + local_8 * 0x30) =
           *(undefined4 *)(&DAT_00527ec0 + DAT_0067f380 * 4 + local_8 * 0x10);
    }
    local_8 = local_8 + 1;
  } while( true );
}


