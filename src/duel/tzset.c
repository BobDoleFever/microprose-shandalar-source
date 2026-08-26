/*
 * tzset.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 33
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __tzset
 * Entry Point: 004e9930
 * Size: 861 bytes
 */


/* Library Function - Single Match
    __tzset
   
   Library: Visual Studio 1998 Debug */

void __cdecl __tzset(void)

{
  char cVar1;
  uint32_t *arg2;
  DWORD DVar2;
  int val_3;
  size_t sVar4;
  long lVar5;
  int32_t arg_2;
  char *arg_3;
  int32_t arg_4;
  uint32_t *match_count;
  
  DAT_005edc20 = 0;
  DAT_0050a800 = 0xffffffff;
  DAT_0050a7f0 = 0xffffffff;
  arg2 = (uint32_t *)_getenv("TZ");
  if (arg2 == (uint32_t *)0x0) {
    DVar2 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_005edc28);
    if (DVar2 != 0) {
      DAT_005edc20 = 1;
      DAT_0050a750 = DAT_005edc28 * 0x3c;
      if (DAT_005edc6e != 0) {
        DAT_0050a750 = DAT_0050a750 + DAT_005edc7c * 0x3c;
      }
      if ((DAT_005edcc2 == 0) || (DAT_005edcd0 == 0)) {
        DAT_0050a754 = 0;
        DAT_0050a758 = 0;
      }
      else {
        DAT_0050a754 = 1;
        DAT_0050a758 = (DAT_005edcd0 - DAT_005edc7c) * 0x3c;
      }
      _wcstombs(PTR_DAT_0050a7e0,(wchar_t *)&DAT_005edc2c,0x40);
      _wcstombs(PTR_DAT_0050a7e4,(wchar_t *)&DAT_005edc80,0x40);
      PTR_DAT_0050a7e4[0x3f] = 0;
      PTR_DAT_0050a7e0[0x3f] = PTR_DAT_0050a7e4[0x3f];
    }
  }
  else if (((char)*arg2 != '\0') &&
          ((DAT_0050a7e8 == (uint32_t *)0x0 ||
           (val_3 = _strcmp((char *)arg2,(char *)DAT_0050a7e8), val_3 != 0)))) {
    __free_dbg(DAT_0050a7e8,2);
    arg_4 = 0xec;
    arg_3 = "tzset.c";
    arg_2 = 2;
    sVar4 = _strlen((char *)arg2);
    DAT_0050a7e8 = (uint32_t *)__malloc_dbg(sVar4 + 1,arg_2,arg_3,arg_4);
    if (DAT_0050a7e8 != (uint32_t *)0x0) {
      Mem_AllocOrFree_004d9630(DAT_0050a7e8,arg2);
      _strncpy(PTR_DAT_0050a7e0,(char *)arg2,3);
      PTR_DAT_0050a7e0[3] = 0;
      match_count = (uint32_t *)((int)arg2 + 3);
      cVar1 = *(char *)match_count;
      if (cVar1 == '-') {
        match_count = arg2 + 1;
      }
      lVar5 = _atol((char *)match_count);
      DAT_0050a750 = lVar5 * 0xe10;
      for (; ((char)*match_count == '+' || (('/' < (char)*match_count && ((char)*match_count < ':'))));
          match_count = (uint32_t *)((int)match_count + 1)) {
      }
      if ((char)*match_count == ':') {
        match_count = (uint32_t *)((int)match_count + 1);
        lVar5 = _atol((char *)match_count);
        DAT_0050a750 = DAT_0050a750 + lVar5 * 0x3c;
        for (; ('/' < (char)*match_count && ((char)*match_count < ':'));
            match_count = (uint32_t *)((int)match_count + 1)) {
        }
        if ((char)*match_count == ':') {
          match_count = (uint32_t *)((int)match_count + 1);
          lVar5 = _atol((char *)match_count);
          DAT_0050a750 = DAT_0050a750 + lVar5;
          for (; ('/' < (char)*match_count && ((char)*match_count < ':'));
              match_count = (uint32_t *)((int)match_count + 1)) {
          }
        }
      }
      if (cVar1 == '-') {
        DAT_0050a750 = -DAT_0050a750;
      }
      DAT_0050a754 = (int)(char)*match_count;
      if (DAT_0050a754 == 0) {
        *PTR_DAT_0050a7e4 = 0;
      }
      else {
        _strncpy(PTR_DAT_0050a7e4,(char *)match_count,3);
        PTR_DAT_0050a7e4[3] = 0;
      }
    }
  }
  return;
}



/*
 * Decompiled function: __isindst
 * Entry Point: 004e9c90
 * Size: 859 bytes
 */


