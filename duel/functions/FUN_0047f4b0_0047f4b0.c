/*
 * Decompiled function: FUN_0047f4b0
 * Entry Point: 0047f4b0
 * Size: 567 bytes
 */
#include "duel.h"


undefined4 FUN_0047f4b0(int arg1,int *arg2)

{
  int *arg_2;
  uint *puVar1;
  int iVar2;
  int arg_3;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  void *ptr_1;
  void *ptr_1_00;
  int local_28;
  void *local_18;
  
  iVar3 = arg2[7] / (int)(2 - (uint)(arg2[10] == 1));
  iVar4 = iVar3 / (int)(2 - (uint)(*arg2 == 0));
  iVar2 = arg2[9];
  arg_3 = *(int *)arg2[0x68];
  arg_2 = (int *)arg2[0x68] + 1;
  *arg_2 = -0x80000000;
  iVar5 = FUN_004d85eb(arg_2 + arg_3,arg_2,arg_3);
  local_18 = (void *)((int)(arg_2 + arg_3) + iVar5);
  for (local_28 = 0; local_28 < arg2[10]; local_28 = local_28 + 1) {
    pvVar6 = (void *)((iVar3 * iVar3 + iVar4 * iVar4 * 2 + 0x40) * local_28 * 4 + arg1);
    ptr_1 = (void *)((int)pvVar6 + iVar3 * iVar3 * 4 + 0x80);
    ptr_1_00 = (void *)((int)ptr_1 + iVar4 * iVar4 * 4 + 0x80);
    FID_conflict__memcpy(pvVar6,local_18,iVar2 * iVar2 * 4);
    puVar1 = (uint *)((int)local_18 + iVar2 * iVar2 * 4);
    FUN_004d8cfe((undefined8 *)((int)pvVar6 + iVar2 * iVar2 * 4),puVar1,arg2[local_28 + 0x17]);
    pvVar6 = (void *)((int)puVar1 + arg2[local_28 + 0x17]);
    FID_conflict__memcpy(ptr_1,pvVar6,iVar2 * iVar2 * 4);
    puVar1 = (uint *)((int)pvVar6 + iVar2 * iVar2 * 4);
    FUN_004d8cfe((undefined8 *)((int)ptr_1 + iVar2 * iVar2 * 4),puVar1,arg2[local_28 + 0x1b]);
    pvVar6 = (void *)((int)puVar1 + arg2[local_28 + 0x1b]);
    FID_conflict__memcpy(ptr_1_00,pvVar6,iVar2 * iVar2 * 4);
    puVar1 = (uint *)((int)pvVar6 + iVar2 * iVar2 * 4);
    FUN_004d8cfe((undefined8 *)((int)ptr_1_00 + iVar2 * iVar2 * 4),puVar1,arg2[local_28 + 0x1f]);
    local_18 = (void *)((int)puVar1 + arg2[local_28 + 0x1f]);
  }
  return 0;
}


