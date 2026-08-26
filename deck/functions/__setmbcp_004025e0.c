/*
 * Decompiled function: __setmbcp
 * Entry Point: 004025e0
 * Size: 815 bytes
 */
#include "deck.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setmbcp(int arg_1)

{
  UINT CodePage;
  int val_1;
  BOOL BVar2;
  BYTE *local_2c;
  uint32_t local_28;
  _cpinfo local_24;
  uint32_t local_10;
  uint8_t *local_c;
  uint32_t local_8;
  
  CodePage = getSystemCP(arg_1);
  if (CodePage == DAT_00412c6c) {
    val_1 = 0;
  }
  else if (CodePage == 0) {
    setSBCS();
    val_1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      if (*(UINT *)(&DAT_00412c90 + local_8 * 0x30) == CodePage) {
        for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
          (&DAT_00412b68)[local_28] = 0;
        }
        for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
          for (local_c = &DAT_00412ca0 + local_8 * 0x30 + local_10 * 8;
              (*local_c != 0 && (local_c[1] != 0)); local_c = local_c + 2) {
            for (local_28 = (uint32_t)*local_c; local_28 <= local_c[1]; local_28 = local_28 + 1) {
              (&DAT_00412b69)[local_28] = (&DAT_00412b69)[local_28] | (&DAT_00412c88)[local_10];
            }
          }
        }
        DAT_00412c6c = CodePage;
        _DAT_00412c70 = _CPtoLCID(CodePage);
        for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
          *(int16_t *)(&DAT_00412c78 + local_10 * 2) =
               *(int16_t *)(&DAT_00412c94 + local_10 * 2 + local_8 * 0x30);
        }
        return 0;
      }
    }
    BVar2 = GetCPInfo(CodePage,&local_24);
    if (BVar2 == 1) {
      for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
        (&DAT_00412b68)[local_28] = 0;
      }
      if (local_24.MaxCharSize < 2) {
        DAT_00412c6c = 0;
        _DAT_00412c70 = 0;
      }
      else {
        for (local_2c = local_24.LeadByte; (*local_2c != 0 && (local_2c[1] != 0));
            local_2c = local_2c + 2) {
          for (local_28 = (uint32_t)*local_2c; local_28 <= local_2c[1]; local_28 = local_28 + 1) {
            (&DAT_00412b69)[local_28] = (&DAT_00412b69)[local_28] | 4;
          }
        }
        for (local_28 = 1; local_28 < 0xff; local_28 = local_28 + 1) {
          (&DAT_00412b69)[local_28] = (&DAT_00412b69)[local_28] | 8;
        }
        DAT_00412c6c = CodePage;
        _DAT_00412c70 = _CPtoLCID(CodePage);
      }
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(int16_t *)(&DAT_00412c78 + local_10 * 2) = 0;
      }
      val_1 = 0;
    }
    else if (DAT_00412c84 == 0) {
      val_1 = -1;
    }
    else {
      setSBCS();
      val_1 = 0;
    }
  }
  return val_1;
}


