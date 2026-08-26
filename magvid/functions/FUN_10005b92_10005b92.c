/*
 * Decompiled function: FUN_10005b92
 * Entry Point: 10005b92
 * Size: 230 bytes
 */
#include "magvid.h"


void __cdecl FUN_10005b92(LPARAM *ptr_1)

{
  int *ptr_1_00;
  bool flag_1;
  undefined3 extraout_var;
  
  if ((ptr_1 != (LPARAM *)0x0) && (ptr_1[2] != 0)) {
    ptr_1_00 = (int *)ptr_1[2];
    if (ptr_1_00 != (int *)0x0) {
      flag_1 = thunk_FUN_10004c20((int)ptr_1_00);
      if (CONCAT31(extraout_var,flag_1) == 0) {
        return;
      }
      if (((uint32_t)ptr_1[1] >> 1 & 1) != 0) {
        thunk_FUN_10005ef9((int)ptr_1);
      }
      if (ptr_1[0x10] != 0) {
        ptr_1[0x12] = 0;
        ptr_1[0x10] = 0;
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
      thunk_FUN_10001c16(ptr_1_00);
      thunk_FUN_100019c7((int)ptr_1_00);
      LeaveCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
    PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
  }
  return;
}


