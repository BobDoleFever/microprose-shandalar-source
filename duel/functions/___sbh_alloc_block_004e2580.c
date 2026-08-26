/*
 * Decompiled function: ___sbh_alloc_block
 * Entry Point: 004e2580
 * Size: 1207 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 1998 Debug */

undefined * ___sbh_alloc_block(uint arg_1)

{
  int *piVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined **local_18;
  undefined *local_14;
  undefined *local_10;
  undefined4 *local_8;
  
  local_18 = (undefined **)PTR_LOOP_0050a1f4;
  do {
    if (local_18[0x204] != (undefined *)0x0) {
      for (local_10 = local_18[2]; (int)local_10 < 0x400;
          local_10 = (undefined *)((int)local_10 + 1)) {
        if (((arg_1 <= *(byte *)((int)local_10 + 0x10 + (int)local_18)) &&
            (*(char *)((int)local_10 + 0x10 + (int)local_18) != -1)) &&
           (arg_1 < *(byte *)((int)local_10 + 0x410 + (int)local_18))) {
          puVar2 = (undefined *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)local_18[0x204] + (int)local_10 * 0x1000),
                              (uint)*(byte *)((int)local_10 + 0x10 + (int)local_18),arg_1);
          if (puVar2 != (undefined *)0x0) {
            PTR_LOOP_0050a1f4 = (undefined *)local_18;
            *(char *)((int)local_10 + 0x10 + (int)local_18) =
                 *(char *)((int)local_10 + 0x10 + (int)local_18) - (char)arg_1;
            local_18[2] = local_10;
            return puVar2;
          }
          *(char *)((int)local_10 + 0x410 + (int)local_18) = (char)arg_1;
        }
      }
      for (local_10 = (undefined *)0x0; (int)local_10 < (int)local_18[2];
          local_10 = (undefined *)((int)local_10 + 1)) {
        if (((arg_1 <= *(byte *)((int)local_10 + 0x10 + (int)local_18)) &&
            (*(char *)((int)local_10 + 0x10 + (int)local_18) != -1)) &&
           (arg_1 < *(byte *)((int)local_10 + 0x410 + (int)local_18))) {
          puVar2 = (undefined *)
                   ___sbh_alloc_block_from_page
                             ((int *)((int)local_18[0x204] + (int)local_10 * 0x1000),
                              (uint)*(byte *)((int)local_10 + 0x10 + (int)local_18),arg_1);
          if (puVar2 != (undefined *)0x0) {
            PTR_LOOP_0050a1f4 = (undefined *)local_18;
            *(char *)((int)local_10 + 0x10 + (int)local_18) =
                 *(char *)((int)local_10 + 0x10 + (int)local_18) - (char)arg_1;
            local_18[2] = local_10;
            return puVar2;
          }
          *(char *)((int)local_10 + 0x410 + (int)local_18) = (char)arg_1;
        }
      }
    }
    local_18 = (undefined **)*local_18;
  } while (local_18 != (undefined **)PTR_LOOP_0050a1f4);
  local_18 = &PTR_LOOP_005099e0;
  while ((local_18[0x204] == (undefined *)0x0 || (local_18[3] == (undefined *)0xffffffff))) {
    local_18 = (undefined **)*local_18;
    if (local_18 == &PTR_LOOP_005099e0) {
      puVar2 = (undefined *)___sbh_new_region();
      if (puVar2 != (undefined *)0x0) {
        piVar1 = *(int **)(puVar2 + 0x810);
        *(char *)(piVar1 + 2) = (char)arg_1;
        PTR_LOOP_0050a1f4 = puVar2;
        *piVar1 = (int)piVar1 + arg_1 + 8;
        piVar1[1] = 0xf0 - arg_1;
        puVar2[0x10] = puVar2[0x10] - (char)arg_1;
        return (undefined *)(*(int *)(puVar2 + 0x810) + 0x100);
      }
      return (undefined *)0x0;
    }
  }
  puVar2 = local_18[3];
  puVar3 = puVar2 + 0x10;
  if (0x3ff < (int)puVar3) {
    puVar3 = (undefined *)0x400;
  }
  do {
    local_10 = puVar2 + 1;
    if ((int)puVar3 <= (int)local_10) break;
    puVar4 = puVar2 + 0x11;
    puVar2 = local_10;
  } while (puVar4[(int)local_18] == -1);
  puVar2 = local_18[3];
  puVar3 = local_18[0x204];
  puVar4 = VirtualAlloc(local_18[0x204] + (int)local_18[3] * 0x1000,
                        ((int)local_10 - (int)local_18[3]) * 0x1000,0x1000,4);
  if (puVar3 + (int)puVar2 * 0x1000 == puVar4) {
    local_14 = local_18[3];
    local_8 = (undefined4 *)(local_18[0x204] + (int)local_14 * 0x1000);
    for (; (int)local_14 < (int)local_10; local_14 = local_14 + 1) {
      _memset(local_8,0x1000,0);
      *local_8 = local_8 + 2;
      local_8[1] = 0xf0;
      *(undefined1 *)(local_8 + 0x3e) = 0xff;
      (local_14 + 0x10)[(int)local_18] = 0xf0;
      (local_14 + 0x410)[(int)local_18] = 0xf1;
      local_8 = local_8 + 0x400;
    }
    PTR_LOOP_0050a1f4 = (undefined *)local_18;
    for (; ((int)local_10 < 0x400 && ((local_10 + 0x10)[(int)local_18] != -1));
        local_10 = local_10 + 1) {
    }
    puVar2 = local_18[3];
    if ((int)local_10 < 0x400) {
      local_18[3] = local_10;
    }
    else {
      local_18[3] = (undefined *)0xffffffff;
    }
    puVar5 = (undefined4 *)(local_18[0x204] + (int)puVar2 * 0x1000);
    *(char *)(puVar5 + 2) = (char)arg_1;
    local_18[2] = puVar2;
    (puVar2 + 0x10)[(int)local_18] = (puVar2 + 0x10)[(int)local_18] - (char)arg_1;
    *puVar5 = (undefined *)((int)puVar5 + arg_1 + 8);
    puVar5[1] = puVar5[1] - arg_1;
    puVar2 = local_18[0x204] + (int)puVar2 * 0x1000 + 0x100;
  }
  else {
    puVar2 = (undefined *)0x0;
  }
  return puVar2;
}


