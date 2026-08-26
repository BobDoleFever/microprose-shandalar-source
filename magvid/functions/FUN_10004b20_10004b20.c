/*
 * Decompiled function: DeckDll_SideboardWndProc
 * Entry Point: 10004b20
 * Size: 57 bytes
 */
#include "magvid.h"


int * __thiscall DeckDll_SideboardWndProc(void *this,uint8_t arg_2)

{
  thunk_FUN_10001926(this);
  if ((arg_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}


