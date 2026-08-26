/*
 * Decompiled function: __fcloseall
 * Entry Point: 004e8e20
 * Size: 187 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 1998 Debug */

int __cdecl __fcloseall(void)

{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  for (local_c = 3; local_c < DAT_006c2ca0; local_c = local_c + 1) {
    if (*(int *)(DAT_006c1c98 + local_c * 4) != 0) {
      if ((*(byte *)(*(int *)(DAT_006c1c98 + local_c * 4) + 0xc) & 0x83) != 0) {
        iVar1 = _fclose(*(FILE **)(DAT_006c1c98 + local_c * 4));
        if (iVar1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      if (0x13 < local_c) {
        __free_dbg(*(void **)(DAT_006c1c98 + local_c * 4),2);
        *(undefined4 *)(DAT_006c1c98 + local_c * 4) = 0;
      }
    }
  }
  return local_8;
}


