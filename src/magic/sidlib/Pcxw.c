/*
 * sidlib/Pcxw.c - Reconstructed MicroProse Source Module
 * Program: MAGIC.EXE
 * Contained Functions: 41
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Pcx_Load256ColorPcx
 * Entry Point: 00512230
 * Size: 608 bytes
 */


int32_t * Pcx_Load256ColorPcx(char *filepath,int32_t *arg_2,void *arg_3)

{
  uint8_t *u_ptr_1;
  uint8_t flag_2;
  uint32_t uval_3;
  HGLOBAL pvVar4;
  int val_6;
  uint32_t uval_7;
  int32_t *puVar8;
  uint32_t uVar9;
  int iVar10;
  uint8_t *pbVar11;
  int32_t *puVar12;
  uint8_t *pbVar13;
  int slot_idx;
  int val_5;
  
  g_PicFileStream = (int)fopen(str_1,&DAT_0052afc4);
  AssertOrLog((uint32_t)((FILE *)g_PicFileStream != (FILE *)0x0),
              (int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x69,
              s_Error_Opening_File__s_005327dc);
  DAT_00703938 = str_1;
  Pic_DecodeKimpicHeader(arg_3);
  if ((DAT_00703943 != '\b') || (val_6 = 1, DAT_00703981 != '\x01')) {
    val_6 = 0;
  }
  AssertOrLog(val_6,(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x6f,
              s__s_Not_a_256_color_palettized_pc_00536cbc);
  uval_3 = 4 - (g_PicSourceWidth & 3);
  uVar9 = (int)uval_3 >> 0x1f;
  val_6 = ((uval_3 ^ uVar9) - uVar9 & 3 ^ uVar9) - uVar9;
  if ((DAT_00536cb4 == g_PicSourceWidth) && (DAT_00536cb8 == g_PicSourceHeight)) {
    uVar9 = (DAT_00536cb4 + val_6) * DAT_00536cb8;
    puVar12 = arg_2;
    for (uval_3 = uVar9 >> 2; uval_3 != 0; uval_3 = uval_3 - 1) {
      *puVar12 = 0;
      puVar12 = puVar12 + 1;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(uint8_t *)puVar12 = 0;
      puVar12 = (int32_t *)((int)puVar12 + 1);
    }
  }
  else {
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalUnlock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalFree(pvVar4);
    pvVar4 = GlobalAlloc(0x40,(val_6 + g_PicSourceWidth) * g_PicSourceHeight);
    arg_2 = GlobalLock(pvVar4);
    pvVar4 = GlobalHandle(arg_2);
    GlobalLock(pvVar4);
    DAT_00536cb4 = g_PicSourceWidth;
    DAT_00536cb8 = g_PicSourceHeight;
  }
  puVar12 = arg_2;
  slot_idx = 0;
  if (0 < g_PicSourceHeight) {
    do {
      pbVar11 = &DAT_00702930;
      for (iVar10 = (int)DAT_00703982; 0 < iVar10; iVar10 = iVar10 + val_5) {
        uval_3 = fgetc((FILE *)g_PicFileStream);
        flag_2 = (uint8_t)uval_3;
        if ((flag_2 & 0xc0) == 0xc0) {
          uVar9 = uval_3 & 0x3f;
          val_5 = fgetc((FILE *)g_PicFileStream);
          flag_2 = (uint8_t)val_5;
          if (uVar9 < 2) goto LAB_00512421;
          if (uVar9 != 0) {
            pbVar13 = pbVar11;
            for (uval_7 = uVar9 >> 2; uval_7 != 0; uval_7 = uval_7 - 1) {
              *(uint32_t *)pbVar13 = CONCAT22(CONCAT11(flag_2,flag_2),CONCAT11(flag_2,flag_2));
              pbVar13 = pbVar13 + 4;
            }
            for (uval_3 = uval_3 & 3; uval_3 != 0; uval_3 = uval_3 - 1) {
              *pbVar13 = flag_2;
              pbVar13 = pbVar13 + 1;
            }
            pbVar11 = pbVar11 + uVar9;
          }
          val_5 = -uVar9;
        }
        else {
LAB_00512421:
          *pbVar11 = flag_2;
          pbVar11 = pbVar11 + 1;
          val_5 = -1;
        }
      }
      iVar10 = 0;
      if (0 < (int)g_PicSourceWidth) {
        do {
          u_ptr_1 = &DAT_00702930 + iVar10;
          puVar8 = (int32_t *)((int)arg_2 + 1);
          iVar10 = iVar10 + 1;
          *(uint8_t *)arg_2 = *u_ptr_1;
          arg_2 = puVar8;
        } while (iVar10 < (int)g_PicSourceWidth);
      }
      arg_2 = (int32_t *)((int)arg_2 + val_6);
      slot_idx = slot_idx + 1;
    } while (slot_idx < g_PicSourceHeight);
  }
  fclose((FILE *)g_PicFileStream);
  return puVar12;
}



/*
 * Decompiled function: Pic_DecodeKimpicHeader
 * Entry Point: 00512500
 * Size: 421 bytes
 */


int32_t Pic_DecodeKimpicHeader(void *arg_1)

{
  int val_1;
  
  fread(&DAT_00703940,0x80,1,g_PicFileStream);
  AssertOrLog((uint32_t)(DAT_00703940 == '\n'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xad
              ,s__s_Not_a_pcx_file_00536d30);
  AssertOrLog((uint32_t)(DAT_00703941 == '\x05'),(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,
              0xae,s__s_Not_a_version_5_pcx_file_00536d10);
  g_PicSourceWidth = ((uint32_t)DAT_00703948 - (uint32_t)DAT_00703944) + 1;
  g_PicSourceHeight = ((uint32_t)DAT_0070394a - (uint32_t)DAT_00703946) + 1;
  if (arg_1 == (void *)0x0) {
    return 1;
  }
  if ((DAT_00703981 == '\x01') && (DAT_00703943 == '\b')) {
    fseek(g_PicFileStream,-0x300,2);
    fread(arg_1,1,0x300,g_PicFileStream);
    fseek(g_PicFileStream,0x80,0);
    return 1;
  }
  if ((DAT_00703981 == '\x04') && (DAT_00703943 == '\x01')) {
    val_1 = 0x10;
    fseek(g_PicFileStream,0x10,2);
    do {
      fread(arg_1,1,3,g_PicFileStream);
      val_1 = val_1 + -1;
      arg_1 = (void *)((int)arg_1 + 4);
    } while (val_1 != 0);
    fseek(g_PicFileStream,0x80,0);
    return 1;
  }
  AssertOrLog(0,(int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0xd4,
              s__s_is_not_in_a_recognizable_form_00536ce8);
  return 1;
}



/*
 * Decompiled function: Pic_DecodeKimpicScanline
 * Entry Point: 005126b0
 * Size: 132 bytes
 */


int32_t Pic_DecodeKimpicScanline(uint8_t *arg_1)

{
  uint8_t flag_1;
  uint32_t uval_2;
  uint32_t uval_3;
  int val_4;
  uint32_t uval_5;
  int val_6;
  uint8_t *pbVar7;
  
  val_6 = (int)DAT_00703982;
  do {
    if (val_6 < 1) {
      return 1;
    }
    uval_2 = fgetc(g_PicFileStream);
    flag_1 = (uint8_t)uval_2;
    if ((flag_1 & 0xc0) == 0xc0) {
      uval_3 = uval_2 & 0x3f;
      val_4 = fgetc(g_PicFileStream);
      flag_1 = (uint8_t)val_4;
      if (uval_3 < 2) goto LAB_00512722;
      if (uval_3 != 0) {
        pbVar7 = arg_1;
        for (uval_5 = uval_3 >> 2; uval_5 != 0; uval_5 = uval_5 - 1) {
          *(uint32_t *)pbVar7 = CONCAT22(CONCAT11(flag_1,flag_1),CONCAT11(flag_1,flag_1));
          pbVar7 = pbVar7 + 4;
        }
        for (uval_2 = uval_2 & 3; uval_2 != 0; uval_2 = uval_2 - 1) {
          *pbVar7 = flag_1;
          pbVar7 = pbVar7 + 1;
        }
        arg_1 = arg_1 + uval_3;
      }
      val_4 = -uval_3;
    }
    else {
LAB_00512722:
      *arg_1 = flag_1;
      arg_1 = arg_1 + 1;
      val_4 = -1;
    }
    val_6 = val_6 + val_4;
  } while( true );
}



/*
 * Decompiled function: Pcx_OpenPcxFileStream
 * Entry Point: 00512740
 * Size: 422 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int32_t Pcx_OpenPcxFileStream(void)

{
  int arg_4;
  uint16_t uval_1;
  uint16_t uval_2;
  int val_3;
  int stack_arg;
  char *stack_arg;
  void *stack_arg;
  int stack_arg;
  int stack_arg;
  uint32_t stack_arg;
  int stack_arg;
  
  Mem_AllocOrFree_00513bd0();
  DAT_00703934 = (int)fopen(stack_arg,&DAT_00536d44);
  AssertOrLog((uint32_t)((FILE *)DAT_00703934 != (FILE *)0x0),
              (int)PTR_s_G__NewMagic_sources_sidlib_Pcxw__00536cb0,0x146,
              s_Error_Opening_File__s_005327dc);
  DAT_00703940 = 10;
  val_3 = 0;
  DAT_00703944 = 0;
  uval_2 = (uint16_t)stack_arg;
  DAT_00703948 = uval_2 - 1;
  DAT_00703941 = 5;
  DAT_00703942 = 1;
  DAT_00703943 = 8;
  DAT_0070394a = (short)stack_arg + -1;
  DAT_00703980 = 0;
  DAT_00703981 = 1;
  DAT_00703946 = 0;
  _DAT_0070394c = 0;
  uval_1 = (uint16_t)((int)stack_arg >> 0x1f);
  _DAT_0070394e = 0;
  _DAT_00703986 = 0;
  _DAT_00703988 = 0;
  DAT_00703982 = (((uval_2 ^ uval_1) - uval_1 & 1 ^ uval_1) - uval_1) + uval_2;
  _DAT_00703984 = 1;
  DAT_00703938 = stack_arg;
  fwrite(&DAT_00703940,0x80,1,(FILE *)DAT_00703934);
  if (0 < stack_arg) {
    do {
      arg_4 = stack_arg + val_3;
      val_3 = val_3 + 1;
      Surface_GetLine((int32_t *)&stack0x00000004,stack_arg,stack_arg,arg_4,
                      stack_arg);
      FUN_005129a0(&stack0x00000004,stack_arg);
    } while (val_3 < stack_arg);
  }
  fwrite(&stack0x00000003,1,1,(FILE *)DAT_00703934);
  fwrite(stack_arg,3,0x100,(FILE *)DAT_00703934);
  fclose((FILE *)DAT_00703934);
  return 0;
}



/*
 * Decompiled function: FUN_005129a0
 * Entry Point: 005129a0
 * Size: 293 bytes
 */


int32_t FUN_005129a0(uint8_t *arg1,int arg2)

{
  uint8_t *pbVar1;
  int val_2;
  int val_3;
  uint8_t local_7;
  uint8_t local_6;
  uint8_t local_5;
  uint32_t local_4;
  
  val_3 = 0;
  if (0 < arg2) {
    do {
      local_5 = *arg1;
      val_2 = arg2 - val_3;
      if ((val_2 == 1) || (arg1[1] != local_5)) {
        local_7 = 0xc1;
        local_6 = local_5;
        if ((local_5 & 0xc0) == 0xc0) {
          fwrite(&local_7,1,1,DAT_00703934);
        }
        val_3 = val_3 + 1;
        arg1 = arg1 + 1;
        fwrite(&local_6,1,1,DAT_00703934);
      }
      else {
        if (0x3e < val_2) {
          val_2 = 0x3f;
        }
        local_4 = 0;
        pbVar1 = arg1;
        while (val_2 != 0) {
          val_2 = val_2 + -1;
          if (*pbVar1 != local_5) break;
          local_4 = local_4 + 1;
          pbVar1 = pbVar1 + 1;
        }
        val_3 = val_3 + local_4;
        arg1 = arg1 + local_4;
        local_4 = local_4 | 0xc0;
        fwrite(&local_4,1,1,DAT_00703934);
        fwrite(&local_5,1,1,DAT_00703934);
      }
    } while (val_3 < arg2);
  }
  if (val_3 < DAT_00703982) {
    local_5 = 0;
    fwrite(&local_5,1,1,DAT_00703934);
  }
  return 1;
}



/*
 * Decompiled function: FUN_00512b50
 * Entry Point: 00512b50
 * Size: 66 bytes
 */


int32_t FUN_00512b50(void *arg_1)

{
  uint8_t local_1;
  
  local_1 = 0xc;
  fwrite(&local_1,1,1,DAT_00703934);
  fwrite(arg_1,3,0x100,DAT_00703934);
  return 0;
}



/*
 * Decompiled function: FUN_00512ba0
 * Entry Point: 00512ba0
 * Size: 95 bytes
 */


int FUN_00512ba0(int32_t arg1,char *mode_str)

{
  int player_id;
  int val_1;
  
  arg_1 = _open(str_2,0x8302,0x80);
  val_1 = arg_1;
  if (arg_1 != -1) {
    DAT_006261d0 = 0;
    val_1 = Mem_AllocOrFree_00512c90(arg_1,Surface_GetLine,arg1,0,0,0x140,200);
    _close(arg_1);
  }
  return val_1;
}



/*
 * Decompiled function: FUN_00512c00
 * Entry Point: 00512c00
 * Size: 130 bytes
 */


int FUN_00512c00(int32_t arg_1,int card_slot,int event_type,int arg_4,int arg_5,int arg_6,char *str_7)

{
  int arg_1_00;
  int val_1;
  
  arg_1_00 = _open(str_7,0x8302,0x80);
  val_1 = arg_1_00;
  if (arg_1_00 != -1) {
    if (arg_6 != 0) {
      FUN_0050eb90(arg_1_00);
    }
    DAT_006261d0 = (uint32_t)(arg_6 != 0);
    val_1 = Mem_AllocOrFree_00512c90(arg_1_00,Surface_GetLine,arg_1,arg_2,arg_3,arg_4,arg_5);
    _close(arg_1_00);
  }
  return val_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00512c90
 * Entry Point: 00512c90
 * Size: 13 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Mem_AllocOrFree_00512c90
               (int player_id,uint8_t *arg_2,int32_t arg_3,int arg_4,int arg_5,int arg_6,int arg_7)

{
  uint8_t *u_ptr_1;
  uint8_t *pbVar2;
  uint32_t uval_3;
  int val_4;
  int val_5;
  long lVar6;
  uint32_t uval_7;
  uint16_t uval_8;
  uint32_t arg_1_00;
  bool bVar9;
  uint8_t *pbStack_10;
  
  DAT_006261d4 = arg_1;
  DAT_006261e4 = (int)malloc(0xbfd0);
  DAT_006261e8 = -1;
  _DAT_006261ca = 0;
  DAT_006261c0 = 0;
  DAT_006261b8 = 0;
  _DAT_006261cc = (int16_t)arg_6;
  _DAT_006261ce = (int16_t)arg_7;
  _DAT_006261c8 = 0x3058;
  DAT_006261e0 = 0;
  val_5 = 7;
  pbVar2 = &DAT_006261c8;
  do {
    FUN_005135e0(8,(uint32_t)*pbVar2);
    bVar9 = val_5 != 0;
    val_5 = val_5 + -1;
    pbVar2 = pbVar2 + 1;
  } while (bVar9);
  uval_8 = 1;
  pbVar2 = &DAT_006261f0 + arg_4;
  uval_3 = 0xffffffff;
  pbStack_10 = pbVar2 + arg_6;
  do {
    uval_7 = uval_3;
    if (pbVar2 + arg_6 <= pbStack_10) {
      bVar9 = arg_7 == 0;
      arg_7 = arg_7 + -1;
      if (bVar9) {
        val_5 = DAT_006261e8;
        if ((short)uval_3 == 0x90) {
          while (DAT_006261e8 = val_5, uval_8 != 0) {
            uval_8 = uval_8 - 1;
            if (val_5 == -1) {
              DAT_006261e8 = 0;
              FUN_005135e0(8,0xb);
              FUN_005134a0();
              g_PcxDecoderHeight = 0x90;
              g_OverworldWorldState = 0x90;
              g_PcxDecoderWidth = 1;
              val_5 = g_PcxDecoderHeight;
            }
            else {
              val_4 = g_PcxDecoderWidth + 1;
              u_ptr_1 = &g_OverworldWorldState + g_PcxDecoderWidth;
              g_PcxDecoderWidth = val_4;
              *u_ptr_1 = 0x90;
              if (val_5 < val_4) {
                DAT_006261e8 = val_4;
              }
              val_5 = FUN_00513510(0x90);
              if (val_5 == -1) {
                *DAT_00702924 = 0x90;
                DAT_00702924[1] = g_PcxDecoderHeight;
                DAT_00702924[2] = DAT_006261ec;
                DAT_006261ec = DAT_006261ec + 1;
                FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
                g_PcxDecoderWidth = 1;
                g_PcxDecoderHeight = 0x90;
                g_OverworldWorldState = 0x90;
                val_5 = g_PcxDecoderHeight;
                if ((1 << ((uint8_t)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                   (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                  FUN_005134a0();
                  val_5 = g_PcxDecoderHeight;
                }
              }
            }
            g_PcxDecoderHeight = val_5;
            FUN_00513200(0);
            val_5 = DAT_006261e8;
          }
        }
        else {
          if (3 < uval_8) {
            do {
              uval_7 = (uint32_t)uval_8;
              if (0xfe < uval_8) {
                uval_7 = 0xff;
              }
              uval_8 = uval_8 - (short)uval_7;
              FUN_00513200(uval_3 & 0xffff);
              FUN_00513200(0x90);
              FUN_00513200(uval_7);
            } while (3 < uval_8);
          }
          if (uval_8 != 0) {
            do {
              uval_8 = uval_8 - 1;
              FUN_00513200(uval_3 & 0xffff);
            } while (uval_8 != 0);
          }
        }
        FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
        FUN_005135e0(8,0);
        _write(DAT_006261d4,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        lVar6 = _tell(DAT_006261d4);
        _DAT_006261ca = (short)lVar6 + -4;
        if (DAT_006261d0 == 0) {
          lVar6 = 0;
        }
        else {
          lVar6 = 0x306;
        }
        _lseek(DAT_006261d4,lVar6,0);
        _write(DAT_006261d4,&DAT_006261c8,8);
        free((void *)DAT_006261e4);
        _close(DAT_006261d4);
        return;
      }
      val_5 = arg_5 + 1;
      (*(code *)arg_2)(pbVar2,arg_3,arg_4,arg_5,arg_6);
      arg_5 = val_5;
      pbStack_10 = pbVar2;
      if (uval_3 == 0xffffffff) {
        pbStack_10 = (uint8_t *)(arg_4 + 0x6261f1);
        uval_7 = (uint32_t)*pbVar2;
      }
    }
    uval_3 = (uint32_t)*pbStack_10;
    if (uval_7 == uval_3) {
      uval_8 = uval_8 + 1;
      uval_3 = uval_7;
      pbStack_10 = pbStack_10 + 1;
    }
    else {
      val_5 = DAT_006261e8;
      if ((short)uval_7 == 0x90) {
        while (DAT_006261e8 = val_5, uval_8 != 0) {
          uval_8 = uval_8 - 1;
          if (val_5 == -1) {
            DAT_006261e8 = 0;
            FUN_005135e0(8,0xb);
            FUN_005134a0();
            g_PcxDecoderHeight = 0x90;
            g_OverworldWorldState = 0x90;
            g_PcxDecoderWidth = 1;
            val_5 = g_PcxDecoderHeight;
          }
          else {
            val_4 = g_PcxDecoderWidth + 1;
            u_ptr_1 = &g_OverworldWorldState + g_PcxDecoderWidth;
            g_PcxDecoderWidth = val_4;
            *u_ptr_1 = 0x90;
            if (val_5 < val_4) {
              DAT_006261e8 = val_4;
            }
            val_5 = FUN_00513510(0x90);
            if (val_5 == -1) {
              *DAT_00702924 = 0x90;
              DAT_00702924[1] = g_PcxDecoderHeight;
              DAT_00702924[2] = DAT_006261ec;
              DAT_006261ec = DAT_006261ec + 1;
              FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
              g_PcxDecoderHeight = 0x90;
              g_OverworldWorldState = 0x90;
              g_PcxDecoderWidth = 1;
              val_5 = g_PcxDecoderHeight;
              if ((1 << ((uint8_t)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                 (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                FUN_005134a0();
                val_5 = g_PcxDecoderHeight;
              }
            }
          }
          g_PcxDecoderHeight = val_5;
          FUN_00513200(0);
          val_5 = DAT_006261e8;
        }
      }
      else {
        if (3 < uval_8) {
          do {
            arg_1_00 = (uint32_t)uval_8;
            if (0xfe < uval_8) {
              arg_1_00 = 0xff;
            }
            uval_8 = uval_8 - (short)arg_1_00;
            FUN_00513200(uval_7 & 0xffff);
            FUN_00513200(0x90);
            FUN_00513200(arg_1_00);
          } while (3 < uval_8);
        }
        if (uval_8 != 0) {
          do {
            uval_8 = uval_8 - 1;
            FUN_00513200(uval_7 & 0xffff);
          } while (uval_8 != 0);
        }
      }
      uval_8 = 1;
      pbStack_10 = pbStack_10 + 1;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_00512c9d
 * Entry Point: 00512c9d
 * Size: 1364 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00512c9d(void)

{
  uint8_t *u_ptr_1;
  uint8_t *pbVar2;
  uint8_t *pbVar3;
  uint32_t uval_4;
  int val_5;
  int val_6;
  long lVar7;
  uint8_t *pbVar8;
  uint32_t uVar9;
  uint16_t uVar10;
  uint32_t arg_1;
  bool bVar11;
  code *stack_arg;
  int32_t stack_arg;
  int stack_arg;
  int stack_arg;
  int16_t uStack00000028;
  int16_t uStack0000002c;
  
  DAT_006261e4 = (int)malloc(0xbfd0);
  DAT_006261e8 = -1;
  _DAT_006261ca = 0;
  DAT_006261c0 = 0;
  DAT_006261b8 = 0;
  _DAT_006261cc = uStack00000028;
  _DAT_006261ce = uStack0000002c;
  _DAT_006261c8 = 0x3058;
  DAT_006261e0 = 0;
  val_6 = 7;
  pbVar8 = &DAT_006261c8;
  do {
    FUN_005135e0(8,(uint32_t)*pbVar8);
    bVar11 = val_6 != 0;
    val_6 = val_6 + -1;
    pbVar8 = pbVar8 + 1;
  } while (bVar11);
  uVar10 = 1;
  pbVar2 = &DAT_006261f0 + stack_arg;
  uval_4 = 0xffffffff;
  pbVar8 = pbVar2 + _uStack00000028;
  do {
    uVar9 = uval_4;
    pbVar3 = pbVar8;
    if (pbVar2 + _uStack00000028 <= pbVar8) {
      bVar11 = _uStack0000002c == 0;
      _uStack0000002c = _uStack0000002c + -1;
      if (bVar11) {
        val_6 = DAT_006261e8;
        if ((short)uval_4 == 0x90) {
          while (DAT_006261e8 = val_6, uVar10 != 0) {
            uVar10 = uVar10 - 1;
            if (val_6 == -1) {
              DAT_006261e8 = 0;
              FUN_005135e0(8,0xb);
              FUN_005134a0();
              g_PcxDecoderHeight = 0x90;
              g_OverworldWorldState = 0x90;
              g_PcxDecoderWidth = 1;
              val_6 = g_PcxDecoderHeight;
            }
            else {
              val_5 = g_PcxDecoderWidth + 1;
              u_ptr_1 = &g_OverworldWorldState + g_PcxDecoderWidth;
              g_PcxDecoderWidth = val_5;
              *u_ptr_1 = 0x90;
              if (val_6 < val_5) {
                DAT_006261e8 = val_5;
              }
              val_6 = FUN_00513510(0x90);
              if (val_6 == -1) {
                *DAT_00702924 = 0x90;
                DAT_00702924[1] = g_PcxDecoderHeight;
                DAT_00702924[2] = DAT_006261ec;
                DAT_006261ec = DAT_006261ec + 1;
                FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
                g_PcxDecoderWidth = 1;
                g_PcxDecoderHeight = 0x90;
                g_OverworldWorldState = 0x90;
                val_6 = g_PcxDecoderHeight;
                if ((1 << ((uint8_t)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                   (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                  FUN_005134a0();
                  val_6 = g_PcxDecoderHeight;
                }
              }
            }
            g_PcxDecoderHeight = val_6;
            FUN_00513200(0);
            val_6 = DAT_006261e8;
          }
        }
        else {
          if (3 < uVar10) {
            do {
              uVar9 = (uint32_t)uVar10;
              if (0xfe < uVar10) {
                uVar9 = 0xff;
              }
              uVar10 = uVar10 - (short)uVar9;
              FUN_00513200(uval_4 & 0xffff);
              FUN_00513200(0x90);
              FUN_00513200(uVar9);
            } while (3 < uVar10);
          }
          if (uVar10 != 0) {
            do {
              uVar10 = uVar10 - 1;
              FUN_00513200(uval_4 & 0xffff);
            } while (uVar10 != 0);
          }
        }
        FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
        FUN_005135e0(8,0);
        _write(DAT_006261d4,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        lVar7 = _tell(DAT_006261d4);
        _DAT_006261ca = (short)lVar7 + -4;
        if (DAT_006261d0 == 0) {
          lVar7 = 0;
        }
        else {
          lVar7 = 0x306;
        }
        _lseek(DAT_006261d4,lVar7,0);
        _write(DAT_006261d4,&DAT_006261c8,8);
        free((void *)DAT_006261e4);
        _close(DAT_006261d4);
        return;
      }
      val_6 = stack_arg + 1;
      (*stack_arg)
                (pbVar2,stack_arg,stack_arg,stack_arg,_uStack00000028);
      pbVar3 = pbVar2;
      stack_arg = val_6;
      if (uval_4 == 0xffffffff) {
        pbVar3 = (uint8_t *)(stack_arg + 0x6261f1);
        uVar9 = (uint32_t)*pbVar2;
      }
    }
    pbVar8 = pbVar3 + 1;
    uval_4 = (uint32_t)*pbVar3;
    if (uVar9 == uval_4) {
      uVar10 = uVar10 + 1;
      uval_4 = uVar9;
    }
    else {
      val_6 = DAT_006261e8;
      if ((short)uVar9 == 0x90) {
        while (DAT_006261e8 = val_6, uVar10 != 0) {
          uVar10 = uVar10 - 1;
          if (val_6 == -1) {
            DAT_006261e8 = 0;
            FUN_005135e0(8,0xb);
            FUN_005134a0();
            g_PcxDecoderHeight = 0x90;
            g_OverworldWorldState = 0x90;
            g_PcxDecoderWidth = 1;
            val_6 = g_PcxDecoderHeight;
          }
          else {
            val_5 = g_PcxDecoderWidth + 1;
            u_ptr_1 = &g_OverworldWorldState + g_PcxDecoderWidth;
            g_PcxDecoderWidth = val_5;
            *u_ptr_1 = 0x90;
            if (val_6 < val_5) {
              DAT_006261e8 = val_5;
            }
            val_6 = FUN_00513510(0x90);
            if (val_6 == -1) {
              *DAT_00702924 = 0x90;
              DAT_00702924[1] = g_PcxDecoderHeight;
              DAT_00702924[2] = DAT_006261ec;
              DAT_006261ec = DAT_006261ec + 1;
              FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
              g_PcxDecoderHeight = 0x90;
              g_OverworldWorldState = 0x90;
              g_PcxDecoderWidth = 1;
              val_6 = g_PcxDecoderHeight;
              if ((1 << ((uint8_t)DAT_006261bc & 0x1f) < DAT_006261ec) &&
                 (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
                FUN_005134a0();
                val_6 = g_PcxDecoderHeight;
              }
            }
          }
          g_PcxDecoderHeight = val_6;
          FUN_00513200(0);
          val_6 = DAT_006261e8;
        }
      }
      else {
        if (3 < uVar10) {
          do {
            arg_1 = (uint32_t)uVar10;
            if (0xfe < uVar10) {
              arg_1 = 0xff;
            }
            uVar10 = uVar10 - (short)arg_1;
            FUN_00513200(uVar9 & 0xffff);
            FUN_00513200(0x90);
            FUN_00513200(arg_1);
          } while (3 < uVar10);
        }
        if (uVar10 != 0) {
          do {
            uVar10 = uVar10 - 1;
            FUN_00513200(uVar9 & 0xffff);
          } while (uVar10 != 0);
        }
      }
      uVar10 = 1;
    }
  } while( true );
}



/*
 * Decompiled function: FUN_00513200
 * Entry Point: 00513200
 * Size: 664 bytes
 */


void FUN_00513200(int player_id)

{
  uint8_t *u_ptr_1;
  int val_2;
  int val_3;
  uint32_t uval_4;
  uint32_t uval_5;
  uint8_t uval_6;
  int val_7;
  
  val_7 = DAT_006261e8;
  uval_6 = (uint8_t)arg_1;
  if (DAT_006261e8 == -1) {
    val_7 = 0;
    DAT_006261e8 = 0;
    FUN_005135e0(8,0xb);
    val_3 = 0;
    do {
      val_3 = val_3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + val_3) = val_7;
      *(int *)(DAT_006261e4 + -0xc + val_3) = val_7;
      val_7 = val_7 + 1;
      *(int32_t *)(DAT_006261e4 + -8 + val_3) = 0xffffffff;
    } while (val_3 < 0xc00);
    if (val_7 < 0xffb) {
      val_7 = val_7 * 0xc;
      do {
        val_7 = val_7 + 0xc;
        *(int32_t *)(DAT_006261e4 + -0xc + val_7) = 0xffffffff;
      } while (val_7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
    g_PcxDecoderWidth = 1;
    g_PcxDecoderHeight = arg_1;
    g_OverworldWorldState = uval_6;
    return;
  }
  val_2 = g_PcxDecoderWidth + 1;
  u_ptr_1 = &g_OverworldWorldState + g_PcxDecoderWidth;
  g_PcxDecoderWidth = val_2;
  *u_ptr_1 = uval_6;
  val_3 = g_PcxDecoderWidth;
  if (val_7 < val_2) {
    DAT_006261e8 = val_2;
  }
  uval_4 = 0;
  (&g_OverworldWorldState)[g_PcxDecoderWidth] = 0;
  if (0 < val_3) {
    val_7 = 0;
    do {
      uval_4 = uval_4 + (int)*(short *)(&g_OverworldWorldState + val_7);
      val_7 = val_7 + 2;
    } while (val_7 < g_PcxDecoderWidth);
  }
  uval_4 = uval_4 & 0x7fff;
  if (uval_4 == 0) {
    uval_4 = g_PcxDecoderWidth * 0x25 & 0x7fff;
  }
  uval_5 = uval_4 % 0xffb;
  val_7 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uval_5 * 0xc);
    if (*DAT_00702924 == -1) break;
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == g_PcxDecoderHeight)) goto LAB_0051338a;
    if (val_7 == -1) {
      val_7 = 0xff9 - uval_4 % 0xff9;
    }
    if (val_7 == 0) {
      val_7 = g_PcxDecoderWidth * 0x89;
    }
    uval_5 = (int)(uval_5 + val_7) % 0xffb;
  }
  uval_5 = 0xffffffff;
LAB_0051338a:
  if (uval_5 != 0xffffffff) {
    g_PcxDecoderHeight = uval_5;
    return;
  }
  *DAT_00702924 = arg_1;
  DAT_00702924[1] = g_PcxDecoderHeight;
  DAT_00702924[2] = DAT_006261ec;
  DAT_006261ec = DAT_006261ec + 1;
  FUN_005135e0(DAT_006261bc,*(uint32_t *)(DAT_006261e4 + 8 + g_PcxDecoderHeight * 0xc));
  g_PcxDecoderHeight = arg_1;
  g_PcxDecoderWidth = 1;
  g_OverworldWorldState = uval_6;
  if ((1 << ((uint8_t)DAT_006261bc & 0x1f) < DAT_006261ec) &&
     (DAT_006261bc = DAT_006261bc + 1, 0xb < DAT_006261bc)) {
    val_3 = 0;
    val_7 = 0;
    do {
      val_3 = val_3 + 0xc;
      *(int *)(DAT_006261e4 + -4 + val_3) = val_7;
      *(int *)(DAT_006261e4 + -0xc + val_3) = val_7;
      val_7 = val_7 + 1;
      *(int32_t *)(DAT_006261e4 + -8 + val_3) = 0xffffffff;
    } while (val_3 < 0xc00);
    if (val_7 < 0xffb) {
      val_7 = val_7 * 0xc;
      do {
        val_7 = val_7 + 0xc;
        *(int32_t *)(DAT_006261e4 + -0xc + val_7) = 0xffffffff;
      } while (val_7 < 0xbfc4);
    }
    DAT_006261bc = 9;
    DAT_006261ec = 0x101;
  }
  return;
}



/*
 * Decompiled function: FUN_005134a0
 * Entry Point: 005134a0
 * Size: 109 bytes
 */


void FUN_005134a0(void)

{
  int val_1;
  int val_2;
  
  val_1 = 0;
  val_2 = 0;
  do {
    val_2 = val_2 + 0xc;
    *(int *)(DAT_006261e4 + -4 + val_2) = val_1;
    *(int *)(DAT_006261e4 + -0xc + val_2) = val_1;
    val_1 = val_1 + 1;
    *(int32_t *)(DAT_006261e4 + -8 + val_2) = 0xffffffff;
  } while (val_2 < 0xc00);
  if (val_1 < 0xffb) {
    val_1 = val_1 * 0xc;
    do {
      val_1 = val_1 + 0xc;
      *(int32_t *)(DAT_006261e4 + -0xc + val_1) = 0xffffffff;
    } while (val_1 < 0xbfc4);
  }
  DAT_006261bc = 9;
  DAT_006261ec = 0x101;
  return;
}



/*
 * Decompiled function: FUN_00513510
 * Entry Point: 00513510
 * Size: 204 bytes
 */


uint32_t FUN_00513510(int player_id)

{
  int val_1;
  uint32_t uval_2;
  uint32_t uval_3;
  
  val_1 = g_PcxDecoderWidth;
  uval_2 = 0;
  (&g_OverworldWorldState)[g_PcxDecoderWidth] = 0;
  if (0 < val_1) {
    val_1 = 0;
    do {
      uval_2 = uval_2 + (int)*(short *)(&g_OverworldWorldState + val_1);
      val_1 = val_1 + 2;
    } while (val_1 < g_PcxDecoderWidth);
  }
  uval_2 = uval_2 & 0x7fff;
  if (uval_2 == 0) {
    uval_2 = g_PcxDecoderWidth * 0x25 & 0x7fff;
  }
  uval_3 = uval_2 % 0xffb;
  val_1 = -1;
  while( true ) {
    DAT_00702924 = (int *)(DAT_006261e4 + uval_3 * 0xc);
    if (*DAT_00702924 == -1) {
      return 0xffffffff;
    }
    if ((arg_1 == *DAT_00702924) && (DAT_00702924[1] == g_PcxDecoderHeight)) break;
    if (val_1 == -1) {
      val_1 = 0xff9 - uval_2 % 0xff9;
    }
    if (val_1 == 0) {
      val_1 = g_PcxDecoderWidth * 0x89;
    }
    uval_3 = (int)(val_1 + uval_3) % 0xffb;
  }
  return uval_3;
}



/*
 * Decompiled function: FUN_005135e0
 * Entry Point: 005135e0
 * Size: 170 bytes
 */


void FUN_005135e0(int arg1,uint32_t arg2)

{
  int player_id;
  uint32_t uval_1;
  
  arg_1 = DAT_006261d4;
  while (arg1 != 0) {
    arg1 = arg1 + -1;
    uval_1 = DAT_006261b8;
    if (7 < DAT_006261c0) {
      (&DAT_00706510)[DAT_006261e0] = (char)DAT_006261b8;
      DAT_006261e0 = DAT_006261e0 + 1;
      DAT_006261b8 = 0;
      DAT_006261c0 = 0;
      uval_1 = 0;
      if (0x1ff < DAT_006261e0) {
        _write(arg_1,&DAT_00706510,DAT_006261e0);
        DAT_006261e0 = 0;
        arg_1 = DAT_006261d4;
        uval_1 = DAT_006261b8;
      }
    }
    DAT_006261b8 = (int)uval_1 >> 1;
    if ((arg2 & 1) != 0) {
      DAT_006261b8 = DAT_006261b8 | 0x80;
    }
    arg2 = (int)arg2 >> 1;
    DAT_006261c0 = DAT_006261c0 + 1;
  }
  return;
}



/*
 * Decompiled function: UI_Register_ShowPaletteClass_00513820
 * Entry Point: 00513820
 * Size: 131 bytes
 */


ATOM UI_Register_ShowPaletteClass_00513820(HINSTANCE hInstance)

{
  ATOM AVar1;
  WNDCLASSA local_28;
  
  local_28.style = 0x20;
  local_28.hInstance = hInstance;
  local_28.lpfnWndProc = (WNDPROC)&LAB_00513690;
  local_28.cbClsExtra = 0;
  local_28.cbWndExtra = 0;
  local_28.hIcon = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_28.hbrBackground = CreateSolidBrush(0);
  local_28.lpszMenuName = (LPCSTR)0x0;
  local_28.lpszClassName = s_ShowPaletteClass_005326ac;
  AVar1 = RegisterClassA(&local_28);
  return AVar1;
}



/*
 * Decompiled function: UI_Register_ShowPaletteClass_005138b0
 * Entry Point: 005138b0
 * Size: 121 bytes
 */


void UI_Register_ShowPaletteClass_005138b0(HINSTANCE hInstance,HWND hwnd)

{
  tagRECT card_idx;
  
  card_idx.right = 0x100;
  card_idx.bottom = 0x100;
  card_idx.left = 0;
  card_idx.top = 0;
  AdjustWindowRect(&card_idx,0xcc0000,0);
  CreateWindowExA(0,s_ShowPaletteClass_005326ac,s_Current_Palette_005326c0,0x80c80000,100,0x32,
                  card_idx.right - card_idx.left,card_idx.bottom - card_idx.top,hwnd,(HMENU)0x0,
                  hInstance,(LPVOID)0x0);
  return;
}



/*
 * Decompiled function: FUN_00513a70
 * Entry Point: 00513a70
 * Size: 140 bytes
 */


void FUN_00513a70(HDC hdc,int card_slot,int event_type,int arg_4,int arg_5,uint32_t arg_6)

{
  HPEN h;
  HGDIOBJ ho;
  LOGPEN card_idx;
  
  card_idx.lopnStyle = 0;
  card_idx.lopnColor = arg_6 & 0xffff | 0x1000000;
  card_idx.lopnWidth.x = 0;
  card_idx.lopnWidth.y = 0;
  h = CreatePenIndirect(&card_idx);
  ho = SelectObject(hdc,h);
  DeleteObject(ho);
  for (; arg_3 < arg_5; arg_3 = arg_3 + 1) {
    MoveToEx(hdc,arg_2,arg_3,(LPPOINT)0x0);
    LineTo(hdc,arg_4,arg_3);
  }
  return;
}



/*
 * Decompiled function: strlen
 * Entry Point: 00513afc
 * Size: 6 bytes
 */


size_t __cdecl strlen(char *filepath)

{
  size_t len_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513afc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  len_1 = strlen(str_1);
  return len_1;
}



/*
 * Decompiled function: sprintf
 * Entry Point: 00513b02
 * Size: 6 bytes
 */


int __cdecl sprintf(char *filepath,char *mode_str,...)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = sprintf(str_1,str_2);
  return val_1;
}



/*
 * Decompiled function: abs
 * Entry Point: 00513b08
 * Size: 6 bytes
 */


int __cdecl abs(int player_id)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = abs(arg_1);
  return val_1;
}



/*
 * Decompiled function: strcat
 * Entry Point: 00513b0e
 * Size: 6 bytes
 */


char * __cdecl strcat(char *filepath,char *mode_str)

{
  char *char_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  char_ptr_1 = strcat(str_1,str_2);
  return char_ptr_1;
}



/*
 * Decompiled function: strcpy
 * Entry Point: 00513b14
 * Size: 6 bytes
 */


char * __cdecl strcpy(char *filepath,char *mode_str)

{
  char *char_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  char_ptr_1 = strcpy(str_1,str_2);
  return char_ptr_1;
}



/*
 * Decompiled function: strcmp
 * Entry Point: 00513b2c
 * Size: 6 bytes
 */


int __cdecl strcmp(char *filepath,char *mode_str)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = strcmp(str_1,str_2);
  return val_1;
}



/*
 * Decompiled function: memcpy
 * Entry Point: 00513b80
 * Size: 6 bytes
 */


void * __cdecl memcpy(void *ptr_1,void *ptr_2,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memcpy(ptr_1,ptr_2,arg_3);
  return buf_ptr_1;
}



/*
 * Decompiled function: _vsnprintf
 * Entry Point: 00513b98
 * Size: 6 bytes
 */


int __cdecl _vsnprintf(char *filepath,size_t arg_2,char *str_3,va_list arg_4)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = _vsnprintf(str_1,arg_2,str_3,arg_4);
  return val_1;
}



/*
 * Decompiled function: memset
 * Entry Point: 00513b9e
 * Size: 6 bytes
 */


void * __cdecl memset(void *ptr_1,int card_slot,size_t arg_3)

{
  void *buf_ptr_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513b9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  buf_ptr_1 = memset(ptr_1,arg_2,arg_3);
  return buf_ptr_1;
}



/*
 * Decompiled function: clock
 * Entry Point: 00513bbc
 * Size: 6 bytes
 */


clock_t __cdecl clock(void)

{
  clock_t cVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513bbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  cVar1 = clock();
  return cVar1;
}



/*
 * Decompiled function: Mem_AllocOrFree_00513bd0
 * Entry Point: 00513bd0
 * Size: 47 bytes
 */


/* WARNING: Unable to track spacebase fully for stack */

void Mem_AllocOrFree_00513bd0(void)

{
  uint32_t reg_eax;
  uint8_t *u_ptr_1;
  int32_t unaff_retaddr;
  
  u_ptr_1 = &stack0x00000004;
  for (; 0xfff < reg_eax; reg_eax = reg_eax - 0x1000) {
    u_ptr_1 = u_ptr_1 + -0x1000;
  }
  *(int32_t *)(u_ptr_1 + (-4 - reg_eax)) = unaff_retaddr;
  return;
}



/*
 * Decompiled function: memcmp
 * Entry Point: 00513c00
 * Size: 6 bytes
 */


int __cdecl memcmp(void *ptr_1,void *ptr_2,size_t arg_3)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513c00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = memcmp(ptr_1,ptr_2,arg_3);
  return val_1;
}



/*
 * Decompiled function: __allshl
 * Entry Point: 00513c50
 * Size: 31 bytes
 */


/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(uint8_t arg1,int arg2)

{
  uint32_t reg_eax;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | reg_eax >> 0x20 - (arg1 & 0x1f),reg_eax << (arg1 & 0x1f));
  }
  return (ulonglong)(reg_eax << (arg1 & 0x1f)) << 0x20;
}



/*
 * Decompiled function: __onexit
 * Entry Point: 00513c80
 * Size: 208 bytes
 */


/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Debug */

_onexit_t __onexit(_onexit_t arg_1)

{
  DWORD DVar1;
  _onexit_t match_count;
  char slot_idx;
  
  if (DAT_00536d50 == 0) {
    DVar1 = GetVersion();
    slot_idx = (char)DVar1;
    if ((slot_idx == '\x03') && ((int)DVar1 < 0)) {
      DAT_00536d50 = DAT_00536d50 + 1;
    }
    else {
      DAT_00536d50 = DAT_00536d50 + -1;
    }
  }
  if (0 < DAT_00536d50) {
    while (0 < DAT_00536d54) {
      Sleep(0);
    }
    DAT_00536d54 = DAT_00536d54 + 1;
  }
  if (DAT_0070ac9c == -1) {
    match_count = _onexit(arg_1);
  }
  else {
    match_count = (_onexit_t)__dllonexit(arg_1,&DAT_0070ac9c,&DAT_0070ac98);
  }
  if (0 < DAT_00536d50) {
    DAT_00536d54 = DAT_00536d54 + -1;
  }
  return match_count;
}



/*
 * Decompiled function: _atexit
 * Entry Point: 00513d50
 * Size: 48 bytes
 */


/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Debug */

int __cdecl _atexit(_func_4879 *ptr_1)

{
  int val_1;
  
  val_1 = __onexit((_onexit_t)ptr_1);
  if (val_1 == 0) {
    val_1 = -1;
  }
  else {
    val_1 = 0;
  }
  return val_1;
}



/*
 * Decompiled function: entry
 * Entry Point: 00513da0
 * Size: 510 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  uint8_t *pbVar1;
  int32_t *u_ptr_2;
  HMODULE x;
  int32_t *unaff_FS_OFFSET;
  HINSTANCE y;
  uint32_t local_84;
  uint8_t *local_78;
  char **local_74;
  _startupinfo local_70;
  int local_6c;
  char **local_68;
  int local_64;
  _STARTUPINFOA local_60;
  uint8_t *color_idx;
  int32_t player_idx;
  uint8_t *puStack_10;
  uint8_t *puStack_c;
  int32_t slot_idx;
  
  puStack_c = &DAT_005151c8;
  puStack_10 = &DAT_0051409e;
  player_idx = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &player_idx;
  color_idx = &stack0xffffff6c;
  slot_idx = 0;
  __set_app_type(2);
  DAT_0070ac98 = 0xffffffff;
  DAT_0070ac9c = 0xffffffff;
  u_ptr_2 = (int32_t *)__p__fmode();
  *u_ptr_2 = DAT_00536d70;
  u_ptr_2 = (int32_t *)__p__commode();
  *u_ptr_2 = DAT_00536d6c;
  _DAT_0070ac94 = *(int32_t *)_adjust_fdiv_exref;
  __setargv();
  if (DAT_00536d68 == 0) {
    __setusermatherr(Mem_AllocOrFree_00514060);
  }
  __setdefaultprecision();
  initterm(&DAT_00516008,&DAT_0051600c);
  local_70.newmode = DAT_00536d64;
  __getmainargs(&local_64,&local_74,&local_68,DAT_00536d60,&local_70);
  initterm(&DAT_00516000,&DAT_00516004);
  u_ptr_2 = (int32_t *)__p__acmdln();
  local_78 = (uint8_t *)*u_ptr_2;
  pbVar1 = local_78;
  if (*local_78 == 0x22) {
    do {
      local_78 = pbVar1;
      pbVar1 = local_78 + 1;
      if (*pbVar1 == 0) break;
    } while (*pbVar1 != 0x22);
    if (*pbVar1 == 0x22) {
      pbVar1 = local_78 + 2;
    }
  }
  else {
    for (; pbVar1 = local_78, 0x20 < *local_78; local_78 = local_78 + 1) {
    }
  }
  while ((local_78 = pbVar1, *local_78 != 0 && (*local_78 < 0x21))) {
    pbVar1 = local_78 + 1;
  }
  local_60.dwFlags = 0;
  GetStartupInfoA(&local_60);
  if ((local_60.dwFlags & 1) == 0) {
    local_84 = 10;
  }
  else {
    local_84 = local_60._48_4_ & 0xffff;
  }
  y = (HINSTANCE)0x0;
  x = GetModuleHandleA((LPCSTR)0x0);
  local_6c = WinMain(x,y,(LPSTR)local_78,local_84);
                    /* WARNING: Subroutine does not return */
  exit(local_6c);
}



/*
 * Decompiled function: _write
 * Entry Point: 00513fde
 * Size: 6 bytes
 */


int __cdecl _write(int player_id,void *ptr_2,uint32_t arg_3)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00513fde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = _write(arg_1,ptr_2,arg_3);
  return val_1;
}



/*
 * Decompiled function: __dllonexit
 * Entry Point: 00514008
 * Size: 6 bytes
 */


void __dllonexit(void)

{
                    /* WARNING: Could not recover jumptable at 0x00514008. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __dllonexit();
  return;
}



/*
 * Decompiled function: initterm
 * Entry Point: 00514022
 * Size: 6 bytes
 */


void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x00514022. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}



/*
 * Decompiled function: __setdefaultprecision
 * Entry Point: 00514030
 * Size: 29 bytes
 */


/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Debug */

void __setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00514060
 * Entry Point: 00514060
 * Size: 18 bytes
 */


int32_t Mem_AllocOrFree_00514060(void)

{
  return 0;
}



/*
 * Decompiled function: __setargv
 * Entry Point: 00514080
 * Size: 11 bytes
 */


/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Debug */

int __cdecl __setargv(void)

{
  int reg_eax;
  
  return reg_eax;
}



/*
 * Decompiled function: _controlfp
 * Entry Point: 005140a4
 * Size: 6 bytes
 */


uint32_t __cdecl _controlfp(uint32_t arg1,uint32_t arg2)

{
  uint32_t uval_1;
  
                    /* WARNING: Could not recover jumptable at 0x005140a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uval_1 = _controlfp(arg1,arg2);
  return uval_1;
}



/*
 * Decompiled function: _chdir
 * Entry Point: 00514128
 * Size: 6 bytes
 */


int __cdecl _chdir(char *filepath)

{
  int val_1;
  
                    /* WARNING: Could not recover jumptable at 0x00514128. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  val_1 = _chdir(str_1);
  return val_1;
}



