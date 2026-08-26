/*
 * Decompiled function: thunk_FUN_1000405a
 * Entry Point: 1000108c
 * Size: 5 bytes
 */
#include "magsnd.h"


int32_t __cdecl thunk_FUN_1000405a(int32_t *ptr_1)

{
  uint32_t uval_1;
  uint32_t uval_2;
  uint32_t uStack_48;
  int32_t uStack_44;
  int32_t uStack_40;
  int32_t uStack_3c;
  int32_t uStack_38;
  uint32_t uStack_34;
  uint32_t uStack_30;
  uint8_t auStack_2c [4];
  int32_t uStack_28;
  int32_t uStack_24;
  uint32_t uStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint32_t uStack_c;
  uint32_t uStack_8;
  
  uStack_28 = 0;
  uStack_48 = 0;
  uStack_40 = 0;
  uStack_38 = 0;
  uStack_24 = 0;
  uStack_44 = 0;
  iStack_10 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  uStack_3c = 0;
  (**(code **)(*(int *)ptr_1[0x2f] + 0x10))(ptr_1[0x2f],&uStack_48,&uStack_28);
  uStack_34 = (uint32_t)ptr_1[0x77] % (uint32_t)ptr_1[0x2c];
  if (uStack_34 < uStack_48) {
    ptr_1[0x77] = ptr_1[0x77] + (uStack_48 - uStack_34);
  }
  else {
    ptr_1[0x77] = ptr_1[0x77] + (ptr_1[0x2c] - uStack_34);
    ptr_1[0x77] = ptr_1[0x77] + uStack_48;
  }
  uStack_30 = uStack_48 / (uint32_t)ptr_1[0x23];
  uStack_20 = (uint32_t)ptr_1[0x76] / (uint32_t)ptr_1[0x23];
  if (uStack_20 != uStack_30) {
    if (((((uint32_t)ptr_1[1] >> 4 & 1) == 0) || ((uint32_t)ptr_1[0x75] < (uint32_t)ptr_1[0x2c])) &&
       ((((uint32_t)ptr_1[1] >> 1 & 1) == 0 || (ptr_1[0x7c] != 0)))) {
      iStack_18 = ptr_1[0x23];
      if (((uint32_t)ptr_1[1] >> 4 & 1) == 0) {
        uval_1 = ptr_1[0x74];
        uval_2 = ptr_1[0x24];
        iStack_14 = (**(code **)(*(int *)ptr_1[0x2f] + 0x2c))
                              (ptr_1[0x2f],ptr_1[0x76],iStack_18,&uStack_44,&uStack_8,&iStack_10,
                               &uStack_c,0);
        if (iStack_14 != 0) {
          return 10;
        }
        AVIStreamRead(*ptr_1,uval_1 / uval_2,uStack_8 / (uint32_t)ptr_1[0x24],uStack_44,uStack_8,
                      auStack_2c,&iStack_1c);
        if (iStack_10 != 0) {
          AVIStreamRead(*ptr_1,iStack_1c + uval_1 / uval_2,uStack_c / (uint32_t)ptr_1[0x24],iStack_10,
                        uStack_c,auStack_2c,&iStack_1c);
        }
        ptr_1[0x76] = ptr_1[0x76] + iStack_18;
        ptr_1[0x76] = (uint32_t)ptr_1[0x76] % (uint32_t)ptr_1[0x2c];
        ptr_1[0x74] = ptr_1[0x74] + iStack_18;
        ptr_1[0x75] = ptr_1[0x75] + iStack_18;
        if ((uint32_t)ptr_1[0x73] <= (uint32_t)ptr_1[0x74]) {
          ptr_1[1] = ptr_1[1] | 0x10;
          ptr_1[0x75] = 0;
        }
        (**(code **)(*(int *)ptr_1[0x2f] + 0x4c))(ptr_1[0x2f],uStack_44,uStack_8,iStack_10,uStack_c)
        ;
        ptr_1[1] = ptr_1[1] & 0xffffff7f;
      }
      else {
        ptr_1[0x75] = ptr_1[0x75] + iStack_18;
      }
    }
    else {
      (**(code **)(*(int *)ptr_1[0x2f] + 0x48))(ptr_1[0x2f]);
      if ((0 < DAT_1000a428) && (DAT_1000a428 = DAT_1000a428 + -1, DAT_1000a428 == 0)) {
        thunk_FUN_10004788();
      }
      ptr_1[1] = ptr_1[1] & 0xfffffffe;
      ptr_1[1] = ptr_1[1] & 0xfffffffd;
      ptr_1[1] = ptr_1[1] | 4;
      ptr_1[1] = ptr_1[1] & 0xffffffdf;
      ptr_1[0x77] = 0;
    }
  }
  return 0;
}


