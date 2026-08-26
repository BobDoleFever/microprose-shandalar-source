/*
 * Decompiled function: thunk_FUN_10005f0c
 * Entry Point: 100010eb
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_10005f0c(int32_t *ptr_1,int arg_2)

{
  int32_t uval_1;
  int iStack_4c;
  int iStack_44;
  HPSTR pcStack_40;
  int iStack_3c;
  int iStack_38;
  int32_t uStack_34;
  size_t sStack_30;
  HPSTR pcStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int32_t uStack_1c;
  int32_t uStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int32_t uStack_8;
  
  pcStack_40 = (HPSTR)0x0;
  uStack_1c = 0;
  pcStack_2c = (HPSTR)0x0;
  uStack_8 = 0;
  uStack_18 = 0;
  uStack_34 = 0;
  iStack_38 = 0;
  if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
    thunk_FUN_10005d4a((int)ptr_1,arg_2);
  }
  iStack_3c = (uint32_t)*(uint16_t *)(ptr_1 + 0x21) * arg_2;
  iStack_28 = ptr_1[0x73];
  iStack_4c = iStack_28 - iStack_3c;
  sStack_30 = 0x10000;
  if ((iStack_3c < 0) || (iStack_28 < iStack_3c)) {
    uval_1 = 5;
  }
  else {
    iStack_20 = iStack_3c;
    iStack_c = iStack_3c;
    iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                          (ptr_1[0x2f],0,0x10000,&pcStack_40,&uStack_8,&uStack_1c,&uStack_18,0);
    if (iStack_14 == 0) {
      pcStack_2c = pcStack_40;
      iStack_14 = 0;
      while (iStack_38 == 0) {
        if (iStack_4c < (int)sStack_30) {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            iStack_10 = mmioRead((HMMIO)ptr_1[0x72],pcStack_2c,iStack_4c);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,pcStack_2c,iStack_4c,&iStack_10,0);
          }
          pcStack_2c = pcStack_2c + iStack_10;
          sStack_30 = sStack_30 - iStack_10;
          iStack_4c = 0;
          iStack_20 = ptr_1[0x73];
          if ((*(uint8_t *)(ptr_1 + 2) & 1) == 0) {
            memset(pcStack_2c,0,sStack_30);
            iStack_38 = 1;
          }
          else {
            if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
              thunk_FUN_10005d4a((int)ptr_1,0);
            }
            iStack_20 = 0;
            iStack_4c = ptr_1[0x73];
            iStack_c = 0;
          }
        }
        else {
          if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
            iStack_10 = mmioRead((HMMIO)ptr_1[0x72],pcStack_2c,sStack_30);
          }
          else {
            AVIStreamRead(*ptr_1,arg_2,
                          (int)(0x10000 / (ulonglong)(longlong)(int)(uint32_t)*(uint16_t *)(ptr_1 + 0x21))
                          ,pcStack_2c,0x10000,&iStack_10,&iStack_44);
          }
          sStack_30 = sStack_30 - iStack_10;
          iStack_c = iStack_c + iStack_10;
          iStack_4c = iStack_4c - iStack_10;
          iStack_20 = iStack_20 + iStack_10;
          arg_2 = arg_2 + iStack_44;
          iStack_38 = 1;
        }
      }
      mmioGetInfo((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        mmioAdvance((HMMIO)ptr_1[0x72],(LPMMIOINFO)(ptr_1 + 0x60),0);
      }
      else {
        thunk_FUN_10006830(ptr_1,arg_2);
      }
      iStack_24 = iStack_4c;
      if (0xffff < iStack_4c) {
        iStack_24 = 0x10000;
      }
      ptr_1[0x74] = ptr_1[0x73] - (iStack_4c - iStack_24);
      ptr_1[0x75] = ptr_1[0x73] - iStack_4c;
      ptr_1[0x76] = 0;
      iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                            (ptr_1[0x2f],pcStack_40,uStack_8,uStack_1c,uStack_18);
      if (iStack_14 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      if (((uint32_t)ptr_1[2] >> 5 & 1) == 0) {
        thunk_FUN_10005a46(ptr_1);
      }
      else {
        thunk_FUN_1000681e();
      }
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  return uval_1;
}


