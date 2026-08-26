/*
 * Decompiled function: FUN_100035b2
 * Entry Point: 100035b2
 * Size: 192 bytes
 */
#include "statwin.h"


bool FUN_100035b2(void)

{
  FILE *_File;
  int val_1;
  char *char_ptr_2;
  char *char_ptr_3;
  int32_t *puVar4;
  char local_130 [20];
  int32_t local_11c [3];
  char local_110 [268];
  
  char_ptr_2 = s_a_statwin_water_avi_10011c10;
  char_ptr_3 = local_130;
  for (val_1 = 5; val_1 != 0; val_1 = val_1 + -1) {
    *(int32_t *)char_ptr_3 = *(int32_t *)char_ptr_2;
    char_ptr_2 = char_ptr_2 + 4;
    char_ptr_3 = char_ptr_3 + 4;
  }
  puVar4 = local_11c;
  for (val_1 = 0x46; val_1 != 0; val_1 = val_1 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  _getcwd(local_110,0x100);
  local_130[0] = local_110[0];
  _File = fopen(local_130,&DAT_10011c24);
  if (_File == (FILE *)0x0) {
    DAT_10013170 = 1;
    thunk_FUN_1000353c();
  }
  else {
    fclose(_File);
    DAT_10013170 = 0;
    DAT_1001317c = local_130[0];
  }
  return _File == (FILE *)0x0;
}


