/*
 * Decompiled function: FUN_0041f2af
 * Entry Point: 0041f2af
 * Size: 165 bytes
 */
#include "magic.h"


undefined4 FUN_0041f2af(int arg1,int arg2)

{
  int iVar1;
  int local_c;
  
  iVar1 = *(int *)(&DAT_0067f780 + DAT_00519c24 * 4);
  if (arg2 + arg1 <= *(int *)(&DAT_0067f780 + DAT_00519c24 * 4)) {
    iVar1 = arg2 + arg1;
  }
  DAT_00680770 = 1;
  for (local_c = arg1; local_c < iVar1; local_c = local_c + 1) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + local_c * 4 + DAT_00519c24 * 200),0);
  }
  DAT_00680770 = 0;
  return 1;
}


