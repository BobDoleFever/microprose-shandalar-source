/*
 * Decompiled function: FUN_1002140e
 * Entry Point: 1002140e
 * Size: 270 bytes
 */
#include "deckdll.h"


void FUN_1002140e(char *str_1,char *str_2,int arg_3)

{
  bool flag_1;
  char *char_ptr_2;
  int val_3;
  char *local_14;
  char *local_8;
  
  if ((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) {
    flag_1 = false;
    local_8 = str_2;
    char_ptr_2 = local_8;
    while (local_8 = char_ptr_2, !flag_1) {
      while ((*local_8 != '\0' && (val_3 = strncmp(local_8,&DAT_1004397c,2), val_3 != 0))) {
        local_8 = local_8 + 1;
      }
      if (*local_8 == '\0') {
        flag_1 = true;
        char_ptr_2 = local_8;
      }
      else {
        val_3 = atoi(local_8 + 2);
        char_ptr_2 = local_8 + 2;
        if (val_3 == arg_3) {
          local_8 = local_8 + 3;
          local_14 = str_1;
          while ((*local_8 != '\0' && (val_3 = strncmp(local_8,&DAT_10043980,2), val_3 != 0))) {
            *local_14 = *local_8;
            local_8 = local_8 + 1;
            local_14 = local_14 + 1;
          }
          *local_14 = '\0';
          flag_1 = true;
          char_ptr_2 = local_8;
        }
      }
    }
  }
  return;
}