/* Library Function - Single Match
    __isindst
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isindst(tm *ptr_1)

{
  int val_1;
  
  if (DAT_0050a754 == 0) {
    return 0;
  }
  if ((ptr_1->tm_year != DAT_0050a7f0) || (ptr_1->tm_year != DAT_0050a800)) {
    if (DAT_005edc20 == 0) {
      cvtdate(1,1,ptr_1->tm_year,4,1,0,0,2,0,0,0);
      cvtdate(0,1,ptr_1->tm_year,10,5,0,0,2,0,0,0);
    }
    else {
      if (DAT_005edcc0 == 0) {
        cvtdate(1,1,ptr_1->tm_year,(uint32_t)DAT_005edcc2,(uint32_t)DAT_005edcc6,(uint32_t)DAT_005edcc4,0,
                (uint32_t)DAT_005edcc8,(uint32_t)DAT_005edcca,(uint32_t)DAT_005edccc,(uint32_t)DAT_005edcce);
      }
      else {
        cvtdate(1,0,ptr_1->tm_year,(uint32_t)DAT_005edcc2,0,0,(uint32_t)DAT_005edcc6,(uint32_t)DAT_005edcc8,
                (uint32_t)DAT_005edcca,(uint32_t)DAT_005edccc,(uint32_t)DAT_005edcce);
      }
      if (DAT_005edc6c == 0) {
        cvtdate(0,1,ptr_1->tm_year,(uint32_t)DAT_005edc6e,(uint32_t)DAT_005edc72,(uint32_t)DAT_005edc70,0,
                (uint32_t)DAT_005edc74,(uint32_t)DAT_005edc76,(uint32_t)DAT_005edc78,(uint32_t)DAT_005edc7a);
      }
      else {
        cvtdate(0,0,ptr_1->tm_year,(uint32_t)DAT_005edc6e,0,0,(uint32_t)DAT_005edc72,(uint32_t)DAT_005edc74,
                (uint32_t)DAT_005edc76,(uint32_t)DAT_005edc78,(uint32_t)DAT_005edc7a);
      }
    }
  }
  if (DAT_0050a7f4 < DAT_0050a804) {
    if ((ptr_1->tm_yday < DAT_0050a7f4) || (DAT_0050a804 < ptr_1->tm_yday)) {
      return 0;
    }
    if ((DAT_0050a7f4 < ptr_1->tm_yday) && (ptr_1->tm_yday < DAT_0050a804)) {
      return 1;
    }
  }
  else {
    if ((ptr_1->tm_yday < DAT_0050a804) || (DAT_0050a7f4 < ptr_1->tm_yday)) {
      return 1;
    }
    if ((DAT_0050a804 < ptr_1->tm_yday) && (ptr_1->tm_yday < DAT_0050a7f4)) {
      return 0;
    }
  }
  val_1 = (ptr_1->tm_hour * 0xe10 + ptr_1->tm_min * 0x3c + ptr_1->tm_sec) * 1000;
  if (ptr_1->tm_yday == DAT_0050a7f4) {
    if (val_1 < DAT_0050a7f8) {
      val_1 = 0;
    }
    else {
      val_1 = 1;
    }
  }
  else if (val_1 < DAT_0050a808) {
    val_1 = 1;
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: cvtdate
 * Entry Point: 004ea000
 * Size: 515 bytes
 */


/* Library Function - Single Match
    _cvtdate
   
   Library: Visual Studio 1998 Debug */

void __cdecl
cvtdate(int player_id,int card_slot,uint32_t arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,int arg_9,
       int arg_10,int arg_11)

{
  int val_1;
  int player_idx;
  int card_idx;
  int match_count;
  
  if (arg_2 == 1) {
    if ((arg_3 & 3) == 0) {
      card_idx = *(int *)(&DAT_0050a834 + arg_4 * 4);
    }
    else {
      card_idx = *(int *)(&DAT_0050a86c + arg_4 * 4);
    }
    val_1 = (int)((arg_3 - 0x46) * 0x16d + ((int)(arg_3 - 1) >> 2) + -0xd + card_idx + 1) % 7;
    if (val_1 < arg_6) {
      match_count = (arg_6 - val_1) + (arg_5 + -1) * 7;
    }
    else {
      match_count = (arg_6 - val_1) + arg_5 * 7;
    }
    match_count = card_idx + 1 + match_count;
    if (arg_5 == 5) {
      if ((arg_3 & 3) == 0) {
        player_idx = *(int *)(&DAT_0050a838 + arg_4 * 4);
      }
      else {
        player_idx = *(int *)(&DAT_0050a870 + arg_4 * 4);
      }
      if (player_idx < match_count) {
        match_count = match_count + -7;
      }
    }
  }
  else {
    if ((arg_3 & 3) == 0) {
      match_count = *(int *)(&DAT_0050a834 + arg_4 * 4);
    }
    else {
      match_count = *(int *)(&DAT_0050a86c + arg_4 * 4);
    }
    match_count = match_count + arg_7;
  }
  if (arg_1 == 1) {
    DAT_0050a7f4 = match_count;
    DAT_0050a7f8 = ((arg_8 * 0x3c + arg_9) * 0x3c + arg_10) * 1000 + arg_11;
    DAT_0050a7f0 = arg_3;
  }
  else {
    DAT_0050a804 = match_count;
    DAT_0050a808 = ((arg_8 * 0x3c + arg_9) * 0x3c + arg_10) * 1000 + arg_11 + DAT_0050a758 * 1000;
    if (DAT_0050a808 < 0) {
      DAT_0050a808 = DAT_0050a808 + 86399999;
    }
    else if (86399999 < DAT_0050a808) {
      DAT_0050a808 = DAT_0050a808 + -86399999;
    }
    DAT_0050a800 = arg_3;
  }
  return;
}



