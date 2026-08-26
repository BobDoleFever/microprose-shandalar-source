/*
 * Decompiled function: __amsg_exit
 * Entry Point: 004dec80
 * Size: 55 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 1998 Debug */

void __cdecl __amsg_exit(int arg_1)

{
  if (DAT_005096e8 == 1) {
    __FF_MSGBANNER();
  }
  __NMSG_WRITE(arg_1);
  (*(code *)PTR___exit_005096e4)(0xff);
  return;
}


