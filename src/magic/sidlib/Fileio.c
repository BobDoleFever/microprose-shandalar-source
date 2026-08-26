/*
 * sidlib/Fileio.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: FileIO_OpenFileStream
 * Entry Point: 00510b70
 * Size: 610 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FileIO_OpenFileStream(int player_id,int card_slot,int event_type,char *str_4,short *arg_5)

{
  char *_Str2;
  int val_1;
  int32_t extraout_ECX;
  int32_t extraout_ECX_00;
  int32_t arg_1_00;
  int32_t extraout_EDX;
  int32_t extraout_EDX_00;
  int32_t arg_2_00;
  short local_400 [512];
  
  _Str2 = strchr(str_4,0x2e);
  val_1 = _stricmp(&DAT_005327f4,_Str2);
  if (val_1 != 0) {
    val_1 = _open(str_4,0x8000);
    arg_1_00 = extraout_ECX;
    arg_2_00 = extraout_EDX;
    if (val_1 == -1) {
      AssertOrLog(0,0x5327b8,0x87,str_4);
      arg_1_00 = extraout_ECX_00;
      arg_2_00 = extraout_EDX_00;
    }
    DAT_00706500 = PTR_DAT_005327b0;
    _DAT_006261ac = 0xffffffff;
    DAT_0067f43c = &LAB_00510f90;
    DAT_006261a8 = val_1;
    DAT_006261b0 = val_1;
    Pic_ReadCompressedChunk(arg_1_00,arg_2_00,(uint16_t *)arg_5);
    if (arg_1 < 0) {
      g_PicSourceHeight = 0;
    }
    DAT_006261a4 = 0;
    if (0 < g_PicSourceHeight) {
      do {
        Mem_AllocOrFree_0070d484(&DAT_00706710,g_PicSourceWidth);
        Surface_PutLine((int32_t *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,g_PicSourceWidth);
        DAT_006261a4 = DAT_006261a4 + 1;
      } while (DAT_006261a4 < g_PicSourceHeight);
    }
    if ((DAT_005327b4 != DAT_006261b0) && (val_1 = _close(DAT_006261b0), val_1 != 0)) {
      AssertOrLog(0,0x5327b8,0xa7,(char *)0x0);
    }
    return;
  }
  g_PicFileStream = (int)fopen(str_4,&DAT_0052afc4);
  AssertOrLog((uint32_t)((FILE *)g_PicFileStream != (FILE *)0x0),0x5327b8,0xf6,
              s_Error_Opening_File__s_005327dc);
  DAT_00703938 = str_4;
  if (arg_5 == (short *)0x1) {
    arg_5 = local_400;
  }
  if (arg_5 == (short *)0x0) {
    Pic_DecodeKimpicHeader((void *)0x0);
  }
  else {
    Pic_DecodeKimpicHeader(arg_5 + 3);
    *(uint8_t *)arg_5 = 0x4d;
    *(uint8_t *)((int)arg_5 + 1) = 0x31;
    arg_5[1] = 0x300;
    *(uint8_t *)(arg_5 + 2) = 0;
    *(uint8_t *)((int)arg_5 + 5) = 0xff;
    FUN_0050e8b0(arg_5);
  }
  if (arg_1 < 0) {
    g_PicSourceHeight = 0;
  }
  DAT_006261a4 = 0;
  if (0 < g_PicSourceHeight) {
    do {
      Pic_DecodeKimpicScanline(&DAT_00706710);
      Surface_PutLine((int32_t *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,g_PicSourceWidth);
      DAT_006261a4 = DAT_006261a4 + 1;
    } while (DAT_006261a4 < g_PicSourceHeight);
  }
  fclose((FILE *)g_PicFileStream);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510de0
 * Entry Point: 00510de0
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510de0(int arg1,char *mode_str)

{
  FileIO_OpenFileStream(arg1,0,0,str_2,(short *)0x1);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510e20
 * Entry Point: 00510e20
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510e20(int arg1,char *mode_str)

{
  FileIO_OpenFileStream(arg1,0,0,str_2,(short *)0x0);
  return;
}



/*
 * Decompiled function: LoadPalNoPic
 * Entry Point: 00510e40
 * Size: 22 bytes
 */


