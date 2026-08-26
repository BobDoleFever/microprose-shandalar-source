/*
 * Decompiled function: thunk_FUN_1000630c
 * Entry Point: 10001064
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_1000630c(int32_t *ptr_1)

{
  int32_t uval_1;
  int iStack_34;
  uint32_t uStack_30;
  uint8_t auStack_2c [4];
  uint32_t uStack_28;
  int iStack_24;
  uint8_t auStack_20 [4];
  int iStack_1c;
  int iStack_18;
  int32_t uStack_14;
  int iStack_10;
  int32_t uStack_c;
  int iStack_8;
  
  iStack_24 = ptr_1[0x25] * ptr_1[0x23];
  iStack_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                       (ptr_1[0x2f],0,iStack_24,&iStack_34,&uStack_c,&iStack_18,&uStack_14,0);
  if (iStack_8 == 0) {
    if (iStack_18 == 0) {
      ptr_1[0x76] = 0;
      ptr_1[0x74] = 0;
      ptr_1[0x75] = 0;
      iStack_1c = iStack_34;
      iStack_10 = 0;
      uStack_28 = (uint32_t)ptr_1[0x23] / (uint32_t)ptr_1[0x24];
      iStack_8 = 0;
      for (uStack_30 = 0; uStack_30 < (uint32_t)ptr_1[0x25]; uStack_30 = uStack_30 + 1) {
        AVIStreamRead(*ptr_1,iStack_10,uStack_28,iStack_1c,ptr_1[0x23],auStack_2c,auStack_20);
        ptr_1[0x76] = ptr_1[0x76] + ptr_1[0x23];
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + ptr_1[0x23];
        ptr_1[0x75] = ptr_1[0x75] + ptr_1[0x23];
        iStack_1c = iStack_1c + ptr_1[0x23];
        iStack_10 = iStack_10 + uStack_28;
      }
      iStack_8 = (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))
                           (ptr_1[0x2f],iStack_34,uStack_c,iStack_18,uStack_14);
      if (iStack_8 == 0) {
        uval_1 = 0;
      }
      else {
        thunk_FUN_10005a46(ptr_1);
        thunk_FUN_10006622(ptr_1);
        uval_1 = 9;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],iStack_34,uStack_c,iStack_18,uStack_14);
      thunk_FUN_1000681e();
      thunk_FUN_10006622(ptr_1);
      uval_1 = 9;
    }
  }
  else {
    thunk_FUN_1000681e();
    thunk_FUN_10006622(ptr_1);
    uval_1 = 9;
  }
  return uval_1;
}


