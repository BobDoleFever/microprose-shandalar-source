/*
 * Decompiled function: thunk_FUN_1000f104
 * Entry Point: 10001474
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_1000f104(int arg_1,int arg_2,uint32_t *arg_3,int arg_4,int arg_5,int arg_6)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  short *psVar4;
  int iStack_8c;
  uint8_t *puStack_80;
  int iStack_78;
  int iStack_64;
  uint32_t uStack_5c;
  uint32_t uStack_50;
  uint32_t uStack_44;
  uint32_t uStack_40;
  int iStack_3c;
  uint32_t uStack_34;
  uint32_t auStack_28 [6];
  int iStack_10;
  int iStack_c;
  uint8_t *puStack_8;
  
  iStack_8c = 1;
  puStack_80 = &DAT_10041600 + arg_1 * 0xc0;
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
      DAT_10129258 = 1;
    }
    if (arg_1 != DAT_10042384) {
      for (uStack_5c = 0; uStack_5c < 0x41; uStack_5c = uStack_5c + 1) {
        if (*(int *)(&DAT_10202ee0 + uStack_5c * 4) != 0) {
          free(*(void **)(&DAT_10202ee0 + uStack_5c * 4));
          *(int32_t *)(&DAT_10202ee0 + uStack_5c * 4) = 0;
        }
      }
      thunk_FUN_1000f6ef(arg_1,0x10202ee0);
      DAT_10042384 = arg_1;
    }
    for (uStack_5c = 0; uStack_5c < 5; uStack_5c = uStack_5c + 1) {
      thunk_FUN_100029d0((undefined8 *)(&DAT_101cfc50 + uStack_5c * 0x8060),0,0x8060);
      auStack_28[uStack_5c + 1] = uStack_5c * 0x8060 + 0x101cfc78;
    }
    val_1 = *(int *)(&DAT_10041588 + arg_1 * 4);
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
        uval_2 = *(uint32_t *)(iStack_78 + (int)arg_3);
        auStack_28[0] = uval_2 & 0xffffff;
        *(uint32_t *)(iStack_78 + (int)arg_3) = *(uint32_t *)(iStack_78 + (int)arg_3) & 0xff000000;
        psVar4 = (short *)(auStack_28[1] + uStack_5c * 8);
        if (auStack_28[0] == 0) {
          uStack_44 = 0;
          uStack_50 = 0;
          uStack_40 = 0;
          uStack_34 = 0;
        }
        else if (auStack_28[0] == 0xffffff) {
          uStack_50 = 0xff;
          uStack_40 = 0xff;
          uStack_34 = 0xff;
          uStack_44 = 0xffffff;
        }
        else {
          uStack_34 = (uint32_t)(uint8_t)PTR_DAT_10042380[(uval_2 & 0xff) + ((int)*psVar4 >> 8)];
          uStack_40 = (uint32_t)(uint8_t)PTR_DAT_10042380
                                  [(auStack_28[0] >> 8 & 0xff) + ((int)psVar4[1] >> 8)];
          uStack_50 = (uint32_t)(uint8_t)PTR_DAT_10042380[(auStack_28[0] >> 0x10) + ((int)psVar4[2] >> 8)];
          auStack_28[0] = uStack_50 << 0x10 | uStack_40 << 8 | uStack_34;
          uStack_44 = thunk_FUN_1000ebea(auStack_28[0]);
        }
        *(uint32_t *)(iStack_78 + (int)arg_3) = *(uint32_t *)(iStack_78 + (int)arg_3) | uStack_44;
        for (puStack_8 = puStack_80; puStack_8 < puStack_80 + val_1 * 0x10;
            puStack_8 = puStack_8 + 0x10) {
          val_3 = *(int *)(puStack_8 + 0xc);
          psVar4 = (short *)((*(int *)(puStack_8 + 4) + uStack_5c) * 8 +
                            auStack_28[*(int *)(puStack_8 + 8) + 1]);
          *psVar4 = (short)*(int32_t *)(val_3 + (uStack_34 - (uStack_44 & 0xff)) * 4) + *psVar4;
          psVar4[1] = (short)*(int32_t *)(val_3 + (uStack_40 - (uStack_44 >> 8 & 0xff)) * 4) +
                      psVar4[1];
          psVar4[2] = (short)*(int32_t *)(val_3 + (uStack_50 - (uStack_44 >> 0x10)) * 4) +
                      psVar4[2];
        }
        iStack_78 = iStack_78 + iStack_3c;
      }
      thunk_FUN_1000f6ae(auStack_28 + 1,*(int *)(&DAT_100415b0 + arg_1 * 4));
      memset((void *)(auStack_28[*(int *)(&DAT_100415b0 + arg_1 * 4)] - 0x28),0,arg_5 * 8 + 0x50);
      if (arg_2 != 0) {
        iStack_8c = -iStack_8c;
        puStack_80 = &DAT_10041600 + (uint32_t)(iStack_8c == -1) * 0x6c0 + arg_1 * 0xc0;
      }
      arg_3 = (uint32_t *)((int)arg_3 + arg_5 * 3 + arg_6);
    }
  }
  return arg_4;
}


