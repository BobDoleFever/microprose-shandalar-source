/*
 * Decompiled function: FUN_00403250
 * Entry Point: 00403250
 * Size: 955 bytes
 */
#include "magic.h"


undefined4
FUN_00403250(int *arg_1,int arg_2,int arg_3,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,
            uint arg_9,uint arg_10,uint arg_11,uint arg_12,int arg_13,int arg_14,uint arg_15,
            uint arg_16,uint arg_17,uint arg_18,uint arg_19)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  int local_2c;
  int local_28;
  undefined4 local_20;
  int local_18;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_18 = 0;
  local_20 = 0;
  if (((arg_2 == 0) || (arg_2 == 1)) || (arg_2 == 2)) {
    bVar1 = false;
    local_28 = 0;
    while( true ) {
      if (1 < local_28) break;
      iVar2 = Rules_ParseFilter_0040360b
                        (local_28,-1,(char *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,arg_7,arg_8,
                         arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,arg_19
                        );
      if (iVar2 != 0) {
        local_20 = 1;
        local_18 = local_18 + 1;
        if (arg_1 == (int *)0x0) {
          bVar1 = true;
        }
      }
      local_28 = local_28 + 1;
    }
    if (arg_3 == 0) {
      local_8 = (uint)((arg_4 & 2) == 0);
    }
    else if (((arg_5 & 2) == 0) && ((arg_5 & 1) == 0)) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
    local_28 = 0;
    while ((local_28 < 2 && (!bVar1))) {
      local_c = 0;
      while( true ) {
        iVar2 = DAT_006808bc;
        if (DAT_006808bc <= g_PlayerActiveCardCount) {
          iVar2 = g_PlayerActiveCardCount;
        }
        if ((iVar2 <= local_c) || (bVar1)) break;
        if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          if (arg_2 == 0) {
            local_10 = local_8;
            local_2c = local_c;
            bVar3 = true;
          }
          else if (arg_2 == 1) {
            bVar3 = *(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) ==
                    DAT_006ff2e0;
            if (bVar3) {
              local_10 = (uint)(char)(&g_CardSlot_Toughness)[local_c * 0x120 + local_8 * 0x5b20];
              local_2c = *(int *)(&g_CardSlot_OriginalCardId + local_c * 0x120 + local_8 * 0x5b20);
            }
          }
          else if (*(int *)(&g_CardSlot_CardId + local_c * 0x120 + local_8 * 0x5b20) == DAT_006ff2e0
                  ) {
            local_10 = (uint)(char)(&g_CardSlot_DamageReceived)[local_c * 0x120 + local_8 * 0x5b20];
            local_2c = *(int *)(&g_CardSlot_TypeFlags + local_c * 0x120 + local_8 * 0x5b20);
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if ((bVar3) &&
             (iVar2 = Rules_ParseFilter_0040360b
                                (local_10,local_2c,(char *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,
                                 arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,
                                 arg_17,arg_18,arg_19), iVar2 != 0)) {
            local_20 = 1;
            local_18 = local_18 + 1;
            if (arg_1 == (int *)0x0) {
              bVar1 = true;
            }
          }
        }
        local_c = local_c + 1;
      }
      local_28 = local_28 + 1;
      local_8 = 1 - local_8;
    }
    if (arg_1 != (int *)0x0) {
      *arg_1 = local_18;
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}


