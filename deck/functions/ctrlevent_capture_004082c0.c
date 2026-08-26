/*
 * Decompiled function: ctrlevent_capture
 * Entry Point: 004082c0
 * Size: 136 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _ctrlevent_capture@4
   
   Library: Visual Studio 1998 Debug
   __stdcall ctrlevent_capture,4 */

int32_t ctrlevent_capture(int arg_1)

{
  int32_t uval_1;
  code *local_10;
  int32_t *local_c;
  int32_t local_8;
  
  if (arg_1 == 0) {
    local_c = &DAT_00413910;
    local_10 = DAT_00413910;
    local_8 = 2;
  }
  else {
    local_c = &DAT_00413914;
    local_10 = DAT_00413914;
    local_8 = 0x15;
  }
  if (local_10 == (code *)0x0) {
    uval_1 = 0;
  }
  else {
    if (local_10 != (code *)0x1) {
      *local_c = 0;
      (*local_10)(local_8);
    }
    uval_1 = 1;
  }
  return uval_1;
}


