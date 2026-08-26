/*
 * Decompiled function: thunk_FUN_1001c8d1
 * Entry Point: 100013bb
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_1001c8d1(HDC hdc,char arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  uint8_t auStack_3c [4];
  int iStack_38;
  int iStack_34;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  tagRECT tStack_18;
  int iStack_8;
  
  if (((hdc != (HDC)0x0) && (-0x13 < arg_2)) && (arg_2 < '\0')) {
    GetObjectA(DAT_1013e61c,0x18,auStack_3c);
    iStack_20 = iStack_34;
    iStack_24 = iStack_34;
    iStack_8 = iStack_38 - iStack_34;
    if (arg_2 == -0x10) {
      iStack_1c = 0;
    }
    else if (arg_2 == -0xf) {
      iStack_1c = iStack_34;
    }
    else if (arg_2 == -0xe) {
      iStack_1c = iStack_34 * 2;
    }
    else if (arg_2 == -0xd) {
      iStack_1c = iStack_34 * 3;
    }
    else if (arg_2 == -0xc) {
      iStack_1c = iStack_34 << 2;
    }
    else if (arg_2 == -0xb) {
      iStack_1c = iStack_34 * 5;
    }
    else if (arg_2 == -10) {
      iStack_1c = iStack_34 * 6;
    }
    else if (arg_2 == -9) {
      iStack_1c = iStack_34 * 7;
    }
    else if (arg_2 == -8) {
      iStack_1c = iStack_34 << 3;
    }
    else if (arg_2 == -7) {
      iStack_1c = iStack_34 * 9;
    }
    else if (arg_2 == -6) {
      iStack_1c = iStack_34 * 10;
    }
    else if (arg_2 == -0x11) {
      iStack_1c = iStack_34 * 0xb;
    }
    else if (arg_2 == -5) {
      iStack_1c = iStack_34 * 0xc;
    }
    else if (arg_2 == -4) {
      iStack_1c = iStack_34 * 0xd;
    }
    else if (arg_2 == -3) {
      iStack_1c = iStack_34 * 0xe;
    }
    else if (arg_2 == -2) {
      iStack_1c = iStack_34 * 0xf;
    }
    else if (arg_2 == -1) {
      iStack_1c = iStack_34 << 4;
    }
    else if (arg_2 == -0x12) {
      iStack_1c = iStack_34 * 0x11;
    }
    SetRect(&tStack_18,arg_3,arg_4,arg_5 + arg_3,arg_6 + arg_4);
    thunk_FUN_1003197a(hdc,&tStack_18.left,DAT_1013e61c,iStack_20,iStack_24,iStack_1c,0,iStack_8,0);
  }
  return;
}


