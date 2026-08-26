/*
 * Decompiled function: Palette_Subsystem_0049c7c7
 * Entry Point: 0042053a
 * Size: 4227 bytes
 */
#include "duel.h"


undefined4
Palette_Subsystem_0049c7c7(HDC hdc,int *arg_2,undefined4 *arg_3,int arg_4,uint arg_5,int arg_6)

{
  HGDIOBJ pvVar1;
  size_t sVar2;
  int iVar3;
  HBRUSH pHVar4;
  LPCSTR pCVar5;
  undefined4 uVar6;
  undefined *local_1fc;
  undefined1 local_1f0 [4];
  int local_1ec;
  int local_1e8;
  int local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  tagTEXTMETRICA local_1cc;
  tagRECT local_194;
  int local_184;
  uint local_180;
  tagRECT local_17c;
  uint local_16c [25];
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
  uint local_b0 [13];
  tagRECT local_7c;
  undefined4 local_6c;
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
  
  if (((hdc == (HDC)0x0) || (arg_2 == (int *)0x0)) || (arg_3 == (undefined4 *)0x0)) {
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
    if (((arg_3[3] == -1) || ((*(byte *)(arg_3 + 3) & 0x10) != 0)) ||
       ((*(byte *)(arg_3 + 3) & 0x80) != 0)) {
      local_f0 = CreateSolidBrush(DAT_0050af90);
      SelectObject(hdc,local_f0);
    }
    else {
      local_f0 = CreateSolidBrush(DAT_0050b1d0);
      SelectObject(hdc,local_f0);
    }
    pvVar1 = GetStockObject(8);
    SelectObject(hdc,pvVar1);
    RoundRect(hdc,0,0,local_c4,local_2c,local_44 / 2,local_28 / 2);
    pvVar1 = GetStockObject(4);
    SelectObject(hdc,pvVar1);
    if (local_f0 != (HBRUSH)0x0) {
      DeleteObject(local_f0);
    }
    if (arg_3[4] == 1) {
      local_104 = &DAT_0050b1f4;
    }
    else if (arg_3[4] == 8) {
      local_104 = &DAT_0050ac1c;
    }
    else if (arg_3[4] == 7) {
      local_104 = &DAT_0050b1e8;
    }
    else if (arg_3[4] == 5) {
      local_104 = &DAT_0050abdc;
    }
    else if (arg_3[4] == 2) {
      local_104 = &DAT_0050b1dc;
    }
    else if (arg_3[4] == 4) {
      local_104 = &DAT_0050adec;
    }
    else if (arg_3[4] == 0) {
      local_104 = &DAT_0050b1c4;
    }
    else if (arg_3[4] == 3) {
      local_104 = &DAT_0050b1c4;
    }
    else if (arg_3[4] == 6) {
      if ((*(byte *)(arg_3 + 3) & 2) == 0) {
        if ((*(byte *)(arg_3 + 3) & 4) == 0) {
          if ((*(byte *)(arg_3 + 3) & 0x20) == 0) {
            if ((*(byte *)((int)arg_3 + 0xd) & 1) == 0) {
              if ((*(byte *)(arg_3 + 3) & 8) == 0) {
                iVar3 = _strcmp((char *)arg_3[1],s_Swamp_004f33f4);
                if (iVar3 == 0) {
                  local_104 = &DAT_0050addc;
                }
                else {
                  iVar3 = _strcmp((char *)arg_3[1],s_Plains_004f33fc);
                  if (iVar3 == 0) {
                    local_104 = &DAT_0050ade8;
                  }
                  else {
                    iVar3 = _strcmp((char *)arg_3[1],s_Mountain_004f3404);
                    if (iVar3 == 0) {
                      local_104 = &DAT_0050b14c;
                    }
                    else {
                      iVar3 = _strcmp((char *)arg_3[1],s_Forest_004f3410);
                      if (iVar3 == 0) {
                        local_104 = &DAT_0050ac20;
                      }
                      else {
                        iVar3 = _strcmp((char *)arg_3[1],s_Island_004f3418);
                        if (iVar3 == 0) {
                          local_104 = &DAT_0050afa0;
                        }
                        else {
                          local_104 = &DAT_0050b1f0;
                        }
                      }
                    }
                  }
                }
              }
              else {
                local_104 = &DAT_0050b1f0;
              }
            }
            else {
              local_104 = &DAT_0050abd0;
            }
          }
          else {
            local_104 = &DAT_0050b17c;
          }
        }
        else {
          local_104 = &DAT_0050b1cc;
        }
      }
      else {
        local_104 = &DAT_0050b1f0;
      }
    }
    else if (arg_3[4] == -1) {
      local_104 = &DAT_0050b1c0;
    }
    else {
      local_104 = &DAT_0050b1c4;
    }
    Palette_Subsystem_0049c3ac(local_104);
    SetRect(&local_100,local_44,local_28,local_c4 - local_44,local_2c - local_28);
    if (*local_104 == 0) {
      pHVar4 = GetStockObject(0);
      FillRect(hdc,&local_100,pHVar4);
    }
    else {
      FUN_004709ae((int)hdc,(int)&local_100,(HANDLE)*local_104);
    }
    local_68 = (HANDLE)*local_104;
    local_cc = 1;
    local_c8 = FUN_00472b02(0xbf);
    SelectObject(hdc,DAT_0050b13c);
    SetBkMode(hdc,1);
    SetTextColor(hdc,DAT_0050ade0);
    OffsetRect(&local_40,local_cc,local_cc);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    OffsetRect(&local_40,-local_cc,-local_cc);
    SetTextColor(hdc,local_c8);
    DrawTextA(hdc,(LPCSTR)arg_3[1],-1,&local_40,0x824);
    local_108 = 100;
    SelectObject(hdc,DAT_0050af88);
    if ((arg_3[0x1f] != 0) || (arg_3[0x20] != 0)) {
      local_b0[0]._0_1_ = 0;
      if (arg_3[0x1f] == local_108) {
        FUN_004d9640(local_b0,(uint *)&DAT_004f3420);
      }
      else if (local_108 < (int)arg_3[0x1f]) {
        iVar3 = arg_3[0x1f] - local_108;
        pCVar5 = &DAT_004f3424;
        sVar2 = _strlen((char *)local_b0);
        wsprintfA((LPSTR)((int)local_b0 + sVar2),pCVar5,iVar3);
      }
      else {
        uVar6 = arg_3[0x1f];
        pCVar5 = &DAT_004f342c;
        sVar2 = _strlen((char *)local_b0);
        wsprintfA((LPSTR)((int)local_b0 + sVar2),pCVar5,uVar6);
      }
      FUN_004d9640(local_b0,(uint *)&DAT_004f3430);
      if (arg_3[0x20] == local_108) {
        FUN_004d9640(local_b0,(uint *)&DAT_004f3434);
      }
      else if (local_108 < (int)arg_3[0x20]) {
        iVar3 = arg_3[0x20] - local_108;
        pCVar5 = &DAT_004f3438;
        sVar2 = _strlen((char *)local_b0);
        wsprintfA((LPSTR)((int)local_b0 + sVar2),pCVar5,iVar3);
      }
      else {
        uVar6 = arg_3[0x20];
        pCVar5 = &DAT_004f3440;
        sVar2 = _strlen((char *)local_b0);
        wsprintfA((LPSTR)((int)local_b0 + sVar2),pCVar5,uVar6);
      }
      SetTextColor(hdc,DAT_0050ade0);
      OffsetRect(&local_dc,local_cc,local_cc);
      DrawTextA(hdc,(LPCSTR)local_b0,-1,&local_dc,0x26);
      OffsetRect(&local_dc,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,(LPCSTR)local_b0,-1,&local_dc,0x26);
    }
    SelectObject(hdc,DAT_0050ac2c);
    SetBkMode(hdc,1);
    if ((arg_3[5] != -1) && (arg_3[5] != 0)) {
      if ((arg_3[5] == 2) && ((arg_3[6] == 0 || (arg_3[6] == 0xda)))) {
        Mem_AllocOrFree_004d9630(local_16c,(uint *)s_Enchantment_004f3444);
      }
      else {
        if ((arg_3[6] == 0) || (arg_3[6] == 0xda)) {
          local_1fc = &DAT_004f3450;
        }
        else {
          local_1fc = (&PTR_DAT_004f5500)[arg_3[6]];
        }
        _sprintf((char *)local_16c,s__s__s_004f3454,(&PTR_DAT_004f54d8)[arg_3[5]],local_1fc);
      }
      SetTextColor(hdc,DAT_0050ade0);
      OffsetRect(&local_64,local_cc,local_cc);
      DrawTextA(hdc,(LPCSTR)local_16c,-1,&local_64,0x24);
      OffsetRect(&local_64,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,(LPCSTR)local_16c,-1,&local_64,0x24);
    }
    if (arg_3[0x10] != 0) {
      wsprintfA((LPSTR)local_b0,s_Illus___s_004f345c,arg_3[0x10]);
      SetTextColor(hdc,DAT_0050ade0);
      OffsetRect(&local_c0,local_cc,local_cc);
      DrawTextA(hdc,(LPCSTR)local_b0,-1,&local_c0,0x824);
      OffsetRect(&local_c0,-local_cc,-local_cc);
      SetTextColor(hdc,local_c8);
      DrawTextA(hdc,(LPCSTR)local_b0,-1,&local_c0,0x824);
    }
    if (((arg_3[5] != 5) && (arg_3[5] != 8)) && (arg_3[5] != 0)) {
      FUN_00421990(hdc,(int)&local_24,(char *)(arg_3 + 10));
    }
    if (arg_3[3] != -1) {
      FUN_00421802((int)hdc,(int)&local_14,arg_3[3]);
    }
    if (DAT_0060cc70 != 0) {
      CopyRect(&local_17c,&local_ec);
      LPtoDP(hdc,(LPPOINT)&local_17c,2);
      if ((arg_5 & 0xf) == 0) {
        iVar3 = FUN_004867ca(*arg_3,arg_4);
        if (iVar3 == 0) {
          FUN_00438c81(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          FUN_004868d1(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      else if ((arg_5 & 0xf) == 1) {
        iVar3 = FUN_004867ca(*arg_3,arg_4);
        if (iVar3 == 0) {
          if (((arg_5 & 0x10) != 0) && (iVar3 = FUN_00438bf0(*arg_3,arg_4), iVar3 != 0)) {
            FUN_00438c81(hdc,&local_ec,*arg_3,arg_4);
          }
          FUN_004864e0(*arg_3,arg_4,local_17c.right - local_17c.left,
                       local_17c.bottom - local_17c.top);
        }
        FUN_004868d1(hdc,&local_ec,*arg_3,arg_4);
      }
      else {
        iVar3 = FUN_004867ca(*arg_3,arg_4);
        if (((iVar3 == 0) && ((arg_5 & 0x10) != 0)) &&
           (iVar3 = FUN_00438bf0(*arg_3,arg_4), iVar3 != 0)) {
          FUN_00438c81(hdc,&local_ec,*arg_3,arg_4);
        }
        iVar3 = FUN_004864e0(*arg_3,arg_4,local_17c.right - local_17c.left,
                             local_17c.bottom - local_17c.top);
        if (iVar3 == 0) {
          FUN_00438c81(hdc,&local_ec,*arg_3,arg_4);
        }
        else {
          FUN_004868d1(hdc,&local_ec,*arg_3,arg_4);
        }
      }
      local_6c = FUN_00486861(*arg_3,arg_4,local_17c.right - local_17c.left,
                              local_17c.bottom - local_17c.top);
    }
    SetTextColor(hdc,DAT_0050b244);
    SetBkMode(hdc,1);
    if (arg_6 != 0) {
      SelectObject(hdc,DAT_0050af94);
      local_180 = FUN_004222b9(hdc,(int)&local_54,arg_3[0x1d]);
      local_180 = local_180 >> 0x10;
      GetTextMetricsA(hdc,&local_1cc);
      CopyRect(&local_194,&local_54);
      local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 2;
      SelectObject(hdc,DAT_0050b1ec);
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
          FUN_00470a16(hdc,&local_7c.left,local_68,(local_1ec * 0x49) / 1000,
                       (local_1e8 * 0x25d) / 1000,(local_1ec * 0x359) / 1000,
                       (local_1e8 * 0x140) / 1000);
        }
      }
    }
    SelectObject(hdc,DAT_0050af94);
    local_180 = FUN_0042233a(hdc,&local_54.left,(char *)arg_3[0x1d],1);
    local_180 = local_180 >> 0x10;
    GetTextMetricsA(hdc,&local_1cc);
    CopyRect(&local_194,&local_54);
    local_194.top = local_194.top + local_180 + local_1cc.tmHeight / 3;
    SelectObject(hdc,DAT_0050b1ec);
    DrawTextA(hdc,(LPCSTR)arg_3[0x1e],-1,&local_194,0x10);
    RestoreDC(hdc,local_30);
  }
  return local_6c;
}


