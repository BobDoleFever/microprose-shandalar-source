/*
 * Decompiled function: FUN_00471426
 * Entry Point: 00471426
 * Size: 753 bytes
 */
#include "duel.h"


undefined4 FUN_00471426(void)

{
  UINT UVar1;
  PALETTEENTRY local_628;
  uint local_624 [66];
  undefined4 local_51c;
  UINT local_514;
  uint local_510 [66];
  LOGPALETTE *local_408;
  tagPALETTEENTRY local_404 [256];
  
  local_51c = 1;
  Mem_AllocOrFree_004d9630(local_624,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_624,(uint *)s__DUELPALall_TR_004f9834);
  Mem_AllocOrFree_004d9630(local_510,(uint *)&DAT_005f76e0);
  FUN_004d9640(local_510,(uint *)s__DUEL_plogpal_004f9844);
  local_408 = (LOGPALETTE *)Catalog_LoadPaletteMap((char *)local_624,(char *)local_510);
  if (local_408 == (LOGPALETTE *)0x0) {
    local_51c = 0;
  }
  else {
    for (local_514 = 1; (int)local_514 < 0xff; local_514 = local_514 + 1) {
      local_408->palPalEntry[local_514].peFlags = '\x04';
    }
    DAT_005f76d0 = CreatePalette(local_408);
    if (DAT_005f76d0 == (HPALETTE)0x0) {
      local_51c = 0;
    }
    else {
      local_628.peRed = 0xff;
      local_628.peGreen = 0xff;
      local_628.peBlue = 0xff;
      local_628.peFlags = '\0';
      SetPaletteEntries(DAT_005f76d0,0xff,1,&local_628);
      local_628.peRed = 0xfe;
      local_628.peGreen = 0xfe;
      local_628.peBlue = 0xfe;
      local_628.peFlags = '\x04';
      SetPaletteEntries(DAT_005f76d0,0xbf,1,&local_628);
      for (local_514 = 0xec; (int)local_514 < 0xff; local_514 = local_514 + 1) {
        local_628.peRed = '\x01';
        local_628.peGreen = '\x01';
        local_628.peBlue = '\x01';
        local_628.peFlags = '\x04';
        SetPaletteEntries(DAT_005f76d0,local_514,1,&local_628);
      }
      UVar1 = GetPaletteEntries(DAT_005f76d0,0,0x100,local_404);
      for (local_514 = 0; (int)local_514 < (int)UVar1; local_514 = local_514 + 1) {
        (&DAT_00617580)[local_514 * 4] = local_404[local_514].peBlue;
        (&DAT_00617581)[local_514 * 4] = local_404[local_514].peGreen;
        (&DAT_00617582)[local_514 * 4] = local_404[local_514].peRed;
        (&DAT_00617583)[local_514 * 4] = 0;
      }
      while (local_514 = UVar1, (int)local_514 < 0x100) {
        (&DAT_00617580)[local_514 * 4] = 0;
        (&DAT_00617581)[local_514 * 4] = 0;
        (&DAT_00617582)[local_514 * 4] = 0;
        (&DAT_00617583)[local_514 * 4] = 0;
        UVar1 = local_514 + 1;
      }
    }
  }
  return local_51c;
}


