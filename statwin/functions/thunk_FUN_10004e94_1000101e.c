/*
 * Decompiled function: thunk_FUN_10004e94
 * Entry Point: 1000101e
 * Size: 5 bytes
 */
#include "statwin.h"


void __fastcall thunk_FUN_10004e94(int *ptr_1)

{
  CPrintPreviewState *this;
  void *buf_ptr_1;
  BOOL BVar2;
  int32_t *unaff_FS_OFFSET;
  int iStack_1a0;
  char acStack_190 [256];
  int iStack_90;
  uint8_t auStack_8c [14];
  uint16_t uStack_7e;
  uint32_t uStack_78;
  HANDLE pvStack_64;
  int iStack_60;
  int *piStack_5c;
  void *pvStack_58;
  DWORD DStack_54;
  uint8_t auStack_50 [8];
  int iStack_48;
  int iStack_44;
  CPrintPreviewState aCStack_40 [24];
  int *piStack_28;
  DWORD DStack_24;
  int32_t auStack_20 [2];
  int iStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int iStack_8;
  
  iStack_8 = 0xffffffff;
  puStack_c = &LAB_100058b4;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  CPrintPreviewState::CPrintPreviewState(aCStack_40);
  iStack_8 = 0;
  pvStack_58 = (void *)0x0;
  piStack_28 = (int *)0x0;
  if (ptr_1[3] != 0) {
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    ptr_1[3] = 0;
  }
  this = operator_new(0x18);
  iStack_8._0_1_ = 1;
  if (this == (CPrintPreviewState *)0x0) {
    iStack_1a0 = 0;
  }
  else {
    iStack_1a0 = CPrintPreviewState::CPrintPreviewState(this);
  }
  iStack_8 = (uint32_t)iStack_8._1_3_ << 8;
  ptr_1[3] = iStack_1a0;
  if (*ptr_1 != 0) {
    operator_delete((void *)*ptr_1);
    *ptr_1 = 0;
  }
  buf_ptr_1 = operator_new(0x34);
  *ptr_1 = (int)buf_ptr_1;
  ptr_1[7] = 0;
  iStack_90 = GetSystemMetrics(0);
  iStack_60 = GetSystemMetrics(1);
  thunk_FUN_10009e72((void *)ptr_1[3],iStack_90,iStack_60,0x18);
  thunk_FUN_1000432f(acStack_190,PTR_s_statwin__10012ac0,PTR_s_statscrn_tmp_10012ad0);
  pvStack_64 = CreateFileA(acStack_190,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  if (pvStack_64 == (HANDLE)0xffffffff) {
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    iStack_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  DStack_54 = 0x34;
  BVar2 = ReadFile(pvStack_64,(LPVOID)*ptr_1,0x34,&DStack_24,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    CloseHandle(pvStack_64);
    DeleteFileA(acStack_190);
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    iStack_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  if (DStack_24 != DStack_54) {
    assert(s_nBytesRead____nBytesToRead_10012ba8,s_G__NewMagic_tstvid_statclas_cpp_10012b88,0x223);
  }
  DStack_54 = 0x28;
  BVar2 = ReadFile(pvStack_64,auStack_8c,0x28,&DStack_24,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    if (DStack_24 != DStack_54) {
      assert(s_nBytesRead____nBytesToRead_10012be4,s_G__NewMagic_tstvid_statclas_cpp_10012bc4,0x22f)
      ;
    }
    if (uStack_7e < 9) {
      piStack_5c = operator_new(0x428);
      DStack_54 = 0x400;
      piStack_28 = piStack_5c + 0x1b8;
      if (ptr_1[2] == 0) {
        buf_ptr_1 = operator_new(0x428);
        ptr_1[2] = (int)buf_ptr_1;
      }
      if ((piStack_28 == (int *)0x0) || (ptr_1[2] == 0)) {
        assert(s_pclrs____pbibkgrnd_10012c20,s_G__NewMagic_tstvid_statclas_cpp_10012c00,0x23b);
      }
      BVar2 = ReadFile(pvStack_64,piStack_28,DStack_54,&DStack_24,(LPOVERLAPPED)0x0);
      if (BVar2 == 0) {
        CloseHandle(pvStack_64);
        DeleteFileA(acStack_190);
        if ((void *)ptr_1[3] != (void *)0x0) {
          thunk_FUN_10004250((void *)ptr_1[3],1);
        }
        operator_delete((void *)*ptr_1);
        iStack_8 = 0xffffffff;
        FUN_100058ab();
        FUN_100058be();
        return;
      }
      memcpy((void *)(ptr_1[2] + 0x6e0),piStack_28,DStack_24);
      if (DStack_24 != DStack_54) {
        assert(s_nBytesRead____nBytesToRead_10012c54,s_G__NewMagic_tstvid_statclas_cpp_10012c34,
               0x246);
      }
    }
    else {
      piStack_5c = operator_new(0x28);
      if (ptr_1[2] == 0) {
        buf_ptr_1 = operator_new(0x28);
        ptr_1[2] = (int)buf_ptr_1;
      }
    }
    memcpy(piStack_5c,auStack_8c,0x28);
    memcpy((void *)ptr_1[2],auStack_8c,0x28);
    pvStack_58 = operator_new(uStack_78);
    DStack_54 = uStack_78;
    if (pvStack_58 == (void *)0x0) {
      assert(s_pbits_10012c90,s_G__NewMagic_tstvid_statclas_cpp_10012c70,599);
    }
    BVar2 = ReadFile(pvStack_64,pvStack_58,DStack_54,&DStack_24,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      if (DStack_24 != DStack_54) {
        assert(s_nBytesRead____nBytesToRead_10012cb8,s_G__NewMagic_tstvid_statclas_cpp_10012c98,
               0x262);
      }
      thunk_FUN_1000a058(aCStack_40,piStack_5c,pvStack_58);
      thunk_FUN_1000acc2(aCStack_40,auStack_20);
      (**(code **)(*(int *)ptr_1[3] + 0x14))(auStack_50);
      if ((iStack_48 == iStack_18) && (iStack_14 == iStack_44)) {
        thunk_FUN_1000ad09(aCStack_40,(CFontDialog *)ptr_1[3],0,0,iStack_18,iStack_14,0,0);
        ptr_1[5] = 0;
        ptr_1[6] = 0;
      }
      else {
        if ((iStack_48 <= iStack_18) || (iStack_44 <= iStack_14)) {
          CloseHandle(pvStack_64);
          DeleteFileA(acStack_190);
          operator_delete(piStack_5c);
          operator_delete(pvStack_58);
          if ((void *)ptr_1[3] != (void *)0x0) {
            thunk_FUN_10004250((void *)ptr_1[3],1);
          }
          operator_delete((void *)*ptr_1);
          iStack_8 = 0xffffffff;
          FUN_100058ab();
          FUN_100058be();
          return;
        }
        ptr_1[5] = (iStack_48 - iStack_18) / 2;
        ptr_1[6] = (iStack_44 - iStack_14) / 2;
        thunk_FUN_1000ad09(aCStack_40,(CFontDialog *)ptr_1[3],ptr_1[5],ptr_1[6],iStack_18,iStack_14,
                           0,0);
      }
      operator_delete(piStack_5c);
      operator_delete(pvStack_58);
      CloseHandle(pvStack_64);
      iStack_8 = 0xffffffff;
      FUN_100058ab();
      FUN_100058be();
      return;
    }
    CloseHandle(pvStack_64);
    DeleteFileA(acStack_190);
    operator_delete(piStack_5c);
    operator_delete(pvStack_58);
    if ((void *)ptr_1[3] != (void *)0x0) {
      thunk_FUN_10004250((void *)ptr_1[3],1);
    }
    operator_delete((void *)*ptr_1);
    iStack_8 = 0xffffffff;
    FUN_100058ab();
    FUN_100058be();
    return;
  }
  CloseHandle(pvStack_64);
  DeleteFileA(acStack_190);
  if ((void *)ptr_1[3] != (void *)0x0) {
    thunk_FUN_10004250((void *)ptr_1[3],1);
  }
  operator_delete((void *)*ptr_1);
  iStack_8 = 0xffffffff;
  FUN_100058ab();
  FUN_100058be();
  return;
}


