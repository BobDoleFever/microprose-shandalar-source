/*
 * Decompiled function: thunk_FUN_1002c4d3
 * Entry Point: 1000132f
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1002c4d3(HDC hdc,int *y,int32_t arg_3,int height)

{
  uint8_t auStack_2c [4];
  int iStack_28;
  int iStack_24;
  tagRECT tStack_14;
  
  thunk_FUN_1002c220(hdc,y,&tStack_14,height);
  InflateRect(&tStack_14,-1,-1);
  GetObjectA(DAT_1016e4a4,0x18,auStack_2c);
  switch(arg_3) {
  case 10:
    SelectObject(DAT_101625e8,DAT_101cde90);
    break;
  case 0xb:
    SelectObject(DAT_101625e8,DAT_10176aa4);
    break;
  case 0xc:
    SelectObject(DAT_101625e8,DAT_101cde98);
    break;
  default:
    SelectObject(DAT_101625e8,DAT_10175540);
    break;
  case 0xe:
    SelectObject(DAT_101625e8,DAT_1016e4a4);
    break;
  case 0xf:
    SelectObject(DAT_101625e8,DAT_101cdeb8);
    break;
  case 0x10:
    SelectObject(DAT_101625e8,DAT_10162618);
    break;
  case 0x11:
    SelectObject(DAT_101625e8,DAT_10175540);
    break;
  case 0x12:
    SelectObject(DAT_101625e8,DAT_101625e4);
    break;
  case 0x15:
    SelectObject(DAT_101625e8,DAT_101cf92c);
    break;
  case 0x16:
    SelectObject(DAT_101625e8,DAT_101625f0);
    break;
  case 0x17:
    SelectObject(DAT_101625e8,DAT_101628e0);
    break;
  case 0x18:
    SelectObject(DAT_101625e8,DAT_10176474);
    break;
  case 0x19:
    SelectObject(DAT_101625e8,DAT_10162620);
    break;
  case 0x1a:
    SelectObject(DAT_101625e8,DAT_101628d0);
    break;
  case 0x1b:
    SelectObject(DAT_101625e8,DAT_10158880);
    break;
  case 0x1d:
    SelectObject(DAT_101625e8,DAT_10176864);
    break;
  case 0x1e:
    SelectObject(DAT_101625e8,DAT_101cde9c);
    break;
  case 0x1f:
    SelectObject(DAT_101625e8,DAT_10176854);
    break;
  case 0x20:
    SelectObject(DAT_101625e8,DAT_1015887c);
    break;
  case 0x21:
    SelectObject(DAT_101625e8,DAT_10158878);
    break;
  case 0x22:
    SelectObject(DAT_101625e8,DAT_10176980);
  }
  StretchBlt(hdc,tStack_14.left,tStack_14.top,tStack_14.right - tStack_14.left,
             tStack_14.bottom - tStack_14.top,DAT_101625e8,0,0,iStack_28,iStack_24,0xcc0020);
  SelectObject(DAT_101625e8,DAT_101cf924);
  return;
}


