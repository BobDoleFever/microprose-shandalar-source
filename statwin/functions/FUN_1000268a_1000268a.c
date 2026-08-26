/*
 * Decompiled function: StatWin_DisplayStatusScreen
 * Entry Point: 1000268a
 * Size: 1327 bytes
 */
#include "statwin.h"


void __cdecl StatWin_DisplayStatusScreen(int arg_1)

{
  int val_1;
  CPrintPreviewState *this;
  HWND hWnd;
  int32_t *unaff_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int *local_148;
  char local_140 [256];
  int *local_40;
  uint32_t local_3c;
  short local_38;
  short local_36;
  int32_t local_34;
  int32_t local_30;
  DWORD local_2c;
  HANDLE local_28;
  int32_t local_24;
  int local_20;
  int local_1c;
  int32_t local_18;
  int32_t local_14;
  int32_t local_10;
  uint8_t *puStack_c;
  int32_t local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10002bd1;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  local_3c = (uint32_t)*(uint8_t *)(arg_1 + 0x2d);
  local_24 = 5;
  thunk_FUN_1000432f(local_140,PTR_s___statwin__10011540,
                     (&PTR_s_cball00_avi_100115a8)[*(uint8_t *)(arg_1 + 0x2e)]);
  val_1 = thunk_FUN_100097b0(local_140,&local_30,&local_38,1);
  if (val_1 == 0) {
    thunk_FUN_1000432f(local_140,PTR_DAT_10011544,s_statscrn_wav_10011bc4);
    thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),local_30);
    thunk_FUN_10009a89(local_30,1);
    local_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + DAT_10011554;
    local_36 = DAT_10011556 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(DAT_10013174,&local_38);
    local_34 = local_30;
    if (*(int *)(arg_1 + local_3c * 4) != 0) {
      local_38 = (short)*(int32_t *)(&DAT_10011688 + local_3c * 0x10);
      local_36 = (short)*(int32_t *)(&DAT_1001168c + local_3c * 0x10);
      thunk_FUN_1000432f(local_140,PTR_s___statwin__10011540,
                         (&PTR_s_Whit_hit_avi_10011558)[local_3c]);
      val_1 = thunk_FUN_100097b0(local_140,&local_34,&local_38,5);
      if (val_1 == 0) {
        thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),local_34);
        thunk_FUN_10009a89(local_34,1);
        local_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + local_38;
        local_36 = local_36 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
        thunk_FUN_100099ba(local_34,&local_38);
      }
    }
    local_28 = GetCurrentProcess();
    local_2c = GetPriorityClass(local_28);
    thunk_FUN_1000432f(local_140,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
    thunk_FUN_1000308a(local_140);
    thunk_FUN_10009ace(local_30);
    thunk_FUN_10009824(local_30);
    *DAT_1001e878 = 1;
    DAT_10013180 = 0;
    while (val_1 = thunk_FUN_10009b0f(local_30), val_1 != 0) {
      val_1 = thunk_FUN_1000245c();
      if (val_1 != 0) {
        thunk_FUN_10009865(local_30);
        break;
      }
      Sleep(0);
    }
    *DAT_1001e878 = 0;
    thunk_FUN_10009ace(local_30);
    this = operator_new(0x18);
    local_8 = 0;
    if (this == (CPrintPreviewState *)0x0) {
      local_148 = (int *)0x0;
    }
    else {
      local_148 = (int *)CPrintPreviewState::CPrintPreviewState(this);
    }
    local_8 = 0xffffffff;
    local_40 = local_148;
    thunk_FUN_10004200(local_148,0xff00);
    thunk_FUN_1000432f(local_140,PTR_s_statwin__10012ac0,s_wht_mask_bmp_10011d88 + local_3c * 0x110)
    ;
    val_1 = local_3c * 0x110;
    local_20 = *(int *)(&DAT_10011e88 + val_1);
    local_1c = *(int *)(&DAT_10011e8c + val_1);
    local_18 = *(int32_t *)(&DAT_10011e90 + val_1);
    local_14 = *(int32_t *)(&DAT_10011e94 + val_1);
    val_1 = (**(code **)*local_40)(0,local_140,0x18);
    if (val_1 == 1) {
      (**(code **)(*local_40 + 0x18))
                (*(int32_t *)((int)DAT_100117a4 + 0xc),
                 *(int *)((int)DAT_100117a4 + 0x14) + local_20,
                 *(int *)((int)DAT_100117a4 + 0x18) + local_1c,local_18,local_14,0,0);
      if (local_40 != (int *)0x0) {
        thunk_FUN_10004250(local_40,1);
      }
      local_40 = (int *)0x0;
    }
    val_1 = thunk_FUN_10007b3b(DAT_100117a4,(int *)(&DAT_10011688 + local_3c * 0x10),local_3c);
    if (val_1 == 0) {
      thunk_FUN_10009a44(*(int32_t *)((int)DAT_100117a4 + 0x10),local_34);
      thunk_FUN_10004200(*(void **)((int)DAT_100117a4 + 0x10),0);
    }
    if (*(int *)(arg_1 + local_3c * 4) != 0) {
      thunk_FUN_10009824(local_34);
      DAT_10013180 = 0;
      while (val_1 = thunk_FUN_10009b0f(local_34), val_1 != 0) {
        val_1 = thunk_FUN_1000245c();
        if (val_1 != 0) {
          thunk_FUN_10009865(local_34);
          break;
        }
        Sleep(0);
      }
    }
    thunk_FUN_100049cf(DAT_100117a4,arg_1,1);
    thunk_FUN_100017b0(0xff);
    thunk_FUN_10009ace(local_34);
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    SetPriorityClass(local_28,local_2c);
    if (*(int *)(arg_1 + local_3c * 4) != 0) {
      thunk_FUN_100097f0(local_34);
    }
    thunk_FUN_100097f0(local_30);
    thunk_FUN_100016c1(0xff);
    lParam = 0;
    wParam = 0;
    Msg = 0x12;
    hWnd = (HWND)thunk_FUN_10001c1a();
    SendMessageA(hWnd,Msg,wParam,lParam);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


