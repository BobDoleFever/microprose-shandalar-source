/*
 * Decompiled function: Sprite_DrawClipped
 * Entry Point: 00510360
 * Size: 752 bytes
 */
#include "magic.h"


void Sprite_DrawClipped(int *x,int y,int width,int height)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint arg_5;
  byte *pbVar7;
  byte *arg_1;
  int arg_3;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  int local_18;
  int local_14;
  int local_8;
  
  iVar1 = *x;
  if (((height != 0) && (iVar3 = x[3], y <= iVar3)) && (iVar10 = x[4], width <= iVar10)) {
    iVar8 = (&DAT_0070a850)[iVar1];
    if (((x[1] <= y) && (*(short *)(height + 4) + y <= iVar3)) &&
       ((x[2] <= width && (*(short *)(height + 6) + width <= iVar10)))) {
      Sprite_DrawDirect(x,y,width,height);
      return;
    }
    iVar9 = width + *(short *)(height + 0xc);
    iVar6 = (int)*(short *)(height + 0xe);
    if (((y <= iVar3) && (x[1] <= *(short *)(height + 4) + y)) &&
       ((x[2] <= iVar6 + iVar9 && (iVar9 <= iVar10)))) {
      iVar3 = *(int *)(iVar8 + 0x2c) + *(int *)(iVar8 + 0x20);
      local_8 = 0;
      local_18 = iVar3 * iVar9 + *(int *)(iVar8 + 0x18) + y;
      arg_1 = (byte *)(height + 0x10);
      if (0 < iVar6) {
        do {
          bVar2 = false;
          iVar10 = iVar9 + local_8;
          if (x[4] < iVar10) {
            return;
          }
          if (iVar10 < x[2]) {
            if (*arg_1 == 0xff) {
              pbVar7 = arg_1 + 1;
            }
            else if (arg_1[1] == 0xfe) {
              local_14 = arg_1[2] + 3;
LAB_00510623:
              pbVar7 = arg_1 + local_14;
            }
            else {
              pbVar7 = arg_1 + arg_1[1] + 2;
            }
          }
          else {
            uVar5 = (uint)*arg_1;
            pbVar7 = arg_1 + 1;
            if (uVar5 != 0xff) {
              arg_5 = (uint)*pbVar7;
              pbVar7 = arg_1 + 2;
              if (arg_5 == 0xfe) {
                bVar2 = x[1] < (int)(y + uVar5);
                arg_5 = (uint)arg_1[2];
                pbVar7 = arg_1 + 3;
              }
              arg_1 = pbVar7;
              arg_3 = y + uVar5;
              iVar8 = x[3];
              if (arg_3 <= iVar8) {
                if (iVar8 < (int)(y + arg_5 + uVar5)) {
                  uVar4 = (iVar8 - uVar5) - y;
                  local_14 = arg_5 - uVar4;
                  arg_5 = uVar4;
                }
                else {
                  local_14 = 0;
                }
                if (bVar2) {
                  if (0 < (int)arg_5) {
                    if (iVar1 == 0) {
                      Surface_PutLine((undefined4 *)arg_1,0,arg_3,iVar10,arg_5);
                    }
                    else {
                      pbVar7 = arg_1;
                      pbVar11 = (byte *)(local_18 + uVar5);
                      for (uVar4 = arg_5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
                        *(undefined4 *)pbVar11 = *(undefined4 *)pbVar7;
                        pbVar7 = pbVar7 + 4;
                        pbVar11 = pbVar11 + 4;
                      }
                      for (uVar5 = arg_5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                        *pbVar11 = *pbVar7;
                        pbVar7 = pbVar7 + 1;
                        pbVar11 = pbVar11 + 1;
                      }
                    }
                  }
                  local_14 = local_14 + arg_5;
                }
                else {
                  if (arg_3 < x[1]) {
                    iVar8 = 0;
                    if (0 < (int)arg_5) {
                      do {
                        if (x[1] <= (int)(y + iVar8 + uVar5)) break;
                        iVar8 = iVar8 + 1;
                        arg_1 = arg_1 + 1;
                      } while (iVar8 < (int)arg_5);
                    }
                  }
                  else {
                    iVar8 = 0;
                  }
                  if (iVar1 == 0) {
                    for (; iVar8 < (int)arg_5; iVar8 = iVar8 + 1) {
                      if (*arg_1 != 0) {
                        Surface_PutPixel(x,y + iVar8 + uVar5,iVar10,(uint)*arg_1);
                      }
                      arg_1 = arg_1 + 1;
                    }
                  }
                  else {
                    for (; iVar8 < (int)arg_5; iVar8 = iVar8 + 1) {
                      if (*arg_1 != 0) {
                        *(byte *)(local_18 + iVar8 + uVar5) = *arg_1;
                      }
                      arg_1 = arg_1 + 1;
                    }
                  }
                }
                goto LAB_00510623;
              }
              pbVar7 = arg_1 + arg_5;
            }
          }
          local_8 = local_8 + 1;
          local_18 = local_18 + iVar3;
          arg_1 = pbVar7;
        } while (local_8 < iVar6);
      }
    }
  }
  return;
}


