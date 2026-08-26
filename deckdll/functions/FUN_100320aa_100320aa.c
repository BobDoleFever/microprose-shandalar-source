/*
 * Decompiled function: FUN_100320aa
 * Entry Point: 100320aa
 * Size: 753 bytes
 */
#include "deckdll.h"


int32_t FUN_100320aa(void)

{
  UINT UVar1;
  PALETTEENTRY local_628;
  char local_624 [264];
  int32_t local_51c;
  UINT local_514;
  char local_510 [264];
  LOGPALETTE *local_408;
  tagPALETTEENTRY local_404 [256];
  
  local_51c = 1;
  strcpy(local_624,&DAT_10158770);
  strcat(local_624,s__DUELPALall_TR_100466e4);
  strcpy(local_510,&DAT_10158770);
  strcat(local_510,s__DUEL_plogpal_100466f4);
  local_408 = (LOGPALETTE *)thunk_FUN_1000e474(local_624,local_510);
  if (local_408 == (LOGPALETTE *)0x0) {
    local_51c = 0;
  }
  else {
    for (local_514 = 1; (int)local_514 < 0xff; local_514 = local_514 + 1) {
      local_408->palPalEntry[local_514].peFlags = '\x04';
    }
    DAT_10140990 = CreatePalette(local_408);
    if (DAT_10140990 == (HPALETTE)0x0) {
      local_51c = 0;
    }
    else {
      local_628.peRed = 0xff;
      local_628.peGreen = 0xff;
      local_628.peBlue = 0xff;
      local_628.peFlags = '\0';
      SetPaletteEntries(DAT_10140990,0xff,1,&local_628);
      local_628.peRed = 0xfe;
      local_628.peGreen = 0xfe;
      local_628.peBlue = 0xfe;
      local_628.peFlags = '\x04';
      SetPaletteEntries(DAT_10140990,0xbf,1,&local_628);
      for (local_514 = 0xec; (int)local_514 < 0xff; local_514 = local_514 + 1) {
        local_628.peRed = '\x01';
        local_628.peGreen = '\x01';
        local_628.peBlue = '\x01';
        local_628.peFlags = '\x04';
        SetPaletteEntries(DAT_10140990,local_514,1,&local_628);
      }
      UVar1 = GetPaletteEntries(DAT_10140990,0,0x100,local_404);
      for (local_514 = 0; (int)local_514 < (int)UVar1; local_514 = local_514 + 1) {
        (&DAT_10175f10)[local_514 * 4] = local_404[local_514].peBlue;
        (&DAT_10175f11)[local_514 * 4] = local_404[local_514].peGreen;
        (&DAT_10175f12)[local_514 * 4] = local_404[local_514].peRed;
        (&DAT_10175f13)[local_514 * 4] = 0;
      }
      while (local_514 = UVar1, (int)local_514 < 0x100) {
        (&DAT_10175f10)[local_514 * 4] = 0;
        (&DAT_10175f11)[local_514 * 4] = 0;
        (&DAT_10175f12)[local_514 * 4] = 0;
        (&DAT_10175f13)[local_514 * 4] = 0;
        UVar1 = local_514 + 1;
      }
    }
  }
  return local_51c;
}


