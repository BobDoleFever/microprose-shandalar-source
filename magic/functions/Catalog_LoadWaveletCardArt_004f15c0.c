/*
 * Decompiled function: Catalog_LoadWaveletCardArt
 * Entry Point: 004f15c0
 * Size: 841 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * Catalog_LoadWaveletCardArt(int arg_1,char *str_2,int arg_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char local_40c [260];
  char local_308 [264];
  char local_200 [256];
  char local_100 [256];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  _splitpath(str_2,(char *)0x0,local_40c,local_200,local_100);
  if (DAT_00566224 == 0) {
    uVar2 = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar9 + -uVar2;
    pcVar9 = local_308;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar2 = 0xffffffff;
    pcVar6 = s_SmallArt_cat_005300c4;
    do {
      pcVar9 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    iVar4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uVar2;
    pcVar9 = pcVar8 + -1;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_005300a4 = Catalog_Open(local_308);
    uVar2 = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    pcVar6 = pcVar9 + -uVar2;
    pcVar9 = local_308;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar2 = 0xffffffff;
    pcVar6 = s_MedArt_cat_005300b8;
    do {
      pcVar9 = pcVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
    iVar4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uVar2;
    pcVar9 = pcVar8 + -1;
    for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_005300a8 = Catalog_Open(local_308);
    DAT_00566224 = 1;
  }
  iVar4 = -1;
  pcVar6 = local_40c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar4 = DAT_005300a4;
  if ((arg_1 != 0) && (iVar4 = DAT_005300a8, arg_1 != 1)) {
    return (undefined4 *)0x0;
  }
  uVar2 = 0xffffffff;
  pcVar6 = local_200;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = local_40c;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = local_100;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar5 = -1;
  pcVar6 = local_40c;
  do {
    pcVar8 = pcVar6;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_0061d7e0 = iVar4;
  _strlwr(local_40c);
  puVar7 = &DAT_00566230;
  for (iVar4 = 0x6c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar6 = str_2;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = (char *)&DAT_005662cc;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_005663d0 = (undefined4 *)&DAT_005e0be0;
  iVar4 = Catalog_ReadFile(DAT_0061d7e0,local_40c,(int *)&DAT_005663d0);
  if (iVar4 != -1) {
    _DAT_005663d4 = iVar4 + -0x9c;
    puVar7 = DAT_005663d0;
    puVar10 = &DAT_00566230;
    for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_005663d0 = DAT_005663d0 + 0x27;
    if (DAT_00566258 == 4) {
      DAT_0056624c = DAT_0056624c * 2;
      DAT_00566250 = DAT_00566250 * 2;
    }
    if (arg_3 != 0) {
      _DAT_005663dc = Haar_DecompressWaveletImage(&DAT_00566230,(undefined8 *)0x0);
      if (_DAT_005663dc == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
        return (undefined4 *)0x0;
      }
      _DAT_005663d8 = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
    }
    return &DAT_00566230;
  }
  uVar2 = 0xffffffff;
  pcVar6 = (char *)&DAT_005300b4;
  do {
    pcVar9 = pcVar6;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar4 = -1;
  pcVar6 = str_2;
  do {
    pcVar8 = pcVar6;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uVar2;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  OutputDebugStringA(str_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  return (undefined4 *)0x0;
}


