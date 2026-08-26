/*
 * Decompiled function: thunk_FUN_1000fc9e
 * Entry Point: 1000177b
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1000fc9e(int arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  uint8_t flag_2;
  uint8_t flag_3;
  uint8_t bVar4;
  int val_5;
  uint32_t uval_6;
  int val_7;
  uint32_t uval_8;
  int iStack_8c;
  uint8_t *puStack_80;
  int iStack_78;
  int iStack_70;
  int iStack_64;
  uint32_t uStack_5c;
  uint32_t uStack_44;
  int iStack_3c;
  uint32_t auStack_28 [6];
  int iStack_10;
  int iStack_c;
  uint8_t *puStack_8;
  
  iStack_8c = 1;
  puStack_80 = &DAT_10041600 + arg_1 * 0xc0;
  if (DAT_1012924c == 0) {
    for (uStack_5c = -0x200; (int)uStack_5c < 0x200; uStack_5c = uStack_5c + 1) {
      if (((int)uStack_5c < 0) || (0xff < (int)uStack_5c)) {
        if ((int)uStack_5c < 0) {
          PTR_DAT_10042380[uStack_5c] = 0;
        }
        else {
          PTR_DAT_10042380[uStack_5c] = 0xff;
        }
      }
      else {
        PTR_DAT_10042380[uStack_5c] = (uint8_t)uStack_5c;
      }
    }
    DAT_1012924c = 1;
  }
  if (arg_1 != DAT_10042388) {
    for (uStack_5c = 0; uStack_5c < 0x41; uStack_5c = uStack_5c + 1) {
      if (*(int *)(&DAT_10202ee0 + uStack_5c * 4) != 0) {
        free(*(void **)(&DAT_10202ee0 + uStack_5c * 4));
        *(int32_t *)(&DAT_10202ee0 + uStack_5c * 4) = 0;
      }
    }
    thunk_FUN_1000f6ef(arg_1,0x10202ee0);
    DAT_10042388 = arg_1;
  }
  for (uStack_5c = 0; uStack_5c < 5; uStack_5c = uStack_5c + 1) {
    memset(&DAT_101cfc50 + uStack_5c * 0x8060,0,0x8060);
    auStack_28[uStack_5c + 1] = uStack_5c * 0x8060 + 0x101cfc78;
  }
  val_5 = *(int *)(&DAT_10041588 + arg_1 * 4);
  for (iStack_64 = 0; iStack_64 < arg_4; iStack_64 = iStack_64 + 1) {
    if (iStack_8c < 1) {
      iStack_10 = arg_5 + -1;
      iStack_c = -1;
      iStack_3c = -3;
    }
    else {
      iStack_10 = 0;
      iStack_c = arg_5;
      iStack_3c = 3;
    }
    iStack_78 = iStack_10 * 3;
    for (uStack_5c = iStack_10; uStack_5c != iStack_c; uStack_5c = uStack_5c + iStack_8c) {
      uval_6 = *(uint32_t *)(iStack_78 + arg_3);
      uval_8 = uval_6 & 0xffffff;
      *(uint32_t *)(iStack_78 + arg_3) = *(uint32_t *)(iStack_78 + arg_3) & 0xff000000;
      psVar1 = (short *)(auStack_28[1] + uStack_5c * 8);
      flag_2 = PTR_DAT_10042380[(uval_6 & 0xff) + ((int)*psVar1 >> 8)];
      flag_3 = PTR_DAT_10042380[(uval_8 >> 8 & 0xff) + ((int)psVar1[1] >> 8)];
      bVar4 = PTR_DAT_10042380[(uval_8 >> 0x10) + ((int)psVar1[2] >> 8)];
      auStack_28[0] = (uint32_t)flag_3 << 8 | (uint32_t)bVar4 << 0x10 | (uint32_t)flag_2;
      if (auStack_28[0] == 0) {
        uStack_44 = 0;
      }
      else if (auStack_28[0] == 0xffffff) {
        uStack_44 = 0xffffff;
      }
      else {
        uStack_44 = thunk_FUN_10010980(auStack_28[0]);
      }
      *(uint32_t *)(iStack_78 + arg_3) = *(uint32_t *)(iStack_78 + arg_3) | uStack_44;
      puStack_8 = puStack_80;
      for (iStack_70 = 0; iStack_70 < val_5; iStack_70 = iStack_70 + 1) {
        val_7 = *(int *)(puStack_8 + 0xc);
        psVar1 = (short *)(auStack_28[*(int *)(puStack_8 + 8) + 1] +
                          (*(int *)(puStack_8 + 4) + uStack_5c) * 8);
        *psVar1 = (short)*(int32_t *)(val_7 + ((uint32_t)flag_2 - (uStack_44 & 0xff)) * 4) + *psVar1;
        psVar1[1] = (short)*(int32_t *)(val_7 + ((uint32_t)flag_3 - (uStack_44 >> 8 & 0xff)) * 4) +
                    psVar1[1];
        psVar1[2] = (short)*(int32_t *)(val_7 + ((uint32_t)bVar4 - (uStack_44 >> 0x10 & 0xff)) * 4) +
                    psVar1[2];
        puStack_8 = puStack_8 + 0x10;
      }
      iStack_78 = iStack_78 + iStack_3c;
    }
    thunk_FUN_1000f6ae(auStack_28 + 1,*(int *)(&DAT_100415b0 + arg_1 * 4));
    memset((void *)(auStack_28[*(int *)(&DAT_100415b0 + arg_1 * 4)] - 0x28),0,arg_5 * 8 + 0x50);
    if (arg_2 != 0) {
      iStack_8c = -iStack_8c;
      puStack_80 = &DAT_10041600 + (uint32_t)(iStack_8c == -1) * 0x6c0 + arg_1 * 0xc0;
    }
    arg_3 = arg_3 + arg_5 * 3 + arg_6;
  }
  return 1;
}


