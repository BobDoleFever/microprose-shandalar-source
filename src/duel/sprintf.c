/*
 * sprintf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 29
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _sprintf
 * Entry Point: 004d9720
 * Size: 236 bytes
 */


/* Library Function - Single Match
    _sprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _sprintf(char *filepath,char *mode_str,...)

{
  code *char_ptr_1;
  int val_2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f01fc,0x5d,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f01fc,0x5e,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = 0x7fffffff;
  val_2 = __output(&local_24,(uint8_t *)str_2,(int32_t *)&stack0x0000000c);
  local_24._cnt = local_24._cnt + -1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return val_2;
}



/*
 * Decompiled function: Mem_AllocOrFree_004d9810
 * Entry Point: 004d9810
 * Size: 24 bytes
 */


int Mem_AllocOrFree_004d9810(uint32_t arg_1)

{
  return (arg_1 ^ (int)arg_1 >> 0x1f) - ((int)arg_1 >> 0x1f);
}



/*
 * Decompiled function: Mem_AllocOrFree_004d9830
 * Entry Point: 004d9830
 * Size: 19 bytes
 */


void Mem_AllocOrFree_004d9830(int32_t arg_1)

{
  DAT_005093d0 = arg_1;
  return;
}



/*
 * Decompiled function: _rand
 * Entry Point: 004d9850
 * Size: 65 bytes
 */


/* Library Function - Single Match
    _rand
   
   Library: Visual Studio 1998 Debug */

int __cdecl _rand(void)

{
  DAT_005093d0 = DAT_005093d0 * 0x343fd + 0x269ec3;
  return DAT_005093d0 >> 0x10 & 0x7fff;
}



/*
 * Decompiled function: _strlen
 * Entry Point: 004d98a0
 * Size: 123 bytes
 */


/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *filepath)

{
  uint32_t uval_1;
  uint32_t *u_ptr_2;
  uint32_t *u_ptr_3;
  
  u_ptr_2 = (uint32_t *)str_1;
  do {
    if (((uint32_t)u_ptr_2 & 3) == 0) goto LAB_004d98c0;
    uval_1 = *u_ptr_2;
    u_ptr_2 = (uint32_t *)((int)u_ptr_2 + 1);
  } while ((char)uval_1 != '\0');
LAB_004d98f3:
  return (size_t)((int)u_ptr_2 + (-1 - (int)str_1));
LAB_004d98c0:
  do {
    do {
      u_ptr_3 = u_ptr_2;
      u_ptr_2 = u_ptr_3 + 1;
    } while (((*u_ptr_3 ^ 0xffffffff ^ *u_ptr_3 + 0x7efefeff) & 0x81010100) == 0);
    uval_1 = *u_ptr_3;
    if ((char)uval_1 == '\0') {
      return (int)u_ptr_3 - (int)str_1;
    }
    if ((char)(uval_1 >> 8) == '\0') {
      return (size_t)((int)u_ptr_3 + (1 - (int)str_1));
    }
    if ((uval_1 & 0xff0000) == 0) {
      return (size_t)((int)u_ptr_3 + (2 - (int)str_1));
    }
  } while ((uval_1 & 0xff000000) != 0);
  goto LAB_004d98f3;
}



/*
 * Decompiled function: _strcmp
 * Entry Point: 004d9920
 * Size: 129 bytes
 */


/* Library Function - Single Match
    _strcmp
   
   Library: Visual Studio 1998 Debug */

int __cdecl _strcmp(char *filepath,char *mode_str)

{
  int16_t uval_1;
  int32_t uval_2;
  uint8_t flag_3;
  uint8_t bVar4;
  bool bVar5;
  
  if (((uint32_t)str_1 & 3) != 0) {
    if (((uint32_t)str_1 & 1) != 0) {
      bVar4 = *str_1;
      str_1 = str_1 + 1;
      bVar5 = bVar4 < (uint8_t)*str_2;
      if (bVar4 != *str_2) goto LAB_004d9964;
      str_2 = str_2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint32_t)str_1 & 2) == 0) goto LAB_004d9930;
    }
    uval_1 = *(int16_t *)str_1;
    str_1 = str_1 + 2;
    bVar4 = (uint8_t)uval_1;
    bVar5 = bVar4 < (uint8_t)*str_2;
    if (bVar4 != *str_2) goto LAB_004d9964;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (uint8_t)((uint16_t)uval_1 >> 8);
    bVar5 = bVar4 < (uint8_t)str_2[1];
    if (bVar4 != str_2[1]) goto LAB_004d9964;
    if (bVar4 == 0) {
      return 0;
    }
    str_2 = str_2 + 2;
  }
