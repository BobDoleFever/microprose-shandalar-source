/*
 * Decompiled function: FUN_0041bcf0
 * Entry Point: 0041bcf0
 * Size: 955 bytes
 */
#include "duel.h"


undefined4
FUN_0041bcf0(int *arg_1,int arg_2,int arg_3,uint arg_4,uint arg_5,uint arg_6,uint arg_7,uint arg_8,
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
      iVar2 = Rules_ParseFilter_0041c0ab
                        (local_28,-1,(undefined1 *)0x0,arg_3,(byte)arg_4,(byte)arg_5,arg_6,arg_7,
                         arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,arg_16,arg_17,arg_18,
                         arg_19);
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
        iVar2 = DAT_0066640c;
        if (DAT_0066640c <= DAT_00666408) {
          iVar2 = DAT_00666408;
        }
        if ((iVar2 <= local_c) || (bVar1)) break;
        if (*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) != -1) {
          if (arg_2 == 0) {
            local_10 = local_8;
            local_2c = local_c;
            bVar3 = true;
          }
          else if (arg_2 == 1) {
            bVar3 = *(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068f104;
            if (bVar3) {
              local_10 = (uint)(char)(&DAT_006826d2)[local_c * 0x120 + local_8 * 0x5b20];
              local_2c = *(int *)(&DAT_006826e8 + local_c * 0x120 + local_8 * 0x5b20);
            }
          }
          else if (*(int *)(&DAT_006826c4 + local_c * 0x120 + local_8 * 0x5b20) == DAT_0068f104) {
            local_10 = (uint)(char)(&DAT_006826d3)[local_c * 0x120 + local_8 * 0x5b20];
            local_2c = *(int *)(&DAT_006826ec + local_c * 0x120 + local_8 * 0x5b20);
            bVar3 = true;
          }
          else {
            bVar3 = false;
          }
          if ((bVar3) &&
             (iVar2 = Rules_ParseFilter_0041c0ab
                                (local_10,local_2c,(undefined1 *)0x0,arg_3,(byte)arg_4,(byte)arg_5,
                                 arg_6,arg_7,arg_8,arg_9,arg_10,arg_11,arg_12,arg_13,arg_14,arg_15,
                                 arg_16,arg_17,arg_18,arg_19), iVar2 != 0)) {
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


