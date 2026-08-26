/*
 * Decompiled function: ___sbh_heap_check
 * Entry Point: 004e2f10
 * Size: 617 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_heap_check
   
   Library: Visual Studio 1998 Debug */

undefined4 ___sbh_heap_check(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_2c;
  uint local_28;
  int local_24;
  undefined **local_20;
  int local_1c;
  int local_18;
  undefined *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_20 = &PTR_LOOP_005099e0;
  do {
    if (local_20 == (undefined **)PTR_LOOP_0050a1f4) {
      local_c = local_c + 1;
    }
    if (local_20[0x204] != (undefined *)0x0) {
      local_14 = (undefined *)0x0;
      local_2c = 0;
      local_8 = (int *)local_20[0x204];
      for (; (int)local_14 < 0x400; local_14 = local_14 + 1) {
        if ((local_14 + 0x10)[(int)local_20] == -1) {
          if ((local_2c == 0) && (local_20[3] != local_14)) {
            return 0xffffffff;
          }
          local_2c = local_2c + 1;
        }
        else {
          if (local_8 + 0x3e <= (int *)*local_8) {
            return 0xfffffffe;
          }
          if ((char)local_8[0x3e] != -1) {
            return 0xfffffffd;
          }
          local_18 = 0;
          local_10 = 0;
          local_28 = 0;
          local_24 = 0;
          while (local_18 < 0xf0) {
            if ((int)local_8 + local_18 + 8 == *local_8) {
              local_10 = local_10 + 1;
            }
            if (*(char *)(local_18 + 8 + (int)local_8) == '\0') {
              local_28 = local_28 + 1;
              local_24 = local_24 + 1;
              local_18 = local_18 + 1;
            }
            else {
              if ((int)(uint)(byte)(local_14 + 0x410)[(int)local_20] <= local_24) {
                return 0xfffffffc;
              }
              if (local_10 == 1) {
                if (local_24 < local_8[1]) {
                  return 0xfffffffb;
                }
                local_10 = 2;
              }
              local_24 = 0;
              iVar2 = local_18;
              while (local_1c = iVar2 + 1,
                    local_1c < (int)((uint)*(byte *)(local_18 + 8 + (int)local_8) + local_18)) {
                iVar1 = iVar2 + 9;
                iVar2 = local_1c;
                if (*(char *)(iVar1 + (int)local_8) != '\0') {
                  return 0xfffffffa;
                }
              }
              local_18 = local_1c;
            }
          }
          if ((byte)(local_14 + 0x10)[(int)local_20] != local_28) {
            return 0xfffffff9;
          }
          if (local_10 == 0) {
            return 0xfffffff8;
          }
        }
        local_8 = local_8 + 0x400;
      }
    }
    local_20 = (undefined **)*local_20;
    if (local_20 == &PTR_LOOP_005099e0) {
      if (local_c == 0) {
        uVar3 = 0xfffffff7;
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
  } while( true );
}


