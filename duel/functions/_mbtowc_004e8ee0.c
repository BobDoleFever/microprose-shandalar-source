/*
 * Decompiled function: _mbtowc
 * Entry Point: 004e8ee0
 * Size: 410 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    _mbtowc
   
   Library: Visual Studio 1998 Debug */

int __cdecl _mbtowc(wchar_t *str_1,char *str_2,size_t arg_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if (((DAT_005096ac != 1) && (DAT_005096ac != 2)) &&
     (iVar2 = __CrtDbgReport(2,0x4f1234,0x4d,0,"MB_CUR_MAX == 1 || MB_CUR_MAX == 2"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((str_2 == (char *)0x0) || (arg_3 == 0)) {
    uVar3 = 0;
  }
  else if (*str_2 == '\0') {
    if (str_1 != (wchar_t *)0x0) {
      *str_1 = L'\0';
    }
    uVar3 = 0;
  }
  else if (DAT_0050a730 == 0) {
    if (str_1 != (wchar_t *)0x0) {
      *str_1 = (ushort)(byte)*str_2;
    }
    uVar3 = 1;
  }
  else if ((*(ushort *)(PTR_DAT_005094a0 + (uint)(byte)*str_2 * 2) & 0x8000) == 0) {
    iVar2 = MultiByteToWideChar(DAT_0050a740,9,str_2,1,str_1,(uint)(str_1 != (wchar_t *)0x0));
    if (iVar2 == 0) {
      DAT_00509420 = 0x2a;
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = 1;
    }
  }
  else if (((((int)DAT_005096ac < 2) || ((int)arg_3 < (int)DAT_005096ac)) ||
           (iVar2 = MultiByteToWideChar(DAT_0050a740,9,str_2,DAT_005096ac,str_1,
                                        (uint)(str_1 != (wchar_t *)0x0)), uVar3 = DAT_005096ac,
           iVar2 == 0)) && ((arg_3 < DAT_005096ac || (uVar3 = DAT_005096ac, str_2[1] == '\0')))) {
    DAT_00509420 = 0x2a;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


