/*
 * Decompiled function: Palette_Subsystem_00495cde
 * Entry Point: 00495cde
 * Size: 526 bytes
 */
#include "magic.h"


void Palette_Subsystem_00495cde(MSG *arg_1)

{
  int iVar1;
  BOOL BVar2;
  LRESULT LVar3;
  uint uVar4;
  WPARAM local_8;
  
  iVar1 = TranslateAcceleratorA(g_MainAppHwnd,DAT_006ff4b0,arg_1);
  if ((iVar1 == 0) && (iVar1 = Palette_Subsystem_00495eec((int *)arg_1,0x4b), iVar1 == 0)) {
    if (((DAT_006b1578 == 0) ||
        (((BVar2 = IsWindowVisible(DAT_007006b0), BVar2 == 0 ||
          (LVar3 = SendMessageA(DAT_007006b0,0x402,0,0), LVar3 == 0)) || (arg_1->message != 0x102)))
        ) || (((arg_1->wParam != 0x20 && (arg_1->wParam != 0xd)) && (arg_1->wParam != 0x1b)))) {
      iVar1 = FUN_004088d0((int *)arg_1);
      if ((iVar1 == 0) &&
         (((Palette_Util_00496332(arg_1->hwnd,arg_1->message,arg_1->wParam,arg_1->lParam),
           arg_1->message != 0x201 && (arg_1->message != 0x204)) || (DAT_006b1578 != 0)))) {
        TranslateMessage(arg_1);
        DispatchMessageA(arg_1);
      }
    }
    else {
      uVar4 = SendMessageA(DAT_007006b0,0x402,0,0);
      local_8 = 0xfffffc18;
      if (((uVar4 & 2) == 0) || ((uVar4 & 1) == 0)) {
        if ((arg_1->wParam == 0xd) || (arg_1->wParam == 0x20)) {
          local_8 = 0;
        }
        else if ((arg_1->wParam == 0x1b) && ((uVar4 & 1) != 0)) {
          local_8 = DAT_0068a710;
        }
      }
      else if (arg_1->wParam == 0xd) {
        local_8 = DAT_00695ecc;
      }
      else if (arg_1->wParam == 0x1b) {
        local_8 = DAT_0068a710;
      }
      if (local_8 != 0xfffffc18) {
        SendMessageA(DAT_007006b0,0x401,local_8,0);
      }
    }
  }
  return;
}


