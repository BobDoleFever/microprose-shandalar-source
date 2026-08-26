/*
 * Decompiled function: _strncat
 * Entry Point: 004e0d80
 * Size: 291 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strncat
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strncat(char *str_1,char *str_2,size_t arg_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)str_1;
  if (arg_3 == 0) {
    return str_1;
  }
  do {
    if (((uint)puVar5 & 3) == 0) goto LAB_004e0daa;
    uVar4 = *puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while ((byte)uVar4 != 0);
  goto LAB_004e0ddb;
  while( true ) {
    if ((uVar4 & 0xff0000) == 0) {
      puVar6 = (uint *)((int)puVar6 + 2);
      goto LAB_004e0deb;
    }
    if ((uVar4 & 0xff000000) == 0) break;
LAB_004e0daa:
    do {
      puVar6 = puVar5;
      puVar5 = puVar6 + 1;
    } while (((*puVar6 ^ 0xffffffff ^ *puVar6 + 0x7efefeff) & 0x81010100) == 0);
    uVar4 = *puVar6;
    if ((char)uVar4 == '\0') goto LAB_004e0deb;
    if ((char)(uVar4 >> 8) == '\0') {
      puVar6 = (uint *)((int)puVar6 + 1);
      goto LAB_004e0deb;
    }
  }
LAB_004e0ddb:
  puVar6 = (uint *)((int)puVar5 + -1);
LAB_004e0deb:
  if (((uint)str_2 & 3) == 0) {
    uVar3 = arg_3 >> 2;
  }
  else {
    do {
      bVar1 = (byte)*(uint *)str_2;
      uVar4 = (uint)bVar1;
      str_2 = (char *)((int)str_2 + 1);
      if (bVar1 == 0) goto LAB_004e0e3a;
      *(byte *)puVar6 = bVar1;
      puVar6 = (uint *)((int)puVar6 + 1);
      arg_3 = arg_3 - 1;
      if (arg_3 == 0) goto LAB_004e0e30;
    } while (((uint)str_2 & 3) != 0);
    uVar3 = arg_3 >> 2;
  }
  do {
    if (uVar3 == 0) {
      for (uVar4 = arg_3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        uVar3 = *(uint *)str_2;
        str_2 = (char *)((int)str_2 + 1);
        *(byte *)puVar6 = (byte)uVar3;
        puVar6 = (uint *)((int)puVar6 + 1);
        if ((byte)uVar3 == 0) {
          return str_1;
        }
      }
LAB_004e0e30:
      *(byte *)puVar6 = 0;
      return str_1;
    }
    uVar2 = *(uint *)str_2;
    uVar4 = *(uint *)str_2;
    str_2 = (char *)((int)str_2 + 4);
    if (((uVar2 ^ 0xffffffff ^ uVar2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uVar4 == '\0') {
LAB_004e0e3a:
        *(byte *)puVar6 = (byte)uVar4;
        return str_1;
      }
      if ((char)(uVar4 >> 8) == '\0') {
        *(short *)puVar6 = (short)uVar4;
        return str_1;
      }
      if ((uVar4 & 0xff0000) == 0) {
        *(short *)puVar6 = (short)uVar4;
        *(byte *)((int)puVar6 + 2) = 0;
        return str_1;
      }
      if ((uVar4 & 0xff000000) == 0) {
        *puVar6 = uVar4;
        return str_1;
      }
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 1;
    uVar3 = uVar3 - 1;
  } while( true );
}


