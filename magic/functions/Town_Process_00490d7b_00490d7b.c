/*
 * Decompiled function: Town_Process_00490d7b
 * Entry Point: 00490d7b
 * Size: 4071 bytes
 */
#include "magic.h"


void Town_Process_00490d7b(void)

{
  undefined4 uVar1;
  int iVar2;
  uint arg_2;
  uint arg_4;
  DWORD arg_5;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  DWORD local_45c;
  int local_444;
  int local_43c;
  int local_434;
  DWORD local_430;
  int local_42c;
  int local_424;
  int aiStack_418 [10];
  int aiStack_3f0 [247];
  int local_14;
  int local_10;
  int local_8;
  
  local_14 = 0;
  local_444 = 0;
  Mem_AllocOrFree_00510e20(1,s_infobar_pic_00528650);
  Mem_AllocOrFree_0050fc00();
  for (local_43c = 0; local_43c < 4; local_43c = local_43c + 1) {
    if (*(int *)(&DAT_005281f0 + local_43c * 0x54) == *(int *)(&DAT_005281e0 + local_43c * 0x54)) {
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f0 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f0 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f4 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f4 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281f8 + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281f8 + local_43c * 0x54) = uVar1;
      uVar1 = Ai_Util_004c3bc4(*(int *)(&DAT_005281fc + local_43c * 0x54));
      *(undefined4 *)(&DAT_005281fc + local_43c * 0x54) = uVar1;
    }
    for (local_42c = 0; local_42c < 4; local_42c = local_42c + 1) {
      uVar1 = Sprite_EncodeFromSurface(1,local_42c * 0x12 + 0x2b,local_43c * 0x31 + 0x1c,0x11,0x2f);
      (&DAT_00676c40)[local_43c * 4 + local_42c] = (void *)uVar1;
    }
  }
  if (DAT_00528340 == DAT_00528330) {
    DAT_00528340 = Ai_Util_004c3bc4(DAT_00528340);
    DAT_00528344 = Ai_Util_004c3bc4(DAT_00528344);
    DAT_00528348 = Ai_Util_004c3bc4(DAT_00528348);
    DAT_0052834c = Ai_Util_004c3bc4(DAT_0052834c);
  }
  for (local_42c = 0; local_42c < 3; local_42c = local_42c + 1) {
    uVar1 = Sprite_EncodeFromSurface(1,local_42c * 0x3c + 0x2b,1,0x3a,0x18);
    *(undefined4 *)(&DAT_00676be0 + local_42c * 4) = uVar1;
  }
  FUN_0050fc20();
  iVar2 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar2);
  FUN_0041f17e(0x5281e0,5,iVar2);
  Mem_AllocOrFree_0041f159(0);
  DAT_00641884 = 1;
  Adventure_LoadFacePalette(1);
  *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
  *(undefined4 *)(g_DisplaySurfaceBackBuffer + 0x20) = 1;
  FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_cityinfo_pic_0052865c,(short *)0x0);
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
  FUN_00510b70(2,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,s_cinfopce_pic_0052866c,
               (short *)0x0);
  arg_2 = (int)((int)DAT_00522458 / 2 + DAT_00522458 * 0x30) / 0x280;
  local_8 = Ai_Util_004c3bc4(0x52);
  arg_4 = Ai_Util_004c3bc4(0x231);
  arg_5 = Ai_Util_004c3bc4(0x2a);
  iVar2 = Ai_Util_004c3bc4(0x19);
  uVar5 = arg_4;
  iVar3 = Ai_Util_004c3bc4(0x38);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x46,
                     0x231,0x19,(int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3,uVar5,iVar2);
  Surface_StretchBlt((int *)g_DisplaySurfaceWork,0,*(int *)(g_DisplaySurfaceWork + 0x10) + -0x2c,
                     0x231,0x2a,(int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5);
  for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
    FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                 arg_2,local_42c * arg_5 + local_8);
  }
  FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceScreen,0,0);
  for (local_10 = 0; local_10 < 0x80; local_10 = local_10 + 1) {
    if (((((&DAT_0067be00)[local_10 * 100] & 2) != 0) || (DAT_0067b9a4 != 0)) &&
       (*(int *)(&DAT_0067bdf0 + local_10 * 100) != 1)) {
      aiStack_418[local_14 + 1] = local_10;
      local_14 = local_14 + 1;
    }
  }
  for (local_42c = 0; local_42c < 5; local_42c = local_42c + 1) {
    FUN_0040d4d1((int)g_DisplaySurfaceScreen,0xfe,local_42c * 0x2a + 0xcc,0x2a);
  }
