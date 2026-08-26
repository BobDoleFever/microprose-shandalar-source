/*
 * Decompiled function: _raise
 * Entry Point: 004e0a10
 * Size: 475 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 1998 Debug */

int __cdecl _raise(int arg_1)

{
  int iVar1;
  code *local_18;
  undefined4 *local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  switch(arg_1) {
  case 2:
    local_14 = &DAT_00509730;
    local_18 = DAT_00509730;
    break;
  default:
    return -1;
  case 4:
  case 8:
  case 0xb:
    iVar1 = siglookup(arg_1);
    local_14 = (undefined4 *)(iVar1 + 8);
    local_18 = (code *)*local_14;
    break;
  case 0xf:
    local_14 = &DAT_0050973c;
    local_18 = DAT_0050973c;
    break;
  case 0x15:
    local_14 = &DAT_00509734;
    local_18 = DAT_00509734;
    break;
  case 0x16:
    local_14 = &DAT_00509738;
    local_18 = DAT_00509738;
  }
  if (local_18 != (code *)0x1) {
    if (local_18 == (code *)0x0) {
      __exit(3);
    }
    if (((arg_1 == 8) || (arg_1 == 0xb)) || (arg_1 == 4)) {
      local_10 = DAT_0050a670;
      DAT_0050a670 = 0;
      if (arg_1 == 8) {
        local_8 = DAT_0050a66c;
        DAT_0050a66c = 0x8c;
      }
    }
    if (arg_1 == 8) {
      for (local_c = DAT_0050a660; local_c < DAT_0050a664 + DAT_0050a660; local_c = local_c + 1) {
        *(undefined4 *)(local_c * 0xc + 0x50a5f0) = 0;
      }
    }
    else {
      *local_14 = 0;
    }
    if (arg_1 == 8) {
      (*local_18)(8,DAT_0050a66c);
    }
    else {
      (*local_18)(arg_1);
      if ((arg_1 != 0xb) && (arg_1 != 4)) {
        return 0;
      }
    }
    if (arg_1 == 8) {
      DAT_0050a66c = local_8;
    }
    DAT_0050a670 = local_10;
    return 0;
  }
  return 0;
}


