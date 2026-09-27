/*
 * NedCard/Catalog.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: Catalog_Open
 * Entry Point: 004340f0
 * Size: 586 bytes
 */


int Catalog_Open(char *str_1)

{
  int iVar1;
  FILE *pFVar2;
  void *pvVar3;
  int local_20;
  int local_1c;
  int local_10;
  int local_c;
  
  local_c = -1;
  local_10 = 0;
  do {
    if (4 < local_10) {
LAB_00434144:
      File_Load_Assertfile
                ((uint)(local_c != -1),0x4f4548,0x43,s_Too_many_open_Catalogs__Max__d_004f4528);
      iVar1 = local_c * 0x114;
      *(undefined4 *)(&DAT_006c0cbc + iVar1) = 0;
      Mem_AllocOrFree_004d9630((uint *)(iVar1 + 0x6c0cc0),(uint *)str_1);
      pFVar2 = _fopen(str_1,&DAT_004f4570);
      *(FILE **)(&DAT_006c0cb0 + iVar1) = pFVar2;
      pFVar2 = *(FILE **)(&DAT_006c0cb0 + iVar1);
      if (pFVar2 == (FILE *)0x0) {
        local_c = 0;
      }
      else {
        _fread(&DAT_006c0cb4 + iVar1,4,1,pFVar2);
        pvVar3 = _malloc(*(int *)(&DAT_006c0cb4 + iVar1) * 0xc);
        *(void **)(&DAT_006c0cb8 + iVar1) = pvVar3;
        _fread(*(void **)(&DAT_006c0cb8 + iVar1),0xc,*(size_t *)(&DAT_006c0cb4 + iVar1),pFVar2);
        if (DAT_004f4524 != 0) {
          for (local_10 = 0; local_10 < 5; local_10 = local_10 + 1) {
            if ((local_c != local_10) && (*(int *)(&DAT_006c0cb0 + local_10 * 0x114) != 0)) {
              local_1c = 0;
              while (*(int *)(&DAT_006c0cb4 + iVar1) != 0) {
                for (local_20 = 0; local_20 < *(int *)(&DAT_006c0cb4 + local_10 * 0x114);
                    local_20 = local_20 + 1) {
                  File_Load_Assertfile
                            ((uint)(*(int *)(*(int *)(&DAT_006c0cb8 + local_10 * 0x114) +
                                            local_1c * 0xc) !=
                                   *(int *)(*(int *)(&DAT_006c0cb8 + iVar1) + local_1c * 0xc)),
                             0x4f45d0,0x69,s_Duplicate_short_name_found_in_ca_004f4574);
                }
                local_1c = local_1c + 1;
              }
            }
          }
        }
        local_c = local_c + 1;
      }
      return local_c;
    }
    if (*(int *)(&DAT_006c0cb0 + local_10 * 0x114) == 0) {
      local_c = local_10;
      goto LAB_00434144;
    }
    local_10 = local_10 + 1;
  } while( true );
}



/*
 * Decompiled function: FUN_0043433a
 * Entry Point: 0043433a
 * Size: 188 bytes
 */


bool FUN_0043433a(int arg_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = arg_1 + -1;
  iVar2 = *(int *)(&DAT_006c0cb0 + iVar1 * 0x114);
  if (iVar2 != 0) {
    FUN_004db150(*(undefined4 *)(&DAT_006c0cb8 + iVar1 * 0x114));
    _fclose(*(FILE **)(&DAT_006c0cb0 + iVar1 * 0x114));
    *(undefined4 *)(&DAT_006c0cb8 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_006c0cb0 + iVar1 * 0x114) = 0;
    *(undefined4 *)(&DAT_006c0cb4 + iVar1 * 0x114) = 0;
  }
  return iVar2 != 0;
}



/*
 * Decompiled function: FUN_004343f6
 * Entry Point: 004343f6
 * Size: 70 bytes
 */


undefined4 FUN_004343f6(int *csv_buffer,int *out_record)

