/*
 * Decompiled function: FUN_0043456a
 * Entry Point: 0043456a
 * Size: 234 bytes
 */
#include "duel.h"


uint FUN_0043456a(byte *arg_1)

{
  int iVar1;
  int local_138;
  uint local_134 [4];
  char local_124 [260];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_10;
  int local_8;
  
  local_10 = 3;
  local_20 = 0;
  local_138 = 0;
  local_8 = 0;
  __splitpath((char *)arg_1,(char *)local_134,local_124,(char *)&local_1c,(char *)local_134);
  arg_1 = (byte *)&local_1c;
  FUN_004d9640(&local_1c,local_134);
  while( true ) {
    iVar1 = (int)(char)*arg_1;
    arg_1 = arg_1 + 1;
    if (iVar1 == 0) break;
    if ((local_10 & 1) == 0) {
      local_8 = local_10 * iVar1 + local_8;
    }
    else {
      local_138 = local_10 * iVar1 + local_138;
    }
    local_10 = local_10 + 1;
  }
  return (int)(char)(local_1c._1_1_ ^ (byte)local_1c) << 0x18 | local_8 * local_138 & 0xffffffU;
}


