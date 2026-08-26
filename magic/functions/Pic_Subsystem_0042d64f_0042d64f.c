/*
 * Decompiled function: Pic_Subsystem_0042d64f
 * Entry Point: 0042d64f
 * Size: 1242 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Subsystem_0042d64f(int arg_1,int arg_2,int arg_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  
  if (arg_3 == 0x73) {
    if (((*(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) & 0x20010) == 0) &&
       ((*(byte *)(&DAT_006a2828 + (1 - arg_1)) & 2) != 0)) {
      return 1;
    }
    return 0;
  }
  if (arg_3 != 0x6d) goto LAB_0042d76f;
  if (local_c == -1) {
LAB_0042d745:
    g_ActivePlayer = 1;
  }
  else {
    iVar2 = FUN_00473179(arg_1,arg_2,0x32,0xffffffff);
    iVar3 = FUN_00473179(_DAT_0063ee20,local_c,0x32,0xffffffff);
    if (iVar2 < iVar3) goto LAB_0042d745;
    *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = local_c;
    (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = DAT_0063ee20;
  }
  *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
       *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
LAB_0042d76f:
  if ((arg_3 == 0x72) &&
     (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) != -1)) {
    uVar4 = Pic_Subsystem_0042ca53
                      ((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                       *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20));
    *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = uVar4;
    (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] = (undefined1)arg_1;
  }
  if (((((&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] != -1) &&
       (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) &&
     (*(int *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) == 0)) {
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 1;
    bVar1 = true;
    if (((arg_3 == 0x77) && (g_OverworldMapGrid == arg_2)) && (g_OverworldPlayerCoordX == arg_1)) {
      bVar1 = false;
    }
    if (((&g_CardSlot_Flags)[arg_2 * 0x120 + arg_1 * 0x5b20] & 0x10) == 0) {
      bVar1 = false;
    }
    iVar2 = FUN_00473179(arg_1,arg_2,0x32,0xffffffff);
    iVar3 = FUN_00473179((int)(char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20],
                         *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20),0x32,
                         0xffffffff);
    if (iVar2 < iVar3) {
      bVar1 = false;
    }
    if (!bVar1) {
      iVar2 = *(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20);
      *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
      (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
           (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
      Pic_Subsystem_0042ca53(arg_1,iVar2);
    }
    *(undefined4 *)(&g_CardSlot_ConvertedManaCost + arg_2 * 0x120 + arg_1 * 0x5b20) = 0;
  }
  if (((arg_3 == 0x77) &&
      (*(int *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) == g_OverworldMapGrid))
     && (((char)(&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] == g_OverworldPlayerCoordX
         && (g_OverworldMapGrid != -1)))) {
    *(undefined4 *)(&g_CardSlot_OriginalCardId + arg_2 * 0x120 + arg_1 * 0x5b20) = 0xffffffff;
    (&g_CardSlot_Toughness)[arg_2 * 0x120 + arg_1 * 0x5b20] =
         (&g_CardSlot_OriginalCardId)[arg_2 * 0x120 + arg_1 * 0x5b20];
  }
  return 0;
}


