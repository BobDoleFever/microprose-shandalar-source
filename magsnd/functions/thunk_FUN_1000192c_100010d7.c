/*
 * Decompiled function: thunk_FUN_1000192c
 * Entry Point: 100010d7
 * Size: 5 bytes
 */
#include "magsnd.h"


int __cdecl thunk_FUN_1000192c(int32_t *ptr_1,int *ptr_2)

{
  int val_1;
  int iStack_1c;
  int *piStack_18;
  uint32_t uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  uStack_14 = 0;
  iStack_c = 0;
  if (((uint32_t)ptr_1[2] >> 1 & 1) == 0) {
    if ((ptr_2 == (int *)0x0) || (((uint32_t)ptr_2[7] >> 1 & 1) == 0)) {
      val_1 = thunk_FUN_100043c4((int)ptr_1,(int *)&piStack_18);
      if (val_1 != 0) {
        return val_1;
      }
      iStack_8 = 0;
    }
    else {
      piStack_18 = (int *)ptr_1[0x2f];
    }
  }
  else {
    if ((*(uint8_t *)(ptr_1 + 1) & 1) != 0) {
      thunk_FUN_10002900(ptr_1[4]);
    }
    if (((DAT_1000a420 == 1) && (DAT_1000a424 == 0)) &&
       (iStack_8 = thunk_FUN_100046fb(), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
    if (DAT_1000a420 != 0) {
      DAT_1000a428 = DAT_1000a428 + 1;
    }
    uStack_14 = uStack_14 | 1;
    piStack_18 = (int *)ptr_1[0x2f];
    if ((((uint32_t)ptr_1[1] >> 5 & 1) == 0) && (iStack_8 = thunk_FUN_1000394f(ptr_1), iStack_8 != 0)) {
      UnloadSnd(ptr_1[4]);
      return iStack_8;
    }
  }
  if (ptr_2 == (int *)0x0) {
    iStack_1c = 0;
    ptr_1[0x7c] = 400;
    iStack_c = ptr_1[0x1f];
    ptr_1[0x7b] = iStack_c;
    iStack_10 = 0;
    ptr_1[0x7a] = 0;
  }
  else {
    iStack_1c = *ptr_2;
    if (400 < iStack_1c) {
      iStack_1c = 400;
    }
    ptr_1[0x7c] = iStack_1c;
    iStack_1c = (iStack_1c * 5 + -2000) * 2;
    if (ptr_2[1] == 0) {
      iStack_c = ptr_1[0x1f];
    }
    else {
      iStack_c = ptr_2[1];
    }
    ptr_1[0x7b] = iStack_c;
    if (ptr_2[2] == 0) {
      iStack_10 = 0;
    }
    else {
      iStack_10 = ptr_2[2];
    }
    ptr_1[0x7a] = iStack_10;
    iStack_10 = iStack_10 * 10;
    if ((*(uint8_t *)(ptr_2 + 7) & 1) != 0) {
      uStack_14 = uStack_14 | 1;
      ptr_1[2] = ptr_1[2] | 1;
    }
    if (((uint32_t)ptr_2[7] >> 3 & 1) != 0) {
      ptr_1[2] = ptr_1[2] | 4;
    }
  }
  (**(code **)(*piStack_18 + 0x3c))(piStack_18,iStack_1c);
  (**(code **)(*piStack_18 + 0x44))(piStack_18,iStack_c);
  (**(code **)(*piStack_18 + 0x40))(piStack_18,iStack_10);
  (**(code **)(*piStack_18 + 0x34))(piStack_18,0);
  val_1 = (**(code **)(*piStack_18 + 0x30))(piStack_18,0,0,uStack_14);
  if (val_1 == 0) {
    ptr_1[1] = ptr_1[1] | 1;
    ptr_1[1] = ptr_1[1] & 0xffffffdf;
    val_1 = 0;
  }
  else {
    val_1 = 9;
  }
  return val_1;
}