LAB_004d9930:
  while( true ) {
    uval_2 = *(int32_t *)str_1;
    bVar4 = (uint8_t)uval_2;
    bVar5 = bVar4 < (uint8_t)*str_2;
    if (bVar4 != *str_2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (uint8_t)((uint32_t)uval_2 >> 8);
    bVar5 = bVar4 < (uint8_t)str_2[1];
    if (bVar4 != str_2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (uint8_t)((uint32_t)uval_2 >> 0x10);
    bVar5 = bVar4 < (uint8_t)str_2[2];
    if (bVar4 != str_2[2]) break;
    flag_3 = (uint8_t)((uint32_t)uval_2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = flag_3 < (uint8_t)str_2[3];
    if (flag_3 != str_2[3]) break;
    str_2 = str_2 + 4;
    str_1 = str_1 + 4;
    if (flag_3 == 0) {
      return 0;
    }
  }
LAB_004d9964:
  return (uint32_t)bVar5 * -2 + 1;
}



/*
 * Decompiled function: FID_conflict:_memcpy
 * Entry Point: 004d99b0
 * Size: 285 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    _memcpy
    _memmove
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl FID_conflict__memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  uint32_t uval_1;
  int in_EDX;
  uint32_t uval_2;
  int32_t *u_ptr_3;
  uint8_t *puVar4;
  int32_t *puVar5;
  uint8_t *puVar6;
  
  if ((ptr_2 < ptr_1) && (ptr_1 < (void *)((int)ptr_2 + arg_3))) {
    u_ptr_3 = (int32_t *)((int)ptr_2 + arg_3);
    puVar5 = (int32_t *)((int)ptr_1 + arg_3);
    if (((uint32_t)puVar5 & 3) == 0) {
      uval_1 = arg_3 >> 2;
      while( true ) {
        puVar5 = puVar5 + -1;
        u_ptr_3 = u_ptr_3 + -1;
        if (uval_1 == 0) break;
        uval_1 = uval_1 - 1;
        *puVar5 = *u_ptr_3;
      }
      switch(arg_3 & 3) {
      case 1:
switchD_004d9a79_caseD_1:
        *(uint8_t *)((int)puVar5 + 3) = *(uint8_t *)((int)u_ptr_3 + 3);
        return ptr_1;
      case 2:
switchD_004d9a79_caseD_2:
        *(int16_t *)((int)puVar5 + 2) = *(int16_t *)((int)u_ptr_3 + 2);
        return ptr_1;
      case 3:
switchD_004d9a79_caseD_3:
        *(int16_t *)((int)puVar5 + 2) = *(int16_t *)((int)u_ptr_3 + 2);
        *(uint8_t *)((int)puVar5 + 1) = *(uint8_t *)((int)u_ptr_3 + 1);
        return ptr_1;
      }
    }
    else {
      puVar4 = (uint8_t *)((int)u_ptr_3 + -1);
      puVar6 = (uint8_t *)((int)puVar5 + -1);
      if (arg_3 < 0xd) {
        for (; arg_3 != 0; arg_3 = arg_3 - 1) {
          *puVar6 = *puVar4;
          puVar4 = puVar4 + -1;
          puVar6 = puVar6 + -1;
        }
        return ptr_1;
      }
      uval_2 = -in_EDX & 3;
      uval_1 = arg_3 - uval_2;
      for (; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + -1;
        puVar6 = puVar6 + -1;
      }
      u_ptr_3 = (int32_t *)(puVar4 + -3);
      puVar5 = (int32_t *)(puVar6 + -3);
      for (uval_2 = uval_1 >> 2; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar5 = *u_ptr_3;
        u_ptr_3 = u_ptr_3 + -1;
        puVar5 = puVar5 + -1;
      }
      switch(uval_1 & 3) {
      case 1:
        goto switchD_004d9a79_caseD_1;
      case 2:
        goto switchD_004d9a79_caseD_2;
      case 3:
        goto switchD_004d9a79_caseD_3;
      }
    }
    return ptr_1;
  }
  u_ptr_3 = ptr_1;
  if (((uint32_t)ptr_1 & 3) == 0) {
    for (uval_1 = arg_3 >> 2; uval_1 != 0; uval_1 = uval_1 - 1) {
      *u_ptr_3 = *(int32_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 4);
      u_ptr_3 = u_ptr_3 + 1;
    }
    switch(arg_3 & 3) {
    case 1:
switchD_004d99e0_caseD_1:
      *(uint8_t *)u_ptr_3 = *(uint8_t *)ptr_2;
      return ptr_1;
    case 2:
switchD_004d99e0_caseD_2:
      *(int16_t *)u_ptr_3 = *(int16_t *)ptr_2;
      return ptr_1;
    case 3:
switchD_004d99e0_caseD_3:
      *(int16_t *)u_ptr_3 = *(int16_t *)ptr_2;
      *(uint8_t *)((int)u_ptr_3 + 2) = *(uint8_t *)((int)ptr_2 + 2);
      return ptr_1;
    }
  }
  else {
    puVar4 = ptr_1;
    if (arg_3 < 0xd) {
      for (; arg_3 != 0; arg_3 = arg_3 - 1) {
        *puVar4 = *(uint8_t *)ptr_2;
        ptr_2 = (uint8_t *)((int)ptr_2 + 1);
        puVar4 = puVar4 + 1;
      }
      return ptr_1;
    }
    uval_2 = -(int)ptr_1 & 3;
    uval_1 = arg_3 - uval_2;
    for (; uval_2 != 0; uval_2 = uval_2 - 1) {
      *(uint8_t *)u_ptr_3 = *(uint8_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 1);
      u_ptr_3 = (int32_t *)((int)u_ptr_3 + 1);
    }
    for (uval_2 = uval_1 >> 2; uval_2 != 0; uval_2 = uval_2 - 1) {
      *u_ptr_3 = *(int32_t *)ptr_2;
      ptr_2 = (int32_t *)((int)ptr_2 + 4);
      u_ptr_3 = u_ptr_3 + 1;
    }
    switch(uval_1 & 3) {
    case 1:
      goto switchD_004d99e0_caseD_1;
    case 2:
      goto switchD_004d99e0_caseD_2;
    case 3:
      goto switchD_004d99e0_caseD_3;
    }
  }
  return ptr_1;
}



/*
 * Decompiled function: _strncmp
 * Entry Point: 004d9b00
 * Size: 56 bytes
 */


/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *filepath,char *mode_str,size_t arg_3)

{
  char cVar1;
  char cVar2;
  size_t len_3;
  int val_4;
  uint32_t uval_5;
  char *pcVar6;
  char *pcVar7;
  
  uval_5 = 0;
  len_3 = arg_3;
  pcVar6 = str_1;
  if (arg_3 != 0) {
    do {
      if (len_3 == 0) break;
      len_3 = len_3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    val_4 = arg_3 - len_3;
    do {
      pcVar6 = str_2;
      pcVar7 = str_1;
      if (val_4 == 0) break;
      val_4 = val_4 + -1;
      pcVar7 = str_1 + 1;
      pcVar6 = str_2 + 1;
      cVar2 = *str_1;
      cVar1 = *str_2;
      str_2 = pcVar6;
      str_1 = pcVar7;
    } while (cVar1 == cVar2);
    uval_5 = 0;
    if ((uint8_t)pcVar6[-1] <= (uint8_t)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uval_5 = 0xfffffffe;
    }
    uval_5 = ~uval_5;
  }
  return uval_5;
}



/*
 * Decompiled function: _atol
 * Entry Point: 004d9b40
 * Size: 282 bytes
 */


/* Library Function - Single Match
    _atol
   
   Library: Visual Studio 1998 Debug */

long __cdecl _atol(char *filepath)

{
  uint8_t *pbVar1;
  uint32_t uval_2;
  uint32_t target_idx;
  uint32_t player_idx;
  int match_count;
  uint32_t slot_idx;
  
  while( true ) {
    if (DAT_005096ac < 2) {
      player_idx = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)(uint8_t)*str_1 * 2) & 8;
    }
    else {
      player_idx = __isctype((uint32_t)(uint8_t)*str_1,8);
    }
    if (player_idx == 0) break;
    str_1 = str_1 + 1;
  }
  uval_2 = (uint32_t)(uint8_t)*str_1;
  if ((uval_2 == 0x2d) || (pbVar1 = (uint8_t *)(str_1 + 1), slot_idx = uval_2, uval_2 == 0x2b)) {
    slot_idx = (uint32_t)(uint8_t)str_1[1];
    pbVar1 = (uint8_t *)(str_1 + 2);
  }
  str_1 = (char *)pbVar1;
  match_count = 0;
  while( true ) {
    if (DAT_005096ac < 2) {
      target_idx = *(uint16_t *)(PTR_DAT_005094a0 + slot_idx * 2) & 4;
    }
    else {
      target_idx = __isctype(slot_idx,4);
    }
    if (target_idx == 0) break;
    match_count = (slot_idx - 0x30) + match_count * 10;
    slot_idx = (uint32_t)(uint8_t)*str_1;
    str_1 = str_1 + 1;
  }
  if (uval_2 == 0x2d) {
    match_count = -match_count;
  }
  return match_count;
}



