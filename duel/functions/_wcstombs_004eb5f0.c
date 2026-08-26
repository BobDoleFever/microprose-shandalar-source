/*
 * Decompiled function: _wcstombs
 * Entry Point: 004eb5f0
 * Size: 829 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _wcstombs
   
   Library: Visual Studio 1998 Debug */

size_t __cdecl _wcstombs(char *str_1,wchar_t *str_2,size_t arg_3)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  DWORD DVar4;
  BOOL local_18;
  int local_14;
  CHAR local_10 [4];
  int local_c;
  uint local_8;
  
  local_8 = 0;
  local_18 = 0;
  if ((str_1 == (char *)0x0) || (arg_3 != 0)) {
    if ((str_2 == (wchar_t *)0x0) &&
       (iVar2 = __CrtDbgReport(2,0x4f12bc,0x7a,0,"pwcs != NULL"), iVar2 == 1)) {
      pcVar1 = (code *)swi(3);
      sVar3 = (*pcVar1)();
      return sVar3;
    }
    if (str_1 == (char *)0x0) {
      if (DAT_0050a730 == 0) {
        local_8 = _wcslen(str_2);
      }
      else {
        iVar2 = WideCharToMultiByte(DAT_0050a740,0x220,str_2,-1,(LPSTR)0x0,0,(LPCSTR)0x0,&local_18);
        if ((iVar2 == 0) || (local_18 != 0)) {
          DAT_00509420 = 0x2a;
          local_8 = 0xffffffff;
        }
        else {
          local_8 = iVar2 - 1;
        }
      }
    }
    else if (DAT_0050a730 == 0) {
      for (; local_8 < arg_3; local_8 = local_8 + 1) {
        if (0xff < (ushort)*str_2) {
          DAT_00509420 = 0x2a;
          return 0xffffffff;
        }
        str_1[local_8] = (char)*str_2;
        if (*str_2 == L'\0') {
          return local_8;
        }
        str_2 = str_2 + 1;
      }
    }
    else if (DAT_005096ac == 1) {
      if (arg_3 != 0) {
        arg_3 = wcsncnt(str_2,arg_3);
      }
      local_8 = WideCharToMultiByte(DAT_0050a740,0x220,str_2,arg_3,str_1,arg_3,(LPCSTR)0x0,&local_18
                                   );
      if ((local_8 == 0) || (local_18 != 0)) {
        DAT_00509420 = 0x2a;
        local_8 = 0xffffffff;
      }
      else if (str_1[local_8 - 1] == '\0') {
        local_8 = local_8 - 1;
      }
    }
    else {
      local_8 = WideCharToMultiByte(DAT_0050a740,0x220,str_2,-1,str_1,arg_3,(LPCSTR)0x0,&local_18);
      if ((local_8 == 0) || (local_18 != 0)) {
        if ((local_18 == 0) && (DVar4 = GetLastError(), DVar4 == 0x7a)) {
          while (local_8 < arg_3) {
            local_14 = WideCharToMultiByte(DAT_0050a740,0,str_2,1,local_10,DAT_005096ac,(LPCSTR)0x0,
                                           &local_18);
            if ((local_14 == 0) || (local_18 != 0)) {
              DAT_00509420 = 0x2a;
              return 0xffffffff;
            }
            if (arg_3 < local_14 + local_8) {
              return local_8;
            }
            for (local_c = 0; local_c < local_14; local_c = local_c + 1) {
              str_1[local_8] = local_10[local_c];
              if (str_1[local_8] == '\0') {
                return local_8;
              }
              local_8 = local_8 + 1;
            }
            str_2 = str_2 + 1;
          }
        }
        else {
          DAT_00509420 = 0x2a;
          local_8 = 0xffffffff;
        }
      }
      else {
        local_8 = local_8 - 1;
      }
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}


