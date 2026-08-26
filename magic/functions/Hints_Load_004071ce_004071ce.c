/*
 * Decompiled function: Hints_Load_004071ce
 * Entry Point: 004071ce
 * Size: 589 bytes
 */
#include "magic.h"


void Hints_Load_004071ce(void)

{
  char *pcVar1;
  long lVar2;
  int local_124;
  char local_120 [8];
  int local_118;
  int local_114;
  undefined4 local_110;
  char local_10c;
  char local_10b [255];
  FILE *local_c;
  int local_8;
  
  local_c = fopen(s_hints_txt_00516548,&DAT_00516544);
  local_118 = 0;
  do {
    local_8 = fscanf(local_c,s_______00516554,&local_10c);
    if (local_10c == '.') {
      sscanf(local_10b,s__d__d__s_0051655c,&local_124,&local_114,local_120);
      *(int *)(&DAT_00701940 + local_118 * 8) = local_124;
      *(int *)(&DAT_00701944 + local_118 * 8) = local_114;
      *(undefined4 *)(&DAT_00701430 + local_118 * 4) = 0;
      pcVar1 = strchr(local_120,0x41);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 1;
      }
      pcVar1 = strchr(local_120,0x42);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 2;
      }
      pcVar1 = strchr(local_120,0x43);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 4;
      }
      pcVar1 = strchr(local_120,0x44);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_00701430 + local_118 * 4) = *(uint *)(&DAT_00701430 + local_118 * 4) | 8;
      }
      local_110 = Pic_Subsystem_0045268f(local_124);
      local_110 = Pic_Subsystem_0045268f(local_114);
      local_8 = fscanf(local_c,&DAT_00516568,&local_10c);
      lVar2 = ftell(local_c);
      *(long *)(&DAT_00701030 + local_118 * 4) = lVar2;
      local_118 = local_118 + 1;
    }
    else {
      local_8 = fscanf(local_c,&DAT_00516570,&local_10c);
    }
  } while ((local_118 < 0x100) && (local_8 != -1));
  do {
    *(undefined4 *)(&DAT_00701944 + local_118 * 8) = 0xffffffff;
    *(undefined4 *)(&DAT_00701940 + local_118 * 8) = *(undefined4 *)(&DAT_00701944 + local_118 * 8);
    local_118 = local_118 + 1;
  } while (local_118 < 0x100);
  fclose(local_c);
  return;
}


