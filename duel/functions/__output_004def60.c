/*
 * Decompiled function: __output
 * Entry Point: 004def60
 * Size: 3177 bytes
 */
#include "duel.h"


/* Library Function - Single Match
    __output
   
   Library: Visual Studio 1998 Debug */

int __output(FILE *arg_1,byte *arg_2,undefined4 *arg_3)

{
  byte *pbVar1;
  wchar_t *pwVar2;
  size_t sVar3;
  code *pcVar4;
  ulonglong uVar5;
  wchar_t wVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  ulonglong uVar11;
  longlong lVar12;
  char local_28c [4];
  size_t local_288;
  wchar_t *local_284;
  int local_280;
  undefined8 local_27c;
  int local_274;
  undefined8 local_270;
  undefined4 local_268;
  undefined4 local_264;
  int *local_260;
  int local_25c;
  wchar_t *local_258;
  wchar_t *local_254;
  short *local_250;
  undefined2 local_24c;
  int local_248;
  char local_244;
  char local_243;
  int local_240;
  uint local_23c;
  int local_238;
  int local_234;
  int local_230;
  undefined1 local_22c [511];
  undefined2 uStack_2d;
  size_t local_28;
  wchar_t *local_24;
  int local_20;
  int local_1c;
  wchar_t local_18;
  undefined2 uStack_16;
  int local_14;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_230 = 0;
  local_1c = 0;
  pbVar1 = arg_2;
  do {
    arg_2 = pbVar1;
    uStack_2d._1_1_ = *arg_2;
    pbVar1 = arg_2 + 1;
    if ((uStack_2d._1_1_ == 0) || (local_230 < 0)) {
      return local_230;
    }
    if (((char)uStack_2d._1_1_ < ' ') || ('x' < (char)uStack_2d._1_1_)) {
      local_10 = 0;
    }
    else {
      local_10 = (int)"buf.c"[(char)uStack_2d._1_1_] & 0xf;
    }
    local_1c = (int)(char)(&DAT_004f0bb8)[local_10 * 8 + local_1c] >> 4;
    switch(local_1c) {
    case 0:
switchD_004dfca7_caseD_0:
      local_20 = 0;
      if ((*(ushort *)(PTR_DAT_005094a0 + (uint)uStack_2d._1_1_ * 2) & 0x8000) != 0) {
        write_char((int)(char)uStack_2d._1_1_,arg_1,&local_230);
        uStack_2d._1_1_ = *pbVar1;
        pbVar1 = arg_2 + 2;
        if (uStack_2d._1_1_ == 0) {
          iVar9 = __CrtDbgReport(2,0x4f0c14,0x185,0,"ch != _T(\'\\0\')");
          if (iVar9 == 1) {
            pcVar4 = (code *)swi(3);
            iVar9 = (*pcVar4)();
            return iVar9;
          }
        }
      }
      arg_2 = pbVar1;
      write_char((int)(char)uStack_2d._1_1_,arg_1,&local_230);
      pbVar1 = arg_2;
      break;
    case 1:
      local_c = 0;
      local_240 = 0;
      local_248 = 0;
      local_14 = 0;
      local_8 = 0;
      local_238 = -1;
      local_20 = 0;
      break;
    case 2:
      switch(uStack_2d._1_1_) {
      case 0x20:
        local_8 = local_8 | 2;
        break;
      case 0x23:
        local_8 = local_8 | 0x80;
        break;
      case 0x2b:
        local_8 = local_8 | 1;
        break;
      case 0x2d:
        local_8 = local_8 | 4;
        break;
      case 0x30:
        local_8 = local_8 | 8;
      }
      break;
    case 3:
      if (uStack_2d._1_1_ == 0x2a) {
        local_248 = get_int_arg((int *)&arg_3);
        if (local_248 < 0) {
          local_8 = local_8 | 4;
          local_248 = -local_248;
        }
      }
      else {
        local_248 = (char)uStack_2d._1_1_ + -0x30 + local_248 * 10;
      }
      break;
    case 4:
      local_238 = 0;
      break;
    case 5:
      if (uStack_2d._1_1_ == 0x2a) {
        local_238 = get_int_arg((int *)&arg_3);
        if (local_238 < 0) {
          local_238 = -1;
        }
      }
      else {
        local_238 = (char)uStack_2d._1_1_ + -0x30 + local_238 * 10;
      }
      break;
    case 6:
      switch(uStack_2d._1_1_) {
      case 0x49:
        if ((*pbVar1 != 0x36) || (arg_2[2] != 0x34)) {
          local_1c = 0;
          goto switchD_004dfca7_caseD_0;
        }
        local_8 = local_8 | 0x8000;
        pbVar1 = arg_2 + 3;
        break;
      case 0x68:
        local_8 = local_8 | 0x20;
        break;
      case 0x6c:
        local_8 = local_8 | 0x10;
        break;
      case 0x77:
        local_8 = local_8 | 0x800;
      }
      arg_2 = pbVar1;
      pbVar1 = arg_2;
      break;
    case 7:
      pwVar2 = local_24;
      switch(uStack_2d._1_1_) {
      case 0x43:
        if ((local_8 & 0x830) == 0) {
          local_8 = local_8 | 0x800;
        }
      case 99:
        if ((local_8 & 0x810) == 0) {
          local_24c = get_int_arg((int *)&arg_3);
          local_22c[0] = (char)local_24c;
          local_28 = 1;
        }
        else {
          wVar6 = get_short_arg((int *)&arg_3);
          _local_18 = CONCAT22(uStack_16,wVar6);
          local_28 = _wctomb(local_22c,wVar6);
          if ((int)local_28 < 0) {
            local_240 = 1;
          }
        }
        pwVar2 = (wchar_t *)local_22c;
        break;
      case 0x45:
      case 0x47:
        local_c = 1;
        uStack_2d._1_1_ = uStack_2d._1_1_ + 0x20;
      case 0x65:
      case 0x66:
      case 0x67:
        local_8 = local_8 | 0x40;
        local_24 = (wchar_t *)local_22c;
        if (local_238 < 0) {
          local_238 = 6;
        }
        else if ((local_238 == 0) && (uStack_2d._1_1_ == 0x67)) {
          local_238 = 1;
        }
        local_268 = *arg_3;
        local_264 = arg_3[1];
        arg_3 = arg_3 + 2;
        (*(code *)PTR___fptrap_0050a5b0)
                  (&local_268,local_24,(int)(char)uStack_2d._1_1_,local_238,local_c);
        if (((local_8 & 0x80) != 0) && (local_238 == 0)) {
          (*(code *)PTR___fptrap_0050a5bc)(local_24);
        }
        if ((uStack_2d._1_1_ == 0x67) && ((local_8 & 0x80) == 0)) {
          (*(code *)PTR___fptrap_0050a5b4)(local_24);
        }
        if ((char)*local_24 == '-') {
          local_8 = local_8 | 0x100;
          local_24 = (wchar_t *)((int)local_24 + 1);
        }
        local_28 = _strlen((char *)local_24);
        pwVar2 = local_24;
        break;
      case 0x53:
        if ((local_8 & 0x830) == 0) {
          local_8 = local_8 | 0x800;
        }
      case 0x73:
        if (local_238 == -1) {
          local_25c = 0x7fffffff;
        }
        else {
          local_25c = local_238;
        }
        local_24 = (wchar_t *)get_int_arg((int *)&arg_3);
        if ((local_8 & 0x810) == 0) {
          if (local_24 == (wchar_t *)0x0) {
            local_24 = (wchar_t *)PTR_DAT_005096f0;
          }
          for (local_254 = local_24; (local_25c != 0 && ((char)*local_254 != '\0'));
              local_254 = (wchar_t *)((int)local_254 + 1)) {
            local_25c = local_25c + -1;
          }
          local_28 = (int)local_254 - (int)local_24;
          local_25c = local_25c + -1;
          pwVar2 = local_24;
        }
        else {
          if (local_24 == (wchar_t *)0x0) {
            local_24 = (wchar_t *)PTR_DAT_005096f4;
          }
          local_20 = 1;
          for (local_258 = local_24; (local_25c != 0 && (*local_258 != L'\0'));
              local_258 = local_258 + 1) {
            local_25c = local_25c + -1;
          }
          local_28 = (int)local_258 - (int)local_24 >> 1;
          local_25c = local_25c + -1;
          pwVar2 = local_24;
        }
        break;
      case 0x5a:
        local_250 = (short *)get_int_arg((int *)&arg_3);
        if ((local_250 == (short *)0x0) || (*(int *)(local_250 + 2) == 0)) {
          local_24 = (wchar_t *)PTR_DAT_005096f0;
          local_28 = _strlen(PTR_DAT_005096f0);
          pwVar2 = local_24;
        }
        else if ((local_8 & 0x800) == 0) {
          local_20 = 0;
          local_28 = (size_t)*local_250;
          pwVar2 = *(wchar_t **)(local_250 + 2);
        }
        else {
          local_28 = (uint)(int)*local_250 >> 1;
          local_20 = 1;
          pwVar2 = *(wchar_t **)(local_250 + 2);
        }
        break;
      case 100:
      case 0x69:
        local_8 = local_8 | 0x40;
        local_23c = 10;
        goto LAB_004df77c;
      case 0x6e:
        local_260 = (int *)get_int_arg((int *)&arg_3);
        if ((local_8 & 0x20) == 0) {
          *local_260 = local_230;
        }
        else {
          *(short *)local_260 = (short)local_230;
        }
        local_240 = 1;
        pwVar2 = local_24;
        break;
      case 0x6f:
        local_23c = 8;
        if ((local_8 & 0x80) != 0) {
          local_8 = local_8 | 0x200;
        }
        goto LAB_004df77c;
      case 0x70:
        local_238 = 8;
      case 0x58:
        local_234 = 7;
        goto LAB_004df72b;
      case 0x75:
        local_23c = 10;
        goto LAB_004df77c;
      case 0x78:
        local_234 = 0x27;
LAB_004df72b:
        local_23c = 0x10;
        if ((local_8 & 0x80) != 0) {
          local_244 = '0';
          local_243 = (char)local_234 + 'Q';
          local_14 = 2;
        }
LAB_004df77c:
        if ((local_8 & 0x8000) == 0) {
          if ((local_8 & 0x20) == 0) {
            if ((local_8 & 0x40) == 0) {
              uVar8 = get_int_arg((int *)&arg_3);
              uVar11 = (ulonglong)uVar8;
            }
            else {
              iVar9 = get_int_arg((int *)&arg_3);
              uVar11 = (ulonglong)iVar9;
            }
          }
          else if ((local_8 & 0x40) == 0) {
            uVar8 = get_int_arg((int *)&arg_3);
            uVar11 = (ulonglong)(uVar8 & 0xffff);
          }
          else {
            sVar7 = get_int_arg((int *)&arg_3);
            uVar11 = (ulonglong)(int)sVar7;
          }
        }
        else {
          uVar11 = get_int64_arg((int *)&arg_3);
        }
        local_27c._4_4_ = (int)(uVar11 >> 0x20);
        local_27c._0_4_ = (int)uVar11;
        uVar5 = uVar11;
        if ((((local_8 & 0x40) != 0) && ((longlong)uVar11 < 0x100000000)) && ((longlong)uVar11 < 0))
        {
          local_8 = local_8 | 0x100;
          uVar5 = CONCAT44(-(local_27c._4_4_ + (uint)((int)local_27c != 0)),-(int)local_27c);
        }
        local_270._4_4_ = (uint)(uVar5 >> 0x20);
        local_270._0_4_ = (uint)uVar5;
        if ((local_8 & 0x8000) == 0) {
          local_270._4_4_ = 0;
        }
        lVar12 = CONCAT44(local_270._4_4_,(uint)local_270);
        if (local_238 < 0) {
          local_238 = 1;
        }
        else {
          local_8 = local_8 & 0xfffffff7;
        }
        if ((local_270._4_4_ == 0) && ((uint)local_270 == 0)) {
          local_14 = 0;
        }
        local_24 = &uStack_2d;
        local_27c = uVar11;
        while( true ) {
          local_270._4_4_ = (uint)((ulonglong)lVar12 >> 0x20);
          local_270._0_4_ = (uint)lVar12;
          iVar9 = local_238 + -1;
          if ((local_238 < 1) && (lVar12 == 0)) break;
          local_238 = iVar9;
          local_274 = __aullrem((uint)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
          local_270 = lVar12;
          local_274 = local_274 + 0x30;
          lVar12 = __aulldiv((uint)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
          if (0x39 < local_274) {
            local_274 = local_274 + local_234;
          }
          *(char *)local_24 = (char)local_274;
          local_24 = (wchar_t *)((int)local_24 + -1);
        }
        local_28 = (int)&uStack_2d - (int)local_24;
        pwVar2 = (wchar_t *)((int)local_24 + 1);
        local_270 = 0;
        local_238 = iVar9;
        if (((local_8 & 0x200) != 0) && ((*(char *)pwVar2 != '0' || (local_28 == 0)))) {
          *(char *)local_24 = '0';
          local_28 = local_28 + 1;
          pwVar2 = local_24;
        }
      }
      local_24 = pwVar2;
      if (local_240 == 0) {
        if ((local_8 & 0x40) != 0) {
          if ((local_8 & 0x100) == 0) {
            if ((local_8 & 1) == 0) {
              if ((local_8 & 2) != 0) {
                local_244 = ' ';
                local_14 = 1;
              }
            }
            else {
              local_244 = '+';
              local_14 = 1;
            }
          }
          else {
            local_244 = '-';
            local_14 = 1;
          }
        }
        local_280 = (local_248 - local_28) - local_14;
        if ((local_8 & 0xc) == 0) {
          write_multi_char(0x20,local_280,arg_1,&local_230);
        }
        write_string(&local_244,local_14,arg_1,&local_230);
        if (((local_8 & 8) != 0) && ((local_8 & 4) == 0)) {
          write_multi_char(0x30,local_280,arg_1,&local_230);
        }
        if ((local_20 == 0) || ((int)local_28 < 1)) {
          write_string((char *)local_24,local_28,arg_1,&local_230);
        }
        else {
          local_284 = local_24;
          local_288 = local_28;
          while (sVar3 = local_288 - 1, bVar10 = local_288 != 0, local_288 = sVar3, bVar10) {
            wVar6 = *local_284;
            local_284 = local_284 + 1;
            iVar9 = _wctomb(local_28c,wVar6);
            if (iVar9 < 1) break;
            write_string(local_28c,iVar9,arg_1,&local_230);
          }
        }
        if ((local_8 & 4) != 0) {
          write_multi_char(0x20,local_280,arg_1,&local_230);
        }
      }
    }
  } while( true );
}


