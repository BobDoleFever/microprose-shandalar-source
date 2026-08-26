/*
 * Decompiled function: ___sbh_alloc_block_from_page
 * Entry Point: 00406200
 * Size: 763 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_alloc_block_from_page
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___sbh_alloc_block_from_page(int *ptr_1,uint32_t arg_2,uint32_t arg_3)

{
  uint8_t *pbVar1;
  int val_2;
  uint32_t local_14;
  uint8_t *local_10;
  uint8_t *local_c;
  
  pbVar1 = (uint8_t *)*ptr_1;
  if ((uint32_t)ptr_1[1] < arg_3) {
    local_c = pbVar1;
    if (pbVar1[ptr_1[1]] != 0) {
      local_c = pbVar1 + ptr_1[1];
    }
    while (local_c + arg_3 < ptr_1 + 0x3e) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (arg_3 <= local_14) {
          if (local_c + arg_3 < ptr_1 + 0x3e) {
            *ptr_1 = (int)(local_c + arg_3);
            ptr_1[1] = local_14 - arg_3;
          }
          else {
            *ptr_1 = (int)(ptr_1 + 2);
            ptr_1[1] = 0;
          }
          *local_c = (uint8_t)arg_3;
          return (int)local_c * 0x10 + (int)ptr_1 * -0xf + 0x80;
        }
        if (pbVar1 == local_c) {
          ptr_1[1] = local_14;
        }
        else {
          arg_2 = arg_2 - local_14;
          if (arg_2 < arg_3) {
            return 0;
          }
        }
        local_c = local_10;
      }
      else {
        local_c = local_c + *local_c;
      }
    }
    local_c = (uint8_t *)(ptr_1 + 2);
    while ((local_c < pbVar1 && (local_c + arg_3 <= (uint8_t *)((int)ptr_1 + 0xf7)))) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (arg_3 <= local_14) {
          if (local_c + arg_3 < ptr_1 + 0x3e) {
            *ptr_1 = (int)(local_c + arg_3);
            ptr_1[1] = local_14 - arg_3;
          }
          else {
            *ptr_1 = (int)(ptr_1 + 2);
            ptr_1[1] = 0;
          }
          *local_c = (uint8_t)arg_3;
          return (int)local_c * 0x10 + (int)ptr_1 * -0xf + 0x80;
        }
        arg_2 = arg_2 - local_14;
        if (arg_2 < arg_3) {
          return 0;
        }
        local_c = local_10;
      }
      else {
        local_c = local_c + *local_c;
      }
    }
    val_2 = 0;
  }
  else {
    *pbVar1 = (uint8_t)arg_3;
    if (pbVar1 + arg_3 < ptr_1 + 0x3e) {
      *ptr_1 = *ptr_1 + arg_3;
      ptr_1[1] = ptr_1[1] - arg_3;
    }
    else {
      *ptr_1 = (int)(ptr_1 + 2);
      ptr_1[1] = 0;
    }
    val_2 = (int)pbVar1 * 0x10 + (int)ptr_1 * -0xf + 0x80;
  }
  return val_2;
}