/*
 * Decompiled function: _gmtime
 * Entry Point: 004ea210
 * Size: 487 bytes
 */


/* Library Function - Single Match
    _gmtime
   
   Library: Visual Studio 1998 Debug */

tm * __cdecl _gmtime(time_t *ptr_1)

{
  int val_1;
  bool flag_2;
  tm *ptVar3;
  int val_4;
  int target_idx;
  uint8_t *player_idx;
  int card_idx;
  
  val_4 = (int)*ptr_1;
  flag_2 = false;
  if (val_4 < 0) {
    ptVar3 = (tm *)0x0;
  }
  else {
    val_1 = val_4 % 0x7861f80;
    val_4 = (val_4 / 0x7861f80) * 4;
    target_idx = val_4 + 0x46;
    card_idx = val_1;
    if (0x1e1337f < val_1) {
      target_idx = val_4 + 0x47;
      card_idx = val_1 + -0x1e13380;
      if (0x1e1337f < card_idx) {
        target_idx = val_4 + 0x48;
        card_idx = val_1 + -0x3c26700;
        if (card_idx < 0x1e28500) {
          flag_2 = true;
        }
        else {
          target_idx = val_4 + 0x49;
          card_idx = val_1 + -0x5a4ec00;
        }
      }
    }
    DAT_0050a824 = target_idx;
    DAT_0050a82c = card_idx / 0x15180;
    if (flag_2) {
      player_idx = &DAT_0050a838;
    }
    else {
      player_idx = &DAT_0050a870;
    }
    for (target_idx = 1; *(int *)(player_idx + target_idx * 4) < DAT_0050a82c; target_idx = target_idx + 1) {
    }
    DAT_0050a820 = target_idx + -1;
    DAT_0050a81c = DAT_0050a82c - *(int *)(player_idx + DAT_0050a820 * 4);
    DAT_0050a828 = ((int)*ptr_1 / 0x15180 + 4) % 7;
    DAT_0050a818 = (card_idx % 0x15180) / 0xe10;
    val_4 = (card_idx % 0x15180) % 0xe10;
    DAT_0050a814 = val_4 / 0x3c;
    DAT_0050a810 = val_4 % 0x3c;
    DAT_0050a830 = 0;
    ptVar3 = (tm *)&DAT_0050a810;
  }
  return ptVar3;
}



/*
 * Decompiled function: __statusfp
 * Entry Point: 004ea400
 * Size: 35 bytes
 */


/* Library Function - Single Match
    __statusfp
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl __statusfp(void)

{
  uint32_t uval_1;
  uint8_t in_FPUStatusWord;
  
  uval_1 = __abstract_sw(in_FPUStatusWord);
  return uval_1;
}



/*
 * Decompiled function: __clearfp
 * Entry Point: 004ea430
 * Size: 36 bytes
 */


/* Library Function - Single Match
    __clearfp
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl __clearfp(void)

{
  uint32_t uval_1;
  uint8_t in_FPUStatusWord;
  
  uval_1 = __abstract_sw(in_FPUStatusWord);
  return uval_1;
}



/*
 * Decompiled function: __control87
 * Entry Point: 004ea460
 * Size: 79 bytes
 */


/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl __control87(uint32_t arg1,uint32_t arg2)

{
  uint32_t uval_1;
  int16_t in_FPUControlWord;
  int32_t player_idx;
  
  player_idx = CONCAT22(player_idx._2_2_,in_FPUControlWord);
  uval_1 = __abstract_cw(player_idx);
  uval_1 = ~arg2 & uval_1 | arg1 & arg2;
  __hw_cw(uval_1);
  return uval_1;
}



/*
 * Decompiled function: __controlfp
 * Entry Point: 004ea4b0
 * Size: 37 bytes
 */


/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 1998 Debug */

uint32_t __cdecl __controlfp(uint32_t arg1,uint32_t arg2)

{
  uint32_t uval_1;
  
  uval_1 = __control87(arg1,arg2 & 0xfff7ffff);
  return uval_1;
}



/*
 * Decompiled function: __fpreset
 * Entry Point: 004ea4e0
 * Size: 89 bytes
 */


/* Library Function - Single Match
    __fpreset
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fpreset(void)

{
  int val_1;
  
  val_1 = DAT_0050a670;
  __setdefaultprecision();
  if ((val_1 != 0) && ((**(uint32_t **)(val_1 + 4) & 0x10008) != 0)) {
    val_1 = *(int *)(val_1 + 4);
    *(int32_t *)(val_1 + 0x20) = 0;
    *(int32_t *)(val_1 + 0x24) = 0xffff;
  }
  return;
}



/*
 * Decompiled function: __abstract_cw
 * Entry Point: 004ea540
 * Size: 308 bytes
 */


