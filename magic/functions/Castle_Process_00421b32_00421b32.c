/*
 * Decompiled function: Castle_Process_00421b32
 * Entry Point: 00421b32
 * Size: 3986 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 Castle_Process_00421b32(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  DWORD arg_5;
  uint arg_4;
  uint arg_2;
  undefined4 arg_2_00;
  int arg_2_01;
  int *arg_6;
  char *str_6;
  char *str_7;
  int local_374;
  uint local_368;
  undefined4 local_364 [200];
  int local_44;
  int local_40 [9];
  int *local_1c;
  int local_18;
  int local_14;
  int local_c;
  uint local_8;
  
  local_40[0] = 4;
  local_40[1] = 0;
  local_40[2] = 0;
  local_40[3] = 800;
  local_40[4] = 600;
  local_40[5] = 1;
  local_40[6] = 0xf;
  local_40[7] = 4;
  local_40[8] = 0;
  local_1c = local_40;
  local_14 = 0xb7;
  local_c = 0x1c;
  FUN_005112b0(0,(short)DAT_00530d9c);
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 4;
  *(undefined4 *)(g_DisplaySurfaceWork + 0x20) = 4;
  Surface_FillRect((int *)g_DisplaySurfaceScreen,0,0,DAT_00522458,DAT_0052245c,0);
  LoadPalNoPic(s_advfac64_pic_0051ac9c);
  Sprite_LoadAll(local_364,s_statbutt_spr_0051acac);
  local_44 = 0;
  for (local_368 = 0; local_368 < 5; local_368 = local_368 + 1) {
    (&DAT_00538a10)[local_368] = (void *)local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538a88 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538a98 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  for (local_368 = 0; iVar1 = local_44, local_368 < 3; local_368 = local_368 + 1) {
    *(undefined4 *)(&DAT_00538aa8 + local_368 * 4) = local_364[local_44];
    local_44 = local_44 + 1;
  }
  _DAT_00538ac0 = local_364[local_44];
  local_44 = local_44 + 1;
  DAT_00538ac4 = local_364[local_44];
  local_44 = iVar1 + 2;
  FUN_0040b441((int *)&DAT_0051a4e8,10);
  _DAT_0051a678 = 3;
  DAT_00538ac8 = 0;
LAB_00421d4c:
  DAT_0070a860 = DAT_0067bdd4;
  SelectObject(*(HDC *)(DAT_0067bdd4 + 4),DAT_0067bdd8);
  if (DAT_0070a880 == 8) {
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_statbak_pic_0051acbc,(short *)0x1);
  }
  else {
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_statbak_pic_0051acc8,(short *)0x1);
  }
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x26,DAT_0052245c - 0x1d1,0x8c,0xac,
               *(undefined4 *)(&DAT_0051ac18 + DAT_006410d8 * 8));
  FUN_004219e1(g_DisplaySurfaceBackBuffer,0x27,DAT_0052245c - 0x1d0,0x8a,0xaa,
               *(undefined4 *)(&DAT_0051ac1c + DAT_006410d8 * 8));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
  iVar1 = Ai_Util_004c3bc4(0xa9);
  iVar2 = Ai_Util_004c3bc4(0x89);
  iVar3 = Ai_Util_004c3bc4(0x11);
  iVar4 = Ai_Util_004c3bc4(0x28);
  Surface_StretchBlt(local_1c,0,0,0x89,0xa9,(int *)g_DisplaySurfaceBackBuffer,iVar4,iVar3,iVar2,
                     iVar1);
  iVar3 = 0x154;
  iVar2 = 0;
  arg_6 = (int *)g_DisplaySurfaceWork;
  arg_5 = Ai_Util_004c3bc4(0x7f);
  arg_4 = Ai_Util_004c3bc4(0x173);
  iVar1 = Ai_Util_004c3bc4(0x43);
  arg_2 = Ai_Util_004c3bc4(0xf7);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar1,arg_4,arg_5,arg_6,iVar2,iVar3);
  str_7 = s_advfac64_pic_0051acd4;
  str_6 = s_prdblk_pic_0051ace4;
  iVar1 = Ai_Util_004c3bc4(0xa9);
  iVar2 = Ai_Util_004c3bc4(0x89);
  iVar3 = Ai_Util_004c3bc4(0x11);
  arg_2_00 = Ai_Util_004c3bc4(0x28);
  FUN_00488fdb((undefined4 *)g_DisplaySurfaceBackBuffer,arg_2_00,iVar3,iVar2,iVar1,str_6,str_7);
  SelectObject(*(HDC *)(DAT_0070a860 + 4),*(HGDIOBJ *)(DAT_0070a860 + 0xc));
  DAT_0070a860 = 0;
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x4f,0x102);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb7,0x102);
  Minit_Subsystem_00452827();
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x4f,0x138);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb7,0x138);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x29,0x161);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x4e,0x161);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x73,0x161);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x98,0x161);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xbd,0x161);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_c,0x69,0xc6);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_c,0x69,0xd6);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_c,0x10e,0x16c);
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_006410c0 + local_8 * 4) != 0) {
      iVar1 = (int)(&DAT_00538a10)[local_8];
      iVar2 = Ai_Util_004c3bc4(0x30);
      iVar3 = Ai_Util_004c3bc4(0x30);
      iVar4 = Ai_Util_004c3bc4(0x154);
      arg_2_01 = Ai_Util_004c3bc4(local_8 * 0x39 + 0x14d);
      Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,arg_2_01,iVar4,iVar3,iVar2,iVar1);
    }
  }
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_c,0x118,0xeb);
  for (local_8 = 0; (int)local_8 < 0xc; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 3;
    *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 0;
    if (((int)local_8 < 2) || ((local_8 & 1) != 0)) {
      if ((int)local_8 < 2) {
        local_374 = local_8 * 0x35;
      }
      else {
        local_374 = ((int)(local_8 - 2) / 2) * 0x35 + 0x6a;
      }
      *(int *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54) = local_374 + 0xee;
      *(undefined4 *)(&DAT_0051a4e8 + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54);
      *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54) = 0x10e;
      *(undefined4 *)(&DAT_0051a4ec + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54);
      if ((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 0;
        *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 1;
      }
    }
    else {
      *(int *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54) = ((int)(local_8 - 2) / 2) * 0x35 + 0x16b;
      *(undefined4 *)(&DAT_0051a4e8 + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4f8 + (local_8 + 10) * 0x54);
      *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54) = 0xd2;
      *(undefined4 *)(&DAT_0051a4ec + (local_8 + 10) * 0x54) =
           *(undefined4 *)(&DAT_0051a4fc + (local_8 + 10) * 0x54);
      if ((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) {
        *(undefined4 *)(&DAT_0051a528 + (local_8 + 10) * 0x54) = 0;
        *(undefined4 *)(&DAT_00538a30 + local_8 * 4) = 1;
      }
    }
    *(undefined4 *)(&DAT_0051a504 + (local_8 + 10) * 0x54) = 0x35;
    *(undefined4 *)(&DAT_0051a4f4 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a504 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a500 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a4f4 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a4f0 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a500 + (local_8 + 10) * 0x54);
    *(undefined4 *)(&DAT_0051a52c + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_006782a0 + local_8 * 4);
    *(undefined4 *)(&DAT_0051a534 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_006782d0 + local_8 * 4);
    *(undefined4 *)(&DAT_0051a530 + (local_8 + 10) * 0x54) =
         *(undefined4 *)(&DAT_0051a534 + (local_8 + 10) * 0x54);
  }
  FUN_0040b441((int *)&DAT_0051a830,0xc);
  FUN_00422f06();
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x184);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x184);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x196);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x196);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x1a8);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x1a8);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0x14,0x1ba);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0xb2,0x1ba);
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0xe9,0x19a);
  for (local_8 = 0; (int)local_8 < 5; local_8 = local_8 + 1) {
    FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_14,local_8 * 0x39 + 0x165,0x19a);
  }
  FUN_0040d49d((int)g_DisplaySurfaceBackBuffer,local_c,0xe9,0x1c0);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_14,0x1a1,0x1c0);
  FUN_0040d4d1((int)g_DisplaySurfaceBackBuffer,local_c,0x1b0,0x36);
  if (DAT_0070a880 == 8) {
    memset((void *)((int)&DAT_0070a134 + 2),0,0x300);
    FUN_0050e8b0((short *)&DAT_0070a130);
  }
  if (DAT_0070a880 == 8) {
    FUN_00510b70(-1,0,0,s_advfac64_pic_0051ae08,(short *)&DAT_0070a130);
  }
  else {
    LoadPalNoPic(s_advfac64_pic_0051ae18);
  }
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceScreen,0,0);
  FUN_005115a0(0,(short)DAT_00530d9c);
  if (DAT_00522458 == 0x280) {
    Mem_AllocOrFree_00510de0(1,s_creatures640_pic_0051ae28);
    DAT_0051a4c8 = 0;
  }
  else if (DAT_00522458 == 800) {
    Mem_AllocOrFree_00510de0(1,s_creatures800_pic_0051ae3c);
    DAT_0051a4c8 = 1;
  }
  else if (DAT_00522458 == 0x400) {
    Mem_AllocOrFree_00510de0(1,s_creatures1024_pic_0051ae50);
    DAT_0051a4c8 = 2;
  }
  DAT_00538ac8 = 0;
  FUN_00422b04(0);
  FUN_0042192b(0x51a638);
LAB_004228ce:
  local_18 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_18);
  FUN_0041f17e(0x51a4e8,0x16,local_18);
  DAT_00680770 = 1;
  for (local_8 = 0; (int)local_8 < 3; local_8 = local_8 + 1) {
    FUN_004212f0((int)(&DAT_0051a4e8 + local_8 * 0x54),0);
  }
  for (local_8 = 10; (int)local_8 < 0x16; local_8 = local_8 + 1) {
    FUN_0041e370((int)(&DAT_0051a4e8 + local_8 * 0x54),0);
  }
  DAT_00680770 = 0;
  DAT_00538a28 = -1;
  while (DAT_00538a28 == -1) {
    Pic_Subsystem_0044b84b();
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  switch(DAT_00538a28) {
  case 1:
    FUN_0040a3e1();
    Adventure_Map_UpdateLightingAndPalette(0,0xffffffff);
    goto switchD_00422abd_caseD_6;
  case 2:
    FUN_0040b4e8();
    goto switchD_00422abd_caseD_6;
  case 3:
    Mem_AllocOrFree_0050fc50(DAT_00538a10);
    FUN_005112b0(0,(short)DAT_00530d9c);
    LoadPalNoPic(s_advfac64_pic_0051ae64);
    return 0;
  case 4:
  case 5:
    goto LAB_004228ce;
  default:
    goto switchD_00422abd_caseD_6;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
    Pic_Load_worlbak1_004230bd(DAT_00538a28 + -0xf);
    goto switchD_00422abd_caseD_6;
  }
  if (*(int *)(DAT_00538a28 * 4 + 0x641098) != 0) {
    FUN_005112b0(0,(short)DAT_00530d9c);
    Adventure_Map_UpdateLightingAndPalette(0x101,DAT_00538a28 - 9);
  }
  FUN_0040a3e1();
  if (*(int *)(DAT_00538a28 * 4 + 0x641098) != 0) goto switchD_00422abd_caseD_6;
  goto LAB_004228ce;
switchD_00422abd_caseD_6:
  goto LAB_00421d4c;
}


