/*
 * Decompiled function: __ld12cvt
 * Entry Point: 004eae70
 * Size: 616 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 1998 Debug */

undefined4 __ld12cvt(ushort *arg_1,uint *arg_2,int *arg_3)

{
  int iVar1;
  undefined4 local_34 [4];
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  byte local_10;
  int local_c;
  int local_8;
  
  local_8 = (arg_1[5] & 0x7fff) - 0x3fff;
  local_24 = arg_1[5] & 0x8000;
  local_1c = *(uint *)(arg_1 + 3);
  local_18 = *(uint *)(arg_1 + 1);
  local_14 = (uint)*arg_1 << 0x10;
  if (local_8 == -0x3fff) {
    local_c = 0;
    iVar1 = __IsZeroMan((int)&local_1c);
    if (iVar1 == 0) {
      __FillZeroMan((int)&local_1c);
      local_20 = 2;
    }
    else {
      local_20 = 0;
    }
  }
  else {
    __CopyMan(local_34,&local_1c);
    iVar1 = __RoundMan((int)&local_1c,arg_3[2]);
    if (iVar1 != 0) {
      local_8 = local_8 + 1;
    }
    if (local_8 < arg_3[1] - arg_3[2]) {
      __FillZeroMan((int)&local_1c);
      local_c = 0;
      local_20 = 2;
    }
    else if (arg_3[1] < local_8) {
      if (local_8 < *arg_3) {
        local_c = arg_3[5] + local_8;
        local_1c = local_1c & 0x7fffffff;
        __ShrMan((int)&local_1c,arg_3[3]);
        local_20 = 0;
      }
      else {
        __FillZeroMan((int)&local_1c);
        local_1c = local_1c | 0x80000000;
        __ShrMan((int)&local_1c,arg_3[3]);
        local_c = arg_3[5] + *arg_3;
        local_20 = 1;
      }
    }
    else {
      iVar1 = arg_3[1] - local_8;
      __CopyMan(&local_1c,local_34);
      __ShrMan((int)&local_1c,iVar1);
      __RoundMan((int)&local_1c,arg_3[2]);
      __ShrMan((int)&local_1c,arg_3[3] + 1);
      local_c = 0;
      local_20 = 2;
    }
  }
  local_10 = 0x20 - ((char)arg_3[3] + '\x01');
  local_1c = (local_24 == 0) - 1 & 0x80000000 | local_c << (local_10 & 0x1f) | local_1c;
  if (arg_3[4] == 0x40) {
    arg_2[1] = local_1c;
    *arg_2 = local_18;
  }
  else if (arg_3[4] == 0x20) {
    *arg_2 = local_1c;
  }
  return local_20;
}


