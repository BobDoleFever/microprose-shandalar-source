/*
 * Decompiled function: ___loctotime_t
 * Entry Point: 004e6c50
 * Size: 274 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___loctotime_t
   
   Library: Visual Studio 1998 Debug */

int ___loctotime_t(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  uint uVar1;
  int iVar2;
  int local_30;
  tm local_2c;
  int local_8;
  
  uVar1 = arg_1 - 0x76c;
  if (((int)uVar1 < 0x46) || (0x8a < (int)uVar1)) {
    local_8 = -1;
  }
  else {
    local_30 = *(int *)(&DAT_0050a86c + arg_2 * 4) + arg_3;
    if (((uVar1 & 3) == 0) && (2 < arg_2)) {
      local_30 = local_30 + 1;
    }
    local_8 = ((((arg_1 + -0x7b2) * 0x16d + (arg_1 + -0x76d >> 2) + -0x11 + local_30) * 0x18 + arg_4
               ) * 0x3c + arg_5) * 0x3c + arg_6;
    ___tzset();
    local_8 = local_8 + DAT_0050a750;
    local_2c.tm_yday = local_30;
    local_2c.tm_mon = arg_2 + -1;
    local_2c.tm_hour = arg_4;
    if ((arg_7 == 1) ||
       (((arg_7 == -1 && (DAT_0050a754 != 0)) &&
        (local_2c.tm_year = uVar1, iVar2 = __isindst(&local_2c), iVar2 != 0)))) {
      local_8 = local_8 + DAT_0050a758;
    }
  }
  return local_8;
}


