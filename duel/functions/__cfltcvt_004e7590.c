/*
 * Decompiled function: __cfltcvt
 * Entry Point: 004e7590
 * Size: 119 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 1998 Debug */

errno_t __cdecl __cfltcvt(double *ptr_1,char *str_2,size_t arg_3,int arg_4,int arg_5,int arg_6)

{
  errno_t eVar1;
  int unaff_EDI;
  
  if ((arg_3 == 0x65) || (arg_3 == 0x45)) {
    eVar1 = __cftoe(ptr_1,str_2,arg_4,arg_5,unaff_EDI);
  }
  else if (arg_3 == 0x66) {
    eVar1 = __cftof(ptr_1,str_2,arg_4,unaff_EDI);
  }
  else {
    eVar1 = __cftog((undefined4 *)ptr_1,(int)str_2,arg_4,arg_5);
  }
  return eVar1;
}


