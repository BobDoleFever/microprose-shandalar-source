/*
 * Decompiled function: ___sbh_alloc_block_from_page
 * Entry Point: 004e2a50
 * Size: 763 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___sbh_alloc_block_from_page
   
   Library: Visual Studio 1998 Debug */

int ___sbh_alloc_block_from_page(int *arg_1,uint arg_2,uint arg_3)

{
  byte *pbVar1;
  int iVar2;
  uint local_14;
  byte *local_10;
  byte *local_c;
  
  pbVar1 = (byte *)*arg_1;
  if ((uint)arg_1[1] < arg_3) {
    local_c = pbVar1;
    if (pbVar1[arg_1[1]] != 0) {
      local_c = pbVar1 + arg_1[1];
    }
    while (local_c + arg_3 < arg_1 + 0x3e) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (arg_3 <= local_14) {
          if (local_c + arg_3 < arg_1 + 0x3e) {
            *arg_1 = (int)(local_c + arg_3);
            arg_1[1] = local_14 - arg_3;
          }
          else {
            *arg_1 = (int)(arg_1 + 2);
            arg_1[1] = 0;
          }
          *local_c = (byte)arg_3;
          return (int)local_c * 0x10 + (int)arg_1 * -0xf + 0x80;
        }
        if (pbVar1 == local_c) {
          arg_1[1] = local_14;
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
    local_c = (byte *)(arg_1 + 2);
    while ((local_c < pbVar1 && (local_c + arg_3 <= (byte *)((int)arg_1 + 0xf7)))) {
      if (*local_c == 0) {
        local_14 = 1;
        local_10 = local_c;
        while (local_10 = local_10 + 1, *local_10 == 0) {
          local_14 = local_14 + 1;
        }
        if (arg_3 <= local_14) {
          if (local_c + arg_3 < arg_1 + 0x3e) {
            *arg_1 = (int)(local_c + arg_3);
            arg_1[1] = local_14 - arg_3;
          }
          else {
            *arg_1 = (int)(arg_1 + 2);
            arg_1[1] = 0;
          }
          *local_c = (byte)arg_3;
          return (int)local_c * 0x10 + (int)arg_1 * -0xf + 0x80;
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
    iVar2 = 0;
  }
  else {
    *pbVar1 = (byte)arg_3;
    if (pbVar1 + arg_3 < arg_1 + 0x3e) {
      *arg_1 = *arg_1 + arg_3;
      arg_1[1] = arg_1[1] - arg_3;
    }
    else {
      *arg_1 = (int)(arg_1 + 2);
      arg_1[1] = 0;
    }
    iVar2 = (int)pbVar1 * 0x10 + (int)arg_1 * -0xf + 0x80;
  }
  return iVar2;
}


