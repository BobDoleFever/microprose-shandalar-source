/*
 * Decompiled function: __cftof
 * Entry Point: 004e7260
 * Size: 393 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cftof
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cftof(double *x,char *y,size_t width,int height)

{
  int iVar1;
  size_t sVar2;
  STRFLT unaff_EDI;
  int *local_c;
  char *local_8;
  
  if (DAT_0050a5c8 == '\0') {
    local_c = (int *)__fltout(*(undefined4 *)x,*(undefined4 *)((int)x + 4));
    __fptostr(y + (*local_c == 0x2d),local_c[1] + width,(int)local_c,unaff_EDI);
  }
  else {
    local_c = DAT_005edb14;
    if (width == DAT_0050a5cc) {
      iVar1 = DAT_0050a5cc + (*DAT_005edb14 == 0x2d);
      y[iVar1] = '0';
      (y + iVar1)[1] = '\0';
    }
  }
  local_8 = y;
  if (*local_c == 0x2d) {
    *y = '-';
    local_8 = y + 1;
  }
  if (local_c[1] < 1) {
    __shift(local_8,1);
    *local_8 = '0';
    local_8 = local_8 + 1;
  }
  else {
    local_8 = local_8 + local_c[1];
  }
  if (0 < (int)width) {
    __shift(local_8,1);
    *local_8 = DAT_005096b0;
    if (local_c[1] < 0) {
      if (DAT_0050a5c8 == '\0') {
        sVar2 = -local_c[1];
        if ((int)width <= -local_c[1]) {
          sVar2 = width;
        }
      }
      else {
        sVar2 = -local_c[1];
      }
      width = sVar2;
      __shift(local_8 + 1,width);
      _memset(local_8 + 1,0x30,width);
    }
  }
  return (errno_t)y;
}


