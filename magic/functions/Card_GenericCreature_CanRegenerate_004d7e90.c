/*
 * Decompiled function: Card_GenericCreature_CanRegenerate
 * Entry Point: 004d7e90
 * Size: 579 bytes
 */
#include "magic.h"


undefined4 Card_GenericCreature_CanRegenerate(int arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  int local_c;
  int local_8;
  
  local_c = 0;
  bVar1 = false;
  while ((local_c < 2 && (!bVar1))) {
    local_8 = 0;
    while ((local_8 < (int)(&g_PlayerActiveCardCount)[local_c] && (!bVar1))) {
      iVar2 = FUN_00471c32(local_c,local_8);
      if ((((iVar2 != 0) &&
           ((char)(&g_CardSlot_Toughness)[local_c * 0x5b20 + local_8 * 0x120] == arg1)) &&
          (*(int *)(&g_CardSlot_OriginalCardId + local_c * 0x5b20 + local_8 * 0x120) == arg2)) &&
         (((*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) == DAT_006a4b64 &&
           (((&DAT_006a5f6a)[local_c * 0x5b20 + local_8 * 0x120] & 0x80) != 0)) ||
          (*(int *)(&g_CardSlot_CardId + local_c * 0x5b20 + local_8 * 0x120) == DAT_006a49ec)))) {
        bVar1 = true;
      }
      local_8 = local_8 + 1;
    }
    local_c = local_c + 1;
  }
  if (!bVar1) {
    (&DAT_006a5f50)[arg2 * 0x120 + arg1 * 0x5b20] = 0;
    *(undefined4 *)(&DAT_006a5f80 + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    *(undefined2 *)(&g_CardSlot_Power + arg2 * 0x120 + arg1 * 0x5b20) = 0;
    FUN_00415d48(arg1,arg2);
    *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Abilities1 + arg2 * 0x120 + arg1 * 0x5b20) & 0xffffff7f;
    (&g_CardSlot_ColorMask)[arg2 * 0x120 + arg1 * 0x5b20] = 0xff;
    *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg2 * 0x120 + arg1 * 0x5b20) & 0xfffffff3;
  }
  return 0;
}


