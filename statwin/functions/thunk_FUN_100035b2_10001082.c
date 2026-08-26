/*
 * Decompiled function: thunk_FUN_100035b2
 * Entry Point: 10001082
 * Size: 5 bytes
 */
#include "statwin.h"


bool thunk_FUN_100035b2(void)

{
  FILE *_File;
  int val_1;
  char *char_ptr_2;
  char *char_ptr_3;
  int32_t *puVar4;
  char acStack_130 [20];
  int32_t auStack_11c [3];
  char acStack_110 [268];
  
  char_ptr_2 = s_a_statwin_water_avi_10011c10;
  char_ptr_3 = acStack_130;
  for (val_1 = 5; val_1 != 0; val_1 = val_1 + -1) {
    *(int32_t *)char_ptr_3 = *(int32_t *)char_ptr_2;
    char_ptr_2 = char_ptr_2 + 4;
    char_ptr_3 = char_ptr_3 + 4;
  }
  puVar4 = auStack_11c;
  for (val_1 = 0x46; val_1 != 0; val_1 = val_1 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  _getcwd(acStack_110,0x100);
  acStack_130[0] = acStack_110[0];
  _File = fopen(acStack_130,&DAT_10011c24);
  if (_File == (FILE *)0x0) {
    DAT_10013170 = 1;
    thunk_FUN_1000353c();
  }
  else {
    fclose(_File);
    DAT_10013170 = 0;
    DAT_1001317c = acStack_130[0];
  }
  return _File == (FILE *)0x0;
}


