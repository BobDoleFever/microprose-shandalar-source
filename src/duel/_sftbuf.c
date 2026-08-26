/*
 * _sftbuf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 37
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __stbuf
 * Entry Point: 004e6640
 * Size: 330 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __stbuf
   
   Library: Visual Studio 1998 Debug */

int __cdecl __stbuf(FILE *fp)

{
  code *char_ptr_1;
  int val_2;
  int32_t uval_3;
  int match_count;
  
  if ((fp == (FILE *)0x0) && (val_2 = __CrtDbgReport(2,0x4f0ef0,0x41,0,"str != NULL"), val_2 == 1))
  {
    char_ptr_1 = (code *)swi(3);
    val_2 = (*char_ptr_1)();
    return val_2;
  }
  val_2 = __isatty(fp->_file);
  if (val_2 == 0) {
    val_2 = 0;
  }
  else {
    if (fp == (FILE *)0x509770) {
      match_count = 0;
    }
    else {
      if (fp != (FILE *)&DAT_00509790) {
        return 0;
      }
      match_count = 1;
    }
    _DAT_005099d0 = _DAT_005099d0 + 1;
    if ((fp->_flag & 0x10cU) == 0) {
      if (*(int *)(&DAT_0050a5a8 + match_count * 4) == 0) {
        uval_3 = __malloc_dbg(0x1000,2,"_sftbuf.c",0x5e);
        *(int32_t *)(&DAT_0050a5a8 + match_count * 4) = uval_3;
        if (*(int *)(&DAT_0050a5a8 + match_count * 4) == 0) {
          return 0;
        }
      }
      fp->_base = *(char **)(&DAT_0050a5a8 + match_count * 4);
      fp->_ptr = fp->_base;
      fp->_bufsiz = 0x1000;
      fp->_cnt = fp->_bufsiz;
      fp->_flag = fp->_flag | 0x1102;
      val_2 = 1;
    }
    else {
      val_2 = 0;
    }
  }
  return val_2;
}



/*
 * Decompiled function: __ftbuf
 * Entry Point: 004e6790
 * Size: 182 bytes
 */


/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 1998 Debug */

void __cdecl __ftbuf(int arg1,FILE *arg2)

{
  code *char_ptr_1;
  int val_2;
  
  if (((arg1 != 0) && (arg1 != 1)) &&
     (val_2 = __CrtDbgReport(2,0x4f0ef0,0x96,0,"flag == 0 || flag == 1"), val_2 == 1)) {
    char_ptr_1 = (code *)swi(3);
    (*char_ptr_1)();
    return;
  }
  if (arg1 == 0) {
    if ((arg2->_flag & 0x1000) != 0) {
      __flush(arg2);
    }
  }
  else if ((arg2->_flag & 0x1000) != 0) {
    __flush(arg2);
    arg2->_flag = arg2->_flag & 0xffffeeff;
    arg2->_bufsiz = 0;
    arg2->_ptr = (char *)0x0;
    arg2->_base = arg2->_ptr;
  }
  return;
}



/*
 * Decompiled function: _asctime
 * Entry Point: 004e6850
 * Size: 345 bytes
 */


