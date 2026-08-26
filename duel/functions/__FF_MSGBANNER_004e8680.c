/*
 * Decompiled function: __FF_MSGBANNER
 * Entry Point: 004e8680
 * Size: 95 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Debug */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_005096e8 == 1) || ((DAT_005096e8 == 0 && (DAT_005096ec == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_0050a710 != (code *)0x0) {
      (*DAT_0050a710)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