/* Library Function - Single Match
    __abstract_cw
   
   Library: Visual Studio 1998 Debug */

uint32_t __abstract_cw(uint32_t arg_1)

{
  uint32_t uval_1;
  int32_t slot_idx;
  
  slot_idx = 0;
  if ((arg_1 & 1) != 0) {
    slot_idx = 0x10;
  }
  if ((arg_1 & 4) != 0) {
    slot_idx = slot_idx | 8;
  }
  if ((arg_1 & 8) != 0) {
    slot_idx = slot_idx | 4;
  }
  if ((arg_1 & 0x10) != 0) {
    slot_idx = slot_idx | 2;
  }
  if ((arg_1 & 0x20) != 0) {
    slot_idx = slot_idx | 1;
  }
  if ((arg_1 & 2) != 0) {
    slot_idx = slot_idx | 0x80000;
  }
  uval_1 = arg_1 & 0xc00;
  if (uval_1 < 0x401) {
    if (uval_1 == 0x400) {
      slot_idx = slot_idx | 0x100;
    }
  }
  else if (uval_1 == 0x800) {
    slot_idx = slot_idx | 0x200;
  }
  else if (uval_1 == 0xc00) {
    slot_idx = slot_idx | 0x300;
  }
  if ((arg_1 & 0x300) == 0) {
    slot_idx = slot_idx | 0x20000;
  }
  else if ((arg_1 & 0x300) == 0x200) {
    slot_idx = slot_idx | 0x10000;
  }
  if ((arg_1 & 0x1000) != 0) {
    slot_idx = slot_idx | 0x40000;
  }
  return slot_idx;
}



/*
 * Decompiled function: __hw_cw
 * Entry Point: 004ea690
 * Size: 431 bytes
 */


/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 1998 Debug */

int32_t __hw_cw(uint32_t arg_1)

{
  uint16_t uval_1;
  uint32_t uval_2;
  
  uval_1 = (uint16_t)((arg_1 & 0x10) != 0);
  if ((arg_1 & 8) != 0) {
    uval_1 = uval_1 | 4;
  }
  if ((arg_1 & 4) != 0) {
    uval_1 = uval_1 | 8;
  }
  if ((arg_1 & 2) != 0) {
    uval_1 = uval_1 | 0x10;
  }
  if ((arg_1 & 1) != 0) {
    uval_1 = uval_1 | 0x20;
  }
  if ((arg_1 & 0x80000) != 0) {
    uval_1 = uval_1 | 2;
  }
  uval_2 = arg_1 & 0x300;
  if (uval_2 < 0x101) {
    if (uval_2 == 0x100) {
      uval_1 = uval_1 | 0x400;
    }
  }
  else if (uval_2 == 0x200) {
    uval_1 = uval_1 | 0x800;
  }
  else if (uval_2 == 0x300) {
    uval_1 = uval_1 | 0xc00;
  }
  uval_2 = arg_1 & 0x30000;
  if (uval_2 == 0) {
    uval_2 = uval_1 | 0x300;
    uval_1 = (uint16_t)uval_2;
  }
  else if (uval_2 == 0x10000) {
    uval_2 = uval_1 | 0x200;
    uval_1 = (uint16_t)uval_2;
  }
  if ((arg_1 & 0x40000) != 0) {
    uval_2 = uval_1 | 0x1000;
    uval_1 = (uint16_t)uval_2;
  }
  return CONCAT22((short)(uval_2 >> 0x10),uval_1);
}



/*
 * Decompiled function: __abstract_sw
 * Entry Point: 004ea860
 * Size: 116 bytes
 */


/* Library Function - Single Match
    __abstract_sw
   
   Library: Visual Studio 1998 Debug */

uint32_t __abstract_sw(uint8_t arg_1)

{
  int32_t slot_idx;
  
  slot_idx = 0;
  if ((arg_1 & 1) != 0) {
    slot_idx = 0x10;
  }
  if ((arg_1 & 4) != 0) {
    slot_idx = slot_idx | 8;
  }
  if ((arg_1 & 8) != 0) {
    slot_idx = slot_idx | 4;
  }
  if ((arg_1 & 0x10) != 0) {
    slot_idx = slot_idx | 2;
  }
  if ((arg_1 & 0x20) != 0) {
    slot_idx = slot_idx | 1;
  }
  if ((arg_1 & 2) != 0) {
    slot_idx = slot_idx | 0x80000;
  }
  return slot_idx;
}



/*
 * Decompiled function: __fptrap
 * Entry Point: 004ea8e0
 * Size: 21 bytes
 */


/* Library Function - Single Match
    __fptrap
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fptrap(void)

{
  __amsg_exit(2);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004ea900
 * Entry Point: 004ea900
 * Size: 22 bytes
 */


int Mem_AllocOrFree_004ea900(int player_id)

{
  return arg_1 + 0x20;
}



/*
 * Decompiled function: _tolower
 * Entry Point: 004ea920
 * Size: 313 bytes
 */


/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Debug */

int __cdecl _tolower(int player_id)

