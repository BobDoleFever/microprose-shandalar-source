/*
 * Decompiled function: FUN_10028f53
 * Entry Point: 10028f53
 * Size: 685 bytes
 */
#include "deckdll.h"


int FUN_10028f53(WPARAM arg_1,int y,int width,int height)

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
    local_8 = thunk_FUN_10029205(arg_1,y);
    if (local_8 != 0) {
      if ((*(int *)(local_8 + 8) == width) && (*(int *)(local_8 + 0xc) == height)) {
        return 1;
      }
      thunk_FUN_10029435(arg_1,y);
    }
    if (y == 0) {
      sprintf(local_154,s__s__04d_WVL_10046074,&DAT_10158890,arg_1);
    }
    else {
      sprintf(local_154,s__s__04d_c_WVL_10046064,&DAT_10158890,arg_1,(int)(char)((char)y + '`'));
    }
    local_40 = thunk_FUN_10001f20(0,local_154,0);
    if (local_40 == 0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      thunk_FUN_10031425(local_48);
      thunk_FUN_10023560((int32_t *)&local_34,width,height);
      local_4c = CreateDIBSection(local_48,&local_34,0,&local_3c,(HANDLE)0x0,0);
      if (local_4c == (HBITMAP)0x0) {
        local_44 = 0;
      }
      else {
        local_38 = (void *)thunk_FUN_100037d0(0,local_40,width,height);
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
      thunk_FUN_10002340(local_40);
    }
    if (local_44 != 0) {
      *(HBITMAP *)(&DAT_10175560 + DAT_101cdeb0 * 0x18) = local_4c;
      *(void **)(&DAT_10175564 + DAT_101cdeb0 * 0x18) = local_3c;
      *(int *)(&DAT_10175568 + DAT_101cdeb0 * 0x18) = width;
      *(int *)(&DAT_1017556c + DAT_101cdeb0 * 0x18) = height;
      *(WPARAM *)(&DAT_10175570 + DAT_101cdeb0 * 0x18) = arg_1;
      *(int *)(&DAT_10175574 + DAT_101cdeb0 * 0x18) = y;
      DAT_101cdeb0 = DAT_101cdeb0 + 1;
      PostMessageA(DAT_10176868,0x433,arg_1,y);
    }
  }
  return local_44;
}


