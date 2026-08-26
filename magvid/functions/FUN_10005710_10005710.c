/*
 * Decompiled function: FUN_10005710
 * Entry Point: 10005710
 * Size: 539 bytes
 */
#include "magvid.h"


void __cdecl FUN_10005710(LPARAM *ptr_1)

{
  bool flag_1;
  bool flag_2;
  int val_3;
  LPARAM *local_18;
  
  flag_1 = false;
  flag_2 = false;
  if (ptr_1[2] != 0) {
    local_18 = ptr_1;
    ptr_1[0x13] = 1;
    while ((local_18 != (LPARAM *)0x0 && (local_18[0x12] != 0))) {
      EnterCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
      if (local_18[0xe] == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
        Sleep(5);
      }
      else {
        val_3 = CArchive::IsBufferEmpty((CArchive *)local_18[2]);
        if (val_3 == 0) {
          thunk_FUN_10007c85((int *)local_18[2]);
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
          if (((!flag_1) || (flag_2)) || (_delay == 0)) {
            if (!flag_2) {
              thunk_FUN_10004f02(*ptr_1 + 0x100,0);
              flag_2 = true;
            }
          }
          else {
            thunk_FUN_10007bde((void *)local_18[2],1000);
            thunk_FUN_10004f02(*ptr_1 + 0x100,0);
            flag_2 = true;
            _delay = 0;
          }
          flag_1 = true;
          Sleep(1);
        }
        else {
          local_18[0xe] = 0;
          LeaveCriticalSection((LPCRITICAL_SECTION)(local_18 + 8));
          PostMessageA(*(HWND *)(local_18[2] + 0x14),0x111,0x9c44,*local_18);
          if (local_18[0x19] == 0) {
            local_18 = (LPARAM *)0x0;
          }
          else {
            PostMessageA(*(HWND *)(local_18[2] + 0x14),0x111,0x9c67,*(LPARAM *)local_18[0x19]);
            local_18 = (LPARAM *)local_18[0x19];
          }
        }
      }
    }
    thunk_FUN_10004f90(*ptr_1 + 0x100);
    thunk_FUN_10004ea1(*ptr_1 + 0x100);
    ptr_1[0x13] = 0;
  }
  return;
}


