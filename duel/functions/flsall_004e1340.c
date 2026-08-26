/*
 * Decompiled function: flsall
 * Entry Point: 004e1340
 * Size: 247 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _flsall
   
   Library: Visual Studio 1998 Debug */

int __cdecl flsall(int arg_1)

{
  int iVar1;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  for (local_10 = 0; local_10 < DAT_006c2ca0; local_10 = local_10 + 1) {
    if ((*(int *)(DAT_006c1c98 + local_10 * 4) != 0) &&
       ((*(byte *)(*(int *)(DAT_006c1c98 + local_10 * 4) + 0xc) & 0x83) != 0)) {
      if (arg_1 == 1) {
        iVar1 = _fflush(*(FILE **)(DAT_006c1c98 + local_10 * 4));
        if (iVar1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      else if (((arg_1 == 0) && ((*(byte *)(*(int *)(DAT_006c1c98 + local_10 * 4) + 0xc) & 2) != 0))
              && (iVar1 = _fflush(*(FILE **)(DAT_006c1c98 + local_10 * 4)), iVar1 == -1)) {
        local_c = -1;
      }
    }
  }
  if (arg_1 == 1) {
    local_c = local_8;
  }
  return local_c;
}


