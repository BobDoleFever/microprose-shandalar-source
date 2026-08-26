/*
 * Decompiled function: thunk_FUN_10004afa
 * Entry Point: 1000104b
 * Size: 5 bytes
 */
#include "statwin.h"


void __fastcall thunk_FUN_10004afa(int32_t *ptr_1)

{
  BOOL BVar1;
  int32_t uval_2;
  int32_t uval_3;
  int32_t *unaff_FS_OFFSET;
  int32_t uval_4;
  int32_t uval_5;
  char acStack_140 [256];
  HANDLE pvStack_40;
  CPrintPreviewState aCStack_3c [24];
  DWORD *pDStack_24;
  LPCVOID pvStack_20;
  LPCVOID pvStack_1c;
  DWORD DStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10004e7b;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_3c);
  uStack_8 = 0;
  thunk_FUN_1000432f(acStack_140,PTR_s_statwin__10012ac0,PTR_s_statscrn_tmp_10012ad0);
  pvStack_40 = CreateFileA(acStack_140,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,(HANDLE)0x0);
  if (pvStack_40 == (HANDLE)0xffffffff) {
    uStack_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  BVar1 = WriteFile(pvStack_40,(LPCVOID)*ptr_1,0x34,&DStack_18,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    CloseHandle(pvStack_40);
    DeleteFileA(acStack_140);
    uStack_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  if (ptr_1[2] == 0) {
    assert(s_pbibkgrnd_10012b2c,s_G__NewMagic_tstvid_statclas_cpp_10012b0c,0x1ba);
  }
  thunk_FUN_10009e72(aCStack_3c,*(int *)(ptr_1[2] + 4),*(int *)(ptr_1[2] + 8),0x18);
  pDStack_24 = (DWORD *)thunk_FUN_100042a0((int)aCStack_3c);
  pDStack_24[5] = *(DWORD *)(ptr_1[2] + 0x14);
  if (pDStack_24 == (DWORD *)0x0) {
    assert(&DAT_10012b58,s_G__NewMagic_tstvid_statclas_cpp_10012b38,0x1be);
  }
  BVar1 = WriteFile(pvStack_40,pDStack_24,*pDStack_24,&DStack_18,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    CloseHandle(pvStack_40);
    DeleteFileA(acStack_140);
    uStack_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  iStack_14 = thunk_FUN_1000a9b8(ptr_1[3]);
  pvStack_1c = (LPCVOID)thunk_FUN_10009530(ptr_1[3]);
  if ((pvStack_1c != (LPCVOID)0x0) &&
     (BVar1 = WriteFile(pvStack_40,pvStack_1c,iStack_14 << 2,&DStack_18,(LPOVERLAPPED)0x0),
     BVar1 == 0)) {
    CloseHandle(pvStack_40);
    DeleteFileA(acStack_140);
    uStack_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  uval_5 = ptr_1[6];
  uval_4 = ptr_1[5];
  uval_2 = thunk_FUN_100095b0((CFontDialog *)aCStack_3c);
  uval_3 = thunk_FUN_10009580((CFontDialog *)aCStack_3c);
  (**(code **)(*(int *)ptr_1[3] + 0x18))(aCStack_3c,0,0,uval_3,uval_2,uval_4,uval_5);
  pvStack_20 = (LPCVOID)thunk_FUN_100042d0((int)aCStack_3c);
  if (pvStack_20 == (LPCVOID)0x0) {
    assert(s_pbits_10012b80,s_G__NewMagic_tstvid_statclas_cpp_10012b60,0x1d9);
  }
  BVar1 = WriteFile(pvStack_40,pvStack_20,pDStack_24[5],&DStack_18,(LPOVERLAPPED)0x0);
  if (BVar1 != 0) {
    CloseHandle(pvStack_40);
    uStack_8 = 0xffffffff;
    FUN_10004e72();
    FUN_10004e85();
    return;
  }
  CloseHandle(pvStack_40);
  DeleteFileA(acStack_140);
  uStack_8 = 0xffffffff;
  FUN_10004e72();
  FUN_10004e85();
  return;
}


