/*
 * setenv.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 8
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: ___crtsetenv
 * Entry Point: 004ee530
 * Size: 867 bytes
 */


/* Library Function - Single Match
    ___crtsetenv
   
   Library: Visual Studio 1998 Debug */

int __cdecl ___crtsetenv(char **str_1,int card_slot)

{
  char **ppcVar1;
  int val_2;
  int *i_ptr_3;
  size_t sVar4;
  uint32_t *arg1;
  uint8_t *puVar5;
  bool bVar6;
  int32_t arg_2_00;
  char *arg_3;
  int32_t arg_4;
  LPCSTR loop_idx;
  int match_count;
  
  if (((str_1 == (char **)0x0) ||
      (ppcVar1 = (char **)__mbschr((uchar *)str_1,0x3d), ppcVar1 == (char **)0x0)) ||
     (str_1 == ppcVar1)) {
    return -1;
  }
  bVar6 = *(uchar *)((int)ppcVar1 + 1) == '\0';
  if (DAT_0050944c == DAT_00509448) {
    DAT_00509448 = (int *)copy_environ(DAT_00509448);
  }
  if (DAT_00509448 == (int *)0x0) {
    if ((arg_2 == 0) || (DAT_00509450 == (int32_t *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_00509448 = (int *)__malloc_dbg(4,2,"setenv.c",0x87);
      if (DAT_00509448 == (int *)0x0) {
        return -1;
      }
      *DAT_00509448 = 0;
      if (DAT_00509450 == (int32_t *)0x0) {
        DAT_00509450 = (int32_t *)__malloc_dbg(4,2,"setenv.c",0x8e);
        if (DAT_00509450 == (int32_t *)0x0) {
          return -1;
        }
        *DAT_00509450 = 0;
      }
    }
    else {
      val_2 = ___wtomb_environ();
      if (val_2 != 0) {
        return -1;
      }
    }
  }
  i_ptr_3 = DAT_00509448;
  match_count = findenv((uchar *)str_1,(int)ppcVar1 - (int)str_1);
  if ((match_count < 0) || (*i_ptr_3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (match_count < 0) {
      match_count = -match_count;
    }
    i_ptr_3 = (int *)__realloc_dbg(i_ptr_3,match_count * 4 + 8,2,"setenv.c",0xce);
    if (i_ptr_3 == (int *)0x0) {
      return -1;
    }
    i_ptr_3[match_count] = (int)str_1;
    i_ptr_3[match_count + 1] = 0;
    DAT_00509448 = i_ptr_3;
  }
  else if (bVar6) {
    __free_dbg((void *)i_ptr_3[match_count],2);
    for (; i_ptr_3[match_count] != 0; match_count = match_count + 1) {
      i_ptr_3[match_count] = i_ptr_3[match_count + 1];
    }
    i_ptr_3 = (int *)__realloc_dbg(i_ptr_3,match_count << 2,2,"setenv.c",0xb9);
    if (i_ptr_3 != (int *)0x0) {
      DAT_00509448 = i_ptr_3;
    }
  }
  else {
    i_ptr_3[match_count] = (int)str_1;
  }
  if (arg_2 != 0) {
    arg_4 = 0xe5;
    arg_3 = "setenv.c";
    arg_2_00 = 2;
    sVar4 = _strlen((char *)str_1);
    arg1 = (uint32_t *)__malloc_dbg(sVar4 + 2,arg_2_00,arg_3,arg_4);
    if (arg1 != (uint32_t *)0x0) {
      Mem_AllocOrFree_004d9630(arg1,(uint32_t *)str_1);
      puVar5 = (uint8_t *)(((int)ppcVar1 - (int)str_1) + (int)arg1);
      *puVar5 = 0;
      loop_idx = puVar5 + 1;
      if (bVar6) {
        loop_idx = (LPCSTR)0x0;
      }
      SetEnvironmentVariableA((LPCSTR)arg1,loop_idx);
      __free_dbg(arg1,2);
    }
  }
  return 0;
}



/*
 * Decompiled function: findenv
 * Entry Point: 004ee8a0
 * Size: 155 bytes
 */


/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 1998 Debug */

int __cdecl findenv(uchar *str_1,size_t arg2)

{
  int val_1;
  int *slot_idx;
  
  slot_idx = DAT_00509448;
  while( true ) {
    if (*slot_idx == 0) {
      return -((int)slot_idx - (int)DAT_00509448 >> 2);
    }
    val_1 = __mbsnbicoll(str_1,(uchar *)*slot_idx,arg2);
    if ((val_1 == 0) &&
       ((*(char *)(arg2 + *slot_idx) == '=' || (*(char *)(arg2 + *slot_idx) == '\0')))) break;
    slot_idx = slot_idx + 1;
  }
  return (int)slot_idx - (int)DAT_00509448 >> 2;
}



/*
 * Decompiled function: copy_environ
 * Entry Point: 004ee940
 * Size: 255 bytes
 */


/* Library Function - Single Match
    _copy_environ
   
   Library: Visual Studio 1998 Debug */

int * __cdecl copy_environ(int *arg_1)

{
  int *i_ptr_1;
  size_t len_2;
  int val_3;
  int32_t arg_2;
  char *arg_3;
  int32_t arg_4;
  int player_idx;
  int *card_idx;
  int *match_count;
  
  player_idx = 0;
  card_idx = arg_1;
  if (arg_1 == (int *)0x0) {
    i_ptr_1 = (int *)0x0;
  }
  else {
    while( true ) {
      if (*card_idx == 0) break;
      player_idx = player_idx + 1;
      card_idx = card_idx + 1;
    }
    i_ptr_1 = (int *)__malloc_dbg(player_idx * 4 + 4,2,"setenv.c",0x146);
    if (i_ptr_1 == (int *)0x0) {
      __amsg_exit(9);
    }
    match_count = i_ptr_1;
    for (card_idx = arg_1; *card_idx != 0; card_idx = card_idx + 1) {
      arg_4 = 0x14f;
      arg_3 = "setenv.c";
      arg_2 = 2;
      len_2 = _strlen((char *)*card_idx);
      val_3 = __malloc_dbg(len_2 + 1,arg_2,arg_3,arg_4);
      *match_count = val_3;
      if (*match_count != 0) {
        Mem_AllocOrFree_004d9630((uint32_t *)*match_count,(uint32_t *)*card_idx);
      }
      match_count = match_count + 1;
    }
    *match_count = 0;
  }
  return i_ptr_1;
}



/*
 * Decompiled function: __mbschr
 * Entry Point: 004eea40
 * Size: 229 bytes
 */


/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 1998 Debug */

uchar * __cdecl __mbschr(uchar *str_1,uint32_t arg_2)

{
  uchar *u_ptr_1;
  uint8_t flag_2;
  uint16_t uval_3;
  
  if (DAT_0050a304 == 0) {
    str_1 = (uchar *)_strchr((char *)str_1,arg_2);
  }
  else {
    while( true ) {
      flag_2 = *str_1;
      uval_3 = (uint16_t)flag_2;
      if (uval_3 == 0) break;
      if (((&DAT_0050a201)[flag_2] & 4) == 0) {
        u_ptr_1 = str_1;
        if (uval_3 == arg_2) break;
      }
      else {
        u_ptr_1 = str_1 + 1;
        if (*u_ptr_1 == '\0') {
          return (uchar *)0x0;
        }
        if (CONCAT11(flag_2,*u_ptr_1) == arg_2) {
          return str_1;
        }
      }
      str_1 = u_ptr_1;
      str_1 = str_1 + 1;
    }
    if (uval_3 != arg_2) {
      str_1 = (uchar *)0x0;
    }
  }
  return str_1;
}



/*
 * Decompiled function: RtlUnwind
 * Entry Point: 004eec20
 * Size: 6 bytes
 */


void RtlUnwind(PVOID arg_1,PVOID arg_2,PEXCEPTION_RECORD arg_3,PVOID arg_4)

{
                    /* WARNING: Could not recover jumptable at 0x004eec20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnwind(arg_1,arg_2,arg_3,arg_4);
  return;
}



/*
 * Decompiled function: __chdir
 * Entry Point: 004eec70
 * Size: 226 bytes
 */


/* Library Function - Single Match
    __chdir
   
   Library: Visual Studio 1998 Debug */

int __cdecl __chdir(char *filepath)

{
  BOOL BVar1;
  DWORD DVar2;
  uint32_t uval_3;
  CHAR local_110;
  uint8_t local_10f;
  uint8_t local_10e;
  uint8_t local_10d;
  uint8_t local_10c;
  uint8_t local_10b;
  
  BVar1 = SetCurrentDirectoryA(str_1);
  if ((BVar1 != 0) && (DVar2 = GetCurrentDirectoryA(0x105,(LPSTR)&local_10c), DVar2 != 0)) {
    if (((local_10c == 0x5c) || (local_10c == 0x2f)) && (local_10c == local_10b)) {
      return 0;
    }
    local_110 = '=';
    uval_3 = __mbctoupper((uint32_t)local_10c);
    local_10f = (uint8_t)uval_3;
    local_10e = 0x3a;
    local_10d = 0;
    BVar1 = SetEnvironmentVariableA(&local_110,(LPCSTR)&local_10c);
    if (BVar1 != 0) {
      return 0;
    }
  }
  DVar2 = GetLastError();
  __dosmaperr(DVar2);
  return -1;
}



/*
 * Decompiled function: __strcmpi
 * Entry Point: 004eed60
 * Size: 140 bytes
 */


/* Library Function - Single Match
    __strcmpi
   
   Library: Visual Studio 1998 Debug */

int __cdecl __strcmpi(char *filepath,char *mode_str)

{
  char cVar1;
  uint32_t uval_2;
  uint8_t flag_3;
  uint8_t bVar4;
  uint8_t bVar5;
  char cVar6;
  int player_id;
  int val_7;
  
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
      flag_3 = bVar5 + 0xbf + (-((uint8_t)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == flag_3);
    cVar6 = (bVar5 < flag_3) * -2 + '\x01';
LAB_004eedae:
    val_7 = (int)cVar6;
  }
  else {
    arg_1 = 0;
    val_7 = 0xff;
    do {
      do {
        if ((char)val_7 == '\0') {
          return val_7;
        }
        cVar6 = *str_2;
        val_7 = CONCAT31((int3)((uint32_t)val_7 >> 8),cVar6);
        str_2 = str_2 + 1;
        cVar1 = *str_1;
        arg_1 = CONCAT31((int3)((uint32_t)arg_1 >> 8),cVar1);
        str_1 = str_1 + 1;
      } while (cVar6 == cVar1);
      arg_1 = _tolower(arg_1);
      val_7 = _tolower(val_7);
    } while ((uint8_t)arg_1 == (uint8_t)val_7);
    uval_2 = (uint32_t)((uint8_t)arg_1 < (uint8_t)val_7);
    val_7 = (1 - uval_2) - (uint32_t)(uval_2 != 0);
  }
  return val_7;
}



/*
 * Decompiled function: __strnicmp
 * Entry Point: 004eedf0
 * Size: 173 bytes
 */


/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __strnicmp(char *filepath,char *mode_str,size_t arg_3)

{
  char cVar1;
  uint8_t flag_2;
  uint16_t uval_3;
  uint32_t arg_1;
  int val_4;
  uint32_t uval_5;
  bool bVar6;
  
  val_4 = 0;
  if (arg_3 != 0) {
    if (DAT_0050a730 == 0) {
      do {
        flag_2 = *str_1;
        cVar1 = *str_2;
        uval_3 = CONCAT11(flag_2,cVar1);
        if (flag_2 == 0) break;
        uval_3 = CONCAT11(flag_2,cVar1);
        uval_5 = (uint32_t)uval_3;
        if (cVar1 == '\0') break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        if ((0x40 < flag_2) && (flag_2 < 0x5b)) {
          uval_5 = (uint32_t)CONCAT11(flag_2 + 0x20,cVar1);
        }
        uval_3 = (uint16_t)uval_5;
        flag_2 = (uint8_t)uval_5;
        if ((0x40 < flag_2) && (flag_2 < 0x5b)) {
          uval_3 = (uint16_t)CONCAT31((int3)(uval_5 >> 8),flag_2 + 0x20);
        }
        flag_2 = (uint8_t)(uval_3 >> 8);
        bVar6 = flag_2 < (uint8_t)uval_3;
        if (flag_2 != (uint8_t)uval_3) goto LAB_004eee4b;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      val_4 = 0;
      flag_2 = (uint8_t)(uval_3 >> 8);
      bVar6 = flag_2 < (uint8_t)uval_3;
      if (flag_2 != (uint8_t)uval_3) {
LAB_004eee4b:
        val_4 = -1;
        if (!bVar6) {
          val_4 = 1;
        }
      }
    }
    else {
      uval_5 = 0;
      arg_1 = 0;
      do {
        arg_1 = CONCAT31((int3)(arg_1 >> 8),*str_1);
        uval_5 = CONCAT31((int3)(uval_5 >> 8),*str_2);
        if ((arg_1 == 0) || (uval_5 == 0)) break;
        str_1 = str_1 + 1;
        str_2 = str_2 + 1;
        uval_5 = _tolower(uval_5);
        arg_1 = _tolower(arg_1);
        bVar6 = arg_1 < uval_5;
        if (arg_1 != uval_5) goto LAB_004eee8d;
        arg_3 = arg_3 - 1;
      } while (arg_3 != 0);
      val_4 = 0;
      bVar6 = arg_1 < uval_5;
      if (arg_1 != uval_5) {
LAB_004eee8d:
        val_4 = -1;
        if (!bVar6) {
          val_4 = 1;
        }
      }
    }
  }
  return val_4;
}