{
  undefined4 uVar1;
  
  if (*out_record < *csv_buffer) {
    uVar1 = 1;
  }
  else if (*csv_buffer < *out_record) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_00434446
 * Entry Point: 00434446
 * Size: 123 bytes
 */


void * FUN_00434446(int csv_buffer,byte *out_record)

{
  void *pvVar1;
  int local_8;
  
  local_8 = FUN_0043456a(out_record);
  if ((*(int *)(csv_buffer + 0xc) == 0) || (**(int **)(csv_buffer + 0xc) != local_8)) {
    pvVar1 = _bsearch(&local_8,*(void **)(csv_buffer + 8),*(size_t *)(csv_buffer + 4),0xc,FUN_004343f6);
    *(void **)(csv_buffer + 0xc) = pvVar1;
  }
  else {
    pvVar1 = *(void **)(csv_buffer + 0xc);
  }
  return pvVar1;
}



/*
 * Decompiled function: FUN_004344c1
 * Entry Point: 004344c1
 * Size: 169 bytes
 */


size_t FUN_004344c1(int arg_1,undefined4 arg_2,int *arg_3)

{
  undefined4 *csv_buffer;
  int iVar1;
  size_t sVar2;
  void *pvVar3;
  
  csv_buffer = (undefined4 *)(&DAT_006c0cb0 + (arg_1 + -1) * 0x114);
  iVar1 = FUN_00434446((int)csv_buffer,arg_2);
  if (iVar1 == 0) {
    sVar2 = 0xffffffff;
  }
  else {
    if (*arg_3 == 0) {
      pvVar3 = _malloc(*(int *)(iVar1 + 8) + 0x10);
      *arg_3 = (int)pvVar3;
    }
    _fseek((FILE *)*csv_buffer,*(long *)(iVar1 + 4),0);
    sVar2 = _fread((void *)*arg_3,1,*(size_t *)(iVar1 + 8),(FILE *)*csv_buffer);
  }
  return sVar2;
}



/*
 * Decompiled function: FUN_0043456a
 * Entry Point: 0043456a
 * Size: 234 bytes
 */


uint FUN_0043456a(byte *arg_1)

{
  int iVar1;
  int local_138;
  uint local_134 [4];
  char local_124 [260];
  undefined4 local_20;
  undefined4 local_1c;
  uint local_10;
  int local_8;
  
  local_10 = 3;
  local_20 = 0;
  local_138 = 0;
  local_8 = 0;
  __splitpath((char *)arg_1,(char *)local_134,local_124,(char *)&local_1c,(char *)local_134);
  arg_1 = (byte *)&local_1c;
  Str_CopyFast(&local_1c, local_134);
  while( true ) {
    iVar1 = (int)(char)*arg_1;
    arg_1 = arg_1 + 1;
    if (iVar1 == 0) break;
    if ((local_10 & 1) == 0) {
      local_8 = local_10 * iVar1 + local_8;
    }
    else {
      local_138 = local_10 * iVar1 + local_138;
    }
    local_10 = local_10 + 1;
  }
  return (int)(char)(local_1c._1_1_ ^ (byte)local_1c) << 0x18 | local_8 * local_138 & 0xffffffU;
}



/*
 * Decompiled function: Catalog_ParseCsvLine
 * Entry Point: 00434660
 * Size: 589 bytes
 */


int Catalog_ParseCsvLine(uint *csv_buffer,uint *out_record)

{
  FILE *fp;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int local_310;
  char local_30c [252];
  uint local_210 [66];
  uint local_108 [63];
  int local_c;
  int local_8;
  
  if (g_IsAiThinking != 1) {
    Mem_AllocOrFree_004d9630(local_108,(uint *)&DAT_004f45f8);
    Str_CopyFast(local_108,out_record);
    Str_CopyFast(local_108,(uint *)&DAT_004f45fc);
    Mem_AllocOrFree_004d9630(local_210,(uint *)&DAT_005f76e0);
    Str_CopyFast(local_210,(uint *)&DAT_004f4600);
    Mem_AllocOrFree_004d9630(local_210,csv_buffer);
    fp = _fopen((char *)local_210,&DAT_004f4604);
    if (fp != (FILE *)0x0) {
      do {
        iVar1 = _strcmp((char *)local_108,local_30c);
        if (iVar1 == 0) {
          _fscanf(fp,&DAT_004f4608,&local_8);
          _fgets(local_30c,0x50,fp);
          local_c = 0;
          for (local_310 = 0; (local_310 < local_8 && (local_310 < 0x32)); local_310 = local_310 + 1
              ) {
            pcVar2 = _fgets(&g_DuelCardNameBuffer + local_310 * 0xfa,0xfa,fp);
            if (pcVar2 == (char *)0x0) {
              _fclose(fp);
              return -local_c;
            }
            sVar3 = _strlen(&g_DuelCardNameBuffer + local_310 * 0xfa);
            (&DAT_006679ef)[local_310 * 0xfa + sVar3] = 0;
            local_c = local_c + 1;
          }
          _fclose(fp);
          if (local_c < local_8) {
            return -local_c;
          }
          return local_c;
        }
        pcVar2 = _fgets(local_30c,0x50,fp);
      } while (pcVar2 != (char *)0x0);
      _fclose(fp);
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004348b2
 * Entry Point: 004348b2
 * Size: 340 bytes
 */


uint FUN_004348b2(undefined4 csv_buffer,undefined4 out_record)

{
  uint arg_1;
  int iVar1;
  size_t sVar2;
  int local_18;
  int local_10;
  int local_c;
  
  if (g_IsAiThinking == 1) {
    arg_1 = 0;
  }
  else {
    arg_1 = Catalog_ParseCsvLine(csv_buffer,out_record);
    for (local_c = 0; iVar1 = Mem_AllocOrFree_004d9810(arg_1), local_c < iVar1;
        local_c = local_c + 1) {
      sVar2 = _strlen(&g_DuelCardNameBuffer + local_c * 0xfa);
      local_18 = 0;
      for (local_10 = 0; local_10 < (int)sVar2; local_10 = local_10 + 1) {
        if (((&g_DuelCardNameBuffer)[local_c * 0xfa + local_10] == '\\') &&
           ((&DAT_006679f1)[local_c * 0xfa + local_10] == 'n')) {
          (&g_DuelCardNameBuffer)[local_c * 0xfa + local_18] = 10;
          local_10 = local_10 + 1;
        }
        else {
          (&g_DuelCardNameBuffer)[local_c * 0xfa + local_18] = (&g_DuelCardNameBuffer)[local_c * 0xfa + local_10];
        }
        local_18 = local_18 + 1;
      }
      (&g_DuelCardNameBuffer)[local_c * 0xfa + local_18] = 0;
    }
  }
  return arg_1;
}



/*
 * Decompiled function: FUN_00434a10
 * Entry Point: 00434a10
 * Size: 51 bytes
 */


void * FUN_00434a10(void)

{
  void *ptr_1;
  
  ptr_1 = _malloc(0x30);
  _memset(ptr_1,0,0x30);
  return ptr_1;
}



/*
 * Decompiled function: Palette_LoadTRFile
 * Entry Point: 00434a43
 * Size: 596 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * Palette_LoadTRFile(char *str_1,char *str_2)

{
  char local_120 [256];
  int local_20;
  int local_1c;
  FILE *local_18;
  char *local_14;
  int local_10;
  uint local_c;
  undefined2 *local_8;
  
  local_20 = 0;
  local_8 = &DAT_006c0150;
  DAT_006c0150 = 0x300;
  local_18 = _fopen(str_1,&DAT_004f5434);
  if (local_18 == (FILE *)0x0) {
    local_8 = (undefined2 *)0x0;
  }
  else {
    if (DAT_005162b4 != (int *)0x0) {
      FUN_00434fa1(DAT_005162b4);
    }
    DAT_005162b4 = (int *)FUN_00434a10();
    _fgets(local_120,0xff,local_18);
    while ((local_18->_flag & 0x10) == 0) {
      _sscanf(local_120,s__d____d__d__d_004f5438,&local_20,&local_10,&local_1c,&local_c);
      local_14 = _strchr(local_120,0x2d);
      local_14 = local_14 + 1;
      local_14 = _strchr(local_14,0x2d);
      local_14 = local_14 + 1;
      FUN_00434ec7(DAT_005162b4,local_14,local_20);
      *(uint *)(&DAT_005162d0 + local_20 * 4) = local_10 << 0x10 | local_1c << 8 | local_c;
      *(undefined1 *)(local_8 + local_20 * 2 + 2) = (undefined1)local_10;
      *(undefined1 *)((int)local_8 + local_20 * 4 + 5) = (undefined1)local_1c;
      *(undefined1 *)(local_8 + local_20 * 2 + 3) = (undefined1)local_c;
      if ((local_20 == 0) || (local_20 == 0xff)) {
        *(undefined1 *)((int)local_8 + local_20 * 4 + 7) = 0;
      }
      else {
        *(undefined1 *)((int)local_8 + local_20 * 4 + 7) = 1;
      }
      _fgets(local_120,0xff,local_18);
    }
    DAT_005166e4 = 0;
    DAT_004f4610 = 0;
    _DAT_005162c8 = FUN_00434d88(DAT_005162b4);
    DAT_004f4610 = DAT_004f4610 + -1;
    local_8[1] = 0x100;
    _fclose(local_18);
    local_18 = (FILE *)0x0;
    if (str_2 != (char *)0x0) {
      local_18 = _fopen(str_2,&DAT_004f5448);
    }
    if (local_18 != (FILE *)0x0) {
      _fread(&DAT_006c0150,0x404,1,local_18);
      _fclose(local_18);
    }
    *(undefined1 *)((int)local_8 + 0x403) = 0;
    *(undefined1 *)((int)local_8 + 7) = *(undefined1 *)((int)local_8 + 0x403);
    FUN_004350b1();
    FUN_00434c97();
  }
  return local_8;
}



/*
 * Decompiled function: FUN_00434c97
 * Entry Point: 00434c97
 * Size: 114 bytes
 */


undefined4 FUN_00434c97(void)

{
  undefined4 uVar1;
  int local_c;
  int local_8;
  
  if (DAT_004f4618 == 0) {
    local_c = -0xff;
    for (local_8 = 0; local_8 < 0x200; local_8 = local_8 + 1) {
      *(int *)(&DAT_00695750 + local_8 * 4) = local_c * local_c;
      local_c = local_c + 1;
    }
    DAT_004f4618 = 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/*
 * Decompiled function: FUN_00434d09
 * Entry Point: 00434d09
 * Size: 127 bytes
 */


void FUN_00434d09(int *arg_1,int arg_2,int *arg_3)

{
  int local_8;
  
  if (*arg_1 == 0) {
    for (local_8 = 0; local_8 < 8; local_8 = local_8 + 1) {
      if (arg_1[local_8 + 2] != 0) {
        FUN_00434d09((int *)arg_1[local_8 + 2],arg_2,arg_3);
      }
    }
  }
  else {
    *(char *)(*arg_3 + arg_2) = (char)arg_1[1];
    *arg_3 = *arg_3 + 1;
  }
  return;
}



/*
 * Decompiled function: FUN_00434d88
 * Entry Point: 00434d88
 * Size: 319 bytes
 */


int FUN_00434d88(int *arg_1)

{
  int iVar1;
  void *pvVar2;
  size_t local_410;
  int local_40c;
  int local_408;
  undefined1 local_404 [1024];
  
  iVar1 = DAT_005166e4;
  local_408 = 0;
  local_410 = 0;
  DAT_005166e4 = DAT_005166e4 + 1;
  if (DAT_004f4610 < DAT_005166e4) {
    DAT_004f4610 = DAT_005166e4;
  }
  if (*arg_1 == 0) {
    for (local_40c = 0; local_40c < 8; local_40c = local_40c + 1) {
      if (arg_1[local_40c + 2] != 0) {
        iVar1 = FUN_00434d88((int *)arg_1[local_40c + 2]);
        local_408 = local_408 + iVar1;
        local_410 = local_410 + 1;
      }
    }
    if (local_410 != 0) {
      local_410 = 0;
      FUN_00434d09(arg_1,(int)local_404,(int *)&local_410);
      pvVar2 = _malloc(local_410);
      arg_1[10] = (int)pvVar2;
      arg_1[0xb] = local_410;
      FID_conflict__memcpy((void *)arg_1[10],local_404,local_410);
    }
    DAT_005166e4 = DAT_005166e4 + -1;
  }
  else {
    local_408 = 1;
    DAT_005166e4 = iVar1;
  }
  return local_408;
}



/*
 * Decompiled function: FUN_00434ec7
 * Entry Point: 00434ec7
 * Size: 218 bytes
 */


undefined4 FUN_00434ec7(undefined4 *arg_1,char *str_2,undefined4 arg_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  size_t sVar5;
  char *str_2_00;
  
  sVar1 = _strspn(str_2,&DAT_004f544c);
  for (str_2 = str_2 + sVar1; *str_2 != '\0'; str_2 = str_2 + sVar1 + sVar4 + sVar5) {
    iVar2 = _atoi(str_2);
    if (arg_1[iVar2 + 2] == 0) {
      uVar3 = FUN_00434a10();
      arg_1[iVar2 + 2] = uVar3;
    }
    arg_1 = (undefined4 *)arg_1[iVar2 + 2];
    str_2_00 = &DAT_004f5454;
    sVar1 = _strspn(str_2,&DAT_004f5458);
    sVar1 = _strcspn(str_2 + sVar1,str_2_00);
    sVar4 = _strspn(str_2,&DAT_004f5450);
    sVar5 = _strspn(str_2 + sVar1 + sVar4,&DAT_004f545c);
  }
  *arg_1 = 1;
  arg_1[1] = arg_3;
  return 0;
}



/*
 * Decompiled function: FUN_00434fa1
 * Entry Point: 00434fa1
 * Size: 172 bytes
 */


int FUN_00434fa1(int *arg_1)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*arg_1 == 0) {
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (arg_1[local_c + 2] != 0) {
        iVar1 = FUN_00434fa1((int *)arg_1[local_c + 2]);
        local_8 = local_8 + iVar1;
      }
    }
    if (arg_1[10] != 0) {
      FUN_004db150(arg_1[10]);
    }
    FUN_004db150(arg_1);
  }
  else {
    FUN_004db150(arg_1);
    local_8 = 1;
  }
  return local_8;
}



/*
 * Decompiled function: Color_RGBToOctreePath
 * Entry Point: 0043504d
 * Size: 100 bytes
 */


void Color_RGBToOctreePath(uint csv_buffer,uint *out_record)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = ((csv_buffer & 0xff0000) >> 0x10) * 8;
  uVar4 = *(uint *)(&DAT_00694f54 + iVar1);
  iVar2 = (csv_buffer & 0xff) * 8;
  uVar5 = *(uint *)(&DAT_006bf954 + iVar2);
  iVar3 = (csv_buffer >> 8 & 0xff) * 8;
  uVar6 = *(uint *)(&DAT_006be134 + iVar3);
  *out_record = *(uint *)(&DAT_00694f50 + iVar1) | *(uint *)(&DAT_006bf950 + iVar2) |
          *(uint *)(&DAT_006be130 + iVar3);
  out_record[1] = uVar4 | uVar5 | uVar6;
  return;
}



/*
 * Decompiled function: FUN_004350b1
 * Entry Point: 004350b1
 * Size: 260 bytes
 */


undefined4 FUN_004350b1(void)

{
  uint local_10;
  int local_c;
  uint local_8;
  
  for (local_8 = 0; (int)local_8 < 0x100; local_8 = local_8 + 1) {
    local_10 = 0x80;
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f461c[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f461c[local_8 * 8 + local_c] = 4;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f4620[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f4620[local_8 * 8 + local_c] = 2;
      }
      if ((local_8 & local_10) == 0) {
        PTR_DAT_004f4624[local_8 * 8 + local_c] = 0;
      }
      else {
        PTR_DAT_004f4624[local_8 * 8 + local_c] = 1;
      }
      local_10 = (int)local_10 >> 1;
    }
  }
  return 0;
}



/*
 * Decompiled function: FUN_004351b5
 * Entry Point: 004351b5
 * Size: 393 bytes
 */


undefined4 FUN_004351b5(uint arg_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int local_34;
  uint local_2c;
  int local_28;
  
  Color_RGBToOctreePath(arg_1,(uint *)&DAT_005166d0);
  pbVar5 = &DAT_005166d0;
  piVar3 = DAT_005162b4;
  do {
    piVar1 = (int *)piVar3[*pbVar5 + 2];
    pbVar5 = pbVar5 + 1;
    if (piVar1 == (int *)0x0) {
      if (*piVar3 == 0) {
        iVar2 = piVar3[10];
        local_34 = 0x7fffffff;
        for (local_28 = 0; local_28 < piVar3[0xb]; local_28 = local_28 + 1) {
          iVar4 = *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 >> 8 & 0xff) -
                          (uint)(byte)(&DAT_005162d1)[(uint)*(byte *)(local_28 + iVar2) * 4]) * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 & 0xff) -
                          (*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) & 0xff))
                          * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          (((arg_1 & 0xff0000) >> 0x10) -
                          ((*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) &
                           0xff0000) >> 0x10)) * 4);
          if (iVar4 < local_34) {
            local_2c = (uint)*(byte *)(local_28 + iVar2);
            local_34 = iVar4;
          }
        }
        return *(undefined4 *)(&DAT_005162d0 + local_2c * 4);
      }
      return *(undefined4 *)(&DAT_005162d0 + piVar3[1] * 4);
    }
    piVar3 = piVar1;
  } while ((char)*piVar1 != '\x01');
  return *(undefined4 *)(&DAT_005162d0 + piVar1[1] * 4);
}



