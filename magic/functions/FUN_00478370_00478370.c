/*
 * Decompiled function: FUN_00478370
 * Entry Point: 00478370
 * Size: 743 bytes
 */
#include "magic.h"


int FUN_00478370(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  int local_4c;
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (arg_1 == 0xffffffff) {
    local_40 = 0;
  }
  else {
    local_4c = FUN_0047865c(arg_1,y);
    if (local_4c != 0) {
      if ((*(int *)(local_4c + 8) == width) && (*(int *)(local_4c + 0xc) == height)) {
        return 1;
      }
      FUN_004788e0(arg_1,y);
    }
    if ((*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) || (y == 0)) {
      sprintf(local_154,s__s__04d_WVL_00525dc8,&DAT_006808d0,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_00525db8,&DAT_006808d0,arg_1,(int)(char)((char)y + '`'));
    }
    local_3c = Catalog_LoadWaveletCardArt(1,local_154,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      FUN_004f3955(local_44);
      FUN_005017f0((undefined4 *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_004f27c0(0,local_3c,width,height);
        if (local_34 == (void *)0x0) {
          local_40 = 0;
          DeleteObject(local_48);
        }
        else {
          if ((-width & 3U) == 0) {
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      Catalog_ReleaseWaveletLock(local_3c);
    }
    if (local_40 != 0) {
      if (0x13 < DAT_00680778) {
        FUN_004788e0(DAT_006fefc0,DAT_006fefc4);
      }
      *(HBITMAP *)(&DAT_006fefb0 + DAT_00680778 * 0x18) = local_48;
      *(void **)(&DAT_006fefb4 + DAT_00680778 * 0x18) = local_38;
      *(int *)(&DAT_006fefb8 + DAT_00680778 * 0x18) = width;
      *(int *)(&DAT_006fefbc + DAT_00680778 * 0x18) = height;
      (&DAT_006fefc0)[DAT_00680778 * 6] = arg_1;
      (&DAT_006fefc4)[DAT_00680778 * 6] = y;
      DAT_00680778 = DAT_00680778 + 1;
      PostMessageA(g_MainAppHwnd,0x434,arg_1,y);
    }
  }
  return local_40;
}


