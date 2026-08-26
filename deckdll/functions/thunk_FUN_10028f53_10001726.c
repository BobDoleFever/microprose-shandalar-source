/*
 * Decompiled function: thunk_FUN_10028f53
 * Entry Point: 10001726
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10028f53(WPARAM arg_1,int y,int width,int height)

{
  int iStack_158;
  char acStack_154 [264];
  HBITMAP pHStack_4c;
  HDC pHStack_48;
  int iStack_44;
  int iStack_40;
  void *pvStack_3c;
  void *pvStack_38;
  BITMAPINFO BStack_34;
  int iStack_8;
  
  iStack_44 = 1;
  if (arg_1 == 0xffffffff) {
    iStack_44 = 0;
  }
  else {
    iStack_8 = thunk_FUN_10029205(arg_1,y);
    if (iStack_8 != 0) {
      if ((*(int *)(iStack_8 + 8) == width) && (*(int *)(iStack_8 + 0xc) == height)) {
        return 1;
      }
      thunk_FUN_10029435(arg_1,y);
    }
    if (y == 0) {
      sprintf(acStack_154,s__s__04d_WVL_10046074,&DAT_10158890,arg_1);
    }
    else {
      sprintf(acStack_154,s__s__04d_c_WVL_10046064,&DAT_10158890,arg_1,(int)(char)((char)y + '`'));
    }
    iStack_40 = thunk_FUN_10001f20(0,acStack_154,0);
    if (iStack_40 == 0) {
      iStack_44 = 0;
    }
    else {
      pHStack_48 = GetDC((HWND)0x0);
      thunk_FUN_10031425(pHStack_48);
      thunk_FUN_10023560((int32_t *)&BStack_34,width,height);
      pHStack_4c = CreateDIBSection(pHStack_48,&BStack_34,0,&pvStack_3c,(HANDLE)0x0,0);
      if (pHStack_4c == (HBITMAP)0x0) {
        iStack_44 = 0;
      }
      else {
        pvStack_38 = (void *)thunk_FUN_100037d0(0,iStack_40,width,height);
        if (pvStack_38 == (void *)0x0) {
          iStack_44 = 0;
          DeleteObject(pHStack_4c);
        }
        else {
          if ((-width & 3U) == 0) {
            iStack_158 = 0;
          }
          else {
            iStack_158 = 4 - (-width & 3U);
          }
          memcpy(pvStack_3c,pvStack_38,(width * 3 + iStack_158) * height);
        }
      }
      ReleaseDC((HWND)0x0,pHStack_48);
      thunk_FUN_10002340(iStack_40);
    }
    if (iStack_44 != 0) {
      *(HBITMAP *)(&DAT_10175560 + DAT_101cdeb0 * 0x18) = pHStack_4c;
      *(void **)(&DAT_10175564 + DAT_101cdeb0 * 0x18) = pvStack_3c;
      *(int *)(&DAT_10175568 + DAT_101cdeb0 * 0x18) = width;
      *(int *)(&DAT_1017556c + DAT_101cdeb0 * 0x18) = height;
      *(WPARAM *)(&DAT_10175570 + DAT_101cdeb0 * 0x18) = arg_1;
      *(int *)(&DAT_10175574 + DAT_101cdeb0 * 0x18) = y;
      DAT_101cdeb0 = DAT_101cdeb0 + 1;
      PostMessageA(DAT_10176868,0x433,arg_1,y);
    }
  }
  return iStack_44;
}


