/*
 * Decompiled function: Ai_Subsystem_004b35b4
 * Entry Point: 004b35b4
 * Size: 451 bytes
 */
#include "magic.h"


void Ai_Subsystem_004b35b4(LPRECT arg_1,HWND hwnd,int arg_3)

{
  HWND pHVar1;
  tagRECT *ptVar2;
  tagRECT local_24;
  tagRECT local_14;
  
  if (arg_1 != (LPRECT)0x0) {
    if (arg_3 == 5) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41c);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x422);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 2) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41e);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x423);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 1) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x420);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x424);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 4) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41f);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x425);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 3) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x41d);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x426);
      GetWindowRect(pHVar1,ptVar2);
    }
    if (arg_3 == 0) {
      ptVar2 = &local_24;
      pHVar1 = GetDlgItem(hwnd,0x421);
      GetWindowRect(pHVar1,ptVar2);
      ptVar2 = &local_14;
      pHVar1 = GetDlgItem(hwnd,0x427);
      GetWindowRect(pHVar1,ptVar2);
    }
    UnionRect(arg_1,&local_24,&local_14);
    InflateRect(arg_1,0,10);
    MapWindowPoints((HWND)0x0,hwnd,(LPPOINT)arg_1,2);
  }
  return;
}


