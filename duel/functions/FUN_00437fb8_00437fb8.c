/*
 * Decompiled function: FUN_00437fb8
 * Entry Point: 00437fb8
 * Size: 526 bytes
 */
#include "duel.h"


void FUN_00437fb8(MSG *arg_1)

{
  int iVar1;
  BOOL BVar2;
  LRESULT LVar3;
  uint uVar4;
  WPARAM local_8;
  
  iVar1 = TranslateAcceleratorA(DAT_00618990,DAT_00664c2c,arg_1);
  if ((iVar1 == 0) && (iVar1 = FUN_004381c6((int *)arg_1,0x4b), iVar1 == 0)) {
    if (((DAT_00618158 == 0) ||
        (((BVar2 = IsWindowVisible(DAT_00664d90), BVar2 == 0 ||
          (LVar3 = SendMessageA(DAT_00664d90,0x402,0,0), LVar3 == 0)) || (arg_1->message != 0x102)))
        ) || (((arg_1->wParam != 0x20 && (arg_1->wParam != 0xd)) && (arg_1->wParam != 0x1b)))) {
      iVar1 = FUN_00491ef3((int *)arg_1);
      if ((iVar1 == 0) &&
         (((Mem_AllocOrFree_0043860c(arg_1->hwnd,arg_1->message,arg_1->wParam,arg_1->lParam),
           arg_1->message != 0x201 && (arg_1->message != 0x204)) || (DAT_00618158 != 0)))) {
        TranslateMessage(arg_1);
        DispatchMessageA(arg_1);
      }
    }
    else {
      uVar4 = SendMessageA(DAT_00664d90,0x402,0,0);
      local_8 = 0xfffffc18;
      if (((uVar4 & 2) == 0) || ((uVar4 & 1) == 0)) {
        if ((arg_1->wParam == 0xd) || (arg_1->wParam == 0x20)) {
          local_8 = 0;
        }
        else if ((arg_1->wParam == 0x1b) && ((uVar4 & 1) != 0)) {
          local_8 = DAT_00601614;
        }
      }
      else if (arg_1->wParam == 0xd) {
        local_8 = DAT_0060cc78;
      }
      else if (arg_1->wParam == 0x1b) {
        local_8 = DAT_00601614;
      }
      if (local_8 != 0xfffffc18) {
        SendMessageA(DAT_00664d90,0x401,local_8,0);
      }
    }
  }
  return;
}


