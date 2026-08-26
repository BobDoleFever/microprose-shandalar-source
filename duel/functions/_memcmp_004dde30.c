/*
 * Decompiled function: _memcmp
 * Entry Point: 004dde30
 * Size: 172 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _memcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _memcmp(void *ptr_1,void *ptr_2,size_t arg_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  bool bVar9;
  
  if (arg_3 != 0) {
    if ((((uint)ptr_1 | (uint)ptr_2) & 3) == 0) {
      uVar2 = arg_3 & 3;
      uVar5 = arg_3 >> 2;
      bVar9 = false;
      puVar7 = ptr_1;
      puVar8 = ptr_2;
      if (uVar5 != 0) {
        do {
          ptr_1 = puVar7;
          ptr_2 = puVar8;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          ptr_2 = puVar8 + 1;
          ptr_1 = puVar7 + 1;
          bVar9 = *puVar7 == *puVar8;
          puVar7 = ptr_1;
          puVar8 = ptr_2;
        } while (bVar9);
        if (!bVar9) {
          uVar2 = *(uint *)((int)ptr_1 + -4);
          uVar5 = *(uint *)((int)ptr_2 + -4);
          bVar9 = (byte)uVar2 < (byte)uVar5;
          if ((((byte)uVar2 == (byte)uVar5) &&
              (bVar4 = (byte)(uVar2 >> 8), bVar6 = (byte)(uVar5 >> 8), bVar9 = bVar4 < bVar6,
              bVar4 == bVar6)) &&
             (bVar4 = (byte)(uVar2 >> 0x10), bVar6 = (byte)(uVar5 >> 0x10), bVar9 = bVar4 < bVar6,
             bVar4 == bVar6)) {
            bVar9 = (byte)(uVar2 >> 0x18) < (byte)(uVar5 >> 0x18);
          }
          goto LAB_004ddeaa;
        }
      }
      if (uVar2 != 0) {
        uVar5 = *(uint *)ptr_1;
        uVar1 = *(uint *)ptr_2;
        bVar9 = (byte)uVar5 < (byte)uVar1;
        if ((byte)uVar5 != (byte)uVar1) {
LAB_004ddeaa:
          return (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        iVar3 = 0;
        if (uVar2 != 1) {
          bVar6 = (byte)(uVar5 >> 8);
          bVar4 = (byte)(uVar1 >> 8);
          bVar9 = bVar6 < bVar4;
          if (bVar6 != bVar4) goto LAB_004ddeaa;
          iVar3 = 0;
          if (uVar2 != 2) {
            bVar9 = (uVar5 & 0xff0000) < (uVar1 & 0xff0000);
            if ((uVar5 & 0xff0000) != (uVar1 & 0xff0000)) goto LAB_004ddeaa;
            iVar3 = uVar2 - 3;
          }
        }
        return iVar3;
      }
    }
    else {
      if ((arg_3 & 1) == 0) goto LAB_004dde5d;
      bVar9 = *(byte *)ptr_1 < *(byte *)ptr_2;
      if (*(byte *)ptr_1 != *(byte *)ptr_2) goto LAB_004ddeaa;
      ptr_1 = (void *)((int)ptr_1 + 1);
      ptr_2 = (void *)((int)ptr_2 + 1);
      for (arg_3 = arg_3 - 1; arg_3 != 0; arg_3 = arg_3 - 2) {
LAB_004dde5d:
        bVar9 = *(byte *)ptr_1 < *(byte *)ptr_2;
        if ((*(byte *)ptr_1 != *(byte *)ptr_2) ||
           (bVar9 = *(byte *)((int)ptr_1 + 1) < *(byte *)((int)ptr_2 + 1),
           *(byte *)((int)ptr_1 + 1) != *(byte *)((int)ptr_2 + 1))) goto LAB_004ddeaa;
        ptr_2 = (void *)((int)ptr_2 + 2);
        ptr_1 = (void *)((int)ptr_1 + 2);
      }
    }
  }
  return 0;
}


