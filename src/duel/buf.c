/*
 * buf.c - Reconstructed MicroProse Source Module
 * Program: DUEL.EXE
 * Contained Functions: 12
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "shandalar/shandalar.h"
/* Modular Shandalar Subsystem */

/*
 * Decompiled function: __output
 * Entry Point: 004def60
 * Size: 3177 bytes
 */


/* Library Function - Single Match
    __output
   
   Library: Visual Studio 1998 Debug */

int __output(FILE *arg_1,uint8_t *arg_2,int32_t *arg_3)

{
  uint8_t *pbVar1;
  wchar_t *pwVar2;
  size_t len_3;
  code *pcVar4;
  ulonglong uval_5;
  wchar_t wVar6;
  short sVar7;
  uint32_t uval_8;
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
  int32_t local_268;
  int32_t local_264;
  int *local_260;
  int local_25c;
  wchar_t *local_258;
  wchar_t *local_254;
  short *local_250;
  int16_t local_24c;
  int local_248;
  char local_244;
  char local_243;
  int local_240;
  uint32_t local_23c;
  int local_238;
  int local_234;
  int local_230;
  uint8_t local_22c [511];
  int16_t uStack_2d;
  size_t local_28;
  wchar_t *local_24;
  int loop_idx;
  int color_idx;
  wchar_t target_idx;
  int16_t uStack_16;
  int player_idx;
  uint32_t card_idx;
  int32_t match_count;
  uint32_t slot_idx;
  
  local_230 = 0;
  color_idx = 0;
  pbVar1 = arg_2;
  do {
    arg_2 = pbVar1;
    uStack_2d._1_1_ = *arg_2;
    pbVar1 = arg_2 + 1;
    if ((uStack_2d._1_1_ == 0) || (local_230 < 0)) {
      return local_230;
    }
    if (((char)uStack_2d._1_1_ < ' ') || ('x' < (char)uStack_2d._1_1_)) {
      card_idx = 0;
    }
    else {
      card_idx = (int)"buf.c"[(char)uStack_2d._1_1_] & 0xf;
    }
    color_idx = (int)(char)(&DAT_004f0bb8)[card_idx * 8 + color_idx] >> 4;
    switch(color_idx) {
    case 0:
switchD_004dfca7_caseD_0:
      loop_idx = 0;
      if ((*(uint16_t *)(PTR_DAT_005094a0 + (uint32_t)uStack_2d._1_1_ * 2) & 0x8000) != 0) {
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
      match_count = 0;
      local_240 = 0;
      local_248 = 0;
      player_idx = 0;
      slot_idx = 0;
      local_238 = -1;
      loop_idx = 0;
      break;
    case 2:
      switch(uStack_2d._1_1_) {
      case 0x20:
        slot_idx = slot_idx | 2;
        break;
      case 0x23:
        slot_idx = slot_idx | 0x80;
        break;
      case 0x2b:
        slot_idx = slot_idx | 1;
        break;
      case 0x2d:
        slot_idx = slot_idx | 4;
        break;
      case 0x30:
        slot_idx = slot_idx | 8;
      }
      break;
    case 3:
      if (uStack_2d._1_1_ == 0x2a) {
        local_248 = get_int_arg((int *)&arg_3);
        if (local_248 < 0) {
          slot_idx = slot_idx | 4;
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
          color_idx = 0;
          goto switchD_004dfca7_caseD_0;
        }
        slot_idx = slot_idx | 0x8000;
        pbVar1 = arg_2 + 3;
        break;
      case 0x68:
        slot_idx = slot_idx | 0x20;
        break;
      case 0x6c:
        slot_idx = slot_idx | 0x10;
        break;
      case 0x77:
        slot_idx = slot_idx | 0x800;
      }
      arg_2 = pbVar1;
      pbVar1 = arg_2;
      break;
    case 7:
      pwVar2 = local_24;
      switch(uStack_2d._1_1_) {
      case 0x43:
        if ((slot_idx & 0x830) == 0) {
          slot_idx = slot_idx | 0x800;
        }
      case 99:
        if ((slot_idx & 0x810) == 0) {
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
        match_count = 1;
        uStack_2d._1_1_ = uStack_2d._1_1_ + 0x20;
      case 0x65:
      case 0x66:
      case 0x67:
        slot_idx = slot_idx | 0x40;
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
                  (&local_268,local_24,(int)(char)uStack_2d._1_1_,local_238,match_count);
        if (((slot_idx & 0x80) != 0) && (local_238 == 0)) {
          (*(code *)PTR___fptrap_0050a5bc)(local_24);
        }
        if ((uStack_2d._1_1_ == 0x67) && ((slot_idx & 0x80) == 0)) {
          (*(code *)PTR___fptrap_0050a5b4)(local_24);
        }
        if ((char)*local_24 == '-') {
          slot_idx = slot_idx | 0x100;
          local_24 = (wchar_t *)((int)local_24 + 1);
        }
        local_28 = _strlen((char *)local_24);
        pwVar2 = local_24;
        break;
      case 0x53:
        if ((slot_idx & 0x830) == 0) {
          slot_idx = slot_idx | 0x800;
        }
      case 0x73:
        if (local_238 == -1) {
          local_25c = 0x7fffffff;
        }
        else {
          local_25c = local_238;
        }
        local_24 = (wchar_t *)get_int_arg((int *)&arg_3);
        if ((slot_idx & 0x810) == 0) {
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
          loop_idx = 1;
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
        else if ((slot_idx & 0x800) == 0) {
          loop_idx = 0;
          local_28 = (size_t)*local_250;
          pwVar2 = *(wchar_t **)(local_250 + 2);
        }
        else {
          local_28 = (uint32_t)(int)*local_250 >> 1;
          loop_idx = 1;
          pwVar2 = *(wchar_t **)(local_250 + 2);
        }
        break;
      case 100:
      case 0x69:
        slot_idx = slot_idx | 0x40;
        local_23c = 10;
        goto LAB_004df77c;
      case 0x6e:
        local_260 = (int *)get_int_arg((int *)&arg_3);
        if ((slot_idx & 0x20) == 0) {
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
        if ((slot_idx & 0x80) != 0) {
          slot_idx = slot_idx | 0x200;
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
        if ((slot_idx & 0x80) != 0) {
          local_244 = '0';
          local_243 = (char)local_234 + 'Q';
          player_idx = 2;
        }
LAB_004df77c:
        if ((slot_idx & 0x8000) == 0) {
          if ((slot_idx & 0x20) == 0) {
            if ((slot_idx & 0x40) == 0) {
              uval_8 = get_int_arg((int *)&arg_3);
              uVar11 = (ulonglong)uval_8;
            }
            else {
              iVar9 = get_int_arg((int *)&arg_3);
              uVar11 = (ulonglong)iVar9;
            }
          }
          else if ((slot_idx & 0x40) == 0) {
            uval_8 = get_int_arg((int *)&arg_3);
            uVar11 = (ulonglong)(uval_8 & 0xffff);
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
        uval_5 = uVar11;
        if ((((slot_idx & 0x40) != 0) && ((longlong)uVar11 < 0x100000000)) && ((longlong)uVar11 < 0))
        {
          slot_idx = slot_idx | 0x100;
          uval_5 = CONCAT44(-(local_27c._4_4_ + (uint32_t)((int)local_27c != 0)),-(int)local_27c);
        }
        local_270._4_4_ = (uint32_t)(uval_5 >> 0x20);
        local_270._0_4_ = (uint32_t)uval_5;
        if ((slot_idx & 0x8000) == 0) {
          local_270._4_4_ = 0;
        }
        lVar12 = CONCAT44(local_270._4_4_,(uint32_t)local_270);
        if (local_238 < 0) {
          local_238 = 1;
        }
        else {
          slot_idx = slot_idx & 0xfffffff7;
        }
        if ((local_270._4_4_ == 0) && ((uint32_t)local_270 == 0)) {
          player_idx = 0;
        }
        local_24 = &uStack_2d;
        local_27c = uVar11;
        while( true ) {
          local_270._4_4_ = (uint32_t)((ulonglong)lVar12 >> 0x20);
          local_270._0_4_ = (uint32_t)lVar12;
          iVar9 = local_238 + -1;
          if ((local_238 < 1) && (lVar12 == 0)) break;
          local_238 = iVar9;
          local_274 = __aullrem((uint32_t)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
          local_270 = lVar12;
          local_274 = local_274 + 0x30;
          lVar12 = __aulldiv((uint32_t)local_270,local_270._4_4_,local_23c,(int)local_23c >> 0x1f);
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
        if (((slot_idx & 0x200) != 0) && ((*(char *)pwVar2 != '0' || (local_28 == 0)))) {
          *(char *)local_24 = '0';
          local_28 = local_28 + 1;
          pwVar2 = local_24;
        }
      }
      local_24 = pwVar2;
      if (local_240 == 0) {
        if ((slot_idx & 0x40) != 0) {
          if ((slot_idx & 0x100) == 0) {
            if ((slot_idx & 1) == 0) {
              if ((slot_idx & 2) != 0) {
                local_244 = ' ';
                player_idx = 1;
              }
            }
            else {
              local_244 = '+';
              player_idx = 1;
            }
          }
          else {
            local_244 = '-';
            player_idx = 1;
          }
        }
        local_280 = (local_248 - local_28) - player_idx;
        if ((slot_idx & 0xc) == 0) {
          write_multi_char(0x20,local_280,arg_1,&local_230);
        }
        write_string(&local_244,player_idx,arg_1,&local_230);
        if (((slot_idx & 8) != 0) && ((slot_idx & 4) == 0)) {
          write_multi_char(0x30,local_280,arg_1,&local_230);
        }
        if ((loop_idx == 0) || ((int)local_28 < 1)) {
          write_string((char *)local_24,local_28,arg_1,&local_230);
        }
        else {
          local_284 = local_24;
          local_288 = local_28;
          while (len_3 = local_288 - 1, bVar10 = local_288 != 0, local_288 = len_3, bVar10) {
            wVar6 = *local_284;
            local_284 = local_284 + 1;
            iVar9 = _wctomb(local_28c,wVar6);
            if (iVar9 < 1) break;
            write_string(local_28c,iVar9,arg_1,&local_230);
          }
        }
        if ((slot_idx & 4) != 0) {
          write_multi_char(0x20,local_280,arg_1,&local_230);
        }
      }
    }
  } while( true );
}



/*
 * Decompiled function: write_char
 * Entry Point: 004dfcf0
 * Size: 117 bytes
 */


/* Library Function - Single Match
    _write_char
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_char(int player_id,FILE *fp,int *arg_3)

{
  uint32_t slot_idx;
  
  fp->_cnt = fp->_cnt + -1;
  if (fp->_cnt < 0) {
    slot_idx = __flsbuf(arg_1,fp);
  }
  else {
    *fp->_ptr = (char)arg_1;
    slot_idx = (uint32_t)(uint8_t)*fp->_ptr;
    fp->_ptr = fp->_ptr + 1;
  }
  if (slot_idx == 0xffffffff) {
    *arg_3 = -1;
  }
  else {
    *arg_3 = *arg_3 + 1;
  }
  return;
}



/*
 * Decompiled function: write_multi_char
 * Entry Point: 004dfd70
 * Size: 75 bytes
 */


/* Library Function - Single Match
    _write_multi_char
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_multi_char(int x,int y,FILE *fp,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char(x,fp,height);
    y = y + -1;
  } while (*height != -1);
  return;
}



/*
 * Decompiled function: write_string
 * Entry Point: 004dfdc0
 * Size: 87 bytes
 */


/* Library Function - Single Match
    _write_string
   
   Library: Visual Studio 1998 Debug */

void __cdecl write_string(char *filepath,int y,FILE *fp,int *height)

{
  do {
    if (y < 1) {
      return;
    }
    write_char((int)*str_1,fp,height);
    str_1 = str_1 + 1;
    y = y + -1;
  } while (*height != -1);
  return;
}



/*
 * Decompiled function: get_int_arg
 * Entry Point: 004dfe20
 * Size: 30 bytes
 */


/* Library Function - Single Match
    _get_int_arg
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl get_int_arg(int *arg_1)

{
  *arg_1 = *arg_1 + 4;
  return *(int32_t *)(*arg_1 + -4);
}



/*
 * Decompiled function: get_int64_arg
 * Entry Point: 004dfe40
 * Size: 35 bytes
 */


/* Library Function - Single Match
    _get_int64_arg
   
   Library: Visual Studio 1998 Debug */

undefined8 __cdecl get_int64_arg(int *arg_1)

{
  *arg_1 = *arg_1 + 8;
  return *(undefined8 *)(*arg_1 + -8);
}



/*
 * Decompiled function: get_short_arg
 * Entry Point: 004dfe70
 * Size: 31 bytes
 */


/* Library Function - Single Match
    _get_short_arg
   
   Library: Visual Studio 1998 Debug */

int32_t __cdecl get_short_arg(int *arg_1)

{
  *arg_1 = *arg_1 + 4;
  return CONCAT22((short)((uint32_t)*arg_1 >> 0x10),*(int16_t *)(*arg_1 + -4));
}



/*
 * Decompiled function: __CrtDbgBreak
 * Entry Point: 004dfe90
 * Size: 17 bytes
 */


/* Library Function - Single Match
    __CrtDbgBreak
   
   Library: Visual Studio 1998 Debug */

void __CrtDbgBreak(void)

{
  DebugBreak();
  return;
}



/*
 * Decompiled function: __CrtSetReportMode
 * Entry Point: 004dfeb0
 * Size: 126 bytes
 */


/* Library Function - Single Match
    __CrtSetReportMode
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtSetReportMode(int arg1,uint32_t arg2)

{
  int32_t uval_1;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 0xffffffff;
  }
  else if (arg2 == 0xffffffff) {
    uval_1 = *(int32_t *)(&DAT_00509700 + arg1 * 4);
  }
  else if ((arg2 & 0xfffffff8) == 0) {
    uval_1 = *(int32_t *)(&DAT_00509700 + arg1 * 4);
    *(uint32_t *)(&DAT_00509700 + arg1 * 4) = arg2;
  }
  else {
    uval_1 = 0xffffffff;
  }
  return uval_1;
}



/*
 * Decompiled function: __CrtSetReportFile
 * Entry Point: 004dff30
 * Size: 169 bytes
 */


/* Library Function - Single Match
    __CrtSetReportFile
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtSetReportFile(int arg1,int arg2)

{
  int32_t uval_1;
  HANDLE buf_ptr_2;
  
  if ((arg1 < 0) || (2 < arg1)) {
    uval_1 = 0xfffffffe;
  }
  else if (arg2 == -6) {
    uval_1 = *(int32_t *)(&DAT_00509710 + arg1 * 4);
  }
  else {
    uval_1 = *(int32_t *)(&DAT_00509710 + arg1 * 4);
    if (arg2 == -4) {
      buf_ptr_2 = GetStdHandle(0xfffffff5);
      *(HANDLE *)(&DAT_00509710 + arg1 * 4) = buf_ptr_2;
    }
    else if (arg2 == -5) {
      buf_ptr_2 = GetStdHandle(0xfffffff4);
      *(HANDLE *)(&DAT_00509710 + arg1 * 4) = buf_ptr_2;
    }
    else {
      *(int *)(&DAT_00509710 + arg1 * 4) = arg2;
    }
  }
  return uval_1;
}



/*
 * Decompiled function: Mem_AllocOrFree_004dffe0
 * Entry Point: 004dffe0
 * Size: 38 bytes
 */


int32_t Mem_AllocOrFree_004dffe0(int32_t arg_1)

{
  int32_t uval_1;
  
  uval_1 = DAT_006c2ca4;
  DAT_006c2ca4 = arg_1;
  return uval_1;
}



/*
 * Decompiled function: __CrtDbgReport
 * Entry Point: 004e0010
 * Size: 998 bytes
 */


/* Library Function - Single Match
    __CrtDbgReport
   
   Library: Visual Studio 1998 Debug */

int32_t __CrtDbgReport(int player_id,int card_slot,int event_type,int32_t arg_4,char *str_5)

{
  LONG LVar1;
  size_t nNumberOfBytesToWrite;
  int val_2;
  int32_t *u_ptr_3;
  char local_3028 [20];
  DWORD local_3014;
  HMODULE local_3010;
  uint8_t local_300c;
  int32_t local_300b;
  uint8_t local_200c;
  int32_t local_200b;
  int32_t local_100c;
  va_list local_1008;
  uint8_t local_1004;
  int32_t local_1003;
  int32_t uStackY_2c;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  
  Mem_AllocOrFree_004ddee0();
  local_300c = 0;
  u_ptr_3 = &local_300b;
  for (val_2 = 0x3ff; val_2 != 0; val_2 = val_2 + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  *(int16_t *)u_ptr_3 = 0;
  *(uint8_t *)((int)u_ptr_3 + 2) = 0;
  local_200c = '\0';
  u_ptr_3 = &local_200b;
  for (val_2 = 0x3ff; val_2 != 0; val_2 = val_2 + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  *(int16_t *)u_ptr_3 = 0;
  *(uint8_t *)((int)u_ptr_3 + 2) = 0;
  local_1004 = '\0';
  u_ptr_3 = &local_1003;
  for (val_2 = 0x3ff; val_2 != 0; val_2 = val_2 + -1) {
    *u_ptr_3 = 0;
    u_ptr_3 = u_ptr_3 + 1;
  }
  *(int16_t *)u_ptr_3 = 0;
  *(uint8_t *)((int)u_ptr_3 + 2) = 0;
  local_1008 = &stack0x00000018;
  if ((arg_1 < 0) || (2 < arg_1)) {
    local_100c = 0xffffffff;
  }
  else if ((arg_1 == 2) && (LVar1 = InterlockedIncrement((LONG *)&DAT_005096f8), 0 < LVar1)) {
    if ((DAT_0050972c == (FARPROC)0x0) &&
       ((local_3010 = LoadLibraryA("user32.dll"), local_3010 == (HMODULE)0x0 ||
        (DAT_0050972c = GetProcAddress(local_3010,"wsprintfA"), DAT_0050972c == (FARPROC)0x0)))) {
      local_100c = 0xffffffff;
    }
    else {
      (*DAT_0050972c)();
      OutputDebugStringA(&local_200c);
      InterlockedDecrement((LONG *)&DAT_005096f8);
      __CrtDbgBreak();
      local_100c = 0xffffffff;
    }
  }
  else {
    if ((str_5 != (char *)0x0) &&
       (val_2 = __vsnprintf(&local_1004,0xfed,str_5,local_1008), val_2 < 0)) {
      Mem_AllocOrFree_004d9630
                ((uint32_t *)&local_1004,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
    }
    if (arg_1 == 2) {
      Mem_AllocOrFree_004d9630
                ((uint32_t *)&local_300c,
                 (uint32_t *)("Assertion failed: " + ((str_5 != (char *)0x0) - 1 & 0xfffff6dc)));
    }
    Str_CopyFast((uint32_t *)&local_300c,(uint32_t *)&local_1004);
    if (arg_1 == 2) {
      if ((bRam00509708 & 1) != 0) {
        Str_CopyFast((uint32_t *)&local_300c,(uint32_t *)&DAT_004f0c60);
      }
      Str_CopyFast((uint32_t *)&local_300c,(uint32_t *)&DAT_004f021c);
    }
    if (arg_2 == 0) {
      Mem_AllocOrFree_004d9630((uint32_t *)&local_200c,(uint32_t *)&local_300c);
    }
    else {
      uStackY_2c = 0x4e024d;
      val_2 = __snprintf(&local_200c,0x1000,"%s(%d) : %s");
      if (val_2 < 0) {
        Mem_AllocOrFree_004d9630
                  ((uint32_t *)&local_200c,(uint32_t *)"_CrtDbgReport: String too long or IO Error");
      }
    }
    if ((DAT_006c2ca4 == (code *)0x0) || (val_2 = (*DAT_006c2ca4)(), val_2 == 0)) {
      if ((((&DAT_00509700)[arg_1 * 4] & 1) != 0) && (*(int *)(&DAT_00509710 + arg_1 * 4) != -1)) {
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_3014;
        nNumberOfBytesToWrite = _strlen(&local_200c);
        WriteFile(*(HANDLE *)(&DAT_00509710 + arg_1 * 4),&local_200c,nNumberOfBytesToWrite,
                  lpNumberOfBytesWritten,lpOverlapped);
      }
      if (((&DAT_00509700)[arg_1 * 4] & 2) != 0) {
        OutputDebugStringA(&local_200c);
      }
      if (((&DAT_00509700)[arg_1 * 4] & 4) == 0) {
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_005096f8);
        }
        local_100c = 0;
      }
      else {
        if (arg_3 != 0) {
          __itoa(arg_3,local_3028,10);
        }
        local_100c = _CrtMessageWindow();
        if (arg_1 == 2) {
          InterlockedDecrement((LONG *)&DAT_005096f8);
        }
      }
    }
    else if (arg_1 == 2) {
      InterlockedDecrement((LONG *)&DAT_005096f8);
    }
  }
  return local_100c;
}



