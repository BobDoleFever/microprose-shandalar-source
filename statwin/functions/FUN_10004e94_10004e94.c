/*
 * Decompiled function: FUN_10004e94
 * Entry Point: 10004e94
 * Size: 2567 bytes
 */
#include "statwin.h"


void __fastcall FUN_10004e94(int *ptr_1)

{
  CPrintPreviewState *this;
  void *buf_ptr_1;
  BOOL BVar2;
  int32_t *unaff_FS_OFFSET;
  int local_1a0;
  char local_190 [256];
  int local_90;
  uint8_t local_8c [14];
  uint16_t local_7e;
  uint32_t local_78;
  HANDLE local_64;
  int local_60;
  int *local_5c;
  void *local_58;
  DWORD local_54;
  uint8_t local_50 [8];
  int local_48;
  int local_44;
  CPrintPreviewState local_40 [24];
  int *local_28;
  DWORD local_24;
  int32_t local_20 [2];
  int local_18;
  int local_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100058b4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(local_40);
  local_8 = 0;
  local_58 = (void *)0x0;
  local_28 = (int *)0x0;
  if (ptr_1[3] != 0) {
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    ptr_1[3] = 0;
  }
  this = operator_new(0x18);
  local_8._0_1_ = 1;
  if (this == (CPrintPreviewState *)0x0) {
    local_1a0 = 0;
  }
  else {
    local_1a0 = CPrintPreviewState::CPrintPreviewState(this);
  }
  local_8 = (uint32_t)local_8._1_3_ << 8;
  ptr_1[3] = local_1a0;
  if (*ptr_1 != 0) {
    operator_delete((void *)*ptr_1);
    *ptr_1 = 0;
  }
  buf_ptr_1 = operator_new(0x34);
  *ptr_1 = (int)buf_ptr_1;
  ptr_1[7] = 0;
  local_90 = GetSystemMetrics(0);
  local_60 = GetSystemMetrics(1);
  thunk_FUN_10009e72((void *)ptr_1[3],local_90,local_60,0x18);
  thunk_FUN_1000432f(local_190,PTR_s_statwin__10012ac0,PTR_s_statscrn_tmp_10012ad0);
  local_64 = CreateFileA(local_190,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (local_64 == (HANDLE)0xffffffff) {
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    local_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  local_54 = 0x34;
  BVar2 = ReadFile(local_64,(LPVOID)*ptr_1,0x34,&local_24,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    CloseHandle(local_64);
    DeleteFileA(local_190);
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    local_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  if (local_24 != local_54) {
    assert(s_nBytesRead____nBytesToRead_10012ba8,s_G__NewMagic_tstvid_statclas_cpp_10012b88,0x223);
  }
  local_54 = 0x28;
  BVar2 = ReadFile(local_64,local_8c,0x28,&local_24,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    if (local_24 != local_54) {
      assert(s_nBytesRead____nBytesToRead_10012be4,s_G__NewMagic_tstvid_statclas_cpp_10012bc4,0x22f)
      ;
    }
    if (local_7e < 9) {
      local_5c = operator_new(0x428);
      local_54 = 0x400;
      local_28 = local_5c + 0x1b8;
      if (ptr_1[2] == 0) {
        buf_ptr_1 = operator_new(0x428);
        ptr_1[2] = (int)buf_ptr_1;
      }
      if ((local_28 == (int *)0x0) || (ptr_1[2] == 0)) {
        assert(s_pclrs____pbibkgrnd_10012c20,s_G__NewMagic_tstvid_statclas_cpp_10012c00,0x23b);
      }
      BVar2 = ReadFile(local_64,local_28,local_54,&local_24,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        CloseHandle(local_64);
        DeleteFileA(local_190);
        if ((void *)ptr_1[3] != (void *)0x0) {
          thunk_FUN_10004250((void *)ptr_1[3],1);
        }
        operator_delete((void *)*ptr_1);
        local_8 = 0xffffffff;
        FUN_100058ab();
        FUN_100058be();
        return;
      }
      memcpy((void *)(ptr_1[2] + 0x6e0),local_28,local_24);
      if (local_24 != local_54) {
        assert(s_nBytesRead____nBytesToRead_10012c54,s_G__NewMagic_tstvid_statclas_cpp_10012c34,
               0x246);
      }
    }
    else {
      local_5c = operator_new(0x28);
      if (ptr_1[2] == 0) {
        buf_ptr_1 = operator_new(0x28);
        ptr_1[2] = (int)buf_ptr_1;
      }
    }
    memcpy(local_5c,local_8c,0x28);
    memcpy((void *)ptr_1[2],local_8c,0x28);
    local_58 = operator_new(local_78);
    local_54 = local_78;
    if (local_58 == (void *)0x0) {
      assert(s_pbits_10012c90,s_G__NewMagic_tstvid_statclas_cpp_10012c70,599);
    }
    BVar2 = ReadFile(local_64,local_58,local_54,&local_24,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      if (local_24 != local_54) {
        assert(s_nBytesRead____nBytesToRead_10012cb8,s_G__NewMagic_tstvid_statclas_cpp_10012c98,
               0x262);
      }
      thunk_FUN_1000a058(local_40,local_5c,local_58);
      thunk_FUN_1000acc2(local_40,local_20);
      (**(code **)(*(int *)ptr_1[3] + 0x14))(local_50);
      if ((local_48 == local_18) && (local_14 == local_44)) {
        thunk_FUN_1000ad09(local_40,(CFontDialog *)ptr_1[3],0,0,local_18,local_14,0,0);
        ptr_1[5] = 0;
        ptr_1[6] = 0;
      }
      else {
        if ((local_48 <= local_18) || (local_44 <= local_14)) {
          CloseHandle(local_64);
          DeleteFileA(local_190);
          operator_delete(local_5c);
          operator_delete(local_58);
          if ((void *)ptr_1[3] != (void *)0x0) {
            thunk_FUN_10004250((void *)ptr_1[3],1);
          }
          operator_delete((void *)*ptr_1);
          local_8 = 0xffffffff;
          FUN_100058ab();
          FUN_100058be();
          return;
        }
        ptr_1[5] = (local_48 - local_18) / 2;
        ptr_1[6] = (local_44 - local_14) / 2;
        thunk_FUN_1000ad09(local_40,(CFontDialog *)ptr_1[3],ptr_1[5],ptr_1[6],local_18,local_14,0,0)
        ;
      }
      operator_delete(local_5c);
      operator_delete(local_58);
      CloseHandle(local_64);
      local_8 = 0xffffffff;
      FUN_100058ab();
      FUN_100058be();
      return;
    }
    CloseHandle(local_64);
    DeleteFileA(local_190);
    operator_delete(local_5c);
    operator_delete(local_58);
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    local_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  CloseHandle(local_64);
  DeleteFileA(local_190);
  if ((void *)ptr_1[3] != (void *)0x0) {
    thunk_FUN_10004250((void *)ptr_1[3],1);
  }
  operator_delete((void *)*ptr_1);
  local_8 = 0xffffffff;
  FUN_100058ab();
  FUN_100058be();
  return;
}


