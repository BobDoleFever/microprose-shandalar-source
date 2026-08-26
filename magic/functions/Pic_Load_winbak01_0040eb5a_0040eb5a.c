/*
 * Decompiled function: Pic_Load_winbak01_0040eb5a
 * Entry Point: 0040eb5a
 * Size: 835 bytes
 */
#include "magic.h"


void Pic_Load_winbak01_0040eb5a(int arg1,int arg2)

{
  uint arg_1;
  int iVar1;
  undefined4 arg_2;
  int iVar2;
  int arg_4;
  char *str_5;
  uint auStack_20 [5];
  int local_c;
  LPVOID local_8;
  
  for (local_c = 0; local_c < arg2; local_c = local_c + 1) {
    do {
      do {
        arg_1 = FUN_0040a1d2(g_MasterCardCount + -0x29);
        iVar1 = Pic_Subsystem_00452551(arg_1);
      } while (iVar1 < 3);
      iVar1 = FUN_00485005(arg_1);
    } while (iVar1 == 0);
    auStack_20[local_c] = arg_1;
    FUN_0050b206(arg_1,(int)(0x96 / (longlong)arg2) * local_c + 100,
                 (int)(10 / (longlong)arg2) * local_c + 100,1,&DAT_00519184);
  }
  local_8 = (LPVOID)Adventure_CheckMonsterEncounter(0,arg1);
  strcpy(&g_OverworldWorldState,s_You_encounter_00519188);
  Adventure_FormatNewsString((int)local_8,1,0);
  if (arg1 == 0xd) {
    strcat(&g_OverworldWorldState,s_Genie_00519198);
  }
  else if (arg1 == 0x10) {
    strcat(&g_OverworldWorldState,s_Spectre_005191a0);
  }
  else if (arg1 == 0x12) {
    strcat(&g_OverworldWorldState,s_Dragon_005191ac);
  }
  else {
    strcat(&g_OverworldWorldState,s_warily_005191b4);
  }
  strcat(&g_OverworldWorldState,s_guarding_a_horde_of_valuable_spe_005191bc);
  iVar1 = FUN_00489710(&g_OverworldWorldState,0x5a,100);
  if (iVar1 == 1) {
    arg_2 = Pic_Subsystem_0045268f(*(int *)(&DAT_0052262c + (int)local_8 * 0x44));
    FUN_004909d3((int)local_8,arg_2,0,-1);
    DAT_006b2d64 = FUN_00473cc5((&DAT_0052262b)[(int)local_8 * 0x44]);
    DAT_0063ee24 = 0;
    DAT_00695df0 = 3;
    iVar1 = Pic_Load_0044ef70(arg_2,local_8);
    if (iVar1 != 0) {
      Mem_AllocOrFree_00510de0(1,s_winbak01_pic_00519214);
      Adventure_Audio_PlayDuelIntro(1);
      Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,
                         (int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c);
      for (local_c = 0; local_c < arg2; local_c = local_c + 1) {
        iVar1 = (int)(300 / (longlong)(arg2 + 1));
        iVar2 = Pic_Subsystem_00452551(auStack_20[local_c]);
        strcpy(&g_OverworldWorldState,(char *)(&DAT_0052b73c)[iVar2]);
        str_5 = &g_OverworldWorldState;
        arg_4 = 1;
        iVar2 = FUN_0040a1d2(10);
        FUN_0050b206(auStack_20[local_c],(iVar1 * local_c + 0x6f) - ((arg2 + -1) * iVar1) / 2,
                     iVar2 + 0x10,arg_4,str_5);
        local_8 = (LPVOID)Pic_Subsystem_00451e40(auStack_20[local_c]);
        if (local_8 != (LPVOID)0xffffffff) {
          *(uint *)(&deck + (int)local_8 * 4) = *(uint *)(&deck + (int)local_8 * 4) | 0x4000;
        }
      }
      *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
      FUN_004896be(s_Won_These_Cards_00519224,0x40,0x96);
    }
    Pic_Subsystem_00423c82(0x10);
  }
  return;
}


