/*
 * Decompiled function: FUN_0049fac1
 * Entry Point: 0049fac1
 * Size: 334 bytes
 */
#include "duel.h"


void FUN_0049fac1(void)

{
  if (DAT_005dcd1c != (HMENU)0x0) {
    DestroyMenu(DAT_005dcd1c);
  }
  DAT_005dcd1c = (HMENU)0x0;
  if (DAT_005dcd54 != (HANDLE)0x0) {
    FUN_00471395(DAT_005dcd54);
  }
  if (DAT_005dcd4c != (HANDLE)0x0) {
    FUN_00471395(DAT_005dcd4c);
  }
  if (DAT_005dcd48 != (HANDLE)0x0) {
    FUN_00471395(DAT_005dcd48);
  }
  if (DAT_005dcd50 != (HANDLE)0x0) {
    FUN_00471395(DAT_005dcd50);
  }
  if (DAT_005dcd18 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dcd18);
  }
  if (DAT_005dcd5c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dcd5c);
  }
  if (DAT_005dcd20 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dcd20);
  }
  if (DAT_005dcd58 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_005dcd58);
  }
  DAT_005dcd54 = (HANDLE)0x0;
  DAT_005dcd4c = (HANDLE)0x0;
  DAT_005dcd48 = (HANDLE)0x0;
  DAT_005dcd50 = (HANDLE)0x0;
  DAT_005dcd18 = (HGDIOBJ)0x0;
  DAT_005dcd5c = (HGDIOBJ)0x0;
  DAT_005dcd20 = (HGDIOBJ)0x0;
  DAT_005dcd58 = (HGDIOBJ)0x0;
  return;
}


