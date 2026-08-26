/*
 * Decompiled function: Save_ProcessGame_004207a8
 * Entry Point: 004207a8
 * Size: 2576 bytes
 */
#include "magic.h"


int Save_ProcessGame_004207a8(int arg_1)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  char local_234;
  char local_230 [255];
  char acStack_131 [257];
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  char *local_10;
  int local_c;
  FILE *local_8;
  
  local_10 = s_magic4_map_0051a438;
  FUN_005112b0(0,(short)DAT_00530d9c);
  FUN_00510b70(1,0,0,s_menopt_pic_0051a444,
               (short *)((int)&DAT_0070a130 + ((DAT_0070a880 == 8) - 1 & 0xff8f5ed1)));
  Surface_StretchBlt((int *)g_DisplaySurfaceBackBuffer,0,0,0x280,0x1e0,(int *)g_DisplaySurfaceScreen
                     ,0,0,DAT_00522458,DAT_0052245c);
  FUN_005115a0(0,(short)DAT_00530d9c);
  Mem_AllocOrFree_00510e20(1,s_optbox_pic_0051a450);
  Mem_AllocOrFree_0050fc00();
  DAT_005387b8 = (void *)Sprite_EncodeFromSurface(1,1,1,0x40,0x19);
  DAT_005387bc = Sprite_EncodeFromSurface(1,0x42,1,0xe,0xe);
  DAT_005387c0 = Sprite_EncodeFromSurface(1,0x83,1,0xe,0xe);
  DAT_005387c4 = Sprite_EncodeFromSurface(1,1,0x1d,0xe,0xe);
  DAT_005387c8 = Sprite_EncodeFromSurface(1,0x42,0x1d,0xe,0xe);
  DAT_005387cc = Sprite_EncodeFromSurface(1,0x83,0x1d,8,0xb);
  DAT_005387d0 = Sprite_EncodeFromSurface(1,1,0x39,0xb,8);
  DAT_005387d4 = Sprite_EncodeFromSurface(1,0x42,0x39,8,0xb);
  DAT_005387d8 = Sprite_EncodeFromSurface(1,0x83,0x39,0xb,8);
  for (local_18 = 0; local_18 < 2; local_18 = local_18 + 1) {
    for (local_c = 0; local_c < 3; local_c = local_c + 1) {
      uVar3 = Sprite_EncodeFromSurface(1,local_c * 0x41 + 1,local_18 * 0x1c + 0x55,0x1e,0x1b);
      *(undefined4 *)(&DAT_00538818 + local_18 * 0xc + local_c * 4) = uVar3;
    }
  }
  FUN_0050fc20();
  local_28 = 0x1c;
  local_2c = 0x45;
  local_20 = 0x188;
  local_24 = 0x149;
  FUN_0042038c(g_DisplaySurfaceScreen,0x1c,0x45,0x188,0x149);
  strcpy(&g_OverworldWorldState,s_Save_0051a45c + ((arg_1 != 0) - 1 & 8));
  strcat(&g_OverworldWorldState,s_Game_Files_0051a46c);
  local_10[5] = '4';
  local_8 = fopen(s_saveDescs_0051a480,&DAT_0051a47c);
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    fgets(&DAT_0067f450 + local_c * 0x40,0x40,local_8);
    sVar4 = strlen(&DAT_0067f450 + local_c * 0x40);
    (&DAT_0067f44f)[local_c * 0x40 + sVar4] = 0;
    cVar2 = FUN_0048c6d0(local_c + 4);
    local_10[5] = cVar2;
    uVar3 = FUN_00406b01(local_10);
    *(undefined4 *)(&DAT_005387e0 + local_c * 4) = uVar3;
    if (*(int *)(&DAT_005387e0 + local_c * 4) == 0) {
      strcpy(&DAT_0067f450 + local_c * 0x40,s__Empty__0051a48c);
    }
    if (arg_1 != 0) {
      *(undefined4 *)(&DAT_005387e0 + local_c * 4) = 1;
    }
  }
  if (DAT_0051a090 == DAT_0051a080) {
    for (local_c = 0; local_c < 10; local_c = local_c + 1) {
      iVar5 = Ai_Util_004c3bc4((&DAT_0051a090)[local_c * 0x15]);
      (&DAT_0051a090)[local_c * 0x15] = iVar5;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a094 + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a094 + local_c * 0x54) = uVar3;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a098 + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a098 + local_c * 0x54) = uVar3;
      uVar3 = Ai_Util_004c3bc4(*(int *)(&DAT_0051a09c + local_c * 0x54));
      *(undefined4 *)(&DAT_0051a09c + local_c * 0x54) = uVar3;
    }
  }
