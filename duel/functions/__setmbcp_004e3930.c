/*
 * Decompiled function: __setmbcp
 * Entry Point: 004e3930
 * Size: 815 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setmbcp(int arg_1)

{
  UINT CodePage;
  int iVar1;
  BOOL BVar2;
  BYTE *local_2c;
  uint local_28;
  _cpinfo local_24;
  uint local_10;
  byte *local_c;
  uint local_8;
  
  CodePage = getSystemCP(arg_1);
  if (CodePage == DAT_0050a304) {
    iVar1 = 0;
  }
  else if (CodePage == 0) {
    setSBCS();
    iVar1 = 0;
  }
  else {
    for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
      if (*(UINT *)(&DAT_0050a328 + local_8 * 0x30) == CodePage) {
        for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
          (&DAT_0050a200)[local_28] = 0;
        }
        for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
          for (local_c = &DAT_0050a338 + local_8 * 0x30 + local_10 * 8;
              (*local_c != 0 && (local_c[1] != 0)); local_c = local_c + 2) {
            for (local_28 = (uint)*local_c; local_28 <= local_c[1]; local_28 = local_28 + 1) {
              (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | (&DAT_0050a320)[local_10];
            }
          }
        }
        DAT_0050a304 = CodePage;
        DAT_0050a308 = _CPtoLCID(CodePage);
        for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
          *(undefined2 *)(&DAT_0050a310 + local_10 * 2) =
               *(undefined2 *)(&DAT_0050a32c + local_10 * 2 + local_8 * 0x30);
        }
        return 0;
      }
    }
    BVar2 = GetCPInfo(CodePage,&local_24);
    if (BVar2 == 1) {
      for (local_28 = 0; local_28 < 0x101; local_28 = local_28 + 1) {
        (&DAT_0050a200)[local_28] = 0;
      }
      if (local_24.MaxCharSize < 2) {
        DAT_0050a304 = 0;
        DAT_0050a308 = 0;
      }
      else {
        for (local_2c = local_24.LeadByte; (*local_2c != 0 && (local_2c[1] != 0));
            local_2c = local_2c + 2) {
          for (local_28 = (uint)*local_2c; local_28 <= local_2c[1]; local_28 = local_28 + 1) {
            (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | 4;
          }
        }
        for (local_28 = 1; local_28 < 0xff; local_28 = local_28 + 1) {
          (&DAT_0050a201)[local_28] = (&DAT_0050a201)[local_28] | 8;
        }
        DAT_0050a304 = CodePage;
        DAT_0050a308 = _CPtoLCID(CodePage);
      }
      for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
        *(undefined2 *)(&DAT_0050a310 + local_10 * 2) = 0;
      }
      iVar1 = 0;
    }
    else if (DAT_0050a31c == 0) {
      iVar1 = -1;
    }
    else {
      setSBCS();
      iVar1 = 0;
    }
  }
  return iVar1;
}


