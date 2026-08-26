/*
 * Decompiled function: thunk_FUN_10027036
 * Entry Point: 100015be
 * Size: 5 bytes
 */
#include "deckdll.h"


void thunk_FUN_10027036(void)

{
  char acStack_54 [80];
  
  sprintf(acStack_54,s_Stats___d_cards__10045d5c,DAT_101cece0);
  SetWindowTextA(DAT_101cf948,acStack_54);
  InvalidateRect(DAT_101cf948,(RECT *)0x0,0);
  return;
}


