/*
 * Decompiled function: Adventure_GetLocationEncounterIndex
 * Entry Point: 004ea7a6
 * Size: 248 bytes
 */
#include "magic.h"


undefined4 Adventure_GetLocationEncounterIndex(undefined4 arg_1)

{
  undefined4 local_8;
  
  switch(arg_1) {
  case 1:
    local_8 = 4;
    break;
  case 2:
    local_8 = 8;
    break;
  case 3:
    local_8 = 2;
    break;
  case 4:
    local_8 = 0x30;
    break;
  case 5:
    local_8 = 0x10;
    break;
  case 6:
    local_8 = 0x20;
    break;
  case 7:
    local_8 = 0x24;
    break;
  case 8:
    local_8 = 6;
    break;
  case 9:
    local_8 = 0x14;
    break;
  case 10:
    local_8 = 0x28;
    break;
  case 0xb:
    local_8 = 10;
    break;
  case 0xc:
    local_8 = 0x12;
    break;
  case 0xd:
    local_8 = 0x22;
    break;
  case 0xe:
    local_8 = 0xc;
    break;
  case 0xf:
    local_8 = 0x18;
    break;
  default:
    local_8 = 0;
  }
  return local_8;
}


