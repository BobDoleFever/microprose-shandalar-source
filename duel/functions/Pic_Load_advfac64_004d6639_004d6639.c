/*
 * Decompiled function: Pic_Load_advfac64_004d6639
 * Entry Point: 004d6639
 * Size: 797 bytes
 */
#include "duel.h"


int Pic_Load_advfac64_004d6639
              (int arg_1,int *out_buffer,int arg_3,undefined4 arg_4,int arg_5,undefined4 arg_6)

{
  longlong lVar1;
  int local_178c;
  int local_1788;
  int aiStackY_1784 [500];
  int aiStackY_fb4 [500];
  int local_7e4;
  int local_7e0;
  int local_7dc;
  int aiStackY_7d8 [487];
  undefined4 uStackY_3c;
  undefined4 uStackY_38;
  undefined4 uStackY_34;
  undefined4 uStackY_30;
  undefined4 uStackY_2c;
  undefined4 uStackY_28;
  int iVar2;
  
  Mem_AllocOrFree_004ddee0();
  if ((DAT_00676510 == arg_1) && (DAT_0066aaf4 != 1)) {
    if (DAT_0068eed8 == 0) {
      FUN_00434a43(s_todpal_tr_005092a8,(char *)0x0);
      Mem_AllocOrFree_0049f6b4();
      SelectPalette(DAT_005f2fa4,DAT_005f6290,0);
      Mem_AllocOrFree_0049f7d9();
      uStackY_28 = 0x4d6763;
      Mem_AllocOrFree_0049f7c4();
      uStackY_28 = 0x1e0;
      uStackY_2c = 0x280;
      uStackY_30 = 0;
      uStackY_34 = 0;
      uStackY_38 = DAT_00505990;
      uStackY_3c = 0x4d6795;
      Mem_AllocOrFree_0049f7a0();
      local_1788 = 0;
      for (iVar2 = 0; iVar2 < arg_3; iVar2 = iVar2 + 1) {
        if ((out_buffer[iVar2] != -1) &&
           ((iVar2 == 0 || (out_buffer[iVar2 + -1] != out_buffer[iVar2])))) {
          local_1788 = local_1788 + 1;
        }
      }
      local_7dc = (local_1788 + -1) / 5;
      if (local_7dc == 0) {
        local_7dc = 1;
      }
      lVar1 = (longlong)local_7dc;
      local_7e0 = 0x60;
      local_7dc = 0;
      local_7e4 = 0x10;
      for (iVar2 = 0; iVar2 < arg_3; iVar2 = iVar2 + 1) {
        if ((out_buffer[iVar2] != -1) &&
           ((iVar2 == 0 || (out_buffer[iVar2 + -1] != out_buffer[iVar2])))) {
          aiStackY_fb4[local_7dc] = local_7e0 + 4;
          aiStackY_1784[local_7dc] = local_7e4;
          aiStackY_7d8[local_7dc] = iVar2;
          local_7dc = local_7dc + 1;
          local_7e0 = local_7e0 + 0x38;
          if (0x13f < local_7e0) {
            local_7e0 = 0x60;
            local_7e4 = local_7e4 + (int)(0x54 / lVar1);
          }
        }
      }
      FUN_004b93c4();
    }
    else {
      uStackY_28 = 0x4d694e;
      local_178c = FUN_00450f15(out_buffer,arg_3,arg_4,arg_5,arg_6);
    }
  }
  else {
    local_7dc = 0;
    for (iVar2 = 0; iVar2 < arg_3; iVar2 = iVar2 + 1) {
      if (out_buffer[iVar2] != -1) {
        aiStackY_7d8[local_7dc] = iVar2;
        local_7dc = local_7dc + 1;
      }
    }
    DAT_0068f2c8 = FUN_00439892(local_7dc);
    if (DAT_00676510 != arg_1) {
      if (DAT_0066aaf4 == 1) {
        FUN_0043064a();
      }
      else {
        FUN_004307b2();
      }
    }
    local_178c = aiStackY_7d8[DAT_0068f2c8];
  }
  return local_178c;
}


