/*
 * Decompiled function: thunk_FUN_1002a529
 * Entry Point: 10001438
 * Size: 5 bytes
 */
#include "deckdll.h"


char * thunk_FUN_1002a529(int32_t *arg_1)

{
  char *char_ptr_1;
  char *pcStack_14;
  char *pcStack_8;
  
  pcStack_8 = (char *)*arg_1;
  if (*pcStack_8 == '\"') {
    pcStack_8 = pcStack_8 + 1;
    pcStack_14 = strchr(pcStack_8,0x22);
    *pcStack_14 = '\0';
    if (pcStack_14[1] == ',') {
      pcStack_14 = pcStack_14 + 2;
    }
    else {
      pcStack_14 = pcStack_14 + 3;
    }
  }
  else {
    pcStack_14 = strchr(pcStack_8,0x2c);
    char_ptr_1 = strchr(pcStack_8,0xd);
    if (pcStack_14 < char_ptr_1) {
      *pcStack_14 = '\0';
      pcStack_14 = pcStack_14 + 1;
    }
    else {
      *char_ptr_1 = '\0';
      pcStack_14 = char_ptr_1 + 2;
    }
  }
  *arg_1 = pcStack_8;
  return pcStack_14;
}


