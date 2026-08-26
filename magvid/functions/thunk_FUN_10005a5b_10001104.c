/*
 * Decompiled function: thunk_FUN_10005a5b
 * Entry Point: 10001104
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl thunk_FUN_10005a5b(LPARAM *ptr_1,LPCSTR arg_2)

{
  void *this;
  bool flag_1;
  int32_t uval_2;
  HANDLE hFile;
  DWORD DVar3;
  undefined3 extraout_var;
  int val_4;
  
  if ((ptr_1 == (LPARAM *)0x0) || (ptr_1[2] == 0)) {
    uval_2 = 2;
  }
  else {
    this = (void *)ptr_1[2];
    hFile = (HANDLE)_lopen(arg_2,0);
    if (hFile == (HANDLE)0xffffffff) {
      uval_2 = 1;
    }
    else {
      DVar3 = GetFileSize(hFile,(LPDWORD)0x0);
      ptr_1[0x18] = DVar3;
      ptr_1[0x18] = (int)(ptr_1[0x18] + (ptr_1[0x18] >> 0x1f & 0x3ffU)) >> 10;
      _lclose((HFILE)hFile);
      flag_1 = thunk_FUN_10004c20((int)this);
      if (CONCAT31(extraout_var,flag_1) != 0) {
        thunk_FUN_10005b92(ptr_1);
      }
      val_4 = thunk_FUN_10001951(this,arg_2);
      if (val_4 == 0) {
        val_4 = thunk_FUN_10001a02(this,ptr_1[4],*ptr_1);
        if (val_4 == 0) {
          ptr_1[1] = ptr_1[1] | 1;
          PostMessageA((HWND)ptr_1[4],0x401,0,*ptr_1);
          InitializeCriticalSection((LPCRITICAL_SECTION)(ptr_1 + 8));
          uval_2 = 0;
        }
        else {
          uval_2 = 1;
        }
      }
      else {
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}


