/*
 * Decompiled function: entry
 * Entry Point: 00513da0
 * Size: 510 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  HMODULE x;
  undefined4 *unaff_FS_OFFSET;
  HINSTANCE y;
  uint local_84;
  byte *local_78;
  char **local_74;
  _startupinfo local_70;
  int local_6c;
  char **local_68;
  int local_64;
  _STARTUPINFOA local_60;
  undefined1 *local_1c;
  undefined4 local_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  puStack_c = &DAT_005151c8;
  puStack_10 = &DAT_0051409e;
  local_14 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_14;
  local_1c = &stack0xffffff6c;
  local_8 = 0;
  __set_app_type(2);
  DAT_0070ac98 = 0xffffffff;
  DAT_0070ac9c = 0xffffffff;
  puVar2 = (undefined4 *)__p__fmode();
  *puVar2 = DAT_00536d70;
  puVar2 = (undefined4 *)__p__commode();
  *puVar2 = DAT_00536d6c;
  _DAT_0070ac94 = *(undefined4 *)_adjust_fdiv_exref;
  __setargv();
  if (DAT_00536d68 == 0) {
    __setusermatherr(Mem_AllocOrFree_00514060);
  }
  __setdefaultprecision();
  initterm(&DAT_00516008,&DAT_0051600c);
  local_70.newmode = DAT_00536d64;
  __getmainargs(&local_64,&local_74,&local_68,DAT_00536d60,&local_70);
  initterm(&DAT_00516000,&DAT_00516004);
  puVar2 = (undefined4 *)__p__acmdln();
  local_78 = (byte *)*puVar2;
  pbVar1 = local_78;
  if (*local_78 == 0x22) {
    do {
      local_78 = pbVar1;
      pbVar1 = local_78 + 1;
      if (*pbVar1 == 0) break;
    } while (*pbVar1 != 0x22);
    if (*pbVar1 == 0x22) {
      pbVar1 = local_78 + 2;
    }
  }
  else {
    for (; pbVar1 = local_78, 0x20 < *local_78; local_78 = local_78 + 1) {
    }
  }
  while ((local_78 = pbVar1, *local_78 != 0 && (*local_78 < 0x21))) {
    pbVar1 = local_78 + 1;
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    local_84 = 10;
  }
  else {
    local_84 = local_60._48_4_ & 0xffff;
  }
  y = (HINSTANCE)0x0;
  x = GetModuleHandleA((LPCSTR)0x0);
  local_6c = WinMain(x,y,(LPSTR)local_78,local_84);
                    /* WARNING: Subroutine does not return */
  exit(local_6c);
}


