/*
 * Decompiled function: FUN_1002e266
 * Entry Point: 1002e266
 * Size: 1566 bytes
 */
#include "deckdll.h"


void FUN_1002e266(void)

{
  int val_1;
  int local_c;
  
  val_1 = thunk_FUN_10034b40(s_menus_10046340,s_FILTERS_10046338);
  if (val_1 != -1) {
    DAT_1013f1ac = CreatePopupMenu();
    for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
      AppendMenuA(DAT_1013f1ac,0,local_c + 100,&DAT_1016e4c0 + local_c * 0x80);
    }
  }
  if (((uint8_t)DAT_10158748 & 0x40) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_10046350,&DAT_10046348);
    if (val_1 != -1) {
      DAT_1013f1cc = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1cc,0,local_c + 1,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  val_1 = thunk_FUN_10034b40(s_menus_10046360,&DAT_10046358);
  if (val_1 != -1) {
    DAT_1013f1d0 = CreatePopupMenu();
    for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
      AppendMenuA(DAT_1013f1d0,0,local_c + 4,&DAT_1016e4c0 + local_c * 0x80);
    }
  }
  val_1 = thunk_FUN_10034b40(s_menus_10046374,s_ARTIFACT_10046368);
  if (val_1 != -1) {
    DAT_1013f1e0 = CreatePopupMenu();
    for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
      AppendMenuA(DAT_1013f1e0,0,local_c + 7,&DAT_1016e4c0 + local_c * 0x80);
    }
  }
  val_1 = thunk_FUN_10034b40(s_menus_10046388,s_CREATURE_1004637c);
  if (val_1 != -1) {
    DAT_1013f1c4 = CreatePopupMenu();
    if ((DAT_1017646c & 2) == 0) {
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        if (local_c != 1) {
          AppendMenuA(DAT_1013f1c4,0,local_c + 9,&DAT_1016e4c0 + local_c * 0x80);
        }
      }
      InsertMenuA(DAT_1013f1c4,local_c - 2,0x400,0x800,(LPCSTR)0x0);
    }
    else {
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1c4,0,local_c + 9,&DAT_1016e4c0 + local_c * 0x80);
      }
      InsertMenuA(DAT_1013f1c4,local_c - 1,0x400,0x800,(LPCSTR)0x0);
    }
  }
  val_1 = thunk_FUN_10034b40(s_menus_1004639c,s_ENCHANTMENT_10046390);
  if (val_1 != -1) {
    DAT_1013f1dc = CreatePopupMenu();
    for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
      AppendMenuA(DAT_1013f1dc,0,local_c + 0xd,&DAT_1016e4c0 + local_c * 0x80);
    }
  }
  if (((uint8_t)DAT_1015874c & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_100463b0,s_CASTCOST_100463a4);
    if (val_1 != -1) {
      DAT_1013f1e4 = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1e4,0,local_c + 0x13,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  if (((uint8_t)DAT_10158750 & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_100463c0,s_POWER_100463b8);
    if (val_1 != -1) {
      DAT_1013f1d8 = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1d8,0,local_c + 0x17,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  if (((uint8_t)DAT_10158754 & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_100463d4,s_TOUGHNESS_100463c8);
    if (val_1 != -1) {
      DAT_1013f1e8 = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1e8,0,local_c + 0x1a,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  if (((uint8_t)DAT_10158758 & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_100463e4,s_ABILITY_100463dc);
    if (val_1 != -1) {
      DAT_1013f1d4 = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1d4,0,local_c + 0x1d,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
    InsertMenuA(DAT_1013f1d4,2,0x400,0x800,(LPCSTR)0x0);
  }
  if (((uint8_t)DAT_1015875c & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_100463f4,s_RARITY_100463ec);
    if (val_1 != -1) {
      DAT_1013f1ec = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1ec,0,local_c + 0x2c,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  if (((uint8_t)DAT_10158760 & 1) != 0) {
    val_1 = thunk_FUN_10034b40(s_menus_10046404,s_ARTIST_100463fc);
    if (val_1 != -1) {
      DAT_1013f1c8 = CreatePopupMenu();
      for (local_c = 0; local_c < val_1; local_c = local_c + 1) {
        AppendMenuA(DAT_1013f1c8,0,local_c + 0x2f,&DAT_1016e4c0 + local_c * 0x80);
      }
    }
  }
  return;
}


