/*
 * Decompiled function: FUN_100029cf
 * Entry Point: 100029cf
 * Size: 993 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100029cf(LPCSTR x,int *y,short *width,uint32_t height)

{
  int32_t uval_1;
  void *buf_ptr_2;
  int32_t *ptr_1;
  HWND pHVar3;
  int val_4;
  int32_t *unaff_FS_OFFSET;
  int32_t *local_3c;
  LPCSTR local_34;
  DWORD local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10002dae;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_1c = 0;
  local_2c = 0;
  local_20 = 0;
  local_24 = 0;
  for (local_28 = 0; (local_28 < 3 && (*(int *)(&DAT_10010868 + local_28 * 4) != 0));
      local_28 = local_28 + 1) {
  }
  if (local_28 == 3) {
    uval_1 = 3;
  }
  else {
    buf_ptr_2 = operator_new(0x70);
    *(void **)(&DAT_10010868 + local_28 * 4) = buf_ptr_2;
    local_18 = *(int **)(&DAT_10010868 + local_28 * 4);
    if (local_18 == (int *)0x0) {
      uval_1 = 3;
    }
    else {
      memset(local_18,0,0x70);
      ptr_1 = operator_new(0x128);
      local_8 = 0;
      if (ptr_1 == (int32_t *)0x0) {
        local_3c = (int32_t *)0x0;
      }
      else {
        local_3c = thunk_FUN_10001740(ptr_1);
      }
      local_8 = 0xffffffff;
      *(int32_t **)(*(int *)(&DAT_10010868 + local_28 * 4) + 8) = local_3c;
      local_14 = *(int *)(*(int *)(&DAT_10010868 + local_28 * 4) + 8);
      if (local_14 == 0) {
        operator_delete(*(void **)(&DAT_10010868 + local_28 * 4));
        *(int32_t *)(&DAT_10010868 + local_28 * 4) = 0;
        uval_1 = 3;
      }
      else {
        if (height == 0) {
          local_1c = -0x80000000;
          local_2c = -0x80000000;
          if (width == (short *)0x0) {
            local_20 = 0;
            local_18[0x16] = 0;
            local_24 = 0;
            local_18[0x16] = 0;
          }
          else {
            local_20 = (int)*width;
            local_18[0x16] = local_20;
            local_24 = (int)width[1];
            local_18[0x17] = local_24;
          }
        }
        else {
          local_1c = GetSystemMetrics(0);
          local_2c = GetSystemMetrics(1);
          local_20 = 0;
          local_18[0x16] = 0;
          local_24 = 0;
          local_18[0x17] = 0;
        }
        if ((height & 4) == 0) {
          DAT_1001053c = (HWND)thunk_FUN_100053fa();
          local_18[6] = (int)DAT_1001053c;
          pHVar3 = CreateWindowExA(0,PTR_s_VIDWINCLASS_10010534,(LPCSTR)0x0,0x90000000,local_20,
                                   local_24,local_1c,local_2c,DAT_1001053c,(HMENU)0x0,DAT_1001054c,
                                   (LPVOID)0x0);
          local_18[4] = (int)pHVar3;
          if (local_18[4] == 0) {
            local_30 = GetLastError();
            FormatMessageA(0x1100,(LPCVOID)0x0,local_30,0x400,(LPSTR)&local_34,0,(va_list *)0x0);
            MessageBoxA((HWND)0x0,local_34,s_GetLastError_10010564,0x40);
            LocalFree(local_34);
          }
          local_18[5] = 1;
        }
        else if ((*(int *)(&DAT_10010868 + *y * 4) != 0) &&
                (*(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10) != 0)) {
          local_18[4] = *(int *)(*(int *)(&DAT_10010868 + *y * 4) + 0x10);
          local_18[5] = 0;
        }
        *local_18 = local_28;
        if ((height & 4) == 0) {
          SetFocus(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          SetForegroundWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          ShowWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10),1);
        }
        val_4 = thunk_FUN_10005a5b(local_18,x);
        if (val_4 == 0) {
          *y = local_28;
          uval_1 = 0;
        }
        else {
          if ((height & 4) == 0) {
            DestroyWindow(*(HWND *)(*(int *)(&DAT_10010868 + local_28 * 4) + 0x10));
          }
          operator_delete(*(void **)(&DAT_10010868 + local_28 * 4));
          *(int32_t *)(&DAT_10010868 + local_28 * 4) = 0;
          uval_1 = 1;
        }
      }
    }
  }
  *unaff_FS_OFFSET = local_10;
  return uval_1;
}


