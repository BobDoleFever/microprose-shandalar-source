/*
 * Decompiled function: FUN_10028a10
 * Entry Point: 10028a10
 * Size: 620 bytes
 */
#include "deckdll.h"


int FUN_10028a10(WPARAM arg_1,int arg_2,int width,int height)

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
  else if (*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_10162910 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_10162918 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_1016291c + arg_1 * 0x10) == height)) {
        return 1;
      }
      thunk_FUN_10028f03(arg_1);
    }
    sprintf(local_150,s__s__04d_WVL_10046058,&DAT_10158890,arg_1);
    local_3c = thunk_FUN_10001f20(0,local_150,0);
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
            local_154 = 0;
          }
          else {
            local_154 = 4 - (-width & 3U);
          }
          memcpy(local_38,local_34,(width * 3 + local_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      thunk_FUN_10002340(local_3c);
    }
    if (local_40 != 0) {
      *(HBITMAP *)(&DAT_10162910 + arg_1 * 0x10) = local_48;
      *(void **)(&DAT_10162914 + arg_1 * 0x10) = local_38;
      *(int *)(&DAT_10162918 + arg_1 * 0x10) = width;
      *(int *)(&DAT_1016291c + arg_1 * 0x10) = height;
      PostMessageA(DAT_10176868,0x433,arg_1,0);
    }
  }
  else {
    local_40 = thunk_FUN_10028f53(arg_1,arg_2,width,height);
  }
  return local_40;
}


