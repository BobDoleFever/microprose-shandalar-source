/*
 * Decompiled function: thunk_FUN_10013760
 * Entry Point: 100014e7
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10013760(WPARAM arg_1,int y,int width,int height)

{
  int iStack_158;
  char acStack_154 [264];
  int iStack_4c;
  HBITMAP pHStack_48;
  HDC pHStack_44;
  int iStack_40;
  int iStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  BITMAPINFO BStack_30;
  
  iStack_40 = 1;
  if (arg_1 == 0xffffffff) {
    iStack_40 = 0;
  }
  else {
    iStack_4c = thunk_FUN_10013a4c(arg_1,y);
    if (iStack_4c != 0) {
      if ((*(int *)(iStack_4c + 8) == width) && (*(int *)(iStack_4c + 0xc) == height)) {
        return 1;
      }
      thunk_FUN_10013cd0(arg_1,y);
    }
    if ((*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) || (y == 0)) {
      sprintf(acStack_154,s__s__04d_WVL_10042f84,&DAT_10158890,arg_1);
    }
    else {
      sprintf(acStack_154,s__s__04d_c_WVL_10042f74,&DAT_10158890,arg_1,(int)(char)((char)y + '`'));
    }
    iStack_3c = thunk_FUN_10001f20(1,acStack_154,0);
    if (iStack_3c == 0) {
      iStack_40 = 0;
    }
    else {
      pHStack_44 = GetDC((HWND)0x0);
      thunk_FUN_10031425(pHStack_44);
      thunk_FUN_10023560((int32_t *)&BStack_30,width,height);
      pHStack_48 = CreateDIBSection(pHStack_44,&BStack_30,0,&pvStack_38,(HANDLE)0x0,0);
      if (pHStack_48 == (HBITMAP)0x0) {
        iStack_40 = 0;
      }
      else {
        pvStack_34 = (void *)thunk_FUN_100037d0(0,iStack_3c,width,height);
        if (pvStack_34 == (void *)0x0) {
          iStack_40 = 0;
          DeleteObject(pHStack_48);
        }
        else {
          if ((-width & 3U) == 0) {
            iStack_158 = 0;
          }
          else {
            iStack_158 = 4 - (-width & 3U);
          }
          memcpy(pvStack_38,pvStack_34,(width * 3 + iStack_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,pHStack_44);
      thunk_FUN_10002340(iStack_3c);
    }
    if (iStack_40 != 0) {
      if (0x13 < DAT_10158728) {
        thunk_FUN_10013cd0(DAT_101cf600,DAT_101cf604);
      }
      *(HBITMAP *)(&DAT_101cf5f0 + DAT_10158728 * 0x18) = pHStack_48;
      *(void **)(&DAT_101cf5f4 + DAT_10158728 * 0x18) = pvStack_38;
      *(int *)(&DAT_101cf5f8 + DAT_10158728 * 0x18) = width;
      *(int *)(&DAT_101cf5fc + DAT_10158728 * 0x18) = height;
      (&DAT_101cf600)[DAT_10158728 * 6] = arg_1;
      (&DAT_101cf604)[DAT_10158728 * 6] = y;
      DAT_10158728 = DAT_10158728 + 1;
      PostMessageA(DAT_10176868,0x434,arg_1,y);
    }
  }
  return iStack_40;
}


