/*
 * Decompiled function: FUN_00479e13
 * Entry Point: 00479e13
 * Size: 396 bytes
 */
#include "duel.h"


int FUN_00479e13(int arg1,int arg2)

{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_8;
  
  iVar1 = *(int *)(&DAT_006826c4 + arg2 * 0x120 + arg1 * 0x5b20);
  local_20 = FUN_0048b81a(arg1,arg2,0x32,0xffffffff);
  local_24 = FUN_0048b81a(arg1,arg2,0x33,0xffffffff);
  if (local_20 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = local_20 + 5;
  }
  if (local_24 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = local_24 + 5;
  }
  iVar2 = (*(int *)(&DAT_004ff5b0 + iVar1 * 0x34) + local_20 + 2) * (local_24 + 2);
  local_8 = iVar2 * 5;
  if (((&DAT_004ff5a5)[iVar1 * 0x34] & 2) != 0) {
    local_8 = (iVar2 * 0xf) / 2;
  }
  if (((&DAT_004ff5a8)[iVar1 * 0x34] & 3) != 0) {
    local_8 = local_8 / 2;
  }
  if (((&DAT_004ff5a4)[iVar1 * 0x34] & 0x20) != 0) {
    local_8 = (local_8 * 3) / 2;
  }
  if (((&DAT_004ff5a8)[iVar1 * 0x34] & 8) != 0) {
    local_8 = local_8 * 3;
  }
  if (((&DAT_004ff5a8)[iVar1 * 0x34] & 0x10) != 0) {
    local_8 = local_8 * 3;
  }
  return local_8;
}


