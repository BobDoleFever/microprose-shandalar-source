/*
 * Decompiled function: _localtime
 * Entry Point: 004e69f0
 * Size: 597 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _localtime
   
   Library: Visual Studio 1998 Debug */

tm * __cdecl _localtime(time_t *ptr_1)

{
  tm *ptr_1_00;
  int iVar1;
  int local_8;
  
  if ((int)*ptr_1 < 0) {
    ptr_1_00 = (tm *)0x0;
  }
  else {
    ___tzset();
    if (((int)*ptr_1 < 0x3f481) || (0x7ffc0b7e < (int)*ptr_1)) {
      ptr_1_00 = _gmtime(ptr_1);
      iVar1 = __isindst(ptr_1_00);
      if (iVar1 == 0) {
        local_8 = ptr_1_00->tm_sec - DAT_0050a750;
      }
      else {
        local_8 = ptr_1_00->tm_sec - (DAT_0050a750 + DAT_0050a758);
      }
      ptr_1_00->tm_sec = local_8 % 0x3c;
      if (ptr_1_00->tm_sec < 0) {
        ptr_1_00->tm_sec = ptr_1_00->tm_sec + 0x3c;
        local_8 = local_8 + -0x3c;
      }
      local_8 = ptr_1_00->tm_min + local_8 / 0x3c;
      ptr_1_00->tm_min = local_8 % 0x3c;
      if (ptr_1_00->tm_min < 0) {
        ptr_1_00->tm_min = ptr_1_00->tm_min + 0x3c;
        local_8 = local_8 + -0x3c;
      }
      local_8 = ptr_1_00->tm_hour + local_8 / 0x3c;
      ptr_1_00->tm_hour = local_8 % 0x18;
      if (ptr_1_00->tm_hour < 0) {
        ptr_1_00->tm_hour = ptr_1_00->tm_hour + 0x18;
        local_8 = local_8 + -0x18;
      }
      local_8 = local_8 / 0x18;
      if (local_8 < 1) {
        if (local_8 < 0) {
          ptr_1_00->tm_wday = (ptr_1_00->tm_wday + 7 + local_8) % 7;
          ptr_1_00->tm_mday = ptr_1_00->tm_mday + local_8;
          if (ptr_1_00->tm_mday < 1) {
            ptr_1_00->tm_mday = ptr_1_00->tm_mday + 0x1f;
            ptr_1_00->tm_yday = 0x16c;
            ptr_1_00->tm_mon = 0xb;
            ptr_1_00->tm_year = ptr_1_00->tm_year + -1;
          }
          else {
            ptr_1_00->tm_yday = ptr_1_00->tm_yday + local_8;
          }
        }
      }
      else {
        ptr_1_00->tm_wday = (ptr_1_00->tm_wday + local_8) % 7;
        ptr_1_00->tm_mday = ptr_1_00->tm_mday + local_8;
        ptr_1_00->tm_yday = ptr_1_00->tm_yday + local_8;
      }
    }
    else {
      local_8 = (int)*ptr_1 - DAT_0050a750;
      ptr_1_00 = _gmtime((time_t *)&local_8);
      if ((DAT_0050a754 != 0) && (iVar1 = __isindst(ptr_1_00), iVar1 != 0)) {
        local_8 = local_8 - DAT_0050a758;
        ptr_1_00 = _gmtime((time_t *)&local_8);
        ptr_1_00->tm_isdst = 1;
      }
    }
  }
  return ptr_1_00;
}


