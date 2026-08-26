/*
 * Decompiled function: thunk_FUN_10005ef9
 * Entry Point: 10001285
 * Size: 5 bytes
 */
#include "magvid.h"


void __cdecl thunk_FUN_10005ef9(int arg_1)

{
  int32_t *ptr_1;
  HDC hDC;
  bool flag_1;
  undefined3 extraout_var;
  HANDLE hProcess;
  
  ptr_1 = *(int32_t **)(arg_1 + 8);
  if ((ptr_1 != (int32_t *)0x0) &&
     (flag_1 = thunk_FUN_10004c20((int)ptr_1), CONCAT31(extraout_var,flag_1) != 0)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    *(int32_t *)(arg_1 + 0x3c) = 0;
    *(int32_t *)(arg_1 + 0x38) = 0;
    hDC = (HDC)ptr_1[0xc];
    thunk_FUN_10001d28(ptr_1);
    if (*(int *)(arg_1 + 100) == 0) {
      hProcess = GetCurrentProcess();
      SetPriorityClass(hProcess,0x20);
      if (*(int *)(arg_1 + 0x48) != 0) {
        *(int32_t *)(arg_1 + 0x48) = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
      CloseHandle(*(HANDLE *)(arg_1 + 0x40));
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)(arg_1 + 0x20));
    }
    thunk_FUN_10007050((int)ptr_1);
    if (hDC != (HDC)0x0) {
      ReleaseDC(*(HWND *)(arg_1 + 0x10),hDC);
    }
  }
  return;
}