LAB_00420bf9:
  local_1c = FUN_0041f354();
  Mem_AllocOrFree_0041f12b(local_1c);
  FUN_0041f17e(0x51a080,0xb - (uint)(arg_1 == 0),local_1c);
  for (local_c = 0; local_c < 10; local_c = local_c + 1) {
    if (*(int *)(&DAT_005387e0 + local_c * 4) == 0) {
      FUN_0041ece4((int)(&DAT_0051a080 + local_c * 0x15));
      FUN_0042024f(local_c,3);
    }
    else {
      FUN_0041ed3a((int)(&DAT_0051a080 + local_c * 0x15));
      FUN_0042024f(local_c,0);
    }
  }
  DAT_005387b0 = -1;
  while (DAT_005387b0 == -1) {
    FUN_0041f3ea(DAT_0067bda4,DAT_0067bda8,DAT_007039c4);
  }
  FUN_0041f391();
  Mem_AllocOrFree_0041f12b(local_1c);
  if (DAT_005387b0 == 0xe) {
    FUN_005112b0(0,(short)DAT_00530d9c);
    return -1;
  }
  if (arg_1 == 0) {
LAB_00421183:
    fclose(local_8);
    Mem_AllocOrFree_0050fc50(DAT_005387b8);
    FUN_005112b0(0,(short)DAT_00530d9c);
    return DAT_005387b0;
  }
  local_30 = DAT_005387b0 + -4;
  strcpy(local_230,&DAT_0067f450 + local_30 * 0x40);
  DAT_00538834 = 1;
  memset(acStack_131 + 1,0,0x100);
  strcpy(acStack_131 + 1,&DAT_0067f450 + local_30 * 0x40);
  iVar5 = strcmp(acStack_131 + 1,s__Empty__0051a494);
  if (iVar5 == 0) {
    acStack_131[1] = 0;
  }
  DAT_00538830 = strlen(acStack_131 + 1);
  FUN_0042024f(local_30,2);
  do {
    uVar6 = FUN_004080b2();
    sVar4 = DAT_00538830;
    if (uVar6 == 0x1c0d) {
      DAT_00538834 = 0;
      fseek(local_8,0,0);
      for (local_c = 0; local_c < 10; local_c = local_c + 1) {
        fprintf(local_8,&DAT_0051a4a0,&DAT_0067f450 + local_c * 0x40);
      }
      goto LAB_00421183;
    }
    if ((int)uVar6 < 0xe09) {
      if (uVar6 == 0xe08) {
        if (DAT_00538830 != 0) {
          DAT_00538830 = DAT_00538830 - 1;
          strcpy(acStack_131 + sVar4,acStack_131 + sVar4 + 1);
        }
      }
      else {
        if (uVar6 == 0x11b) break;
LAB_00420f5c:
        uVar1 = uVar6 & 0xff;
        if ((((0x40 < uVar1) && (uVar1 < 0x5b)) || ((0x60 < uVar1 && (uVar1 < 0x7b)))) ||
           (((0x2f < uVar1 && (uVar1 < 0x3a)) || (uVar1 == 0x20)))) {
          if (DAT_0051a078 != 0) {
            memmove(acStack_131 + DAT_00538830 + 2,acStack_131 + DAT_00538830 + 1,
                    0xff - DAT_00538830);
          }
          local_234 = (char)uVar6;
          acStack_131[DAT_00538830 + 1] = local_234;
          DAT_00538830 = DAT_00538830 + 1;
        }
      }
    }
    else if ((int)uVar6 < 0xf10) {
      if (uVar6 == 0xf0f) {
        DAT_00538830 = DAT_00538830 - 8;
        if ((int)DAT_00538830 < 1) {
          DAT_00538830 = 0;
        }
      }
      else {
        if (uVar6 != 0xf09) goto LAB_00420f5c;
        DAT_00538830 = DAT_00538830 + 8;
      }
    }
    else if ((int)uVar6 < 0x4701) {
      if (uVar6 == 0x4700) {
        DAT_00538830 = 0;
      }
      else if (uVar6 != 0x1c0d) goto LAB_00420f5c;
    }
    else if ((int)uVar6 < 0x4d01) {
      if (uVar6 == 0x4d00) {
        sVar4 = strlen(acStack_131 + 1);
        if (sVar4 == DAT_00538830) {
          strcat(acStack_131 + 1,&DAT_0051a49c);
        }
        DAT_00538830 = DAT_00538830 + 1;
      }
      else {
        if (uVar6 != 0x4b00) goto LAB_00420f5c;
        if (-1 < (int)DAT_00538830) {
          DAT_00538830 = DAT_00538830 - 1;
        }
      }
    }
    else if (uVar6 == 0x4f00) {
      DAT_00538830 = strlen(acStack_131 + 1);
    }
    else if (uVar6 == 0x5200) {
      DAT_0051a078 = DAT_0051a078 ^ 1;
    }
    else {
      if (uVar6 != 0x5300) goto LAB_00420f5c;
      sVar4 = strlen(acStack_131 + 1);
      if ((int)DAT_00538830 < (int)sVar4) {
        strcpy(acStack_131 + DAT_00538830 + 1,acStack_131 + DAT_00538830 + 2);
      }
    }
    strcpy(&DAT_0067f450 + local_30 * 0x40,acStack_131 + 1);
    FUN_0042024f(local_30,2);
  } while( true );
  DAT_00538834 = 0;
  strcpy(&DAT_0067f450 + local_30 * 0x40,local_230);
  goto LAB_00420bf9;
}


