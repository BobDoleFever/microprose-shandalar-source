/*
 * Decompiled function: __fpmath
 * Entry Point: 004de970
 * Size: 38 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 1998 Debug */

void __cdecl __fpmath(int arg_1)

{
  __cfltcvt_init();
  _DAT_005096cc = __ms_p5_mp_test_fdiv();
  __setdefaultprecision();
  return;
}


