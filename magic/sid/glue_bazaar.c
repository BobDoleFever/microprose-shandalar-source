/*
 * sid/glue_bazaar.c - Bazaar Card Trading Shop & Haar Wavelet Art Decompressor
 * Reconstructed MicroProse Source Module
 * Author: Ned Way & Sid Meier / MicroProse (1997)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
#include "shandalar/win32_compat.h"
#include "shandalar/catalog.h"
#include "shandalar/haar.h"
#include "shandalar/glue.h"

/*
 * Bazaar_GetCardBaseValue
 * Purpose: Retrieve base shop buy/sell gold valuation for card.
 * Procedure:
 * 1. Calculate gold price based on card rarity and power level.
 */
/*
 * Decompiled function: Bazaar_GetCardBaseValue
 * Entry Point: 004f0de8
 * Size: 95 bytes
 */

int Bazaar_GetCardBaseValue(int arg1)

{
  int status;
  int local_8;
  
  for (local_8 = 0;
      (status = g_MasterCardCount + 0x10, local_8 < g_MasterCardCount + 0x10 &&
      (status = local_8,
      *(int *)(&g_MasterCardTypeTable + local_8 * 0x34) != *(int *)(&Scards + arg1 * 0x10)));
      local_8 = local_8 + 1) {
  }
  return status;
}

/*
 * Bazaar_SellCardsDialog
 * Purpose: Display interactive card shop / sell dialog.
 * Procedure:
 * 1. Render list of owned cards with sell values.
 * 2. Process player confirmation to sell card for gold.
 * 3. Update player gold total.
 */
/*
 * Decompiled function: Bazaar_SellCardsDialog
 * Entry Point: 004f0e47
 * Size: 1899 bytes
 */

int Bazaar_SellCardsDialog(int arg1)

