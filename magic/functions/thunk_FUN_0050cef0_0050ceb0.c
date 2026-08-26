/*
 * Decompiled function: thunk_FUN_0050cef0
 * Entry Point: 0050ceb0
 * Size: 5 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * thunk_FUN_0050cef0(void)

{
  LOGPALETTE *pLVar1;
  undefined4 *puVar2;
  int iVar3;
  int arg_2;
  int arg_3;
  int iVar4;
  undefined4 uVar5;
  LOGPALETTE *plpal;
  HPALETTE hPal;
  undefined4 **ppuVar6;
  undefined4 **ppuVar7;
  char acStack_a [10];
  
  acStack_a[0] = DAT_00532572;
  acStack_a[1] = '\0';
  acStack_a[2] = '\0';
  acStack_a[3] = '\0';
  acStack_a[4] = '\0';
  acStack_a[5] = '\0';
  acStack_a[6] = '\0';
  acStack_a[7] = '\0';
  acStack_a[8] = '\0';
  acStack_a[9] = 0;
  if (DAT_0053255c != 0) {
    return DAT_0070a850;
  }
  puVar2 = malloc(0x30);
  iVar3 = GetDeviceCaps(_hdcScreen,8);
  DAT_0070a87c = iVar3;
  puVar2[8] = iVar3;
  arg_2 = GetDeviceCaps(_hdcScreen,10);
  DAT_0070a878 = arg_2;
  puVar2[9] = arg_2;
  arg_3 = GetDeviceCaps(_hdcScreen,0xc);
  DAT_0070a880 = arg_3;
  puVar2[10] = arg_3;
  iVar4 = arg_3 * arg_2 * iVar3;
  _DAT_00532554 = 0;
  puVar2[7] = ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + 0x10;
  _itoa(0,acStack_a,10);
  puVar2[1] = _hdcScreen;
  uVar5 = FUN_0050ec90(iVar3,arg_2,arg_3);
  puVar2[4] = uVar5;
  uVar5 = FUN_0050ec90(iVar3,arg_2,8);
  puVar2[4] = uVar5;
  *puVar2 = 0;
  puVar2[2] = 0;
  plpal = malloc(0x408);
  plpal->palVersion = 0x300;
  iVar3 = 0x100;
  plpal->palNumEntries = 0x100;
  pLVar1 = plpal;
  do {
    pLVar1->palPalEntry[0].peRed = '\0';
    iVar3 = iVar3 + -1;
    pLVar1->palPalEntry[0].peGreen = '\0';
    pLVar1->palPalEntry[0].peBlue = '\0';
    pLVar1->palPalEntry[0].peFlags = '\x01';
    pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
  } while (iVar3 != 0);
  plpal->palPalEntry[0].peFlags = '\0';
  *(undefined1 *)((int)&plpal[0x80].palNumEntries + 1) = 0;
  ppuVar6 = (undefined4 **)&DAT_0070a450;
  _DAT_0070ac90 = plpal;
  do {
    *(undefined1 *)ppuVar6 = 0;
    ppuVar7 = ppuVar6 + 1;
    *(undefined1 *)((int)ppuVar6 + 1) = 0;
    *(undefined1 *)((int)ppuVar6 + 2) = 0;
    *(undefined1 *)((int)ppuVar6 + 3) = 1;
    ppuVar6 = ppuVar7;
  } while (ppuVar7 < &DAT_0070a850);
  DAT_0070a453 = 0;
  DAT_0070a84f = 0;
  hPal = CreatePalette(plpal);
  DAT_00626834 = hPal;
  _hLibPal = hPal;
  puVar2[5] = hPal;
  SelectPalette((HDC)puVar2[1],hPal,0);
  RealizePalette((HDC)puVar2[1]);
  SetStretchBltMode((HDC)puVar2[1],3);
  DAT_0070a850 = puVar2;
  DAT_0053255c = 1;
  return puVar2;
}


