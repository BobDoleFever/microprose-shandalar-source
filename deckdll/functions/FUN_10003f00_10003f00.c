/*
 * Decompiled function: FUN_10003f00
 * Entry Point: 10003f00
 * Size: 291 bytes
 */
#include "deckdll.h"


int FUN_10003f00(HWND hwnd,int arg_2,int arg_3,int arg_4,DWORD arg_5,DWORD arg_6)

{
  uint8_t uval_1;
  int32_t *lpvBits;
  int val_2;
  BITMAPINFO *lpbmi;
  HDC hdc;
  uint32_t uval_3;
  uint32_t uval_4;
  int val_5;
  int32_t *puVar6;
  int32_t *puVar7;
  int val_8;
  int iVar9;
  int *piVar10;
  int iVar11;
  DWORD DVar12;
  DWORD local_4;
  
  val_8 = 0;
  iVar11 = 0;
  uval_4 = arg_6 * arg_5 * 3;
  lpvBits = malloc(arg_6 * arg_5 * 3 + 8);
  puVar7 = lpvBits;
  for (uval_3 = uval_4 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  for (uval_4 = uval_4 & 3; uval_4 != 0; uval_4 = uval_4 - 1) {
    *(uint8_t *)puVar7 = 0;
    puVar7 = (int32_t *)((int)puVar7 + 1);
  }
  if (0 < (int)arg_6) {
    val_5 = 0;
    local_4 = arg_6;
    puVar7 = lpvBits;
    do {
      if (0 < (int)arg_5) {
        piVar10 = (int *)(arg_2 + val_5 * 4);
        puVar6 = puVar7;
        iVar9 = val_8;
        DVar12 = arg_5;
        do {
          val_2 = *piVar10 >> 2;
          val_8 = val_2;
          if ((iVar9 <= val_2) && (val_8 = iVar9, iVar11 < val_2)) {
            iVar11 = val_2;
          }
          if (val_2 < 1) {
            val_2 = 0;
          }
          if (0xfe < val_2) {
            val_2 = 0xff;
          }
          uval_1 = (uint8_t)val_2;
          *(uint8_t *)((int)puVar6 + 2) = uval_1;
          piVar10 = piVar10 + 1;
          *(uint8_t *)((int)puVar6 + 1) = uval_1;
          puVar7 = (int32_t *)((int)puVar6 + 3);
          DVar12 = DVar12 - 1;
          *(uint8_t *)puVar6 = uval_1;
          puVar6 = puVar7;
          iVar9 = val_8;
        } while (DVar12 != 0);
      }
      val_5 = val_5 + arg_5;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  lpbmi = (BITMAPINFO *)thunk_FUN_10003410(arg_5,arg_6,0x18);
  hdc = GetDC(hwnd);
  val_8 = SetDIBitsToDevice(hdc,arg_3,arg_4,arg_5,arg_6,0,0,0,arg_6,lpvBits,lpbmi,0);
  ReleaseDC(hwnd,hdc);
  free(lpbmi);
  free(lpvBits);
  return val_8;
}


