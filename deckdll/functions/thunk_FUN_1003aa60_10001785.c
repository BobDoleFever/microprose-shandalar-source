/*
 * Decompiled function: thunk_FUN_1003aa60
 * Entry Point: 10001785
 * Size: 5 bytes
 */
#include "deckdll.h"


uint8_t * thunk_FUN_1003aa60(int arg_1,int arg_2,int arg_3)

{
  int val_1;
  DWORD dwMaximumSizeLow;
  int32_t uval_2;
  HANDLE buf_ptr_3;
  HDC pHVar4;
  HBITMAP pHVar5;
  uint8_t *puVar6;
  uint32_t uval_7;
  
  *(int *)(PTR_DAT_1004bae8 + 0x20) = arg_1;
  *(int *)(PTR_DAT_1004bae8 + 0x24) = arg_2;
  *(int *)(PTR_DAT_1004bae8 + 0x28) = arg_3;
  val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
  uval_7 = val_1 >> 0x1f;
  if (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) == uval_7) {
    *(int32_t *)(PTR_DAT_1004bae8 + 0x2c) = 0;
  }
  else {
    val_1 = arg_3 * arg_1 + (arg_3 * arg_1 >> 0x1f & 7U);
    uval_7 = val_1 >> 0x1f;
    *(uint32_t *)(PTR_DAT_1004bae8 + 0x2c) = 4 - (((val_1 >> 3 ^ uval_7) - uval_7 & 3 ^ uval_7) - uval_7);
  }
  val_1 = (*(int *)(PTR_DAT_1004bae8 + 0x2c) + arg_1) * arg_3 * arg_2;
  dwMaximumSizeLow = ((int)(val_1 + (val_1 >> 0x1f & 7U)) >> 3) + 0x10;
  *(DWORD *)(PTR_DAT_1004bae8 + 0x1c) = dwMaximumSizeLow;
  uval_2 = thunk_FUN_10003410(arg_1,arg_2,arg_3);
  *(int32_t *)(PTR_DAT_1004bae8 + 0x10) = uval_2;
  if (*(int *)(PTR_DAT_1004bae8 + 0x10) == 0) {
    puVar6 = (uint8_t *)0x0;
  }
  else {
    buf_ptr_3 = CreateFileMappingA((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,0x8000004,0,
                                dwMaximumSizeLow,(LPCSTR)0x0);
    *(HANDLE *)PTR_DAT_1004bae8 = buf_ptr_3;
    if (*(int *)PTR_DAT_1004bae8 == 0) {
      thunk_FUN_100034b0(*(void **)(PTR_DAT_1004bae8 + 0x10));
      puVar6 = (uint8_t *)0x0;
    }
    else {
      pHVar4 = GetDC((HWND)0x0);
      *(HDC *)(PTR_DAT_1004bae8 + 4) = pHVar4;
      thunk_FUN_10031425(*(HDC *)(PTR_DAT_1004bae8 + 4));
      pHVar5 = CreateDIBSection(*(HDC *)(PTR_DAT_1004bae8 + 4),
                                *(BITMAPINFO **)(PTR_DAT_1004bae8 + 0x10),(uint32_t)(arg_3 == 8),
                                (void **)(PTR_DAT_1004bae8 + 0x18),*(HANDLE *)PTR_DAT_1004bae8,0);
      *(HBITMAP *)(PTR_DAT_1004bae8 + 8) = pHVar5;
      ReleaseDC((HWND)0x0,*(HDC *)(PTR_DAT_1004bae8 + 4));
      if (*(int *)(PTR_DAT_1004bae8 + 8) == 0) {
        thunk_FUN_100034b0(*(void **)(PTR_DAT_1004bae8 + 0x10));
        CloseHandle(*(HANDLE *)PTR_DAT_1004bae8);
        puVar6 = (uint8_t *)0x0;
      }
      else {
        thunk_FUN_100034b0(*(void **)(PTR_DAT_1004bae8 + 0x10));
        puVar6 = PTR_DAT_1004bae8;
      }
    }
  }
  return puVar6;
}


