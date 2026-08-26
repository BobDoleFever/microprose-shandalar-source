/*
 * Decompiled function: __strnicmp
 * Entry Point: 004eedf0
 * Size: 173 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __strnicmp(char *str_1,char *str_2,size_t arg_3)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint arg_1;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  iVar4 = 0;
  if (arg_3 != 0) {
    if (DAT_0050a730 == 0) {
      do {
        bVar2 = *str_1;
        cVar1 = *str_2;
        uVar3 = CONCAT11(bVar2,cVar1);
        if (bVar2 == 0) break;
        uVar3 = CONCAT11(bVar2,cVar1);
        uVar5 = (uint)uVar3;
        if (cVar1 == '\0') break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar5 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
        }
        uVar3 = (ushort)uVar5;
        bVar2 = (byte)uVar5;
        if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
          uVar3 = (ushort)CONCAT31((int3)(uVar5 >> 8),bVar2 + 0x20);
        }
        bVar2 = (byte)(uVar3 >> 8);
        bVar6 = bVar2 < (byte)uVar3;
        if (bVar2 != (byte)uVar3) goto LAB_004eee4b;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      iVar4 = 0;
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) {
LAB_004eee4b:
        iVar4 = -1;
        if (!bVar6) {
          iVar4 = 1;
        }
      }
    }
    else {
      uVar5 = 0;
      arg_1 = 0;
      do {
        arg_1 = CONCAT31((int3)(arg_1 >> 8),*str_1);
        uVar5 = CONCAT31((int3)(uVar5 >> 8),*str_2);
        if ((arg_1 == 0) || (uVar5 == 0)) break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        uVar5 = _tolower(uVar5);
        arg_1 = _tolower(arg_1);
        bVar6 = arg_1 < uVar5;
        if (arg_1 != uVar5) goto LAB_004eee8d;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      iVar4 = 0;
      bVar6 = arg_1 < uVar5;
      if (arg_1 != uVar5) {
LAB_004eee8d:
        iVar4 = -1;
        if (!bVar6) {
          iVar4 = 1;
        }
      }
    }
  }
  return iVar4;
}


