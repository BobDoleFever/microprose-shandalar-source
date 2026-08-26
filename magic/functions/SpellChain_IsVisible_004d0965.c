/*
 * Decompiled function: SpellChain_IsVisible
 * Entry Point: 004d0965
 * Size: 88 bytes
 */
#include "magic.h"


BOOL SpellChain_IsVisible(void)

{
  BOOL BVar1;
  BOOL BVar2;
  
  BVar1 = IsWindowVisible(DAT_00565940);
  if (BVar1 == 0) {
    BVar2 = IsWindowVisible(DAT_006fe3fc);
    if (BVar2 != 0) {
      SendMessageA(DAT_006fe3fc,0x111,0x65,0);
    }
  }
  return BVar1;
}


