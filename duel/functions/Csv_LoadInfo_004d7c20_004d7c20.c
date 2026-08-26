/*
 * Decompiled function: Csv_LoadInfo_004d7c20
 * Entry Point: 004d7c20
 * Size: 318 bytes
 */
#include "duel.h"


int Csv_LoadInfo_004d7c20(int arg_1)

{
  int iVar1;
  char local_28 [32];
  int local_8;
  
  if (((*(uint *)(&DAT_004ff5a8 + arg_1 * 0x34) & 0x180) != 0) ||
     ((&DAT_004ff5ae)[arg_1 * 0x34] == '@')) {
    (&DAT_004ff5ac)[arg_1 * 0x34] = 4;
  }
  if ((&DAT_004ff5ac)[arg_1 * 0x34] == -1) {
    Csv_LoadMaster_00492951(local_28,*(int *)(&DAT_004ff590 + arg_1 * 0x34),9,s_info_csv_005092e0);
    local_8 = 1;
    iVar1 = _strcmp(local_28,s_Special_005092ec);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = _strcmp(local_28,&DAT_005092f4);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = _strcmp(local_28,s_Uncommon_005092fc);
    if (iVar1 == 0) {
      local_8 = 2;
    }
    (&DAT_004ff5ac)[arg_1 * 0x34] = (undefined1)local_8;
  }
  else {
    local_8 = (int)(char)(&DAT_004ff5ac)[arg_1 * 0x34];
  }
  return local_8;
}


