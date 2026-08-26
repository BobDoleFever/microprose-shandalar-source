/*
 * Decompiled function: FUN_10004afa
 * Entry Point: 10004afa
 * Size: 888 bytes
 */
#include "statwin.h"


void __fastcall FUN_10004afa(int32_t *ptr_1)

{
  BOOL BVar1;
  int32_t uval_2;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int32_t uval_4;
  int32_t uval_5;
  char local_140 [256];
  HANDLE local_40;
  CPrintPreviewState local_3c [24];
  DWORD *local_24;
  LPCVOID local_20;
  LPCVOID local_1c;
  DWORD local_18;
  int local_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10004e7b;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(local_3c);
  local_8 = 0;
  thunk_FUN_1000432f(local_140,PTR_s_statwin__10012ac0,PTR_s_statscrn_tmp_10012ad0);
  local_40 = CreateFileA(local_140,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
  if (local_40 == (HANDLE)0xffffffff) {
    local_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  BVar1 = WriteFile(local_40,(LPCVOID)*ptr_1,0x34,&local_18,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    CloseHandle(local_40);
    DeleteFileA(local_140);
    local_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  if (ptr_1[2] == 0) {
    assert(s_pbibkgrnd_10012b2c,s_G__NewMagic_tstvid_statclas_cpp_10012b0c,0x1ba);
  }
  thunk_FUN_10009e72(local_3c,*(int *)(ptr_1[2] + 4),*(int *)(ptr_1[2] + 8),0x18);
  local_24 = (DWORD *)thunk_FUN_100042a0((int)local_3c);
  local_24[5] = *(DWORD *)(ptr_1[2] + 0x14);
  if (local_24 == (DWORD *)0x0) {
    assert(&DAT_10012b58,s_G__NewMagic_tstvid_statclas_cpp_10012b38,0x1be);
  }
  BVar1 = WriteFile(local_40,local_24,*local_24,&local_18,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    CloseHandle(local_40);
    DeleteFileA(local_140);
    local_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  local_14 = thunk_FUN_1000a9b8(ptr_1[3]);
  local_1c = (LPCVOID)thunk_FUN_10009530(ptr_1[3]);
  if ((local_1c != (LPCVOID)0x0) &&
     (BVar1 = WriteFile(local_40,local_1c,local_14 << 2,&local_18,(LPOVERLAPPED)0x0), BVar1 == 0)) {
    CloseHandle(local_40);
    DeleteFileA(local_140);
    local_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  uval_5 = ptr_1[6];
  uval_4 = ptr_1[5];
  uval_2 = thunk_FUN_100095b0((CFontDialog *)local_3c);
  uval_3 = thunk_FUN_10009580((CFontDialog *)local_3c);
  (**(code **)(*(int *)ptr_1[3] + 0x18))(local_3c,0,0,uval_3,uval_2,uval_4,uval_5);
  local_20 = (LPCVOID)thunk_FUN_100042d0((int)local_3c);
  if (local_20 == (LPCVOID)0x0) {
    assert(s_pbits_10012b80,s_G__NewMagic_tstvid_statclas_cpp_10012b60,0x1d9);
  }
  BVar1 = WriteFile(local_40,local_20,local_24[5],&local_18,(LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    CloseHandle(local_40);
    local_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  CloseHandle(local_40);
  DeleteFileA(local_140);
  local_8 = 0xffffffff;
  FUN_10004e72();
  FUN_10004e85();
  return;
}


