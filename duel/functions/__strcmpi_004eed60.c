/*
 * Decompiled function: __strcmpi
 * Entry Point: 004eed60
 * Size: 140 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __strcmpi
   
   Library: Visual Studio 1998 Debug */

int __cdecl __strcmpi(char *str_1,char *str_2)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  int arg_1;
  int iVar7;
  
  if (DAT_0050a730 == 0) {
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_004eedae;
        bVar5 = *str_2;
        str_2 = str_2 + 1;
        bVar4 = *str_1;
        str_1 = str_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
LAB_004eedae:
    iVar7 = (int)cVar6;
  }
  else {
    arg_1 = 0;
    iVar7 = 0xff;
    do {
      do {
        if ((char)iVar7 == '\0') {
          return iVar7;
        }
        cVar6 = *str_2;
        iVar7 = CONCAT31((int3)((uint)iVar7 >> 8),cVar6);
        str_2 = str_2 + 1;
        cVar1 = *str_1;
        arg_1 = CONCAT31((int3)((uint)arg_1 >> 8),cVar1);
        str_1 = str_1 + 1;
      } while (cVar6 == cVar1);
      arg_1 = _tolower(arg_1);
      iVar7 = _tolower(iVar7);
    } while ((byte)arg_1 == (byte)iVar7);
    uVar2 = (uint)((byte)arg_1 < (byte)iVar7);
    iVar7 = (1 - uVar2) - (uint)(uVar2 != 0);
  }
  return iVar7;
}


