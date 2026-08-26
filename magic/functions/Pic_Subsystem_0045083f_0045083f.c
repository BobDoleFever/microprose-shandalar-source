/*
 * Decompiled function: Pic_Subsystem_0045083f
 * Entry Point: 0045083f
 * Size: 310 bytes
 */
#include "magic.h"


void Pic_Subsystem_0045083f(int arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  int local_10;
  int local_c;
  
  for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
    if (*(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) != -1) {
      bVar1 = false;
      local_10 = 0;
      while ((local_10 < 0x50 && (!bVar1))) {
        iVar2 = Ai_Subsystem_004cbcd9(*(int *)(&DAT_00516cb8 + local_10 * 8 + arg2 * 0x280));
        if (iVar2 == *(int *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120)) {
          *(int *)(&DAT_00516cbc + local_10 * 8 + arg2 * 0x280) =
               *(int *)(&DAT_00516cbc + local_10 * 8 + arg2 * 0x280) + 1;
          bVar1 = true;
        }
        local_10 = local_10 + 1;
      }
      *(undefined4 *)(&g_CardSlot_CardId + arg1 * 0x5b20 + local_c * 0x120) = 0xffffffff;
    }
  }
  for (local_c = 0; local_c < 7; local_c = local_c + 1) {
    iVar2 = FUN_0040a02a(arg2);
    Pic_Subsystem_00451291(arg1,iVar2);
  }
  return;
}


