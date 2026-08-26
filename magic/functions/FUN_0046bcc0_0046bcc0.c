/*
 * Decompiled function: FUN_0046bcc0
 * Entry Point: 0046bcc0
 * Size: 620 bytes
 */
#include "magic.h"


int FUN_0046bcc0(WPARAM arg_1,int arg_2,int width,int height)

{
  int local_154;
  char local_150 [264];
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
  else if (*(int *)(&DAT_006b30b4 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_00696a20 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_00696a28 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_00696a2c + arg_1 * 0x10) == height)) {
        return 1;
      }
      FUN_0046c1b3(arg_1);
    }
    sprintf(local_150,s__s__04d_WVL_00525044,&DAT_006808d0,arg_1);
    local_3c = Catalog_LoadWaveletCardArt(0,local_150,0);
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
            local_154 = 0;
          }
          else {
            local_154 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      Catalog_ReleaseWaveletLock(local_3c);
    }
    if (local_40 != 0) {
      *(HBITMAP *)(&DAT_00696a20 + arg_1 * 0x10) = local_48;
      *(void **)(&DAT_00696a24 + arg_1 * 0x10) = local_38;
      *(int *)(&DAT_00696a28 + arg_1 * 0x10) = width;
      *(int *)(&DAT_00696a2c + arg_1 * 0x10) = height;
      PostMessageA(g_MainAppHwnd,0x433,arg_1,0);
    }
  }
  else {
    local_40 = FUN_0046c203(arg_1,arg_2,width,height);
  }
  return local_40;
}


