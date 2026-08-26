/*
 * Decompiled function: Story_Load_0040706f
 * Entry Point: 0040706f
 * Size: 155 bytes
 */
#include "magic.h"


void Story_Load_0040706f(void)

{
  int local_74;
  char local_70 [100];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_story_txt_00516504,&DAT_00516500);
  local_74 = 6;
  do {
    local_8 = fscanf(local_c,s_______00516510,local_70);
    if (local_70[0] == '.') {
      local_74 = local_74 + 3;
    }
    else {
      FUN_0040c336(local_70,0xa0,local_74,0xff);
      local_74 = local_74 + 7;
    }
    local_8 = fscanf(local_c,&DAT_00516518,local_70);
  } while (local_8 != -1);
  return;
}