{
  int status;
  uint arg_1_00;
  char *file_name;
  uint local_17a0;
  int local_1798;
  int local_1794;
  int local_1790;
  int aiStackY_178c [500];
  int local_fbc;
  int aiStackY_fb8 [500];
  int aiStackY_7e8 [493];
  int uStackY_34;
  int val_result;
  int temp_idx;
  
  Mem_AllocOrFree_00513bd0();
  Adventure_LoadFacePalette(1);
  local_1798 = 0;
  do {
    *(int *)g_DisplaySurfaceScreen = 1;
    FUN_0050d560(*(int *)g_DisplaySurfaceScreen,(-(uint)(arg1 == 0) & 0xffffff0f) + 0xf4);
    Duel_TriggerCardDrawAnimation();
    temp_idx = 0;
    for (val_result = 0; val_result < 500; val_result = val_result + 1) {
    }
    local_1794 = 0;
    for (val_result = 499; -1 < val_result; val_result = val_result + -1) {
      if (*(int *)(&deck + val_result * 4) != -1) {
        if (g_MasterCardCount + -0x1d < (int)(*(uint *)(&deck + val_result * 4) & 0xfff)) {
          *(int *)(&deck + val_result * 4) = 0xffffffff;
        }
        else if (local_1798 == 1) {
          if (((&DAT_00702151)[val_result * 4] & 0x40) == 0) goto LAB_004f108c;
        }
        else if ((local_1798 != 2) || (((&DAT_00702151)[val_result * 4] & 0x40) != 0)) {
LAB_004f108c:
          if (local_1798 == 0) {
            local_17a0 = *(uint *)(&deck + val_result * 4) & 0xc000;
          }
          else {
            local_17a0 = 0;
          }
          val_result = (0x28 < DAT_0067bde8) - 1;
          FUN_00484e2d(*(uint *)(&deck + local_17a0 * 4) & 0xfff,
                       (*(uint *)(&deck + local_17a0 * 4) & 7) + temp_idx + 4,val_result,local_17a0,val_result);
          status = temp_idx + 4;
          val_result = Ai_Util_004c3ba3(status);
          aiStackY_fb8[local_1794] = val_result;
          val_result = 0x4f1127;
          status = Ai_Util_004c3ba3(status);
          aiStackY_178c[local_1794] = status;
          aiStackY_7e8[local_1794] = val_result;
          local_1794 = local_1794 + 1;
          temp_idx = temp_idx + 0x40;
          if (0x13f < temp_idx) {
            temp_idx = 0;
          }
        }
      }
    }
    *(int *)g_DisplaySurfaceScreen = 0;
    uStackY_34 = 0x4f11b4;
    Surface_BlitToDevice((int *)g_DisplaySurfaceBackBuffer,0,0,g_DisplayScreenWidth,g_DisplayScreenHeight,
                 (int *)g_DisplaySurfaceScreen,0,0);
    if (arg1 == 0) {
      Ai_Subsystem_004cd1d1();
      return 0;
    }
    if (0 < arg1) {
      FUN_0040c3cc(s_F1__all_cards__F2__active_cards__00530004,0xa0,2,0);
    }
    Pic_Subsystem_0044b8aa();
    do {
      Pic_Subsystem_0044b84b();
      if (DAT_0067bda0 != 0) break;
      val_result = Mem_AllocOrFree_00408089();
    } while (val_result == 0);
    Pic_Subsystem_0044b8da();
    if (DAT_0067bda0 == 0) {
      local_fbc = FUN_0048ac2f();
      if (local_fbc == 0x72) {
        FUN_00484691(4,0);
      }
      else if (local_fbc == 0x52) {
        FUN_00484691(4,1);
      }
      else if (local_fbc == 0x62) {
        FUN_00484691(1,0);
      }
      else if (local_fbc == 0x42) {
        FUN_00484691(1,1);
      }
      else if (local_fbc == 0x75) {
        FUN_00484691(2,0);
      }
      else if (local_fbc == 0x55) {
        FUN_00484691(2,1);
      }
      else if (local_fbc == 0x67) {
        FUN_00484691(3,0);
      }
      else if (local_fbc == 0x47) {
        FUN_00484691(3,1);
      }
      else if (local_fbc == 0x77) {
        FUN_00484691(5,0);
      }
      else if (local_fbc == 0x57) {
        FUN_00484691(5,1);
      }
      else if (local_fbc == 0x3b00) {
        local_1798 = 0;
      }
      else if (local_fbc == 0x3c00) {
        local_1798 = 1;
      }
      else if (local_fbc == 0x3d00) {
        local_1798 = 2;
      }
      else {
        if (local_fbc != 0x3f00) {
          return -1;
        }
        Palette_Subsystem_004981b5(1);
      }
    }
    else {
      local_1790 = -1;
      for (val_result = 0; val_result < local_1794; val_result = val_result + 1) {
        if ((((aiStackY_fb8[val_result] <= DAT_0067bda4) && (DAT_0067bda4 < aiStackY_fb8[val_result] + 0x62))
            && (aiStackY_178c[val_result] <= DAT_0067bda8)) &&
           (DAT_0067bda8 < aiStackY_178c[val_result] + 0x74)) {
          local_1790 = aiStackY_7e8[val_result];
        }
      }
      if (arg1 == -1) {
        return local_1790;
      }
      if (local_1790 == -1) {
        return local_1794;
      }
      if (DAT_0067bda0 == 2) {
        arg_1_00 = *(uint *)(&deck + local_1790 * 4) & 0xfff;
        val_result = SellPrice(arg_1_00);
        strcpy(&g_OverworldWorldState,s_Sell_00530048);
        strcat(&g_OverworldWorldState,s_Swamp_0051aea9 + arg_1_00 * 0x34);
        strcat(&g_OverworldWorldState,s_for_00530050);
        file_name = _itoa(val_result,&DAT_00565a10,10);
        strcat(&g_OverworldWorldState,file_name);
        strcat(&g_OverworldWorldState,s_gold___Y_N__00530058);
        Ai_Subsystem_004cc50a(arg_1_00,0xf6,&g_OverworldWorldState);
        temp_idx = FUN_0048ac2f();
        if (temp_idx == 0x79) {
          Gold = Gold + val_result;
          Pic_Subsystem_00452065(local_1790);
        }
      }
      if (DAT_0067bda0 == 1) {
        *(uint *)(&deck + local_1790 * 4) = *(uint *)(&deck + local_1790 * 4) ^ 0x4000;
      }
      App_ProcessPendingMessages();
    }
  } while( true );
}

