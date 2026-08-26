/*
 * Decompiled function: FUN_00492693
 * Entry Point: 00492693
 * Size: 315 bytes
 */
#include "duel.h"


void FUN_00492693(void)

{
  long lVar1;
  int iVar2;
  int local_214;
  char local_20c [512];
  FILE *local_c;
  char *local_8;
  
  local_c = _fopen(s_master_csv_005053e4,&DAT_005053e0);
  for (local_214 = 0; local_214 < 0x4e2; local_214 = local_214 + 1) {
    *(undefined4 *)(&DAT_005daf18 + local_214 * 4) = 0xffffffff;
  }
  do {
    lVar1 = _ftell(local_c);
    local_8 = _fgets(local_20c,0x200,local_c);
    if (local_8 == (char *)0x0) break;
    if (local_20c[0] == '0') {
      iVar2 = _atoi(local_20c);
      if (((-1 < iVar2) && (iVar2 < 0x4e2)) && (*(int *)(&DAT_005daf18 + iVar2 * 4) == -1)) {
        *(long *)(&DAT_005daf18 + iVar2 * 4) = lVar1;
      }
      FUN_004d7d5e(iVar2);
    }
  } while (local_8 != (char *)0xffffffff);
  _fclose(local_c);
  return;
}


