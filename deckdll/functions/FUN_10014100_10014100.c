/*
 * Decompiled function: FUN_10014100
 * Entry Point: 10014100
 * Size: 415 bytes
 */
#include "deckdll.h"


int32_t FUN_10014100(char *str_1)

{
  FILE *_File;
  int local_c;
  int32_t local_8;
  
  _File = fopen(str_1,&DAT_10042f98);
  if (_File == (FILE *)0x0) {
    local_8 = 0;
  }
  else {
    fprintf(_File,&DAT_10042f9c,&DAT_10162630);
    fprintf(_File,&DAT_10042fa4,&DAT_1016264f);
    fprintf(_File,&DAT_10042fac,&DAT_10162664);
    fprintf(_File,&DAT_10042fb4,&DAT_101626b5);
    fprintf(_File,&DAT_10042fbc,&DAT_10162706);
    fprintf(_File,&DAT_10042fc4,DAT_1016271c);
    fprintf(_File,&DAT_10042fcc,&DAT_10162720);
    fprintf(_File,&DAT_10042fd4,&DAT_10162730);
    fprintf(_File,&DAT_10042fdc);
    for (local_c = 0; local_c < DAT_101cece4; local_c = local_c + 1) {
      fprintf(_File,s___d__d__s_10042fe0,*(int32_t *)(local_c * 0xc + 0x101cded0),
              *(int32_t *)(local_c * 0xc + 0x101cded4),
              *(int32_t *)(local_c * 0xc + 0x101cded8));
    }
    fclose(_File);
    local_8 = 1;
  }
  return local_8;
}