LAB_00491326:
  do {
    for (local_42c = 0; local_42c < 9; local_42c = local_42c + 1) {
      FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,(int *)g_DisplaySurfaceBackBuffer,
                   arg_2,local_42c * arg_5 + local_8);
    }
    local_424 = local_444;
    local_43c = 0;
    while( true ) {
      iVar2 = local_14 - local_444;
      if (8 < iVar2) {
        iVar2 = 9;
      }
      if (iVar2 <= local_43c) break;
      local_10 = aiStack_418[local_424 + 1];
      iVar2 = Ai_Util_004c3bc4(0x68);
      Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,local_10,0x30,iVar2 + local_43c * arg_5);
      local_43c = local_43c + 1;
      local_424 = local_424 + 1;
    }
    FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_8,arg_4,arg_5 * 9,
                 (int *)g_DisplaySurfaceScreen,arg_2,local_8);
    if (9 < local_14) {
      local_45c = arg_5;
      if (local_444 == 0) {
        local_45c = 0;
      }
      FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_8,arg_4,arg_5 * 9,
                   (int *)g_DisplaySurfaceBackBuffer,arg_2,local_45c);
      if (local_444 == 0) {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 9);
        iVar2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[0],0x30,iVar2 + arg_5 * 9);
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        if (10 < local_14) {
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_3f0[1],0x30,iVar2 + arg_5 * 10)
          ;
        }
      }
      else {
        FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                     (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
        iVar2 = Ai_Util_004c3bc4(0x15);
        Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,iVar2);
        if (local_444 + 10 < local_14) {
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
        }
        if (local_444 + 10 < local_14) {
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f
                    (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444],0x30,iVar2 + arg_5 * 10);
        }
      }
    }
    local_430 = arg_5;
    if (local_444 == 0) {
      local_430 = 0;
    }
