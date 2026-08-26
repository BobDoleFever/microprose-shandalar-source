/*
 * Decompiled function: FUN_1000e202
 * Entry Point: 1000e202
 * Size: 217 bytes
 */
#include "deckdll.h"


uint32_t FUN_1000e202(uint8_t *arg_1)

{
  int val_1;
  char local_134 [256];
  int local_34;
  uint8_t local_30;
  uint8_t local_2f;
  int local_20;
  uint32_t local_18;
  char local_14 [16];
  
  local_18 = 3;
  local_34 = 0;
  local_20 = 0;
  _splitpath((char *)arg_1,local_14,local_134,(char *)&local_30,local_14);
  arg_1 = &local_30;
  strcat((char *)&local_30,local_14);
  while( true ) {
    val_1 = (int)(char)*arg_1;
    arg_1 = arg_1 + 1;
    if (val_1 == 0) break;
    if ((local_18 & 1) == 0) {
      local_20 = local_18 * val_1 + local_20;
    }
    else {
      local_34 = local_18 * val_1 + local_34;
    }
    local_18 = local_18 + 1;
  }
  return (int)(char)(local_2f ^ local_30) << 0x18 | local_20 * local_34 & 0xffffffU;
}


