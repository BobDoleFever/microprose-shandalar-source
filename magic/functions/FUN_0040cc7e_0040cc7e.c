/*
 * Decompiled function: FUN_0040cc7e
 * Entry Point: 0040cc7e
 * Size: 551 bytes
 */
#include "magic.h"


int FUN_0040cc7e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
                undefined4 *arg_9)

{
  int iVar1;
  int iVar2;
  undefined4 local_41c;
  int local_418;
  int local_414;
  char *local_410;
  char local_40c [1024];
  char *local_c;
  va_list local_8;
  
  local_8 = (va_list)(arg_9 + 1);
  iVar1 = _vsnprintf(local_40c,0x400,(char *)*arg_9,local_8);
  local_418 = FUN_0040cc08(local_40c);
  if (arg_4 != 0) {
    arg_7 = (arg_7 * DAT_00522458) / 0x280;
    arg_8 = (DAT_0052245c * arg_8) / 0x1e0;
  }
  if (arg_6 != 0) {
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    arg_8 = arg_8 - (iVar2 * local_418) / 2;
  }
  if (-1 < arg_2) {
    local_41c = *(undefined4 *)(arg_1 + 0x18);
    *(int *)(arg_1 + 0x18) = arg_2;
  }
  local_410 = local_40c;
  local_c = local_410;
  while( true ) {
    if (local_418 == 0) break;
    for (; (*local_410 != '\0' && (*local_410 != '\n')); local_410 = local_410 + 1) {
    }
    *local_410 = '\0';
    if (arg_5 == 0) {
      local_414 = arg_7;
    }
    else {
      iVar2 = FUN_0050f440((int *)arg_1,local_c);
      local_414 = arg_7 - iVar2 / 2;
    }
    if (arg_3 != 0) {
      local_41c = *(undefined4 *)(arg_1 + 0x18);
      *(undefined4 *)(arg_1 + 0x18) = 0;
      FUN_0050f820((int *)arg_1,local_414 + 1,arg_8 + 1,local_c);
      *(undefined4 *)(arg_1 + 0x18) = local_41c;
    }
    FUN_0050f820((int *)arg_1,local_414,arg_8,local_c);
    *local_410 = '\n';
    local_410 = local_410 + 1;
    local_c = local_410;
    iVar2 = Mem_AllocOrFree_0050f740(*(int *)(arg_1 + 0x20));
    arg_8 = arg_8 + iVar2;
    local_418 = local_418 + -1;
  }
  if (-1 < arg_2) {
    *(undefined4 *)(arg_1 + 0x18) = local_41c;
  }
  return iVar1;
}


