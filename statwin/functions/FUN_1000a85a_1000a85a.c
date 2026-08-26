/*
 * Decompiled function: FUN_1000a85a
 * Entry Point: 1000a85a
 * Size: 350 bytes
 */
#include "statwin.h"


int32_t __thiscall FUN_1000a85a(void *this,LPCSTR arg_2)

{
  int16_t uval_1;
  HANDLE hFile;
  int32_t uval_2;
  short extraout_var;
  LPCVOID buf_ptr_3;
  DWORD nNumberOfBytesToWrite;
  DWORD local_24;
  LPCVOID local_20;
  int local_1c;
  int16_t local_18;
  int local_16;
  int16_t local_12;
  int16_t local_10;
  int local_e;
  int32_t local_8;
  
  local_8 = 0;
  local_1c = 0;
  hFile = CreateFileA(arg_2,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    uval_2 = 2;
  }
  else {
    local_18 = 0x4d42;
    local_12 = 0;
    local_10 = 0;
    local_1c = thunk_FUN_1000a9b8((int)this);
    uval_1 = thunk_FUN_1000b6e0((int)this);
    local_16 = local_1c * 4 + 0x36;
    local_e = local_16;
    buf_ptr_3 = (LPCVOID)thunk_FUN_100042a0((int)this);
    nNumberOfBytesToWrite =
         *(int *)((int)buf_ptr_3 + 4) *
         ((int)(CONCAT22(extraout_var,uval_1) + ((int)extraout_var >> 0xf & 7U)) >> 3) *
         *(int *)((int)buf_ptr_3 + 8);
    local_16 = local_16 + nNumberOfBytesToWrite;
    WriteFile(hFile,&local_18,0xe,&local_24,(LPOVERLAPPED)0x0);
    *(DWORD *)((int)buf_ptr_3 + 0x14) = nNumberOfBytesToWrite;
    WriteFile(hFile,buf_ptr_3,0x28,&local_24,(LPOVERLAPPED)0x0);
    if (local_1c != 0) {
      buf_ptr_3 = (LPCVOID)thunk_FUN_10009530((int)this);
      WriteFile(hFile,buf_ptr_3,local_1c << 2,&local_24,(LPOVERLAPPED)0x0);
    }
    local_20 = (LPCVOID)thunk_FUN_100042d0((int)this);
    WriteFile(hFile,local_20,nNumberOfBytesToWrite,&local_24,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
    uval_2 = 0;
  }
  return uval_2;
}


