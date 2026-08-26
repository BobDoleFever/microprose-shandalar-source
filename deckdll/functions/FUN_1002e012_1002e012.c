/*
 * Decompiled function: FUN_1002e012
 * Entry Point: 1002e012
 * Size: 596 bytes
 */
#include "deckdll.h"


int32_t FUN_1002e012(HWND hwnd,LONG arg_2,LONG arg_3)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  POINT pt_03;
  POINT pt_04;
  POINT pt_05;
  POINT pt_06;
  POINT pt_07;
  POINT pt_08;
  BOOL BVar1;
  int32_t uval_2;
  tagRECT local_24;
  tagRECT local_14;
  
  GetClientRect(hwnd,&local_24);
  thunk_FUN_1002c0c7(&local_24.left,0x13,&local_14);
  thunk_FUN_1002c0c7(&local_24.left,0x15,&local_14);
  pt.y = arg_3;
  pt.x = arg_2;
  BVar1 = PtInRect(&local_14,pt);
  uval_2 = DAT_1013f1d0;
  if (BVar1 == 0) {
    thunk_FUN_1002c0c7(&local_24.left,0x16,&local_14);
    pt_00.y = arg_3;
    pt_00.x = arg_2;
    BVar1 = PtInRect(&local_14,pt_00);
    uval_2 = DAT_1013f1e0;
    if (BVar1 == 0) {
      thunk_FUN_1002c0c7(&local_24.left,0x17,&local_14);
      pt_01.y = arg_3;
      pt_01.x = arg_2;
      BVar1 = PtInRect(&local_14,pt_01);
      uval_2 = DAT_1013f1c4;
      if (BVar1 == 0) {
        thunk_FUN_1002c0c7(&local_24.left,0x18,&local_14);
        pt_02.y = arg_3;
        pt_02.x = arg_2;
        BVar1 = PtInRect(&local_14,pt_02);
        uval_2 = DAT_1013f1dc;
        if (BVar1 == 0) {
          thunk_FUN_1002c0c7(&local_24.left,0x1d,&local_14);
          pt_03.y = arg_3;
          pt_03.x = arg_2;
          BVar1 = PtInRect(&local_14,pt_03);
          uval_2 = DAT_1013f1e4;
          if (BVar1 == 0) {
            thunk_FUN_1002c0c7(&local_24.left,0x1e,&local_14);
            pt_04.y = arg_3;
            pt_04.x = arg_2;
            BVar1 = PtInRect(&local_14,pt_04);
            uval_2 = DAT_1013f1d8;
            if (BVar1 == 0) {
              thunk_FUN_1002c0c7(&local_24.left,0x1f,&local_14);
              pt_05.y = arg_3;
              pt_05.x = arg_2;
              BVar1 = PtInRect(&local_14,pt_05);
              uval_2 = DAT_1013f1e8;
              if (BVar1 == 0) {
                thunk_FUN_1002c0c7(&local_24.left,0x20,&local_14);
                pt_06.y = arg_3;
                pt_06.x = arg_2;
                BVar1 = PtInRect(&local_14,pt_06);
                uval_2 = DAT_1013f1d4;
                if (BVar1 == 0) {
                  thunk_FUN_1002c0c7(&local_24.left,0x21,&local_14);
                  pt_07.y = arg_3;
                  pt_07.x = arg_2;
                  BVar1 = PtInRect(&local_14,pt_07);
                  uval_2 = DAT_1013f1ec;
                  if (BVar1 == 0) {
                    thunk_FUN_1002c0c7(&local_24.left,0x22,&local_14);
                    pt_08.y = arg_3;
                    pt_08.x = arg_2;
                    BVar1 = PtInRect(&local_14,pt_08);
                    uval_2 = DAT_1013f1ac;
                    if (BVar1 != 0) {
                      uval_2 = DAT_1013f1c8;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uval_2;
}


