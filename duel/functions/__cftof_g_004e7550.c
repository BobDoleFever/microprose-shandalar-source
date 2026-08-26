/*
 * Decompiled function: __cftof_g
 * Entry Point: 004e7550
 * Size: 59 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cftof_g
   
   Library: Visual Studio 1998 Debug */

errno_t __cftof_g(double *arg_1,char *str_2,size_t arg_3)

{
  errno_t eVar1;
  int unaff_EDI;
  
  DAT_0050a5c8 = 1;
  eVar1 = __cftof(arg_1,str_2,arg_3,unaff_EDI);
  DAT_0050a5c8 = 0;
  return eVar1;
}


