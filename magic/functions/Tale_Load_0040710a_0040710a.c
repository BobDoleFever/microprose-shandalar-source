/*
 * Decompiled function: Tale_Load_0040710a
 * Entry Point: 0040710a
 * Size: 196 bytes
 */
#include "magic.h"


void Tale_Load_0040710a(int arg_1)

{
  int local_74;
  char local_70 [100];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_tale_txt_00516524,&DAT_00516520);
  local_74 = 0;
  do {
    local_8 = fscanf(local_c,s_______00516530,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 1;
    }
    else if (local_74 == arg_1) {
      strcat(&g_OverworldWorldState,local_70);
      strcat(&g_OverworldWorldState,&DAT_00516538);
    }
    local_8 = fscanf(local_c,&DAT_0051653c,local_70);
  } while ((local_8 != -1) && (local_74 <= arg_1));
  fclose(local_c);
  return;
}


