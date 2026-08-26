/*
 * Decompiled function: thunk_FUN_1001f340
 * Entry Point: 1000102d
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001f340(HDC hdc,int32_t *arg_2,uint32_t arg_3)

{
  int arg_5;
  uint8_t auStack_dc [4];
  int iStack_d8;
  int iStack_d4;
  int iStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  int iStack_b4;
  int32_t uStack_b0;
  uint32_t auStack_ac [20];
  int aiStack_5c [17];
  tagRECT tStack_18;
  int iStack_8;
  
  auStack_ac[0] = 0x20;
  auStack_ac[1] = 0x400;
  auStack_ac[2] = 0x40;
  auStack_ac[3] = 0x80;
  auStack_ac[4] = 0x100;
  auStack_ac[5] = 0x200;
  auStack_ac[6] = 1;
  auStack_ac[7] = 2;
  auStack_ac[8] = 4;
  auStack_ac[9] = 8;
  auStack_ac[10] = 0x10;
  auStack_ac[0xb] = 0x800;
  auStack_ac[0xc] = 0x1000;
  auStack_ac[0xd] = 0x2000;
  auStack_ac[0xe] = 0x4000;
  auStack_ac[0xf] = 0x8000;
  auStack_ac[0x10] = 0x10000;
  aiStack_5c[0] = 0xb;
  aiStack_5c[1] = 0x10;
  aiStack_5c[2] = 0xd;
  aiStack_5c[3] = 0xc;
  aiStack_5c[4] = 0xe;
  aiStack_5c[5] = 0xf;
  aiStack_5c[6] = 3;
  aiStack_5c[7] = 2;
  aiStack_5c[8] = 0;
  aiStack_5c[9] = 1;
  aiStack_5c[10] = 4;
  aiStack_5c[0xb] = 8;
  aiStack_5c[0xc] = 7;
  aiStack_5c[0xd] = 5;
  aiStack_5c[0xe] = 6;
  aiStack_5c[0xf] = 9;
  aiStack_5c[0x10] = 10;
  auStack_ac[0x11] = 0x11;
  if (((hdc != (HDC)0x0) && (arg_2 != (int32_t *)0x0)) && (arg_3 != 0)) {
    iStack_c0 = SaveDC(hdc);
    if (DAT_1013e5d0 != (HANDLE)0x0) {
      GetObjectA(DAT_1013e5d0,0x18,auStack_dc);
      iStack_b8 = iStack_d8;
      arg_5 = iStack_d4 / (int)(auStack_ac[0x11] + 1);
      iStack_8 = 0;
      iStack_b4 = iStack_d4 - arg_5;
      uStack_b0 = *arg_2;
      iStack_c4 = arg_2[3] - arg_5;
      for (iStack_bc = 0; iStack_bc < (int)auStack_ac[0x11]; iStack_bc = iStack_bc + 1) {
        if ((arg_3 & auStack_ac[iStack_bc]) != 0) {
          thunk_FUN_1001f5d7(&tStack_18,auStack_ac[iStack_bc],arg_2,arg_3);
          auStack_ac[0x12] = 0;
          auStack_ac[0x13] = aiStack_5c[iStack_bc] * arg_5;
          thunk_FUN_1003197a(hdc,&tStack_18.left,DAT_1013e5d0,iStack_b8,arg_5,0,auStack_ac[0x13],
                             iStack_8,iStack_b4);
        }
      }
    }
    RestoreDC(hdc,iStack_c0);
  }
  return;
}


