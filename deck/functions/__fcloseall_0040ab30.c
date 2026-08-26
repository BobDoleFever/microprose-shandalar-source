/*
 * Decompiled function: __fcloseall
 * Entry Point: 0040ab30
 * Size: 187 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __fcloseall
   
   Library: Visual Studio 1998 Debug */

int __cdecl __fcloseall(void)

{
  int val_1;
  int32_t local_c;
  int32_t local_8;
  
  local_8 = 0;
  for (local_c = 3; local_c < DAT_00415690; local_c = local_c + 1) {
    if (*(int *)(DAT_00414344 + local_c * 4) != 0) {
      if ((*(uint8_t *)(*(int *)(DAT_00414344 + local_c * 4) + 0xc) & 0x83) != 0) {
        val_1 = _fclose(*(FILE **)(DAT_00414344 + local_c * 4));
        if (val_1 != -1) {
          local_8 = local_8 + 1;
        }
      }
      if (0x13 < local_c) {
        __free_dbg(*(void **)(DAT_00414344 + local_c * 4),2);
        *(int32_t *)(DAT_00414344 + local_c * 4) = 0;
      }
    }
  }
  return local_8;
}