/* Library Function - Single Match
    _asctime
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _asctime(tm *ptr_1)

{
  int val_1;
  int val_2;
  uint8_t *u_ptr_3;
  char *filepath;
  int player_idx;
  char *slot_idx;
  
  slot_idx = &DAT_005edaf8;
  val_1 = ptr_1->tm_wday;
  val_2 = ptr_1->tm_mon;
  for (player_idx = 0; player_idx < 3; player_idx = player_idx + 1) {
    *slot_idx = "SunMonTueWedThuFriSat"[val_1 * 3 + player_idx];
    slot_idx[4] = "JanFebMarAprMayJunJulAugSepOctNovDec"[val_2 * 3 + player_idx];
    slot_idx = slot_idx + 1;
  }
  *slot_idx = ' ';
  slot_idx[4] = ' ';
  u_ptr_3 = (uint8_t *)store_dt(slot_idx + 5,ptr_1->tm_mday);
  *u_ptr_3 = 0x20;
  u_ptr_3 = (uint8_t *)store_dt(u_ptr_3 + 1,ptr_1->tm_hour);
  *u_ptr_3 = 0x3a;
  u_ptr_3 = (uint8_t *)store_dt(u_ptr_3 + 1,ptr_1->tm_min);
  *u_ptr_3 = 0x3a;
  u_ptr_3 = (uint8_t *)store_dt(u_ptr_3 + 1,ptr_1->tm_sec);
  *u_ptr_3 = 0x20;
  str_1 = (char *)store_dt(u_ptr_3 + 1,ptr_1->tm_year / 100 + 0x13);
  u_ptr_3 = (uint8_t *)store_dt(str_1,ptr_1->tm_year % 100);
  *u_ptr_3 = 10;
  u_ptr_3[1] = 0;
  return &DAT_005edaf8;
}



/*
 * Decompiled function: store_dt
 * Entry Point: 004e69b0
 * Size: 63 bytes
 */


/* Library Function - Single Match
    _store_dt
   
   Library: Visual Studio 1998 Debug */

char * __cdecl store_dt(char *filepath,int arg2)

{
  *str_1 = (char)(arg2 / 10) + '0';
  str_1[1] = (char)(arg2 % 10) + '0';
  return str_1 + 2;
}



/*
 * Decompiled function: _localtime
 * Entry Point: 004e69f0
 * Size: 597 bytes
 */


/* Library Function - Single Match
    _localtime
   
   Library: Visual Studio 1998 Debug */

tm * __cdecl _localtime(time_t *ptr_1)

{
  tm *ptr_1_00;
  int val_1;
  int slot_idx;
  
  if ((int)*ptr_1 < 0) {
    ptr_1_00 = (tm *)0x0;
  }
  else {
    ___tzset();
    if (((int)*ptr_1 < 0x3f481) || (0x7ffc0b7e < (int)*ptr_1)) {
      ptr_1_00 = _gmtime(ptr_1);
      val_1 = __isindst(ptr_1_00);
      if (val_1 == 0) {
        slot_idx = ptr_1_00->tm_sec - DAT_0050a750;
      }
      else {
        slot_idx = ptr_1_00->tm_sec - (DAT_0050a750 + DAT_0050a758);
      }
      ptr_1_00->tm_sec = slot_idx % 0x3c;
      if (ptr_1_00->tm_sec < 0) {
        ptr_1_00->tm_sec = ptr_1_00->tm_sec + 0x3c;
        slot_idx = slot_idx + -0x3c;
      }
      slot_idx = ptr_1_00->tm_min + slot_idx / 0x3c;
      ptr_1_00->tm_min = slot_idx % 0x3c;
      if (ptr_1_00->tm_min < 0) {
        ptr_1_00->tm_min = ptr_1_00->tm_min + 0x3c;
        slot_idx = slot_idx + -0x3c;
      }
      slot_idx = ptr_1_00->tm_hour + slot_idx / 0x3c;
      ptr_1_00->tm_hour = slot_idx % 0x18;
      if (ptr_1_00->tm_hour < 0) {
        ptr_1_00->tm_hour = ptr_1_00->tm_hour + 0x18;
        slot_idx = slot_idx + -0x18;
      }
      slot_idx = slot_idx / 0x18;
      if (slot_idx < 1) {
        if (slot_idx < 0) {
          ptr_1_00->tm_wday = (ptr_1_00->tm_wday + 7 + slot_idx) % 7;
          ptr_1_00->tm_mday = ptr_1_00->tm_mday + slot_idx;
          if (ptr_1_00->tm_mday < 1) {
            ptr_1_00->tm_mday = ptr_1_00->tm_mday + 0x1f;
            ptr_1_00->tm_yday = 0x16c;
            ptr_1_00->tm_mon = 0xb;
            ptr_1_00->tm_year = ptr_1_00->tm_year + -1;
          }
          else {
            ptr_1_00->tm_yday = ptr_1_00->tm_yday + slot_idx;
          }
        }
      }
      else {
        ptr_1_00->tm_wday = (ptr_1_00->tm_wday + slot_idx) % 7;
        ptr_1_00->tm_mday = ptr_1_00->tm_mday + slot_idx;
        ptr_1_00->tm_yday = ptr_1_00->tm_yday + slot_idx;
      }
    }
    else {
      slot_idx = (int)*ptr_1 - DAT_0050a750;
      ptr_1_00 = _gmtime((time_t *)&slot_idx);
      if ((DAT_0050a754 != 0) && (val_1 = __isindst(ptr_1_00), val_1 != 0)) {
        slot_idx = slot_idx - DAT_0050a758;
        ptr_1_00 = _gmtime((time_t *)&slot_idx);
        ptr_1_00->tm_isdst = 1;
      }
    }
  }
  return ptr_1_00;
}