{
  int val_1;
  BOOL unaff_ESI;
  int unaff_EDI;
  uint32_t player_idx;
  uint16_t card_idx [2];
  uint8_t match_count;
  uint8_t local_b;
  uint8_t local_a;
  LPCSTR slot_idx;
  
  if (DAT_0050a730 == (_locale_t)0x0) {
    if ((0x40 < arg_1) && (arg_1 < 0x5b)) {
      arg_1 = arg_1 + 0x20;
    }
  }
  else {
    if (arg_1 < 0x100) {
      if (DAT_005096ac < 2) {
        player_idx = *(uint16_t *)(PTR_DAT_005094a0 + arg_1 * 2) & 1;
      }
      else {
        player_idx = __isctype(arg_1,1);
      }
      if (player_idx == 0) {
        return arg_1;
      }
    }
    if ((*(uint16_t *)(PTR_DAT_005094a0 + ((uint32_t)arg_1 >> 8 & 0xff) * 2) & 0x8000) == 0) {
      match_count = (uint8_t)arg_1;
      local_b = 0;
      slot_idx = (LPCSTR)0x1;
    }
    else {
      match_count = (uint8_t)((uint32_t)arg_1 >> 8);
      local_b = (uint8_t)arg_1;
      local_a = 0;
      slot_idx = (LPCSTR)0x2;
    }
    val_1 = ___crtLCMapStringA(DAT_0050a730,(LPCWSTR)0x100,(DWORD)&match_count,slot_idx,(int)card_idx,
                               (LPSTR)0x3,0,unaff_EDI,unaff_ESI);
    if (val_1 != 0) {
      if (val_1 == 1) {
        arg_1 = (int)(uint8_t)card_idx[0];
      }
      else {
        arg_1 = (int)card_idx[0];
      }
    }
  }
  return arg_1;
}



/*
 * Decompiled function: __ZeroTail
 * Entry Point: 004eaa60
 * Size: 153 bytes
 */


/* Library Function - Single Match
    __ZeroTail
   
   Library: Visual Studio 1998 Debug */

int32_t __ZeroTail(int arg1,int arg2)

{
  uint32_t uval_1;
  uint8_t flag_2;
  int card_idx;
  uint8_t slot_idx;
  
  card_idx = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  flag_2 = (uint8_t)(arg2 >> 0x1f);
  slot_idx = 0x1f - ((((uint8_t)arg2 ^ flag_2) - flag_2 & 0x1f ^ flag_2) - flag_2);
  uval_1 = ~(-1 << (slot_idx & 0x1f)) & *(uint32_t *)(arg1 + card_idx * 4);
  while( true ) {
    if (uval_1 != 0) {
      return 0;
    }
    card_idx = card_idx + 1;
    if (2 < card_idx) break;
    uval_1 = *(uint32_t *)(arg1 + card_idx * 4);
  }
  return 1;
}



/*
 * Decompiled function: __IncMan
 * Entry Point: 004eab00
 * Size: 179 bytes
 */


/* Library Function - Single Match
    __IncMan
   
   Library: Visual Studio 1998 Debug */

int __IncMan(int arg1,int arg2)

{
  uint8_t flag_1;
  int32_t player_idx;
  int32_t card_idx;
  uint8_t slot_idx;
  
  card_idx = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  flag_1 = (uint8_t)(arg2 >> 0x1f);
  slot_idx = 0x1f - ((((uint8_t)arg2 ^ flag_1) - flag_1 & 0x1f ^ flag_1) - flag_1);
  player_idx = ___addl(*(uint32_t *)(arg1 + card_idx * 4),1 << (slot_idx & 0x1f),
                     (uint32_t *)(card_idx * 4 + arg1));
  while ((card_idx = card_idx + -1, -1 < card_idx && (player_idx != 0))) {
    player_idx = ___addl(*(uint32_t *)(arg1 + card_idx * 4),1,(uint32_t *)(card_idx * 4 + arg1));
  }
  return player_idx;
}



/*
 * Decompiled function: __RoundMan
 * Entry Point: 004eabc0
 * Size: 220 bytes
 */


/* Library Function - Single Match
    __RoundMan
   
   Library: Visual Studio 1998 Debug */

int32_t __RoundMan(int arg1,int arg2)

{
  uint32_t *u_ptr_1;
  uint8_t flag_2;
  int val_3;
  int32_t color_idx;
  int32_t player_idx;
  uint8_t match_count;
  
  color_idx = 0;
  player_idx = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  flag_2 = (uint8_t)(arg2 >> 0x1f);
  match_count = 0x1f - ((((uint8_t)arg2 ^ flag_2) - flag_2 & 0x1f ^ flag_2) - flag_2);
  if ((1 << (match_count & 0x1f) & *(uint32_t *)(arg1 + player_idx * 4)) != 0) {
    val_3 = __ZeroTail(arg1,arg2 + 1);
    if (val_3 == 0) {
      color_idx = __IncMan(arg1,arg2 + -1);
    }
  }
  u_ptr_1 = (uint32_t *)(arg1 + player_idx * 4);
  *u_ptr_1 = *u_ptr_1 & -1 << (match_count & 0x1f);
  while (player_idx = player_idx + 1, player_idx < 3) {
    *(int32_t *)(arg1 + player_idx * 4) = 0;
  }
  return color_idx;
}



