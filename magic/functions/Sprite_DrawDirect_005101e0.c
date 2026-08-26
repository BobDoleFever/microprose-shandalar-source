/*
 * Decompiled function: Sprite_DrawDirect
 * Entry Point: 005101e0
 * Size: 384 bytes
 */
#include "magic.h"


void Sprite_DrawDirect(int *x,int y,int width,int height)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *arg_1;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  int local_10;
  int local_c;
  
  iVar2 = *x;
  if (height != 0) {
    iVar10 = (&DAT_0070a850)[iVar2];
    sVar1 = *(short *)(height + 0xe);
    iVar7 = width + *(short *)(height + 0xc);
    iVar3 = *(int *)(iVar10 + 0x2c) + *(int *)(iVar10 + 0x20);
    local_c = 0;
    local_10 = y + iVar3 * iVar7 + *(int *)(iVar10 + 0x18);
    pbVar8 = (byte *)(height + 0x10);
    if (0 < sVar1) {
      do {
        uVar4 = (uint)*pbVar8;
        arg_1 = pbVar8 + 1;
        if (uVar4 != 0xff) {
          uVar6 = (uint)*arg_1;
          arg_1 = pbVar8 + 2;
          bVar12 = uVar6 != 0xfe;
          if (!bVar12) {
            uVar6 = (uint)*arg_1;
            arg_1 = pbVar8 + 3;
          }
          iVar10 = iVar7 + local_c;
          if (iVar10 < 0) {
            arg_1 = arg_1 + uVar6;
          }
          else if (bVar12) {
            if (iVar2 == 0) {
              iVar9 = 0;
              if (uVar6 != 0) {
                do {
                  if (*arg_1 != 0) {
                    Surface_PutPixel(x,y + uVar4 + iVar9,iVar10,(uint)*arg_1);
                  }
                  iVar9 = iVar9 + 1;
                  arg_1 = arg_1 + 1;
                } while (iVar9 < (int)uVar6);
              }
            }
            else {
              iVar10 = 0;
              if (uVar6 != 0) {
                do {
                  if (*arg_1 != 0) {
                    *(byte *)(uVar4 + iVar10 + local_10) = *arg_1;
                  }
                  iVar10 = iVar10 + 1;
                  arg_1 = arg_1 + 1;
                } while (iVar10 < (int)uVar6);
              }
            }
          }
          else if (iVar2 == 0) {
            Surface_PutLine((undefined4 *)arg_1,0,y + uVar4,iVar10,uVar6);
            arg_1 = arg_1 + uVar6;
          }
          else {
            pbVar8 = arg_1;
            pbVar11 = (byte *)(local_10 + uVar4);
            for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *(undefined4 *)pbVar11 = *(undefined4 *)pbVar8;
              pbVar8 = pbVar8 + 4;
              pbVar11 = pbVar11 + 4;
            }
            arg_1 = arg_1 + uVar6;
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pbVar11 = *pbVar8;
              pbVar8 = pbVar8 + 1;
              pbVar11 = pbVar11 + 1;
            }
          }
        }
        local_c = local_c + 1;
        local_10 = local_10 + iVar3;
        pbVar8 = arg_1;
      } while (local_c < sVar1);
    }
  }
  return;
}


