/*
 * Decompiled function: UnloadAVI
 * Entry Point: 10001131
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl UnloadAVI(int arg_1)

{
  LPARAM *ptr_1;
  void *this;
  int32_t uval_1;
  
                    /* 0x1131  4  UnloadAVI */
  if ((arg_1 < 0) || (2 < arg_1)) {
    uval_1 = 2;
  }
  else {
    ptr_1 = *(LPARAM **)(&DAT_10010868 + arg_1 * 4);
    if (ptr_1 == (LPARAM *)0x0) {
      uval_1 = 0;
    }
    else {
      if (ptr_1[0x13] != 0) {
        StopAVI(arg_1);
      }
      this = (void *)ptr_1[2];
      if ((((uint32_t)ptr_1[1] >> 3 & 1) != 0) && (ptr_1[0x1a] != 0)) {
        ptr_1[0x12] = 0;
      }
      if (((*(uint8_t *)(ptr_1 + 1) & 1) != 0) && (this != (void *)0x0)) {
        thunk_FUN_10005b92(ptr_1);
        ptr_1[1] = ptr_1[1] & 0xfffffffe;
      }
      if (ptr_1[7] != 0) {
        ReleaseDC((HWND)ptr_1[4],(HDC)ptr_1[7]);
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x1c) = 0;
        }
        ptr_1[0x19] = 0;
      }
      if ((ptr_1[4] != 0) && (ptr_1[5] != 0)) {
        DestroyWindow((HWND)ptr_1[4]);
        ptr_1[4] = 0;
        if (ptr_1[0x19] != 0) {
          *(int32_t *)(ptr_1[0x19] + 0x10) = 0;
        }
        ptr_1[5] = 0;
      }
      if (this != (void *)0x0) {
        if (this != (void *)0x0) {
          thunk_FUN_10004b20(this,1);
        }
      }
      if ((ptr_1[0x15] != 0) && (ptr_1[0x14] != 0)) {
        if ((void *)ptr_1[0x14] != (void *)0x0) {
          thunk_FUN_10004b70((void *)ptr_1[0x14],1);
        }
      }
      DAT_1001053c = ptr_1[6];
      operator_delete(ptr_1);
      *(int32_t *)(&DAT_10010868 + arg_1 * 4) = 0;
      uval_1 = 0;
    }
  }
  return uval_1;
}


