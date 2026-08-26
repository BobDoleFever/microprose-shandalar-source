/*
 * Decompiled function: FUN_004931aa
 * Entry Point: 004931aa
 * Size: 578 bytes
 */
#include "duel.h"


void FUN_004931aa(void)

{
  char *pcVar1;
  long lVar2;
  undefined4 local_124;
  char local_120 [8];
  int local_118;
  undefined4 local_114;
  undefined4 local_110;
  char local_10c;
  char local_10b [255];
  FILE *local_c;
  int local_8;
  
  local_c = _fopen(s_hints_txt_00505508,&DAT_00505504);
  local_118 = 0;
  do {
    local_8 = _fscanf(local_c,s_______00505514,&local_10c);
    if (local_10c == '.') {
      _sscanf(local_10b,s__d__d__s_0050551c,&local_124,&local_114,local_120);
      *(undefined4 *)(&DAT_006656d0 + local_118 * 8) = local_124;
      *(undefined4 *)(&DAT_006656d4 + local_118 * 8) = local_114;
      *(undefined4 *)(&DAT_006651c0 + local_118 * 4) = 0;
      pcVar1 = _strchr(local_120,0x41);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_006651c0 + local_118 * 4) = *(uint *)(&DAT_006651c0 + local_118 * 4) | 1;
      }
      pcVar1 = _strchr(local_120,0x42);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_006651c0 + local_118 * 4) = *(uint *)(&DAT_006651c0 + local_118 * 4) | 2;
      }
      pcVar1 = _strchr(local_120,0x43);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_006651c0 + local_118 * 4) = *(uint *)(&DAT_006651c0 + local_118 * 4) | 4;
      }
      pcVar1 = _strchr(local_120,0x44);
      if (pcVar1 != (char *)0x0) {
        *(uint *)(&DAT_006651c0 + local_118 * 4) = *(uint *)(&DAT_006651c0 + local_118 * 4) | 8;
      }
      local_110 = FUN_004d7d5e(local_124);
      local_110 = FUN_004d7d5e(local_114);
      local_8 = _fscanf(local_c,&DAT_00505528,&local_10c);
      lVar2 = _ftell(local_c);
      *(long *)(&DAT_00664dc0 + local_118 * 4) = lVar2;
      local_118 = local_118 + 1;
    }
    else {
      local_8 = _fscanf(local_c,&DAT_00505530,&local_10c);
    }
  } while ((local_118 < 0x100) && (local_8 != -1));
  do {
    *(undefined4 *)(&DAT_006656d4 + local_118 * 8) = 0xffffffff;
    *(undefined4 *)(&DAT_006656d0 + local_118 * 8) = *(undefined4 *)(&DAT_006656d4 + local_118 * 8);
    local_118 = local_118 + 1;
  } while (local_118 < 0x100);
  _fclose(local_c);
  return;
}


