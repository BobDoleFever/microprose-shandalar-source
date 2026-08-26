/*
 * Decompiled function: __cftoe_g
 * Entry Point: 004e7510
 * Size: 63 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cftoe_g
   
   Library: Visual Studio 1998 Debug */

errno_t __cftoe_g(double *arg_1,char *str_2,size_t arg_3,int height)

{
  errno_t eVar1;
  int unaff_EDI;
  
  DAT_0050a5c8 = 1;
  eVar1 = __cftoe(arg_1,str_2,arg_3,height,unaff_EDI);
  DAT_0050a5c8 = 0;
  return eVar1;
}


