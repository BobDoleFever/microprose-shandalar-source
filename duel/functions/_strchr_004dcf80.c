/*
 * Decompiled function: _strchr
 * Entry Point: 004dcf80
 * Size: 193 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strchr
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strchr(char *str_1,int arg_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)str_1 & 3) != 0) {
    uVar1 = *(uint *)str_1;
    if ((char)uVar1 == (char)arg_2) {
      return (char *)(uint *)str_1;
    }
    str_1 = (char *)((int)str_1 + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)str_1;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)arg_2,(char)arg_2),CONCAT11((char)arg_2,(char)arg_2));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)str_1 + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      str_1 = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)str_1;
    if ((char)uVar1 == (char)arg_2) {
      return (char *)(uint *)str_1;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)arg_2) {
      return (char *)((int)str_1 + 3);
    }
    str_1 = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}