/*
 * Decompiled function: __CopyMan
 * Entry Point: 004eaca0
 * Size: 74 bytes
 */


/* Library Function - Single Match
    __CopyMan
   
   Library: Visual Studio 1998 Debug */

void __CopyMan(int32_t *arg1,int32_t *arg2)

{
  int card_idx;
  int32_t *match_count;
  int32_t *slot_idx;
  
  slot_idx = arg2;
  match_count = arg1;
  for (card_idx = 0; card_idx < 3; card_idx = card_idx + 1) {
    *match_count = *slot_idx;
    slot_idx = slot_idx + 1;
    match_count = match_count + 1;
  }
  return;
}



/*
 * Decompiled function: __FillZeroMan
 * Entry Point: 004eacf0
 * Size: 57 bytes
 */


/* Library Function - Single Match
    __FillZeroMan
   
   Library: Visual Studio 1998 Debug */

void __FillZeroMan(int player_id)

{
  int32_t slot_idx;
  
  for (slot_idx = 0; slot_idx < 3; slot_idx = slot_idx + 1) {
    *(int32_t *)(arg_1 + slot_idx * 4) = 0;
  }
  return;
}



/*
 * Decompiled function: __IsZeroMan
 * Entry Point: 004ead30
 * Size: 77 bytes
 */


/* Library Function - Single Match
    __IsZeroMan
   
   Library: Visual Studio 1998 Debug */

int32_t __IsZeroMan(int player_id)

{
  int slot_idx;
  
  slot_idx = 0;
  while( true ) {
    if (2 < slot_idx) {
      return 1;
    }
    if (*(int *)(arg_1 + slot_idx * 4) != 0) break;
    slot_idx = slot_idx + 1;
  }
  return 0;
}



/*
 * Decompiled function: __ShrMan
 * Entry Point: 004ead80
 * Size: 235 bytes
 */


/* Library Function - Single Match
    __ShrMan
   
   Library: Visual Studio 1998 Debug */

void __ShrMan(int arg1,int arg2)

{
  uint32_t *u_ptr_1;
  uint32_t uval_2;
  int val_3;
  int32_t card_idx;
  int32_t match_count;
  uint8_t slot_idx;
  
  val_3 = (int)(arg2 + (arg2 >> 0x1f & 0x1fU)) >> 5;
  slot_idx = (uint8_t)(arg2 >> 0x1f);
  slot_idx = (((uint8_t)arg2 ^ slot_idx) - slot_idx & 0x1f ^ slot_idx) - slot_idx;
  match_count = 0;
  for (card_idx = 0; card_idx < 3; card_idx = card_idx + 1) {
    uval_2 = *(uint32_t *)(arg1 + card_idx * 4);
    u_ptr_1 = (uint32_t *)(arg1 + card_idx * 4);
    *u_ptr_1 = *u_ptr_1 >> (slot_idx & 0x1f);
    u_ptr_1 = (uint32_t *)(arg1 + card_idx * 4);
    *u_ptr_1 = *u_ptr_1 | match_count;
    match_count = (uval_2 & ~(-1 << (slot_idx & 0x1f))) << (0x20 - slot_idx & 0x1f);
  }
  for (card_idx = 2; -1 < card_idx; card_idx = card_idx + -1) {
    if (card_idx < val_3) {
      *(int32_t *)(arg1 + card_idx * 4) = 0;
    }
    else {
      *(int32_t *)(arg1 + card_idx * 4) = *(int32_t *)(arg1 + (card_idx - val_3) * 4);
    }
  }
  return;
}



/*
 * Decompiled function: __ld12cvt
 * Entry Point: 004eae70
 * Size: 616 bytes
 */


/* Library Function - Single Match
    __ld12cvt
   
   Library: Visual Studio 1998 Debug */

int32_t __ld12cvt(uint16_t *arg_1,uint32_t *arg_2,int *arg_3)

