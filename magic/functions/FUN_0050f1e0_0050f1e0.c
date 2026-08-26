/*
 * Decompiled function: FUN_0050f1e0
 * Entry Point: 0050f1e0
 * Size: 197 bytes
 */
#include "magic.h"


undefined4 FUN_0050f1e0(int arg_1,int arg_2,LPCSTR str_3,LPCSTR str_4,int arg_5,DWORD arg_6)

{
  char cVar1;
  HFONT pHVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  AddFontResourceA(str_3);
  iVar5 = arg_1 * 0x2a0;
  pHVar2 = CreateFontA(arg_2,0,0,0,arg_5,arg_6,0,0,0,0,0,0,0,str_4);
  uVar3 = 0xffffffff;
  *(HFONT *)(&DAT_007077bc + iVar5) = pHVar2;
  do {
    pcVar6 = str_3;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = str_3 + 1;
    cVar1 = *str_3;
    str_3 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  pcVar7 = &DAT_007077c0 + iVar5;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = 0xffffffff;
  do {
    pcVar6 = str_4;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = str_4 + 1;
    cVar1 = *str_4;
    str_4 = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar6 + -uVar3;
  pcVar7 = &DAT_007078c0 + iVar5;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  (&DAT_007077a4)[iVar5] = (char)((int)(arg_2 * 0xd + (arg_2 * 0xd >> 0x1f & 0xfU)) >> 4);
  *(undefined4 *)(&DAT_007077b8 + iVar5) = 1;
  return 1;
}


