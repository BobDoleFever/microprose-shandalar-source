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
 * Decompiled function: FUN_00510b70
 * Entry Point: 00510b70
 * Size: 610 bytes
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00510b70(int arg_1,int arg_2,int arg_3,char *str_4,short *arg_5)

{
  char *_Str2;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 arg_1_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 arg_2_00;
  short local_400 [512];
  
  _Str2 = strchr(str_4,0x2e);
  iVar1 = _stricmp(&DAT_005327f4,_Str2);
  if (iVar1 != 0) {
    iVar1 = _open(str_4,0x8000);
    arg_1_00 = extraout_ECX;
    arg_2_00 = extraout_EDX;
    if (iVar1 == -1) {
      AssertOrLog(0,0x5327b8,0x87,str_4);
      arg_1_00 = extraout_ECX_00;
      arg_2_00 = extraout_EDX_00;
    }
    DAT_00706500 = PTR_DAT_005327b0;
    _DAT_006261ac = 0xffffffff;
    DAT_0067f43c = &LAB_00510f90;
    DAT_006261a8 = iVar1;
    DAT_006261b0 = iVar1;
    FUN_0070d000(arg_1_00,arg_2_00,(ushort *)arg_5);
    if (arg_1 < 0) {
      DAT_00536864 = 0;
    }
    DAT_006261a4 = 0;
    if (0 < DAT_00536864) {
      do {
        Mem_AllocOrFree_0070d484(&DAT_00706710,DAT_00536860);
        Surface_PutLine((undefined4 *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,DAT_00536860);
        DAT_006261a4 = DAT_006261a4 + 1;
      } while (DAT_006261a4 < DAT_00536864);
    }
    if ((DAT_005327b4 != DAT_006261b0) && (iVar1 = _close(DAT_006261b0), iVar1 != 0)) {
      AssertOrLog(0,0x5327b8,0xa7,(char *)0x0);
    }
    return;
  }
  DAT_00703930 = (int)fopen(str_4,&DAT_0052afc4);
  AssertOrLog((uint)((FILE *)DAT_00703930 != (FILE *)0x0),0x5327b8,0xf6,
              s_Error_Opening_File__s_005327dc);
  DAT_00703938 = str_4;
  if (arg_5 == (short *)0x1) {
    arg_5 = local_400;
  }
  if (arg_5 == (short *)0x0) {
    FUN_00512500((void *)0x0);
  }
  else {
    FUN_00512500(arg_5 + 3);
    *(undefined1 *)arg_5 = 0x4d;
    *(undefined1 *)((int)arg_5 + 1) = 0x31;
    arg_5[1] = 0x300;
    *(undefined1 *)(arg_5 + 2) = 0;
    *(undefined1 *)((int)arg_5 + 5) = 0xff;
    FUN_0050e8b0(arg_5);
  }
  if (arg_1 < 0) {
    DAT_00536864 = 0;
  }
  DAT_006261a4 = 0;
  if (0 < DAT_00536864) {
    do {
      FUN_005126b0(&DAT_00706710);
      Surface_PutLine((undefined4 *)&DAT_00706710,arg_1,arg_2,DAT_006261a4 + arg_3,DAT_00536860);
      DAT_006261a4 = DAT_006261a4 + 1;
    } while (DAT_006261a4 < DAT_00536864);
  }
  fclose((FILE *)DAT_00703930);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510de0
 * Entry Point: 00510de0
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510de0(int arg1,char *str_2)

{
  FUN_00510b70(arg1,0,0,str_2,(short *)0x1);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510e20
 * Entry Point: 00510e20
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510e20(int arg1,char *str_2)

{
  FUN_00510b70(arg1,0,0,str_2,(short *)0x0);
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
  FUN_00510b70(-1,0,0,filepath,(short *)0x1);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_00510e60
 * Entry Point: 00510e60
 * Size: 25 bytes
 */


void Mem_AllocOrFree_00510e60(char *str_1,short *arg2)

{
  FUN_00510b70(-1,0,0,str_1,arg2);
  return;
}



/*
 * Decompiled function: FUN_00510fc0
 * Entry Point: 00510fc0
 * Size: 350 bytes
 */


void FUN_00510fc0(int *arg1,int *arg2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  
  iVar1 = *arg2;
  iVar2 = arg2[1];
  iVar3 = arg2[2];
  iVar5 = iVar2;
  if (iVar2 <= iVar3) {
    iVar5 = iVar3;
  }
  if (iVar5 <= iVar1) {
    iVar5 = iVar1;
  }
  local_1c = iVar2;
  if (iVar3 <= iVar2) {
    local_1c = iVar3;
  }
  if (iVar1 <= local_1c) {
    local_1c = iVar1;
  }
  if (iVar5 != 0) {
    local_1c = iVar5 - local_1c;
    iVar4 = (local_1c * 0x1000) / iVar5;
    if (local_1c == 0) {
      *arg1 = 0;
      arg1[1] = iVar4;
      arg1[2] = iVar5 << 6;
      return;
    }
    if (iVar5 == iVar1) {
      local_1c = ((iVar2 - iVar3) * 0xf00) / local_1c;
    }
    else if (iVar5 == iVar2) {
      local_1c = ((iVar3 - iVar1) * 0xf00) / local_1c + 0x1e00;
    }
    else {
      local_1c = ((iVar1 - iVar2) * 0xf00) / local_1c + 0x3c00;
    }
    if (local_1c < 0) {
      local_1c = local_1c + 0x5a00;
    }
    *arg1 = local_1c;
    arg1[1] = iVar4;
    arg1[2] = iVar5 << 6;
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


void FUN_00511120(uint *arg1,int *arg2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar1 = arg2[1];
  if ((iVar1 == 0) && (*arg2 == -1)) {
    uVar2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
    *arg1 = uVar2;
    arg1[1] = uVar2;
    arg1[2] = uVar2;
    arg1[3] = local_4;
    return;
  }
  if (*arg2 == 0x5a00) {
    *arg2 = 0;
  }
  uVar2 = (int)(arg2[2] + (arg2[2] >> 0x1f & 0x3fU)) >> 6;
  iVar3 = (0x1000 - iVar1) * uVar2;
  uVar4 = (int)(iVar3 + (iVar3 >> 0x1f & 0xfffU)) >> 0xc;
  uVar5 = ((0xf00000 - iVar1 * (*arg2 % 0xf00)) * uVar2) / 0xf00000;
  local_10 = 0xf00;
  uVar6 = (((*arg2 % 0xf00 + -0xf00) * iVar1 + 0xf00000) * uVar2) / 0xf00000;
  switch(*arg2 / 0xf00) {
  case 0:
    local_10 = uVar2;
    local_c = uVar6;
    local_8 = uVar4;
    break;
  case 1:
    local_10 = uVar5;
    local_c = uVar2;
    local_8 = uVar4;
    break;
  case 2:
    local_10 = uVar4;
    local_c = uVar2;
    local_8 = uVar6;
    break;
  case 3:
    local_10 = uVar4;
    local_c = uVar5;
    local_8 = uVar2;
    break;
  case 4:
    local_10 = uVar6;
    local_c = uVar4;
    local_8 = uVar2;
    break;
  case 5:
    local_10 = uVar2;
    local_c = uVar4;
    local_8 = uVar5;
  }
  *arg1 = local_10;
  arg1[1] = local_c;
  arg1[2] = local_8;
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
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10 [4];
  
  iVar6 = (int)arg2;
  iVar1 = (int)(0x4000 / (longlong)iVar6);
  if (DAT_0070a880 != 8) {
    return (uint)(ushort)((ulonglong)(0x4000 / (longlong)iVar6) >> 0x10) << 0x10;
  }
  puVar2 = &DAT_0070a130;
  puVar8 = &DAT_007051e0;
  for (iVar4 = 0xc0; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar8 = puVar8 + 1;
  }
  local_2c = (int)arg1;
  local_28 = local_2c;
  local_24 = local_2c;
  puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&local_2c);
  local_1c = *puVar2;
  local_18 = puVar2[1];
  local_14 = puVar2[2];
  sVar7 = 0;
  FUN_0050e8b0((short *)&DAT_0070a130);
  do {
    iVar5 = (int)sVar7;
    pbVar9 = (byte *)(iVar5 * 3 + DAT_00532804);
    (&DAT_00705500)[iVar5 * 4] = (uint)*pbVar9;
    (&DAT_00705504)[iVar5 * 4] = (uint)pbVar9[1];
    (&DAT_00705508)[iVar5 * 4] = (uint)pbVar9[2];
    puVar2 = (undefined4 *)FUN_00510fc0((int *)local_10,&DAT_00705500 + iVar5 * 4);
    (&DAT_007039e0)[iVar5 * 3] = *puVar2;
    (&DAT_007039e4)[iVar5 * 3] = puVar2[1];
    (&DAT_007039e8)[iVar5 * 3] = puVar2[2];
    iVar4 = (local_18 - (&DAT_007039e4)[iVar5 * 3]) / iVar6;
    (&DAT_007045e4)[iVar5 * 3] = iVar4;
    if ((int)(&DAT_007039e4)[iVar5 * 3] < local_18) {
      iVar3 = 0x1000;
    }
    else {
      iVar3 = -0x1000;
    }
    sVar7 = sVar7 + 1;
    (&DAT_007045e4)[iVar5 * 3] = iVar3 / iVar6 + iVar4;
  } while (sVar7 < 0x100);
  local_3e = 1;
  if (0 < arg2) {
    do {
      sVar7 = 0;
      do {
        iVar6 = (int)sVar7;
        if (local_14 == 0) {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007039e4)[iVar6 * 3];
          local_30 = (&DAT_007039e8)[iVar6 * 3] - iVar1;
          (&DAT_007039e8)[iVar6 * 3] = local_30;
        }
        else {
          local_38 = (&DAT_007039e0)[iVar6 * 3];
          local_34 = (&DAT_007045e4)[iVar6 * 3] * (int)local_3e + (&DAT_007039e4)[iVar6 * 3];
          if (0xfbf < local_34) {
            local_34 = 0xfc0;
          }
          if (local_34 < 1) {
            local_34 = 0;
          }
          iVar4 = iVar1;
          if (local_14 < (int)(&DAT_007039e8)[iVar6 * 3]) {
            iVar4 = -iVar1;
          }
          (&DAT_007039e8)[iVar6 * 3] = (&DAT_007039e8)[iVar6 * 3] + iVar4;
          local_30 = (&DAT_007039e8)[iVar6 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        if (local_30 < 1) {
          local_30 = 0;
        }
        iVar4 = (int)sVar7;
        sVar7 = sVar7 + 1;
        puVar2 = (undefined4 *)FUN_00511120(local_10,&local_38);
        (&DAT_00705500)[iVar4 * 4] = *puVar2;
        (&DAT_00705504)[iVar4 * 4] = puVar2[1];
        iVar6 = iVar4 * 3;
        (&DAT_00705508)[iVar4 * 4] = puVar2[2];
        (&DAT_0070550c)[iVar4 * 4] = puVar2[3];
        *(undefined1 *)(DAT_00532804 + iVar6) = *(undefined1 *)(&DAT_00705500 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 1 + iVar6) = *(undefined1 *)(&DAT_00705504 + iVar4 * 4);
        *(undefined1 *)(DAT_00532804 + 2 + iVar6) = *(undefined1 *)(&DAT_00705508 + iVar4 * 4);
      } while (sVar7 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + 1;
    } while (local_3e <= arg2);
  }
  sVar7 = 0;
  do {
    iVar1 = (int)sVar7;
    sVar7 = sVar7 + 1;
    iVar1 = iVar1 * 3;
    *(undefined1 *)(DAT_00532804 + iVar1) = (undefined1)local_2c;
    *(undefined1 *)(DAT_00532804 + 1 + iVar1) = (undefined1)local_28;
    *(undefined1 *)(DAT_00532804 + 2 + iVar1) = (undefined1)local_24;
  } while (sVar7 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  iVar1 = FUN_0050d560(0,0);
  return iVar1;
}



/*
 * Decompiled function: FUN_005115a0
 * Entry Point: 005115a0
 * Size: 784 bytes
 */


int FUN_005115a0(short arg1,short arg2)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined2 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  bool bVar13;
  short local_3e;
  int local_38;
  int local_34;
  int local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar11 = (int)arg2;
  iVar3 = (int)(0x3fc0 / (longlong)iVar11);
  if (DAT_0070a880 != 8) {
    return (uint)(ushort)((ulonglong)(0x3fc0 / (longlong)iVar11) >> 0x10) << 0x10;
  }
  local_2c = CONCAT11((undefined1)arg1,(undefined1)arg1);
  local_2a = (undefined1)arg1;
  iVar9 = 0x2ff;
  puVar8 = DAT_00532804;
  puVar12 = DAT_00532808;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 1;
    bVar13 = iVar9 != 0;
    iVar9 = iVar9 + -1;
  } while (bVar13);
  sVar2 = 0;
  do {
    iVar9 = (int)sVar2;
    sVar2 = sVar2 + 1;
    puVar10 = (undefined2 *)(DAT_00532804 + iVar9 * 3);
    *puVar10 = local_2c;
    *(undefined1 *)(puVar10 + 1) = (undefined1)arg1;
  } while (sVar2 < 0x100);
  FUN_0050e8b0((short *)&DAT_0070a130);
  local_10 = (int)arg1;
  local_c = local_10;
  local_8 = local_10;
  puVar4 = (undefined4 *)FUN_00510fc0((int *)&local_2c,&local_10);
  sVar2 = 0;
  local_1c = *puVar4;
  local_18 = puVar4[1];
  local_14 = puVar4[2];
  do {
    iVar9 = (int)sVar2;
    pbVar7 = DAT_00532808 + iVar9 * 3;
    (&DAT_00705500)[iVar9 * 4] = (uint)*pbVar7;
    (&DAT_00705504)[iVar9 * 4] = (uint)pbVar7[1];
    (&DAT_00705508)[iVar9 * 4] = (uint)pbVar7[2];
    puVar4 = (undefined4 *)FUN_00510fc0((int *)&local_2c,&DAT_00705500 + iVar9 * 4);
    (&DAT_007039e0)[iVar9 * 3] = *puVar4;
    (&DAT_007039e4)[iVar9 * 3] = puVar4[1];
    (&DAT_007039e8)[iVar9 * 3] = puVar4[2];
    (&DAT_007045e4)[iVar9 * 3] = (local_18 - (&DAT_007039e4)[iVar9 * 3]) / iVar11;
    if ((int)(&DAT_007039e4)[iVar9 * 3] < local_18) {
      iVar5 = 0x1000;
    }
    else {
      iVar5 = -0x1000;
    }
    sVar2 = sVar2 + 1;
    (&DAT_007045e4)[iVar9 * 3] = iVar5 / iVar11;
  } while (sVar2 < 0x100);
  local_3e = arg2;
  if (0 < arg2) {
    do {
      sVar2 = 0;
      do {
        iVar11 = (int)sVar2;
        if (local_14 == 0) {
          local_38 = (&DAT_007039e0)[iVar11 * 3];
          local_34 = (&DAT_007039e4)[iVar11 * 3];
          local_30 = (&DAT_007039e8)[iVar11 * 3] - local_3e * iVar3;
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
          local_30 = iVar3 * local_3e + (&DAT_007039e8)[iVar11 * 3];
          if (0x3fbf < local_30) {
            local_30 = 0x3fc0;
          }
        }
        iVar5 = (int)sVar2;
        piVar6 = (int *)FUN_00511120((uint *)&local_2c,&local_38);
        (&DAT_00705500)[iVar5 * 4] = *piVar6;
        (&DAT_00705504)[iVar5 * 4] = piVar6[1];
        iVar9 = iVar5 * 3;
        (&DAT_00705508)[iVar5 * 4] = piVar6[2];
        (&DAT_0070550c)[iVar5 * 4] = piVar6[3];
        iVar11 = (&DAT_00705500)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9] = (char)iVar11;
        iVar11 = (&DAT_00705504)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        DAT_00532804[iVar9 + 1] = (char)iVar11;
        iVar11 = (&DAT_00705508)[iVar5 * 4];
        if (0xfe < iVar11) {
          iVar11 = 0xff;
        }
        sVar2 = sVar2 + 1;
        DAT_00532804[iVar9 + 2] = (char)iVar11;
      } while (sVar2 < 0x100);
      FUN_0050e8b0((short *)&DAT_0070a130);
      local_3e = local_3e + -1;
    } while (local_3e != 0);
  }
  iVar3 = 0x2ff;
  puVar8 = DAT_00532808;
  puVar12 = DAT_00532804;
  do {
    uVar1 = *puVar8;
    puVar8 = puVar8 + 1;
    *puVar12 = uVar1;
    puVar12 = puVar12 + 1;
    bVar13 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar13);
  iVar3 = FUN_0050e8b0((short *)&DAT_0070a130);
  return iVar3;
}



/*
 * Decompiled function: FUN_00511930
 * Entry Point: 00511930
 * Size: 172 bytes
 */


undefined4
FUN_00511930(HDC hdc,COLORREF arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8)

{
  HDC hdc_00;
  HBITMAP h;
  HBRUSH hbr;
  RECT local_10;
  
  local_10.left = 0;
  local_10.top = 0;
  local_10.right = arg_5;
  local_10.bottom = arg_6;
  hdc_00 = CreateCompatibleDC(hdc);
  h = CreateCompatibleBitmap(hdc,arg_5,arg_6);
  hbr = CreateSolidBrush(arg_2);
  SelectObject(hdc_00,h);
  FillRect(hdc_00,&local_10,hbr);
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


uint FUN_005119e0(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int y;
  COLORREF color;
  uint uVar4;
  int x;
  int x_00;
  int y_00;
  int cy;
  uint uVar5;
  uint uVar6;
  uint local_10;
  
  iVar1 = (uint)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  iVar2 = (uint)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  uVar4 = 0x40000000;
  uVar6 = 0;
  uVar5 = (iVar2 + 1) * (iVar1 + 1);
  iVar3 = 0;
  do {
    if ((uVar4 & uVar5) != 0) {
      if (uVar6 == 0) {
        uVar6 = uVar4;
      }
      iVar3 = iVar3 + 1;
    }
    uVar4 = (int)uVar4 >> 1;
  } while (uVar4 != 0);
  if (iVar3 != 1) {
    uVar6 = uVar6 * 2;
  }
  local_10 = 0;
  uVar4 = 1;
  if (1 < (int)uVar6) {
    do {
      local_10 = local_10 | uVar4;
      uVar4 = uVar4 * 2;
    } while ((int)uVar4 < (int)uVar6);
  }
  iVar3 = rand();
  uVar4 = iVar3 % (int)uVar6;
  uVar6 = iVar3 / (int)uVar6;
  while (uVar5 != 0) {
    uVar4 = uVar4 * 0x21 + 1 & local_10;
    uVar6 = uVar4;
    if ((int)uVar4 <= iVar2 * iVar1) {
      y = (int)uVar4 / iVar1;
      x_00 = (int)uVar4 % iVar1;
      x = x_00 * arg_6 + arg_2;
      y_00 = y * arg_7 + arg_3;
      iVar3 = arg_6;
      if (arg_4 + arg_2 <= arg_6 + x) {
        iVar3 = (arg_2 - x) + arg_4;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_3 - y_00) + arg_5;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x_00,y);
        uVar6 = SetPixelV(hdc,x_00,y,color);
      }
      else {
        uVar6 = BitBlt(hdc,x,y_00,iVar3,cy,param_8,x,y_00,0xcc0020);
      }
      uVar5 = uVar5 - 1;
    }
  }
  return uVar6;
}



/*
 * Decompiled function: FUN_00511b90
 * Entry Point: 00511b90
 * Size: 461 bytes
 */


uint FUN_00511b90(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,HDC param_8,
                 int arg_9,int arg_10)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int y;
  COLORREF color;
  int iVar4;
  int x;
  int y_00;
  int cx;
  int cy;
  uint uVar5;
  uint uVar6;
  uint local_1c;
  
  iVar1 = (uint)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  iVar2 = (uint)(arg_5 % arg_7 != 0) + arg_5 / arg_7;
  iVar4 = 0;
  uVar6 = 0;
  uVar5 = (iVar2 + 1) * (iVar1 + 1);
  uVar3 = 0x40000000;
  do {
    if ((uVar5 & uVar3) != 0) {
      if (uVar6 == 0) {
        uVar6 = uVar3;
      }
      iVar4 = iVar4 + 1;
    }
    uVar3 = (int)uVar3 >> 1;
  } while (uVar3 != 0);
  if (iVar4 != 1) {
    uVar6 = uVar6 * 2;
  }
  local_1c = 0;
  uVar3 = 1;
  if (1 < (int)uVar6) {
    do {
      local_1c = local_1c | uVar3;
      uVar3 = uVar3 * 2;
    } while ((int)uVar3 < (int)uVar6);
  }
  iVar4 = rand();
  uVar3 = iVar4 % (int)uVar6;
  uVar6 = iVar4 / (int)uVar6;
  while (uVar5 != 0) {
    uVar3 = uVar3 * 0x21 + 1 & local_1c;
    uVar6 = uVar3;
    if ((int)uVar3 <= iVar2 * iVar1) {
      y = (int)uVar3 / iVar1;
      x = (int)uVar3 % iVar1;
      iVar4 = arg_2 + x * arg_6;
      y_00 = arg_3 + y * arg_7;
      cx = arg_6;
      if (arg_4 + arg_2 <= arg_6 + iVar4) {
        cx = (arg_4 - iVar4) + arg_2;
      }
      cy = arg_7;
      if (arg_5 + arg_3 <= arg_7 + y_00) {
        cy = (arg_5 - y_00) + arg_3;
      }
      if ((arg_6 == 1) && (arg_7 == 1)) {
        color = GetPixel(param_8,x,y);
        uVar6 = SetPixelV(hdc,x,y,color);
      }
      else {
        uVar6 = BitBlt(hdc,iVar4,y_00,cx,cy,param_8,arg_9 + x * arg_6,arg_10 + y * arg_7,0xcc0020);
      }
      uVar5 = uVar5 - 1;
    }
  }
  return uVar6;
}



/*
 * Decompiled function: FUN_00511d60
 * Entry Point: 00511d60
 * Size: 182 bytes
 */


undefined4
FUN_00511d60(HDC hdc,COLORREF arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
            int arg_9,int arg_10)

{
  HDC hdc_00;
  HBITMAP h;
  HBRUSH hbr;
  RECT local_10;
  
  local_10.left = 0;
  local_10.top = 0;
  local_10.right = arg_5;
  local_10.bottom = arg_6;
  hdc_00 = CreateCompatibleDC(hdc);
  h = CreateCompatibleBitmap(hdc,arg_5,arg_6);
  hbr = CreateSolidBrush(arg_2);
  SelectObject(hdc_00,h);
  FillRect(hdc_00,&local_10,hbr);
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


void FUN_00511e20(HDC hdc,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6,int arg_7,int arg_8,
                 int arg_9,HDC param_10)

{
  int y;
  int iVar1;
  int iVar2;
  int iVar3;
  void *_Memory;
  DWORD DVar4;
  int y_00;
  COLORREF color;
  uint uVar5;
  int x;
  int iVar6;
  int cx;
  int cy;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int local_38;
  int local_30;
  int *local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_c;
  
  local_38 = -arg_7 + 1;
  iVar1 = (uint)(arg_6 % arg_8 != 0) + arg_6 / arg_8;
  uVar5 = 0x40000000;
  uVar7 = ((uint)(arg_5 % arg_9 != 0) + arg_5 / arg_9) * iVar1;
  iVar2 = (uint)(arg_4 % arg_6 != 0) + arg_4 / arg_6;
  uVar8 = 0;
  iVar3 = 0;
  do {
    if ((uVar5 & uVar7) != 0) {
      if (uVar8 == 0) {
        uVar8 = uVar5;
      }
      iVar3 = iVar3 + 1;
    }
    uVar5 = (int)uVar5 >> 1;
  } while (uVar5 != 0);
  if (iVar3 != 1) {
    uVar8 = uVar8 * 2;
  }
  _Memory = malloc(((arg_7 + iVar2) * 4 + 0x14) * 5);
  DVar4 = GetTickCount();
  iVar3 = -arg_7 + 2;
  *(int *)((int)_Memory + local_38 * 0x14 + arg_7 * 0x14) = (int)DVar4 % (int)uVar8;
  local_2c = (int *)((int)_Memory + local_38 * 0x14 + arg_7 * 0x14);
  local_2c[1] = 5;
  local_2c[2] = 1;
  local_2c[3] = uVar8;
  local_2c[4] = uVar8;
  if (iVar3 < iVar2) {
    piVar9 = (int *)((int)_Memory + iVar3 * 0x14 + arg_7 * 0x14);
    do {
      *piVar9 = (piVar9[-5] * 5 + 1) % (int)uVar8;
      iVar6 = iVar3 % 0x14;
      iVar3 = iVar3 + 1;
      piVar9[1] = *(int *)(&DAT_00532810 + iVar6 * 4) * 4 + 1;
      piVar9[2] = 1;
      piVar9[3] = uVar8;
      piVar9[4] = uVar8;
      piVar9 = piVar9 + 5;
    } while (iVar3 < iVar2);
  }
  if (local_38 < iVar2) {
    local_18 = arg_6 * local_38;
    do {
      local_1c = arg_7;
      if (local_38 < arg_7 + local_38) {
        local_c = arg_7;
        do {
          local_30 = local_38;
          iVar3 = local_38 + local_1c;
          if (iVar2 <= local_38 + local_1c) {
            iVar3 = iVar2;
          }
          if (local_38 < iVar3) {
            local_20 = local_18;
            piVar9 = local_2c;
            do {
              iVar6 = (piVar9[1] * *piVar9 + piVar9[2]) % piVar9[3];
              *piVar9 = iVar6;
              piVar9[4] = piVar9[4] + -1;
              if (iVar6 < (int)uVar7) {
                y_00 = iVar6 / iVar1;
                iVar6 = iVar6 % iVar1;
                x = iVar6 * arg_8 + arg_2 + local_20;
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
                    color = GetPixel(param_10,iVar6,y_00);
                    SetPixel(hdc,iVar6,y_00,color);
                  }
                  else {
                    BitBlt(hdc,x,y,cx,cy,param_10,x,y,0xcc0020);
                  }
                }
              }
              local_20 = local_20 + arg_6;
              piVar9 = piVar9 + 5;
              local_30 = local_30 + 1;
            } while (local_30 < iVar3);
          }
          local_1c = local_1c + -1;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      if (local_2c[4] < 1) {
        local_2c = local_2c + 5;
        local_18 = local_18 + arg_6;
        local_38 = local_38 + 1;
      }
    } while (local_38 < iVar2);
  }
  free(_Memory);
  return;
}



/*
 * Decompiled function: Mem_AllocOrFree_005121d0
 * Entry Point: 005121d0
 * Size: 6 bytes
 */


undefined4 Mem_AllocOrFree_005121d0(void)

{
  return 0xffffffff;
}



/*
 * Decompiled function: Mem_AllocOrFree_005121e0
 * Entry Point: 005121e0
 * Size: 6 bytes
 */


undefined4 Mem_AllocOrFree_005121e0(void)

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


undefined4 Mem_AllocOrFree_00512210(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_007039d0;
  DAT_007039d0 = 0;
  return uVar1;
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



