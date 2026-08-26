/*
 * Decompiled function: LoadAVI
 * Entry Point: 100012d0
 * Size: 5 bytes
 */
#include "magvid.h"


int32_t __cdecl LoadAVI(LPCSTR x,int *y,short *width,uint32_t height)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int32_t *ptr_1;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t *puStack_3c;
  LPCSTR pCStack_34;
  DWORD DStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int *piStack_18;
  int iStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
                    /* 0x12d0  3  LoadAVI */
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10002dae;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  iStack_1c = 0;
  iStack_2c = 0;
  iStack_20 = 0;
  iStack_24 = 0;
  for (iStack_28 = 0; (iStack_28 < 3 && (*(int *)(&DAT_10010868 + iStack_28 * 4) != 0));
      iStack_28 = iStack_28 + 1) {
  }
  if (iStack_28 == 3) {
    uval_1 = 3;
  }
  else {
    buf_ptr_2 = operator_new(0x70);
    *(void **)(&DAT_10010868 + iStack_28 * 4) = buf_ptr_2;
    piStack_18 = *(int **)(&DAT_10010868 + iStack_28 * 4);
    if (piStack_18 == (int *)0x0) {
      uval_1 = 3;
    }
    else {
      memset(piStack_18,0,0x70);
      ptr_1 = operator_new(0x128);
      uStack_8 = 0;
      if (ptr_1 == (int32_t *)0x0) {
        puStack_3c = (int32_t *)0x0;
      }
      else {
        puStack_3c = thunk_FUN_10001740(ptr_1);
      }
      uStack_8 = 0xffffffff;
      *(int32_t **)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 8) = puStack_3c;
      iStack_14 = *(int *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 8);
      if (iStack_14 == 0) {
        operator_delete(*(void **)(&DAT_10010868 + iStack_28 * 4));
        *(int32_t *)(&DAT_10010868 + iStack_28 * 4) = 0;
        uval_1 = 3;
      }
      else {
        if (height == 0) {
          iStack_1c = -0x80000000;
          iStack_2c = -0x80000000;
          if (width == (short *)0x0) {
            iStack_20 = 0;
            piStack_18[0x16] = 0;
            iStack_24 = 0;
            piStack_18[0x16] = 0;
          }
          else {
            iStack_20 = (int)*width;
            piStack_18[0x16] = iStack_20;
            iStack_24 = (int)width[1];
            piStack_18[0x17] = iStack_24;
          }
        }
        else {
          iStack_1c = GetSystemMetrics(0);
          iStack_2c = GetSystemMetrics(1);
          iStack_20 = 0;
          piStack_18[0x16] = 0;
          iStack_24 = 0;
          piStack_18[0x17] = 0;
        }
        if ((height & 4) == 0) {
          DAT_1001053c = (HWND)thunk_FUN_100053fa();
          piStack_18[6] = (int)DAT_1001053c;
          pHVar3 = CreateWindowExA(0,PTR_s_VIDWINCLASS_10010534,(LPCSTR)0x0,0x90000000,iStack_20,
                                   iStack_24,iStack_1c,iStack_2c,DAT_1001053c,(HMENU)0x0,
                                   DAT_1001054c,(LPVOID)0x0);
          piStack_18[4] = (int)pHVar3;
          if (piStack_18[4] == 0) {
            DStack_30 = GetLastError();
            FormatMessageA(0x1100,(LPCVOID)0x0,DStack_30,0x400,(LPSTR)&pCStack_34,0,(va_list *)0x0);
            MessageBoxA((HWND)0x0,pCStack_34,s_GetLastError_10010564,0x40);
            LocalFree(pCStack_34);
          }
          piStack_18[5] = 1;
        }
        else if ((*(int *)(&DAT_10010868 + *y * 4) != 0) &&
                (*(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10) != 0)) {
          piStack_18[4] = *(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10);
          piStack_18[5] = 0;
        }
        *piStack_18 = iStack_28;
        if ((height & 4) == 0) {
          SetFocus(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          SetForegroundWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          ShowWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10),1);
        }
        val_4 = thunk_FUN_10005a5b(piStack_18,x);
        if (val_4 == 0) {
          *y = iStack_28;
          uval_1 = 0;
        }
        else {
          if ((height & 4) == 0) {
            DestroyWindow(*(HWND *)(*(int *)(&DAT_10010868 + iStack_28 * 4) + 0x10));
          }
          operator_delete(*(void **)(&DAT_10010868 + iStack_28 * 4));
          *(int32_t *)(&DAT_10010868 + iStack_28 * 4) = 0;
          uval_1 = 1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = uStack_10;
  return uval_1;
}


