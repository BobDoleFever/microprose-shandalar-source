/*
 * Decompiled function: _strncpy
 * Entry Point: 004de870
 * Size: 254 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _strncpy
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strncpy(char *str_1,char *str_2,size_t arg_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (arg_3 == 0) {
    return str_1;
  }
  puVar5 = (uint *)str_1;
  if (((uint)str_2 & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)str_2;
      str_2 = (char *)((int)str_2 + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
      if (arg_3 == 0) {
        return str_1;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)str_2 & 3) == 0) {
        uVar4 = arg_3 >> 2;
        goto joined_r0x004de8ae;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = arg_3 >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_004de8eb;
        goto LAB_004de959;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
    } while (arg_3 != 0);
    return str_1;
  }
  uVar4 = arg_3 >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)str_2;
      uVar2 = *(uint *)str_2;
      str_2 = (char *)((int)str_2 + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x004de955:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_004de959:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          arg_3 = arg_3 & 3;
          if (arg_3 != 0) goto LAB_004de8eb;
          return str_1;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x004de955;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x004de955;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x004de955;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x004de8ae:
    } while (uVar4 != 0);
    arg_3 = arg_3 & 3;
    if (arg_3 == 0) {
      return str_1;
    }
  }
  do {
    cVar3 = (char)*(uint *)str_2;
    str_2 = (char *)((int)str_2 + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (arg_3 = arg_3 - 1, arg_3 != 0) {
LAB_004de8eb:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return str_1;
    }
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return str_1;
}