/*
 * Decompiled function: _atoi
 * Entry Point: 004d9c60
 * Size: 28 bytes
 */


/* Library Function - Single Match
    _atoi
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atoi(char *filepath)

{
  long lVar1;
  
  lVar1 = _atol(str_1);
  return lVar1;
}



/*
 * Decompiled function: __atoi64
 * Entry Point: 004d9c80
 * Size: 324 bytes
 */


/* Library Function - Single Match
    __atoi64
   
   Library: Visual Studio 1998 Debug */

longlong __cdecl __atoi64(char *filepath)

{
  uint8_t *pbVar1;
  uint32_t uval_2;
  longlong lVar3;
  uint32_t color_idx;
  uint32_t target_idx;
  uint32_t card_idx;
  int match_count;
  uint32_t slot_idx;
  
  while( true ) {
    if (DAT_005096ac < 2) {
      target_idx = *(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)(uint8_t)*str_1 * 2) & 8;
    }
    else {
      target_idx = __isctype((uint32_t)(uint8_t)*str_1,8);
    }
    if (target_idx == 0) break;
    str_1 = str_1 + 1;
  }
  uval_2 = (uint32_t)(uint8_t)*str_1;
  if ((uval_2 == 0x2d) || (pbVar1 = (uint8_t *)(str_1 + 1), slot_idx = uval_2, uval_2 == 0x2b)) {
    slot_idx = (uint32_t)(uint8_t)str_1[1];
    pbVar1 = (uint8_t *)(str_1 + 2);
  }
  str_1 = (char *)pbVar1;
  lVar3 = 0;
  while( true ) {
    match_count = (int)((ulonglong)lVar3 >> 0x20);
    card_idx = (uint32_t)lVar3;
    if (DAT_005096ac < 2) {
      color_idx = *(uint16_t *)(PTR_DAT_005094a0 + slot_idx * 2) & 4;
    }
    else {
      color_idx = __isctype(slot_idx,4);
    }
    if (color_idx == 0) break;
    lVar3 = __allmul(card_idx,match_count,10,0);
    lVar3 = lVar3 + (int)(slot_idx - 0x30);
    slot_idx = (uint32_t)(uint8_t)*str_1;
    str_1 = str_1 + 1;
  }
  if (uval_2 == 0x2d) {
    lVar3 = CONCAT44(-(match_count + (uint32_t)(card_idx != 0)),-card_idx);
  }
  return lVar3;
}



