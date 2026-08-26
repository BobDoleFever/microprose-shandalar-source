/*
 * Decompiled function: _strcmp
 * Entry Point: 004d9920
 * Size: 129 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strcmp
   
   Library: Visual Studio 1998 Debug */

int __cdecl _strcmp(char *str_1,char *str_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)str_1 & 3) != 0) {
    if (((uint)str_1 & 1) != 0) {
      bVar4 = *str_1;
      str_1 = str_1 + 1;
      bVar5 = bVar4 < (byte)*str_2;
      if (bVar4 != *str_2) goto LAB_004d9964;
      str_2 = str_2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)str_1 & 2) == 0) goto LAB_004d9930;
    }
    uVar1 = *(undefined2 *)str_1;
    str_1 = str_1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*str_2;
    if (bVar4 != *str_2) goto LAB_004d9964;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)str_2[1];
    if (bVar4 != str_2[1]) goto LAB_004d9964;
    if (bVar4 == 0) {
      return 0;
    }
    str_2 = str_2 + 2;
  }
LAB_004d9930:
  while( true ) {
    uVar2 = *(undefined4 *)str_1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*str_2;
    if (bVar4 != *str_2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)str_2[1];
    if (bVar4 != str_2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)str_2[2];
    if (bVar4 != str_2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)str_2[3];
    if (bVar3 != str_2[3]) break;
    str_2 = str_2 + 4;
    str_1 = str_1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_004d9964:
  return (uint)bVar5 * -2 + 1;
}


