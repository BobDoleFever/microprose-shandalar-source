/*
 * Decompiled function: FUN_00511e20
 * Entry Point: 00511e20
 * Size: 846 bytes
 */
#include "magic.h"


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