/*
 * Catalog_LoadWaveletCardArt
 * Purpose: Open MedArt.cat or SmallArt.cat archive and decompress Haar wavelet illustration.
 * Procedure:
 * 1. Open catalog archive file.
 * 2. Read compressed wavelet coefficients for card ID.
 * 3. Decompress 2D Haar wavelets into 8-bit bitmap buffer.
 * 4. Return decompressed bitmap pointer.
 */
/*
 * Decompiled function: Catalog_LoadWaveletCardArt
 * Entry Point: 004f15c0
 * Size: 841 bytes
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * Catalog_LoadWaveletCardArt(int arg1,char *file_name,int arg3)

{
  char c_res;
  uint u_temp;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *puVar7;
  char *pcVar8;
  char *pcVar9;
  int *puVar10;
  char local_40c [260];
  char local_308 [264];
  char local_200 [256];
  char local_100 [256];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  _splitpath(file_name,(char *)0x0,local_40c,local_200,local_100);
  if (DAT_00566224 == 0) {
    u_temp = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (u_temp == 0) break;
      u_temp = u_temp - 1;
      pcVar9 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar9;
    } while (c_res != '\0');
    u_temp = ~u_temp;
    pcVar6 = pcVar9 + -u_temp;
    pcVar9 = local_308;
    for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(int *)pcVar9 = *(int *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    u_temp = 0xffffffff;
    pcVar6 = s_SmallArt_cat_005300c4;
    do {
      pcVar9 = pcVar6;
      if (u_temp == 0) break;
      u_temp = u_temp - 1;
      pcVar9 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar9;
    } while (c_res != '\0');
    u_temp = ~u_temp;
    iVar4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar8;
    } while (c_res != '\0');
    pcVar6 = pcVar9 + -u_temp;
    pcVar9 = pcVar8 + -1;
    for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(int *)pcVar9 = *(int *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_005300a4 = Catalog_Open(local_308);
    u_temp = 0xffffffff;
    pcVar6 = local_40c;
    do {
      pcVar9 = pcVar6;
      if (u_temp == 0) break;
      u_temp = u_temp - 1;
      pcVar9 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar9;
    } while (c_res != '\0');
    u_temp = ~u_temp;
    pcVar6 = pcVar9 + -u_temp;
    pcVar9 = local_308;
    for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(int *)pcVar9 = *(int *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    u_temp = 0xffffffff;
    pcVar6 = s_MedArt_cat_005300b8;
    do {
      pcVar9 = pcVar6;
      if (u_temp == 0) break;
      u_temp = u_temp - 1;
      pcVar9 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar9;
    } while (c_res != '\0');
    u_temp = ~u_temp;
    iVar4 = -1;
    pcVar6 = local_308;
    do {
      pcVar8 = pcVar6;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar6 + 1;
      c_res = *pcVar6;
      pcVar6 = pcVar8;
    } while (c_res != '\0');
    pcVar6 = pcVar9 + -u_temp;
    pcVar9 = pcVar8 + -1;
    for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(int *)pcVar9 = *(int *)pcVar6;
      pcVar6 = pcVar6 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
      *pcVar9 = *pcVar6;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    }
    DAT_005300a8 = Catalog_Open(local_308);
    DAT_00566224 = 1;
  }
  iVar4 = -1;
  pcVar6 = local_40c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    c_res = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (c_res != '\0');
  iVar4 = DAT_005300a4;
  if ((arg1 != 0) && (iVar4 = DAT_005300a8, arg1 != 1)) {
    return (int *)0x0;
  }
  u_temp = 0xffffffff;
  pcVar6 = local_200;
  do {
    pcVar9 = pcVar6;
    if (u_temp == 0) break;
    u_temp = u_temp - 1;
    pcVar9 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar9;
  } while (c_res != '\0');
  u_temp = ~u_temp;
  pcVar6 = pcVar9 + -u_temp;
  pcVar9 = local_40c;
  for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(int *)pcVar9 = *(int *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  u_temp = 0xffffffff;
  pcVar6 = local_100;
  do {
    pcVar9 = pcVar6;
    if (u_temp == 0) break;
    u_temp = u_temp - 1;
    pcVar9 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar9;
  } while (c_res != '\0');
  u_temp = ~u_temp;
  iVar5 = -1;
  pcVar6 = local_40c;
  do {
    pcVar8 = pcVar6;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar8 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar8;
  } while (c_res != '\0');
  pcVar6 = pcVar9 + -u_temp;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(int *)pcVar9 = *(int *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_0061d7e0 = iVar4;
  _strlwr(local_40c);
  puVar7 = &DAT_00566230;
  for (iVar4 = 0x6c; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  u_temp = 0xffffffff;
  pcVar6 = file_name;
  do {
    pcVar9 = pcVar6;
    if (u_temp == 0) break;
    u_temp = u_temp - 1;
    pcVar9 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar9;
  } while (c_res != '\0');
  u_temp = ~u_temp;
  pcVar6 = pcVar9 + -u_temp;
  pcVar9 = (char *)&DAT_005662cc;
  for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(int *)pcVar9 = *(int *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  DAT_005663d0 = (int *)&DAT_005e0be0;
  iVar4 = Catalog_ReadFile(DAT_0061d7e0,local_40c,(int *)&DAT_005663d0);
  if (iVar4 != -1) {
    _DAT_005663d4 = iVar4 + -0x9c;
    puVar7 = DAT_005663d0;
    puVar10 = &DAT_00566230;
    for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar10 = puVar10 + 1;
    }
    DAT_005663d0 = DAT_005663d0 + 0x27;
    if (DAT_00566258 == 4) {
      DAT_0056624c = DAT_0056624c * 2;
      DAT_00566250 = DAT_00566250 * 2;
    }
    if (arg3 != 0) {
      _DAT_005663dc = Haar_DecompressWaveletImage(&DAT_00566230,(undefined8 *)0x0);
      if (_DAT_005663dc == 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
        return (int *)0x0;
      }
      _DAT_005663d8 = 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
    }
    return &DAT_00566230;
  }
  u_temp = 0xffffffff;
  pcVar6 = (char *)&DAT_005300b4;
  do {
    pcVar9 = pcVar6;
    if (u_temp == 0) break;
    u_temp = u_temp - 1;
    pcVar9 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar9;
  } while (c_res != '\0');
  u_temp = ~u_temp;
  iVar4 = -1;
  pcVar6 = file_name;
  do {
    pcVar8 = pcVar6;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar6 + 1;
    c_res = *pcVar6;
    pcVar6 = pcVar8;
  } while (c_res != '\0');
  pcVar6 = pcVar9 + -u_temp;
  pcVar9 = pcVar8 + -1;
  for (uVar3 = u_temp >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(int *)pcVar9 = *(int *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (u_temp = u_temp & 3; u_temp != 0; u_temp = u_temp - 1) {
    *pcVar9 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  }
  OutputDebugStringA(file_name);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  return (int *)0x0;
}

/*
 * Catalog_ReleaseWaveletLock
 * Purpose: Release concurrency lock on wavelet decompression cache.
 * Procedure:
 * 1. Leave critical section for wavelet cache.
 */
/*
 * Decompiled function: Catalog_ReleaseWaveletLock
 * Entry Point: 004f1910
 * Size: 14 bytes
 */

int Catalog_ReleaseWaveletLock(void)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_006ff490);
  return 0;
}

