/*
 * Decompiled function: ___sbh_heap_check
 * Entry Point: 004066c0
 * Size: 617 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_heap_check
   
   Library: Visual Studio 1998 Debug */

int32_t ___sbh_heap_check(void)

{
  int val_1;
  int val_2;
  int32_t uval_3;
  int local_2c;
  uint32_t local_28;
  int local_24;
  uint8_t **local_20;
  int local_1c;
  int local_18;
  uint8_t *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_20 = &PTR_LOOP_00413090;
  do {
    if (local_20 == (uint8_t **)PTR_LOOP_004138a4) {
      local_c = local_c + 1;
    }
    if (local_20[0x204] != (uint8_t *)0x0) {
      local_14 = (uint8_t *)0x0;
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
              if ((int)(uint32_t)(uint8_t)(local_14 + 0x410)[(int)local_20] <= local_24) {
                return 0xfffffffc;
              }
              if (local_10 == 1) {
                if (local_24 < local_8[1]) {
                  return 0xfffffffb;
                }
                local_10 = 2;
              }
              local_24 = 0;
              val_2 = local_18;
              while (local_1c = val_2 + 1,
                    local_1c < (int)((uint32_t)*(uint8_t *)(local_18 + 8 + (int)local_8) + local_18)) {
                val_1 = val_2 + 9;
                val_2 = local_1c;
                if (*(char *)(val_1 + (int)local_8) != '\0') {
                  return 0xfffffffa;
                }
              }
              local_18 = local_1c;
            }
          }
          if ((uint8_t)(local_14 + 0x10)[(int)local_20] != local_28) {
            return 0xfffffff9;
          }
          if (local_10 == 0) {
            return 0xfffffff8;
          }
        }
        local_8 = local_8 + 0x400;
      }
    }
    local_20 = (uint8_t **)*local_20;
    if (local_20 == &PTR_LOOP_00413090) {
      if (local_c == 0) {
        uval_3 = 0xfffffff7;
      }
      else {
        uval_3 = 0;
      }
      return uval_3;
    }
  } while( true );
}


