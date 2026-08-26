/*
 * Decompiled function: ___add_12
 * Entry Point: 004ec200
 * Size: 171 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    ___add_12
   
   Library: Visual Studio 1998 Debug */

void ___add_12(uint *arg1,uint *arg2)

{
  int iVar1;
  
  iVar1 = ___addl(*arg1,*arg2,arg1);
  if (iVar1 != 0) {
    iVar1 = ___addl(arg1[1],1,arg1 + 1);
    if (iVar1 != 0) {
      arg1[2] = arg1[2] + 1;
    }
  }
  iVar1 = ___addl(arg1[1],arg2[1],arg1 + 1);
  if (iVar1 != 0) {
    arg1[2] = arg1[2] + 1;
  }
  ___addl(arg1[2],arg2[2],arg1 + 2);
  return;
}


