/*
 * Decompiled function: Castle_Process_0048f523
 * Entry Point: 0048f523
 * Size: 5156 bytes
 */
#include "magic.h"


void Castle_Process_0048f523(void)

{
  byte bVar1;
  undefined4 uVar2;
  void *pvVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  DWORD arg_5;
  uint arg_2;
  int iVar9;
  void **ppvVar10;
  bool bVar11;
  int local_1528;
  int local_14c8;
  int local_14c0;
  int local_14bc;
  int local_14b0;
  void *local_14ac [50];
  uint auStackY_13e4 [15];
  uint auStackY_13a8 [50];
  undefined4 local_12e0;
  uint local_12dc;
  uint local_12d4;
  int local_12d0;
  uint local_12cc;
  int local_12c8;
  char acStackY_12c4 [4744];
  undefined4 uStackY_3c;
  int *arg_6;
  
  Mem_AllocOrFree_00513bd0();
  local_12dc = 0;
  local_12c8 = 0;
  local_14c8 = 0;
  local_14ac[0] = (void *)0x0;
  ppvVar10 = local_14ac;
  for (iVar9 = 0x31; ppvVar10 = ppvVar10 + 1, iVar9 != 0; iVar9 = iVar9 + -1) {
    *ppvVar10 = (void *)0x0;
  }
  Mem_AllocOrFree_00510e20(1,s_dun_bar_pic_0052855c);
  Mem_AllocOrFree_0050fc00();
  DAT_00676bd0 = (void *)Sprite_EncodeFromSurface(1,2,1,0xd,0x70);
  for (local_14b0 = 0; local_14b0 < 3; local_14b0 = local_14b0 + 1) {
    uVar2 = Sprite_EncodeFromSurface(1,local_14b0 * 0x3c + 0x10,1,0x3b,0x1a);
    *(undefined4 *)(&DAT_00676bc0 + local_14b0 * 4) = uVar2;
  }
  for (local_14bc = 0; local_14bc < 2; local_14bc = local_14bc + 1) {
    for (local_14b0 = 0; local_14b0 < 4; local_14b0 = local_14b0 + 1) {
      uVar2 = Sprite_EncodeFromSurface
                        (1,local_14bc * 0x80 + local_14b0 * 0x20 + 0x10,0x1c,0x1f,0x24);
      *(undefined4 *)(&DAT_00676ba0 + local_14b0 * 4 + local_14bc * 0x10) = uVar2;
    }
  }
  FUN_0050fc20();
  if (DAT_00528000 == DAT_00527ff0) {
    for (local_14b0 = 0; local_14b0 < 3; local_14b0 = local_14b0 + 1) {
      uVar2 = Ai_Util_004c3bc4((&DAT_00528000)[local_14b0 * 0x15]);
      (&DAT_00528000)[local_14b0 * 0x15] = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528004 + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_00528004 + local_14b0 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_00528008 + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_00528008 + local_14b0 * 0x54) = uVar2;
      uVar2 = Ai_Util_004c3bc4(*(int *)(&DAT_0052800c + local_14b0 * 0x54));
      *(undefined4 *)(&DAT_0052800c + local_14b0 * 0x54) = uVar2;
    }
  }
  FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_dung_bd_pic_00528568,(short *)0x0);
  uStackY_3c = 0x48f7d7;
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                     (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
  FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
               (int *)g_DisplaySurfaceScreen,0,0);
  Mem_AllocOrFree_0050fc00();
  for (local_12cc = 0; (int)local_12cc < 0xf; local_12cc = local_12cc + 1) {
    local_12e0 = 0;
    if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (DAT_0067b9a4 != 0)) &&
       (((int)local_12cc < 5 ||
        ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (DAT_0067b9a4 != 0)))))) {
      auStackY_13a8[local_12c8] = local_12cc;
      if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
        if ((int)local_12cc < 5) {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          pvVar3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = pvVar3;
        }
        else {
          Ai_Util_004c3bc4(0x3e);
          Ai_Util_004c3bc4(0x3e);
          pvVar3 = (void *)FUN_0048ee42();
          local_14ac[local_12c8] = pvVar3;
        }
      }
      local_12c8 = local_12c8 + 1;
    }
  }
  FUN_0050fc20();
  local_12d0 = 1;
  iVar9 = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(iVar9);
  FUN_0041f17e(0x527ff0,3,iVar9);
  Mem_AllocOrFree_0041f159(0);
