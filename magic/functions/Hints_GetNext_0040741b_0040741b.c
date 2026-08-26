/*
 * Decompiled function: Hints_GetNext_0040741b
 * Entry Point: 0040741b
 * Size: 126 bytes
 */
#include "magic.h"


void Hints_GetNext_0040741b(int arg_1)

{
  char local_10c [256];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_hints_txt_0051657c,&DAT_00516578);
  fseek(local_c,*(long *)(&DAT_00701030 + arg_1 * 4),0);
  local_8 = fscanf(local_c,s_______00516588,local_10c);
  strcat(&g_OverworldWorldState,local_10c);
  fclose(local_c);
  return;
}


