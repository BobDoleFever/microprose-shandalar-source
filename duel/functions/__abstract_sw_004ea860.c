/*
 * Decompiled function: __abstract_sw
 * Entry Point: 004ea860
 * Size: 116 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __abstract_sw
   
   Library: Visual Studio 1998 Debug */

uint __abstract_sw(byte arg_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  if ((arg_1 & 1) != 0) {
    local_8 = 0x10;
  }
  if ((arg_1 & 4) != 0) {
    local_8 = local_8 | 8;
  }
  if ((arg_1 & 8) != 0) {
    local_8 = local_8 | 4;
  }
  if ((arg_1 & 0x10) != 0) {
    local_8 = local_8 | 2;
  }
  if ((arg_1 & 0x20) != 0) {
    local_8 = local_8 | 1;
  }
  if ((arg_1 & 2) != 0) {
    local_8 = local_8 | 0x80000;
  }
  return local_8;
}


