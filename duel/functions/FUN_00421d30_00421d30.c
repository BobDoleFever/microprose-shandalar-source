/*
 * Decompiled function: FUN_00421d30
 * Entry Point: 00421d30
 * Size: 735 bytes
 */
#include "duel.h"


uint FUN_00421d30(HDC hdc,int arg_2,int arg_3,LONG arg_4,char *str_5)

{
  uint uVar1;
  HFONT pHVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  LOGFONTA local_d4;
  int local_98;
  int local_94;
  HFONT local_90;
  tagTEXTMETRICA local_8c;
  int local_54;
  UINT local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined4 local_2f;
  _ABC local_10;
  
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 400;
  local_38 = 0;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  local_34 = 0;
  local_33 = 0;
  local_32 = 0;
  local_31 = 0;
  local_30 = 0;
  puVar5 = &local_2f;
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)puVar5 = 0;
  *(undefined1 *)((int)puVar5 + 2) = 0;
  if ((hdc == (HDC)0x0) || (str_5 == (char *)0x0)) {
    uVar1 = 0;
  }
  else {
    local_94 = SaveDC(hdc);
    FID_conflict__memcpy(&local_d4,&local_4c,0x3c);
    local_d4.lfHeight = arg_4;
    Mem_AllocOrFree_004d9630((uint *)local_d4.lfFaceName,(uint *)s_REGULAR_004f3468);
    local_90 = CreateFontIndirectA(&local_d4);
    if (local_90 == (HFONT)0x0) {
      local_90 = GetStockObject(0xd);
    }
    SelectObject(hdc,local_90);
    GetTextMetricsA(hdc,&local_8c);
    local_54 = local_8c.tmHeight;
    local_98 = local_8c.tmHeight;
    local_50 = GetTextAlign(hdc);
    if (((byte)local_50 & 0x18) == 0x18) {
      arg_3 = arg_3 - local_8c.tmAscent;
    }
    else if ((local_50 & 8) != 0) {
      arg_3 = arg_3 - local_8c.tmHeight;
    }
    if (((byte)local_50 & 6) == 6) {
      iVar4 = FUN_00421a54(hdc,str_5);
      arg_2 = arg_2 - iVar4 / 2;
    }
    else if ((local_50 & 2) != 0) {
      iVar4 = FUN_00421a54(hdc,str_5);
      arg_2 = arg_2 - iVar4;
    }
    SetTextAlign(hdc,0);
    for (; *str_5 != '\0'; str_5 = str_5 + 1) {
      if ((*str_5 < -0x12) || ((uint)(int)*str_5 < 0x80000000)) {
        GetCharABCWidthsA(hdc,(int)*str_5,(int)*str_5,&local_10);
        TextOutA(hdc,arg_2,arg_3,str_5,1);
        arg_2 = local_10.abcB + local_10.abcC + arg_2 + local_10.abcA;
      }
      else {
        FUN_0042200f((int)hdc,*str_5,arg_2,arg_3,local_98,local_54);
        arg_2 = arg_2 + local_98;
      }
    }
    SetTextAlign(hdc,local_50);
    RestoreDC(hdc,local_94);
    pHVar2 = GetStockObject(0xd);
    if (pHVar2 != local_90) {
      DeleteObject(local_90);
    }
    sVar3 = _strlen(str_5);
    uVar1 = sVar3 * local_98 & 0xffff | local_54 << 0x10;
  }
  return uVar1;
}