/*
 * Decompiled function: __assert
 * Entry Point: 004d9dd0
 * Size: 951 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __assert
   
   Library: Visual Studio 1998 Debug */

void __assert(uint32_t *arg_1,uint32_t *arg_2,int event_type)

{
  code *char_ptr_1;
  DWORD DVar2;
  size_t len_3;
  size_t sVar4;
  int val_5;
  uint32_t local_328 [65];
  uint32_t *local_224;
  uint32_t local_220 [135];
  
  if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
    if ((_DAT_0050979c & 0x10c) == 0) {
      _setvbuf((FILE *)&DAT_00509790,(char *)0x0,4,0);
    }
    _fprintf((FILE *)&DAT_00509790,s_Assertion_failed___s__file__s__l_005093e0,arg_1,arg_2,arg_3);
    _fflush((FILE *)&DAT_00509790);
  }
  else {
    Mem_AllocOrFree_004d9630(local_220,(uint32_t *)"Assertion failed!");
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_00509410);
    Str_CopyFast(local_220, (uint32_t *)"Program: ");
    DVar2 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_328,0x104);
    if (DVar2 == 0) {
      Mem_AllocOrFree_004d9630(local_328,(uint32_t *)"<program name unknown>");
    }
    local_224 = local_328;
    len_3 = _strlen((char *)local_328);
    if (0x3c < len_3 + 0xb) {
      len_3 = _strlen((char *)local_328);
      local_224 = (uint32_t *)((int)local_224 + (len_3 - 0x31));
      _strncpy((char *)local_224,PTR_DAT_00509408,3);
    }
    Str_CopyFast(local_220,local_224);
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_0050940c);
    Str_CopyFast(local_220, (uint32_t *)"File: ");
    local_224 = arg_2;
    len_3 = _strlen((char *)arg_2);
    if (0x3c < len_3 + 8) {
      len_3 = _strlen((char *)arg_2);
      local_224 = (uint32_t *)((int)local_224 + (len_3 - 0x34));
      _strncpy((char *)local_224,PTR_DAT_00509408,3);
    }
    Str_CopyFast(local_220,local_224);
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_0050940c);
    Str_CopyFast(local_220, (uint32_t *)"Line: ");
    val_5 = 10;
    len_3 = _strlen((char *)local_220);
    __itoa(arg_3,(char *)((int)local_220 + len_3),val_5);
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_00509410);
    Str_CopyFast(local_220, (uint32_t *)"Expression: ");
    len_3 = _strlen((char *)arg_1);
    sVar4 = _strlen((char *)local_220);
    if (len_3 + sVar4 + 0xb0 < 0x21d) {
      Str_CopyFast(local_220,arg_1);
    }
    else {
      len_3 = _strlen((char *)local_220);
      _strncat((char *)local_220,(char *)arg_1,0x21c - (len_3 + 0xb1));
      Str_CopyFast(local_220, (uint32_t *)PTR_DAT_00509408);
    }
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_00509410);
    Str_CopyFast(local_220,
                 (uint32_t *)
                 "For information on how your program can cause an assertion\nfailure, see the Visual C++ documentation on asserts"
                );
    Str_CopyFast(local_220, (uint32_t *)PTR_DAT_00509410);
    Str_CopyFast(local_220, (uint32_t *)"(Press Retry to debug the application - JIT must be enabled)");
    val_5 = ___crtMessageBoxA((LPCSTR)local_220,"Microsoft Visual C++ Runtime Library",0x12012);
    if (val_5 == 3) {
      _raise(0x16);
      __exit(3);
    }
    if (val_5 == 4) {
      char_ptr_1 = (code *)swi(3);
      (*char_ptr_1)();
      return;
    }
    if (val_5 == 5) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}



