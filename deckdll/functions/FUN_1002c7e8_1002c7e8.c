/*
 * Decompiled function: FUN_1002c7e8
 * Entry Point: 1002c7e8
 * Size: 1866 bytes
 */
#include "deckdll.h"


void FUN_1002c7e8(HDC hdc,int32_t arg_2,int32_t arg_3,int arg_4,int arg_5)

{
  HDC hdc_00;
  uint8_t local_2c [4];
  int local_28;
  int local_24;
  tagRECT local_14;
  
  hdc_00 = CreateCompatibleDC(hdc);
  thunk_FUN_10031425(hdc_00);
  SelectObject(hdc_00,DAT_10162908);
  GetObjectA(DAT_10162908,0x18,local_2c);
  StretchBlt(hdc,0,0,arg_4,arg_5,hdc_00,0,0,local_28,local_24,0xcc0020);
  DeleteDC(hdc_00);
  thunk_FUN_1002c0c7(&arg_2,0xe,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0xe,(int)DAT_101cf7d0 & 2);
  thunk_FUN_1002c0c7(&arg_2,0x11,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x11,(int)DAT_101cf7d0 & 8);
  thunk_FUN_1002c0c7(&arg_2,0xf,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0xf,(int)DAT_101cf7d0 & 0x20);
  thunk_FUN_1002c0c7(&arg_2,0x12,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x12,(int)DAT_101cf7d0 & 4);
  thunk_FUN_1002c0c7(&arg_2,0x10,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x10,(int)DAT_101cf7d0 & 0x10);
  if (DAT_10158748 != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x13,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x13,(int)DAT_101cf7d0 & 0x40);
  }
  thunk_FUN_1002c0c7(&arg_2,0x15,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x15,DAT_101cf7d4 & 1);
  thunk_FUN_1002c0c7(&arg_2,0x16,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x16,DAT_101cf7d4 & 0x10);
  thunk_FUN_1002c0c7(&arg_2,0x17,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x17,DAT_101cf7d4 & 0x80);
  thunk_FUN_1002c0c7(&arg_2,0x18,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x18,DAT_101cf7d4 & 0x1000);
  thunk_FUN_1002c0c7(&arg_2,0x19,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x19,DAT_101cf7d4 & 0x80000);
  thunk_FUN_1002c0c7(&arg_2,0x1a,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x1a,DAT_101cf7d4 & 0x100000);
  thunk_FUN_1002c0c7(&arg_2,0x1b,&local_14);
  thunk_FUN_1002c4d3(hdc,&local_14.left,0x1b,DAT_101cf7d4 & 0x200000);
  if ((DAT_10158744 & 1) != 0) {
    thunk_FUN_1002c0c7(&arg_2,10,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,10,(int)DAT_101cf7d2 & 2);
  }
  if ((DAT_10158744 & 2) != 0) {
    thunk_FUN_1002c0c7(&arg_2,0xb,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0xb,(int)DAT_101cf7d2 & 4);
  }
  if ((DAT_10158744 & 4) != 0) {
    thunk_FUN_1002c0c7(&arg_2,1,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,1,(int)DAT_101cf7d2 & 8);
  }
  if ((DAT_10158744 & 8) != 0) {
    thunk_FUN_1002c0c7(&arg_2,2,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,2,(int)DAT_101cf7d2 & 0x10);
  }
  if ((DAT_10158744 & 0x10) != 0) {
    thunk_FUN_1002c0c7(&arg_2,3,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,3,(int)DAT_101cf7d2 & 0x20);
  }
  if ((DAT_10158744 & 0x20) != 0) {
    thunk_FUN_1002c0c7(&arg_2,4,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,4,(int)DAT_101cf7d2 & 0x40);
  }
  if ((DAT_10158744 & 0x40) != 0) {
    thunk_FUN_1002c0c7(&arg_2,5,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,5,(int)DAT_101cf7d2 & 0x80);
  }
  if ((DAT_10158744 & 0x80) != 0) {
    thunk_FUN_1002c0c7(&arg_2,6,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,6,(int)DAT_101cf7d2 & 0x100);
  }
  if ((DAT_10158744 & 0x100) != 0) {
    thunk_FUN_1002c0c7(&arg_2,7,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,7,(int)DAT_101cf7d2 & 0x200);
  }
  if ((DAT_10158744 & 0x200) != 0) {
    thunk_FUN_1002c0c7(&arg_2,0xc,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0xc,(int)DAT_101cf7d2 & 0x400);
  }
  if ((DAT_10158744 & 0x400) != 0) {
    thunk_FUN_1002c0c7(&arg_2,8,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,8,(int)DAT_101cf7d2 & 0x800);
  }
  if ((DAT_10158744 & 0x800) != 0) {
    thunk_FUN_1002c0c7(&arg_2,9,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,9,(int)DAT_101cf7d2 & 0x1000);
  }
  if (DAT_1015874c != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x1d,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x1d,(int)DAT_101cf7f4 & 1);
  }
  if (DAT_10158750 != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x1e,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x1e,(int)DAT_101cf7f8 & 1);
  }
  if (DAT_10158754 != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x1f,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x1f,(int)DAT_101cf7fc & 1);
  }
  if (DAT_10158758 != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x20,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x20,(int)DAT_101cf800 & 1);
  }
  if (DAT_1015875c != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x21,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x21,(int)DAT_101cf802 & 1);
  }
  if (DAT_10158760 != 0) {
    thunk_FUN_1002c0c7(&arg_2,0x22,&local_14);
    thunk_FUN_1002c4d3(hdc,&local_14.left,0x22,(int)DAT_101cf803 & 1);
  }
  return;
}


