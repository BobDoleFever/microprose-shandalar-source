/*
 * Decompiled function: FUN_0046c203
 * Entry Point: 0046c203
 * Size: 685 bytes
 */
#include "magic.h"


int FUN_0046c203(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  HBITMAP local_4c;
  HDC local_48;
  int local_44;
  int local_40;
  void *local_3c;
  void *local_38;
  BITMAPINFO local_34;
  int local_8;
  
  local_44 = 1;
  if (arg_1 == 0xffffffff) {
    local_44 = 0;
  }
  else {
    local_8 = FUN_0046c4b5(arg_1,y);
    if (local_8 != 0) {
      if ((*(int *)(local_8 + 8) == width) && (*(int *)(local_8 + 0xc) == height)) {
        return 1;
      }
      FUN_0046c6e5(arg_1,y);
    }
    if (y == 0) {
      sprintf(local_154,s__s__04d_WVL_00525060,&DAT_006808d0,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525050,&DAT_006808d0,arg_1,(int)(char)((char)y + '`'));
    }
    local_40 = Catalog_LoadWaveletCardArt(0,local_154,0);
    if (local_40 == 0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      FUN_004f3955(local_48);
      FUN_005017f0((undefined4 *)&local_34,width,height);
      local_4c = CreateDIBSection(local_48,&local_34,0,&local_3c,(HANDLE)0x0,0);
      if (local_4c == (HBITMAP)0x0) {
        local_44 = 0;
      }
      else {
        local_38 = (void *)FUN_004f27c0(0,local_40,width,height);
        if (local_38 == (void *)0x0) {
          local_44 = 0;
          DeleteObject(local_4c);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          memcpy(local_3c,local_38,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_48);
      Catalog_ReleaseWaveletLock(local_40);
    }
    if (local_44 != 0) {
      *(HBITMAP *)(&DAT_006a3f80 + DAT_006fe404 * 0x18) = local_4c;
      *(void **)(&DAT_006a3f84 + DAT_006fe404 * 0x18) = local_3c;
      *(int *)(&DAT_006a3f88 + DAT_006fe404 * 0x18) = width;
      *(int *)(&DAT_006a3f8c + DAT_006fe404 * 0x18) = height;
      *(WPARAM *)(&DAT_006a3f90 + DAT_006fe404 * 0x18) = arg_1;
      *(int *)(&DAT_006a3f94 + DAT_006fe404 * 0x18) = y;
      DAT_006fe404 = DAT_006fe404 + 1;
      PostMessageA(g_MainAppHwnd,0x433,arg_1,y);
    }
  }
  return local_44;
}


