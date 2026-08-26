/*
 * Decompiled function: FUN_0046b04a
 * Entry Point: 0046b04a
 * Size: 924 bytes
 */
#include "magic.h"


uint FUN_0046b04a(int arg1,int arg2)

{
  uint local_10c;
  int local_108;
  char local_104 [256];
  
  local_10c = 0;
  if (*(int *)(arg2 + 4) == *(int *)(arg1 + 4)) {
    if (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x30000) & 0x30000) != 0) {
      local_10c = 2;
    }
    if (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x10) & 0x10) != 0) {
      local_10c = local_10c | 8;
    }
    if (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x1000) & 0x1000) != 0) {
      local_10c = local_10c | 0x10;
    }
    if (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x200000) & 0x200000) != 0) {
      local_10c = local_10c | 0x20;
    }
    if (((*(uint *)(arg2 + 0xc) ^ *(uint *)(arg1 + 0xc) & 0x100000) & 0x100000) != 0) {
      local_10c = local_10c | 0x40;
    }
    if (*(short *)(arg2 + 0x10) != *(short *)(arg1 + 0x10)) {
      local_10c = local_10c | 0x80;
    }
    if (*(short *)(arg2 + 0x14) != *(short *)(arg1 + 0x14)) {
      local_10c = local_10c | 0x100;
    }
    if (*(short *)(arg2 + 0x16) != *(short *)(arg1 + 0x16)) {
      local_10c = local_10c | 0x200;
    }
    if (*(char *)(arg2 + 0x1c) != *(char *)(arg1 + 0x1c)) {
      local_10c = local_10c | 0x400;
    }
    if (*(char *)(arg2 + 0x1d) != *(char *)(arg1 + 0x1d)) {
      local_10c = local_10c | 0x800;
    }
    if (*(char *)(arg1 + 0x1e) != *(char *)(arg2 + 0x1e)) {
      local_10c = local_10c | 0x1000;
    }
    if (*(int *)(arg2 + 0x24) != *(int *)(arg1 + 0x24)) {
      local_10c = local_10c | 0x4000;
    }
    if (*(int *)(arg2 + 0x4c) != *(int *)(arg1 + 0x4c)) {
      local_10c = local_10c | 0x8000;
    }
    if (((*(uint *)(arg1 + 0x38) ^ *(uint *)(arg2 + 0x38) & 0x20000) & 0x20000) != 0) {
      local_10c = local_10c | 0x10000;
    }
    if (*(int *)(arg2 + 0x44) != *(int *)(arg1 + 0x44)) {
      local_10c = local_10c | 0x20000;
    }
    if (*(int *)(arg2 + 0x108) != *(int *)(arg1 + 0x108)) {
      local_10c = local_10c | 0x40000;
    }
    if (*(char *)(arg2 + 0x20) != *(char *)(arg1 + 0x20)) {
      local_10c = local_10c | 0x80000;
    }
  }
  else {
    local_10c = 1;
  }
  sprintf(local_104,s__s__s_00524dbc,s_Swamp_0051aea9 + *(int *)(arg1 + 4) * 0x34,
          s_Swamp_0051aea9 + *(int *)(arg2 + 4) * 0x34);
  OutputDebugStringA(local_104);
  for (local_108 = 0; local_108 < 0x20; local_108 = local_108 + 1) {
    if ((local_10c & 1 << ((byte)local_108 & 0x1f)) != 0) {
      if (local_108 == 0) {
        sprintf(local_104,s__s__d__d_00524dc8,PTR_s_Type_005247d0,*(undefined4 *)(arg1 + 4),
                *(undefined4 *)(arg2 + 4));
      }
      else {
        sprintf(local_104,&DAT_00524dd4,(&PTR_s_Type_005247d0)[local_108]);
      }
      OutputDebugStringA(local_104);
    }
  }
  return local_10c;
}


