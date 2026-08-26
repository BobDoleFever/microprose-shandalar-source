/*
 * Decompiled function: Pic_Subsystem_0044b460
 * Entry Point: 0044b460
 * Size: 985 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044b460(void)

{
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 local_10;
  int local_c;
  
  DVar1 = GetTickCount();
  srand(DVar1);
  uVar2 = Mem_AllocOrFree_0050ce90(s_misc_exe_005239f4,0);
  Mem_AllocOrFree_0050ce80(uVar2);
  uVar2 = Mem_AllocOrFree_0050ce90(s_mgraphic_exe_00523a0c,0x523a00);
  Mem_AllocOrFree_0050ce80(uVar2);
  uVar2 = Mem_AllocOrFree_0050ce90(s_nsound_cvl_00523a1c,0);
  Mem_AllocOrFree_0050ce80(uVar2);
  if (DAT_00522458 == 0x280) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523a28;
    pcVar4 = s_magim____ttf_00523a38;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0300m__ttf_00523a58,s_Zurich_Cn_BT_00523a48,400,0);
  }
  else if (DAT_00522458 == 800) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523a68;
    pcVar4 = s_magim____ttf_00523a78;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    FUN_0050f1e0(1,0x10,s_tt0127m__ttf_00523a98,s_Benguiat_Bk_BT_00523a88,100,0);
  }
  else if (DAT_00522458 == 0x400) {
    DVar1 = 1;
    iVar6 = 700;
    pcVar5 = s_MagicMedieval_00523aa8;
    pcVar4 = s_magim____ttf_00523ab8;
    iVar3 = Ai_Util_004c3bc4(0x1c);
    FUN_0050f1e0(5,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    DVar1 = 0;
    iVar6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ac8;
    pcVar4 = s_tt0127m__ttf_00523ad8;
    iVar3 = Ai_Util_004c3bc4(0xc);
    FUN_0050f1e0(1,iVar3,pcVar4,pcVar5,iVar6,DVar1);
    DVar1 = 0;
    iVar6 = 100;
    pcVar5 = s_Benguiat_Bk_BT_00523ae8;
    pcVar4 = s_tt0127m__ttf_00523af8;
    iVar3 = Ai_Util_004c3bc4(0x11);
    FUN_0050f1e0(4,iVar3,pcVar4,pcVar5,iVar6,DVar1);
  }
  thunk_FUN_0050cef0(0);
  Catalog_LoadPaletteMap(s_todpal_tr_00523b08,(char *)0x0);
  for (local_c = 0; local_c < 3; local_c = local_c + 1) {
    if ((local_c == 1) && (*(int *)(DAT_0070a850 + 0x20) < 0x401)) {
      local_10 = FUN_0050d0b0(1,0x400,800,8);
    }
    else {
      local_10 = Mem_AllocOrFree_0050cec0(local_c);
    }
    FUN_0050d370(local_c,local_10);
  }
  iVar7 = 8;
  iVar3 = Ai_Util_004c3bc4(0x1e0);
  iVar6 = Ai_Util_004c3bc4(0x148);
  iVar6 = (iVar3 - iVar6) + 3;
  iVar3 = Ai_Util_004c3bc4(0x280);
  uVar2 = FUN_0050d0b0(3,iVar3,iVar6,iVar7);
  FUN_0050d370(3,uVar2);
  iVar7 = 8;
  iVar3 = Ai_Util_004c3bc4(0x148);
  iVar6 = Ai_Util_004c3bc4(0x40);
  uVar2 = FUN_0050d0b0(5,iVar6,iVar3,iVar7);
  FUN_0050d370(5,uVar2);
  uVar2 = Ai_Util_004c3bc4(0x280);
  *(undefined4 *)(PTR_DAT_005174bc + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceWork + 0xc) = *(undefined4 *)(PTR_DAT_005174bc + 0xc);
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0xc) = *(undefined4 *)(g_DisplaySurfaceWork + 0xc);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0xc) = *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0xc);
  uVar2 = Ai_Util_004c3bc4(0x1e0);
  *(undefined4 *)(g_DisplaySurfaceWork + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x10) = *(undefined4 *)(g_DisplaySurfaceWork + 0xc);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x10) =
       *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x10);
  iVar3 = Ai_Util_004c3bc4(0x1e0);
  iVar6 = Ai_Util_004c3bc4(0x148);
  *(int *)(PTR_DAT_005174bc + 0x10) = iVar3 - iVar6;
  uVar2 = Ai_Util_004c3bc4(0x148);
  *(undefined4 *)(PTR_DAT_005174e4 + 0x10) = uVar2;
  uVar2 = Ai_Util_004c3bc4(0x40);
  *(undefined4 *)(PTR_DAT_005174e4 + 0xc) = uVar2;
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  FUN_0050d4e0(0);
  DAT_005239ec = Mem_AllocOrFree_005121d0();
  do {
    Adventure_EnterTownLocation();
  } while (DAT_006fe3f0 == 0);
  FUN_0050f350(5);
  if (DAT_005239ec != 0) {
    Mem_AllocOrFree_005121e0();
  }
                    /* WARNING: Subroutine does not return */
  exit(1);
}


