/*
 * Decompiled function: Mana_Init_00452b71
 * Entry Point: 00452b71
 * Size: 779 bytes
 */
#include "magic.h"


void Mana_Init_00452b71(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5)

{
  char *pcVar1;
  char *str_4;
  int iVar2;
  char *str_6;
  int local_c;
  int local_8;
  
  if (arg_3 == 1) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0040d7e9(arg_1,local_8,1);
      }
    }
  }
  if (arg_3 == 0x71) {
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0040d510(arg_1,local_8,1);
      }
    }
  }
  if ((arg_3 != 0x73) && (arg_3 == 0x6d)) {
    if ((arg_4 == DAT_00695ec8) || (DAT_00695ec8 == 0)) {
      local_c = arg_4;
    }
    else if (arg_5 == DAT_00695ec8) {
      local_c = arg_5;
    }
    else {
      strcpy(&g_OverworldWorldState,s_Which_mana__1__00523f08);
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      strcat(&g_OverworldWorldState,pcVar1);
      strcat(&g_OverworldWorldState,&DAT_00523f18);
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      strcat(&g_OverworldWorldState,pcVar1);
      str_6 = (char *)0x0;
      pcVar1 = (char *)Mem_AllocOrFree_00473d7e(arg_5);
      str_4 = (char *)Mem_AllocOrFree_00473d7e(arg_4);
      iVar2 = Ai_Subsystem_004cc814
                        (arg_1,s_Which_type_of_mana_to_produce__00523f20,0,str_4,pcVar1,str_6);
      if (iVar2 == 0) {
        local_c = arg_4;
      }
      else {
        local_c = arg_5;
      }
    }
    FUN_0040d875(arg_1,local_c,1);
    for (local_8 = 0; local_8 < 7; local_8 = local_8 + 1) {
      if ((1 << ((byte)local_8 & 0x1f) & (int)(char)(&DAT_006a5f4c)[arg_2 * 0x120 + arg_1 * 0x5b20])
          != 0) {
        FUN_0040d82b(arg_1,local_8,1);
      }
    }
    *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) =
         *(uint *)(&g_CardSlot_Flags + arg_2 * 0x120 + arg_1 * 0x5b20) | 0x10;
    DAT_006ff2d4 = local_c;
  }
  return;
}


