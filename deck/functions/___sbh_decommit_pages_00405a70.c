/*
 * Decompiled function: ___sbh_decommit_pages
 * Entry Point: 00405a70
 * Size: 376 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    ___sbh_decommit_pages
   
   Library: Visual Studio 1998 Debug */

void __cdecl ___sbh_decommit_pages(int arg_1)

{
  uint8_t **ppuVar1;
  BOOL BVar2;
  uint8_t **local_18;
  int local_14;
  uint8_t *local_10;
  char *local_c;
  
  local_18 = (uint8_t **)PTR_LOOP_00413094;
  do {
    ppuVar1 = local_18;
    if (local_18[0x204] != (uint8_t *)0x0) {
      local_14 = 0;
      local_c = (char *)((int)local_18 + 0x40f);
      for (local_10 = (uint8_t *)0x3ff; -1 < (int)local_10; local_10 = local_10 + -1) {
        if ((*local_c == -0x10) &&
           (BVar2 = VirtualFree(local_18[0x204] + (int)local_10 * 0x1000,0x1000,0x4000), BVar2 != 0)
           ) {
          *local_c = -1;
          DAT_004138a8 = DAT_004138a8 + -1;
          if ((local_18[3] == (uint8_t *)0xffffffff) || ((int)local_10 < (int)local_18[3])) {
            local_18[3] = local_10;
          }
          local_14 = local_14 + 1;
          arg_1 = arg_1 + -1;
          if (arg_1 == 0) break;
        }
        local_c = local_c + -1;
      }
      ppuVar1 = (uint8_t **)local_18[1];
      if ((local_14 != 0) && (*(char *)(local_18 + 4) == -1)) {
        local_10 = (uint8_t *)0x1;
        for (local_c = (char *)((int)local_18 + 0x11); ((int)local_10 < 0x400 && (*local_c == -1));
            local_c = local_c + 1) {
          local_10 = (uint8_t *)((int)local_10 + 1);
        }
        if (local_10 == (uint8_t *)0x400) {
          ___sbh_release_region(local_18);
        }
      }
    }
    local_18 = ppuVar1;
    if (((uint8_t **)PTR_LOOP_00413094 == local_18) || (arg_1 < 1)) {
      return;
    }
  } while( true );
}


