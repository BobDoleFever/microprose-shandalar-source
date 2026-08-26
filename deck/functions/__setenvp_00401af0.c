/*
 * Decompiled function: __setenvp
 * Entry Point: 00401af0
 * Size: 318 bytes
 */
#include "deck.h"


/* Library Function - Single Match
    __setenvp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setenvp(void)

{
  size_t len_1;
  int val_2;
  int *local_10;
  int local_c;
  uint32_t *local_8;
  
  local_c = 0;
  for (local_8 = DAT_00412a58; (char)*local_8 != '\0'; local_8 = (uint32_t *)((int)local_8 + len_1 + 1))
  {
    if ((char)*local_8 != '=') {
      local_c = local_c + 1;
    }
    len_1 = _strlen((char *)local_8);
  }
  local_10 = (int *)__malloc_dbg(local_c * 4 + 4,2,0x410064,0x55);
  DAT_00412a94 = local_10;
  if (local_10 == (int *)0x0) {
    __amsg_exit(9);
  }
  for (local_8 = DAT_00412a58; (char)*local_8 != '\0'; local_8 = (uint32_t *)((int)local_8 + len_1 + 1))
  {
    len_1 = _strlen((char *)local_8);
    if ((char)*local_8 != '=') {
      val_2 = __malloc_dbg(len_1 + 1,2,0x410064,0x61);
      *local_10 = val_2;
      if (*local_10 == 0) {
        __amsg_exit(9);
      }
      FUN_00405450((uint32_t *)*local_10,local_8);
      local_10 = local_10 + 1;
    }
  }
  __free_dbg(DAT_00412a58,2);
  DAT_00412a58 = (uint32_t *)0x0;
  *local_10 = 0;
  return (int)local_10;
}


