/*
 * Decompiled function: thunk_FUN_1001ae07
 * Entry Point: 10001087
 * Size: 5 bytes
 */
#include "deckdll.h"


int32_t thunk_FUN_1001ae07(HDC hdc,int *arg_2,int32_t *arg_3,int arg_4,uint32_t arg_5,int arg_6)

{
  HGDIOBJ buf_ptr_1;
  size_t len_2;
  int val_3;
  HBRUSH pHVar4;
  LPCSTR pCVar5;
  int32_t uval_6;
  uint8_t *puStack_1fc;
  uint8_t auStack_1f0 [4];
  int iStack_1ec;
  int iStack_1e8;
  int iStack_1d8;
  int32_t uStack_1d4;
  int32_t uStack_1d0;
  tagTEXTMETRICA tStack_1cc;
  tagRECT tStack_194;
  int iStack_184;
  uint32_t uStack_180;
  tagRECT tStack_17c;
  char acStack_16c [100];
  int iStack_108;
  int *piStack_104;
  tagRECT tStack_100;
  HBRUSH pHStack_f0;
  tagRECT tStack_ec;
  tagRECT tStack_dc;
  int iStack_cc;
  COLORREF CStack_c8;
  int iStack_c4;
  tagRECT tStack_c0;
  char acStack_b0 [52];
  tagRECT tStack_7c;
  int32_t uStack_6c;
  HANDLE pvStack_68;
  tagRECT tStack_64;
  tagRECT tStack_54;
  int iStack_44;
  tagRECT tStack_40;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  tagRECT tStack_24;
  tagRECT tStack_14;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (int32_t *)0x0)) {
    uStack_6c = 0;
  }
  else {
    iStack_30 = SaveDC(hdc);
    iStack_c4 = 200;
    iStack_2c = 300;
    SetMapMode(hdc,7);
    SetWindowExtEx(hdc,iStack_c4,iStack_2c,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,iStack_c4 / 2,iStack_2c / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2 + (arg_2[2] - *arg_2) / 2,arg_2[1] + (arg_2[3] - arg_2[1]) / 2,
                     (LPPOINT)0x0);
    iStack_44 = 6;
    iStack_28 = 6;
    SetRect(&tStack_40,0xc,9,0xbc,0x16);
    SetRect(&tStack_24,0xc,8,0xbe,0x14);
    SetRect(&tStack_ec,0x15,0x19,0xb5,0xa4);
    SetRect(&tStack_64,0xc,0xa9,0xba,0xb4);
    SetRect(&tStack_14,0xc,0xa9,0xba,0xb4);
    SetRect(&tStack_54,0x1c,0xb9,0xae,0x10c);
    SetRect(&tStack_7c,0x14,0xb4,0xb6,0x10f);
    SetRect(&tStack_c0,0xc,0x114,0xbc,0x124);
    SetRect(&tStack_dc,0xc,0x114,0xbc,0x124);
    if (((arg_3[3] == -1) || ((*(uint8_t *)(arg_3 + 3) & 0x10) != 0)) ||
       ((*(uint8_t *)(arg_3 + 3) & 0x80) != 0)) {
      pHStack_f0 = CreateSolidBrush(DAT_1013e3a8);
      SelectObject(hdc,pHStack_f0);
    }
    else {
      pHStack_f0 = CreateSolidBrush(DAT_1013e5e8);
      SelectObject(hdc,pHStack_f0);
    }
    buf_ptr_1 = GetStockObject(8);
    SelectObject(hdc,buf_ptr_1);
    RoundRect(hdc,0,0,iStack_c4,iStack_2c,iStack_44 / 2,iStack_28 / 2);
    buf_ptr_1 = GetStockObject(4);
    SelectObject(hdc,buf_ptr_1);
    if (pHStack_f0 != (HBRUSH)0x0) {
      DeleteObject(pHStack_f0);
    }
    if (arg_3[4] == 1) {
      piStack_104 = &DAT_1013e60c;
    }
    else if (arg_3[4] == 8) {
      piStack_104 = &DAT_1013e034;
    }
    else if (arg_3[4] == 7) {
      piStack_104 = &DAT_1013e600;
    }
    else if (arg_3[4] == 5) {
      piStack_104 = &DAT_1013dff4;
    }
    else if (arg_3[4] == 2) {
      piStack_104 = &DAT_1013e5f4;
    }
    else if (arg_3[4] == 4) {
      piStack_104 = &DAT_1013e204;
    }
    else if (arg_3[4] == 0) {
      piStack_104 = &DAT_1013e5dc;
    }
    else if (arg_3[4] == 3) {
      piStack_104 = &DAT_1013e5dc;
    }
    else if (arg_3[4] == 6) {
      if ((*(uint8_t *)(arg_3 + 3) & 2) == 0) {
        if ((*(uint8_t *)(arg_3 + 3) & 4) == 0) {
          if ((*(uint8_t *)(arg_3 + 3) & 0x20) == 0) {
            if ((*(uint8_t *)((int)arg_3 + 0xd) & 1) == 0) {
              if ((*(uint8_t *)(arg_3 + 3) & 8) == 0) {
                val_3 = strcmp((char *)arg_3[1],s_Swamp_100436c8);
                if (val_3 == 0) {
                  piStack_104 = &DAT_1013e1f4;
                }
                else {
                  val_3 = strcmp((char *)arg_3[1],s_Plains_100436d0);
                  if (val_3 == 0) {
                    piStack_104 = &DAT_1013e200;
                  }
                  else {
                    val_3 = strcmp((char *)arg_3[1],s_Mountain_100436d8);
                    if (val_3 == 0) {
                      piStack_104 = &DAT_1013e564;
                    }
                    else {
                      val_3 = strcmp((char *)arg_3[1],s_Forest_100436e4);
                      if (val_3 == 0) {
                        piStack_104 = &DAT_1013e038;
                      }
                      else {
                        val_3 = strcmp((char *)arg_3[1],s_Island_100436ec);
                        if (val_3 == 0) {
                          piStack_104 = &DAT_1013e3b8;
                        }
                        else {
                          piStack_104 = &DAT_1013e608;
                        }
                      }
                    }
                  }
                }
              }
              else {
                piStack_104 = &DAT_1013e608;
              }
            }
            else {
              piStack_104 = &DAT_1013dfe8;
            }
          }
          else {
            piStack_104 = &DAT_1013e594;
          }
        }
        else {
          piStack_104 = &DAT_1013e5e4;
        }
      }
      else {
        piStack_104 = &DAT_1013e608;
      }
    }
    else if (arg_3[4] == -1) {
      piStack_104 = &DAT_1013e5d8;
    }
    else {
      piStack_104 = &DAT_1013e5dc;
    }
    thunk_FUN_1001a9ec(piStack_104);
    SetRect(&tStack_100,iStack_44,iStack_28,iStack_c4 - iStack_44,iStack_2c - iStack_28);
    if (*piStack_104 == 0) {
      pHVar4 = GetStockObject(0);
      FillRect(hdc,&tStack_100,pHVar4);
    }
    else {
      thunk_FUN_1003162f((int)hdc,(int)&tStack_100,(HANDLE)*piStack_104);
    }
    pvStack_68 = (HANDLE)*piStack_104;
    iStack_cc = 1;
    CStack_c8 = thunk_FUN_1003378c(0xbf);
    SelectObject(hdc,DAT_1013e554);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_1013e1f8);
    OffsetRect(&tStack_40,iStack_cc,iStack_cc);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&tStack_40,0x824);
    OffsetRect(&tStack_40,-iStack_cc,-iStack_cc);
    SetTextColor(hdc,CStack_c8);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&tStack_40,0x824);
    iStack_108 = 100;
    SelectObject(hdc,DAT_1013e3a0);
    if ((arg_3[0x1f] != 0) || (arg_3[0x20] != 0)) {
      acStack_b0[0] = '\0';
      if (arg_3[0x1f] == iStack_108) {
        strcat(acStack_b0,&DAT_100436f4);
      }
      else if (iStack_108 < (int)arg_3[0x1f]) {
        val_3 = arg_3[0x1f] - iStack_108;
        pCVar5 = &DAT_100436f8;
        len_2 = strlen(acStack_b0);
        wsprintfA(acStack_b0 + len_2,pCVar5,val_3);
      }
      else {
        uval_6 = arg_3[0x1f];
        pCVar5 = &DAT_10043700;
        len_2 = strlen(acStack_b0);
        wsprintfA(acStack_b0 + len_2,pCVar5,uval_6);
      }
      strcat(acStack_b0,&DAT_10043704);
      if (arg_3[0x20] == iStack_108) {
        strcat(acStack_b0,&DAT_10043708);
      }
      else if (iStack_108 < (int)arg_3[0x20]) {
        val_3 = arg_3[0x20] - iStack_108;
        pCVar5 = &DAT_1004370c;
        len_2 = strlen(acStack_b0);
        wsprintfA(acStack_b0 + len_2,pCVar5,val_3);
      }
      else {
        uval_6 = arg_3[0x20];
        pCVar5 = &DAT_10043714;
        len_2 = strlen(acStack_b0);
        wsprintfA(acStack_b0 + len_2,pCVar5,uval_6);
      }
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&tStack_dc,iStack_cc,iStack_cc);
      DrawTextA(hdc,acStack_b0,-1,&tStack_dc,0x26);
      OffsetRect(&tStack_dc,-iStack_cc,-iStack_cc);
      SetTextColor(hdc,CStack_c8);
      DrawTextA(hdc,acStack_b0,-1,&tStack_dc,0x26);
    }
    SelectObject(hdc,DAT_1013e044);
    SetBkMode(hdc,1);
    if ((arg_3[5] != -1) && (arg_3[5] != 0)) {
      if ((arg_3[5] == 2) && ((arg_3[6] == 0 || (arg_3[6] == 0xda)))) {
        strcpy(acStack_16c,s_Enchantment_10043718);
      }
      else {
        if ((arg_3[6] == 0) || (arg_3[6] == 0xda)) {
          puStack_1fc = &DAT_10043724;
        }
        else {
          puStack_1fc = (&PTR_DAT_10043c70)[arg_3[6]];
        }
        sprintf(acStack_16c,s__s__s_10043728,(&PTR_DAT_10043c48)[arg_3[5]],puStack_1fc);
      }
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&tStack_64,iStack_cc,iStack_cc);
      DrawTextA(hdc,acStack_16c,-1,&tStack_64,0x24);
      OffsetRect(&tStack_64,-iStack_cc,-iStack_cc);
      SetTextColor(hdc,CStack_c8);
      DrawTextA(hdc,acStack_16c,-1,&tStack_64,0x24);
    }
    if (arg_3[0x10] != 0) {
      wsprintfA(acStack_b0,s_Illus___s_10043730,arg_3[0x10]);
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&tStack_c0,iStack_cc,iStack_cc);
      DrawTextA(hdc,acStack_b0,-1,&tStack_c0,0x824);
      OffsetRect(&tStack_c0,-iStack_cc,-iStack_cc);
      SetTextColor(hdc,CStack_c8);
      DrawTextA(hdc,acStack_b0,-1,&tStack_c0,0x824);
    }
    if (((arg_3[5] != 5) && (arg_3[5] != 8)) && (arg_3[5] != 0)) {
      thunk_FUN_1001c251(hdc,(int)&tStack_24,(char *)(arg_3 + 10));
    }
    if (arg_3[3] != -1) {
      thunk_FUN_1001c0c3(hdc,(int)&tStack_14,arg_3[3]);
    }
    if (DAT_101628dc != 0) {
      CopyRect(&tStack_17c,&tStack_ec);
      LPtoDP(hdc,(LPPOINT)&tStack_17c,2);
      if ((arg_5 & 0xf) == 0) {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (val_3 == 0) {
          thunk_FUN_10028d12(hdc,&tStack_ec,*arg_3,arg_4);
        }
        else {
          thunk_FUN_10013b53(hdc,&tStack_ec,*arg_3,arg_4);
        }
      }
      else if ((arg_5 & 0xf) == 1) {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (val_3 == 0) {
          if (((arg_5 & 0x10) != 0) && (val_3 = thunk_FUN_10028c81(*arg_3,arg_4), val_3 != 0)) {
            thunk_FUN_10028d12(hdc,&tStack_ec,*arg_3,arg_4);
          }
          thunk_FUN_10013760(*arg_3,arg_4,tStack_17c.right - tStack_17c.left,
                             tStack_17c.bottom - tStack_17c.top);
        }
        thunk_FUN_10013b53(hdc,&tStack_ec,*arg_3,arg_4);
      }
      else {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (((val_3 == 0) && ((arg_5 & 0x10) != 0)) &&
           (val_3 = thunk_FUN_10028c81(*arg_3,arg_4), val_3 != 0)) {
          thunk_FUN_10028d12(hdc,&tStack_ec,*arg_3,arg_4);
        }
        val_3 = thunk_FUN_10013760(*arg_3,arg_4,tStack_17c.right - tStack_17c.left,
                                   tStack_17c.bottom - tStack_17c.top);
        if (val_3 == 0) {
          thunk_FUN_10028d12(hdc,&tStack_ec,*arg_3,arg_4);
        }
        else {
          thunk_FUN_10013b53(hdc,&tStack_ec,*arg_3,arg_4);
        }
      }
      uStack_6c = thunk_FUN_10013ae3(*arg_3,arg_4,tStack_17c.right - tStack_17c.left,
                                     tStack_17c.bottom - tStack_17c.top);
    }
    SetTextColor(hdc,DAT_1013e65c);
    SetBkMode(hdc,1);
    if (arg_6 != 0) {
      SelectObject(hdc,DAT_1013e3ac);
      uStack_180 = thunk_FUN_1001cb7b(hdc,(int)&tStack_54,arg_3[0x1d]);
      uStack_180 = uStack_180 >> 0x10;
      GetTextMetricsA(hdc,&tStack_1cc);
      CopyRect(&tStack_194,&tStack_54);
      tStack_194.top = tStack_194.top + uStack_180 + tStack_1cc.tmHeight / 2;
      SelectObject(hdc,DAT_1013e604);
      DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&tStack_194,0x410);
      iStack_184 = tStack_194.bottom - tStack_54.top;
      if (tStack_54.bottom - tStack_54.top < iStack_184) {
        iStack_1d8 = tStack_54.top - tStack_7c.top;
        tStack_54.top = tStack_54.bottom - iStack_184;
        tStack_7c.top = tStack_54.top - iStack_1d8;
        if (pvStack_68 == (HANDLE)0x0) {
          pHVar4 = GetStockObject(0);
          FillRect(hdc,&tStack_7c,pHVar4);
        }
        else {
          GetObjectA(pvStack_68,0x18,auStack_1f0);
          uStack_1d0 = 0x359;
          uStack_1d4 = 0x140;
          thunk_FUN_10031697(hdc,&tStack_7c.left,pvStack_68,(iStack_1ec * 0x49) / 1000,
                             (iStack_1e8 * 0x25d) / 1000,(iStack_1ec * 0x359) / 1000,
                             (iStack_1e8 * 0x140) / 1000);
        }
      }
    }
    SelectObject(hdc,DAT_1013e3ac);
    uStack_180 = thunk_FUN_1001cbfc(hdc,&tStack_54.left,(char *)arg_3[0x1d],1);
    uStack_180 = uStack_180 >> 0x10;
    GetTextMetricsA(hdc,&tStack_1cc);
    CopyRect(&tStack_194,&tStack_54);
    tStack_194.top = tStack_194.top + uStack_180 + tStack_1cc.tmHeight / 3;
    SelectObject(hdc,DAT_1013e604);
    DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&tStack_194,0x10);
    RestoreDC(hdc,iStack_30);
  }
  return uStack_6c;
}


