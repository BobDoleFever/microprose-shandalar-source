/*
 * Decompiled function: FUN_10027871
 * Entry Point: 10027871
 * Size: 120 bytes
 */
#include "deckdll.h"


int FUN_10027871(void)

{
  int local_88;
  char local_84 [128];
  
  sprintf(local_84,s_Do_you_wish_to_save__s__10045df8,&DAT_101cf340);
  local_88 = MessageBoxA(DAT_10176868,local_84,s_Deck_Maker_10045e10,0x23);
  if (local_88 == 6) {
    local_88 = SendMessageA(DAT_10176868,0x111,0xd,0);
  }
  return local_88;
}


