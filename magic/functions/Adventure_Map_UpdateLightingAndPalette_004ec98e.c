/*
 * Decompiled function: Adventure_Map_UpdateLightingAndPalette
 * Entry Point: 004ec98e
 * Size: 841 bytes
 */
#include "magic.h"


undefined4 Adventure_Map_UpdateLightingAndPalette(uint arg1,uint arg2)

{
  uint local_40 [7];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_0050d560(0,0);
  LoadPalNoPic(s_advfac64_pic_0052fb10);
  local_14 = GetThreadPriority(DAT_00627850);
  for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
    local_20 = 0;
    local_c = 0;
    local_24 = Adventure_Audio_GetTrackStatus(local_18 + 1);
    for (local_1c = 0; local_1c < 0x80; local_1c = local_1c + 1) {
      if (((&DAT_0067be01)[local_1c * 100] != '\0') &&
         ((*(int *)(&DAT_0067be00 + local_1c * 100) >> 8) + -1 == local_18)) {
        local_c = local_c + 1;
      }
    }
    (&DAT_00641058)[local_24] = (undefined1)local_c;
    if (*(int *)(&DAT_006410c0 + local_18 * 4) == 0) {
      local_10 = DAT_0067f380 * local_c + DAT_0067f380 * 5 + 0x1e;
      for (local_1c = 0; (local_1c < 1000 && ((&DAT_0067b9b0)[local_1c] != '\0'));
          local_1c = local_1c + 1) {
        if ((int)(char)(&DAT_0067b9b0)[local_1c] >> 4 == local_18 + 1) {
          local_20 = local_20 + 1;
        }
      }
      *(int *)(&DAT_00641044 + local_24 * 4) = local_20;
      local_40[6] = DAT_0067f380 * 5 + 0x14;
      if ((int)local_40[6] <= local_10 - local_20) {
        local_40[6] = local_10 - local_20;
      }
      *(uint *)(&DAT_00641030 + local_24 * 4) = 0x1e - (local_10 - local_40[6]);
    }
    else {
      *(undefined4 *)(&DAT_00641030 + local_24 * 4) = 0;
    }
  }
  DAT_0064105d = 0;
  DAT_0064105e = 0;
  DAT_0064105f = 0;
  if ((char)arg1 == '\x01') {
    if ((arg1 & 0x100) == 0) {
      *(undefined4 *)(&DAT_006410bc + arg2 * 4) = 1;
    }
    DAT_0064105d = Adventure_Audio_GetTrackStatus(arg2);
    *(undefined4 *)(&DAT_00641030 + (uint)DAT_0064105d * 4) = 0;
    arg1 = arg1 & 0xff;
  }
  if (arg1 == 2) {
    local_40[0] = arg2 >> 0x10;
    local_40[1] = 4;
    local_40[2] = 2;
    local_40[3] = 3;
    local_40[4] = 1;
    local_40[5] = 0;
    arg2 = arg2 & 0xffff;
    if ((&DAT_0052262b)[arg2 * 0x44] == -1) {
      arg1 = 0;
    }
    else {
      DAT_0064105e = (undefined1)arg2;
      DAT_0064105d = (byte)local_40[local_40[0]];
    }
  }
  if (arg1 == 3) {
    DAT_0064105f = (undefined1)arg2;
  }
  Mem_AllocOrFree_00409e13(&DAT_00641030,arg1);
  SetThreadPriority(DAT_00627850,local_14);
  SetThreadPriority(DAT_00626820,local_8);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_0052fb20);
  Catalog_LoadPaletteMap(s_todpal_tr_0052fb30,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  return 0;
}


