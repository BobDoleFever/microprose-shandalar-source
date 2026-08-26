/*
 * Decompiled function: FUN_0040d949
 * Entry Point: 0040d949
 * Size: 892 bytes
 */
#include "magic.h"


int FUN_0040d949(int arg_1,uint arg_2,int arg_3)

{
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_1c;
  int local_10;
  byte local_8;
  
  if (arg_2 == 6) {
    local_28 = 7;
  }
  else if (arg_2 == 0) {
    local_28 = 7;
  }
  else {
    local_28 = arg_2;
  }
  if (arg_3 == 0) {
    local_34 = 1;
  }
  else {
    local_2c = 0;
    local_24 = 0;
    while (((int)local_24 < 10 && (*(int *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) != -1))) {
      if (local_28 == *(uint *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c) >> 0x10) {
        local_8 = (byte)*(undefined2 *)(&DAT_00627a20 + local_24 * 4 + arg_1 * 0x2c);
        local_2c = local_2c | 1 << (local_8 & 0x1f);
      }
      local_24 = local_24 + 1;
    }
    local_30 = *(int *)(&DAT_0063ee90 + local_28 * 4 + arg_1 * 0x20);
    for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
      if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
        local_30 = local_30 + *(int *)(&DAT_0063ee90 + local_24 * 4 + arg_1 * 0x20);
      }
    }
    local_1c = *(int *)(&DAT_0063edd0 + local_28 * 4 + arg_1 * 0x20);
    if (((arg_1 == g_ActivePlayerPriority) || (DAT_006fedc0 != 0)) || (g_IsAiThinking == 1)) {
      for (local_24 = 0; (int)local_24 < 7; local_24 = local_24 + 1) {
        if ((local_24 != local_28) && ((local_2c & 1 << ((byte)local_24 & 0x1f)) != 0)) {
          local_1c = local_1c + *(int *)(&DAT_0063edd0 + local_24 * 4 + arg_1 * 0x20);
        }
      }
    }
    local_10 = 0;
    local_24 = 0;
    while (((int)local_24 < 0x32 && (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) != -1)))
    {
      if (local_28 == 7) {
        local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
      }
      else if ((*(uint *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) &
               1 << ((byte)local_28 & 0x1f)) == 0) {
        if ((((arg_1 == g_ActivePlayerPriority) || (DAT_006fedc0 != 0)) || (g_IsAiThinking == 1)) &&
           ((local_2c & *(uint *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc)) != 0)) {
          local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
        }
      }
      else {
        local_10 = local_10 + (*(int *)(&DAT_00627870 + local_24 * 4 + arg_1 * 0xcc) >> 0x10);
      }
      local_24 = local_24 + 1;
    }
    if ((arg_2 == 7) || (arg_2 == 0)) {
      local_34 = (((local_30 - *(int *)(&DAT_0063eea8 + arg_1 * 0x20)) + local_1c) -
                 *(int *)(&DAT_0063ede8 + arg_1 * 0x20)) + local_10;
    }
    else {
      local_34 = local_1c + local_10 + local_30;
    }
    if (local_34 < arg_3) {
      local_34 = 0;
    }
  }
  return local_34;
}


