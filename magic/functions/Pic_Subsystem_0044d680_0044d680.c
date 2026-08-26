/*
 * Decompiled function: Pic_Subsystem_0044d680
 * Entry Point: 0044d680
 * Size: 869 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044d680(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  
  do {
    Pic_Subsystem_0044e9ac();
    Surface_FillRect((int *)g_DisplaySurfaceWork,0,0,0x140,200,0);
    local_28 = 0;
    for (local_14 = 0; local_14 < 0x40; local_14 = local_14 + 1) {
      for (local_1c = 0; local_1c < 0x40; local_1c = local_1c + 1) {
        if ((((local_14 < 2) || (local_1c < 2)) || (0x3d < local_14)) || (0x3d < local_1c)) {
          Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,0);
        }
        else {
          iVar2 = (local_1c + local_14) * 3 + -0x20;
          iVar3 = (local_1c - local_14) * 3 + 100;
          if (((iVar2 < 4) || (iVar3 < 4)) || ((0x13b < iVar2 || (0xc3 < iVar3)))) {
            Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,0);
          }
          else {
            iVar2 = Pic_Subsystem_0044e864(local_14,local_1c);
            switch((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3) {
            case 0:
            case 1:
              local_10 = 0;
              break;
            case 2:
              local_10 = 1;
              if (0x15 < iVar2) {
                local_10 = 8;
              }
              break;
            case 3:
              local_10 = 3;
              break;
            case 4:
              local_10 = 6;
              if (iVar2 < 0x22) {
                local_10 = 0xd;
              }
              break;
            case 5:
              if (0x2a < iVar2) goto switchD_0044d8a6_caseD_6;
              local_10 = 10;
              break;
            case 6:
switchD_0044d8a6_caseD_6:
              local_10 = 2;
              break;
            case 7:
              if (iVar2 < 0x3c) {
                local_10 = 0xf;
              }
              else {
                local_10 = 5;
              }
              break;
            case 8:
            case 9:
            case 10:
            case 0xb:
              local_10 = 5;
            }
            Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,local_10);
            if (local_10 != 0) {
              local_28 = local_28 + 1;
            }
          }
        }
      }
    }
    if (0x6d5 < local_28) {
      for (local_14 = 1; local_14 < 0x3f; local_14 = local_14 + 1) {
        for (local_1c = 1; local_1c < 0x3f; local_1c = local_1c + 1) {
          local_10 = FUN_0040c761(local_14,local_1c);
          if (local_10 == 0) {
            bVar1 = false;
            for (local_18 = 1; local_18 < 9; local_18 = local_18 + 2) {
              iVar2 = FUN_0040c761(*(int *)(&DAT_00522378 + local_18 * 4) + local_14,
                                   *(int *)(&DAT_005223e0 + local_18 * 4) + local_1c);
              if (iVar2 == 0) {
                bVar1 = true;
                break;
              }
            }
            if (!bVar1) {
              Surface_PutPixel((int *)g_DisplaySurfaceWork,local_14,local_1c,6);
            }
          }
        }
      }
      Pic_Subsystem_0044e528();
      iVar2 = Pic_Subsystem_0044da25();
      if (iVar2 != 0) {
        Pic_Subsystem_0044e17e();
        return;
      }
    }
  } while( true );
}


