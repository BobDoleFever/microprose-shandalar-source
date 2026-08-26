/*
 * Decompiled function: FUN_0040eeb4
 * Entry Point: 0040eeb4
 * Size: 1632 bytes
 */
#include "magic.h"


undefined4 FUN_0040eeb4(int arg1,int arg2)

{
  bool bVar1;
  undefined *puVar2;
  byte arg_1;
  undefined4 arg_1_00;
  uint arg_1_01;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  int local_28;
  int local_24;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar2 = PTR_FUN_00527b3c;
  local_14 = 1;
  PTR_FUN_00527b3c = Mem_AllocOrFree_0040eea2;
LAB_0040eed6:
  if (arg2 == -1) {
    local_30 = Palette_Color_0049716e(s_Which_card_do_you_seek__00519250,0,0xffffffff,local_14,1);
  }
  else {
    local_30 = Palette_Color_0049716e
                         (s_Which_card_do_you_seek__00519238,
                          *(uint *)(&DAT_0067bdfc + arg2 * 100) & 0xff,
                          (*(int *)(&DAT_0067bdfc + arg2 * 100) >> 8) - 1,local_14,1);
  }
  local_14 = 0;
  if (arg1 == 0) {
    local_24 = 0;
    for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
      local_24 = local_24 + (&DAT_0067bdc0)[local_10];
    }
  }
  if (local_30 != 0xffffffff) {
    if (arg1 != -2) goto LAB_0040efc0;
    bVar1 = true;
    if ((int)local_30 < 5) {
      local_c = 4;
    }
    else {
      local_c = 1;
    }
    goto LAB_0040f49b;
  }
LAB_0040f4fb:
  Palette_Subsystem_00496eaf();
  PTR_FUN_00527b3c = puVar2;
  return 0;
LAB_0040efc0:
  local_28 = Pic_Subsystem_00452551(local_30);
  if (local_28 == 1) {
    if ((int)local_30 < 5) {
      local_c = 4;
    }
    else {
      local_c = 1;
    }
  }
  else if (local_28 == 2) {
    local_c = 1;
  }
  else {
    local_c = 1;
  }
  if ((local_28 < 2) && (((&DAT_0051aed1)[local_30 * 0x34] & 4) != 0)) {
    local_28 = local_28 + 1;
  }
  iVar6 = FUN_0050a9bf(local_30);
  local_8 = iVar6 * 4;
  arg_1_00 = FUN_0040c761((int)(DAT_0052eff0 + ((int)DAT_0052eff0 >> 0x1f & 0x1fU)) >> 5,
                          (int)(DAT_0052eff4 + ((int)DAT_0052eff4 >> 0x1f & 0x1fU)) >> 5);
  arg_1 = Adventure_GetLocationEncounterIndex(arg_1_00);
  arg_1_01 = FUN_00473cc5(arg_1);
  if (((arg_1_01 & (int)(char)(&DAT_0051aebe)[local_30 * 0x34]) == 0) &&
     ((&DAT_0051aebe)[local_30 * 0x34] != '\0')) {
    iVar3 = Pic_Subsystem_004521a6(arg_1_01,(int)(char)(&DAT_0051aebe)[local_30 * 0x34],3);
    if (iVar3 == 0) {
      local_8 = iVar6 << 3;
    }
    else {
      local_8 = (iVar6 * 0xc) / 2;
    }
  }
  iVar6 = FUN_0040a1d2(((DAT_0052eff0 & 0x1f) * (DAT_0052eff4 & 0x1f)) / 10);
  iVar3 = FUN_0040a305((((local_8 * 0x4e2) / (iVar6 + 0x2ee)) / 0x32) * 5,5,1000);
  iVar6 = local_28 * 0x32;
  if (local_28 * 0x32 <= (int)(iVar3 * local_c)) {
    iVar6 = iVar3 * local_c;
  }
  strcpy(&g_OverworldWorldState,s_I_ll_trade_you_00519268);
  pcVar4 = _itoa(local_c,&DAT_00538610,10);
  strcat(&g_OverworldWorldState,pcVar4);
  strcat(&g_OverworldWorldState,&DAT_00519278);
  strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + local_30 * 0x34);
  if (1 < local_c) {
    strcat(&g_OverworldWorldState,&DAT_0051927c);
  }
  strcat(&g_OverworldWorldState,s_for_00519280);
  if (arg1 < 0) {
    pcVar4 = _itoa(iVar6,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    strcat(&g_OverworldWorldState,s_Gold_pieces__005192a4);
  }
  else {
    pcVar4 = _itoa(local_28,&DAT_00538610,10);
    strcat(&g_OverworldWorldState,pcVar4);
    if (0 < arg1) {
      strcat(&g_OverworldWorldState,&DAT_00519288);
      pcVar4 = (char *)Mem_AllocOrFree_00473d7e(arg1);
      strcat(&g_OverworldWorldState,pcVar4);
    }
    strcat(&g_OverworldWorldState,s_amulets__0051928c + ((1 < local_28) - 1 & 0xc));
  }
  bVar1 = true;
  if ((0 < arg1) && (*(int *)(&DAT_0067bdbc + arg1 * 4) < local_28)) {
    bVar1 = false;
  }
  if ((arg1 == 0) && (local_24 < local_28)) {
    bVar1 = false;
  }
  if ((arg1 == -1) && (Gold < iVar6)) {
    bVar1 = false;
  }
  if (bVar1) {
    strcat(&g_OverworldWorldState,s_Do_you_wish_to_trade__Yes__I_ll_t_005192b4);
  }
  else {
    strcat(&g_OverworldWorldState,s_Hmmm____you_can_t_afford_this_ca_005192e8);
  }
  iVar3 = Ai_Util_004c3bc4(0x15c);
  iVar3 = iVar3 + 10;
  iVar5 = Ai_Util_004c3bc4(0xf4);
  iVar3 = FUN_00489710(&g_OverworldWorldState,iVar5 + 10,iVar3);
  if ((iVar3 == 0) && (bVar1)) {
    bVar1 = false;
    if ((0 < arg1) && (local_28 <= *(int *)(&DAT_0067bdbc + arg1 * 4))) {
      bVar1 = true;
      *(int *)(&DAT_0067bdbc + arg1 * 4) = *(int *)(&DAT_0067bdbc + arg1 * 4) - local_28;
    }
    if ((arg1 == 0) && (local_28 <= local_24)) {
      bVar1 = true;
      do {
        do {
          iVar3 = FUN_0040a1d2(5);
        } while ((&DAT_0067bdc0)[iVar3] == 0);
        local_28 = local_28 + -1;
        (&DAT_0067bdc0)[iVar3] = (&DAT_0067bdc0)[iVar3] + -1;
      } while (local_28 != 0);
    }
    if ((arg1 == -1) && (iVar6 <= Gold)) {
      bVar1 = true;
      Gold = Gold - iVar6;
    }
LAB_0040f49b:
    if (!bVar1) goto LAB_0040f4fb;
    for (local_10 = 0; local_10 < (int)local_c; local_10 = local_10 + 1) {
      iVar6 = Pic_Subsystem_00451e40(local_30);
      if (iVar6 != -1) {
        *(uint *)(&deck + iVar6 * 4) = *(uint *)(&deck + iVar6 * 4) | 0x4000;
      }
    }
    FUN_0040a566();
    Palette_Subsystem_00496eaf();
  }
  goto LAB_0040eed6;
}


