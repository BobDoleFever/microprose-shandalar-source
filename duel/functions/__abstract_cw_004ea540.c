/*
 * Decompiled function: __abstract_cw
 * Entry Point: 004ea540
 * Size: 308 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __abstract_cw
   
   Library: Visual Studio 1998 Debug */

uint __abstract_cw(uint arg_1)

{
  uint uVar1;
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
  uVar1 = arg_1 & 0xc00;
  if (uVar1 < 0x401) {
    if (uVar1 == 0x400) {
      local_8 = local_8 | 0x100;
    }
  }
  else if (uVar1 == 0x800) {
    local_8 = local_8 | 0x200;
  }
  else if (uVar1 == 0xc00) {
    local_8 = local_8 | 0x300;
  }
  if ((arg_1 & 0x300) == 0) {
    local_8 = local_8 | 0x20000;
  }
  else if ((arg_1 & 0x300) == 0x200) {
    local_8 = local_8 | 0x10000;
  }
  if ((arg_1 & 0x1000) != 0) {
    local_8 = local_8 | 0x40000;
  }
  return local_8;
}


