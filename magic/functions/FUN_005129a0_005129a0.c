/*
 * Decompiled function: FUN_005129a0
 * Entry Point: 005129a0
 * Size: 293 bytes
 */
#include "magic.h"


undefined4 FUN_005129a0(byte *arg1,int arg2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  undefined1 local_7;
  byte local_6;
  byte local_5;
  uint local_4;
  
  iVar3 = 0;
  if (0 < arg2) {
    do {
      local_5 = *arg1;
      iVar2 = arg2 - iVar3;
      if ((iVar2 == 1) || (arg1[1] != local_5)) {
        local_7 = 0xc1;
        local_6 = local_5;
        if ((local_5 & 0xc0) == 0xc0) {
          fwrite(&local_7,1,1,DAT_00703934);
        }
        iVar3 = iVar3 + 1;
        arg1 = arg1 + 1;
        fwrite(&local_6,1,1,DAT_00703934);
      }
      else {
        if (0x3e < iVar2) {
          iVar2 = 0x3f;
        }
        local_4 = 0;
        pbVar1 = arg1;
        while (iVar2 != 0) {
          iVar2 = iVar2 + -1;
          if (*pbVar1 != local_5) break;
          local_4 = local_4 + 1;
          pbVar1 = pbVar1 + 1;
        }
        iVar3 = iVar3 + local_4;
        arg1 = arg1 + local_4;
        local_4 = local_4 | 0xc0;
        fwrite(&local_4,1,1,DAT_00703934);
        fwrite(&local_5,1,1,DAT_00703934);
      }
    } while (iVar3 < arg2);
  }
  if (iVar3 < DAT_00703982) {
    local_5 = 0;
    fwrite(&local_5,1,1,DAT_00703934);
  }
  return 1;
}


