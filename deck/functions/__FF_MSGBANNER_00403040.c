/*
 * Decompiled function: __FF_MSGBANNER
 * Entry Point: 00403040
 * Size: 95 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 1998 Debug */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_00412a64 == 1) || ((DAT_00412a64 == 0 && (DAT_00412a68 == 1)))) {
    __NMSG_WRITE(0xfc);
    if (DAT_00412e20 != (code *)0x0) {
      (*DAT_00412e20)();
    }
    __NMSG_WRITE(0xff);
  }
  return;
}


