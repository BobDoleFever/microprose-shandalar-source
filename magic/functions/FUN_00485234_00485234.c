/*
 * Decompiled function: FUN_00485234
 * Entry Point: 00485234
 * Size: 398 bytes
 */
#include "magic.h"


void FUN_00485234(int arg_1)

{
  int iVar1;
  int iVar2;
  char *str_2;
  int local_10;
  int local_c;
  
  g_OverworldWorldState = 0;
  for (local_c = 0; local_c < 0x50; local_c = local_c + 1) {
    iVar1 = *(int *)(&g_CardSlot_CardId + arg_1 * 0x5b20 + local_c * 0x120);
    if ((iVar1 != -1) && (((&g_CardSlot_Flags)[arg_1 * 0x5b20 + local_c * 0x120] & 2) == 0)) {
      strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar1 * 0x34);
      strcat(&g_OverworldWorldState,&DAT_005270b0);
      for (local_10 = 0; local_10 < (char)(&DAT_0051aebf)[iVar1 * 0x34]; local_10 = local_10 + 1) {
        iVar2 = FUN_00473cc5((&DAT_0051aebe)[iVar1 * 0x34]);
        strcat(&g_OverworldWorldState,(&PTR_DAT_00527080)[iVar2]);
      }
      if ((&DAT_0051aec0)[iVar1 * 0x34] != '\0') {
        str_2 = _itoa((int)(char)(&DAT_0051aec0)[iVar1 * 0x34],&DAT_005395f0,10);
        strcat(&g_OverworldWorldState,str_2);
      }
      strcat(&g_OverworldWorldState,&DAT_005270b4);
    }
  }
  FUN_00489710(&g_OverworldWorldState,10,10);
  return;
}


