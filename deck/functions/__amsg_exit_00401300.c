/*
 * Decompiled function: __amsg_exit
 * Entry Point: 00401300
 * Size: 55 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Debug */

void __cdecl __amsg_exit(int arg_1)

{
  if (DAT_00412a64 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(arg_1);
  (*(code *)PTR___exit_00412a60)(0xff);
  return;
}


