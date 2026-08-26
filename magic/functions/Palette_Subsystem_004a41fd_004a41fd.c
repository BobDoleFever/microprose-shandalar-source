/*
 * Decompiled function: Palette_Subsystem_004a41fd
 * Entry Point: 004a41fd
 * Size: 1379 bytes
 */
#include "magic.h"


int Palette_Subsystem_004a41fd(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int arg_2;
  int arg_3;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
    for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
      (&DAT_0054bd68)[local_18 + local_10 * 0xd] = 0;
    }
  }
  Palette_Subsystem_004a4760(DAT_0054bd28,DAT_0054bd2c,0);
  local_28 = 99;
  cVar1 = '\0';
  local_20 = 1;
  local_24 = 0;
  local_8 = 0;
  for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
    for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
      if ((*(int *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) != 0) &&
         ((local_10 != DAT_0054bd28 || (local_18 != DAT_0054bd2c)))) {
        if ((&DAT_0054bd68)[local_18 + local_10 * 0xd] == '\0') {
          local_20 = 0;
        }
        local_30 = 0;
        for (local_14 = 1; local_14 < 9; local_14 = local_14 + 2) {
          if (*(int *)(&DAT_00649c20 +
                      (*(int *)(&DAT_00522378 + local_14 * 4) + local_10) * 0x34 +
                      (*(int *)(&DAT_005223e0 + local_14 * 4) + local_18) * 4) != 0) {
            local_30 = local_30 + 1;
          }
        }
        if (local_30 == 1) {
          if (((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < '\x10') || (local_18 == local_24))
          {
            local_20 = 0;
          }
          else if (local_18 != local_24) {
            local_8 = local_8 + 1;
            local_24 = local_18;
            if ((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < local_28) {
              local_28 = (int)(char)(&DAT_0054bd68)[local_18 + local_10 * 0xd];
            }
            if (cVar1 < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) {
              cVar1 = (&DAT_0054bd68)[local_18 + local_10 * 0xd];
            }
          }
        }
      }
    }
  }
  if ((local_20 != 0) && (2 < local_8)) {
    local_24 = 0;
    local_8 = 0;
    for (local_18 = 0; local_18 < 0xd; local_18 = local_18 + 1) {
      for (local_10 = 0; local_10 < 0xf; local_10 = local_10 + 1) {
        if ((*(int *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) != 0) &&
           ((local_10 != DAT_0054bd28 || (local_18 != DAT_0054bd2c)))) {
          local_2c = 0;
          local_30 = 0;
          for (local_14 = 1; local_14 < 9; local_14 = local_14 + 2) {
            if (*(int *)(&DAT_00649c20 +
                        (*(int *)(&DAT_00522378 + local_14 * 4) + local_10) * 0x34 +
                        (*(int *)(&DAT_005223e0 + local_14 * 4) + local_18) * 4) != 0) {
              local_30 = local_30 + 1;
            }
            if (*(int *)(&DAT_00649c20 +
                        ((&DAT_005223e4)[local_14] + local_18) * 4 +
                        ((&DAT_0052237c)[local_14] + local_10) * 0x34) != 0) {
              local_2c = local_2c + 1;
            }
          }
          if (local_30 == 1) {
            if ((('\x0f' < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) &&
                (local_18 != local_24)) && (local_18 != local_24)) {
              local_8 = local_8 + 1;
              local_24 = local_18;
              if ((DAT_0054bd24 < 5) && (local_8 == 1)) {
                *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                     *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | 0xf0;
              }
              else {
                *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                     *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | 0x70;
              }
            }
          }
          else {
            iVar3 = *(int *)(&DAT_0067f018 + DAT_0054bd24 * 0x30) + DAT_0067f380;
            if (2 < iVar3) {
              iVar3 = 3;
            }
            if (((((local_28 - (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd]) + 1) % (5 - iVar3)
                  == 0) && ((char)(&DAT_0054bd68)[local_18 + local_10 * 0xd] < cVar1)) &&
               ('\a' < (char)(&DAT_0054bd68)[local_18 + local_10 * 0xd])) {
              arg_3 = 6;
              arg_2 = 0;
              cVar2 = (&DAT_0054bd68)[local_18 + local_10 * 0xd];
              iVar3 = FUN_0040a1d2(6);
              local_1c = FUN_0040a305(((int)((cVar2 - local_28) + (cVar2 - local_28 >> 0x1f & 3U))
                                      >> 2) + -2 + iVar3 + local_2c + local_30,arg_2,arg_3);
              iVar3 = FUN_0040a1d2(DAT_0067f380 + 3);
              if (iVar3 == 0) {
                local_1c = 1;
              }
              *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) =
                   *(uint *)(&DAT_00649c20 + local_18 * 4 + local_10 * 0x34) | local_1c << 4;
            }
          }
        }
      }
    }
    local_20 = 2;
  }
  return local_20;
}