/*
 * Decompiled function: ___loctotime_t
 * Entry Point: 004e6c50
 * Size: 274 bytes
 */


/* Library Function - Single Match
    ___loctotime_t
   
   Library: Visual Studio 1998 Debug */

int ___loctotime_t(int player_id,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7)

{
  uint32_t uval_1;
  int val_2;
  int local_30;
  tm local_2c;
  int slot_idx;
  
  uval_1 = arg_1 - 0x76c;
  if (((int)uval_1 < 0x46) || (0x8a < (int)uval_1)) {
    slot_idx = -1;
  }
  else {
    local_30 = *(int *)(&DAT_0050a86c + arg_2 * 4) + arg_3;
    if (((uval_1 & 3) == 0) && (2 < arg_2)) {
      local_30 = local_30 + 1;
    }
    slot_idx = ((((arg_1 + -0x7b2) * 0x16d + (arg_1 + -0x76d >> 2) + -0x11 + local_30) * 0x18 + arg_4
               ) * 0x3c + arg_5) * 0x3c + arg_6;
    ___tzset();
    slot_idx = slot_idx + DAT_0050a750;
    local_2c.tm_yday = local_30;
    local_2c.tm_mon = arg_2 + -1;
    local_2c.tm_hour = arg_4;
    if ((arg_7 == 1) ||
       (((arg_7 == -1 && (DAT_0050a754 != 0)) &&
        (local_2c.tm_year = uval_1, val_2 = __isindst(&local_2c), val_2 != 0)))) {
      slot_idx = slot_idx + DAT_0050a758;
    }
  }
  return slot_idx;
}



/*
 * Decompiled function: __setdefaultprecision
 * Entry Point: 004e6d70
 * Size: 29 bytes
 */


/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Debug */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}



/*
 * Decompiled function: __ms_p5_test_fdiv
 * Entry Point: 004e6d90
 * Size: 94 bytes
 */


/* WARNING: Removing unreachable block (ram,0x004e6dd8) */
/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Library: Visual Studio 1998 Debug */

int32_t __ms_p5_test_fdiv(void)

{
  return 0;
}



/*
 * Decompiled function: __ms_p5_mp_test_fdiv
 * Entry Point: 004e6df0
 * Size: 86 bytes
 */


/* Library Function - Single Match
    __ms_p5_mp_test_fdiv
   
   Library: Visual Studio 1998 Debug */

void __ms_p5_mp_test_fdiv(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleA("KERNEL32");
  if ((hModule != (HMODULE)0x0) &&
     (pFVar1 = GetProcAddress(hModule,"IsProcessorFeaturePresent"), pFVar1 != (FARPROC)0x0)) {
    (*pFVar1)(0);
    return;
  }
  __ms_p5_test_fdiv();
  return;
}



