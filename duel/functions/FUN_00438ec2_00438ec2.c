/*
 * Decompiled function: FUN_00438ec2
 * Entry Point: 00438ec2
 * Size: 683 bytes
 */
#include "duel.h"


int FUN_00438ec2(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  HBITMAP local_4c;
  HDC local_48;
  int local_44;
  int *local_40;
  void *local_3c;
  void *local_38;
  BITMAPINFO local_34;
  int local_8;
  
  local_44 = 1;
  if (arg_1 == 0xffffffff) {
    local_44 = 0;
  }
  else {
    local_8 = FUN_00439172(arg_1,y);
    if (local_8 != 0) {
      if ((*(int *)(local_8 + 8) == width) && (*(int *)(local_8 + 0xc) == height)) {
        return 1;
      }
      FUN_004393a2(arg_1,y);
    }
    if (y == 0) {
      _sprintf(local_154,s__s__04d_WVL_004f71b4,&DAT_005f7800,arg_1);
    }
    else {
      _sprintf(local_154,s__s__04d_c_WVL_004f71a4,&DAT_005f7800,arg_1,(int)(char)((char)y + '`'));
    }
    local_40 = (int *)Glue_Subsystem_004f15c0(0,local_154,0);
    if (local_40 == (int *)0x0) {
      local_44 = 0;
    }
    else {
      local_48 = GetDC((HWND)0x0);
      FUN_004707a4(local_48);
      FUN_00491750((undefined4 *)&local_34,width,height);
      local_4c = CreateDIBSection(local_48,&local_34,0,&local_3c,(HANDLE)0x0,0);
      if (local_4c == (HBITMAP)0x0) {
        local_44 = 0;
      }
      else {
        local_38 = (void *)FUN_0047fc77((uint *)0x0,local_40,width,height);
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
          FID_conflict__memcpy(local_3c,local_38,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_48);
      FUN_0047e7a5(local_40);
    }
    if (local_44 != 0) {
      *(HBITMAP *)(&DAT_00616a10 + DAT_00663df8 * 0x18) = local_4c;
      *(void **)(&DAT_00616a14 + DAT_00663df8 * 0x18) = local_3c;
      *(int *)(&DAT_00616a18 + DAT_00663df8 * 0x18) = width;
      *(int *)(&DAT_00616a1c + DAT_00663df8 * 0x18) = height;
      *(WPARAM *)(&DAT_00616a20 + DAT_00663df8 * 0x18) = arg_1;
      *(int *)(&DAT_00616a24 + DAT_00663df8 * 0x18) = y;
      DAT_00663df8 = DAT_00663df8 + 1;
      PostMessageA(DAT_00618990,0x433,arg_1,y);
    }
  }
  return local_44;
}


