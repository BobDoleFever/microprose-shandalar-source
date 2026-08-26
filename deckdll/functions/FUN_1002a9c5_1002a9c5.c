/*
 * Decompiled function: FUN_1002a9c5
 * Entry Point: 1002a9c5
 * Size: 5604 bytes
 */
#include "deckdll.h"


LRESULT FUN_1002a9c5(HWND hwnd,uint32_t y,HMENU arg_3,uint32_t height)

{
  POINT pt;
  uint32_t uval_1;
  uint8_t flag_2;
  BOOL BVar3;
  int val_4;
  HDC hdc;
  LRESULT LVar5;
  tagPAINTSTRUCT local_a8;
  tagPOINT local_68;
  HMENU local_60;
  uint32_t local_5c;
  uint32_t local_58;
  int local_54;
  tagRECT local_50;
  tagRECT local_40;
  uint32_t local_30;
  HDC local_2c;
  int local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  uval_1 = DAT_101cf7d4;
  if (y < 0x10) {
    if (y == 0xf) {
      hdc = BeginPaint(hwnd,&local_a8);
      thunk_FUN_10031425(hdc);
      BitBlt(hdc,DAT_1013eac8,DAT_1013eacc,DAT_1013ead0 - DAT_1013eac8,DAT_1013ead4 - DAT_1013eacc,
             DAT_1013eab0,0,0,0xcc0020);
      EndPaint(hwnd,&local_a8);
      return 0;
    }
    if (y == 1) {
      DAT_101cf7d0 = 0x3e;
      DAT_101cf7d2 = 0x406;
      DAT_101cf7d4 = 0x3ff1f7;
      DAT_101cf7f4 = 2;
      DAT_101cf7f6 = 0;
      DAT_101cf7f8 = 2;
      DAT_101cf7fa = 0;
      DAT_101cf7fc = 2;
      DAT_101cf7fe = 0;
      DAT_101cf800 = 0xfffe;
      DAT_101cf802 = 0xe;
      DAT_101cf803 = 0;
      DAT_101cf808 = 0xffffffff;
      DAT_101cf80c = 0x7ffff;
      for (local_28 = 0; local_28 < 7; local_28 = local_28 + 1) {
        *(int32_t *)(&DAT_101cf7d8 + local_28 * 4) = 0xffffffff;
      }
      if (((DAT_1017646c & 2) == 0) && ((DAT_1017646c & 0xc) == 0)) {
        DAT_10158744 = 0;
      }
      else {
        DAT_10158744 = 0x203;
      }
      DAT_1015874c = 1;
      DAT_10158750 = 1;
      DAT_10158754 = 1;
      DAT_10158758 = 1;
      DAT_1015875c = 1;
      DAT_10158760 = 1;
      thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
      thunk_FUN_1002e266();
      return 0;
    }
    if (y == 2) {
      if (DAT_1013eab0 != (HDC)0x0) {
        DeleteDC(DAT_1013eab0);
      }
      DeleteObject(DAT_1013eb10);
      DeleteObject(DAT_1013eac0);
      thunk_FUN_1002e884();
      KillTimer(hwnd,1);
      return 0;
    }
  }
  else if (y < 0x117) {
    if (y == 0x116) {
      if (arg_3 == DAT_1013f1cc) {
        CheckMenuItem(DAT_1013f1cc,1,((int)(short)DAT_101cf7d0 & 0x100U) >> 5);
        CheckMenuItem(DAT_1013f1cc,2,((int)(short)DAT_101cf7d0 & 0x200U) >> 6);
        CheckMenuItem(DAT_1013f1cc,3,((int)(short)DAT_101cf7d0 & 0x400U) >> 7);
      }
      else if (arg_3 == DAT_1013f1d0) {
        CheckMenuItem(DAT_1013f1d0,4,(DAT_101cf7d4 & 2) << 2);
        CheckMenuItem(DAT_1013f1d0,5,(DAT_101cf7d4 & 4) * 2);
        CheckMenuItem(DAT_1013f1d0,6,DAT_101cf7d4 & 8);
      }
      else if (arg_3 == DAT_1013f1e0) {
        CheckMenuItem(DAT_1013f1e0,7,(DAT_101cf7d4 & 0x20) >> 2);
        CheckMenuItem(DAT_1013f1e0,8,(DAT_101cf7d4 & 0x40) >> 3);
      }
      else if (arg_3 == DAT_1013f1c4) {
        CheckMenuItem(DAT_1013f1c4,9,(DAT_101cf7d4 & 0x100) >> 5);
        CheckMenuItem(DAT_1013f1c4,10,(DAT_101cf7d4 & 0x200) >> 6);
        CheckMenuItem(DAT_1013f1c4,0xb,(DAT_101cf7d4 & 0x400) >> 7);
        CheckMenuItem(DAT_1013f1c4,0xc,(DAT_101cf7d4 & 0x800) >> 8);
      }
      else if (arg_3 == DAT_1013f1dc) {
        CheckMenuItem(DAT_1013f1dc,0xd,(DAT_101cf7d4 & 0x2000) >> 10);
        CheckMenuItem(DAT_1013f1dc,0xe,(DAT_101cf7d4 & 0x4000) >> 0xb);
        CheckMenuItem(DAT_1013f1dc,0xf,(DAT_101cf7d4 & 0x8000) >> 0xc);
        CheckMenuItem(DAT_1013f1dc,0x10,(DAT_101cf7d4 & 0x10000) >> 0xd);
        CheckMenuItem(DAT_1013f1dc,0x11,(DAT_101cf7d4 & 0x20000) >> 0xe);
        CheckMenuItem(DAT_1013f1dc,0x12,(DAT_101cf7d4 & 0x40000) >> 0xf);
      }
      else if (arg_3 == DAT_1013f1e4) {
        CheckMenuItem(DAT_1013f1e4,0x13,((int)(char)DAT_101cf7f4 & 2U) << 2);
        CheckMenuItem(DAT_1013f1e4,0x14,((int)(char)DAT_101cf7f4 & 4U) * 2);
        CheckMenuItem(DAT_1013f1e4,0x15,(int)(char)DAT_101cf7f4 & 8);
        CheckMenuItem(DAT_1013f1e4,0x16,((int)(char)DAT_101cf7f4 & 0x10U) >> 1);
      }
      else if (arg_3 == DAT_1013f1d8) {
        CheckMenuItem(DAT_1013f1d8,0x17,((int)(char)DAT_101cf7f8 & 2U) << 2);
        CheckMenuItem(DAT_1013f1d8,0x18,((int)(char)DAT_101cf7f8 & 4U) * 2);
        CheckMenuItem(DAT_1013f1d8,0x19,(int)(char)DAT_101cf7f8 & 8);
      }
      else if (arg_3 == DAT_1013f1e8) {
        CheckMenuItem(DAT_1013f1e8,0x1a,((int)(char)DAT_101cf7fc & 2U) << 2);
        CheckMenuItem(DAT_1013f1e8,0x1b,((int)(char)DAT_101cf7fc & 4U) * 2);
        CheckMenuItem(DAT_1013f1e8,0x1c,(int)(char)DAT_101cf7fc & 8);
      }
      else if (arg_3 == DAT_1013f1d4) {
        CheckMenuItem(DAT_1013f1d4,0x1d,((int)(short)DAT_101cf800 & 2U) << 2);
        CheckMenuItem(DAT_1013f1d4,0x1e,((int)(short)DAT_101cf800 & 4U) * 2);
        CheckMenuItem(DAT_1013f1d4,0x1f,(int)(short)DAT_101cf800 & 8);
        CheckMenuItem(DAT_1013f1d4,0x20,((int)(short)DAT_101cf800 & 0x10U) >> 1);
        CheckMenuItem(DAT_1013f1d4,0x21,((int)(short)DAT_101cf800 & 0x20U) >> 2);
        CheckMenuItem(DAT_1013f1d4,0x22,((int)(short)DAT_101cf800 & 0x40U) >> 3);
        CheckMenuItem(DAT_1013f1d4,0x23,((int)(short)DAT_101cf800 & 0x80U) >> 4);
        CheckMenuItem(DAT_1013f1d4,0x24,((int)(short)DAT_101cf800 & 0x100U) >> 5);
        CheckMenuItem(DAT_1013f1d4,0x25,((int)(short)DAT_101cf800 & 0x200U) >> 6);
        CheckMenuItem(DAT_1013f1d4,0x26,((int)(short)DAT_101cf800 & 0x400U) >> 7);
        CheckMenuItem(DAT_1013f1d4,0x27,((int)(short)DAT_101cf800 & 0x800U) >> 8);
        CheckMenuItem(DAT_1013f1d4,0x28,((int)(short)DAT_101cf800 & 0x1000U) >> 9);
        CheckMenuItem(DAT_1013f1d4,0x29,((int)(short)DAT_101cf800 & 0x2000U) >> 10);
        CheckMenuItem(DAT_1013f1d4,0x2a,((int)(short)DAT_101cf800 & 0x4000U) >> 0xb);
        CheckMenuItem(DAT_1013f1d4,0x2b,((int)(short)DAT_101cf800 & 0x8000U) >> 0xc);
      }
      else if (arg_3 == DAT_1013f1ec) {
        CheckMenuItem(DAT_1013f1ec,0x2c,((int)(char)DAT_101cf802 & 2U) << 2);
        CheckMenuItem(DAT_1013f1ec,0x2d,((int)(char)DAT_101cf802 & 4U) * 2);
        CheckMenuItem(DAT_1013f1ec,0x2e,(int)(char)DAT_101cf802 & 8);
      }
      return 0;
    }
    if (y == 0x111) {
      local_30 = 0;
      switch((uint32_t)arg_3 & 0xffff) {
      case 1:
      case 2:
      case 3:
        DAT_101cf7d0 = DAT_101cf7d0 & 0xf0ff;
        if (((uint32_t)arg_3 & 0xffff) == 1) {
          DAT_101cf7d0 = DAT_101cf7d0 | 0x100;
        }
        if (((uint32_t)arg_3 & 0xffff) == 2) {
          DAT_101cf7d0 = DAT_101cf7d0 | 0x200;
        }
        if (((uint32_t)arg_3 & 0xffff) == 3) {
          DAT_101cf7d0 = DAT_101cf7d0 | 0x400;
        }
        break;
      case 4:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 2;
        local_30 = (uint32_t)((DAT_101cf7d4 & 1) != 0);
        break;
      case 5:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 4;
        local_30 = (uint32_t)((DAT_101cf7d4 & 1) != 0);
        break;
      case 6:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 8;
        local_30 = (uint32_t)((DAT_101cf7d4 & 1) != 0);
        break;
      case 7:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x20;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x10) != 0);
        break;
      case 8:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x40;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x10) != 0);
        break;
      case 9:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x100;
        if ((DAT_101cf7d4 & 0x800) != 0) {
          DAT_101cf7d4 = uval_1 ^ 0x900;
        }
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x80) != 0);
        break;
      case 10:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x200;
        if ((DAT_101cf7d4 & 0x800) != 0) {
          DAT_101cf7d4 = uval_1 ^ 0xa00;
        }
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x80) != 0);
        break;
      case 0xb:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x400;
        if ((DAT_101cf7d4 & 0x800) != 0) {
          DAT_101cf7d4 = uval_1 ^ 0xc00;
        }
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x80) != 0);
        break;
      case 0xc:
        val_4 = thunk_FUN_1002ed06(1);
        if (val_4 != 0) {
          if ((DAT_101cf7d4 & 0x800) == 0) {
            DAT_101cf7d4 = DAT_101cf7d4 | DAT_10046130;
            DAT_10046130 = 0;
          }
          else if (DAT_10046130 == 0) {
            DAT_10046130 = DAT_101cf7d4 & 0x700;
            DAT_101cf7d4 = DAT_101cf7d4 & 0xfffff8ff;
          }
          if ((DAT_101cf7d4 & 0x80) != 0) {
            local_30 = 1;
          }
        }
        break;
      case 0xd:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x2000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0xe:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x4000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0xf:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x8000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0x10:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x10000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0x11:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x20000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0x12:
        DAT_101cf7d4 = DAT_101cf7d4 ^ 0x40000;
        local_30 = (uint32_t)((DAT_101cf7d4 & 0x1000) != 0);
        break;
      case 0x13:
      case 0x14:
      case 0x15:
        DAT_101cfb9c = (int)DAT_101cf7f6;
        val_4 = thunk_FUN_1002e9bb(0x1d);
        if (val_4 != 0) {
          DAT_101cf7f6 = (short)DAT_1013eaa8;
          DAT_101cf7f4 = DAT_101cf7f4 & 1;
          if (((uint32_t)arg_3 & 0xffff) == 0x13) {
            DAT_101cf7f4 = DAT_101cf7f4 | 2;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x14) {
            DAT_101cf7f4 = DAT_101cf7f4 | 4;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x15) {
            DAT_101cf7f4 = DAT_101cf7f4 | 8;
          }
          if ((DAT_101cf7f4 & 1) != 0) {
            local_30 = 1;
          }
        }
        break;
      case 0x16:
        flag_2 = DAT_101cf7f4 & 1;
        DAT_101cf7f4 = flag_2 | 0x10;
        local_30 = (uint32_t)(flag_2 != 0);
        break;
      case 0x17:
      case 0x18:
      case 0x19:
        DAT_101cfb9c = (int)DAT_101cf7fa;
        val_4 = thunk_FUN_1002e9bb(0x1e);
        if (val_4 != 0) {
          DAT_101cf7fa = (short)DAT_1013eaa8;
          DAT_101cf7f8 = DAT_101cf7f8 & 1;
          if (((uint32_t)arg_3 & 0xffff) == 0x17) {
            DAT_101cf7f8 = DAT_101cf7f8 | 2;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x18) {
            DAT_101cf7f8 = DAT_101cf7f8 | 4;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x19) {
            DAT_101cf7f8 = DAT_101cf7f8 | 8;
          }
          if ((DAT_101cf7f8 & 1) != 0) {
            local_30 = 1;
          }
        }
        break;
      case 0x1a:
      case 0x1b:
      case 0x1c:
        DAT_101cfb9c = (int)DAT_101cf7fe;
        val_4 = thunk_FUN_1002e9bb(0x1f);
        if (val_4 != 0) {
          DAT_101cf7fe = (short)DAT_1013eaa8;
          DAT_101cf7fc = DAT_101cf7fc & 1;
          if (((uint32_t)arg_3 & 0xffff) == 0x1a) {
            DAT_101cf7fc = DAT_101cf7fc | 2;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x1b) {
            DAT_101cf7fc = DAT_101cf7fc | 4;
          }
          if (((uint32_t)arg_3 & 0xffff) == 0x1c) {
            DAT_101cf7fc = DAT_101cf7fc | 8;
          }
          if ((DAT_101cf7fc & 1) != 0) {
            local_30 = 1;
          }
        }
        break;
      case 0x1d:
        DAT_101cf800 = DAT_101cf800 ^ 2;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x1e:
        DAT_101cf800 = DAT_101cf800 ^ 4;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x1f:
        DAT_101cf800 = DAT_101cf800 ^ 8;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x20:
        DAT_101cf800 = DAT_101cf800 ^ 0x10;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x21:
        DAT_101cf800 = DAT_101cf800 ^ 0x20;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x22:
        DAT_101cf800 = DAT_101cf800 ^ 0x40;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x23:
        DAT_101cf800 = DAT_101cf800 ^ 0x80;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x24:
        DAT_101cf800 = DAT_101cf800 ^ 0x100;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x25:
        DAT_101cf800 = DAT_101cf800 ^ 0x200;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x26:
        DAT_101cf800 = DAT_101cf800 ^ 0x400;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x27:
        DAT_101cf800 = DAT_101cf800 ^ 0x800;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x28:
        DAT_101cf800 = DAT_101cf800 ^ 0x1000;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x29:
        DAT_101cf800 = DAT_101cf800 ^ 0x2000;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x2a:
        DAT_101cf800 = DAT_101cf800 ^ 0x4000;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x2b:
        DAT_101cf800 = DAT_101cf800 ^ 0x8000;
        local_30 = (uint32_t)((DAT_101cf800 & 1) != 0);
        break;
      case 0x2c:
        DAT_101cf802 = DAT_101cf802 ^ 2;
        local_30 = (uint32_t)((DAT_101cf802 & 1) != 0);
        break;
      case 0x2d:
        DAT_101cf802 = DAT_101cf802 ^ 4;
        local_30 = (uint32_t)((DAT_101cf802 & 1) != 0);
        break;
      case 0x2e:
        DAT_101cf802 = DAT_101cf802 ^ 8;
        local_30 = (uint32_t)((DAT_101cf802 & 1) != 0);
        break;
      case 0x2f:
        val_4 = thunk_FUN_1002ed06(0);
        if ((val_4 == 0) && ((DAT_101cf803 & 1) != 0)) {
          local_30 = 1;
        }
        break;
      default:
        return 0;
      case 100:
        DAT_101cf7d0 = DAT_101cf7d0 | 0x3e;
        DAT_101cf7d2 = DAT_101cf7d2 | 0x406;
        DAT_101cf7d4 = DAT_101cf7d4 | 0x381091;
        local_30 = 1;
        break;
      case 0x65:
        DAT_101cf7d0 = DAT_101cf7d0 & 0xffc1;
        DAT_101cf7d2 = DAT_101cf7d2 & 0xe001;
        DAT_101cf7d4 = DAT_101cf7d4 & 0xffc7ef6e;
        local_30 = 1;
      }
      local_28 = 1;
      GetClientRect(hwnd,&local_24);
      thunk_FUN_1002c0c7(&local_24.left,local_28,&local_14);
      FillRect(DAT_1013eab0,&local_24,DAT_10162900);
      thunk_FUN_1002c7e8(DAT_1013eab0,local_24.left,local_24.top,local_24.right,local_24.bottom);
      InvalidateRect(hwnd,(RECT *)0x0,0);
      if (local_30 == 1) {
        SendMessageA(DAT_101cfb80,0x186,0,0);
        thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
      }
      return 0;
    }
  }
  else if (y < 0x205) {
    if (y == 0x204) {
      local_68.x = height & 0xffff;
      local_68.y = height >> 0x10;
      local_60 = (HMENU)thunk_FUN_1002e012(hwnd,local_68.x,local_68.y);
      if (local_60 != (HMENU)0x0) {
        ClientToScreen(hwnd,&local_68);
        TrackPopupMenu(local_60,2,local_68.x,local_68.y,0,hwnd,(RECT *)0x0);
      }
      return 0;
    }
    if (y == 0x201) {
      local_5c = height & 0xffff;
      local_58 = height >> 0x10;
      GetClientRect(hwnd,&local_50);
      local_54 = 0;
      while( true ) {
        if (0x22 < local_54) {
          return 0;
        }
        thunk_FUN_1002c0c7(&local_50.left,local_54,&local_40);
        pt.y = local_58;
        pt.x = local_5c;
        BVar3 = PtInRect(&local_40,pt);
        if (BVar3 != 0) break;
        local_54 = local_54 + 1;
      }
      FillRect(DAT_1013eab0,&local_50,DAT_10162900);
      val_4 = thunk_FUN_1002cf32(local_54);
      if (val_4 == 0) {
        if (DAT_101cf542 != '\0') {
          thunk_FUN_10027a61(5,400,0,0);
        }
      }
      else if (DAT_101cf542 != '\0') {
        thunk_FUN_10027a61(4,400,0,0);
      }
      SendMessageA(DAT_101cfb80,0x186,0,0);
      thunk_FUN_10037627(DAT_101cf538,DAT_101cfb80);
      thunk_FUN_1002c7e8(DAT_1013eab0,local_50.left,local_50.top,local_50.right,local_50.bottom);
      InvalidateRect(hwnd,(RECT *)0x0,0);
      return 0;
    }
  }
  else {
    if (y == 0x402) {
      GetClientRect(DAT_101628e4,(LPRECT)&DAT_1013eac8);
      if (DAT_1013eab0 != (HDC)0x0) {
        DeleteDC(DAT_1013eab0);
      }
      local_2c = GetDC(hwnd);
      thunk_FUN_10031425(local_2c);
      DAT_1013eab0 = CreateCompatibleDC(local_2c);
      thunk_FUN_10031425(DAT_1013eab0);
      DAT_1013eb10 = CreateCompatibleBitmap
                               (local_2c,DAT_1013ead0 - DAT_1013eac8,DAT_1013ead4 - DAT_1013eacc);
      SelectObject(DAT_1013eab0,DAT_1013eb10);
      DAT_1013eac0 = CreateFontA(DAT_1013ead4 + -6,0,0,0,400,0,0,0,0,4,0,0,0x40,(LPCSTR)0x0);
      SelectObject(DAT_1013eab0,DAT_1013eac0);
      ReleaseDC(hwnd,local_2c);
      FillRect(DAT_1013eab0,(RECT *)&DAT_1013eac8,DAT_10162900);
      thunk_FUN_1002c7e8(DAT_1013eab0,DAT_1013eac8,DAT_1013eacc,DAT_1013ead0,DAT_1013ead4);
      InvalidateRect(hwnd,(RECT *)0x0,1);
      return 0;
    }
    if (y == 0x465) {
      LVar5 = thunk_FUN_1002d55f(hwnd,arg_3,height);
      return LVar5;
    }
  }
  LVar5 = DefWindowProcA(hwnd,y,(WPARAM)arg_3,height);
  return LVar5;
}


