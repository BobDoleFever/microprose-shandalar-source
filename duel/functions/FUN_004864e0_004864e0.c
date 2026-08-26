/*
 * Decompiled function: FUN_004864e0
 * Entry Point: 004864e0
 * Size: 741 bytes
 */
#include "duel.h"


int FUN_004864e0(WPARAM arg_1,int y,int width,int height)

{
  int local_158;
  char local_154 [264];
  int local_4c;
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
  else {
    local_4c = FUN_004867ca(arg_1,y);
    if (local_4c != 0) {
      if ((*(int *)(local_4c + 8) == width) && (*(int *)(local_4c + 0xc) == height)) {
        return 1;
      }
      FUN_00486a4e(arg_1,y);
    }
    if ((*(int *)(&DAT_00618b04 + arg_1 * 0x98) < 2) || (y == 0)) {
      _sprintf(local_154,s__s__04d_WVL_004faabc,&DAT_005f7800,arg_1);
    }
    else {
      _sprintf(local_154,s__s__04d_c_WVL_004faaac,&DAT_005f7800,arg_1,(int)(char)((char)y + '`'));
    }
    local_3c = (int *)Glue_Subsystem_004f15c0(1,local_154,0);
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
            local_158 = 0;
          }
          else {
            local_158 = 4 - (-width & 3U);
          }
          FID_conflict__memcpy(local_38,local_34,(width * 3 + local_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,local_44);
      FUN_0047e7a5(local_3c);
    }
    if (local_40 != 0) {
      if (0x13 < DAT_005f76d4) {
        FUN_00486a4e(DAT_00664880,DAT_00664884);
      }
      *(HBITMAP *)(&DAT_00664870 + DAT_005f76d4 * 0x18) = local_48;
      *(void **)(&DAT_00664874 + DAT_005f76d4 * 0x18) = local_38;
      *(int *)(&DAT_00664878 + DAT_005f76d4 * 0x18) = width;
      *(int *)(&DAT_0066487c + DAT_005f76d4 * 0x18) = height;
      (&DAT_00664880)[DAT_005f76d4 * 6] = arg_1;
      (&DAT_00664884)[DAT_005f76d4 * 6] = y;
      DAT_005f76d4 = DAT_005f76d4 + 1;
      PostMessageA(DAT_00618990,0x434,arg_1,y);
    }
  }
  return local_40;
}


