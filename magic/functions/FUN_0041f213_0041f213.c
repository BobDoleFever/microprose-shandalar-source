/*
 * Decompiled function: FUN_0041f213
 * Entry Point: 0041f213
 * Size: 156 bytes
 */
#include "magic.h"


undefined4 FUN_0041f213(void)

{
  int local_8;
  
  DAT_00680770 = 1;
  for (local_8 = 0; local_8 < *(int *)(&DAT_0067f780 + DAT_00519c24 * 4); local_8 = local_8 + 1) {
    (**(code **)(*(int *)(&DAT_0067f7d0 + local_8 * 4 + DAT_00519c24 * 200) + 0x24))
              (*(undefined4 *)(&DAT_0067f7d0 + local_8 * 4 + DAT_00519c24 * 200),
               local_8 == DAT_00519ff8);
  }
  DAT_00680770 = 0;
  return 1;
}


