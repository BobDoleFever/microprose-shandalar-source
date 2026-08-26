/*
 * Decompiled function: Ai_Subsystem_004c7d69
 * Entry Point: 004c7d69
 * Size: 2276 bytes
 */
#include "magic.h"


int Ai_Subsystem_004c7d69(void)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  uint local_c0;
  int local_bc;
  int local_b4;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_98;
  int local_94;
  int aiStack_90 [16];
  uint local_50;
  int aiStack_4c [16];
  int local_c;
  int local_8;
  
  local_a0 = 0;
  DAT_006ff19c = 0;
  local_c = 0;
  local_94 = (&g_PlayerCreatureCount)[DAT_00559a20];
  local_98 = 0;
  DAT_00559f80 = 0;
  if (DAT_00641870 != 0) {
    local_a0 = DAT_00641874;
  }
  local_a8 = 0;
  do {
    iVar3 = local_94;
    if (DAT_00559a94 <= local_a8) {
      local_c = local_c + DAT_006ff19c;
      if (local_98 != 0) {
        while (local_a0 != 0) {
          local_e4 = 0;
          for (local_a8 = 0; local_a8 < local_98; local_a8 = local_a8 + 1) {
            if (local_e4 < aiStack_90[local_a8]) {
              local_e4 = aiStack_90[local_a8];
              local_e0 = local_a8;
            }
          }
          if (local_e4 == 0) {
            local_a0 = 0;
          }
          else {
            local_94 = local_94 + aiStack_90[local_e0];
            aiStack_90[local_e0] = 0;
            local_a0 = local_a0 + -1;
          }
        }
      }
      if (local_94 < 1) {
        local_c = local_c - (local_94 * -0x60 + 999);
      }
      else {
        iVar3 = ((&g_PlayerCreatureCount)[DAT_00559a20] - local_94) *
                *(int *)(&g_PlayerLifeTotals + DAT_00559a20 * 4) * 0x18;
        iVar3 = iVar3 + (iVar3 >> 0x1f & 3U);
        local_c = local_c - (int)(CONCAT44(iVar3 >> 0x1f,iVar3 >> 2) / (longlong)local_94);
        if (DAT_005597b8 != 0) {
          DAT_00559f80 = (((&g_PlayerCreatureCount)[DAT_00559a20] - local_94) * 700) /
                         (int)(&g_PlayerCreatureCount)[DAT_00559a20];
          local_c = local_c - DAT_00559f80;
        }
      }
      return local_c;
    }
    iVar1 = (&DAT_00559f88)[local_a8];
    local_dc = 0;
    local_d0 = -1;
    local_bc = -1;
    local_c8 = 0;
    bVar2 = false;
    local_50 = 0;
    local_cc = 0;
    DAT_006ff19c = DAT_006ff19c + (&DAT_00559a98)[local_a8];
    for (local_d4 = 0; local_d4 < DAT_00559b1c; local_d4 = local_d4 + 1) {
      if (*(int *)(&DAT_00559958 + local_d4 * 4) == (&DAT_005596b8)[local_a8]) {
        local_cc = local_cc + 1;
        DAT_006ff19c = DAT_006ff19c + (&DAT_00559a28)[local_d4];
        local_dc = local_dc + (&DAT_0055a010)[local_d4];
        local_d0 = local_d4;
        if ((*(byte *)(&DAT_00559638 + local_d4) & 0x40) != 0) {
          bVar2 = true;
        }
        if ((*(uint *)(&DAT_00559b20 + local_d4 * 4) & 1 << ((byte)local_a8 & 0x1f)) != 0) {
          local_dc = local_dc + 99;
        }
        if ((*(uint *)(&DAT_00559a68 + local_a8 * 4) & 1 << ((byte)local_d4 & 0x1f)) != 0) {
          local_50 = local_50 | 1 << ((byte)local_d4 & 0x1f);
        }
        if ((((int)(&DAT_00559848)[local_d4] <= iVar1) || (local_50 != 0)) &&
           ((*(byte *)((int)&DAT_00559638 + local_d4 * 4 + 1) & 2) == 0)) {
          aiStack_4c[local_c8] = local_d4;
          local_c8 = local_c8 + 1;
        }
        if (local_bc < (int)(&DAT_00559678)[local_d4]) {
          local_8 = local_d4;
          local_bc = (&DAT_00559678)[local_d4];
        }
      }
    }
    if (local_d0 == -1) {
      local_94 = local_94 - iVar1;
    }
    else if (((*(byte *)(&DAT_005595f8 + local_a8) & 0x80) != 0) && (local_dc < iVar1)) {
      local_94 = local_94 - (iVar1 - local_dc);
    }
    if (((DAT_00641870 != 0) && (local_94 < iVar3)) &&
       ((DAT_00641870 &
        (int)(char)(&DAT_006a5f4d)[(1 - DAT_00559a20) * 0x5b20 + (&DAT_005596b8)[local_a8] * 0x120])
        != 0)) {
      aiStack_90[local_98] = iVar3 - local_94;
      local_98 = local_98 + 1;
    }
    if (((local_d0 != -1) && ((int)(&DAT_00559808)[local_a8] <= local_dc)) &&
       (((*(byte *)((int)&DAT_005595f8 + local_a8 * 4 + 1) & 3) == 0 || (local_c8 == 0)))) {
      local_c = local_c + ((int)(*(int *)(&g_PlayerLifeTotals + (3 - DAT_00559a20) * 4) *
                                 (&DAT_00559fc8)[local_a8] +
                                (*(int *)(&g_PlayerLifeTotals + (3 - DAT_00559a20) * 4) *
                                 (&DAT_00559fc8)[local_a8] >> 0x1f & 7U)) >> 3);
    }
    local_c4 = -1;
    for (local_c0 = 0; (int)local_c0 < 1 << ((byte)local_c8 & 0x1f); local_c0 = local_c0 + 1) {
      if (local_50 == 0) {
        local_d8 = iVar1;
        if (!bVar2) goto LAB_004c8311;
        if (local_dc - local_cc < iVar1) {
          if (local_c0 == 0) {
            local_a4 = 0;
          }
          else {
            local_a4 = 9999;
          }
          for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
            if ((local_c0 & 1 << ((byte)local_b4 & 0x1f)) != 0) {
              iVar3 = aiStack_4c[local_b4];
              if ((int)(&DAT_0055a098)[iVar3] < local_a4) {
                local_a4 = (&DAT_0055a098)[iVar3];
              }
              if (iVar1 < (int)(&DAT_00559848)[iVar3]) {
                local_a4 = 0;
              }
              else if ((((&DAT_00559638)[iVar3] & 0x1ff800) != 0) &&
                      (((int)(char)(&DAT_006a5f4d)
                                   [(1 - DAT_00559a20) * 0x5b20 + (&DAT_005596b8)[local_a8] * 0x120]
                        << 10 & (&DAT_00559638)[iVar3] & 0x1ff800U) != 0)) {
                local_a4 = 0;
              }
            }
          }
        }
        else {
          local_a4 = 0;
        }
      }
      else {
        local_d8 = 99;
LAB_004c8311:
        local_a4 = 0;
        for (local_b4 = 0; local_b4 < local_c8; local_b4 = local_b4 + 1) {
          if ((local_c0 & 1 << ((byte)local_b4 & 0x1f)) != 0) {
            iVar3 = aiStack_4c[local_b4];
            if ((((*(byte *)((int)&DAT_00559638 + iVar3 * 4 + 1) & 1) == 0) ||
                ((int)(&DAT_0055a010)[iVar3] < (int)(&DAT_00559808)[local_a8])) &&
               (((int)(char)(&DAT_006a5f4d)
                            [(1 - DAT_00559a20) * 0x5b20 + (&DAT_005596b8)[local_a8] * 0x120] << 10
                 & (&DAT_00559638)[iVar3] & 0x1ff800U) == 0)) {
              local_a4 = local_a4 + (&DAT_0055a098)[iVar3];
            }
            local_d8 = local_d8 - (&DAT_00559848)[iVar3];
            if (local_d8 < 0) break;
          }
        }
      }
      if ((-1 < local_d8) && (local_c4 < local_a4)) {
        local_c4 = local_a4;
        DAT_005595d8 = local_c0;
      }
    }
    if (local_c8 == 0) {
      *(int *)(&DAT_00559738 + local_a8 * 4) = -local_8;
    }
    else {
      *(uint *)(&DAT_00559738 + local_a8 * 4) = DAT_005595d8;
    }
    local_c = local_c - local_c4;
    local_a8 = local_a8 + 1;
  } while( true );
}


