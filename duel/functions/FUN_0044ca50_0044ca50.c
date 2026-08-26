/*
 * Decompiled function: FUN_0044ca50
 * Entry Point: 0044ca50
 * Size: 95 bytes
 */
#include "duel.h"


int FUN_0044ca50(char arg_1,char *str_2,int arg_3)

{
  int local_8;
  
  local_8 = 0;
  while ((arg_3 != 0 && (*str_2 == arg_1))) {
    local_8 = local_8 + 1;
    str_2 = str_2 + 1;
    arg_3 = arg_3 + -1;
  }
  return local_8;
}


