/*
 * Decompiled function: __GET_RTERRMSG
 * Entry Point: 004032c0
 * Size: 109 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __GET_RTERRMSG
   
   Library: Visual Studio 1998 Debug */

wchar_t * __cdecl __GET_RTERRMSG(int arg_1)

{
  wchar_t *pwVar1;
  uint32_t local_8;
  
  for (local_8 = 0; (local_8 < 0x12 && (*(int *)(&DAT_00412d90 + local_8 * 8) != arg_1));
      local_8 = local_8 + 1) {
  }
  if (*(int *)(&DAT_00412d90 + local_8 * 8) == arg_1) {
    pwVar1 = (wchar_t *)(&PTR_s_R6002___floating_point_not_loade_00412d94)[local_8 * 2];
  }
  else {
    pwVar1 = (wchar_t *)0x0;
  }
  return pwVar1;
}


