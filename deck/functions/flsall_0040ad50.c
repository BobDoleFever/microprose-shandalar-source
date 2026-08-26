/*
 * Decompiled function: flsall
 * Entry Point: 0040ad50
 * Size: 247 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Debug */

int __cdecl flsall(int arg_1)

{
  int val_1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  for (local_10 = 0; local_10 < DAT_00415690; local_10 = local_10 + 1) {
    if ((*(int *)(DAT_00414344 + local_10 * 4) != 0) &&
       ((*(uint8_t *)(*(int *)(DAT_00414344 + local_10 * 4) + 0xc) & 0x83) != 0)) {
      if (arg_1 == 1) {
        val_1 = _fflush(*(FILE **)(DAT_00414344 + local_10 * 4));
        if (val_1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      else if (((arg_1 == 0) && ((*(uint8_t *)(*(int *)(DAT_00414344 + local_10 * 4) + 0xc) & 2) != 0))
              && (val_1 = _fflush(*(FILE **)(DAT_00414344 + local_10 * 4)), val_1 == -1)) {
        local_c = -1;
      }
    }
  }
  if (arg_1 == 1) {
    local_c = local_8;
  }
  return local_c;
}


