/*
 * Decompiled function: __fltout
 * Entry Point: 004eb3b0
 * Size: 111 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fltout
   
   Library: Visual Studio 1998 Debug */

undefined * __fltout(void)

{
  uint local_10;
  uint local_c;
  ushort local_8;
  
  ___dtold(&local_10,(uint *)&stack0x00000004);
  _DAT_005edd00 = _I10_OUTPUT(local_10,local_c,local_8,0x11,0,&DAT_005edcd8);
  _DAT_005edcf8 = (int)DAT_005edcda;
  _DAT_005edcfc = (int)DAT_005edcd8;
  _DAT_005edd04 = 0x5edcdc;
  return &DAT_005edcf8;
}


