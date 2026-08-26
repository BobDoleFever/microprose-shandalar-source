/*
 * Decompiled function: FUN_0048b5c9
 * Entry Point: 0048b5c9
 * Size: 134 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048b5c9(undefined4 arg1,int arg2)

{
  char cVar1;
  int iVar2;
  
  DAT_00667990 = 0xffffd8f1;
  DAT_0066aaf4 = 1;
  DAT_00666400 = arg1;
  iVar2 = (DAT_005f2f50 + 1) * arg2;
  DAT_0068ef94 = (int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2;
  cVar1 = FUN_00439892(5);
  _DAT_00692c74 = 1 << (cVar1 + 1U & 0x1f);
  Ai_SaveGameState();
  Mem_AllocOrFree_0049f568();
  Mem_AllocOrFree_00452185();
  DAT_0068dd00 = 0;
  DAT_0066aadc = 1;
  DAT_005ef980 = 0;
  return;
}


