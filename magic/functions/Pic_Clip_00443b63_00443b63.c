/*
 * Decompiled function: Pic_Clip_00443b63
 * Entry Point: 00443b63
 * Size: 1636 bytes
 */
#include "magic.h"


undefined4 Pic_Clip_00443b63(HWND hwnd)

{
  undefined4 uVar1;
  tagRECT local_14;
  
  GetClientRect(hwnd,&local_14);
  DAT_006b1570 = CreateWindowExA(0,s_MAGIC_CueCardClass_00521bf4,&DAT_00521bf0,0x80000000,0,0,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_00695ea0 = CreateWindowExA(0,s_MAGIC_PlayerDirectiveClass_00521c0c,&DAT_00521c08,0x80000000,0,
                                 0,100,0x1e,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_007006b0 = CreateWindowExA(0,s_MAGIC_TellUserClass_00521c2c,&DAT_00521c28,0x80000001,0,0,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006a284c = CreateWindowExA(0,s_MAGICGAME_PhaseDisplayClass_00521c50,s_Phase_Display_00521c40,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x77,g_AppHInstance,(LPVOID)0x0);
  DAT_006a283c = CreateWindowExA(0,s_MAGICGAME_AttackPhaseDisplayClas_00521c84,
                                 s_Attack_Phase_Display_00521c6c,0x50000000,0,0,0,0,hwnd,(HMENU)0x78
                                 ,g_AppHInstance,(LPVOID)0x0);
  DAT_0069f744 = CreateWindowExA(0,s_MAGICGAME_FullCardClass_00521cb8,s_Full_size_card_00521ca8,
                                 0x90000000,0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff4a8 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00521cdc,s_Oppon_Life_00521cd0,0x50000000,0
                                 ,0,0,0,hwnd,(HMENU)0x65,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2530 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00521cfc,s_Player_Life_00521cf0,0x50000000,
                                 0,0,0,0,hwnd,(HMENU)0x66,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4928 = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00521d20,s_Oppon_Graveyard_00521d10,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6c,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2e10 = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00521d50,s_Player_Graveyard_00521d3c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6e,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff388 = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00521d7c,s_Oppon_Library_00521d6c,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6d,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe48c = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00521da4,s_Player_Library_00521d94,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6f,g_AppHInstance,(LPVOID)0x0);
  DAT_006ff560 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00521dc8,s_Oppon_Mana_00521dbc,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x68,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2d60 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00521df0,s_Player_Mana_00521de4,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x69,g_AppHInstance,(LPVOID)0x0);
  DAT_006a49f0 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e18,s_Oppon_Face_00521e0c,0x40000000,0
                                 ,0,0,0,hwnd,(HMENU)0x7c,g_AppHInstance,(LPVOID)0x0);
  DAT_0068a620 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00521e38,s_Player_Face_00521e2c,0x40000000,
                                 0,0,0,0,hwnd,(HMENU)0x7b,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4b60 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e58,s_Oppon_Chat_00521e4c,0x80800000,0
                                 ,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006b1574 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00521e78,s_Player_Chat_00521e6c,0x80800000,
                                 0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006a4924 = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ea0,s_Player_Territory_00521e8c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x79,g_AppHInstance,(LPVOID)0x0);
  DAT_006b2e2c = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00521ecc,s_Oppon_Territory_00521ebc,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x7a,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe400 = CreateWindowExA(0,s_MAGICGAME_HandClass_00521ef8,s_Opponent_Hand_00521ee8,
                                 0x82000000,(local_14.right * 0x50) / 100,
                                 (local_14.bottom * 0x28) / 100,0,0,hwnd,(HMENU)0x0,g_AppHInstance,
                                 (LPVOID)0x0);
  DAT_0069e720 = CreateWindowExA(0,s_MAGICGAME_HandClass_00521f18,s_Player_Hand_00521f0c,0x82000000,
                                 (local_14.right * 0x50) / 100,(local_14.bottom * 0x3c) / 100,0,0,
                                 hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006b3064 = CreateWindowExA(0,s_MAGICGAME_AttackClass_00521f34,s_Attack_00521f2c,0x82c00000,0,0
                                 ,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  DAT_006fe3fc = CreateWindowExA(0,s_MAGICGAME_SpellChainClass_00521f58,s_Spell_Chain_00521f4c,
                                 0x80c00000,0,0,0,0,hwnd,(HMENU)0x0,g_AppHInstance,(LPVOID)0x0);
  if ((((((DAT_00695ea0 == (HWND)0x0) || (DAT_0069f744 == (HWND)0x0)) || (DAT_006ff4a8 == (HWND)0x0)
        ) || (((DAT_006b2530 == (HWND)0x0 || (DAT_006ff560 == (HWND)0x0)) ||
              ((DAT_006b2d60 == (HWND)0x0 ||
               ((DAT_006a4928 == (HWND)0x0 || (DAT_006ff388 == (HWND)0x0)))))))) ||
      ((DAT_006b2e10 == (HWND)0x0 ||
       ((((((DAT_006fe48c == (HWND)0x0 || (DAT_006a4b60 == (HWND)0x0)) ||
           (DAT_006b1574 == (HWND)0x0)) ||
          ((DAT_006a284c == (HWND)0x0 || (DAT_006a283c == (HWND)0x0)))) ||
         ((DAT_006b3064 == (HWND)0x0 || ((DAT_006fe3fc == (HWND)0x0 || (DAT_006a4924 == (HWND)0x0)))
          ))) || (DAT_006b2e2c == (HWND)0x0)))))) ||
     ((((DAT_007006b0 == (HWND)0x0 || (DAT_006a49f0 == (HWND)0x0)) || (DAT_0068a620 == (HWND)0x0))
      || ((DAT_006fe400 == (HWND)0x0 || (DAT_0069e720 == (HWND)0x0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


