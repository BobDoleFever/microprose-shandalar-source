/*
 * Decompiled function: Catalog_ComputeFilenameHash
 * Entry Point: 00493d62
 * Size: 235 bytes
 */
#include "magic.h"


uint Catalog_ComputeFilenameHash(byte *arg_1)

{
  int iVar1;
  int local_138;
  char local_134 [16];
  char local_124 [260];
  undefined4 local_20;
  byte local_1c;
  byte local_1b;
  uint local_10;
  int local_8;
  
  local_10 = 3;
  local_20 = 0;
  local_138 = 0;
  local_8 = 0;
  _splitpath((char *)arg_1,local_134,local_124,(char *)&local_1c,local_134);
  arg_1 = &local_1c;
  strcat((char *)&local_1c,local_134);
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
  return (int)(char)(local_1b ^ local_1c) << 0x18 | local_8 * local_138 & 0xffffffU;
}


