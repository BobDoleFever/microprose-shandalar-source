/*
 * Decompiled function: thunk_FUN_10001f20
 * Entry Point: 100010aa
 * Size: 5 bytes
 */
#include "deckdll.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t * thunk_FUN_10001f20(int arg_1,char *str_2,int arg_3)

{
  char cVar1;
  uint32_t uval_2;
  uint32_t uval_3;
  int val_4;
  int val_5;
  char *pcVar6;
  int32_t *puVar7;
  char *pcVar8;
  char *pcVar9;
  int32_t *puVar10;
  char acStack_40c [260];
  char acStack_308 [264];
  char acStack_200 [256];
  char acStack_100 [256];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  _splitpath(str_2,(char *)0x0,acStack_40c,acStack_200,acStack_100);
  if (DAT_1004c6d4 == 0) {
    uval_2 = 0xffffffff;
    pcVar6 = acStack_40c;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = acStack_308;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uval_2 = 0xffffffff;
    pcVar6 = s_SmallArt_cat_10040480;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    val_4 = -1;
    pcVar6 = acStack_308;
    do {
      pcVar8 = pcVar6;
      if (val_4 == 0) break;
      val_4 = val_4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = pcVar8 + -1;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_1004044c = thunk_FUN_1000dd80(acStack_308);
    uval_2 = 0xffffffff;
    pcVar6 = acStack_40c;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = acStack_308;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uval_2 = 0xffffffff;
    pcVar6 = s_MedArt_cat_10040470;
    do {
      pcVar9 = pcVar6;
      if (uval_2 == 0) break;
      uval_2 = uval_2 - 1;
      pcVar9 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar9;
    } while (cVar1 != '\0');
    uval_2 = ~uval_2;
    val_4 = -1;
    pcVar6 = acStack_308;
    do {
      pcVar8 = pcVar6;
      if (val_4 == 0) break;
      val_4 = val_4 + -1;
      pcVar8 = pcVar6 + 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar8;
    } while (cVar1 != '\0');
    pcVar6 = pcVar9 + -uval_2;
    pcVar9 = pcVar8 + -1;
    for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_10040450 = thunk_FUN_1000dd80(acStack_308);
    DAT_1004c6d4 = 1;
  }
  val_4 = -1;
  pcVar6 = acStack_40c;
  do {
    if (val_4 == 0) break;
    val_4 = val_4 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  val_4 = DAT_1004044c;
  if ((arg_1 != 0) && (val_4 = DAT_10040450, arg_1 != 1)) {
    return (int32_t *)0x0;
  }
  uval_2 = 0xffffffff;
  pcVar6 = acStack_200;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = acStack_40c;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uval_2 = 0xffffffff;
  pcVar6 = acStack_100;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  val_5 = -1;
  pcVar6 = acStack_40c;
  do {
    pcVar8 = pcVar6;
    if (val_5 == 0) break;
    val_5 = val_5 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = pcVar8 + -1;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_10103c90 = val_4;
  _strlwr(acStack_40c);
  puVar7 = &DAT_1004c6e0;
  for (val_4 = 0x6c; val_4 != 0; val_4 = val_4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  uval_2 = 0xffffffff;
  pcVar6 = str_2;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = (char *)&DAT_1004c77c;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_1004c880 = (int32_t *)&DAT_100c7090;
  val_4 = thunk_FUN_1000e156(DAT_10103c90,acStack_40c,(int *)&DAT_1004c880);
  if (val_4 != -1) {
    _DAT_1004c884 = val_4 + -0x9c;
    puVar7 = DAT_1004c880;
    puVar10 = &DAT_1004c6e0;
    for (val_4 = 0x27; val_4 != 0; val_4 = val_4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_1004c880 = DAT_1004c880 + 0x27;
    if (DAT_1004c708 == 4) {
      DAT_1004c6fc = DAT_1004c6fc * 2;
      DAT_1004c700 = DAT_1004c700 * 2;
    }
    if (arg_3 != 0) {
      _DAT_1004c88c = thunk_FUN_10002360(&DAT_1004c6e0,(undefined8 *)0x0);
      if (_DAT_1004c88c == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
        return (int32_t *)0x0;
      }
      _DAT_1004c888 = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
    }
    return &DAT_1004c6e0;
  }
  uval_2 = 0xffffffff;
  pcVar6 = (char *)&DAT_1004046c;
  do {
    pcVar9 = pcVar6;
    if (uval_2 == 0) break;
    uval_2 = uval_2 - 1;
    pcVar9 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar9;
  } while (cVar1 != '\0');
  uval_2 = ~uval_2;
  val_4 = -1;
  pcVar6 = str_2;
  do {
    pcVar8 = pcVar6;
    if (val_4 == 0) break;
    val_4 = val_4 + -1;
    pcVar8 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar8;
  } while (cVar1 != '\0');
  pcVar6 = pcVar9 + -uval_2;
  pcVar9 = pcVar8 + -1;
  for (uval_3 = uval_2 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
    *(int32_t *)pcVar9 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  OutputDebugStringA(str_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_101cf930);
  return (int32_t *)0x0;
}


