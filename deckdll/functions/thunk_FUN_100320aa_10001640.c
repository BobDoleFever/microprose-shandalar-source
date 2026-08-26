/*
 * Decompiled function: thunk_FUN_100320aa
 * Entry Point: 10001640
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_100320aa(void)

{
  UINT UVar1;
  PALETTEENTRY PStack_628;
  char acStack_624 [264];
  int32_t uStack_51c;
  UINT UStack_514;
  char acStack_510 [264];
  LOGPALETTE *pLStack_408;
  tagPALETTEENTRY atStack_404 [256];
  
  uStack_51c = 1;
  strcpy(acStack_624,&DAT_10158770);
  strcat(acStack_624,s__DUELPALall_TR_100466e4);
  strcpy(acStack_510,&DAT_10158770);
  strcat(acStack_510,s__DUEL_plogpal_100466f4);
  pLStack_408 = (LOGPALETTE *)thunk_FUN_1000e474(acStack_624,acStack_510);
  if (pLStack_408 == (LOGPALETTE *)0x0) {
    uStack_51c = 0;
  }
  else {
    for (UStack_514 = 1; (int)UStack_514 < 0xff; UStack_514 = UStack_514 + 1) {
      pLStack_408->palPalEntry[UStack_514].peFlags = '\x04';
    }
    DAT_10140990 = CreatePalette(pLStack_408);
    if (DAT_10140990 == (HPALETTE)0x0) {
      uStack_51c = 0;
    }
    else {
      PStack_628.peRed = 0xff;
      PStack_628.peGreen = 0xff;
      PStack_628.peBlue = 0xff;
      PStack_628.peFlags = '\0';
      SetPaletteEntries(DAT_10140990,0xff,1,&PStack_628);
      PStack_628.peRed = 0xfe;
      PStack_628.peGreen = 0xfe;
      PStack_628.peBlue = 0xfe;
      PStack_628.peFlags = '\x04';
      SetPaletteEntries(DAT_10140990,0xbf,1,&PStack_628);
      for (UStack_514 = 0xec; (int)UStack_514 < 0xff; UStack_514 = UStack_514 + 1) {
        PStack_628.peRed = '\x01';
        PStack_628.peGreen = '\x01';
        PStack_628.peBlue = '\x01';
        PStack_628.peFlags = '\x04';
        SetPaletteEntries(DAT_10140990,UStack_514,1,&PStack_628);
      }
      UVar1 = GetPaletteEntries(DAT_10140990,0,0x100,atStack_404);
      for (UStack_514 = 0; (int)UStack_514 < (int)UVar1; UStack_514 = UStack_514 + 1) {
        (&DAT_10175f10)[UStack_514 * 4] = atStack_404[UStack_514].peBlue;
        (&DAT_10175f11)[UStack_514 * 4] = atStack_404[UStack_514].peGreen;
        (&DAT_10175f12)[UStack_514 * 4] = atStack_404[UStack_514].peRed;
        (&DAT_10175f13)[UStack_514 * 4] = 0;
      }
      while (UStack_514 = UVar1, (int)UStack_514 < 0x100) {
        (&DAT_10175f10)[UStack_514 * 4] = 0;
        (&DAT_10175f11)[UStack_514 * 4] = 0;
        (&DAT_10175f12)[UStack_514 * 4] = 0;
        (&DAT_10175f13)[UStack_514 * 4] = 0;
        UVar1 = UStack_514 + 1;
      }
    }
  }
  return uStack_51c;
}


