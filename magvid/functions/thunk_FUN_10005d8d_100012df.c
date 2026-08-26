/*
 * Decompiled function: thunk_FUN_10005d8d
 * Entry Point: 100012df
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10005d8d(LPVOID arg_1)

{
  void *this;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE buf_ptr_2;
  HDC arg_2;
  
  if ((((arg_1 != (LPVOID)0x0) && (*(int *)((int)arg_1 + 8) != 0)) &&
      (this = *(void **)((int)arg_1 + 8), this != (void *)0x0)) &&
     ((flag_1 = thunk_FUN_10004c20((int)this), CONCAT31(extraout_var,flag_1) != 0 &&
      (*(int *)((int)arg_1 + 0x38) == 0)))) {
    *(int32_t *)((int)arg_1 + 0x48) = 1;
    if ((*(int *)((int)arg_1 + 0x3c) == 0) &&
       ((*(int *)((int)arg_1 + 0x40) == 0 && ((*(uint32_t *)((int)arg_1 + 4) >> 3 & 1) == 0)))) {
      buf_ptr_2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_10001005,arg_1
                            ,0,(LPDWORD)((int)arg_1 + 0x44));
      *(HANDLE *)((int)arg_1 + 0x40) = buf_ptr_2;
    }
    if (*(int *)((int)arg_1 + 100) != 0) {
      *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) = *(uint32_t *)(*(int *)((int)arg_1 + 100) + 4) | 8;
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x40) = *(int32_t *)((int)arg_1 + 0x40);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x44) = *(int32_t *)((int)arg_1 + 0x44);
      *(int32_t *)(*(int *)((int)arg_1 + 100) + 0x48) = 1;
    }
    arg_2 = GetDC(*(HWND *)((int)arg_1 + 0x10));
    thunk_FUN_10001c8e(this,(int)arg_2);
    SetThreadPriority(*(HANDLE *)((int)arg_1 + 0x40),1);
    EnterCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
    *(int32_t *)((int)arg_1 + 0x3c) = 0;
    *(int32_t *)((int)arg_1 + 0x38) = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)arg_1 + 0x20));
  }
  return;
}


