/*
 * Decompiled function: Tale_Load_004930ea
 * Entry Point: 004930ea
 * Size: 192 bytes
 */
#include "duel.h"


void Tale_Load_004930ea(int arg_1)

{
  int local_74;
  char local_70 [100];
  FILE *local_c;
  int local_8;
  
  local_c = _fopen(s_tale_txt_005054e4,&DAT_005054e0);
  local_74 = 0;
  do {
    local_8 = _fscanf(local_c,s_______005054f0,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 1;
    }
    else if (local_74 == arg_1) {
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)local_70);
      FUN_004d9640((uint *)&DAT_005f6810,(uint *)&DAT_005054f8);
    }
    local_8 = _fscanf(local_c,&DAT_005054fc,local_70);
  } while ((local_8 != -1) && (local_74 <= arg_1));
  _fclose(local_c);
  return;
}