void LoadPalNoPic(char *filepath)

{
                    /* 0x110e40  5  LoadPalNoPic */
  FileIO_OpenFileStream(-1,0,0,filepath,(short *)0x1);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510e60
 * Entry Point: 00510e60
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510e60(char *filepath,short *arg2)

{
  FileIO_OpenFileStream(-1,0,0,str_1,arg2);
  return;
}



/*
 * Decompiled function: FUN_00510fc0
 * Entry Point: 00510fc0
 * Size: 350 bytes
 */


void FUN_00510fc0(int *arg1,int *arg2)

{
  int val_1;
  int val_2;
  int val_3;
  int val_4;
  int val_5;
  int color_idx;
  
  val_1 = *arg2;
  val_2 = arg2[1];
  val_3 = arg2[2];
  val_5 = val_2;
  if (val_2 <= val_3) {
    val_5 = val_3;
  }
  if (val_5 <= val_1) {
    val_5 = val_1;
  }
  color_idx = val_2;
  if (val_3 <= val_2) {
    color_idx = val_3;
  }
  if (val_1 <= color_idx) {
    color_idx = val_1;
  }
  if (val_5 != 0) {
    color_idx = val_5 - color_idx;
    val_4 = (color_idx * 0x1000) / val_5;
    if (color_idx == 0) {
      *arg1 = 0;
      arg1[1] = val_4;
      arg1[2] = val_5 << 6;
      return;
    }
    if (val_5 == val_1) {
      color_idx = ((val_2 - val_3) * 0xf00) / color_idx;
    }
    else if (val_5 == val_2) {
      color_idx = ((val_3 - val_1) * 0xf00) / color_idx + 0x1e00;
    }
    else {
      color_idx = ((val_1 - val_2) * 0xf00) / color_idx + 0x3c00;
    }
    if (color_idx < 0) {
      color_idx = color_idx + 0x5a00;
    }
    *arg1 = color_idx;
    arg1[1] = val_4;
    arg1[2] = val_5 << 6;
    return;
  }
  *arg1 = -1;
  arg1[1] = 0;
  arg1[2] = 0;
  return;
}



/*
 * Decompiled function: FUN_00511120
 * Entry Point: 00511120
 * Size: 364 bytes
 */


void FUN_00511120(uint32_t *arg1,int *arg2)

{
  int val_1;
  uint32_t uval_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t card_idx;
  uint32_t match_count;
  uint32_t slot_idx;
  uint32_t local_4;
  
  val_1 = arg2[1];
  if ((val_1 == 0) && (*arg2 == -1)) {
    uval_2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
    *arg1 = uval_2;
    arg1[1] = uval_2;
    arg1[2] = uval_2;
    arg1[3] = local_4;
    return;
  }
  if (*arg2 == 0x5a00) {
    *arg2 = 0;
  }
  uval_2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
  val_3 = (0x1000 - val_1) * uval_2;
  uval_4 = (int)(val_3 + (val_3 >> 0x1f & 0xfffU)) >> 0xc;
  uval_5 = ((0xf00000 - val_1 * (*arg2 % 0xf00)) * uval_2) / 0xf00000;
  card_idx = 0xf00;
  uval_6 = (((*arg2 % 0xf00 + -0xf00) * val_1 + 0xf00000) * uval_2) / 0xf00000;
  switch(*arg2 / 0xf00) {
  case 0:
    card_idx = uval_2;
    match_count = uval_6;
    slot_idx = uval_4;
    break;
  case 1:
    card_idx = uval_5;
    match_count = uval_2;
    slot_idx = uval_4;
    break;
  case 2:
    card_idx = uval_4;
    match_count = uval_2;
    slot_idx = uval_6;
    break;
  case 3:
    card_idx = uval_4;
    match_count = uval_5;
    slot_idx = uval_2;
    break;
  case 4:
    card_idx = uval_6;
    match_count = uval_4;
    slot_idx = uval_2;
    break;
  case 5:
    card_idx = uval_2;
    match_count = uval_4;
    slot_idx = uval_5;
  }
  *arg1 = card_idx;
  arg1[1] = match_count;
  arg1[2] = slot_idx;
  arg1[3] = local_4;
  return;
}



/*
 * Decompiled function: FUN_005112b0
 * Entry Point: 005112b0
 * Size: 747 bytes
 */


int FUN_005112b0(short arg1,short arg2)

{
  int val_1;
  int32_t *u_ptr_2;
  int val_3;
  int val_4;
  int val_5;
  int val_6;
  short sVar7;
  int32_t *puVar8;
  uint8_t *pbVar9;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int32_t color_idx;
  int target_idx;
  int player_idx;
  uint32_t card_idx [4];
  
  val_6 = (int)arg2;
  val_1 = (int)(0x4000 / (longlong)val_6);
  if (DAT_0070a880 != 8) {
    return (uint32_t)(uint16_t)((ulonglong)(0x4000 / (longlong)val_6) >> 0x10) << 0x10;
  }
  u_ptr_2 = &DAT_0070a130;
  puVar8 = &DAT_007051e0;
  for (val_4 = 0xc0; val_4 != 0; val_4 = val_4 + -1) {
    *puVar8 = *u_ptr_2;
    u_ptr_2 = u_ptr_2 + 1;
    puVar8 = puVar8 + 1;
  }
  local_2c = (int)arg1;
  local_28 = local_2c;
  local_24 = local_2c;
  u_ptr_2 = (int32_t *)FUN_00510fc0((int *)card_idx,&local_2c);
  color_idx = *u_ptr_2;
  target_idx = u_ptr_2[1];
  player_idx = u_ptr_2[2];
  sVar7 = 0;
  FUN_0050e8b0((short *)&DAT_0070a130);
  do {
    val_5 = (int)sVar7;
    pbVar9 = (uint8_t *)(val_5 * 3 + DAT_00532804);
    (&DAT_00705500)[val_5 * 4] = (uint32_t)*pbVar9;
    (&DAT_00705504)[val_5 * 4] = (uint32_t)pbVar9[1];
    (&DAT_00705508)[val_5 * 4] = (uint32_t)pbVar9[2];
    u_ptr_2 = (int32_t *)FUN_00510fc0((int *)card_idx,&DAT_00705500 + val_5 * 4);
    (&DAT_007039e0)[val_5 * 3] = *u_ptr_2;
    (&DAT_007039e4)[val_5 * 3] = u_ptr_2[1];
    (&DAT_007039e8)[val_5 * 3] = u_ptr_2[2];
    val_4 = (target_idx - (&DAT_007039e4)[val_5 * 3]) / val_6;
    (&DAT_007045e4)[val_5 * 3] = val_4;
    if ((int)(&DAT_007039e4)[val_5 * 3] < target_idx) {
      val_3 = 0x1000;
    }
    else {
      val_3 = -0x1000;
    }
    sVar7 = sVar7 + 1;
    (&DAT_007045e4)[val_5 * 3] = val_3 / val_6 + val_4;
  } while (sVar7 < 0x100);
  local_3e = 1;
  if (0 < arg2) {
    do {
      sVar7 = 0;
      do {
        val_6 = (int)sVar7;
        if (player_idx == 0) {
          local_38 = (&DAT_007039e0)[val_6 * 3];
          local_34 = (&DAT_007039e4)[val_6 * 3];
          local_30 = (&DAT_007039e8)[val_6 * 3] - val_1;
          (&DAT_007039e8)[val_6 * 3] = local_30;
        }
        else {
          local_38 = (&DAT_007039e0)[val_6 * 3];
          local_34 = (&DAT_007045e4)[val_6 * 3] * (int)local_3e + (&DAT_007039e4)[val_6 * 3];
          if (0xfbf < local_34) {
            local_34 = 0xfc0;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          val_4 = val_1;
          if (player_idx < (int)(&DAT_007039e8)[val_6 * 3]) {
            val_4 = -val_1;
          }
          (&DAT_007039e8)[val_6 * 3] = (&DAT_007039e8)[val_6 * 3] + val_4;
          local_30 = (&DAT_007039e8)[val_6 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        if (local_30 < 1) {
          local_30 = 0;
        }
        val_4 = (int)sVar7;
        sVar7 = sVar7 + 1;
        u_ptr_2 = (int32_t *)FUN_00511120(card_idx,&local_38);
        (&DAT_00705500)[val_4 * 4] = *u_ptr_2;
        (&DAT_00705504)[val_4 * 4] = u_ptr_2[1];
        val_6 = val_4 * 3;
        (&DAT_00705508)[val_4 * 4] = u_ptr_2[2];
        (&DAT_0070550c)[val_4 * 4] = u_ptr_2[3];
        *(uint8_t *)(DAT_00532804 + val_6) = *(uint8_t *)(&DAT_00705500 + val_4 * 4);
        *(uint8_t *)(DAT_00532804 + 1 + val_6) = *(uint8_t *)(&DAT_00705504 + val_4 * 4);
        *(uint8_t *)(DAT_00532804 + 2 + val_6) = *(uint8_t *)(&DAT_00705508 + val_4 * 4);
      } while (sVar7 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + 1;
    } while (local_3e <= arg2);
  }
  sVar7 = 0;
  do {
    val_1 = (int)sVar7;
    sVar7 = sVar7 + 1;
    val_1 = val_1 * 3;
    *(uint8_t *)(DAT_00532804 + val_1) = (uint8_t)local_2c;
    *(uint8_t *)(DAT_00532804 + 1 + val_1) = (uint8_t)local_28;
    *(uint8_t *)(DAT_00532804 + 2 + val_1) = (uint8_t)local_24;
  } while (sVar7 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  val_1 = FUN_0050d560(0,0);
  return val_1;
}



/*
 * Decompiled function: FUN_005115a0
 * Entry Point: 005115a0
 * Size: 784 bytes
 */


int FUN_005115a0(short arg1,short arg2)

{
  uint8_t uval_1;
  short len_2;
  int val_3;
  int32_t *puVar4;
  int val_5;
  int *piVar6;
  uint8_t *pbVar7;
  uint8_t *puVar8;
  int iVar9;
  int16_t *puVar10;
  int iVar11;
  uint8_t *puVar12;
  bool bVar13;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  int16_t local_2c;
  uint8_t local_2a;
  int32_t color_idx;
  int target_idx;
  int player_idx;
  int card_idx;
  int match_count;
  int slot_idx;
  
  iVar11 = (int)arg2;
  val_3 = (int)(0x3fc0 / (longlong)iVar11);
  if (DAT_0070a880 != 8) {
    return (uint32_t)(uint16_t)((ulonglong)(0x3fc0 / (longlong)iVar11) >> 0x10) << 0x10;
  }
  local_2c = CONCAT11((uint8_t)arg1,(uint8_t)arg1);
  local_2a = (uint8_t)arg1;
  iVar9 = 0x2ff;
  puVar8 = DAT_00532804;
  puVar12 = DAT_00532808;
  do {
    uval_1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uval_1;
    puVar12 = puVar12 + 1;
    bVar13 = iVar9 != 0;
    iVar9 = iVar9 + -1;
  } while (bVar13);
  len_2 = 0;
  do {
    iVar9 = (int)len_2;
    len_2 = len_2 + 1;
    puVar10 = (int16_t *)(DAT_00532804 + iVar9 * 3);
    *puVar10 = local_2c;
    *(uint8_t *)(puVar10 + 1) = (uint8_t)arg1;
  } while (len_2 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  card_idx = (int)arg1;
  match_count = card_idx;
  slot_idx = card_idx;
  puVar4 = (int32_t *)FUN_00510fc0((int *)&local_2c,&card_idx);
  len_2 = 0;
  color_idx = *puVar4;
  target_idx = puVar4[1];
  player_idx = puVar4[2];
  do {
    iVar9 = (int)len_2;
    pbVar7 = DAT_00532808 + iVar9 * 3;
    (&DAT_00705500)[iVar9 * 4] = (uint32_t)*pbVar7;
    (&DAT_00705504)[iVar9 * 4] = (uint32_t)pbVar7[1];
    (&DAT_00705508)[iVar9 * 4] = (uint32_t)pbVar7[2];
    puVar4 = (int32_t *)FUN_00510fc0((int *)&local_2c,&DAT_00705500 + iVar9 * 4);
    (&DAT_007039e0)[iVar9 * 3] = *puVar4;
    (&DAT_007039e4)[iVar9 * 3] = puVar4[1];
    (&DAT_007039e8)[iVar9 * 3] = puVar4[2];
    (&DAT_007045e4)[iVar9 * 3] = (target_idx - (&DAT_007039e4)[iVar9 * 3]) / iVar11;
    if ((int)(&DAT_007039e4)[iVar9 * 3] < target_idx) {
      val_5 = 0x1000;
    }
    else {
      val_5 = -0x1000;
    }
    len_2 = len_2 + 1;
    (&DAT_007045e4)[iVar9 * 3] = val_5 / iVar11;
  } while (len_2 < 0x100);
  local_3e = arg2;
  if (0 < arg2) {
    do {
      len_2 = 0;
      do {
        iVar11 = (int)len_2;
        if (player_idx == 0) {
          local_38 = (&DAT_007039e0)[iVar11 * 3];
          local_34 = (&DAT_007039e4)[iVar11 * 3];
          local_30 = (&DAT_007039e8)[iVar11 * 3] - local_3e * val_3;
          if (local_30 < 1) {
            local_30 = 0;
          }
        }
        else {
          local_38 = (&DAT_007039e0)[iVar11 * 3];
          local_34 = (&DAT_007045e4)[iVar11 * 3] * (int)local_3e + (&DAT_007039e4)[iVar11 * 3];
          if (0xfff < local_34) {
            local_34 = 0x1000;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          local_30 = val_3 * local_3e + (&DAT_007039e8)[iVar11 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        val_5 = (int)len_2;
        piVar6 = (int *)FUN_00511120((uint32_t *)&local_2c,&local_38);
        (&DAT_00705500)[val_5 * 4] = *piVar6;
        (&DAT_00705504)[val_5 * 4] = piVar6[1];
        iVar9 = val_5 * 3;
        (&DAT_00705508)[val_5 * 4] = piVar6[2];
        (&DAT_0070550c)[val_5 * 4] = piVar6[3];
        iVar11 = (&DAT_00705500)[val_5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9] = (char)iVar11;
        iVar11 = (&DAT_00705504)[val_5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9 + 1] = (char)iVar11;
        iVar11 = (&DAT_00705508)[val_5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        len_2 = len_2 + 1;
        DAT_00532804[iVar9 + 2] = (char)iVar11;
      } while (len_2 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + -1;
    } while (local_3e != 0);
  }
  val_3 = 0x2ff;
  puVar8 = DAT_00532808;
  puVar12 = DAT_00532804;
  do {
    uval_1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uval_1;
    puVar12 = puVar12 + 1;
    bVar13 = val_3 != 0;
    val_3 = val_3 + -1;
  } while (bVar13);
  val_3 = FUN_0050e8b0((short *)&DAT_0070a130);
  return val_3;
}



/*
 * Decompiled function: FUN_00511930
 * Entry Point: 00511930
 * Size: 172 bytes
 */


int32_t
FUN_00511930(HDC hdc,COLORREF arg_2,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8)

{
  HDC hdc_00;
  HBITMAP h;
  HBRUSH hbr;
  RECT card_idx;
  
  card_idx.left = 0;
  card_idx.top = 0;
  card_idx.right = arg_5;
  card_idx.bottom = arg_6;
  hdc_00 = CreateCompatibleDC(hdc);
  h = CreateCompatibleBitmap(hdc,arg_5,arg_6);
  hbr = CreateSolidBrush(arg_2);
  SelectObject(hdc_00,h);
  FillRect(hdc_00,&card_idx,hbr);
  FUN_005119e0(hdc,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8,hdc_00);
  DeleteDC(hdc_00);
  DeleteObject(hbr);
  DeleteObject(h);
  return 0;
}



/*
 * Decompiled function: FUN_005119e0
 * Entry Point: 005119e0
 * Size: 425 bytes
 */


uint32_t FUN_005119e0(HDC hdc,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8)

{
  int val_1;
  int val_2;
  int val_3;
  int y;
  COLORREF color;
  uint32_t uval_4;
  int x;
  int x_00;
  int y_00;
  int cy;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t card_idx;
  
  val_1 = (uint32_t)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  val_2 = (uint32_t)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  uval_4 = 0x40000000;
  uval_6 = 0;
  uval_5 = (val_2 + 1) * (val_1 + 1);
  val_3 = 0;
  do {
    if ((uval_4 & uval_5) != 0) {
      if (uval_6 == 0) {
        uval_6 = uval_4;
      }
      val_3 = val_3 + 1;
    }
    uval_4 = (int)uval_4 >> 1;
  } while (uval_4 != 0);
  if (val_3 != 1) {
    uval_6 = uval_6 * 2;
  }
  card_idx = 0;
  uval_4 = 1;
  if (1 < (int)uval_6) {
    do {
      card_idx = card_idx | uval_4;
      uval_4 = uval_4 * 2;
    } while ((int)uval_4 < (int)uval_6);
  }
  val_3 = rand();
  uval_4 = val_3 % (int)uval_6;
  uval_6 = val_3 / (int)uval_6;
  while (uval_5 != 0) {
    uval_4 = uval_4 * 0x21 + 1 & card_idx;
    uval_6 = uval_4;
    if ((int)uval_4 <= val_2 * val_1) {
      y = (int)uval_4 / val_1;
      x_00 = (int)uval_4 % val_1;
      x = x_00 * arg_6 + arg_2;
      y_00 = y * arg_7 + arg_3;
      val_3 = arg_6;
      if (arg_4 + arg_2 <= arg_6 + x) {
        val_3 = (arg_2 - x) + arg_4;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_3 - y_00) + arg_5;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x_00,y);
        uval_6 = SetPixelV(hdc,x_00,y,color);
      }
      else {
        uval_6 = BitBlt(hdc,x,y_00,val_3,cy,param_8,x,y_00,0xcc0020);
      }
      uval_5 = uval_5 - 1;
    }
  }
  return uval_6;
}



/*
 * Decompiled function: FUN_00511b90
 * Entry Point: 00511b90
 * Size: 461 bytes
 */


uint32_t FUN_00511b90(HDC hdc,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8,
                 int arg_9,int arg_10)

{
  int val_1;
  int val_2;
  uint32_t uval_3;
  int y;
  COLORREF color;
  int val_4;
  int x;
  int y_00;
  int cx;
  int cy;
  uint32_t uval_5;
  uint32_t uval_6;
  uint32_t color_idx;
  
  val_1 = (uint32_t)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  val_2 = (uint32_t)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  val_4 = 0;
  uval_6 = 0;
  uval_5 = (val_2 + 1) * (val_1 + 1);
  uval_3 = 0x40000000;
  do {
    if ((uval_5 & uval_3) != 0) {
      if (uval_6 == 0) {
        uval_6 = uval_3;
      }
      val_4 = val_4 + 1;
    }
    uval_3 = (int)uval_3 >> 1;
  } while (uval_3 != 0);
  if (val_4 != 1) {
    uval_6 = uval_6 * 2;
  }
  color_idx = 0;
  uval_3 = 1;
  if (1 < (int)uval_6) {
    do {
      color_idx = color_idx | uval_3;
      uval_3 = uval_3 * 2;
    } while ((int)uval_3 < (int)uval_6);
  }
  val_4 = rand();
  uval_3 = val_4 % (int)uval_6;
  uval_6 = val_4 / (int)uval_6;
  while (uval_5 != 0) {
    uval_3 = uval_3 * 0x21 + 1 & color_idx;
    uval_6 = uval_3;
    if ((int)uval_3 <= val_2 * val_1) {
      y = (int)uval_3 / val_1;
      x = (int)uval_3 % val_1;
      val_4 = arg_2 + x * arg_6;
      y_00 = arg_3 + y * arg_7;
      cx = arg_6;
      if (arg_4 + arg_2 <= arg_6 + val_4) {
        cx = (arg_4 - val_4) + arg_2;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_5 - y_00) + arg_3;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x,y);
        uval_6 = SetPixelV(hdc,x,y,color);
      }
      else {
        uval_6 = BitBlt(hdc,val_4,y_00,cx,cy,param_8,arg_9 + x * arg_6,arg_10 + y * arg_7,0xcc0020);
      }
      uval_5 = uval_5 - 1;
    }
  }
  return uval_6;
}



/*
 * Decompiled function: FUN_00511d60
 * Entry Point: 00511d60
 * Size: 182 bytes
 */


int32_t
FUN_00511d60(HDC hdc,COLORREF arg_2,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9,int arg_10)

{
  HDC hdc_00;
  HBITMAP h;
  HBRUSH hbr;
  RECT card_idx;
  
  card_idx.left = 0;
  card_idx.top = 0;
  card_idx.right = arg_5;
  card_idx.bottom = arg_6;
  hdc_00 = CreateCompatibleDC(hdc);
  h = CreateCompatibleBitmap(hdc,arg_5,arg_6);
  hbr = CreateSolidBrush(arg_2);
  SelectObject(hdc_00,h);
  FillRect(hdc_00,&card_idx,hbr);
  FUN_00511e20(hdc,arg_3,arg_4,arg_5,arg_6,arg_7,arg_8,arg_9,arg_10,hdc_00);
  DeleteDC(hdc_00);
  DeleteObject(hbr);
  DeleteObject(h);
  return 0;
}



/*
 * Decompiled function: FUN_00511e20
 * Entry Point: 00511e20
 * Size: 846 bytes
 */


void FUN_00511e20(HDC hdc,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
                 int arg_9,HDC param_10)

{
  int y;
  int val_1;
  int val_2;
  int val_3;
  void *_Memory;
  DWORD DVar4;
  int y_00;
  COLORREF color;
  uint32_t uval_5;
  int x;
  int val_6;
  int cx;
  int cy;
  uint32_t uval_7;
  uint32_t uval_8;
  int *piVar9;
  int local_38;
  int local_30;
  int *local_2c;
  int loop_idx;
  int color_idx;
  int target_idx;
  int match_count;
  
  local_38 = -arg_7 + 1;
  val_1 = (uint32_t)(arg_6 % arg_8 != 0) + arg_6 / arg_8;
  uval_5 = 0x40000000;
  uval_7 = ((uint32_t)(arg_5 % arg_9 != 0) + arg_5 / arg_9) * val_1;
  val_2 = (uint32_t)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  uval_8 = 0;
  val_3 = 0;
  do {
    if ((uval_5 & uval_7) != 0) {
      if (uval_8 == 0) {
        uval_8 = uval_5;
      }
      val_3 = val_3 + 1;
    }
    uval_5 = (int)uval_5 >> 1;
  } while (uval_5 != 0);
  if (val_3 != 1) {
    uval_8 = uval_8 * 2;
  }
  _Memory = malloc(((arg_7 + val_2) * 4 + 0x14) * 5);
  DVar4 = GetTickCount();
  val_3 = -arg_7 + 2;
  *(int *)((int)_Memory + local_38 * 0x14 + arg_7 * 0x14) = (int)DVar4 % (int)uval_8;
  local_2c = (int *)((int)_Memory + local_38 * 0x14 + arg_7 * 0x14);
  local_2c[1] = 5;
  local_2c[2] = 1;
  local_2c[3] = uval_8;
  local_2c[4] = uval_8;
  if (val_3 < val_2) {
    piVar9 = (int *)((int)_Memory + val_3 * 0x14 + arg_7 * 0x14);
    do {
      *piVar9 = (piVar9[-5] * 5 + 1) % (int)uval_8;
      val_6 = val_3 % 0x14;
      val_3 = val_3 + 1;
      piVar9[1] = *(int *)(&DAT_00532810 + val_6 * 4) * 4 + 1;
      piVar9[2] = 1;
      piVar9[3] = uval_8;
      piVar9[4] = uval_8;
      piVar9 = piVar9 + 5;
    } while (val_3 < val_2);
  }
  if (local_38 < val_2) {
    target_idx = arg_6 * local_38;
    do {
      color_idx = arg_7;
      if (local_38 < arg_7 + local_38) {
        match_count = arg_7;
        do {
          local_30 = local_38;
          val_3 = local_38 + color_idx;
          if (val_2 <= local_38 + color_idx) {
            val_3 = val_2;
          }
          if (local_38 < val_3) {
            loop_idx = target_idx;
            piVar9 = local_2c;
            do {
              val_6 = (piVar9[1] * *piVar9 + piVar9[2]) % piVar9[3];
              *piVar9 = val_6;
              piVar9[4] = piVar9[4] + -1;
              if (val_6 < (int)uval_7) {
                y_00 = val_6 / val_1;
                val_6 = val_6 % val_1;
                x = val_6 * arg_8 + arg_2 + loop_idx;
                y = y_00 * arg_9 + arg_3;
                cx = arg_8;
                if (arg_4 + arg_2 <= arg_8 + x) {
                  cx = (arg_4 - x) + arg_2;
                }
                cy = arg_9;
                if (arg_5 + arg_3 <= arg_9 + y) {
                  cy = arg_3 + (arg_5 - y);
                }
                if (-1 < local_30) {
                  if ((arg_8 == 1) && (arg_9 == 1)) {
                    color = GetPixel(param_10,val_6,y_00);
                    SetPixel(hdc,val_6,y_00,color);
                  }
                  else {
                    BitBlt(hdc,x,y,cx,cy,param_10,x,y,0xcc0020);
                  }
                }
              }
              loop_idx = loop_idx + arg_6;
              piVar9 = piVar9 + 5;
              local_30 = local_30 + 1;
            } while (local_30 < val_3);
          }
          color_idx = color_idx + -1;
          match_count = match_count + -1;
        } while (match_count != 0);
      }
      if (local_2c[4] < 1) {
        local_2c = local_2c + 5;
        target_idx = target_idx + arg_6;
        local_38 = local_38 + 1;
      }
    } while (local_38 < val_2);
  }
  free(_Memory);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_005121d0
 * Entry Point: 005121d0
 * Size: 6 bytes
 */


int32_t Mem_AllocOrFree_005121d0(void)

{
  return 0xffffffff;
}



/*
 * Decompiled function: Mem_AllocOrFree_005121e0
 * Entry Point: 005121e0
 * Size: 6 bytes
 */


int32_t Mem_AllocOrFree_005121e0(void)

{
  return 0xffffffff;
}



/*
 * Decompiled function: FUN_005121f0
 * Entry Point: 005121f0
 * Size: 9 bytes
 */


void FUN_005121f0(void)

{
  ShowCursor(1);
  return;
}



/*
 * Decompiled function: FUN_00512200
 * Entry Point: 00512200
 * Size: 9 bytes
 */


void FUN_00512200(void)

{
  ShowCursor(0);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00512210
 * Entry Point: 00512210
 * Size: 16 bytes
 */


int32_t Mem_AllocOrFree_00512210(void)

{
  int32_t uval_1;
  
  uval_1 = DAT_007039d0;
  DAT_007039d0 = 0;
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00512220
 * Entry Point: 00512220
 * Size: 1 bytes
 */


void Mem_AllocOrFree_00512220(void)

{
  return;
}



