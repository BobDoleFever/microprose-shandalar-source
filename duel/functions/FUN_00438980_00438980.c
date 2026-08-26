/*
 * Decompiled function: FUN_00438980
 * Entry Point: 00438980
 * Size: 619 bytes
 */
#include "duel.h"


int FUN_00438980(WPARAM arg_1,int arg_2,int width,int height)

{
  int local_154;
  char local_150 [264];
  HBITMAP local_48;
  HDC local_44;
  int local_40;
  int *local_3c;
  void *local_38;
  void *local_34;
  BITMAPINFO local_30;
  
  local_40 = 1;
  if (arg_1 == 0xffffffff) {
    local_40 = 0;
  }
  else if (*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_0060d5b0 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_0060d5b8 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_0060d5bc + arg_1 * 0x10) == height)) {
        return 1;
      }
      FUN_00438e72(arg_1);
    }
    _sprintf(local_150,s__s__04d_WVL_004f7198,&DAT_005f7800,arg_1);
    local_3c = (int *)Glue_Subsystem_004f15c0(0,local_150,0);
    if (local_3c == (int *)0x0) {
      local_40 = 0;
    }
    else {
      local_44 = GetDC((HWND)0x0);
      FUN_004707a4(local_44);
      FUN_00491750((undefined4 *)&local_30,width,height);
      local_48 = CreateDIBSection(local_44,&local_30,0,&local_38,(HANDLE)0x0,0);
      if (local_48 == (HBITMAP)0x0) {
        local_40 = 0;
      }
      else {
        local_34 = (void *)FUN_0047fc77((uint *)0x0,local_3c,width,height);
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
          FID_conflict__memcpy(local_38,local_34,(width * 3 + local_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      FUN_0047e7a5(local_3c);
    }
    if (local_40 != 0) {
      *(HBITMAP *)(&DAT_0060d5b0 + arg_1 * 0x10) = local_48;
      *(void **)(&DAT_0060d5b4 + arg_1 * 0x10) = local_38;
      *(int *)(&DAT_0060d5b8 + arg_1 * 0x10) = width;
      *(int *)(&DAT_0060d5bc + arg_1 * 0x10) = height;
      PostMessageA(DAT_00618990,0x433,arg_1,0);
    }
  }
  else {
    local_40 = FUN_00438ec2(arg_1,arg_2,width,height);
  }
  return local_40;
}


