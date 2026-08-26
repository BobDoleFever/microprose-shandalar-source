/*
 * Decompiled function: FUN_100067b9
 * Entry Point: 100067b9
 * Size: 528 bytes
 */
#include "magvid.h"


int32_t __cdecl FUN_100067b9(int32_t arg_1,HPSTR arg_2)

{
  BOOL BVar1;
  int32_t uval_2;
  MMRESULT MVar3;
  DWORD DVar4;
  int val_5;
  char *pcVar6;
  HWND *ppHVar7;
  CHAR *pCVar8;
  int32_t *puVar9;
  _MMCKINFO local_204;
  _MMCKINFO local_1f0;
  HMMIO local_1dc;
  CHAR local_1d8 [22];
  int32_t local_1c2 [26];
  DWORD local_158;
  char local_154 [4];
  char local_150 [4];
  char local_14c [4];
  char local_148 [4];
  char local_144;
  int32_t local_143;
  DWORD local_50;
  HWND local_4c [2];
  CHAR *local_44;
  char *local_34;
  DWORD local_30;
  char *local_20;
  DWORD local_1c;
  
  ppHVar7 = local_4c;
  for (val_5 = 0x12; val_5 != 0; val_5 = val_5 + -1) {
    *ppHVar7 = (HWND)0x0;
    ppHVar7 = ppHVar7 + 1;
  }
  local_154 = (char  [4])s_d__avi_quant_pal_100105a4._0_4_;
  local_150 = (char  [4])s_d__avi_quant_pal_100105a4._4_4_;
  local_14c = (char  [4])s_d__avi_quant_pal_100105a4._8_4_;
  local_148 = (char  [4])s_d__avi_quant_pal_100105a4._12_4_;
  local_144 = s_d__avi_quant_pal_100105a4[0x10];
  puVar9 = &local_143;
  for (val_5 = 0x3c; val_5 != 0; val_5 = val_5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(int16_t *)puVar9 = 0;
  *(uint8_t *)((int)puVar9 + 2) = 0;
  pcVar6 = s_Palette_Files_100105b8;
  pCVar8 = local_1d8;
  for (val_5 = 5; val_5 != 0; val_5 = val_5 + -1) {
    *(int32_t *)pCVar8 = *(int32_t *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pCVar8 = pCVar8 + 4;
  }
  *(int16_t *)pCVar8 = *(int16_t *)pcVar6;
  puVar9 = local_1c2;
  for (val_5 = 0x1a; val_5 != 0; val_5 = val_5 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(int16_t *)puVar9 = 0;
  local_50 = 0x4c;
  local_4c[0] = (HWND)0x0;
  local_20 = s_Select_Palette_File_100105d0;
  local_44 = local_1d8;
  local_34 = local_154;
  local_30 = 0x104;
  local_1c = 0x806;
  BVar1 = GetOpenFileNameA((LPOPENFILENAMEA)&local_50);
  if (BVar1 == 0) {
    uval_2 = 1;
  }
  else {
    local_1dc = mmioOpenA(local_154,(LPMMIOINFO)0x0,0);
    if (local_1dc == (HMMIO)0x0) {
      uval_2 = 1;
    }
    else {
      local_204.fccType = 0x204c4150;
      MVar3 = mmioDescend(local_1dc,&local_204,(MMCKINFO *)0x0,0x20);
      if (MVar3 == 0) {
        local_1f0.ckid = 0x61746164;
        MVar3 = mmioDescend(local_1dc,&local_1f0,&local_204,0x10);
        if (MVar3 == 0) {
          local_158 = local_1f0.cksize;
          if (local_1f0.cksize == 0) {
            mmioClose(local_1dc,0);
            uval_2 = 1;
          }
          else {
            DVar4 = mmioRead(local_1dc,arg_2,local_1f0.cksize);
            if (DVar4 == local_158) {
              mmioClose(local_1dc,0);
              uval_2 = 0;
            }
            else {
              mmioClose(local_1dc,0);
              uval_2 = 1;
            }
          }
        }
        else {
          mmioClose(local_1dc,0);
          uval_2 = 1;
        }
      }
      else {
        mmioClose(local_1dc,0);
        uval_2 = 1;
      }
    }
  }
  return uval_2;
}


