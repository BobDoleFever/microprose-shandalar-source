/*
 * Decompiled function: x64toa
 * Entry Point: 00407dc0
 * Size: 216 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _x64toa@20
   
   Library: Visual Studio 1998 Debug
   __stdcall x64toa,20 */

void x64toa(undefined8 x,char *y,uint32_t width,int height)

{
  char cVar1;
  char *char_ptr_2;
  bool flag_3;
  undefined8 uval_4;
  undefined8 uval_5;
  char *local_c;
  char *local_8;
  
  local_8 = y;
  if (height != 0) {
    *y = '-';
    local_8 = y + 1;
  }
  local_c = local_8;
  do {
    char_ptr_2 = local_8;
    uval_4 = __aullrem((uint32_t)x,x._4_4_,width,0);
    uval_5 = __aulldiv((uint32_t)x,x._4_4_,width,0);
    if ((uint32_t)uval_4 < 10) {
      *local_8 = (char)uval_4 + '0';
    }
    else {
      *local_8 = (char)uval_4 + 'W';
    }
    local_8 = local_8 + 1;
    x._4_4_ = (uint32_t)((ulonglong)uval_5 >> 0x20);
    flag_3 = x._4_4_ != 0;
    x = uval_5;
  } while ((flag_3) || (x._0_4_ = (uint32_t)uval_5, flag_3 = (uint32_t)x != 0, flag_3));
  *local_8 = '\0';
  local_8 = char_ptr_2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}


