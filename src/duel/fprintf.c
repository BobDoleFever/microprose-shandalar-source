/*
 * fprintf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 3
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: _fprintf
 * Entry Point: 004de4f0
 * Size: 176 bytes
 */


/* Library Function - Single Match
    _fprintf
   
   Library: Visual Studio 1998 Debug */

int __cdecl _fprintf(FILE *fp,char *mode_str,...)

{
  code *char_ptr_1;
  int val_2;
  int val_3;
  
  if (fp == (FILE *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b30,0x38,0,"str != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  if (str_2 == (char *)0x0) {
    val_2 = __CrtDbgReport(2,0x4f0b30,0x39,0,"format != NULL");
    if (val_2 == 1) {
      char_ptr_1 = (code *)swi(3);
      val_2 = (*char_ptr_1)();
      return val_2;
    }
  }
  val_2 = __stbuf(fp);
  val_3 = __output(fp,(uint8_t *)str_2,(int32_t *)&stack0x0000000c);
  __ftbuf(val_2,fp);
  return val_3;
}



/*
 * Decompiled function: _ctime
 * Entry Point: 004de5a0
 * Size: 63 bytes
 */


/* Library Function - Single Match
    _ctime
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _ctime(time_t *ptr_1)

{
  tm *ptr_1_00;
  char *char_ptr_1;
  
  ptr_1_00 = _localtime(ptr_1);
  if (ptr_1_00 == (tm *)0x0) {
    char_ptr_1 = (char *)0x0;
  }
  else {
    char_ptr_1 = _asctime(ptr_1_00);
  }
  return char_ptr_1;
}



/*
 * Decompiled function: _time
 * Entry Point: 004de5f0
 * Size: 390 bytes
 */


/* Library Function - Single Match
    _time
   
   Library: Visual Studio 1998 Debug */

time_t __cdecl _time(time_t *ptr_1)

{
  DWORD DVar1;
  time_t tVar2;
  int local_dc;
  _TIME_ZONE_INFORMATION local_d4;
  _SYSTEMTIME local_28;
  _SYSTEMTIME player_idx;
  
  GetLocalTime(&local_28);
  GetSystemTime(&player_idx);
  if (((((uint32_t)player_idx._8_4_ >> 0x10 == DAT_005edae8 >> 0x10) &&
       ((player_idx._8_4_ & 0xffff) == (DAT_005edae8 & 0xffff))) &&
      ((uint32_t)player_idx._4_4_ >> 0x10 == DAT_005edae4 >> 0x10)) &&
     (((uint32_t)player_idx._0_4_ >> 0x10 == DAT_005edae0 >> 0x10 &&
      ((player_idx._0_4_ & 0xffff) == (DAT_005edae0 & 0xffff))))) {
    local_dc = DAT_005edad8;
  }
  else {
    DVar1 = GetTimeZoneInformation(&local_d4);
    if (DVar1 == 2) {
      local_dc = 1;
    }
    else if (DVar1 == 1) {
      local_dc = 0;
    }
    else {
      local_dc = -1;
    }
    DAT_005edae0._0_2_ = player_idx.wYear;
    DAT_005edae0._2_2_ = player_idx.wMonth;
    DAT_005edae4._0_2_ = player_idx.wDayOfWeek;
    DAT_005edae4._2_2_ = player_idx.wDay;
    DAT_005edae8._0_2_ = player_idx.wHour;
    DAT_005edae8._2_2_ = player_idx.wMinute;
    DAT_005edaec._0_2_ = player_idx.wSecond;
    DAT_005edaec._2_2_ = player_idx.wMilliseconds;
  }
  DAT_005edad8 = local_dc;
  tVar2 = ___loctotime_t(local_28._0_4_ & 0xffff,(uint32_t)local_28._0_4_ >> 0x10,(uint32_t)local_28.wDay,
                         local_28._8_4_ & 0xffff,(uint32_t)local_28._8_4_ >> 0x10,
                         local_28._12_4_ & 0xffff,local_dc);
  if (ptr_1 != (time_t *)0x0) {
    *(int *)ptr_1 = (int)tVar2;
  }
  return tVar2;
}



