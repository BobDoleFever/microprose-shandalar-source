/*
 * Decompiled function: FUN_1000936d
 * Entry Point: 1000936d
 * Size: 610 bytes
 */
#include "magvid.h"


int32_t __thiscall FUN_1000936d(void *this,HPALETTE arg_2)

{
  int32_t uval_1;
  UINT UVar2;
  uint32_t uval_3;
  int val_4;
  tagPALETTEENTRY local_518 [256];
  uint32_t local_118;
  int local_114;
  uint8_t *local_110;
  uint8_t abStack_10c [256];
  int local_c;
  BYTE *local_8;
  
  if (arg_2 == (HPALETTE)0x0) {
    uval_1 = 0;
  }
  else if (*(short *)(*(int *)((int)this + 4) + 0xe) == 8) {
    if (*(int *)((int)this + 0x14) == 0) {
      local_8 = (BYTE *)thunk_FUN_10007080((int)this);
      local_c = 0;
      for (local_118 = 0; local_118 < 0x100; local_118 = local_118 + 1) {
        UVar2 = GetNearestPaletteIndex
                          (arg_2,(uint32_t)CONCAT12(*local_8,CONCAT11(local_8[1],local_8[2])));
        abStack_10c[local_118] = (uint8_t)UVar2;
        local_8 = local_8 + 4;
        if (abStack_10c[local_118] != local_118) {
          local_c = local_c + 1;
        }
        if ((*(int *)((int)this + 0x10) != 0) && (**(uint32_t **)((int)this + 0x10) == local_118)) {
          thunk_FUN_1000a1b0((int)this);
          thunk_FUN_1000a160(this,(uint32_t)abStack_10c[local_118]);
        }
      }
      local_110 = (uint8_t *)thunk_FUN_10004bf0((int)this);
      uval_3 = thunk_FUN_1000a200((int)this);
      val_4 = CFontDialog::GetWeight(this);
      local_114 = uval_3 * val_4;
      while( true ) {
        if (local_114 == 0) break;
        *local_110 = abStack_10c[*local_110];
        local_110 = local_110 + 1;
        local_114 = local_114 + -1;
      }
      local_114 = local_114 + -1;
      GetPaletteEntries(arg_2,0,0x100,local_518);
      local_8 = (BYTE *)thunk_FUN_10007080((int)this);
      for (local_118 = 0; local_118 < 0x100; local_118 = local_118 + 1) {
        local_8[2] = local_518[local_118].peRed;
        local_8[1] = local_518[local_118].peGreen;
        *local_8 = local_518[local_118].peBlue;
        local_8 = local_8 + 4;
      }
      *(int32_t *)((int)this + 0x14) = 1;
      uval_1 = 1;
    }
    else {
      uval_1 = 1;
    }
  }
  else {
    uval_1 = 0;
  }
  return uval_1;
}


