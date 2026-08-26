/*
 * Decompiled function: FUN_00472a0a
 * Entry Point: 00472a0a
 * Size: 391 bytes
 */
#include "magic.h"


undefined4 FUN_00472a0a(int arg_1)

{
  int x;
  uint arg_5;
  int iVar1;
  int local_18;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  x = 1 - arg_1;
  Ai_FilterValidBlockers(&local_8,&local_10);
  if (arg_1 == 1) {
    local_14 = local_8;
  }
  else {
    local_14 = local_10;
  }
  local_c = 0;
  do {
    if ((int)(&g_PlayerActiveCardCount)[x] <= local_c) {
      return 0;
    }
    if ((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + local_c * 0x120) != -1) &&
       (((&g_CardSlot_Flags)[x * 0x5b20 + local_c * 0x120] & 4) != 0)) {
      arg_5 = FUN_00473179(x,local_c,0x34,0xffffffff);
      for (local_18 = 0; local_18 < (int)(&g_PlayerActiveCardCount)[arg_1]; local_18 = local_18 + 1)
      {
        if (((*(int *)(&g_CardSlot_CardId + x * 0x5b20 + local_c * 0x120) != -1) &&
            (((byte)*(undefined4 *)(&g_CardSlot_Flags + local_18 * 0x120 + arg_1 * 0x5b20) & 0x1a)
             == 2)) && (iVar1 = FUN_00472c0c(arg_1,local_18,x,local_c,arg_5,local_14), iVar1 != 0))
        {
          return 1;
        }
      }
    }
    local_c = local_c + 1;
  } while( true );
}


