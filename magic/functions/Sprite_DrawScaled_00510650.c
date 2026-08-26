/*
 * Decompiled function: Sprite_DrawScaled
 * Entry Point: 00510650
 * Size: 1181 bytes
 */
#include "magic.h"


void Sprite_DrawScaled(int *arg_1,int arg_2,int arg_3,int arg_4,int arg_5,int arg_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int width;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  byte *pbVar14;
  bool bVar15;
  uint local_420;
  int local_414;
  int local_410;
  int local_400 [256];
  
  iVar2 = *arg_1;
  if (((arg_6 != 0) && (arg_2 <= arg_1[3])) && (arg_3 <= arg_1[4])) {
    iVar5 = (&DAT_0070a850)[iVar2];
    iVar11 = (int)*(short *)(arg_6 + 4);
    local_400[0] = (int)*(short *)(arg_6 + 6);
    if (((DAT_00625194 != arg_4) || (DAT_0062518c != arg_5)) ||
       ((iVar11 != DAT_00626198 || (local_400[0] != DAT_00625180)))) {
      DAT_00624168 = (iVar11 << 0x10) / arg_4;
      DAT_0062416c = (local_400[0] << 0x10) / arg_5;
      puVar13 = &DAT_00624178;
      for (iVar8 = 0x400; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar13 = 0xffffffff;
        puVar13 = puVar13 + 1;
      }
      iVar8 = 0;
      DAT_00625184 = 0;
      if (-1 < arg_4 + 2) {
        do {
          iVar4 = DAT_00625184 >> 0x10;
          (&DAT_00625198)[iVar8] = iVar4;
          if ((&DAT_00624178)[iVar4] == -1) {
            (&DAT_00624178)[iVar4] = iVar8;
          }
          iVar8 = iVar8 + 1;
          DAT_00625184 = DAT_00625184 + DAT_00624168;
        } while (iVar8 <= arg_4 + 2);
      }
      if ((arg_4 < iVar11) && (-1 < iVar11)) {
        piVar9 = &DAT_00624178;
        iVar8 = iVar11 + 1;
        do {
          if (*piVar9 == -1) {
            *piVar9 = piVar9[-1];
          }
          piVar9 = piVar9 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      DAT_00625194 = arg_4;
      DAT_0062518c = arg_5;
      DAT_00625180 = local_400[0];
      DAT_00626198 = iVar11;
    }
    if (arg_2 < arg_1[1]) {
      DAT_00625190 = arg_1[1] - arg_2;
    }
    else {
      DAT_00625190 = 0;
    }
    if (arg_1[3] < arg_2 + arg_4) {
      DAT_00624170 = arg_1[3] - arg_2;
    }
    else {
      DAT_00624170 = arg_4;
    }
    iVar11 = (int)*(short *)(arg_6 + 0xc);
    DAT_00625188 = 0;
    if (0 < iVar11) {
      do {
        DAT_00625188 = DAT_00625188 + DAT_0062416c;
        arg_3 = arg_3 + 1;
      } while (DAT_00625188 >> 0x10 < iVar11);
    }
    pbVar10 = (byte *)(arg_6 + 0x10);
    sVar1 = *(short *)(arg_6 + 0xe);
    iVar8 = *(int *)(iVar5 + 0x2c) + *(int *)(iVar5 + 0x20);
    local_414 = 0;
    local_410 = iVar8 * arg_3 + *(int *)(iVar5 + 0x18) + arg_2;
    if (DAT_00625188 >> 0x10 < sVar1 + iVar11) {
      do {
        iVar5 = DAT_00625188 >> 0x10;
        pbVar14 = pbVar10 + 1;
        iVar4 = DAT_0062416c + DAT_00625188 >> 0x10;
        uVar6 = (uint)*pbVar10;
        if (uVar6 != 0xff) {
          local_420 = (uint)*pbVar14;
          pbVar14 = pbVar10 + 2;
          bVar15 = local_420 == 0xfe;
          if (bVar15) {
            pbVar14 = pbVar10 + 3;
            local_420 = (uint)pbVar10[2];
          }
          width = local_414 + arg_3;
          if (arg_1[2] <= width) {
            if (arg_1[4] < width) {
              return;
            }
            iVar12 = (&DAT_00624178)[uVar6];
            if ((int)(&DAT_00624178)[uVar6] <= DAT_00625190) {
              iVar12 = DAT_00625190;
            }
            iVar7 = (&DAT_00624178)[local_420 + uVar6];
            if (DAT_00624170 <= (int)(&DAT_00624178)[local_420 + uVar6]) {
              iVar7 = DAT_00624170;
            }
            if ((int)((&DAT_00625198)[iVar12] - uVar6) < 0) {
              iVar12 = iVar12 + 1;
            }
            if (iVar2 == 0) {
              iVar3 = iVar12;
              if (bVar15) {
                for (; iVar3 < iVar7; iVar3 = iVar3 + 1) {
                  *(byte *)((int)local_400 + iVar3) = pbVar14[(&DAT_00625198)[iVar3] - uVar6];
                }
                Surface_PutLine((undefined4 *)((int)local_400 + iVar12),0,arg_2 + iVar12,width,
                                iVar7 - iVar12);
              }
              else {
                for (; iVar12 < iVar7; iVar12 = iVar12 + 1) {
                  if (pbVar14[(&DAT_00625198)[iVar12] - uVar6] != 0) {
                    Surface_PutPixel(arg_1,arg_2 + iVar12,width,
                                     (uint)pbVar14[(&DAT_00625198)[iVar12] - uVar6]);
                  }
                }
              }
            }
            else {
              for (; iVar12 < iVar7; iVar12 = iVar12 + 1) {
                if (pbVar14[(&DAT_00625198)[iVar12] - uVar6] != 0) {
                  *(byte *)(local_410 + iVar12) = pbVar14[(&DAT_00625198)[iVar12] - uVar6];
                }
              }
            }
          }
          pbVar14 = pbVar14 + local_420;
        }
        if (((iVar4 != iVar5) && (iVar4 = iVar4 - iVar5, pbVar10 = pbVar14, iVar4 != 1)) &&
           (iVar5 = iVar4 + -2, iVar4 != 1)) {
          do {
            pbVar10 = pbVar14 + 1;
            if (*pbVar14 != 0xff) {
              uVar6 = (uint)*pbVar10;
              pbVar10 = pbVar14 + 2;
              if (uVar6 == 0xfe) {
                uVar6 = (uint)*pbVar10;
                pbVar10 = pbVar14 + 3;
              }
              pbVar10 = pbVar10 + uVar6;
            }
            bVar15 = iVar5 != 0;
            pbVar14 = pbVar10;
            iVar5 = iVar5 + -1;
          } while (bVar15);
        }
        local_414 = local_414 + 1;
        DAT_00625188 = DAT_00625188 + DAT_0062416c;
        local_410 = local_410 + iVar8;
      } while (DAT_00625188 >> 0x10 < sVar1 + iVar11);
    }
  }
  return;
}


