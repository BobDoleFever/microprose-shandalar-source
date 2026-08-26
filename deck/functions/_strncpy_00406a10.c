/*
 * Decompiled function: _strncpy
 * Entry Point: 00406a10
 * Size: 254 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _strncpy
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _strncpy(char *str_1,char *str_2,size_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  char cVar3;
  uint32_t uval_4;
  uint32_t *puVar5;
  
  if (arg_3 == 0) {
    return str_1;
  }
  puVar5 = (uint32_t *)str_1;
  if (((uint32_t)str_2 & 3) != 0) {
    while( true ) {
      uval_4 = *(uint32_t *)str_2;
      str_2 = (char *)((int)str_2 + 1);
      *(char *)puVar5 = (char)uval_4;
      puVar5 = (uint32_t *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
      if (arg_3 == 0) {
        return str_1;
      }
      if ((char)uval_4 == '\0') break;
      if (((uint32_t)str_2 & 3) == 0) {
        uval_4 = arg_3 >> 2;
        goto joined_r0x00406a4e;
      }
    }
    do {
      if (((uint32_t)puVar5 & 3) == 0) {
        uval_4 = arg_3 >> 2;
        cVar3 = '\0';
        if (uval_4 == 0) goto LAB_00406a8b;
        goto LAB_00406af9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint32_t *)((int)puVar5 + 1);
      arg_3 = arg_3 - 1;
    } while (arg_3 != 0);
    return str_1;
  }
  uval_4 = arg_3 >> 2;
  if (uval_4 != 0) {
    do {
      uval_1 = *(uint32_t *)str_2;
      uval_2 = *(uint32_t *)str_2;
      str_2 = (char *)((int)str_2 + 4);
      if (((uval_1 ^ 0xffffffff ^ uval_1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uval_2 == '\0') {
          *puVar5 = 0;
joined_r0x00406af5:
          while( true ) {
            uval_4 = uval_4 - 1;
            puVar5 = puVar5 + 1;
            if (uval_4 == 0) break;
LAB_00406af9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          arg_3 = arg_3 & 3;
          if (arg_3 != 0) goto LAB_00406a8b;
          return str_1;
        }
        if ((char)(uval_2 >> 8) == '\0') {
          *puVar5 = uval_2 & 0xff;
          goto joined_r0x00406af5;
        }
        if ((uval_2 & 0xff0000) == 0) {
          *puVar5 = uval_2 & 0xffff;
          goto joined_r0x00406af5;
        }
        if ((uval_2 & 0xff000000) == 0) {
          *puVar5 = uval_2;
          goto joined_r0x00406af5;
        }
      }
      *puVar5 = uval_2;
      puVar5 = puVar5 + 1;
      uval_4 = uval_4 - 1;
joined_r0x00406a4e:
    } while (uval_4 != 0);
    arg_3 = arg_3 & 3;
    if (arg_3 == 0) {
      return str_1;
    }
  }
  do {
    cVar3 = (char)*(uint32_t *)str_2;
    str_2 = (char *)((int)str_2 + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint32_t *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (arg_3 = arg_3 - 1, arg_3 != 0) {
LAB_00406a8b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint32_t *)((int)puVar5 + 1);
      }
      return str_1;
    }
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return str_1;
}


