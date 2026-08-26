/*
 * Decompiled function: __dosmaperr
 * Entry Point: 0040a580
 * Size: 177 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Debug */

void __cdecl __dosmaperr(uint32_t arg_1)

{
  uint32_t local_8;
  
  _DAT_00412a70 = arg_1;
  local_8 = 0;
  while( true ) {
    if (0x2c < local_8) {
      if ((arg_1 < 0x13) || (0x24 < arg_1)) {
        if ((arg_1 < 0xbc) || (0xca < arg_1)) {
          _DAT_00412a6c = 0x16;
        }
        else {
          _DAT_00412a6c = 8;
        }
      }
      else {
        _DAT_00412a6c = 0xd;
      }
      return;
    }
    if (*(uint32_t *)(&DAT_00413be0 + local_8 * 8) == arg_1) break;
    local_8 = local_8 + 1;
  }
  _DAT_00412a6c = *(int32_t *)(&DAT_00413be4 + local_8 * 8);
  return;
}


