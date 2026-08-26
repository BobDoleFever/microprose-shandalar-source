/*
 * Decompiled function: thunk_FUN_1000268a
 * Entry Point: 1000105f
 * Size: 5 bytes
 */
#include "statwin.h"


void __cdecl thunk_FUN_1000268a(int arg_1)

{
  int val_1;
  CPrintPreviewState *this;
  HWND hWnd;
  int32_t *unaff_FS_OFFSET;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int *piStack_148;
  char acStack_140 [256];
  int *piStack_40;
  uint32_t uStack_3c;
  short sStack_38;
  short sStack_36;
  int32_t uStack_34;
  int32_t uStack_30;
  DWORD DStack_2c;
  HANDLE pvStack_28;
  int32_t uStack_24;
  int iStack_20;
  int iStack_1c;
  int32_t uStack_18;
  int32_t uStack_14;
  int32_t uStack_10;
  uint8_t *puStack_c;
  int32_t uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10002bd1;
  uStack_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_10;
  uStack_3c = (uint32_t)*(uint8_t *)(arg_1 + 0x2d);
  uStack_24 = 5;
  thunk_FUN_1000432f(acStack_140,PTR_s___statwin__10011540,
                     (&PTR_s_cball00_avi_100115a8)[*(uint8_t *)(arg_1 + 0x2e)]);
  val_1 = thunk_FUN_100097b0(acStack_140,&uStack_30,&sStack_38,1);
  if (val_1 == 0) {
    thunk_FUN_1000432f(acStack_140,PTR_DAT_10011544,s_statscrn_wav_10011bc4);
    thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),uStack_30);
    thunk_FUN_10009a89(uStack_30,1);
    sStack_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + DAT_10011554;
    sStack_36 = DAT_10011556 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
    thunk_FUN_100099ba(DAT_10013174,&sStack_38);
    uStack_34 = uStack_30;
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      sStack_38 = (short)*(int32_t *)(&DAT_10011688 + uStack_3c * 0x10);
      sStack_36 = (short)*(int32_t *)(&DAT_1001168c + uStack_3c * 0x10);
      thunk_FUN_1000432f(acStack_140,PTR_s___statwin__10011540,
                         (&PTR_s_Whit_hit_avi_10011558)[uStack_3c]);
      val_1 = thunk_FUN_100097b0(acStack_140,&uStack_34,&sStack_38,5);
      if (val_1 == 0) {
        thunk_FUN_100099ff(*(int32_t *)((int)DAT_100117a4 + 0xc),uStack_34);
        thunk_FUN_10009a89(uStack_34,1);
        sStack_38 = (short)*(int32_t *)((int)DAT_100117a4 + 0x14) + sStack_38;
        sStack_36 = sStack_36 + (short)*(int32_t *)((int)DAT_100117a4 + 0x18);
        thunk_FUN_100099ba(uStack_34,&sStack_38);
      }
    }
    pvStack_28 = GetCurrentProcess();
    DStack_2c = GetPriorityClass(pvStack_28);
    thunk_FUN_1000432f(acStack_140,PTR_DAT_10011544,PTR_s_statscrn_wav_10011548);
    thunk_FUN_1000308a(acStack_140);
    thunk_FUN_10009ace(uStack_30);
    thunk_FUN_10009824(uStack_30);
    *DAT_1001e878 = 1;
    DAT_10013180 = 0;
    while (val_1 = thunk_FUN_10009b0f(uStack_30), val_1 != 0) {
      val_1 = thunk_FUN_1000245c();
      if (val_1 != 0) {
        thunk_FUN_10009865(uStack_30);
        break;
      }
      Sleep(0);
    }
    *DAT_1001e878 = 0;
    thunk_FUN_10009ace(uStack_30);
    this = operator_new(0x18);
    uStack_8 = 0;
    if (this == (CPrintPreviewState *)0x0) {
      piStack_148 = (int *)0x0;
    }
    else {
      piStack_148 = (int *)CPrintPreviewState::CPrintPreviewState(this);
    }
    uStack_8 = 0xffffffff;
    piStack_40 = piStack_148;
    thunk_FUN_10004200(piStack_148,0xff00);
    thunk_FUN_1000432f(acStack_140,PTR_s_statwin__10012ac0,
                       s_wht_mask_bmp_10011d88 + uStack_3c * 0x110);
    val_1 = uStack_3c * 0x110;
    iStack_20 = *(int *)(&DAT_10011e88 + val_1);
    iStack_1c = *(int *)(&DAT_10011e8c + val_1);
    uStack_18 = *(int32_t *)(&DAT_10011e90 + val_1);
    uStack_14 = *(int32_t *)(&DAT_10011e94 + val_1);
    val_1 = (**(code **)*piStack_40)(0,acStack_140,0x18);
    if (val_1 == 1) {
      (**(code **)(*piStack_40 + 0x18))
                (*(int32_t *)((int)DAT_100117a4 + 0xc),
                 *(int *)((int)DAT_100117a4 + 0x14) + iStack_20,
                 *(int *)((int)DAT_100117a4 + 0x18) + iStack_1c,uStack_18,uStack_14,0,0);
      if (piStack_40 != (int *)0x0) {
        thunk_FUN_10004250(piStack_40,1);
      }
      piStack_40 = (int *)0x0;
    }
    val_1 = thunk_FUN_10007b3b(DAT_100117a4,(int *)(&DAT_10011688 + uStack_3c * 0x10),uStack_3c);
    if (val_1 == 0) {
      thunk_FUN_10009a44(*(int32_t *)((int)DAT_100117a4 + 0x10),uStack_34);
      thunk_FUN_10004200(*(void **)((int)DAT_100117a4 + 0x10),0);
    }
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      thunk_FUN_10009824(uStack_34);
      DAT_10013180 = 0;
      while (val_1 = thunk_FUN_10009b0f(uStack_34), val_1 != 0) {
        val_1 = thunk_FUN_1000245c();
        if (val_1 != 0) {
          thunk_FUN_10009865(uStack_34);
          break;
        }
        Sleep(0);
      }
    }
    thunk_FUN_100049cf(DAT_100117a4,arg_1,1);
    thunk_FUN_100017b0(0xff);
    thunk_FUN_10009ace(uStack_34);
    do {
      val_1 = thunk_FUN_1000245c();
    } while (val_1 == 0);
    SetPriorityClass(pvStack_28,DStack_2c);
    if (*(int *)(arg_1 + uStack_3c * 4) != 0) {
      thunk_FUN_100097f0(uStack_34);
    }
    thunk_FUN_100097f0(uStack_30);
    thunk_FUN_100016c1(0xff);
    lParam = 0;
    wParam = 0;
    Msg = 0x12;
    hWnd = (HWND)thunk_FUN_10001c1a();
    SendMessageA(hWnd,Msg,wParam,lParam);
  }
  *unaff_FS_OFFSET = uStack_10;
  return;
}


