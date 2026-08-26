/*
 * Decompiled function: FUN_1000f104
 * Entry Point: 1000f104
 * Size: 1445 bytes
 */
#include "deckdll.h"


int FUN_1000f104(int arg_1,int arg_2,uint32_t *arg_3,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  short *psVar4;
  int local_8c;
  uint8_t *local_80;
  int local_78;
  int local_64;
  uint32_t local_5c;
  uint32_t local_50;
  uint32_t local_44;
  uint32_t local_40;
  int local_3c;
  uint32_t local_34;
  uint32_t local_28 [6];
  int local_10;
  int local_c;
  uint8_t *local_8;
  
  local_8c = 1;
  local_80 = &DAT_10041600 + arg_1 * 0xc0;
  if (arg_1 == 0) {
    DAT_10042384 = arg_1;
    arg_4 = 0;
  }
  else if (arg_1 == 1) {
    DAT_10042384 = arg_1;
    arg_4 = thunk_FUN_1000ef86(arg_3,arg_4,arg_5,arg_6);
  }
  else {
    if (DAT_10129258 == 0) {
      for (local_5c = -0x200; (int)local_5c < 0x200; local_5c = local_5c + 1) {
        if (((int)local_5c < 0) || (0xff < (int)local_5c)) {
          if ((int)local_5c < 0) {
            PTR_DAT_10042380[local_5c] = 0;
          }
          else {
            PTR_DAT_10042380[local_5c] = 0xff;
          }
        }
        else {
          PTR_DAT_10042380[local_5c] = (uint8_t)local_5c;
        }
      }
      DAT_10129258 = 1;
    }
    if (arg_1 != DAT_10042384) {
      for (local_5c = 0; local_5c < 0x41; local_5c = local_5c + 1) {
        if (*(int *)(&DAT_10202ee0 + local_5c * 4) != 0) {
          free(*(void **)(&DAT_10202ee0 + local_5c * 4));
          *(int32_t *)(&DAT_10202ee0 + local_5c * 4) = 0;
        }
      }
      thunk_FUN_1000f6ef(arg_1,0x10202ee0);
      DAT_10042384 = arg_1;
    }
    for (local_5c = 0; local_5c < 5; local_5c = local_5c + 1) {
      thunk_FUN_100029d0((undefined8 *)(&DAT_101cfc50 + local_5c * 0x8060),0,0x8060);
      local_28[local_5c + 1] = local_5c * 0x8060 + 0x101cfc78;
    }
    val_1 = *(int *)(&DAT_10041588 + arg_1 * 4);
    for (local_64 = 0; local_64 < arg_4; local_64 = local_64 + 1) {
      if (local_8c < 1) {
        local_10 = arg_5 + -1;
        local_c = -1;
        local_3c = -3;
      }
      else {
        local_10 = 0;
        local_c = arg_5;
        local_3c = 3;
      }
      local_78 = local_10 * 3;
      for (local_5c = local_10; local_5c != local_c; local_5c = local_5c + local_8c) {
        uval_2 = *(uint32_t *)(local_78 + (int)arg_3);
        local_28[0] = uval_2 & 0xffffff;
        *(uint32_t *)(local_78 + (int)arg_3) = *(uint32_t *)(local_78 + (int)arg_3) & 0xff000000;
        psVar4 = (short *)(local_28[1] + local_5c * 8);
        if (local_28[0] == 0) {
          local_44 = 0;
          local_50 = 0;
          local_40 = 0;
          local_34 = 0;
        }
        else if (local_28[0] == 0xffffff) {
          local_50 = 0xff;
          local_40 = 0xff;
          local_34 = 0xff;
          local_44 = 0xffffff;
        }
        else {
          local_34 = (uint32_t)(uint8_t)PTR_DAT_10042380[(uval_2 & 0xff) + ((int)*psVar4 >> 8)];
          local_40 = (uint32_t)(uint8_t)PTR_DAT_10042380[(local_28[0] >> 8 & 0xff) + ((int)psVar4[1] >> 8)]
          ;
          local_50 = (uint32_t)(uint8_t)PTR_DAT_10042380[(local_28[0] >> 0x10) + ((int)psVar4[2] >> 8)];
          local_28[0] = local_50 << 0x10 | local_40 << 8 | local_34;
          local_44 = thunk_FUN_1000ebea(local_28[0]);
        }
        *(uint32_t *)(local_78 + (int)arg_3) = *(uint32_t *)(local_78 + (int)arg_3) | local_44;
        for (local_8 = local_80; local_8 < local_80 + val_1 * 0x10; local_8 = local_8 + 0x10) {
          val_3 = *(int *)(local_8 + 0xc);
          psVar4 = (short *)((*(int *)(local_8 + 4) + local_5c) * 8 +
                            local_28[*(int *)(local_8 + 8) + 1]);
          *psVar4 = (short)*(int32_t *)(val_3 + (local_34 - (local_44 & 0xff)) * 4) + *psVar4;
          psVar4[1] = (short)*(int32_t *)(val_3 + (local_40 - (local_44 >> 8 & 0xff)) * 4) +
                      psVar4[1];
          psVar4[2] = (short)*(int32_t *)(val_3 + (local_50 - (local_44 >> 0x10)) * 4) +
                      psVar4[2];
        }
        local_78 = local_78 + local_3c;
      }
      thunk_FUN_1000f6ae(local_28 + 1,*(int *)(&DAT_100415b0 + arg_1 * 4));
      memset((void *)(local_28[*(int *)(&DAT_100415b0 + arg_1 * 4)] - 0x28),0,arg_5 * 8 + 0x50);
      if (arg_2 != 0) {
        local_8c = -local_8c;
        local_80 = &DAT_10041600 + (uint32_t)(local_8c == -1) * 0x6c0 + arg_1 * 0xc0;
      }
      arg_3 = (uint32_t *)((int)arg_3 + arg_5 * 3 + arg_6);
    }
  }
  return arg_4;
}


