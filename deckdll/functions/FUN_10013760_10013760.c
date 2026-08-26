/*
 * Decompiled function: FUN_10013760
 * Entry Point: 10013760
 * Size: 743 bytes
 */
#include "deckdll.h"


int FUN_10013760(WPARAM arg_1,int y,int width,int height)

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
    local_4c = thunk_FUN_10013a4c(arg_1,y);
    if (local_4c != 0) {
      if ((*(int *)(local_4c + 8) == width) && (*(int *)(local_4c + 0xc) == height)) {
        return 1;
      }
      thunk_FUN_10013cd0(arg_1,y);
    }
    if ((*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) || (y == 0)) {
      sprintf(local_154,s__s__04d_WVL_10042f84,&DAT_10158890,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_10042f74,&DAT_10158890,arg_1,(int)(char)((char)y + '`'));
    }
    local_3c = thunk_FUN_10001f20(1,local_154,0);
    if (local_3c == 0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      thunk_FUN_10031425(local_44);
      thunk_FUN_10023560((int32_t *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)thunk_FUN_100037d0(0,local_3c,width,height);
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
      thunk_FUN_10002340(local_3c);
    }
    if (local_40 != 0) {
      if (0x13 < DAT_10158728) {
        thunk_FUN_10013cd0(DAT_101cf600,DAT_101cf604);
      }
      *(HBITMAP *)(&DAT_101cf5f0 + DAT_10158728 * 0x18) = local_48;
      *(void **)(&DAT_101cf5f4 + DAT_10158728 * 0x18) = local_38;
      *(int *)(&DAT_101cf5f8 + DAT_10158728 * 0x18) = width;
      *(int *)(&DAT_101cf5fc + DAT_10158728 * 0x18) = height;
      (&DAT_101cf600)[DAT_10158728 * 6] = arg_1;
      (&DAT_101cf604)[DAT_10158728 * 6] = y;
      DAT_10158728 = DAT_10158728 + 1;
      PostMessageA(DAT_10176868,0x434,arg_1,y);
    }
  }
  return local_40;
}


