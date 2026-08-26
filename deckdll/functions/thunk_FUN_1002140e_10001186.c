/*
 * Decompiled function: thunk_FUN_1002140e
 * Entry Point: 10001186
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1002140e(char *str_1,char *str_2,int arg_3)

{
  bool flag_1;
  char *char_ptr_2;
  int val_3;
  char *pcStack_14;
  char *pcStack_8;
  
  if ((str_1 != (char *)0x0) && (str_2 != (char *)0x0)) {
    flag_1 = false;
    pcStack_8 = str_2;
    char_ptr_2 = pcStack_8;
    while (pcStack_8 = char_ptr_2, !flag_1) {
      while ((*pcStack_8 != '\0' && (val_3 = strncmp(pcStack_8,&DAT_1004397c,2), val_3 != 0))) {
        pcStack_8 = pcStack_8 + 1;
      }
      if (*pcStack_8 == '\0') {
        flag_1 = true;
        char_ptr_2 = pcStack_8;
      }
      else {
        val_3 = atoi(pcStack_8 + 2);
        char_ptr_2 = pcStack_8 + 2;
        if (val_3 == arg_3) {
          pcStack_8 = pcStack_8 + 3;
          pcStack_14 = str_1;
          while ((*pcStack_8 != '\0' && (val_3 = strncmp(pcStack_8,&DAT_10043980,2), val_3 != 0))) {
            *pcStack_14 = *pcStack_8;
            pcStack_8 = pcStack_8 + 1;
            pcStack_14 = pcStack_14 + 1;
          }
          *pcStack_14 = '\0';
          flag_1 = true;
          char_ptr_2 = pcStack_8;
        }
      }
    }
  }
  return;
}