switchD_004918ce_default:
    if (local_14 < 10) {
      FUN_0041ece4(0x5281e0);
      FUN_0041ece4(0x528234);
      FUN_0041ece4(0x528288);
      FUN_0041ece4(0x5282dc);
    }
    else {
      if (local_444 == 0) {
        FUN_0041ece4(0x5281e0);
        FUN_0041ece4(0x528234);
      }
      else {
        FUN_0041ed3a(0x5281e0);
        FUN_0041ed3a(0x528234);
      }
      if (local_14 + -9 == local_444) {
        FUN_0041ece4(0x528288);
        FUN_0041ece4(0x5282dc);
      }
      else {
        FUN_0041ed3a(0x528288);
        FUN_0041ed3a(0x5282dc);
      }
    }
    FUN_0041f213();
    DAT_0054aae0 = -5;
    do {
      Pic_Subsystem_0044b84b();
      FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
      if (DAT_0054aae0 != -5) break;
      iVar2 = Mem_AllocOrFree_00408089();
    } while (iVar2 == 0);
    if (DAT_0054aae0 == 0) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_00676c40);
      return;
    }
    switch(DAT_0054aae0) {
    case 0:
      goto switchD_004918ce_default;
    case 1:
      local_434 = 0x5000;
      break;
    case 2:
      local_434 = 0x5100;
      break;
    case -2:
      local_434 = 0x4900;
      break;
    case -1:
      local_434 = 0x4800;
      break;
    default:
      goto switchD_004918ce_default;
    }
    if (local_14 < 10) {
      FUN_0041f391();
      Mem_AllocOrFree_0050fc50(DAT_00676c40);
      return;
    }
    if (local_434 == 0x4800) {
      local_444 = local_444 + -1;
      if (local_444 < 0) {
        local_444 = 0;
      }
      else {
        for (local_42c = 0; iVar2 = Ai_Util_004c3bc4(0x2b), local_42c < iVar2;
            local_42c = local_42c + 3) {
          iVar2 = Ai_Util_004c3bc4(3);
          iVar2 = local_8 + iVar2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uVar7 = arg_2;
          iVar3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - iVar3;
          uVar5 = arg_4;
          iVar3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar3 + (local_430 - local_42c),uVar5
                       ,DVar4,piVar6,uVar7,iVar2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uVar5 = arg_2;
        iVar2 = local_8;
        iVar3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 9 - iVar3,piVar6,uVar5,
                     iVar2);
        if (local_444 < 1) {
          local_430 = 0;
        }
        else {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,0,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5);
          FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          iVar2 = Ai_Util_004c3bc4(0x15);
          Castle_Process_00491d8f(g_DisplaySurfaceBackBuffer,aiStack_418[local_444],0x30,iVar2);
          local_430 = arg_5;
        }
      }
      goto switchD_004918ce_default;
    }
    if (local_434 == 0x5000) {
      if (local_14 + -9 != local_444) {
        for (local_42c = 0; iVar2 = Ai_Util_004c3bc4(0x2b), local_42c < iVar2;
            local_42c = local_42c + 3) {
          iVar2 = Ai_Util_004c3bc4(3);
          iVar2 = local_8 + iVar2;
          piVar6 = (int *)g_DisplaySurfaceScreen;
          uVar7 = arg_2;
          iVar3 = Ai_Util_004c3bc4(5);
          DVar4 = arg_5 * 9 - iVar3;
          uVar5 = arg_4;
          iVar3 = Ai_Util_004c3bc4(3);
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_42c + iVar3 + local_430,uVar5,
                       DVar4,piVar6,uVar7,iVar2);
        }
        piVar6 = (int *)g_DisplaySurfaceScreen;
        uVar5 = arg_2;
        iVar2 = local_8;
        iVar3 = Ai_Util_004c3bc4(5);
        FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,local_430 + arg_5,arg_4,
                     arg_5 * 9 - iVar3,piVar6,uVar5,iVar2);
        local_430 = arg_5;
        if ((0 < local_444) && (local_444 < local_14 + -9)) {
          FUN_0050e040((int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5,arg_4,arg_5 * 10,
                       (int *)g_DisplaySurfaceBackBuffer,arg_2,0);
          if (local_444 + 10 < local_14) {
            FUN_0050e040((int *)g_DisplaySurfaceWork,0,0x80,arg_4,arg_5,
                         (int *)g_DisplaySurfaceBackBuffer,arg_2,arg_5 * 10);
          }
          if (local_444 + 10 < local_14) {
            iVar2 = Ai_Util_004c3bc4(0x15);
            Castle_Process_00491d8f
                      (g_DisplaySurfaceBackBuffer,aiStack_3f0[local_444 + 1],0x30,iVar2 + arg_5 * 10
                      );
          }
        }
      }
      local_444 = local_444 + 1;
      if (local_14 + -9 < local_444) {
        local_444 = local_14 + -9;
      }
      goto switchD_004918ce_default;
    }
    if (local_434 == 0x4900) {
      local_444 = local_444 + -8;
      if (local_444 < 1) {
        local_444 = 0;
      }
      goto LAB_00491326;
    }
    if (local_434 != 0x5100) goto switchD_004918ce_default;
    iVar2 = local_444 + 8;
    local_444 = local_14 + -9;
    if (iVar2 <= local_14 + -9) {
      local_444 = iVar2;
    }
  } while( true );
}


