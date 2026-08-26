/*
 * Decompiled function: FUN_0049ba93
 * Entry Point: 0049ba93
 * Size: 1859 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0049ba93(HWND hwnd,int arg2)

{
  bool bVar1;
  uint local_1cc [89];
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  uint local_58;
  undefined1 local_54;
  undefined1 local_53 [79];
  
  local_64 = 0;
  local_68 = 0;
  _DAT_005f76c8 = 1;
  DAT_00505988 = 0;
  DAT_00505984 = 1;
  bVar1 = (DAT_00663dfc & 0x10) != 0;
  if (bVar1) {
    DAT_00663dfc = DAT_00663dfc ^ 0x10;
    DAT_005f67ec = hwnd;
    arg2 = 2;
  }
  local_58 = (uint)!bVar1;
  if (arg2 == 1) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f62a0,(uint *)s_Congratulations__00505a04);
    DAT_005f76c0 = DAT_005f76c0 + 1;
    DAT_005f6c58 = DAT_005f6c58 + 1;
  }
  else if (arg2 == 0) {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f62a0,(uint *)s_Too_bad_00505a1c);
    DAT_005f6494 = DAT_005f6494 + 1;
    DAT_005f67e8 = DAT_005f67e8 + 1;
  }
  else if (arg2 == -1) {
    Mem_AllocOrFree_004d9630
              ((uint *)&DAT_005f62a0,(uint *)s_Oh_well____The_duel_ended_in_a_t_00505a28);
    DAT_005f67fc = DAT_005f67fc + 1;
  }
  else {
    Mem_AllocOrFree_004d9630((uint *)&DAT_005f62a0,(uint *)&DAT_00505a50);
  }
  if (local_58 != 0) {
    if (DAT_005f6c58 < DAT_005f628c) {
      if (DAT_005f67e8 < DAT_005f628c) {
        if (DAT_005f64b0 == 0) {
          FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_The_match_continues____00505b10);
          DAT_005f77ec = 1;
        }
        else {
          local_58 = 2;
          DAT_005f77ec = 0;
        }
      }
      else {
        DAT_005f77ec = 0;
        DAT_005f67e8 = 0;
        DAT_005f6c58 = 0;
        local_68 = 1;
        FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_You_lost_the_game__00505af8);
        local_58 = 2;
      }
    }
    else {
      DAT_005f67e8 = 0;
      DAT_005f6c58 = 0;
      local_64 = 1;
      DAT_005f77ec = 0;
      if ((DAT_005f64b0 == 0) && (DAT_005f6cb0 < DAT_005f649c)) {
        FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_You_won_the_match__00505a54);
        local_5c = (DAT_005f6498 + DAT_005f6cb0) % DAT_005f649c;
        if (DAT_005f649c <= local_5c) {
          local_5c = 0;
        }
        _sprintf(&DAT_005f66e0,s__s__s_dck_00505a6c,&DAT_00664a60,&DAT_005f6cc0 + local_5c * 0x80);
        Mem_AllocOrFree_004d9630((uint *)&DAT_00664b90,(uint *)(&DAT_005f6cc0 + local_5c * 0x80));
        FUN_0049f4d8(&DAT_005f66e0,&local_54);
        _sprintf((char *)local_1cc,s_Your_next_duel_is_against__s__00505a78,local_53);
        FUN_004d9640((uint *)&DAT_005f62a0,local_1cc);
        FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_Do_you_wish_to_continue__00505a9c);
        DAT_005f77ec = 1;
      }
      else {
        if (DAT_005f64b0 == 0) {
          FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_You_ve_successfully_run_the_gaun_00505ab8);
        }
        else {
          FUN_004d9640((uint *)&DAT_005f62a0,(uint *)s_You_ve_won_the_duel__00505ae0);
        }
        local_58 = 2;
      }
    }
  }
  local_60 = -1;
  while (local_60 == -1) {
    switch(local_58) {
    case 0:
      DAT_00681eac = 0x14;
      DAT_00681ea8 = 0x14;
      DAT_005f67e8 = 0;
      DAT_005f6c58 = 0;
      DAT_005f6cb0 = 1;
      DAT_005f6498 = 0;
      local_58 = FUN_0049c24f(DAT_005f67ec);
      DAT_00664730 = DAT_005f2f50;
      DAT_00664770 = DAT_005f64b0;
      DAT_00664774 = DAT_005f628c;
      DAT_00664778 = DAT_005f64a4;
      break;
    case 1:
      local_58 = FUN_0049c211(DAT_005f67ec);
      if (local_64 != 0) {
        DAT_005f6cb0 = DAT_005f6cb0 + 1;
      }
      if (local_68 != 0) {
        DAT_005f6cb0 = 1;
      }
      break;
    case 2:
      _DAT_005f76c8 = 0;
      local_58 = FUN_0049c211(DAT_005f67ec);
      if (local_64 != 0) {
        DAT_005f6cb0 = DAT_005f6cb0 + 1;
      }
      if (local_68 != 0) {
        DAT_005f6cb0 = 1;
      }
      break;
    default:
      local_60 = 0;
      break;
    case 4:
      local_60 = 1;
      if (((DAT_0066aaf4 != -1) && (DAT_0066aaf4 != -2)) && (DAT_00601578 == 0)) {
        _PlayerFace = FUN_00439659(&DAT_005f65d0,DAT_00505988,1,0xffffffff);
        if (_PlayerFace == 0) {
          MessageBoxA(hwnd,s_Your_selected_deck_is_not_a_lega_00505b38,s_Duel_Error_00505b2c,0x10);
          local_58 = 0;
          local_60 = -1;
        }
        else if (_PlayerFace == -1) {
          _sprintf((char *)local_1cc,s_Player_s_deck__s_is_invalid__00505b7c,&DAT_005f65d0);
          MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505b9c,0x10);
          local_58 = 0;
          local_60 = -1;
        }
        else if (_PlayerFace == -2) {
          _sprintf((char *)local_1cc,s_Player_s_deck__s_is_invalid__Wro_00505ba8,&DAT_005f65d0);
          MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505bdc,0x10);
          local_58 = 0;
          local_60 = -1;
        }
        else if (_PlayerFace == -3) {
          _sprintf((char *)local_1cc,s_Player_s_deck__s_is_invalid__Dec_00505be8,&DAT_005f65d0);
          MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505c2c,0x10);
          local_58 = 0;
          local_60 = -1;
        }
        else {
          _OpponFace = FUN_00439659(&DAT_005f66e0,DAT_00505984,1,0xffffffff);
          if (_OpponFace == 0) {
            _sprintf((char *)local_1cc,s_Error_loading_deck_file___s_00505c38,&DAT_005f66e0);
            MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505c54,0x10);
            local_58 = 0;
            local_60 = -1;
          }
          else if (_OpponFace == -1) {
            _sprintf((char *)local_1cc,s_Opponent_s_deck__s_is_invalid__00505c60,&DAT_005f66e0);
            MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505c80,0x10);
            local_58 = 0;
            local_60 = -1;
          }
          else if (_OpponFace == -2) {
            _sprintf((char *)local_1cc,s_Opponent_s_deck__s_is_invalid__W_00505c8c,&DAT_005f66e0);
            MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505cc4,0x10);
            local_58 = 0;
            local_60 = -1;
          }
          else if (_OpponFace == -3) {
            _sprintf((char *)local_1cc,s_Opponent_s_deck__s_is_invalid__D_00505cd0,&DAT_005f66e0);
            MessageBoxA(hwnd,(LPCSTR)local_1cc,s_Duel_Error_00505d18,0x10);
            local_58 = 0;
            local_60 = -1;
          }
        }
      }
      break;
    case 5:
      local_60 = 0;
    }
  }
  return local_60;
}


