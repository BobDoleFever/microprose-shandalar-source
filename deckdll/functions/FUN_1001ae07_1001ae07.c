/*
 * Decompiled function: FUN_1001ae07
 * Entry Point: 1001ae07
 * Size: 4215 bytes
 */
#include "deckdll.h"


int32_t FUN_1001ae07(HDC hdc,int *arg_2,int32_t *arg_3,int arg_4,uint32_t arg_5,int arg_6)

{
  HGDIOBJ buf_ptr_1;
  size_t len_2;
  int val_3;
  HBRUSH pHVar4;
  LPCSTR pCVar5;
  int32_t uval_6;
  uint8_t *local_1fc;
  uint8_t local_1f0 [4];
  int local_1ec;
  int local_1e8;
  int local_1d8;
  int32_t local_1d4;
  int32_t local_1d0;
  tagTEXTMETRICA local_1cc;
  tagRECT local_194;
  int local_184;
  uint32_t local_180;
  tagRECT local_17c;
  char local_16c [100];
  int local_108;
  int *local_104;
  tagRECT local_100;
  HBRUSH local_f0;
  tagRECT local_ec;
  tagRECT local_dc;
  int local_cc;
  COLORREF local_c8;
  int local_c4;
  tagRECT local_c0;
  char local_b0 [52];
  tagRECT local_7c;
  int32_t local_6c;
  HANDLE local_68;
  tagRECT local_64;
  tagRECT local_54;
  int local_44;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  tagRECT local_14;
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (int32_t *)0x0)) {
    local_6c = 0;
  }
  else {
    local_30 = SaveDC(hdc);
    local_c4 = 200;
    local_2c = 300;
    SetMapMode(hdc,7);
    SetWindowExtEx(hdc,local_c4,local_2c,(LPSIZE)0x0);
    SetViewportExtEx(hdc,arg_2[2] - *arg_2,arg_2[3] - arg_2[1],(LPSIZE)0x0);
    SetWindowOrgEx(hdc,local_c4 / 2,local_2c / 2,(LPPOINT)0x0);
    SetViewportOrgEx(hdc,*arg_2 + (arg_2[2] - *arg_2) / 2,arg_2[1] + (arg_2[3] - arg_2[1]) / 2,
                     (LPPOINT)0x0);
    local_44 = 6;
    local_28 = 6;
    SetRect(&local_40,0xc,9,0xbc,0x16);
    SetRect(&local_24,0xc,8,0xbe,0x14);
    SetRect(&local_ec,0x15,0x19,0xb5,0xa4);
    SetRect(&local_64,0xc,0xa9,0xba,0xb4);
    SetRect(&local_14,0xc,0xa9,0xba,0xb4);
    SetRect(&local_54,0x1c,0xb9,0xae,0x10c);
    SetRect(&local_7c,0x14,0xb4,0xb6,0x10f);
    SetRect(&local_c0,0xc,0x114,0xbc,0x124);
    SetRect(&local_dc,0xc,0x114,0xbc,0x124);
    if (((arg_3[3] == -1) || ((*(uint8_t *)(arg_3 + 3) & 0x10) != 0)) ||
       ((*(uint8_t *)(arg_3 + 3) & 0x80) != 0)) {
      local_f0 = CreateSolidBrush(DAT_1013e3a8);
      SelectObject(hdc,local_f0);
    }
    else {
      local_f0 = CreateSolidBrush(DAT_1013e5e8);
      SelectObject(hdc,local_f0);
    }
    buf_ptr_1 = GetStockObject(8);
    SelectObject(hdc,buf_ptr_1);
    RoundRect(hdc,0,0,local_c4,local_2c,local_44 / 2,local_28 / 2);
    buf_ptr_1 = GetStockObject(4);
    SelectObject(hdc,buf_ptr_1);
    if (local_f0 != (HBRUSH)0x0) {
      DeleteObject(local_f0);
    }
    if (arg_3[4] == 1) {
      local_104 = &DAT_1013e60c;
    }
    else if (arg_3[4] == 8) {
      local_104 = &DAT_1013e034;
    }
    else if (arg_3[4] == 7) {
      local_104 = &DAT_1013e600;
    }
    else if (arg_3[4] == 5) {
      local_104 = &DAT_1013dff4;
    }
    else if (arg_3[4] == 2) {
      local_104 = &DAT_1013e5f4;
    }
    else if (arg_3[4] == 4) {
      local_104 = &DAT_1013e204;
    }
    else if (arg_3[4] == 0) {
      local_104 = &DAT_1013e5dc;
    }
    else if (arg_3[4] == 3) {
      local_104 = &DAT_1013e5dc;
    }
    else if (arg_3[4] == 6) {
      if ((*(uint8_t *)(arg_3 + 3) & 2) == 0) {
        if ((*(uint8_t *)(arg_3 + 3) & 4) == 0) {
          if ((*(uint8_t *)(arg_3 + 3) & 0x20) == 0) {
            if ((*(uint8_t *)((int)arg_3 + 0xd) & 1) == 0) {
              if ((*(uint8_t *)(arg_3 + 3) & 8) == 0) {
                val_3 = strcmp((char *)arg_3[1],s_Swamp_100436c8);
                if (val_3 == 0) {
                  local_104 = &DAT_1013e1f4;
                }
                else {
                  val_3 = strcmp((char *)arg_3[1],s_Plains_100436d0);
                  if (val_3 == 0) {
                    local_104 = &DAT_1013e200;
                  }
                  else {
                    val_3 = strcmp((char *)arg_3[1],s_Mountain_100436d8);
                    if (val_3 == 0) {
                      local_104 = &DAT_1013e564;
                    }
                    else {
                      val_3 = strcmp((char *)arg_3[1],s_Forest_100436e4);
                      if (val_3 == 0) {
                        local_104 = &DAT_1013e038;
                      }
                      else {
                        val_3 = strcmp((char *)arg_3[1],s_Island_100436ec);
                        if (val_3 == 0) {
                          local_104 = &DAT_1013e3b8;
                        }
                        else {
                          local_104 = &DAT_1013e608;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_104 = &DAT_1013e608;
              }
            }
            else {
              local_104 = &DAT_1013dfe8;
            }
          }
          else {
            local_104 = &DAT_1013e594;
          }
        }
        else {
          local_104 = &DAT_1013e5e4;
        }
      }
      else {
        local_104 = &DAT_1013e608;
      }
    }
    else if (arg_3[4] == -1) {
      local_104 = &DAT_1013e5d8;
    }
    else {
      local_104 = &DAT_1013e5dc;
    }
    thunk_FUN_1001a9ec(local_104);
    SetRect(&local_100,local_44,local_28,local_c4 - local_44,local_2c - local_28);
    if (*local_104 == 0) {
      pHVar4 = GetStockObject(0);
      FillRect(hdc,&local_100,pHVar4);
    }
    else {
      thunk_FUN_1003162f((int)hdc,(int)&local_100,(HANDLE)*local_104);
    }
    local_68 = (HANDLE)*local_104;
    local_cc = 1;
    local_c8 = thunk_FUN_1003378c(0xbf);
    SelectObject(hdc,DAT_1013e554);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_1013e1f8);
    OffsetRect(&local_40,local_cc,local_cc);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    OffsetRect(&local_40,-local_cc,-local_cc);
    SetTextColor(hdc,local_c8);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    local_108 = 100;
    SelectObject(hdc,DAT_1013e3a0);
    if ((arg_3[0x1f] != 0) || (arg_3[0x20] != 0)) {
      local_b0[0] = '\0';
      if (arg_3[0x1f] == local_108) {
        strcat(local_b0,&DAT_100436f4);
      }
      else if (local_108 < (int)arg_3[0x1f]) {
        val_3 = arg_3[0x1f] - local_108;
        pCVar5 = &DAT_100436f8;
        len_2 = strlen(local_b0);
        wsprintfA(local_b0 + len_2,pCVar5,val_3);
      }
      else {
        uval_6 = arg_3[0x1f];
        pCVar5 = &DAT_10043700;
        len_2 = strlen(local_b0);
        wsprintfA(local_b0 + len_2,pCVar5,uval_6);
      }
      strcat(local_b0,&DAT_10043704);
      if (arg_3[0x20] == local_108) {
        strcat(local_b0,&DAT_10043708);
      }
      else if (local_108 < (int)arg_3[0x20]) {
        val_3 = arg_3[0x20] - local_108;
        pCVar5 = &DAT_1004370c;
        len_2 = strlen(local_b0);
        wsprintfA(local_b0 + len_2,pCVar5,val_3);
      }
      else {
        uval_6 = arg_3[0x20];
        pCVar5 = &DAT_10043714;
        len_2 = strlen(local_b0);
        wsprintfA(local_b0 + len_2,pCVar5,uval_6);
      }
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&local_dc,local_cc,local_cc);
      DrawTextA(hdc,local_b0,-1,&local_dc,0x26);
      OffsetRect(&local_dc,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_b0,-1,&local_dc,0x26);
    }
    SelectObject(hdc,DAT_1013e044);
    SetBkMode(hdc,1);
    if ((arg_3[5] != -1) && (arg_3[5] != 0)) {
      if ((arg_3[5] == 2) && ((arg_3[6] == 0 || (arg_3[6] == 0xda)))) {
        strcpy(local_16c,s_Enchantment_10043718);
      }
      else {
        if ((arg_3[6] == 0) || (arg_3[6] == 0xda)) {
          local_1fc = &DAT_10043724;
        }
        else {
          local_1fc = (&PTR_DAT_10043c70)[arg_3[6]];
        }
        sprintf(local_16c,s__s__s_10043728,(&PTR_DAT_10043c48)[arg_3[5]],local_1fc);
      }
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&local_64,local_cc,local_cc);
      DrawTextA(hdc,local_16c,-1,&local_64,0x24);
      OffsetRect(&local_64,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_16c,-1,&local_64,0x24);
    }
    if (arg_3[0x10] != 0) {
      wsprintfA(local_b0,s_Illus___s_10043730,arg_3[0x10]);
      SetTextColor(hdc,DAT_1013e1f8);
      OffsetRect(&local_c0,local_cc,local_cc);
      DrawTextA(hdc,local_b0,-1,&local_c0,0x824);
      OffsetRect(&local_c0,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,local_b0,-1,&local_c0,0x824);
    }
    if (((arg_3[5] != 5) && (arg_3[5] != 8)) && (arg_3[5] != 0)) {
      thunk_FUN_1001c251(hdc,(int)&local_24,(char *)(arg_3 + 10));
    }
    if (arg_3[3] != -1) {
      thunk_FUN_1001c0c3(hdc,(int)&local_14,arg_3[3]);
    }
    if (DAT_101628dc != 0) {
      CopyRect(&local_17c,&local_ec);
      LPtoDP(hdc,(LPPOINT)&local_17c,2);
      if ((arg_5 & 0xf) == 0) {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (val_3 == 0) {
          thunk_FUN_10028d12(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          thunk_FUN_10013b53(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      else if ((arg_5 & 0xf) == 1) {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (val_3 == 0) {
          if (((arg_5 & 0x10) != 0) && (val_3 = thunk_FUN_10028c81(*arg_3,arg_4), val_3 != 0)) {
            thunk_FUN_10028d12(hdc,&local_ec,*arg_3,arg_4);
          }
          thunk_FUN_10013760(*arg_3,arg_4,local_17c.right - local_17c.left,
                             local_17c.bottom - local_17c.top);
        }
        thunk_FUN_10013b53(hdc,&local_ec,*arg_3,arg_4);
      }
      else {
        val_3 = thunk_FUN_10013a4c(*arg_3,arg_4);
        if (((val_3 == 0) && ((arg_5 & 0x10) != 0)) &&
           (val_3 = thunk_FUN_10028c81(*arg_3,arg_4), val_3 != 0)) {
          thunk_FUN_10028d12(hdc,&local_ec,*arg_3,arg_4);
        }
        val_3 = thunk_FUN_10013760(*arg_3,arg_4,local_17c.right - local_17c.left,
                                   local_17c.bottom - local_17c.top);
        if (val_3 == 0) {
          thunk_FUN_10028d12(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          thunk_FUN_10013b53(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      local_6c = thunk_FUN_10013ae3(*arg_3,arg_4,local_17c.right - local_17c.left,
                                    local_17c.bottom - local_17c.top);
    }
    SetTextColor(hdc,DAT_1013e65c);
    SetBkMode(hdc,1);
    if (arg_6 != 0) {
      SelectObject(hdc,DAT_1013e3ac);
      local_180 = thunk_FUN_1001cb7b(hdc,(int)&local_54,arg_3[0x1d]);
      local_180 = local_180 >> 0x10;
      GetTextMetricsA(hdc,&local_1cc);
      CopyRect(&local_194,&local_54);
      local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 2;
      SelectObject(hdc,DAT_1013e604);
      DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&local_194,0x410);
      local_184 = local_194.bottom - local_54.top;
      if (local_54.bottom - local_54.top < local_184) {
        local_1d8 = local_54.top - local_7c.top;
        local_54.top = local_54.bottom - local_184;
        local_7c.top = local_54.top - local_1d8;
        if (local_68 == (HANDLE)0x0) {
          pHVar4 = GetStockObject(0);
          FillRect(hdc,&local_7c,pHVar4);
        }
        else {
          GetObjectA(local_68,0x18,local_1f0);
          local_1d0 = 0x359;
          local_1d4 = 0x140;
          thunk_FUN_10031697(hdc,&local_7c.left,local_68,(local_1ec * 0x49) / 1000,
                             (local_1e8 * 0x25d) / 1000,(local_1ec * 0x359) / 1000,
                             (local_1e8 * 0x140) / 1000);
        }
      }
    }
    SelectObject(hdc,DAT_1013e3ac);
    local_180 = thunk_FUN_1001cbfc(hdc,&local_54.left,(char *)arg_3[0x1d],1);
    local_180 = local_180 >> 0x10;
    GetTextMetricsA(hdc,&local_1cc);
    CopyRect(&local_194,&local_54);
    local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 3;
    SelectObject(hdc,DAT_1013e604);
    DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&local_194,0x10);
    RestoreDC(hdc,local_30);
  }
  return local_6c;
}


