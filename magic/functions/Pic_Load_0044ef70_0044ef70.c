/*
 * Decompiled function: Pic_Load_0044ef70
 * Entry Point: 0044ef70
 * Size: 607 bytes
 */
#include "magic.h"


/* WARNING: Removing unreachable block (ram,0x0044f1b3) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Pic_Load_0044ef70(undefined4 arg1,LPVOID out_buffer)

{
  int nPriority;
  HANDLE hHandle;
  int local_10;
  DWORD local_c [2];
  
  _DAT_0063ee14 = 1;
  Palette_Subsystem_00496eaf();
  local_c[1] = 2;
  nPriority = GetThreadPriority(DAT_00626820);
  SetThreadPriority(DAT_00626820,-0xf);
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,Palette_Subsystem_004958b1,out_buffer,0,
                         local_c);
  WaitForSingleObject(hHandle,0xffffffff);
  GetExitCodeThread(hHandle,local_c + 1);
  CloseHandle(hHandle);
  SetThreadPriority(DAT_00626820,nPriority);
  if (DAT_0063ee80 == 0) {
    for (local_10 = 0; local_10 < 500; local_10 = local_10 + 1) {
      if (*(int *)(&deck + local_10 * 4) != -1) {
        *(uint *)(&deck + local_10 * 4) = *(uint *)(&deck + local_10 * 4) & 0xffff7fff;
      }
    }
  }
  else {
    OutputDebugStringA(s_OneDeck_ONEDECK_ONE_DECK_00523dfc);
  }
  DAT_00522454 = 0xffffffff;
  DAT_006b2fe0 = 0xffffffff;
  DAT_0068a64c = 0xffffffff;
  g_IsAiThinking = 0;
  for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
    *(undefined4 *)(&g_PlayerLifeTotals + local_10 * 4) = 8;
  }
  if (DAT_0067a6b0 != 0) {
    memcpy(&deck,&DAT_00679ee0,2000);
  }
  DAT_0063ee18 = 0;
  _DAT_0063ee14 = 1;
  DAT_006a5f20 = 0;
  DAT_006a48e0 = 0;
  DAT_006ff2d8 = 0xffffffff;
  g_ScWillyScore = 0;
  ShowWindow(_hwndScreen,5);
  SetForegroundWindow(_hwndScreen);
  BringWindowToTop(_hwndScreen);
  SetFocus(_hwndScreen);
  LoadPalNoPic(s_advfac64_pic_00523e18);
  Catalog_LoadPaletteMap(s_todpal_tr_00523e28,(char *)0x0);
  SelectPalette(*(HDC *)(DAT_0070a850 + 4),_hLibPal,0);
  RealizePalette(*(HDC *)(DAT_0070a850 + 4));
  Adventure_Audio_PlayFootstep();
  DAT_00627a7c = 0;
  DAT_00522454 = 0xffffffff;
  return DAT_00627a80;
}


