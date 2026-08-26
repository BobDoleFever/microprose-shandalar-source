/*
 * Decompiled function: FUN_004933ec
 * Entry Point: 004933ec
 * Size: 122 bytes
 */
#include "duel.h"


void FUN_004933ec(int param_1)

{
  undefined1 local_10c [256];
  FILE *local_c;
  int local_8;
  
  local_c = _fopen(s_hints_txt_0050553c,&DAT_00505538);
  _fseek(local_c,*(long *)(&DAT_00664dc0 + param_1 * 4),0);
  local_8 = _fscanf(local_c,s_______00505548,local_10c);
  FUN_004d9640(&DAT_005f6810,local_10c);
  _fclose(local_c);
  return;
}


