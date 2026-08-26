/*
 * Decompiled function: FUN_10034b40
 * Entry Point: 10034b40
 * Size: 649 bytes
 */
#include "deckdll.h"


uint32_t FUN_10034b40(char *str_1,char *str_2)

{
  FILE *_File;
  int val_1;
  char *char_ptr_2;
  size_t len_3;
  int local_f0;
  char local_ec [80];
  char local_9c [128];
  char local_1c [20];
  uint32_t local_8;
  
  strcpy(local_1c,&DAT_1004b9e0);
  strcat(local_1c,str_2);
  strcat(local_1c,&DAT_1004b9e4);
  strcpy(local_9c,&DAT_10158770);
  strcat(local_9c,&DAT_1004b9e8);
  strcat(local_9c,str_1);
  if (DAT_10175ee8 == 0) {
    strcat(local_9c,&DAT_1004b9ec);
  }
  else if (DAT_10175ee8 == 1) {
    strcat(local_9c,&DAT_1004b9f4);
  }
  else if (DAT_10175ee8 == 2) {
    strcat(local_9c,&DAT_1004b9fc);
  }
  _File = fopen(local_9c,&DAT_1004ba04);
  if (_File != (FILE *)0x0) {
    do {
      val_1 = strcmp(local_1c,local_ec);
      if (val_1 == 0) {
        fscanf(_File,&DAT_1004ba08,&local_8);
        fgets(local_ec,0x50,_File);
        if (0xe1 < local_8) {
          fclose(_File);
          return 0xffffffff;
        }
        local_f0 = 0;
        while( true ) {
          if ((int)local_8 <= local_f0) {
            fclose(_File);
            return local_8;
          }
          char_ptr_2 = fgets(&DAT_1016e4c0 + local_f0 * 0x80,0x50,_File);
          if (char_ptr_2 == (char *)0x0) break;
          len_3 = strlen(&DAT_1016e4c0 + local_f0 * 0x80);
          (&DAT_1016e4bf)[local_f0 * 0x80 + len_3] = 0;
          local_f0 = local_f0 + 1;
        }
        fclose(_File);
        return 0xffffffff;
      }
      char_ptr_2 = fgets(local_ec,0x50,_File);
    } while (char_ptr_2 != (char *)0x0);
    fclose(_File);
  }
  return 0xffffffff;
}


