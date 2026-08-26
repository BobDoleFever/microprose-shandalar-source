/*
 * Decompiled function: thunk_FUN_10010a1f
 * Entry Point: 10001163
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t thunk_FUN_10010a1f(int32_t arg_1)

{
  char *char_ptr_1;
  HWND pHVar2;
  HDC hdc;
  int val_3;
  int val_4;
  char acStack_110 [264];
  int iStack_8;
  
  DAT_101cf334 = arg_1;
  thunk_FUN_100129f0();
  DAT_101cfa68 = (int)DAT_101cf540;
  DAT_1016a618 = 0;
  DAT_10176478 = 0;
  DAT_101cdea4 = 0;
  DAT_10175ee8 = 0;
  _DAT_10162904 = 0;
  GetModuleFileNameA((HMODULE)0x0,&DAT_10158770,0x105);
  char_ptr_1 = strrchr(&DAT_10158770,0x5c);
  *char_ptr_1 = '\0';
  strcpy(&DAT_101cfa70,&DAT_10158770);
  strcpy(&DAT_101cf810,&DAT_10158770);
  strcat(&DAT_101cf810,s__PlayDeck_100426a0);
  strcpy(&DAT_10158890,&DAT_10158770);
  strcat(&DAT_10158890,s__CARDART_100426ac);
  strcpy(&DAT_10176870,&DAT_10158770);
  strcat(&DAT_10176870,s__DUELART_100426b8);
  strcpy(&DAT_10176360,&DAT_10158770);
  strcat(&DAT_10176360,s__DBART_100426c4);
  strcpy(&DAT_101cf960,&DAT_10176870);
  strcat(&DAT_101cf960,s__Duel_dat_100426cc);
  DAT_101628dc = 1;
  for (iStack_8 = 0; iStack_8 < 2000; iStack_8 = iStack_8 + 1) {
    *(int32_t *)(&DAT_10162910 + iStack_8 * 0x10) = 0;
  }
  for (iStack_8 = 0; iStack_8 < 0x14; iStack_8 = iStack_8 + 1) {
    *(int32_t *)(&DAT_101cf5f0 + iStack_8 * 0x18) = 0;
  }
  DAT_10158728 = 0;
  strcpy(acStack_110,&DAT_10158770);
  strcat(acStack_110,s__CARDS_DAT_100426d8);
  DAT_10175ee0 = thunk_FUN_100298f0(acStack_110);
  if (DAT_10175ee0 == 0) {
    thunk_FUN_100129a2(s_WinMain__Couldn_t_find_CARDS_DAT_100426e4,(HWND)0x0);
  }
  pHVar2 = GetDesktopWindow();
  hdc = GetDC(pHVar2);
  _DAT_101628c4 = GetDeviceCaps(hdc,0x26);
  _DAT_101628c4 = _DAT_101628c4 & 0x100;
  val_3 = GetDeviceCaps(hdc,0xc);
  val_4 = GetDeviceCaps(hdc,0xe);
  DAT_101cf94c = val_3 * val_4;
  pHVar2 = GetDesktopWindow();
  ReleaseDC(pHVar2,hdc);
  DAT_10041580 = 3;
  Ordinal_17();
  val_3 = thunk_FUN_1001138a();
  if (val_3 == 0) {
    thunk_FUN_100129a2(s_WinMain__Couldn_t_register_the_c_10042708,(HWND)0x0);
  }
  return 0;
}


