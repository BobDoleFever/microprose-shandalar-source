/*
 * Decompiled function: thunk_FUN_10028a10
 * Entry Point: 100010f0
 * Size: 5 bytes
 */
#include "deckdll.h"


int thunk_FUN_10028a10(WPARAM arg_1,int arg_2,int width,int height)

{
  int iStack_154;
  char acStack_150 [264];
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
  else if (*(int *)(&DAT_10176af4 + arg_1 * 0x98) < 2) {
    if (*(int *)(&DAT_10162910 + arg_1 * 0x10) != 0) {
      if ((*(int *)(&DAT_10162918 + arg_1 * 0x10) == width) &&
         (*(int *)(&DAT_1016291c + arg_1 * 0x10) == height)) {
        return 1;
      }
      thunk_FUN_10028f03(arg_1);
    }
    sprintf(acStack_150,s__s__04d_WVL_10046058,&DAT_10158890,arg_1);
    iStack_3c = thunk_FUN_10001f20(0,acStack_150,0);
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
            iStack_154 = 0;
          }
          else {
            iStack_154 = 4 - (-width & 3U);
          }
          memcpy(pvStack_38,pvStack_34,(width * 3 + iStack_154) * height);
        }
      }
      ReleaseDC((HWND)0x0,pHStack_44);
      thunk_FUN_10002340(iStack_3c);
    }
    if (iStack_40 != 0) {
      *(HBITMAP *)(&DAT_10162910 + arg_1 * 0x10) = pHStack_48;
      *(void **)(&DAT_10162914 + arg_1 * 0x10) = pvStack_38;
      *(int *)(&DAT_10162918 + arg_1 * 0x10) = width;
      *(int *)(&DAT_1016291c + arg_1 * 0x10) = height;
      PostMessageA(DAT_10176868,0x433,arg_1,0);
    }
  }
  else {
    iStack_40 = thunk_FUN_10028f53(arg_1,arg_2,width,height);
  }
  return iStack_40;
}