/*
 * Decompiled function: __forcdecpt
 * Entry Point: 004e6e50
 * Size: 179 bytes
 */


/* Library Function - Single Match
    __forcdecpt
   
   Library: Visual Studio 1998 Debug */

void __cdecl __forcdecpt(char *filepath)

{
  char cVar1;
  int val_2;
  uint32_t card_idx;
  char match_count;
  
  val_2 = _tolower((int)*str_1);
  if (val_2 != 0x65) {
    do {
      str_1 = str_1 + 1;
      if (DAT_005096ac < 2) {
        card_idx = *(uint16_t *)(PTR_DAT_005094a0 + *str_1 * 2) & 4;
      }
      else {
        card_idx = __isctype((int)*str_1,4);
      }
    } while (card_idx != 0);
  }
  match_count = *str_1;
  *str_1 = DAT_005096b0;
  do {
    str_1 = str_1 + 1;
    cVar1 = *str_1;
    *str_1 = match_count;
    match_count = cVar1;
  } while (*str_1 != '\0');
  return;
}



/*
 * Decompiled function: __cropzeros
 * Entry Point: 004e6f10
 * Size: 223 bytes
 */


/* Library Function - Single Match
    __cropzeros
   
   Library: Visual Studio 1998 Debug */

void __cdecl __cropzeros(char *filepath)

{
  char *char_ptr_1;
  char *slot_idx;
  
  for (; (*str_1 != '\0' && (DAT_005096b0 != *str_1)); str_1 = str_1 + 1) {
  }
  if (*str_1 != '\0') {
    do {
      char_ptr_1 = str_1;
      str_1 = char_ptr_1 + 1;
      if ((*str_1 == '\0') || (*str_1 == 'e')) break;
    } while (*str_1 != 'E');
    slot_idx = str_1;
    for (str_1 = char_ptr_1; *str_1 == '0'; str_1 = str_1 + -1) {
    }
    if (DAT_005096b0 == *str_1) {
      str_1 = str_1 + -1;
    }
    do {
      str_1 = str_1 + 1;
      *str_1 = *slot_idx;
      slot_idx = slot_idx + 1;
    } while (*str_1 != '\0');
  }
  return;
}



/*
 * Decompiled function: __positive
 * Entry Point: 004e6ff0
 * Size: 50 bytes
 */


/* Library Function - Single Match
    __positive
   
   Library: Visual Studio 1998 Debug */

int __cdecl __positive(double *ptr_1)

{
  return (uint32_t)(0.0 <= *ptr_1);
}



/*
 * Decompiled function: __fassign
 * Entry Point: 004e7030
 * Size: 83 bytes
 */


/* Library Function - Single Match
    __fassign
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fassign(int player_id,char *mode_str,char *str_3)

{
  _CRT_FLOAT card_idx;
  _CRT_FLOAT match_count;
  int32_t slot_idx;
  
  if (arg_1 == 0) {
    FID_conflict___atodbl(&card_idx,str_3);
    *(float *)str_2 = card_idx.f;
  }
  else {
    FID_conflict___atodbl(&match_count,str_3);
    *(float *)str_2 = match_count.f;
    *(int32_t *)(str_2 + 4) = slot_idx;
  }
  return;
}



/*
 * Decompiled function: __cftoe
 * Entry Point: 004e7090
 * Size: 458 bytes
 */