{
  int val_1;
  int32_t local_34 [4];
  uint32_t local_24;
  int32_t loop_idx;
  uint32_t color_idx;
  uint32_t target_idx;
  int player_idx;
  uint8_t card_idx;
  int match_count;
  int slot_idx;
  
  slot_idx = (arg_1[5] & 0x7fff) - 0x3fff;
  local_24 = arg_1[5] & 0x8000;
  color_idx = *(uint32_t *)(arg_1 + 3);
  target_idx = *(uint32_t *)(arg_1 + 1);
  player_idx = (uint32_t)*arg_1 << 0x10;
  if (slot_idx == -0x3fff) {
    match_count = 0;
    val_1 = __IsZeroMan((int)&color_idx);
    if (val_1 == 0) {
      __FillZeroMan((int)&color_idx);
      loop_idx = 2;
    }
    else {
      loop_idx = 0;
    }
  }
  else {
    __CopyMan(local_34,&color_idx);
    val_1 = __RoundMan((int)&color_idx,arg_3[2]);
    if (val_1 != 0) {
      slot_idx = slot_idx + 1;
    }
    if (slot_idx < arg_3[1] - arg_3[2]) {
      __FillZeroMan((int)&color_idx);
      match_count = 0;
      loop_idx = 2;
    }
    else if (arg_3[1] < slot_idx) {
      if (slot_idx < *arg_3) {
        match_count = arg_3[5] + slot_idx;
        color_idx = color_idx & 0x7fffffff;
        __ShrMan((int)&color_idx,arg_3[3]);
        loop_idx = 0;
      }
      else {
        __FillZeroMan((int)&color_idx);
        color_idx = color_idx | 0x80000000;
        __ShrMan((int)&color_idx,arg_3[3]);
        match_count = arg_3[5] + *arg_3;
        loop_idx = 1;
      }
    }
    else {
      val_1 = arg_3[1] - slot_idx;
      __CopyMan(&color_idx,local_34);
      __ShrMan((int)&color_idx,val_1);
      __RoundMan((int)&color_idx,arg_3[2]);
      __ShrMan((int)&color_idx,arg_3[3] + 1);
      match_count = 0;
      loop_idx = 2;
    }
  }
  card_idx = 0x20 - ((char)arg_3[3] + '\x01');
  color_idx = (local_24 == 0) - 1 & 0x80000000 | match_count << (card_idx & 0x1f) | color_idx;
  if (arg_3[4] == 0x40) {
    arg_2[1] = color_idx;
    *arg_2 = target_idx;
  }
  else if (arg_3[4] == 0x20) {
    *arg_2 = color_idx;
  }
  return loop_idx;
}



/*
 * Decompiled function: FID_conflict:__ld12tod
 * Entry Point: 004eb0e0
 * Size: 37 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Debug */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((uint16_t *)ptr_1,(uint32_t *)ptr_2,(int *)&DAT_0050a8a8);
  return IVar1;
}



/*
 * Decompiled function: FID_conflict:__ld12tod
 * Entry Point: 004eb110
 * Size: 37 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __ld12tod
    __ld12tof
   
   Library: Visual Studio 1998 Debug */

INTRNCVT_STATUS __cdecl FID_conflict___ld12tod(_LDBL12 *ptr_1,_CRT_DOUBLE *ptr_2)

{
  INTRNCVT_STATUS IVar1;
  
  IVar1 = __ld12cvt((uint16_t *)ptr_1,(uint32_t *)ptr_2,(int *)&DAT_0050a8c0);
  return IVar1;
}



/*
 * Decompiled function: __ld12told
 * Entry Point: 004eb140
 * Size: 201 bytes
 */


/* Library Function - Single Match
    __ld12told
   
   Library: Visual Studio 1998 Debug */

INTRNCVT_STATUS __cdecl __ld12told(_LDBL12 *ptr_1,_LDOUBLE *ptr_2)

{
  uint16_t uval_1;
  int val_2;
  INTRNCVT_STATUS target_idx;
  int32_t player_idx;
  int32_t card_idx;
  int match_count;
  int32_t slot_idx;
  
  slot_idx = CONCAT22(slot_idx._2_2_,*(int16_t *)(ptr_1->ld12 + 10)) & 0xffff7fff;
  uval_1 = *(uint16_t *)(ptr_1->ld12 + 10);
  player_idx = *(int32_t *)(ptr_1->ld12 + 6);
  card_idx = *(int32_t *)(ptr_1->ld12 + 2);
  match_count = (uint32_t)*(uint16_t *)ptr_1->ld12 << 0x10;
  val_2 = __RoundMan((int)&player_idx,0x40);
  if (val_2 != 0) {
    player_idx = 0x80000000;
    slot_idx = (uint32_t)(uint16_t)((short)slot_idx + 1);
  }
  target_idx = (INTRNCVT_STATUS)((slot_idx & 0xffff) == 0x7fff);
  *(int32_t *)(ptr_2->ld + 4) = player_idx;
  *(int32_t *)ptr_2->ld = card_idx;
  *(uint16_t *)(ptr_2->ld + 8) = uval_1 & 0x8000 | (uint16_t)slot_idx;
  return target_idx;
}



/*
 * Decompiled function: FID_conflict:__atodbl
 * Entry Point: 004eb210
 * Size: 58 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Debug */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *ptr_1,char *mode_str)

{
  INTRNCVT_STATUS IVar1;
  char *player_idx;
  _LDBL12 card_idx;
  
  ___strgtold12(&card_idx,&player_idx,str_2,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&card_idx,(_CRT_DOUBLE *)ptr_1);
  return IVar1;
}



/*
 * Decompiled function: __atoldbl
 * Entry Point: 004eb250
 * Size: 58 bytes
 */


/* Library Function - Single Match
    __atoldbl
   
   Library: Visual Studio 1998 Debug */

int __cdecl __atoldbl(_LDOUBLE *ptr_1,char *mode_str)

{
  INTRNCVT_STATUS IVar1;
  char *player_idx;
  _LDBL12 card_idx;
  
  ___strgtold12(&card_idx,&player_idx,str_2,1,0,0,0);
  IVar1 = __ld12told(&card_idx,ptr_1);
  return IVar1;
}



