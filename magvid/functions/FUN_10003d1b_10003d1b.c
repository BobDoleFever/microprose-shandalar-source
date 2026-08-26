/*
 * Decompiled function: FUN_10003d1b
 * Entry Point: 10003d1b
 * Size: 992 bytes
 */
#include "magvid.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_10003d1b(HWND x,uint32_t y,uint32_t width,LPVOID height)

{
  int val_1;
  LRESULT LVar2;
  int local_58;
  LPVOID local_54;
  HDC local_50;
  tagPAINTSTRUCT local_4c;
  int local_c;
  uint32_t local_8;
  
  if (y < 0x10) {
    if (y == 0xf) {
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        local_50 = BeginPaint(x,&local_4c);
        if (*(int *)(&DAT_10010868 + local_58 * 4) != 0) {
          thunk_FUN_10005c78(*(int *)(&DAT_10010868 + local_58 * 4),(int)local_50);
        }
        EndPaint(x,&local_4c);
        DrawVidBackground(local_58);
      }
    }
    else if (y == 1) {
      _DAT_100108a8 = 0;
    }
    else {
      if (y != 2) goto switchD_10004133_caseD_312;
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if ((val_1 == 0) &&
         (thunk_FUN_10005b92(*(LPARAM **)(&DAT_10010868 + local_58 * 4)),
         *(int *)(&DAT_10010868 + local_58 * 4) != 0)) {
        thunk_FUN_100059e8(*(int *)(&DAT_10010868 + local_58 * 4));
      }
    }
  }
  else if (y < 0x112) {
    if (y == 0x111) {
      local_8 = width & 0xffff;
      local_54 = height;
      switch(local_8) {
      case 0x9c43:
        thunk_FUN_10005d8d(height);
        break;
      case 0x9c44:
        if (*(int *)(&DAT_10010868 + (int)height * 4) != 0) {
          thunk_FUN_10005ef9(*(int *)(&DAT_10010868 + (int)height * 4));
        }
        break;
      default:
        LVar2 = DefWindowProcA(x,0x111,width,(LPARAM)height);
        return LVar2;
      case 0x9c66:
        break;
      case 0x9c67:
      }
    }
    else {
      if (y != 0x14) goto switchD_10004133_caseD_312;
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        DrawVidBackground(local_58);
      }
    }
  }
  else if (y < 0x310) {
    if (y != 0x30f) {
      if (y == 0x202) {
        for (local_c = 0; local_c < 3; local_c = local_c + 1) {
          if ((*(int *)(&DAT_10010868 + local_c * 4) != 0) &&
             (*(HWND *)(*(int *)(&DAT_10010868 + local_c * 4) + 0x10) == x)) {
            *(int32_t *)(*(int *)(&DAT_10010868 + local_c * 4) + 0x10) = 0;
          }
        }
        DestroyWindow(x);
      }
      else if (y != 0x204) goto switchD_10004133_caseD_312;
    }
  }
  else {
    switch(y) {
    case 0x311:
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (((val_1 == 0) &&
          (thunk_FUN_10005ce8(*(int *)(&DAT_10010868 + local_58 * 4),width),
          *(int *)(*(int *)(&DAT_10010868 + local_58 * 4) + 0x38) == 0)) &&
         (*(uint32_t *)(*(int *)(&DAT_10010868 + local_58 * 4) + 0x10) != width)) {
        InvalidateRect(x,(RECT *)0x0,0);
      }
      break;
    default:
switchD_10004133_caseD_312:
      LVar2 = DefWindowProcA(x,y,width,(LPARAM)height);
      return LVar2;
    case 0x3bb:
    case 0x3bc:
    case 0x3bd:
      thunk_FUN_10005fee();
      break;
    case 0x401:
      if ((*(int *)(&DAT_10010868 + (int)height * 4) != 0) &&
         (*(int *)(*(int *)(&DAT_10010868 + (int)height * 4) + 0x50) == 0)) {
        thunk_FUN_10006020(*(int *)(&DAT_10010868 + (int)height * 4));
      }
      val_1 = thunk_FUN_10004249((int)x,&local_58);
      if (val_1 == 0) {
        DrawVidBackground(local_58);
      }
    }
  }
  return 0;
}