/* Library Function - Single Match
    __cftoe
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cftoe(double *ptr_1,char *mode_str,size_t arg_3,int arg_4,int arg_5)

{
  uint8_t *u_ptr_1;
  STRFLT unaff_EDI;
  int card_idx;
  int *match_count;
  char *slot_idx;
  
  if (DAT_0050a5c8 == '\0') {
    match_count = (int *)__fltout(*(int32_t *)ptr_1,*(int32_t *)((int)ptr_1 + 4));
    __fptostr(str_2 + (uint32_t)(*match_count == 0x2d) + (uint32_t)(0 < (int)arg_3),arg_3 + 1,(int)match_count,
              unaff_EDI);
  }
  else {
    match_count = DAT_005edb14;
    __shift(str_2 + (*DAT_005edb14 == 0x2d),(uint32_t)(0 < (int)arg_3));
  }
  slot_idx = str_2;
  if (*match_count == 0x2d) {
    *str_2 = '-';
    slot_idx = str_2 + 1;
  }
  if (0 < (int)arg_3) {
    *slot_idx = slot_idx[1];
    slot_idx = slot_idx + 1;
    *slot_idx = DAT_005096b0;
  }
  u_ptr_1 = (uint8_t *)
           Mem_AllocOrFree_004d9630
                     ((uint32_t *)(slot_idx + (DAT_0050a5c8 == '\0') + arg_3),(uint32_t *)"e+000");
  if (arg_4 != 0) {
    *u_ptr_1 = 0x45;
  }
  if (*(char *)match_count[3] != '0') {
    card_idx = match_count[1] + -1;
    if (card_idx < 0) {
      card_idx = -card_idx;
      u_ptr_1[1] = 0x2d;
    }
    if (99 < card_idx) {
      u_ptr_1[2] = (char)(card_idx / 100) + u_ptr_1[2];
      card_idx = card_idx % 100;
    }
    if (9 < card_idx) {
      u_ptr_1[3] = (char)(card_idx / 10) + u_ptr_1[3];
      card_idx = card_idx % 10;
    }
    u_ptr_1[4] = u_ptr_1[4] + (char)card_idx;
  }
  return (errno_t)str_2;
}



/*
 * Decompiled function: __cftof
 * Entry Point: 004e7260
 * Size: 393 bytes
 */


/* Library Function - Single Match
    __cftof
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cftof(double *x,char *y,size_t width,int height)

{
  int val_1;
  size_t len_2;
  STRFLT unaff_EDI;
  int *match_count;
  char *slot_idx;
  
  if (DAT_0050a5c8 == '\0') {
    match_count = (int *)__fltout(*(int32_t *)x,*(int32_t *)((int)x + 4));
    __fptostr(y + (*match_count == 0x2d),match_count[1] + width,(int)match_count,unaff_EDI);
  }
  else {
    match_count = DAT_005edb14;
    if (width == DAT_0050a5cc) {
      val_1 = DAT_0050a5cc + (*DAT_005edb14 == 0x2d);
      y[val_1] = '0';
      (y + val_1)[1] = '\0';
    }
  }
  slot_idx = y;
  if (*match_count == 0x2d) {
    *y = '-';
    slot_idx = y + 1;
  }
  if (match_count[1] < 1) {
    __shift(slot_idx,1);
    *slot_idx = '0';
    slot_idx = slot_idx + 1;
  }
  else {
    slot_idx = slot_idx + match_count[1];
  }
  if (0 < (int)width) {
    __shift(slot_idx,1);
    *slot_idx = DAT_005096b0;
    if (match_count[1] < 0) {
      if (DAT_0050a5c8 == '\0') {
        len_2 = -match_count[1];
        if ((int)width <= -match_count[1]) {
          len_2 = width;
        }
      }
      else {
        len_2 = -match_count[1];
      }
      width = len_2;
      __shift(slot_idx + 1,width);
      _memset(slot_idx + 1,0x30,width);
    }
  }
  return (errno_t)y;
}



/*
 * Decompiled function: __cftog
 * Entry Point: 004e73f0
 * Size: 281 bytes
 */


/* Library Function - Single Match
    __cftog
   
   Library: Visual Studio 1998 Debug */

void __cftog(int32_t *arg_1,int y,size_t arg_3,int arg_4)

