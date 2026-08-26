/*
 * Decompiled function: FUN_00487ce1
 * Entry Point: 00487ce1
 * Size: 1130 bytes
 */
#include "duel.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00487ce1(int arg_1)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  byte local_8;
  
  DAT_0068ef90 = 0;
  FUN_0048e8f2(arg_1,0xcf,s_Draw_a_card_Phase_004faec8,1);
  if (DAT_0068ef90 == 0) {
    if (DAT_00676510 == arg_1) {
      if (DAT_00505988 == -1) {
        local_c = *(int *)(&DAT_006669f0 + arg_1 * 2000);
        if (local_c != -1) {
          FUN_004d7acc(arg_1,0);
          local_c = Pic_Subsystem_00451291(arg_1,local_c);
        }
      }
      else {
        iVar1 = FUN_004396ea(DAT_00505988);
        local_c = Pic_Subsystem_00451291(arg_1,iVar1);
      }
      if ((local_c == -1) || (*(int *)(&DAT_006826c4 + local_c * 0x120 + arg_1 * 0x5b20) == -1)) {
        if (DAT_0066aaf4 == 1) {
          (&DAT_00681ea8)[DAT_00676510] = 0;
          (&DAT_00681ea8)[1 - DAT_00676510] = 0x14;
        }
        else {
          Mem_AllocOrFree_00450eed(s_No_more_cards__you_lose__004faef4);
          Sleep(0x9c4);
          Mem_AllocOrFree_00450eed(&DAT_004faf10);
          FUN_004d65c6(0);
        }
      }
      else {
        FUN_00451482(0,0x30);
        if (DAT_0066aaf4 != 1) {
          if (DAT_0068eed8 == 0) {
            FUN_00450fca(*(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + arg_1 * 0x5b20),0xf6,
                         s_Draw_Card_004faee8,1);
          }
          else {
            FUN_00442839(*(undefined4 *)(&DAT_006826c4 + local_c * 0x120 + arg_1 * 0x5b20),arg_1,
                         local_c);
          }
        }
      }
    }
    else {
      if (DAT_00505984 == -1) {
        iVar1 = FUN_00439892(3);
        if (iVar1 == 0) {
          local_8 = 1;
        }
        else if (iVar1 == 1) {
          local_8 = 2;
        }
        else if (iVar1 == 2) {
          local_8 = 0x3c;
        }
        do {
          iVar1 = FUN_00439892(DAT_00665ed0);
          local_10 = FUN_004d7876((int)(char)(&DAT_004ff596)[iVar1 * 0x34],DAT_0068ed00,DAT_006669e8
                                 );
          if ((local_10 != 0) && (iVar2 = Pic_Subsystem_00452551(iVar1), DAT_006664e4 < iVar2)) {
            local_10 = 0;
          }
        } while (((local_10 == 0) || ((local_8 & (&DAT_004ff594)[iVar1 * 0x34]) == 0)) ||
                (((&DAT_004ff5a8)[iVar1 * 0x34] & 0x40) != 0));
        local_c = Pic_Subsystem_00451291(arg_1,iVar1);
      }
      else if (*(int *)(&DAT_006669f0 + arg_1 * 2000) == -1) {
        local_c = -1;
      }
      else {
        local_c = Pic_Subsystem_00451291(arg_1,*(int *)(&DAT_006669f0 + arg_1 * 2000));
        if (local_c != -1) {
          FUN_004d7acc(arg_1,0);
        }
      }
      if (local_c == -1) {
        if (DAT_0066aaf4 == 1) {
          (&DAT_00681ea8)[1 - DAT_00676510] = 0;
          (&DAT_00681ea8)[DAT_00676510] = 0x14;
        }
        else {
          Mem_AllocOrFree_00450eed(s_No_more_cards__opponent_loses__004faf14);
          Sleep(0x9c4);
          Mem_AllocOrFree_00450eed(&DAT_004faf34);
          FUN_004d65c6(1);
        }
      }
      FUN_00451482(0,0x30);
    }
    (&DAT_0068ee78)[arg_1] = (&DAT_0068ee78)[arg_1] + 1;
    _DAT_0068eea8 = _DAT_0068eea8 + 1;
    if ((DAT_0066aaf4 != 1) && (local_c != -1)) {
      FUN_0048d00c(2);
    }
    if (local_c != -1) {
      *(uint *)(&DAT_006826cc + local_c * 0x120 + arg_1 * 0x5b20) =
           *(uint *)(&DAT_006826cc + local_c * 0x120 + arg_1 * 0x5b20) | 1;
    }
  }
  else {
    local_c = 0;
  }
  return local_c;
}


