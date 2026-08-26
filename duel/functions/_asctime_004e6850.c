/*
 * Decompiled function: _asctime
 * Entry Point: 004e6850
 * Size: 345 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _asctime
   
   Library: Visual Studio 1998 Debug */

char * __cdecl _asctime(tm *ptr_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  char *str_1;
  int local_14;
  char *local_8;
  
  local_8 = &DAT_005edaf8;
  iVar1 = ptr_1->tm_wday;
  iVar2 = ptr_1->tm_mon;
  for (local_14 = 0; local_14 < 3; local_14 = local_14 + 1) {
    *local_8 = "SunMonTueWedThuFriSat"[iVar1 * 3 + local_14];
    local_8[4] = "JanFebMarAprMayJunJulAugSepOctNovDec"[iVar2 * 3 + local_14];
    local_8 = local_8 + 1;
  }
  *local_8 = ' ';
  local_8[4] = ' ';
  puVar3 = (undefined1 *)store_dt(local_8 + 5,ptr_1->tm_mday);
  *puVar3 = 0x20;
  puVar3 = (undefined1 *)store_dt(puVar3 + 1,ptr_1->tm_hour);
  *puVar3 = 0x3a;
  puVar3 = (undefined1 *)store_dt(puVar3 + 1,ptr_1->tm_min);
  *puVar3 = 0x3a;
  puVar3 = (undefined1 *)store_dt(puVar3 + 1,ptr_1->tm_sec);
  *puVar3 = 0x20;
  str_1 = (char *)store_dt(puVar3 + 1,ptr_1->tm_year / 100 + 0x13);
  puVar3 = (undefined1 *)store_dt(str_1,ptr_1->tm_year % 100);
  *puVar3 = 10;
  puVar3[1] = 0;
  return &DAT_005edaf8;
}