{
  char *x;
  STRFLT unaff_EDI;
  char *slot_idx;
  
  DAT_005edb14 = (int *)__fltout(*arg_1,arg_1[1]);
  DAT_0050a5cc = DAT_005edb14[1] + -1;
  x = (char *)((uint32_t)(*DAT_005edb14 == 0x2d) + y);
  __fptostr(x,arg_3,(int)DAT_005edb14,unaff_EDI);
  DAT_0050a5d0 = DAT_0050a5cc < DAT_005edb14[1] + -1;
  DAT_0050a5cc = DAT_005edb14[1] + -1;
  if ((DAT_0050a5cc < -4) || ((int)arg_3 <= DAT_0050a5cc)) {
    __cftoe_g((double *)arg_1,(char *)y,arg_3,arg_4);
  }
  else {
    if ((bool)DAT_0050a5d0) {
      do {
        slot_idx = x;
        x = slot_idx + 1;
      } while (*slot_idx != '\0');
      slot_idx[-1] = '\0';
    }
    __cftof_g((double *)arg_1,(char *)y,arg_3);
  }
  return;
}



/*
 * Decompiled function: __cftoe_g
 * Entry Point: 004e7510
 * Size: 63 bytes
 */


/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Debug */

errno_t __cftoe_g(double *arg_1,char *mode_str,size_t arg_3,int height)

{
  errno_t eVar1;
  int unaff_EDI;
  
  DAT_0050a5c8 = 1;
  eVar1 = __cftoe(arg_1,str_2,arg_3,height,unaff_EDI);
  DAT_0050a5c8 = 0;
  return eVar1;
}



/*
 * Decompiled function: __cftof_g
 * Entry Point: 004e7550
 * Size: 59 bytes
 */


/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Debug */

errno_t __cftof_g(double *arg_1,char *mode_str,size_t arg_3)

{
  errno_t eVar1;
  int unaff_EDI;
  
  DAT_0050a5c8 = 1;
  eVar1 = __cftof(arg_1,str_2,arg_3,unaff_EDI);
  DAT_0050a5c8 = 0;
  return eVar1;
}



/*
 * Decompiled function: __cfltcvt
 * Entry Point: 004e7590
 * Size: 119 bytes
 */


/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cfltcvt(double *ptr_1,char *mode_str,size_t arg_3,int arg_4,int arg_5,int arg_6)

{
  errno_t eVar1;
  int unaff_EDI;
  
  if ((arg_3 == 0x65) || (arg_3 == 0x45)) {
    eVar1 = __cftoe(ptr_1,str_2,arg_4,arg_5,unaff_EDI);
  }
  else if (arg_3 == 0x66) {
    eVar1 = __cftof(ptr_1,str_2,arg_4,unaff_EDI);
  }
  else {
    eVar1 = __cftog((int32_t *)ptr_1,(int)str_2,arg_4,arg_5);
  }
  return eVar1;
}



/*
 * Decompiled function: __shift
 * Entry Point: 004e7610
 * Size: 54 bytes
 */


/* Library Function - Single Match
    __shift
   
   Library: Visual Studio 1998 Debug */

void __shift(char *filepath,int arg2)

{
  size_t len_1;
  
  if (arg2 != 0) {
    len_1 = _strlen(str_1);
    FID_conflict__memcpy(str_1 + arg2,str_1,len_1 + 1);
  }
  return;
}



/*
 * Decompiled function: __global_unwind2
 * Entry Point: 004e7648
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __global_unwind2(PVOID arg_1)

{
  RtlUnwind(arg_1,(PVOID)0x4e7660,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}



/*
 * Decompiled function: __local_unwind2
 * Entry Point: 004e768a
 * Size: 104 bytes
 */


/* Library Function - Single Match
    __local_unwind2
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release, Visual Studio 2003 Debug, Visual
   Studio 2003 Release */

void __local_unwind2(int arg1,int arg2)