/*
 * Decompiled function: FUN_00435343
 * Entry Point: 00435343
 * Size: 371 bytes
 */


uint FUN_00435343(uint arg_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int local_34;
  uint local_2c;
  int local_28;
  
  Color_RGBToOctreePath(arg_1,(uint *)&DAT_005162c0);
  pbVar5 = &DAT_005162c0;
  piVar3 = DAT_005162b4;
  do {
    piVar1 = (int *)piVar3[*pbVar5 + 2];
    pbVar5 = pbVar5 + 1;
    if (piVar1 == (int *)0x0) {
      if (*piVar3 == 0) {
        iVar2 = piVar3[10];
        local_34 = 0x7fffffff;
        for (local_28 = 0; local_28 < piVar3[0xb]; local_28 = local_28 + 1) {
          iVar4 = *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 >> 8 & 0xff) -
                          (uint)(byte)(&DAT_005162d1)[(uint)*(byte *)(local_28 + iVar2) * 4]) * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          ((arg_1 & 0xff) -
                          ((*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) &
                           0xff0000) >> 0x10)) * 4) +
                  *(int *)(PTR_DAT_004f4614 +
                          (((arg_1 & 0xff0000) >> 0x10) -
                          (*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_28 + iVar2) * 4) & 0xff))
                          * 4);
          if (iVar4 < local_34) {
            local_2c = (uint)*(byte *)(local_28 + iVar2);
            local_34 = iVar4;
          }
        }
        return local_2c;
      }
      return piVar3[1];
    }
    piVar3 = piVar1;
  } while ((char)*piVar1 != '\x01');
  return piVar1[1];
}