/*
 * Decompiled function: _memset
 * Entry Point: 004da190
 * Size: 88 bytes
 */


/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *ptr_1,int card_slot,size_t arg_3)

{
  uint32_t uval_1;
  uint32_t uval_2;
  size_t len_3;
  uint32_t *puVar4;
  
  if (arg_3 == 0) {
    return ptr_1;
  }
  uval_1 = arg_2 & 0xff;
  puVar4 = ptr_1;
  if (3 < arg_3) {
    uval_2 = -(int)ptr_1 & 3;
    len_3 = arg_3;
    if (uval_2 != 0) {
      len_3 = arg_3 - uval_2;
      do {
        *(uint8_t *)puVar4 = (uint8_t)arg_2;
        puVar4 = (uint32_t *)((int)puVar4 + 1);
        uval_2 = uval_2 - 1;
      } while (uval_2 != 0);
    }
    uval_1 = uval_1 * 0x1010101;
    arg_3 = len_3 & 3;
    uval_2 = len_3 >> 2;
    if (uval_2 != 0) {
      for (; uval_2 != 0; uval_2 = uval_2 - 1) {
        *puVar4 = uval_1;
        puVar4 = puVar4 + 1;
      }
      if (arg_3 == 0) {
        return ptr_1;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uval_1;
    puVar4 = (uint32_t *)((int)puVar4 + 1);
    arg_3 = arg_3 - 1;
  } while (arg_3 != 0);
  return ptr_1;
}



/*
 * Decompiled function: __cinit
 * Entry Point: 004da1f0
 * Size: 66 bytes
 */


/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 1998 Debug */

int __cdecl __cinit(int player_id)

{
  int val_1;
  
  if (PTR___fpmath_005096d0 != (uint8_t *)0x0) {
    (*(code *)PTR___fpmath_005096d0)();
  }
  __initterm((int *)&DAT_004f2008,(int *)&DAT_004f2010);
  val_1 = __initterm((int *)&DAT_004f2000,(int *)&DAT_004f2004);
  return val_1;
}



/*
 * Decompiled function: _exit
 * Entry Point: 004da240
 * Size: 27 bytes
 */


/* Library Function - Single Match
    _exit
   
   Library: Visual Studio 1998 Debug */

void __cdecl _exit(int player_id)

{
  doexit(arg_1,0,0);
  return;
}



/*
 * Decompiled function: __exit
 * Entry Point: 004da260
 * Size: 27 bytes
 */


/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 1998 Debug */

void __exit(UINT arg_1)

{
  doexit(arg_1,1,0);
  return;
}



/*
 * Decompiled function: __cexit
 * Entry Point: 004da280
 * Size: 25 bytes
 */


/* Library Function - Single Match
    __cexit
   
   Library: Visual Studio 1998 Debug */

void __cdecl __cexit(void)

{
  doexit(0,0,1);
  return;
}



/*
 * Decompiled function: __c_exit
 * Entry Point: 004da2a0
 * Size: 25 bytes
 */


/* Library Function - Single Match
    __c_exit
   
   Library: Visual Studio 1998 Debug */

void __cdecl __c_exit(void)

{
  doexit(0,1,1);
  return;
}



/*
 * Decompiled function: doexit
 * Entry Point: 004da2c0
 * Size: 251 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 1998 Debug */

void __cdecl doexit(UINT arg_1,int card_slot,int event_type)

{
  HANDLE hProcess;
  uint32_t uval_1;
  UINT uExitCode;
  int *slot_idx;
  
  if (DAT_00509468 == 1) {
    uExitCode = arg_1;
    hProcess = GetCurrentProcess();
    TerminateProcess(hProcess,uExitCode);
  }
  _DAT_00509464 = 1;
  DAT_00509460 = (uint8_t)arg_3;
  if (arg_2 == 0) {
    if (DAT_006c2cb4 != (int *)0x0) {
      slot_idx = DAT_006c2cb0;
      while (slot_idx = slot_idx + -1, DAT_006c2cb4 <= slot_idx) {
        if (*slot_idx != 0) {
          (*(code *)*slot_idx)();
        }
      }
    }
    __initterm((int *)&DAT_004f2014,(int *)&DAT_004f201c);
  }
  __initterm((int *)&DAT_004f2020,(int *)&DAT_004f2024);
  if ((DAT_0050946c == 0) && (uval_1 = __CrtSetDbgFlag(-1), (uval_1 & 0x20) != 0)) {
    DAT_0050946c = 1;
    __CrtDumpMemoryLeaks();
  }
  if (arg_3 == 0) {
    DAT_00509468 = 1;
                    /* WARNING: Subroutine does not return */
    ExitProcess(arg_1);
  }
  return;
}



/*
 * Decompiled function: __initterm
 * Entry Point: 004da3c0
 * Size: 49 bytes
 */


/* Library Function - Single Match
    __initterm
   
   Library: Visual Studio 1998 Debug */

void __initterm(int *arg1,int *arg2)

{
  for (; arg1 < arg2; arg1 = arg1 + 1) {
    if (*arg1 != 0) {
      (*(code *)*arg1)();
    }
  }
  return;
}



/*
 * Decompiled function: _fread
 * Entry Point: 004da400
 * Size: 456 bytes
 */


/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _fread(void *ptr_1,size_t arg_2,size_t arg_3,FILE *fp)

{
  uint32_t uval_1;
  uint32_t arg_3_00;
  int val_2;
  uint32_t loop_idx;
  uint32_t color_idx;
  uint32_t card_idx;
  uint8_t *match_count;
  uint8_t slot_idx;
  
  match_count = ptr_1;
  uval_1 = arg_3 * arg_2;
  if (uval_1 == 0) {
    arg_3 = 0;
  }
  else {
    card_idx = uval_1;
    if ((fp->_flag & 0x10cU) == 0) {
      loop_idx = 0x1000;
    }
    else {
      loop_idx = fp->_bufsiz;
    }
    while (card_idx != 0) {
      if (((fp->_flag & 0x10cU) == 0) || (fp->_cnt == 0)) {
        if (card_idx < loop_idx) {
          val_2 = __filbuf(fp);
          if (val_2 == -1) {
            return (uval_1 - card_idx) / arg_2;
          }
          slot_idx = (uint8_t)val_2;
          *match_count = slot_idx;
          match_count = match_count + 1;
          card_idx = card_idx - 1;
          loop_idx = fp->_bufsiz;
        }
        else {
          if (loop_idx == 0) {
            color_idx = card_idx;
          }
          else {
            color_idx = card_idx - card_idx % loop_idx;
          }
          val_2 = __read(fp->_file,match_count,color_idx);
          if (val_2 == 0) {
            fp->_flag = fp->_flag | 0x10;
            return (uval_1 - card_idx) / arg_2;
          }
          if (val_2 == -1) {
            fp->_flag = fp->_flag | 0x20;
            return (uval_1 - card_idx) / arg_2;
          }
          card_idx = card_idx - val_2;
          match_count = match_count + val_2;
        }
      }
      else {
        arg_3_00 = fp->_cnt;
        if (card_idx <= (uint32_t)fp->_cnt) {
          arg_3_00 = card_idx;
        }
        FID_conflict__memcpy(match_count,fp->_ptr,arg_3_00);
        card_idx = card_idx - arg_3_00;
        fp->_cnt = fp->_cnt - arg_3_00;
        fp->_ptr = fp->_ptr + arg_3_00;
        match_count = match_count + arg_3_00;
      }
    }
  }
  return arg_3;
}



/*
 * Decompiled function: _malloc
 * Entry Point: 004da5d0
 * Size: 40 bytes
 */


/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl _malloc(size_t arg_1)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__nh_malloc_dbg(arg_1,DAT_005099d4,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __malloc_dbg
 * Entry Point: 004da600
 * Size: 46 bytes
 */


/* Library Function - Single Match
    __malloc_dbg
   
   Library: Visual Studio 1998 Debug */

void __malloc_dbg(size_t arg_1,int32_t arg_2,int32_t arg_3,int32_t arg_4)

{
  __nh_malloc_dbg(arg_1,DAT_005099d4,arg_2,arg_3,arg_4);
  return;
}



/*
 * Decompiled function: __nh_malloc
 * Entry Point: 004da630
 * Size: 38 bytes
 */


/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __nh_malloc(size_t arg_1,int card_slot)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__nh_malloc_dbg(arg_1,arg_2,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __nh_malloc_dbg
 * Entry Point: 004da660
 * Size: 101 bytes
 */


/* Library Function - Single Match
    __nh_malloc_dbg
   
   Library: Visual Studio 1998 Debug */

int __nh_malloc_dbg(size_t arg_1,int card_slot,uint32_t arg_3,int arg_4,int32_t arg_5)

{
  int val_1;
  
  while( true ) {
    val_1 = __heap_alloc_dbg(arg_1,arg_3,arg_4,arg_5);
    if (val_1 != 0) {
      return val_1;
    }
    if (arg_2 == 0) break;
    val_1 = __callnewh(arg_1);
    if (val_1 == 0) {
      return 0;
    }
  }
  return 0;
}



/*
 * Decompiled function: __heap_alloc
 * Entry Point: 004da6d0
 * Size: 34 bytes
 */


/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Debug */

void * __cdecl __heap_alloc(size_t arg_1)

{
  void *buf_ptr_1;
  
  buf_ptr_1 = (void *)__heap_alloc_dbg(arg_1,1,0,0);
  return buf_ptr_1;
}



/*
 * Decompiled function: __snprintf
 * Entry Point: 004e8c50
 * Size: 235 bytes
 */


/* Library Function - Single Match
    __snprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __snprintf(char *filepath,size_t arg_2,char *str_3,...)

{
  code *char_ptr_1;
  int val_2;
  FILE local_24;
  
  if (str_1 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f01fc,0x5d,0,"string != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_3 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f01fc,0x5e,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  local_24._flag = 0x42;
  local_24._base = str_1;
  local_24._ptr = str_1;
  local_24._cnt = arg_2;
  val_2 = __output(&local_24,(uint8_t *)str_3,(int32_t *)&stack0x00000010);
  local_24._cnt = local_24._cnt - 1;
  if (local_24._cnt < 0) {
    __flsbuf(0,&local_24);
  }
  else {
    *local_24._ptr = '\0';
  }
  return val_2;
}



/*
 * Decompiled function: __commit
 * Entry Point: 004e8d40
 * Size: 217 bytes
 */


/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Debug */

int __cdecl __commit(int player_id)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD slot_idx;
  
  if ((((uint32_t)arg_1 < DAT_006c1c90) &&
      ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                 (arg_1 & 0x1fU) * 8) & 1) != 0)) &&
     ((*(uint8_t *)(*(int *)((int)&DAT_006c1b90 + ((int)(arg_1 & 0xffffffe0U) >> 3)) + 4 +
                (arg_1 & 0x1fU) * 8) & 1) != 0)) {
    hFile = (HANDLE)__get_osfhandle(arg_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      slot_idx = GetLastError();
    }
    else {
      slot_idx = 0;
    }
    if (slot_idx == 0) {
      return 0;
    }
    DAT_00509424 = slot_idx;
  }
  DAT_00509420 = 9;
  return -1;
}



/*
 * Decompiled function: __fcloseall
 * Entry Point: 004e8e20
 * Size: 187 bytes
 */


/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 1998 Debug */

int __cdecl __fcloseall(void)

{
  int val_1;
  int32_t match_count;
  int32_t slot_idx;
  
  slot_idx = 0;
  for (match_count = 3; match_count < DAT_006c2ca0; match_count = match_count + 1) {
    if (*(int *)(DAT_006c1c98 + match_count * 4) != 0) {
      if ((*(uint8_t *)(*(int *)(DAT_006c1c98 + match_count * 4) + 0xc) & 0x83) != 0) {
        val_1 = _fclose(*(FILE **)(DAT_006c1c98 + match_count * 4));
        if (val_1 != -1) {
          slot_idx = slot_idx + 1;
        }
      }
      if (0x13 < match_count) {
        __free_dbg(*(void **)(DAT_006c1c98 + match_count * 4),2);
        *(int32_t *)(DAT_006c1c98 + match_count * 4) = 0;
      }
    }
  }
  return slot_idx;
}