{
  int val_1;
  int val_2;
  int32_t *unaff_FS_OFFSET;
  int32_t uStack_1c;
  uint8_t *puStack_18;
  int32_t player_idx;
  int iStack_10;
  
  iStack_10 = arg1;
  puStack_18 = &LAB_004e7668;
  uStack_1c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_1c;
  while( true ) {
    val_1 = *(int *)(arg1 + 8);
    val_2 = *(int *)(arg1 + 0xc);
    if ((val_2 == -1) || (val_2 == arg2)) break;
    player_idx = *(int32_t *)(val_1 + val_2 * 0xc);
    *(int32_t *)(arg1 + 0xc) = player_idx;
    if (*(int *)(val_1 + 4 + val_2 * 0xc) == 0) {
      Mem_AllocOrFree_004e771e(0x101);
      (**(code **)(val_1 + 8 + val_2 * 0xc))();
    }
  }
  *unaff_FS_OFFSET = uStack_1c;
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_004e771e
 * Entry Point: 004e771e
 * Size: 24 bytes
 */


void Mem_AllocOrFree_004e771e(void)

{
  int32_t reg_eax;
  int frame_base;
  
  DAT_0050a5dc = *(int32_t *)(frame_base + 8);
  DAT_0050a5d8 = reg_eax;
  DAT_0050a5e0 = frame_base;
  return;
}



/*
 * Decompiled function: __XcptFilter
 * Entry Point: 004e7740
 * Size: 500 bytes
 */


/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 1998 Debug */

int __cdecl __XcptFilter(uint32_t card_id,_EXCEPTION_POINTERS *out_filter)

{
  code *char_ptr_1;
  int32_t uval_2;
  int32_t uval_3;
  int *piVar4;
  int val_5;
  int player_idx;
  
  piVar4 = (int *)xcptlookup(card_id);
  uval_3 = DAT_0050a670;
  if ((piVar4 == (int *)0x0) || (piVar4[2] == 0)) {
    val_5 = UnhandledExceptionFilter(out_filter);
  }
  else if (piVar4[2] == 5) {
    piVar4[2] = 0;
    val_5 = 1;
  }
  else if (piVar4[2] == 1) {
    val_5 = -1;
    DAT_0050a670 = (_EXCEPTION_POINTERS *)uval_3;
  }
  else {
    char_ptr_1 = (code *)piVar4[2];
    DAT_0050a670 = out_filter;
    if (piVar4[1] == 8) {
      for (player_idx = DAT_0050a660; uval_2 = DAT_0050a66c, player_idx < DAT_0050a664 + DAT_0050a660;
          player_idx = player_idx + 1) {
        *(int32_t *)(player_idx * 0xc + 0x50a5f0) = 0;
      }
      if (*piVar4 == -0x3fffff72) {
        DAT_0050a66c = 0x83;
      }
      else if (*piVar4 == -0x3fffff70) {
        DAT_0050a66c = 0x81;
      }
      else if (*piVar4 == -0x3fffff6f) {
        DAT_0050a66c = 0x84;
      }
      else if (*piVar4 == -0x3fffff6d) {
        DAT_0050a66c = 0x85;
      }
      else if (*piVar4 == -0x3fffff73) {
        DAT_0050a66c = 0x82;
      }
      else if (*piVar4 == -0x3fffff71) {
        DAT_0050a66c = 0x86;
      }
      else if (*piVar4 == -0x3fffff6e) {
        DAT_0050a66c = 0x8a;
      }
      (*char_ptr_1)(8,DAT_0050a66c);
      DAT_0050a66c = uval_2;
    }
    else {
      piVar4[2] = 0;
      (*char_ptr_1)(piVar4[1]);
    }
    val_5 = -1;
    DAT_0050a670 = (_EXCEPTION_POINTERS *)uval_3;
  }
  return val_5;
}



/*
 * Decompiled function: xcptlookup
 * Entry Point: 004e7940
 * Size: 97 bytes
 */


/* Library Function - Single Match
    _xcptlookup
   
   Library: Visual Studio 1998 Debug */

int * __cdecl xcptlookup(int player_id)

{
  int *slot_idx;
  
  slot_idx = &DAT_0050a5e8;
  do {
    if (*slot_idx == arg_1) break;
    slot_idx = slot_idx + 3;
  } while (slot_idx < &DAT_0050a5e8 + DAT_0050a668 * 3);
  if (*slot_idx != arg_1) {
    slot_idx = (int *)0x0;
  }
  return slot_idx;
}



/*
 * Decompiled function: __ismbbkalnum
 * Entry Point: 004e79b0
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbbkalnum
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkalnum(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,1);
  return val_1;
}



/*
 * Decompiled function: __ismbbkprint
 * Entry Point: 004e79d0
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbbkprint
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkprint(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,3);
  return val_1;
}



/*
 * Decompiled function: __ismbbkpunct
 * Entry Point: 004e79f0
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbbkpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkpunct(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,2);
  return val_1;
}



/*
 * Decompiled function: __ismbbalnum
 * Entry Point: 004e7a10
 * Size: 35 bytes
 */


/* Library Function - Single Match
    __ismbbalnum
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbalnum(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x107,1);
  return val_1;
}



/*
 * Decompiled function: __ismbbalpha
 * Entry Point: 004e7a40
 * Size: 35 bytes
 */


/* Library Function - Single Match
    __ismbbalpha
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbalpha(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x103,1);
  return val_1;
}



/*
 * Decompiled function: __ismbbgraph
 * Entry Point: 004e7a70
 * Size: 35 bytes
 */


/* Library Function - Single Match
    __ismbbgraph
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbgraph(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x117,3);
  return val_1;
}



/*
 * Decompiled function: __ismbbprint
 * Entry Point: 004e7aa0
 * Size: 35 bytes
 */


/* Library Function - Single Match
    __ismbbprint
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbprint(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x157,3);
  return val_1;
}



/*
 * Decompiled function: __ismbbpunct
 * Entry Point: 004e7ad0
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbbpunct
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbpunct(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0x10,2);
  return val_1;
}



/*
 * Decompiled function: __ismbblead
 * Entry Point: 004e7af0
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbblead
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbblead(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,4);
  return val_1;
}



/*
 * Decompiled function: __ismbbtrail
 * Entry Point: 004e7b10
 * Size: 32 bytes
 */


/* Library Function - Single Match
    __ismbbtrail
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbtrail(uint32_t arg_1)

{
  int val_1;
  
  val_1 = x_ismbbtype((uint8_t)arg_1,0,8);
  return val_1;
}



/*
 * Decompiled function: __ismbbkana
 * Entry Point: 004e7b30
 * Size: 68 bytes
 */


/* Library Function - Single Match
    __ismbbkana
   
   Library: Visual Studio 1998 Debug */

int __cdecl __ismbbkana(uint32_t arg_1)

{
  int val_1;
  
  if ((DAT_0050a304 == 0x3a4) && (val_1 = x_ismbbtype((uint8_t)arg_1,0,3), val_1 != 0)) {
    return 1;
  }
  return 0;
}



/*
 * Decompiled function: x_ismbbtype
 * Entry Point: 004e7b80
 * Size: 110 bytes
 */


/* Library Function - Single Match
    _x_ismbbtype
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl x_ismbbtype(uint8_t arg_1,uint32_t arg_2,uint8_t arg_3)

{
  uint32_t slot_idx;
  
  if ((arg_3 & (&DAT_0050a201)[arg_1]) == 0) {
    if (arg_2 == 0) {
      slot_idx = 0;
    }
    else {
      slot_idx = *(uint16_t *)(&DAT_005094aa + (uint32_t)arg_1 * 2) & arg_2;
    }
    if (slot_idx == 0) {
      return 0;
    }
  }
  return 1;
}



