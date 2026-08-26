/*
 * Decompiled function: Csv_LoadMaster_004063b8
 * Entry Point: 004063b8
 * Size: 320 bytes
 */
#include "magic.h"


void Csv_LoadMaster_004063b8(void)

{
  long lVar1;
  int arg_1;
  int local_214;
  char local_20c [512];
  FILE *local_c;
  char *local_8;
  
  local_c = fopen(s_master_csv_00516404,&DAT_00516400);
  for (local_214 = 0; local_214 < 0x4e2; local_214 = local_214 + 1) {
    *(undefined4 *)(&DAT_00536e78 + local_214 * 4) = 0xffffffff;
  }
  do {
    lVar1 = ftell(local_c);
    local_8 = fgets(local_20c,0x200,local_c);
    if (local_8 == (char *)0x0) break;
    if (local_20c[0] == '0') {
      arg_1 = atoi(local_20c);
      if (((-1 < arg_1) && (arg_1 < 0x4e2)) && (*(int *)(&DAT_00536e78 + arg_1 * 4) == -1)) {
        *(long *)(&DAT_00536e78 + arg_1 * 4) = lVar1;
      }
      Pic_Subsystem_0045268f(arg_1);
    }
  } while (local_8 != (char *)0xffffffff);
  fclose(local_c);
  return;
}


