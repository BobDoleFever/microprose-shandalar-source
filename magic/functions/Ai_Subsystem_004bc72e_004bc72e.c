/*
 * Decompiled function: Ai_Subsystem_004bc72e
 * Entry Point: 004bc72e
 * Size: 2311 bytes
 */
#include "magic.h"


undefined4
Ai_Subsystem_004bc72e(int arg_1,undefined4 arg_2,undefined4 arg_3,undefined4 arg_4,int arg_5)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  byte local_28;
  byte local_20;
  int local_18;
  int local_14;
  int local_c;
  
  bVar1 = false;
  for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
    if ((&DAT_006b2d40)[local_14] == -1) {
      bVar1 = true;
    }
  }
  iVar3 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if (iVar3 == 0) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_1]; local_c = local_c + 1) {
      iVar3 = Ai_Subsystem_004bd035(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = Magic_TriggerCardEvent(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar2 = false;
          for (local_14 = 0; local_14 < 7; local_14 = local_14 + 1) {
            if (((&DAT_006b2d40)[local_14] < 1) ||
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) == 0)) {
              if ((((&DAT_006b2d40)[local_14] == -1) &&
                  ((g_TurnCounter < g_OverworldPlayerCoordY && (g_OverworldPlayerCoordY != -1)))) &&
                 ((1 << ((byte)local_14 & 0x1f) &
                  (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) != 0)) {
                bVar2 = true;
              }
            }
            else {
              bVar2 = true;
            }
          }
          if ((arg_5 != 0) && (!bVar2)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c) != -1)))
            {
              local_20 = (byte)*(undefined2 *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c);
              if (((&DAT_006b2d40)[*(uint *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c) >> 0x10] <
                   1) || ((1 << (local_20 & 0x1f) &
                          (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) == 0)) {
                if (((&DAT_006b2d40)[*(uint *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c) >> 0x10]
                     == -1) &&
                   (((g_TurnCounter < g_OverworldPlayerCoordY && (g_OverworldPlayerCoordY != -1)) &&
                    ((1 << (local_20 & 0x1f) &
                     (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) != 0)))) {
                  bVar2 = true;
                }
              }
              else {
                bVar2 = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (bVar2) {
            iVar3 = Ai_Subsystem_004bd23f(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0040d949(arg_1,6,1);
              iVar4 = FUN_0040d949(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              Ai_Subsystem_004bb9f3(arg_1,arg_2,arg_3,iVar3);
              Ai_Subsystem_004bbb99(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  iVar3 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if ((iVar3 == 0) && ((DAT_006b2d40 != 0 || (DAT_006b2d58 != 0)))) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_1]; local_c = local_c + 1) {
      iVar3 = Ai_Subsystem_004bd035(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = Magic_TriggerCardEvent(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar2 = false;
          if (DAT_006b2d40 < 1) {
            if (((DAT_006b2d40 == -1) && (g_TurnCounter < g_OverworldPlayerCoordY)) &&
               (g_OverworldPlayerCoordY != -1)) {
              bVar2 = true;
            }
            else if (DAT_006b2d58 < 1) {
              if (((DAT_006b2d58 == -1) && (g_TurnCounter < g_OverworldPlayerCoordY)) &&
                 (g_OverworldPlayerCoordY != -1)) {
                bVar2 = true;
              }
            }
            else {
              bVar2 = true;
            }
          }
          else {
            bVar2 = true;
          }
          if (((&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120] == '@') && (DAT_006b2d58 == 0)) {
            bVar2 = false;
          }
          if (bVar2) {
            iVar3 = Ai_Subsystem_004bd23f(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0040d949(arg_1,6,1);
              iVar4 = FUN_0040d949(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              Ai_Subsystem_004bb9f3(arg_1,arg_2,arg_3,iVar3);
              Ai_Subsystem_004bbb99(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  iVar3 = Ai_Subsystem_004bbf8e(0x6b2d40,g_TurnCounter,g_OverworldPlayerCoordY);
  if (((iVar3 == 0) && (bVar1)) && (g_OverworldPlayerCoordY == -1)) {
    for (local_c = 0; local_c < (int)(&g_PlayerActiveCardCount)[arg_1]; local_c = local_c + 1) {
      iVar3 = Ai_Subsystem_004bd035(arg_1,local_c,(byte)arg_4);
      if (iVar3 != 0) {
        iVar3 = Magic_TriggerCardEvent(arg_1,local_c,0x73,1 - arg_1,0xffffffff);
        if (iVar3 != 0) {
          bVar1 = false;
          for (local_14 = 1; local_14 < 7; local_14 = local_14 + 1) {
            if (((g_OverworldPlayerCoordY == -1) && ((&DAT_006b2d40)[local_14] == -1)) &&
               ((1 << ((byte)local_14 & 0x1f) &
                (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) != 0)) {
              bVar1 = true;
            }
            else if ((g_OverworldPlayerCoordY == -1) && (DAT_006b2d40 == -1)) {
              bVar1 = true;
            }
            else if ((g_OverworldPlayerCoordY == -1) && (DAT_006b2d58 == -1)) {
              bVar1 = true;
            }
          }
          if (((&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120] == '@') && (DAT_006b2d58 != -1)) {
            bVar1 = false;
          }
          if ((arg_5 != 0) && (!bVar1)) {
            local_18 = 0;
            while ((local_18 < 10 && (*(int *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c) != -1)))
            {
              if (((g_OverworldPlayerCoordY == -1) &&
                  ((&DAT_006b2d40)[*(uint *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c) >> 0x10]
                   == -1)) &&
                 (local_28 = (byte)*(undefined2 *)(&DAT_00627a20 + local_18 * 4 + arg_1 * 0x2c),
                 (1 << (local_28 & 0x1f) &
                 (int)(char)(&DAT_006a5f4c)[arg_1 * 0x5b20 + local_c * 0x120]) != 0)) {
                bVar1 = true;
              }
              local_18 = local_18 + 1;
            }
          }
          if (bVar1) {
            iVar3 = Ai_Subsystem_004bd23f(arg_1,local_c);
            if (iVar3 != 0) {
              iVar3 = FUN_0040d949(arg_1,6,1);
              iVar4 = FUN_0040d949(arg_1,7,1);
              iVar3 = iVar3 - iVar4;
              Ai_Subsystem_004bb9f3(arg_1,arg_2,arg_3,iVar3);
              Ai_Subsystem_004bbb99(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
              Ai_Subsystem_004bbd93(arg_1,arg_2,arg_3,iVar3,&g_TurnCounter,g_OverworldPlayerCoordY);
            }
          }
        }
      }
    }
  }
  Ai_Subsystem_004b584e();
  return 1;
}


