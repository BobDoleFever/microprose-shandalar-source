/*
 * Decompiled function: FUN_004d8cfe
 * Entry Point: 004d8cfe
 * Size: 653 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004d8cfe(undefined8 *arg_1,uint *arg_2,undefined4 arg_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  byte local_28;
  int local_14;
  uint local_c;
  int local_8;
  
  puVar1 = arg_1;
  DAT_005ddaa8 = arg_2;
  _DAT_005ddaac = arg_2;
  DAT_005ddab0 = arg_3;
  if (((uint)arg_2 & 3) == 0) {
    DAT_005093c8 = 0;
    DAT_005dcea4 = 0;
  }
  else {
    iVar2 = 4 - ((uint)arg_2 & 3);
    DAT_005093c8 = iVar2 * 8;
    DAT_005dcea4 = 0xffffffffU >> (0x20U - (char)DAT_005093c8 & 0x1f) & *arg_2;
    DAT_005ddaa8 = (uint *)((int)arg_2 + iVar2);
  }
  local_c = FUN_004d8f90(8);
  while (local_c != 0xffffffff) {
    if (*(int *)(&DAT_005dcea8 + local_c * 0xc) < 0x7fffffff) {
      uVar3 = *(uint *)(&DAT_005dceac + local_c * 0xc);
      local_28 = (byte)uVar3;
      if (*(int *)(&DAT_005dcea8 + local_c * 0xc) == -0x80000000) {
        iVar2 = FUN_004d8f90(uVar3 + 2);
        if (iVar2 < 0) break;
        uVar3 = iVar2 << (8 - local_28 & 0x1f) | (int)local_c >> (local_28 & 0x1f);
        FUN_004d7f60(arg_1,uVar3);
        arg_1 = (undefined8 *)((int)arg_1 + uVar3 * 4);
        local_c = FUN_004d8f90(8);
      }
      else {
        *(undefined4 *)arg_1 = *(undefined4 *)(&DAT_005dcea8 + local_c * 0xc);
        arg_1 = (undefined8 *)((int)arg_1 + 4);
        iVar2 = FUN_004d8f90(uVar3);
        if (iVar2 == -1) break;
        local_c = (int)local_c >> (local_28 & 0x1f) | iVar2 << (8 - local_28 & 0x1f);
      }
    }
    else {
      local_8 = *(int *)(&DAT_005dceb0 + local_c * 0xc);
      do {
        iVar2 = FUN_004d9080();
        if (iVar2 == -1) goto LAB_004d8f66;
        if (iVar2 == 0) {
          local_14 = *(int *)(&DAT_005ddac4 + local_8 * 8);
        }
        else {
          local_14 = *(int *)(&DAT_005ddac0 + local_8 * 8);
        }
        local_8 = local_14 - _DAT_005ddab8;
      } while (-1 < local_8);
      if (local_14 == 0) {
        uVar3 = FUN_004d8f90(10);
        if (-1 < (int)uVar3) {
          FUN_004d7f60(arg_1,uVar3);
          arg_1 = (undefined8 *)((int)arg_1 + uVar3 * 4);
        }
      }
      else {
        *(undefined4 *)arg_1 = *(undefined4 *)(DAT_005ddabc + local_14 * 4);
        arg_1 = (undefined8 *)((int)arg_1 + 4);
      }
LAB_004d8f66:
      local_c = FUN_004d8f90(8);
    }
  }
  return (int)arg_1 - (int)puVar1 >> 2;
}