/*
 * Decompiled function: FUN_004354bb
 * Entry Point: 004354bb
 * Size: 150 bytes
 */


int FUN_004354bb(int *csv_buffer,int *out_record)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_8 = 0;
  if (*csv_buffer == 0) {
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      if (csv_buffer[local_c + 2] != 0) {
        iVar1 = FUN_004354bb((int *)csv_buffer[local_c + 2],out_record);
        local_8 = local_8 + iVar1;
        out_record = out_record + iVar1;
      }
    }
  }
  else {
    *out_record = csv_buffer[1];
    local_8 = 1;
  }
  return local_8;
}



/*
 * Decompiled function: FUN_00435551
 * Entry Point: 00435551
 * Size: 152 bytes
 */


undefined4 FUN_00435551(uint *x,int y,int width,int height)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  for (local_10 = 0; local_10 < y; local_10 = local_10 + 1) {
    local_c = 0;
    local_18 = *x;
    for (; local_c < width * 3; local_c = local_c + 3) {
      uVar1 = *(uint *)(local_c + 3 + (int)x);
      uVar2 = FUN_004351b5(local_18);
      *(undefined4 *)(local_c + (int)x) = uVar2;
      local_18 = uVar1;
    }
    x = (uint *)((int)x + height + width * 3);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004355e9
 * Entry Point: 004355e9
 * Size: 230 bytes
 */


undefined4 FUN_004355e9(uint *x,int y,int width,int height)

{
  undefined1 uVar1;
  uint arg_1;
  uint local_20;
  int local_18;
  int local_14;
  uint *local_10;
  int local_8;
  
  local_10 = x;
  for (local_18 = 0; local_18 < y; local_18 = local_18 + 1) {
    local_8 = 0;
    local_14 = 0;
    local_20 = *x;
    for (; local_14 < width * 3; local_14 = local_14 + 3) {
      arg_1 = local_20 & 0xffffff;
      local_20 = *(uint *)(local_14 + 3 + (int)x);
      uVar1 = FUN_00435343(arg_1);
      *(undefined1 *)(local_8 + (int)local_10) = uVar1;
      if (*(uint *)(&DAT_005162d0 + (uint)*(byte *)(local_8 + (int)local_10) * 4) != arg_1) {
        *(undefined4 *)(&DAT_005162d0 + (uint)*(byte *)(local_8 + (int)local_10) * 4) = 0;
      }
      local_8 = local_8 + 1;
    }
    x = (uint *)((int)x + height + width * 3);
    local_10 = (uint *)((int)local_10 + height + width);
  }
  return 0;
}



/*
 * Decompiled function: FUN_004356cf
 * Entry Point: 004356cf
 * Size: 1440 bytes
 */


/* WARNING: Type propagation algorithm not settling */

int FUN_004356cf(int arg_1,int arg_2,uint *arg_3,int arg_4,int arg_5,int arg_6)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_88;
  uint local_84;
  int local_80;
  undefined *local_7c;
  uint local_74;
  undefined *local_70 [6];
  int local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  undefined *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  int local_1c;
  uint local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  int local_c;
  uint local_8;
  
  local_14 = 0;
  local_12 = 0;
  local_10 = 0;
  local_e = 0;
  local_54 = 0;
  local_52 = 0;
  local_50 = 0;
  local_4e = 0;
  local_24 = 0xffff;
  local_22 = 0xffff;
  local_20 = 0xffff;
  local_1e = 0;
  local_3c = 1;
  local_2c = 0;
  local_7c = &DAT_004f46a8 + arg_1 * 0xc0;
  local_18 = arg_5 * 8 + 0x50U >> 2;
  if (arg_1 == 0) {
    DAT_004f542c = arg_1;
    local_58 = 0;
  }
  else if (arg_1 == 1) {
    DAT_004f542c = arg_1;
    local_58 = FUN_00435551(arg_3,arg_4,arg_5,arg_6);
  }
  else {
    if (DAT_005166e0 == 0) {
      for (local_4c = -0x200; (int)local_4c < 0x200; local_4c = local_4c + 1) {
        if (((int)local_4c < 0) || (0xff < (int)local_4c)) {
          if ((int)local_4c < 0) {
            PTR_DAT_004f5428[local_4c] = 0;
          }
          else {
            PTR_DAT_004f5428[local_4c] = 0xff;
          }
        }
        else {
          PTR_DAT_004f5428[local_4c] = (undefined1)local_4c;
        }
      }
      DAT_005166e0 = 1;
    }
    if (arg_1 != DAT_004f542c) {
      for (local_4c = 0; local_4c < 0x41; local_4c = local_4c + 1) {
        if (*(int *)(&DAT_006c0560 + local_4c * 4) != 0) {
          FUN_004db150(*(undefined4 *)(&DAT_006c0560 + local_4c * 4));
          *(undefined4 *)(&DAT_006c0560 + local_4c * 4) = 0;
        }
      }
      Palette_AllocErrorDiffusionTable(arg_1,0x6c0560);
      DAT_004f542c = arg_1;
    }
    for (local_4c = 0; local_4c < 5; local_4c = local_4c + 1) {
      FUN_0047ee63((undefined8 *)(&DAT_00695f50 + local_4c * 0x8060),0,0x8060);
      local_70[local_4c + 1] = (undefined *)(local_4c * 0x8060 + 0x695f78);
    }
    iVar2 = *(int *)(&DAT_004f4630 + arg_1 * 4);
    for (local_58 = 0; local_58 < arg_4; local_58 = local_58 + 1) {
      if (local_3c < 1) {
        local_80 = arg_5 + -1;
        local_1c = -1;
        local_88 = -3;
      }
      else {
        local_80 = 0;
        local_1c = arg_5;
        local_88 = 3;
      }
      local_c = local_80 * 3;
      for (local_4c = local_80; local_1c != local_4c; local_4c = local_4c + local_3c) {
        uVar3 = *(uint *)(local_c + (int)arg_3);
        local_28 = uVar3 & 0xffffff;
        *(uint *)(local_c + (int)arg_3) = *(uint *)(local_c + (int)arg_3) & 0xff000000;
        psVar1 = (short *)((int)local_70[1] + local_4c * 8);
        if (local_28 == 0) {
          local_84 = 0;
          local_74 = 0;
          local_38 = 0;
          local_8 = 0;
        }
        else if (local_28 == 0xffffff) {
          local_74 = 0xff;
          local_38 = 0xff;
          local_8 = 0xff;
          local_84 = 0xffffff;
        }
        else {
          local_8 = (uint)(byte)PTR_DAT_004f5428[(uVar3 & 0xff) + ((int)*psVar1 >> 8)];
          local_38 = (uint)(byte)PTR_DAT_004f5428[(local_28 >> 8 & 0xff) + ((int)psVar1[1] >> 8)];
          local_74 = (uint)(byte)PTR_DAT_004f5428[(local_28 >> 0x10) + ((int)psVar1[2] >> 8)];
          local_28 = local_74 << 0x10 | local_38 << 8 | local_8;
          local_84 = FUN_004351b5(local_28);
        }
        *(uint *)(local_c + (int)arg_3) = *(uint *)(local_c + (int)arg_3) | local_84;
        local_40 = local_8 - (local_84 & 0xff);
        local_34 = local_38 - (local_84 >> 8 & 0xff);
        local_70[0] = local_7c + iVar2 * 0x10;
        for (local_30 = local_7c; local_30 < local_7c + iVar2 * 0x10; local_30 = local_30 + 0x10) {
          local_44 = *(int *)(local_30 + 4);
          local_48 = *(int *)(local_30 + 8);
          iVar4 = *(int *)(local_30 + 0xc);
          psVar1 = (short *)((int)local_70[*(int *)(local_30 + 8) + 1] +
                            (*(int *)(local_30 + 4) + local_4c) * 8);
          *psVar1 = (short)*(undefined4 *)(iVar4 + local_40 * 4) + *psVar1;
          psVar1[1] = (short)*(undefined4 *)(iVar4 + local_34 * 4) + psVar1[1];
          psVar1[2] = (short)*(undefined4 *)(iVar4 + (local_74 - (local_84 >> 0x10)) * 4) +
                      psVar1[2];
        }
        local_c = local_c + local_88;
      }
      FUN_00435c74(local_70 + 1,*(int *)(&DAT_004f4658 + arg_1 * 4));
      _memset(local_70[*(int *)(&DAT_004f4658 + arg_1 * 4)] + -0x28,0,local_18 << 2);
      if (arg_2 != 0) {
        local_3c = -local_3c;
        local_7c = &DAT_004f46a8 + (uint)(local_3c == -1) * 0x6c0 + arg_1 * 0xc0;
      }
      arg_3 = (uint *)((int)arg_3 + arg_5 * 3 + arg_6);
    }
  }
  return local_58;
}



/*
 * Decompiled function: FUN_00435c74
 * Entry Point: 00435c74
 * Size: 65 bytes
 */


void FUN_00435c74(undefined4 *csv_buffer,int out_record)

{
  undefined4 uVar1;
  
  uVar1 = *csv_buffer;
  FID_conflict__memcpy(csv_buffer,csv_buffer + 1,out_record * 4 - 4);
  csv_buffer[out_record + -1] = uVar1;
  return;
}