/*
 * Decompiled function: FID_conflict:__atodbl
 * Entry Point: 004eb290
 * Size: 58 bytes
 */


/* Library Function - Multiple Matches With Different Base Names
    __atodbl
    __atoflt
   
   Library: Visual Studio 1998 Debug */

int __cdecl FID_conflict___atodbl(_CRT_FLOAT *ptr_1,char *mode_str)

{
  INTRNCVT_STATUS IVar1;
  char *player_idx;
  _LDBL12 card_idx;
  
  ___strgtold12(&card_idx,&player_idx,str_2,0,0,0,0);
  IVar1 = FID_conflict___ld12tod(&card_idx,(_CRT_DOUBLE *)ptr_1);
  return IVar1;
}



/*
 * Decompiled function: __fptostr
 * Entry Point: 004eb2d0
 * Size: 215 bytes
 */


/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __fptostr(char *x,size_t y,int width,STRFLT height)

{
  char *char_ptr_1;
  char *match_count;
  char *slot_idx;
  
  match_count = *(char **)(width + 0xc);
  *x = '0';
  char_ptr_1 = x;
  for (; slot_idx = char_ptr_1 + 1, 0 < (int)y; y = y - 1) {
    if (*match_count == '\0') {
      *slot_idx = '0';
    }
    else {
      *slot_idx = *match_count;
      match_count = match_count + 1;
    }
    char_ptr_1 = slot_idx;
  }
  *slot_idx = '\0';
  if ((-1 < (int)y) && (slot_idx = char_ptr_1, '4' < *match_count)) {
    for (; *slot_idx == '9'; slot_idx = slot_idx + -1) {
      *slot_idx = '0';
    }
    *slot_idx = *slot_idx + '\x01';
  }
  if (*x == '1') {
    *(int *)(width + 4) = *(int *)(width + 4) + 1;
  }
  else {
    width = Mem_AllocOrFree_004d9630((uint32_t *)x,(uint32_t *)(x + 1));
  }
  return width;
}



/*
 * Decompiled function: __fltout
 * Entry Point: 004eb3b0
 * Size: 111 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fltout
   
   Library: Visual Studio 1998 Debug */

uint8_t * __fltout(void)

{
  uint32_t card_idx;
  uint32_t match_count;
  uint16_t slot_idx;
  
  ___dtold(&card_idx,(uint32_t *)&stack0x00000004);
  _DAT_005edd00 = _I10_OUTPUT(card_idx,match_count,slot_idx,0x11,0,&DAT_005edcd8);
  _DAT_005edcf8 = (int)DAT_005edcda;
  _DAT_005edcfc = (int)DAT_005edcd8;
  _DAT_005edd04 = 0x5edcdc;
  return &DAT_005edcf8;
}



/*
 * Decompiled function: ___dtold
 * Entry Point: 004eb420
 * Size: 375 bytes
 */


/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 1998 Debug */

void ___dtold(uint32_t *arg1,uint32_t *arg2)

{
  uint16_t uval_1;
  uint32_t uval_2;
  uint16_t uval_3;
  uint32_t uval_4;
  short target_idx;
  uint32_t card_idx;
  
  card_idx = 0x80000000;
  uval_4 = (*(uint16_t *)((int)arg2 + 6) & 0x7ff0) >> 4;
  uval_1 = *(uint16_t *)((int)arg2 + 6);
  uval_2 = *arg2;
  target_idx = (short)uval_4;
  if (uval_4 == 0) {
    if (((arg2[1] & 0xfffff) == 0) && (uval_2 == 0)) {
      arg1[1] = 0;
      *arg1 = 0;
      *(int16_t *)(arg1 + 2) = 0;
      return;
    }
    uval_3 = 0x3c01;
    card_idx = 0;
  }
  else if (uval_4 == 0x7ff) {
    uval_3 = 0x7fff;
  }
  else {
    uval_3 = target_idx + 0x3c00;
  }
  arg1[1] = uval_2 >> 0x15 | (arg2[1] & 0xfffff) << 0xb | card_idx;
  *arg1 = uval_2 << 0xb;
  while ((*(uint8_t *)((int)arg1 + 7) & 0x80) == 0) {
    arg1[1] = *arg1 >> 0x1f | arg1[1] * 2;
    *arg1 = *arg1 << 1;
    uval_3 = uval_3 - 1;
  }
  *(uint16_t *)(arg1 + 2) = uval_3 | uval_1 & 0x8000;
  return;
}



/*
 * Decompiled function: _wcslen
 * Entry Point: 004eb5a0
 * Size: 66 bytes
 */


/* Library Function - Single Match
    _wcslen
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _wcslen(wchar_t *str_1)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *slot_idx;
  
  slot_idx = str_1;
  do {
    pwVar1 = slot_idx + 1;
    wVar2 = *slot_idx;
    slot_idx = pwVar1;
  } while (wVar2 != L'\0');
  return ((int)pwVar1 - (int)str_1 >> 1) - 1;
}