LAB_0048fa24:
  if (local_12d0 == 0) {
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_dung_bd_pic_00528574,(short *)0x0);
    uStackY_3c = 0x48fa87;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c,
                 (int *)g_DisplaySurfaceScreen,0,0);
  }
  local_12d0 = 0;
  do {
    if (local_12c8 < 0xd) {
      FUN_0041ece4(0x527ff0);
      FUN_0041ece4(0x528044);
    }
    else {
      if (local_14c8 == 0) {
        FUN_0041ece4(0x527ff0);
      }
      else {
        FUN_0041ed3a(0x527ff0);
      }
      if (local_14c8 + 0xc < local_12c8) {
        FUN_0041ed3a(0x528044);
      }
      else {
        FUN_0041ece4(0x528044);
      }
    }
    FUN_0041f213();
    FUN_00510b70(1,0,DAT_0052245c - 0x1e0,s_dung_bd_pic_00528580,(short *)0x0);
    uStackY_3c = 0x48fbaf;
    Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,DAT_0052245c - 0x1e0,0x280,0x1e0,
                       (int *)g_DisplaySurfaceBackBuffer,0,0,DAT_00522458,DAT_0052245c);
    *(undefined4 *)g_DisplaySurfaceScreen = 1;
    local_12dc = 0;
    *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 1;
    local_14bc = local_14c8;
    while( true ) {
      iVar9 = local_14c8 + 0xc;
      if (local_12c8 <= local_14c8 + 0xc) {
        iVar9 = local_12c8;
      }
      if (iVar9 <= local_14bc) break;
      local_12cc = auStackY_13a8[local_14bc];
      local_12e0 = 0;
      if (((*(int *)(&DAT_0067f010 + local_12cc * 0x30) != 0) || (DAT_0067b9a4 != 0)) &&
         (((int)local_12cc < 5 ||
          ((*(int *)(&DAT_0067eff0 + local_12cc * 0x30) != -1 || (DAT_0067b9a4 != 0)))))) {
        auStackY_13e4[local_12dc] = local_12cc;
        g_OverworldWorldState = 0;
        FUN_0048e2b0(local_12cc);
        if ((int)local_12cc < 5) {
          strcat(&g_OverworldWorldState,&DAT_0052858c);
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e(local_12cc + 1);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,s_Castle__00528590);
        }
        iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x19b);
        iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x69);
        iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
        FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,iVar5 - iVar6 / 2);
        strcpy(acStackY_12c4 + local_12dc * 0x30,&g_OverworldWorldState);
        g_OverworldWorldState = 0;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 1) != 0) || (DAT_0067b9a4 != 0)) {
          if (*(int *)(&DAT_0067f004 + local_12cc * 0x30) -
              *(int *)(&DAT_0067bdf8 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100) < 1) {
            strcpy(&g_OverworldWorldState,
                   &DAT_005285a4 +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          else {
            strcpy(&g_OverworldWorldState,
                   &DAT_0052859c +
                   ((0 < *(int *)(&DAT_0067f000 + local_12cc * 0x30) -
                         *(int *)(&DAT_0067bdf4 + *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100)
                    ) - 1 & 4));
          }
          strcat(&g_OverworldWorldState,&DAT_005285ac);
          Ai_TownEncounter_004c3b19(*(uint *)(&DAT_0067f008 + local_12cc * 0x30));
          strcat(&g_OverworldWorldState,&DAT_005285b0);
          uVar7 = FUN_0040c7c0(*(int *)(&DAT_0067bdf4 +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100),
                               *(int *)(&DAT_0067bdf8 +
                                       *(int *)(&DAT_0067f008 + local_12cc * 0x30) * 100));
          if ((uVar7 & 0x80) != 0) {
            local_12e0 = 1;
          }
          if ((int)local_12cc < 5) {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            pvVar3 = local_14ac[local_14bc];
            iVar6 = Ai_Util_004c3bc4(0x3e);
            iVar8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,iVar5,iVar8,iVar6,(int)pvVar3);
          }
          else {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12dc & 1) == 0) & 0xfffffef9) + 0x15b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12dc / 2) * 0x3e + 0x49);
            pvVar3 = local_14ac[local_14bc];
            iVar6 = Ai_Util_004c3bc4(0x3e);
            iVar8 = Ai_Util_004c3bc4(0x3e);
            FUN_0048efc7(g_DisplaySurfaceScreen,iVar9,iVar5,iVar8,iVar6,(int)pvVar3);
          }
        }
        local_12dc = local_12dc + 1;
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 2) != 0) || (DAT_0067b9a4 != 0)) {
          if ((int)local_12cc < 5) {
            bVar1 = FUN_0049094c();
            (&DAT_0067f00d)[local_12cc * 0x30] = bVar1 | 0x80;
          }
          strcat(&g_OverworldWorldState,
                 &DAT_005285b4 + ((((&DAT_0067f00d)[local_12cc * 0x30] & 0x80) != 0) - 1 & 4));
          pcVar4 = (char *)Mem_AllocOrFree_00473d7e((int)(char)(&DAT_0067f00c)[local_12cc * 0x30]);
          strcat(&g_OverworldWorldState,pcVar4);
          strcat(&g_OverworldWorldState,&DAT_005285bc);
        }
        if ((((&DAT_0067f010)[local_12cc * 0x30] & 4) != 0) || (DAT_0067b9a4 != 0)) {
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x10) != 0) {
            strcat(&g_OverworldWorldState,s_xColor_005285c0);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x20) != 0) {
            strcat(&g_OverworldWorldState,s_1deck_005285c8);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x40) != 0) {
            strcat(&g_OverworldWorldState,s_xArtifacts_005285d0);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 0x80) != 0) {
            strcat(&g_OverworldWorldState,s_xInstants_005285dc);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 1) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285e8);
          }
          if (((&DAT_0067f014)[local_12cc * 0x30] & 2) != 0) {
            strcat(&g_OverworldWorldState,s__Life_005285f0);
          }
          if (*(int *)(&DAT_0067effc + local_12cc * 0x30) == -1) {
            if (*(int *)(&DAT_0067f014 + local_12cc * 0x30) == 0) {
              strcat(&g_OverworldWorldState,s_xRules_005285f8);
            }
          }
          else {
            iVar9 = Pic_Subsystem_0045268f(*(int *)(&DAT_0067effc + local_12cc * 0x30));
            strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + iVar9 * 0x34);
          }
        }
      }
      local_14bc = local_14bc + 1;
    }
    *(undefined4 *)g_DisplaySurfaceScreen = 0;
    iVar9 = Ai_Util_004c3bc4(0x46);
    iVar5 = Ai_Util_004c3bc4(0x50);
    arg_6 = (int *)g_DisplaySurfaceScreen;
    arg_5 = Ai_Util_004c3bc4(0x17a);
    uVar7 = Ai_Util_004c3bc4(0x208);
    iVar6 = Ai_Util_004c3bc4(0x46);
    arg_2 = Ai_Util_004c3bc4(0x50);
    FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,arg_2,iVar6,uVar7,arg_5,arg_6,iVar5,iVar9);
    DAT_0054aae0 = -5;
    local_12d4 = 0xffffffff;
    while( true ) {
      do {
        if (DAT_0054aae0 != -5) {
          FUN_0040a3e1();
          FUN_0041f391();
          Mem_AllocOrFree_0050fc50(DAT_00676bd0);
          if ((local_12c8 != 0) && (local_14ac[0] != (void *)0x0)) {
            Mem_AllocOrFree_0050fc50(local_14ac[0]);
          }
          return;
        }
        local_12cc = 0xffffffff;
        Pic_Subsystem_0044b84b();
        if (DAT_007039c4 == 0) {
          iVar9 = (DAT_0067bda8 * 0x1e0) / (int)DAT_0052245c;
          iVar5 = (DAT_0067bda4 * 0x280) / (int)DAT_00522458;
          iVar6 = FUN_0048edeb(iVar5,iVar9,0x54,0x49,0xfb,0x174);
          if (iVar6 == 0) {
            iVar5 = FUN_0048edeb(iVar5,iVar9,0x15b,0x49,0xfd,0x174);
            if (iVar5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if (((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) &&
             (local_12cc != local_12d4)) {
            if (local_12d4 != 0xffffffff) {
              iVar9 = Ai_Util_004c3bc4((-(uint)((local_12d4 & 1) == 0) & 0xfffffef9) + 0x19b);
              iVar5 = Ai_Util_004c3bc4(((int)local_12d4 / 2) * 0x3e + 0x69);
              iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
              FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xff,iVar9,iVar5 - iVar6 / 2);
            }
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xe3,iVar9,iVar5 - iVar6 / 2);
            local_12d4 = local_12cc;
          }
        }
        else {
          iVar9 = (DAT_0067bda8 * 0x1e0) / (int)DAT_0052245c;
          iVar5 = (DAT_0067bda4 * 0x280) / (int)DAT_00522458;
          iVar6 = FUN_0048edeb(iVar5,iVar9,0x54,0x49,0xfb,0x174);
          if (iVar6 == 0) {
            iVar5 = FUN_0048edeb(iVar5,iVar9,0x15b,0x49,0xfd,0x174);
            if (iVar5 != 0) {
              local_12cc = ((iVar9 + -0x49) / 0x3e) * 2 + 1;
            }
          }
          else {
            local_12cc = ((iVar9 + -0x49) / 0x3e) * 2;
          }
          if ((-1 < (int)local_12cc) && ((int)local_12cc < (int)local_12dc)) {
            iVar9 = Ai_Util_004c3bc4((-(uint)((local_12cc & 1) == 0) & 0xfffffef9) + 0x19b);
            iVar5 = Ai_Util_004c3bc4(((int)local_12cc / 2) * 0x3e + 0x69);
            iVar6 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
            FUN_0040cf6d((int)g_DisplaySurfaceScreen,0xbe,iVar9,iVar5 - iVar6 / 2);
            FUN_0040a3e1();
            Castle_Process_00492ddf(auStackY_13e4[local_12cc]);
            goto LAB_0048fa24;
          }
        }
        local_14c0 = -1;
        FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
        if (DAT_0054aae0 != -5) {
          if (DAT_0054aae0 == -1) {
            local_14c0 = 0x4800;
          }
          else if (DAT_0054aae0 == 1) {
            local_14c0 = 0x5000;
          }
          if (DAT_0054aae0 != 0) {
            DAT_0054aae0 = -5;
          }
        }
      } while ((local_12c8 < 0xd) || ((local_14c0 != 0x4800 && (local_14c0 != 0x5000))));
      if (local_14c0 == 0x4800) {
        local_1528 = -1;
      }
      else {
        local_1528 = 1;
      }
      iVar9 = local_14c8 + local_1528 * 2;
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      iVar5 = (local_12c8 + 2U & 0xfffffffe) - 0xc;
      if (iVar9 <= iVar5) {
        iVar5 = iVar9;
      }
      bVar11 = local_14c8 != iVar5;
      local_14c8 = iVar5;
      if (bVar11) break;
      FUN_0040a3e1();
    }
  } while( true );
}


