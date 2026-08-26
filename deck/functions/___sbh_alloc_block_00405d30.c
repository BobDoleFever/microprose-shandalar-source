/*
 * Decompiled function: ___sbh_alloc_block
 * Entry Point: 00405d30
 * Size: 1207 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Debug */

uint8_t * __cdecl ___sbh_alloc_block(uint32_t arg_1)

{
  uint8_t *u_ptr_1;
  uint8_t *u_ptr_2;
  uint8_t *u_ptr_3;
  int32_t *puVar4;
  uint8_t **ppuVar5;
  uint8_t **local_18;
  uint8_t *local_14;
  uint8_t *local_10;
  int32_t *local_8;
  
  local_18 = (uint8_t **)PTR_LOOP_004138a4;
  do {
    if (local_18[0x204] != (uint8_t *)0x0) {
      for (local_10 = local_18[2]; (int)local_10 < 0x400;
          local_10 = (uint8_t *)((int)local_10 + 1)) {
        if (((arg_1 <= *(uint8_t *)((int)local_10 + 0x10 + (int)local_18)) &&
            (*(char *)((int)local_10 + 0x10 + (int)local_18) != -1)) &&
           (arg_1 < *(uint8_t *)((int)local_10 + 0x410 + (int)local_18))) {
          u_ptr_1 = (uint8_t *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)local_18[0x204] + (int)local_10 * 0x1000),
                              (uint32_t)*(uint8_t *)((int)local_10 + 0x10 + (int)local_18),arg_1);
          if (u_ptr_1 != (uint8_t *)0x0) {
            PTR_LOOP_004138a4 = (uint8_t *)local_18;
            *(char *)((int)local_10 + 0x10 + (int)local_18) =
                 *(char *)((int)local_10 + 0x10 + (int)local_18) - (char)arg_1;
            local_18[2] = local_10;
            return u_ptr_1;
          }
          *(char *)((int)local_10 + 0x410 + (int)local_18) = (char)arg_1;
        }
      }
      for (local_10 = (uint8_t *)0x0; (int)local_10 < (int)local_18[2];
          local_10 = (uint8_t *)((int)local_10 + 1)) {
        if (((arg_1 <= *(uint8_t *)((int)local_10 + 0x10 + (int)local_18)) &&
            (*(char *)((int)local_10 + 0x10 + (int)local_18) != -1)) &&
           (arg_1 < *(uint8_t *)((int)local_10 + 0x410 + (int)local_18))) {
          u_ptr_1 = (uint8_t *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)local_18[0x204] + (int)local_10 * 0x1000),
                              (uint32_t)*(uint8_t *)((int)local_10 + 0x10 + (int)local_18),arg_1);
          if (u_ptr_1 != (uint8_t *)0x0) {
            PTR_LOOP_004138a4 = (uint8_t *)local_18;
            *(char *)((int)local_10 + 0x10 + (int)local_18) =
                 *(char *)((int)local_10 + 0x10 + (int)local_18) - (char)arg_1;
            local_18[2] = local_10;
            return u_ptr_1;
          }
          *(char *)((int)local_10 + 0x410 + (int)local_18) = (char)arg_1;
        }
      }
    }
    local_18 = (uint8_t **)*local_18;
  } while (local_18 != (uint8_t **)PTR_LOOP_004138a4);
  local_18 = &PTR_LOOP_00413090;
  while ((local_18[0x204] == (uint8_t *)0x0 || (local_18[3] == (uint8_t *)0xffffffff))) {
    local_18 = (uint8_t **)*local_18;
    if (local_18 == &PTR_LOOP_00413090) {
      ppuVar5 = ___sbh_new_region();
      if (ppuVar5 != (uint8_t **)0x0) {
        puVar4 = (int32_t *)ppuVar5[0x204];
        *(char *)(puVar4 + 2) = (char)arg_1;
        PTR_LOOP_004138a4 = (uint8_t *)ppuVar5;
        *puVar4 = (uint8_t *)((int)puVar4 + arg_1 + 8);
        puVar4[1] = 0xf0 - arg_1;
        *(char *)(ppuVar5 + 4) = *(char *)(ppuVar5 + 4) - (char)arg_1;
        return ppuVar5[0x204] + 0x100;
      }
      return (uint8_t *)0x0;
    }
  }
  u_ptr_1 = local_18[3];
  u_ptr_2 = u_ptr_1 + 0x10;
  if (0x3ff < (int)u_ptr_2) {
    u_ptr_2 = (uint8_t *)0x400;
  }
  do {
    local_10 = u_ptr_1 + 1;
    if ((int)u_ptr_2 <= (int)local_10) break;
    u_ptr_3 = u_ptr_1 + 0x11;
    u_ptr_1 = local_10;
  } while (u_ptr_3[(int)local_18] == -1);
  u_ptr_1 = local_18[3];
  u_ptr_2 = local_18[0x204];
  u_ptr_3 = VirtualAlloc(local_18[0x204] + (int)local_18[3] * 0x1000,
                        ((int)local_10 - (int)local_18[3]) * 0x1000,0x1000,4);
  if (u_ptr_2 + (int)u_ptr_1 * 0x1000 == u_ptr_3) {
    local_14 = local_18[3];
    local_8 = (int32_t *)(local_18[0x204] + (int)local_14 * 0x1000);
    for (; (int)local_14 < (int)local_10; local_14 = local_14 + 1) {
      _memset(local_8,0x1000,0);
      *local_8 = local_8 + 2;
      local_8[1] = 0xf0;
      *(uint8_t *)(local_8 + 0x3e) = 0xff;
      (local_14 + 0x10)[(int)local_18] = 0xf0;
      (local_14 + 0x410)[(int)local_18] = 0xf1;
      local_8 = local_8 + 0x400;
    }
    PTR_LOOP_004138a4 = (uint8_t *)local_18;
    for (; ((int)local_10 < 0x400 && ((local_10 + 0x10)[(int)local_18] != -1));
        local_10 = local_10 + 1) {
    }
    u_ptr_1 = local_18[3];
    if ((int)local_10 < 0x400) {
      local_18[3] = local_10;
    }
    else {
      local_18[3] = (uint8_t *)0xffffffff;
    }
    puVar4 = (int32_t *)(local_18[0x204] + (int)u_ptr_1 * 0x1000);
    *(char *)(puVar4 + 2) = (char)arg_1;
    local_18[2] = u_ptr_1;
    (u_ptr_1 + 0x10)[(int)local_18] = (u_ptr_1 + 0x10)[(int)local_18] - (char)arg_1;
    *puVar4 = (uint8_t *)((int)puVar4 + arg_1 + 8);
    puVar4[1] = puVar4[1] - arg_1;
    u_ptr_1 = local_18[0x204] + (int)u_ptr_1 * 0x1000 + 0x100;
  }
  else {
    u_ptr_1 = (uint8_t *)0x0;
  }
  return u_ptr_1;
}


