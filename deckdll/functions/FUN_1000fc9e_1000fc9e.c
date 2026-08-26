/*
 * Decompiled function: FUN_1000fc9e
 * Entry Point: 1000fc9e
 * Size: 1350 bytes
 */
#include "deckdll.h"


int32_t FUN_1000fc9e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  uint8_t flag_2;
  uint8_t flag_3;
  uint8_t bVar4;
  int val_5;
  uint32_t uval_6;
  int val_7;
  uint32_t uval_8;
  int local_8c;
  uint8_t *local_80;
  int local_78;
  int local_70;
  int local_64;
  uint32_t local_5c;
  uint32_t local_44;
  int local_3c;
  uint32_t local_28 [6];
  int local_10;
  int local_c;
  uint8_t *local_8;
  
  local_8c = 1;
  local_80 = &DAT_10041600 + arg_1 * 0xc0;
  if (DAT_1012924c == 0) {
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
    DAT_1012924c = 1;
  }
  if (arg_1 != DAT_10042388) {
    for (local_5c = 0; local_5c < 0x41; local_5c = local_5c + 1) {
      if (*(int *)(&DAT_10202ee0 + local_5c * 4) != 0) {
        free(*(void **)(&DAT_10202ee0 + local_5c * 4));
        *(int32_t *)(&DAT_10202ee0 + local_5c * 4) = 0;
      }
    }
    thunk_FUN_1000f6ef(arg_1,0x10202ee0);
    DAT_10042388 = arg_1;
  }
  for (local_5c = 0; local_5c < 5; local_5c = local_5c + 1) {
    memset(&DAT_101cfc50 + local_5c * 0x8060,0,0x8060);
    local_28[local_5c + 1] = local_5c * 0x8060 + 0x101cfc78;
  }
  val_5 = *(int *)(&DAT_10041588 + arg_1 * 4);
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
      uval_6 = *(uint32_t *)(local_78 + arg_3);
      uval_8 = uval_6 & 0xffffff;
      *(uint32_t *)(local_78 + arg_3) = *(uint32_t *)(local_78 + arg_3) & 0xff000000;
      psVar1 = (short *)(local_28[1] + local_5c * 8);
      flag_2 = PTR_DAT_10042380[(uval_6 & 0xff) + ((int)*psVar1 >> 8)];
      flag_3 = PTR_DAT_10042380[(uval_8 >> 8 & 0xff) + ((int)psVar1[1] >> 8)];
      bVar4 = PTR_DAT_10042380[(uval_8 >> 0x10) + ((int)psVar1[2] >> 8)];
      local_28[0] = (uint32_t)flag_3 << 8 | (uint32_t)bVar4 << 0x10 | (uint32_t)flag_2;
      if (local_28[0] == 0) {
        local_44 = 0;
      }
      else if (local_28[0] == 0xffffff) {
        local_44 = 0xffffff;
      }
      else {
        local_44 = thunk_FUN_10010980(local_28[0]);
      }
      *(uint32_t *)(local_78 + arg_3) = *(uint32_t *)(local_78 + arg_3) | local_44;
      local_8 = local_80;
      for (local_70 = 0; local_70 < val_5; local_70 = local_70 + 1) {
        val_7 = *(int *)(local_8 + 0xc);
        psVar1 = (short *)(local_28[*(int *)(local_8 + 8) + 1] +
                          (*(int *)(local_8 + 4) + local_5c) * 8);
        *psVar1 = (short)*(int32_t *)(val_7 + ((uint32_t)flag_2 - (local_44 & 0xff)) * 4) + *psVar1;
        psVar1[1] = (short)*(int32_t *)(val_7 + ((uint32_t)flag_3 - (local_44 >> 8 & 0xff)) * 4) +
                    psVar1[1];
        psVar1[2] = (short)*(int32_t *)(val_7 + ((uint32_t)bVar4 - (local_44 >> 0x10 & 0xff)) * 4) +
                    psVar1[2];
        local_8 = local_8 + 0x10;
      }
      local_78 = local_78 + local_3c;
    }
    thunk_FUN_1000f6ae(local_28 + 1,*(int *)(&DAT_100415b0 + arg_1 * 4));
    memset((void *)(local_28[*(int *)(&DAT_100415b0 + arg_1 * 4)] - 0x28),0,arg_5 * 8 + 0x50);
    if (arg_2 != 0) {
      local_8c = -local_8c;
      local_80 = &DAT_10041600 + (uint32_t)(local_8c == -1) * 0x6c0 + arg_1 * 0xc0;
    }
    arg_3 = arg_3 + arg_5 * 3 + arg_6;
  }
  return 1;
}


