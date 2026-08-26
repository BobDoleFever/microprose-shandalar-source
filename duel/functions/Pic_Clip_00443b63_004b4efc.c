/*
 * Decompiled function: Pic_Clip_00443b63
 * Entry Point: 004b4efc
 * Size: 1636 bytes
 */
#include "duel.h"


undefined4 Pic_Clip_00443b63(HWND hwnd)

{
  undefined4 uVar1;
  tagRECT local_14;
  
  GetClientRect(hwnd,&local_14);
  DAT_00618150 = CreateWindowExA(0,s_MAGIC_CueCardClass_00506b20,&DAT_00506b1c,0x80000000,0,0,0,0,
                                 hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_0060cc6c = CreateWindowExA(0,s_MAGIC_PlayerDirectiveClass_00506b38,&DAT_00506b34,0x80000000,0,
                                 0,100,0x1e,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00664d90 = CreateWindowExA(0,s_MAGIC_TellUserClass_00506b58,&DAT_00506b54,0x80000001,0,0,0,0,
                                 hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_006152ec = CreateWindowExA(0,s_MAGICGAME_PhaseDisplayClass_00506b7c,s_Phase_Display_00506b6c,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x77,DAT_00664680,(LPVOID)0x0);
  DAT_006152e8 = CreateWindowExA(0,s_MAGICGAME_AttackPhaseDisplayClas_00506bb0,
                                 s_Attack_Phase_Display_00506b98,0x50000000,0,0,0,0,hwnd,(HMENU)0x78
                                 ,DAT_00664680,(LPVOID)0x0);
  DAT_006152e0 = CreateWindowExA(0,s_MAGICGAME_FullCardClass_00506be4,s_Full_size_card_00506bd4,
                                 0x90000000,0,0,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00664c28 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00506c08,s_Oppon_Life_00506bfc,0x50000000,0
                                 ,0,0,0,hwnd,(HMENU)0x65,DAT_00664680,(LPVOID)0x0);
  DAT_00618160 = CreateWindowExA(0,s_MAGICGAME_LifeClass_00506c28,s_Player_Life_00506c1c,0x50000000,
                                 0,0,0,0,hwnd,(HMENU)0x66,DAT_00664680,(LPVOID)0x0);
  DAT_0061737c = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00506c4c,s_Oppon_Graveyard_00506c3c,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6c,DAT_00664680,(LPVOID)0x0);
  DAT_00618978 = CreateWindowExA(0,s_MAGICGAME_GraveyardClass_00506c7c,s_Player_Graveyard_00506c68,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x6e,DAT_00664680,(LPVOID)0x0);
  DAT_00664c04 = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00506ca8,s_Oppon_Library_00506c98,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6d,DAT_00664680,(LPVOID)0x0);
  DAT_00663e68 = CreateWindowExA(0,s_MAGICGAME_LibraryClass_00506cd0,s_Player_Library_00506cc0,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x6f,DAT_00664680,(LPVOID)0x0);
  DAT_00664c34 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00506cf4,s_Oppon_Mana_00506ce8,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x68,DAT_00664680,(LPVOID)0x0);
  DAT_00618950 = CreateWindowExA(0,s_MAGICGAME_ManaSummaryClass_00506d1c,s_Player_Mana_00506d10,
                                 0x50000000,0,0,0,0,hwnd,(HMENU)0x69,DAT_00664680,(LPVOID)0x0);
  DAT_00617438 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00506d44,s_Oppon_Face_00506d38,0x40000000,0
                                 ,0,0,0,hwnd,(HMENU)0x7c,DAT_00664680,(LPVOID)0x0);
  DAT_00601550 = CreateWindowExA(0,s_MAGICGAME_FaceClass_00506d64,s_Player_Face_00506d58,0x40000000,
                                 0,0,0,0,hwnd,(HMENU)0x7b,DAT_00664680,(LPVOID)0x0);
  DAT_00617578 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00506d84,s_Oppon_Chat_00506d78,0x80800000,0
                                 ,0,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00618154 = CreateWindowExA(0,s_MAGICGAME_ChatClass_00506da4,s_Player_Chat_00506d98,0x80800000,
                                 0,0,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00617378 = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00506dcc,s_Player_Territory_00506db8,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x79,DAT_00664680,(LPVOID)0x0);
  DAT_00618988 = CreateWindowExA(0,s_MAGICGAME_TerritoryClass_00506df8,s_Oppon_Territory_00506de8,
                                 0x52000000,0,0,0,0,hwnd,(HMENU)0x7a,DAT_00664680,(LPVOID)0x0);
  DAT_00663df4 = CreateWindowExA(0,s_MAGICGAME_HandClass_00506e24,s_Opponent_Hand_00506e14,
                                 0x82000000,(local_14.right * 0x50) / 100,
                                 (local_14.bottom * 0x28) / 100,0,0,hwnd,(HMENU)0x0,DAT_00664680,
                                 (LPVOID)0x0);
  DAT_006152b0 = CreateWindowExA(0,s_MAGICGAME_HandClass_00506e44,s_Player_Hand_00506e38,0x82000000,
                                 (local_14.right * 0x50) / 100,(local_14.bottom * 0x3c) / 100,0,0,
                                 hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00618ab0 = CreateWindowExA(0,s_MAGICGAME_AttackClass_00506e60,s_Attack_00506e58,0x82c00000,0,0
                                 ,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  DAT_00663df0 = CreateWindowExA(0,s_MAGICGAME_SpellChainClass_00506e84,s_Spell_Chain_00506e78,
                                 0x80c00000,0,0,0,0,hwnd,(HMENU)0x0,DAT_00664680,(LPVOID)0x0);
  if ((((((DAT_0060cc6c == (HWND)0x0) || (DAT_006152e0 == (HWND)0x0)) || (DAT_00664c28 == (HWND)0x0)
        ) || (((DAT_00618160 == (HWND)0x0 || (DAT_00664c34 == (HWND)0x0)) ||
              ((DAT_00618950 == (HWND)0x0 ||
               ((DAT_0061737c == (HWND)0x0 || (DAT_00664c04 == (HWND)0x0)))))))) ||
      ((DAT_00618978 == (HWND)0x0 ||
       ((((((DAT_00663e68 == (HWND)0x0 || (DAT_00617578 == (HWND)0x0)) ||
           (DAT_00618154 == (HWND)0x0)) ||
          ((DAT_006152ec == (HWND)0x0 || (DAT_006152e8 == (HWND)0x0)))) ||
         ((DAT_00618ab0 == (HWND)0x0 || ((DAT_00663df0 == (HWND)0x0 || (DAT_00617378 == (HWND)0x0)))
          ))) || (DAT_00618988 == (HWND)0x0)))))) ||
     ((((DAT_00664d90 == (HWND)0x0 || (DAT_00617438 == (HWND)0x0)) || (DAT_00601550 == (HWND)0x0))
      || ((DAT_00663df4 == (HWND)0x0 || (DAT_006152b0 == (HWND)0x0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


