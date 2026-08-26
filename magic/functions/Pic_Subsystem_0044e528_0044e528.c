/*
 * Decompiled function: Pic_Subsystem_0044e528
 * Entry Point: 0044e528
 * Size: 565 bytes
 */
#include "magic.h"


void Pic_Subsystem_0044e528(void)

{
  bool bVar1;
  int iVar2;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  Surface_PutPixel((int *)g_DisplaySurfaceWork,0xa8,0x58,0xff);
  do {
    bVar1 = false;
    for (local_10 = 4; local_10 < 0x40; local_10 = local_10 + 4) {
      for (local_14 = 4; local_14 < 0x40; local_14 = local_14 + 4) {
        iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14 + 0x40);
        if (iVar2 != 0) {
          Surface_FillRect((int *)g_DisplaySurfaceWork,0x40,0,0x40,0x40,0);
          Pic_Subsystem_0044e75d(local_10,local_14,8);
          Surface_PutPixel((int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14 + 0x40,0);
          for (local_18 = 0; local_18 < 0x40; local_18 = local_18 + 1) {
            for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
              iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_18 + 0x40,local_8);
              if ((iVar2 != 0) &&
                 (iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8),
                 iVar2 == 0)) {
                bVar1 = true;
                Surface_PutPixel((int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8,0xff);
                Surface_PutPixel((int *)g_DisplaySurfaceWork,local_18 + 0x80,local_8 + 0x40,0xff);
              }
            }
          }
        }
      }
    }
  } while (bVar1);
  for (local_10 = 0; local_10 < 0x40; local_10 = local_10 + 1) {
    for (local_14 = 0; local_14 < 0x40; local_14 = local_14 + 1) {
      iVar2 = Surface_GetPixel(*(int *)g_DisplaySurfaceWork,local_10 + 0x80,local_14);
      if (iVar2 == 0) {
        Surface_PutPixel((int *)g_DisplaySurfaceWork,local_10,local_14,0);
      }
    }
  }
  return;
}


