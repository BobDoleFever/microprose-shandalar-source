/*
 * Decompiled function: Pic_Subsystem_00452551
 * Entry Point: 00452551
 * Size: 318 bytes
 */
#include "magic.h"


int Pic_Subsystem_00452551(int arg_1)

{
  int iVar1;
  char local_28 [32];
  int local_8;
  
  if (((*(uint *)(&DAT_0051aed0 + arg_1 * 0x34) & 0x180) != 0) ||
     ((&DAT_0051aed6)[arg_1 * 0x34] == '@')) {
    (&DAT_0051aed4)[arg_1 * 0x34] = 4;
  }
  if ((&DAT_0051aed4)[arg_1 * 0x34] == -1) {
    Csv_SearchMaster_00406681
              (local_28,*(int *)(&g_MasterCardTypeTable + arg_1 * 0x34),9,s_info_csv_00523eb8);
    local_8 = 1;
    iVar1 = strcmp(local_28,s_Special_00523ec4);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = strcmp(local_28,&DAT_00523ecc);
    if (iVar1 == 0) {
      local_8 = 3;
    }
    iVar1 = strcmp(local_28,s_Uncommon_00523ed4);
    if (iVar1 == 0) {
      local_8 = 2;
    }
    (&DAT_0051aed4)[arg_1 * 0x34] = (undefined1)local_8;
  }
  else {
    local_8 = (int)(char)(&DAT_0051aed4)[arg_1 * 0x34];
  }
  return local_8;
}


