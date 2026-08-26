/*
 * Decompiled function: FUN_00475c8a
 * Entry Point: 00475c8a
 * Size: 218 bytes
 */
#include "magic.h"


undefined4 FUN_00475c8a(int x,int arg_2,char *arg_3,undefined4 arg_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_0063ee1c;
  if (((DAT_006a3f78 == 0) && (iVar2 = FUN_00505c74(), iVar2 != 0)) && (x != -2)) {
    DAT_0063ee1c = 1;
  }
  do {
    DAT_006ff380 = 0;
    uVar3 = Magic_CleanupPhase(x,arg_2,arg_3,arg_4);
    if ((DAT_006ff380 == 0) || (0 < DAT_006a3f78)) break;
  } while (g_IsAiThinking != 1);
  DAT_0063ee1c = uVar1;
  if (DAT_006a3f78 == 0) {
    DAT_0063ee1c = 0;
    *(uint *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) =
         *(uint *)(&DAT_00696740 + g_DefendingPlayer * 0x98 + g_ScWillyScore * 4) & 0xfffffffd;
  }
  return uVar3;
}


