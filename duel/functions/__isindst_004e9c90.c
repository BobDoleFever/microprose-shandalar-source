/*
 * Decompiled function: __isindst
 * Entry Point: 004e9c90
 * Size: 859 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __isindst
   
   Library: Visual Studio 1998 Debug */

int __cdecl __isindst(tm *ptr_1)

{
  int iVar1;
  
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
        cvtdate(1,1,ptr_1->tm_year,(uint)DAT_005edcc2,(uint)DAT_005edcc6,(uint)DAT_005edcc4,0,
                (uint)DAT_005edcc8,(uint)DAT_005edcca,(uint)DAT_005edccc,(uint)DAT_005edcce);
      }
      else {
        cvtdate(1,0,ptr_1->tm_year,(uint)DAT_005edcc2,0,0,(uint)DAT_005edcc6,(uint)DAT_005edcc8,
                (uint)DAT_005edcca,(uint)DAT_005edccc,(uint)DAT_005edcce);
      }
      if (DAT_005edc6c == 0) {
        cvtdate(0,1,ptr_1->tm_year,(uint)DAT_005edc6e,(uint)DAT_005edc72,(uint)DAT_005edc70,0,
                (uint)DAT_005edc74,(uint)DAT_005edc76,(uint)DAT_005edc78,(uint)DAT_005edc7a);
      }
      else {
        cvtdate(0,0,ptr_1->tm_year,(uint)DAT_005edc6e,0,0,(uint)DAT_005edc72,(uint)DAT_005edc74,
                (uint)DAT_005edc76,(uint)DAT_005edc78,(uint)DAT_005edc7a);
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
  iVar1 = (ptr_1->tm_hour * 0xe10 + ptr_1->tm_min * 0x3c + ptr_1->tm_sec) * 1000;
  if (ptr_1->tm_yday == DAT_0050a7f4) {
    if (iVar1 < DAT_0050a7f8) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  else if (iVar1 < DAT_0050a808) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


