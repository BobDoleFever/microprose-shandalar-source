/*
 * Decompiled function: SpellChain_CleanupUI
 * Entry Point: 004cda01
 * Size: 334 bytes
 */
#include "magic.h"


void SpellChain_CleanupUI(void)

{
  if (DAT_0056594c != (HMENU)0x0) {
    DestroyMenu(DAT_0056594c);
  }
  DAT_0056594c = (HMENU)0x0;
  if (DAT_00565984 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00565984);
  }
  if (DAT_0056597c != (HANDLE)0x0) {
    FUN_004f4548(DAT_0056597c);
  }
  if (DAT_00565978 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00565978);
  }
  if (DAT_00565980 != (HANDLE)0x0) {
    FUN_004f4548(DAT_00565980);
  }
  if (DAT_00565948 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565948);
  }
  if (DAT_0056598c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0056598c);
  }
  if (DAT_00565950 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565950);
  }
  if (DAT_00565988 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_00565988);
  }
  DAT_00565984 = (HANDLE)0x0;
  DAT_0056597c = (HANDLE)0x0;
  DAT_00565978 = (HANDLE)0x0;
  DAT_00565980 = (HANDLE)0x0;
  DAT_00565948 = (HGDIOBJ)0x0;
  DAT_0056598c = (HGDIOBJ)0x0;
  DAT_00565950 = (HGDIOBJ)0x0;
  DAT_00565988 = (HGDIOBJ)0x0;
  return;
}


