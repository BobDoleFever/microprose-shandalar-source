/*
 * Decompiled function: __splitpath
 * Entry Point: 004dcb60
 * Size: 578 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __splitpath
   
   Library: Visual Studio 1998 Debug */

void __cdecl __splitpath(char *str_1,char *str_2,char *str_3,char *str_4,char *str_5)

{
  size_t sVar1;
  byte *local_10;
  byte *local_c;
  byte *local_8;
  
  local_c = (byte *)0x0;
  if (str_1[1] == ':') {
    if (str_2 != (char *)0x0) {
      __mbsnbcpy((uchar *)str_2,(uchar *)str_1,2);
      str_2[2] = '\0';
    }
    str_1 = str_1 + 2;
  }
  else if (str_2 != (char *)0x0) {
    *str_2 = '\0';
  }
  local_10 = (byte *)0x0;
  for (local_8 = (byte *)str_1; *local_8 != 0; local_8 = local_8 + 1) {
    if (((&DAT_0050a201)[*local_8] & 4) == 0) {
      if ((*local_8 == 0x2f) || (*local_8 == 0x5c)) {
        local_10 = local_8 + 1;
      }
      else if (*local_8 == 0x2e) {
        local_c = local_8;
      }
    }
    else {
      local_8 = local_8 + 1;
    }
  }
  if (local_10 == (byte *)0x0) {
    if (str_3 != (char *)0x0) {
      *str_3 = '\0';
    }
  }
  else {
    if (str_3 != (char *)0x0) {
      sVar1 = (int)local_10 - (int)str_1;
      if (0xfe < sVar1) {
        sVar1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_3,(uchar *)str_1,sVar1);
      str_3[sVar1] = '\0';
    }
    str_1 = (char *)local_10;
  }
  if ((local_c == (byte *)0x0) || (local_c < str_1)) {
    if (str_4 != (char *)0x0) {
      sVar1 = (int)local_8 - (int)str_1;
      if (0xfe < sVar1) {
        sVar1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_4,(uchar *)str_1,sVar1);
      str_4[sVar1] = '\0';
    }
    if (str_5 != (char *)0x0) {
      *str_5 = '\0';
    }
  }
  else {
    if (str_4 != (char *)0x0) {
      sVar1 = (int)local_c - (int)str_1;
      if (0xfe < sVar1) {
        sVar1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_4,(uchar *)str_1,sVar1);
      str_4[sVar1] = '\0';
    }
    if (str_5 != (char *)0x0) {
      sVar1 = (int)local_8 - (int)local_c;
      if (0xfe < sVar1) {
        sVar1 = 0xff;
      }
      __mbsnbcpy((uchar *)str_5,local_c,sVar1);
      str_5[sVar1] = '\0';
    }
  }
  return;
}


