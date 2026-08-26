/*
 * Decompiled function: thunk_FUN_10027871
 * Entry Point: 100012cb
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10027871(void)

{
  int iStack_88;
  char acStack_84 [128];
  
  sprintf(acStack_84,s_Do_you_wish_to_save__s__10045df8,&DAT_101cf340);
  iStack_88 = MessageBoxA(DAT_10176868,acStack_84,s_Deck_Maker_10045e10,0x23);
  if (iStack_88 == 6) {
    iStack_88 = SendMessageA(DAT_10176868,0x111,0xd,0);
  }
  return iStack_88;
}


