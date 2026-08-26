/*
 * Decompiled function: _raise
 * Entry Point: 00408350
 * Size: 475 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Debug */

int __cdecl _raise(int arg_1)

{
  code *local_18;
  int32_t *local_14;
  int32_t local_10;
  int local_c;
  int32_t local_8;
  
  switch(arg_1) {
  case 2:
    local_14 = &DAT_00413910;
    local_18 = DAT_00413910;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    local_14 = siglookup(arg_1);
    local_14 = local_14 + 2;
    local_18 = (code *)*local_14;
    break;
  case 0xf:
    local_14 = &DAT_0041391c;
    local_18 = DAT_0041391c;
    break;
  case 0x15:
    local_14 = &DAT_00413914;
    local_18 = DAT_00413914;
    break;
  case 0x16:
    local_14 = &DAT_00413918;
    local_18 = DAT_00413918;
  }
  if (local_18 != (code *)0x1) {
    if (local_18 == (code *)0x0) {
      __exit(3);
    }
    if (((arg_1 == 8) || (arg_1 == 0xb)) || (arg_1 == 4)) {
      local_10 = DAT_00412b58;
      DAT_00412b58 = 0;
      if (arg_1 == 8) {
        local_8 = DAT_00412b54;
        DAT_00412b54 = 0x8c;
      }
    }
    if (arg_1 == 8) {
      for (local_c = DAT_00412b48; local_c < DAT_00412b4c + DAT_00412b48; local_c = local_c + 1) {
        *(int32_t *)(local_c * 0xc + 0x412ad8) = 0;
      }
    }
    else {
      *local_14 = 0;
    }
    if (arg_1 == 8) {
      (*local_18)(8,DAT_00412b54);
    }
    else {
      (*local_18)(arg_1);
      if ((arg_1 != 0xb) && (arg_1 != 4)) {
        return 0;
      }
    }
    if (arg_1 == 8) {
      DAT_00412b54 = local_8;
    }
    DAT_00412b58 = local_10;
    return 0;
  }
  return 0;
}


