/*
 * Decompiled function: FUN_00435343
 * Entry Point: 00435343
 * Size: 371 bytes
 */
#include "duel.h"


uint FUN_00435343(uint arg_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int local_34;
  uint local_2c;
  int local_28;
  
  FUN_0043504d(arg_1,(uint *)&DAT_005162c0);
  pbVar5 = &DAT_005162c0;
  piVar3 = DAT_005162b4;
  do {
    piVar1 = (int *)piVar3[*pbVar5 + 2];
    pbVar5 = pbVar5 + 1;
    if (piVar1 == (int *)0x0) {
      if (*piVar3 == 0) {
        iVar2 = piVar3[10];
        local_34 = 0x7fffffff;
        for (local_28 = 0; local_28 < piVar3[0xb]; local_28 = local_28 + 1) {
          iVar4 = *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 >> 8 & 0xff) -
                          (uint)(byte)(&DAT_005162d1)[(uint)*(byte *)(local_28 + iVar2) * 4]) * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 & 0xff) -
                          ((*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) &
                           0xff0000) >> 0x10)) * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          (((arg_1 & 0xff0000) >> 0x10) -
                          (*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) & 0xff))
                          * 4);
          if (iVar4 < local_34) {
            local_2c = (uint)*(byte *)(local_28 + iVar2);
            local_34 = iVar4;
          }
        }
        return local_2c;
      }
      return piVar3[1];
    }
    piVar3 = piVar1;
  } while ((char)*piVar1 != '\x01');
  return piVar1[1];
}


