/*
 * Decompiled function: Font_LoadTTF_Magim_TTF_0041f669
 * Entry Point: 0041f669
 * Size: 2066 bytes
 */
#include "duel.h"


void Font_LoadTTF_Magim_TTF_0041f669(void)

{
  uint local_110 [66];
  int local_8;
  
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Magim____TTF_004f3228);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Magis____TTF_004f3238);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Tt0127m__TTF_004f3248);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Tt0085m__TTF_004f3258);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Tt0298m__TTF_004f3268);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Tt0299m__TTF_004f3278);
  RemoveFontResourceA((LPCSTR)local_110);
  Mem_AllocOrFree_004d9630(local_110,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_110,(uint *)s__Tt0300m__TTF_004f3288);
  RemoveFontResourceA((LPCSTR)local_110);
  if (DAT_0050b1f8 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1f8);
    DAT_0050b1f8 = (HANDLE)0x0;
  }
  if (DAT_0050af8c != (HANDLE)0x0) {
    FUN_00471395(DAT_0050af8c);
    DAT_0050af8c = (HANDLE)0x0;
  }
  if (DAT_0050b204 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b204);
    DAT_0050b204 = (HANDLE)0x0;
  }
  if (DAT_0050add8 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050add8);
    DAT_0050add8 = (HANDLE)0x0;
  }
  if (DAT_0050b1b8 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1b8);
    DAT_0050b1b8 = (HANDLE)0x0;
  }
  if (DAT_0050adf4 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050adf4);
    DAT_0050adf4 = (HANDLE)0x0;
  }
  if (DAT_0050af98 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050af98);
    DAT_0050af98 = (HANDLE)0x0;
  }
  if (DAT_0050ac24 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050ac24);
    DAT_0050ac24 = (HANDLE)0x0;
  }
  if (DAT_0050adf0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050adf0);
    DAT_0050adf0 = (HANDLE)0x0;
  }
  if (DAT_0050b1e4 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1e4);
    DAT_0050b1e4 = (HANDLE)0x0;
  }
  if (DAT_0050ac30 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050ac30);
    DAT_0050ac30 = (HANDLE)0x0;
  }
  if (DAT_0050b178 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b178);
    DAT_0050b178 = (HANDLE)0x0;
  }
  if (DAT_0050abdc != (HANDLE)0x0) {
    FUN_00471395(DAT_0050abdc);
    DAT_0050abdc = (HANDLE)0x0;
  }
  if (DAT_0050ac1c != (HANDLE)0x0) {
    FUN_00471395(DAT_0050ac1c);
    DAT_0050ac1c = (HANDLE)0x0;
  }
  if (DAT_0050b1dc != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1dc);
    DAT_0050b1dc = (HANDLE)0x0;
  }
  if (DAT_0050b1f4 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1f4);
    DAT_0050b1f4 = (HANDLE)0x0;
  }
  if (DAT_0050b1e8 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1e8);
    DAT_0050b1e8 = (HANDLE)0x0;
  }
  if (DAT_0050adec != (HANDLE)0x0) {
    FUN_00471395(DAT_0050adec);
    DAT_0050adec = (HANDLE)0x0;
  }
  if (DAT_0050b1c4 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1c4);
    DAT_0050b1c4 = (HANDLE)0x0;
  }
  if (DAT_0050ac20 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050ac20);
    DAT_0050ac20 = (HANDLE)0x0;
  }
  if (DAT_0050ade8 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050ade8);
    DAT_0050ade8 = (HANDLE)0x0;
  }
  if (DAT_0050afa0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050afa0);
    DAT_0050afa0 = (HANDLE)0x0;
  }
  if (DAT_0050addc != (HANDLE)0x0) {
    FUN_00471395(DAT_0050addc);
    DAT_0050addc = (HANDLE)0x0;
  }
  if (DAT_0050b14c != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b14c);
    DAT_0050b14c = (HANDLE)0x0;
  }
  if (DAT_0050b17c != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b17c);
    DAT_0050b17c = (HANDLE)0x0;
  }
  if (DAT_0050abe0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050abe0);
    DAT_0050abe0 = (HANDLE)0x0;
  }
  if (DAT_0050b1f0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1f0);
    DAT_0050b1f0 = (HANDLE)0x0;
  }
  if (DAT_0050abd0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050abd0);
    DAT_0050abd0 = (HANDLE)0x0;
  }
  if (DAT_0050b1cc != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1cc);
    DAT_0050b1cc = (HANDLE)0x0;
  }
  if (DAT_0050b1c0 != (HANDLE)0x0) {
    FUN_00471395(DAT_0050b1c0);
    DAT_0050b1c0 = (HANDLE)0x0;
  }
  if (DAT_0050b13c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b13c);
  }
  DAT_0050b13c = (HGDIOBJ)0x0;
  if (DAT_0050ac2c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050ac2c);
  }
  DAT_0050ac2c = (HGDIOBJ)0x0;
  if (DAT_0050af88 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050af88);
  }
  DAT_0050af88 = (HGDIOBJ)0x0;
  if (DAT_0050af94 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050af94);
  }
  DAT_0050af94 = (HGDIOBJ)0x0;
  if (DAT_0050b1ec != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1ec);
  }
  DAT_0050b1ec = (HGDIOBJ)0x0;
  if (DAT_0050b1b4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1b4);
  }
  DAT_0050b1b4 = (HGDIOBJ)0x0;
  if (DAT_0050ade4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050ade4);
  }
  DAT_0050ade4 = (HGDIOBJ)0x0;
  if (DAT_0050abd8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050abd8);
  }
  DAT_0050abd8 = (HGDIOBJ)0x0;
  if (DAT_0050af9c != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050af9c);
  }
  DAT_0050af9c = (HGDIOBJ)0x0;
  if (DAT_0050b1bc != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1bc);
  }
  DAT_0050b1bc = (HGDIOBJ)0x0;
  if (DAT_0050b1c8 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1c8);
  }
  DAT_0050b1c8 = (HGDIOBJ)0x0;
  if (DAT_0050b240 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b240);
  }
  DAT_0050b240 = (HGDIOBJ)0x0;
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_0050b150 + local_8 * 4) != 0) {
      DeleteObject(*(HGDIOBJ *)(&DAT_0050b150 + local_8 * 4));
      *(undefined4 *)(&DAT_0050b150 + local_8 * 4) = 0;
    }
  }
  if (DAT_0050b1d4 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1d4);
  }
  DAT_0050b1d4 = (HGDIOBJ)0x0;
  if (DAT_0050b1e0 != (HGDIOBJ)0x0) {
    DeleteObject(DAT_0050b1e0);
  }
  DAT_0050b1e0 = (HGDIOBJ)0x0;
  return;
}


