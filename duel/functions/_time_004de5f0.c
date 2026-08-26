/*
 * Decompiled function: _time
 * Entry Point: 004de5f0
 * Size: 390 bytes
 */
#include "duel.h"


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
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_28);
  GetSystemTime(&local_14);
  if (((((uint)local_14._8_4_ >> 0x10 == DAT_005edae8 >> 0x10) &&
       ((local_14._8_4_ & 0xffff) == (DAT_005edae8 & 0xffff))) &&
      ((uint)local_14._4_4_ >> 0x10 == DAT_005edae4 >> 0x10)) &&
     (((uint)local_14._0_4_ >> 0x10 == DAT_005edae0 >> 0x10 &&
      ((local_14._0_4_ & 0xffff) == (DAT_005edae0 & 0xffff))))) {
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
    DAT_005edae0._0_2_ = local_14.wYear;
    DAT_005edae0._2_2_ = local_14.wMonth;
    DAT_005edae4._0_2_ = local_14.wDayOfWeek;
    DAT_005edae4._2_2_ = local_14.wDay;
    DAT_005edae8._0_2_ = local_14.wHour;
    DAT_005edae8._2_2_ = local_14.wMinute;
    DAT_005edaec._0_2_ = local_14.wSecond;
    DAT_005edaec._2_2_ = local_14.wMilliseconds;
  }
  DAT_005edad8 = local_dc;
  tVar2 = ___loctotime_t(local_28._0_4_ & 0xffff,(uint)local_28._0_4_ >> 0x10,(uint)local_28.wDay,
                         local_28._8_4_ & 0xffff,(uint)local_28._8_4_ >> 0x10,
                         local_28._12_4_ & 0xffff,local_dc);
  if (ptr_1 != (time_t *)0x0) {
    *(int *)ptr_1 = (int)tVar2;
  }
  return tVar2;
}


