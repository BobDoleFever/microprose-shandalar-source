/*
 * Decompiled function: Adventure_Map_RedrawViewport
 * Entry Point: 004ec7f9
 * Size: 405 bytes
 */
#include "magic.h"


void Adventure_Map_RedrawViewport(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_4c;
  int local_48;
  int local_44;
  int local_3c [5];
  int aiStack_28 [5];
  undefined1 auStack_14 [5];
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  int local_8;
  
  for (local_44 = 0; local_44 < 5; local_44 = local_44 + 1) {
    local_4c = 0;
    local_8 = 0;
    iVar1 = Adventure_Audio_GetTrackStatus(local_44 + 1);
    for (local_48 = 0; local_48 < 0x80; local_48 = local_48 + 1) {
      if (((&DAT_0067be01)[local_48 * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_48 * 100) >> 8) + -1 == local_44)) {
        local_8 = local_8 + 1;
      }
    }
    auStack_14[iVar1] = (undefined1)local_8;
    if (*(int *)(&DAT_006410c0 + local_44 * 4) == 0) {
      iVar2 = DAT_0067f380 * local_8 + DAT_0067f380 * 5 + 0x1e;
      for (local_48 = 0; (local_48 < 1000 && ((&DAT_0067b9b0)[local_48] != '\0'));
          local_48 = local_48 + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_48] >> 4 == local_44 + 1) {
          local_4c = local_4c + 1;
        }
      }
      aiStack_28[iVar1] = local_4c;
      iVar3 = DAT_0067f380 * 5 + 0x14;
      local_4c = iVar2 - local_4c;
      if (iVar3 <= local_4c) {
        iVar3 = local_4c;
      }
      local_3c[iVar1] = 0x1e - (iVar2 - iVar3);
    }
    else {
      local_3c[iVar1] = 0;
    }
  }
  local_f = 0;
  local_e = 0;
  local_d = 0;
  Mem_AllocOrFree_00409e3c(local_3c);
  return;
}


