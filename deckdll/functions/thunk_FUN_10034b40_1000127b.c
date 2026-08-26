/*
 * Decompiled function: thunk_FUN_10034b40
 * Entry Point: 1000127b
 * Size: 5 bytes
 */
#include "deckdll.h"


uint32_t thunk_FUN_10034b40(char *str_1,char *str_2)

{
  FILE *_File;
  int val_1;
  char *char_ptr_2;
  size_t len_3;
  int iStack_f0;
  char acStack_ec [80];
  char acStack_9c [128];
  char acStack_1c [20];
  uint32_t uStack_8;
  
  strcpy(acStack_1c,&DAT_1004b9e0);
  strcat(acStack_1c,str_2);
  strcat(acStack_1c,&DAT_1004b9e4);
  strcpy(acStack_9c,&DAT_10158770);
  strcat(acStack_9c,&DAT_1004b9e8);
  strcat(acStack_9c,str_1);
  if (DAT_10175ee8 == 0) {
    strcat(acStack_9c,&DAT_1004b9ec);
  }
  else if (DAT_10175ee8 == 1) {
    strcat(acStack_9c,&DAT_1004b9f4);
  }
  else if (DAT_10175ee8 == 2) {
    strcat(acStack_9c,&DAT_1004b9fc);
  }
  _File = fopen(acStack_9c,&DAT_1004ba04);
  if (_File != (FILE *)0x0) {
    do {
      val_1 = strcmp(acStack_1c,acStack_ec);
      if (val_1 == 0) {
        fscanf(_File,&DAT_1004ba08,&uStack_8);
        fgets(acStack_ec,0x50,_File);
        if (0xe1 < uStack_8) {
          fclose(_File);
          return 0xffffffff;
        }
        iStack_f0 = 0;
        while( true ) {
          if ((int)uStack_8 <= iStack_f0) {
            fclose(_File);
            return uStack_8;
          }
          char_ptr_2 = fgets(&DAT_1016e4c0 + iStack_f0 * 0x80,0x50,_File);
          if (char_ptr_2 == (char *)0x0) break;
          len_3 = strlen(&DAT_1016e4c0 + iStack_f0 * 0x80);
          (&DAT_1016e4bf)[iStack_f0 * 0x80 + len_3] = 0;
          iStack_f0 = iStack_f0 + 1;
        }
        fclose(_File);
        return 0xffffffff;
      }
      char_ptr_2 = fgets(acStack_ec,0x50,_File);
    } while (char_ptr_2 != (char *)0x0);
    fclose(_File);
  }
  return 0xffffffff;
}


