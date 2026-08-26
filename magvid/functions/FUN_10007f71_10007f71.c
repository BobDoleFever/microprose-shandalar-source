/*
 * Decompiled function: FUN_10007f71
 * Entry Point: 10007f71
 * Size: 448 bytes
 */
#include "magvid.h"


int32_t __fastcall FUN_10007f71(int32_t *ptr_1)

{
  int val_1;
  int32_t uval_2;
  int local_c;
  int local_8;
  
  if ((int)ptr_1[0x11] < (int)ptr_1[0x12]) {
    ptr_1[0x12] = 0xffffffff;
  }
  if (ptr_1[0x11] - ptr_1[0x12] != 1) {
    val_1 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11],0x14);
    if (val_1 == ptr_1[0x11]) {
      ptr_1[0x13] = ptr_1[0x11];
      uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
      ptr_1[0x14] = uval_2;
    }
    else if (ptr_1[0x11] - ptr_1[0x12] == 2) {
      thunk_FUN_10008136(ptr_1);
    }
    else {
      if (((int)ptr_1[0x14] < (int)ptr_1[0x11]) || ((int)ptr_1[0x11] < (int)ptr_1[0x13])) {
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + -1,0x14);
        ptr_1[0x13] = uval_2;
        uval_2 = AVIStreamFindSample(ptr_1[3],ptr_1[0x11] + 1,0x11);
        ptr_1[0x14] = uval_2;
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x13]) < 0) {
        local_8 = -(ptr_1[0x11] - ptr_1[0x13]);
      }
      else {
        local_8 = ptr_1[0x11] - ptr_1[0x13];
      }
      if ((int)(ptr_1[0x11] - ptr_1[0x14]) < 0) {
        local_c = -(ptr_1[0x11] - ptr_1[0x14]);
      }
      else {
        local_c = ptr_1[0x11] - ptr_1[0x14];
      }
      if (local_c < local_8) {
        if (ptr_1[6] != 0) {
          return 0;
        }
        thunk_FUN_10008136(ptr_1);
      }
      else {
        thunk_FUN_10008136(ptr_1);
      }
    }
  }
  return 1;
}


