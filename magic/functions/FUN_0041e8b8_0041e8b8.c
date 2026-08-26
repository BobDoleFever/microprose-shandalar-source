/*
 * Decompiled function: FUN_0041e8b8
 * Entry Point: 0041e8b8
 * Size: 981 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0041e8b8(int arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint arg_4;
  DWORD arg_5;
  int *arg_6;
  uint arg_7;
  int arg_8;
  int local_58 [6];
  int local_40;
  int local_3c [6];
  int local_24;
  uint local_20;
  DWORD local_1c;
  uint local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = *(int *)(arg1 + 0x2c) * 2 + -0x60;
  if (DAT_00680770 == 0) {
    if ((DAT_007039cc < *(int *)(arg1 + 0x10)) ||
       (*(int *)(arg1 + 0x18) + *(int *)(arg1 + 0x10) < DAT_007039cc)) {
      bVar1 = false;
    }
    else if ((DAT_007039c8 < *(int *)(arg1 + 0x14)) ||
            (*(int *)(arg1 + 0x14) + *(int *)(arg1 + 0x1c) < DAT_007039c8)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return 0;
    }
  }
  if (*(int *)(arg1 + 0x40) == 3) {
    uVar3 = 0;
  }
  else {
    if (((_DAT_0067f374 & 1 << ((byte)local_8 & 0x1f)) != 0) &&
       (local_c = Bazaar_GetCardBaseValue(local_8), *(int *)(&DAT_0067bdbc + (local_8 / 2) * 4) != 0
       )) {
      if (arg2 == 2) {
        local_14 = *(int *)(&DAT_00519dc4 + (*(int *)(arg1 + 0x2c) + -0x31) * 0x54);
        local_20 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f20 + local_8 * 0x10));
        local_24 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f24 + local_8 * 0x10));
        local_18 = Ai_Util_004c3bc4(*(int *)(&DAT_00519f28 + local_8 * 0x10));
        local_1c = Ai_Util_004c3bc4(*(int *)(&DAT_00519f2c + local_8 * 0x10));
        local_10 = Ai_Util_004c3bc4(4);
        iVar2 = local_24;
        arg_4 = local_18;
        arg_5 = local_1c;
        arg_6 = (int *)g_DisplaySurfaceBackBuffer;
        arg_7 = local_20;
        arg_8 = local_24;
        iVar4 = Ai_Util_004c3bc4(0x148);
        FUN_0050dce0((int *)PTR_DAT_005174bc,local_20,iVar2 - iVar4,arg_4,arg_5,arg_6,arg_7,arg_8);
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,*(int *)(&DAT_00519f20 + local_8 * 0x10),
                   *(int *)(&DAT_00519f24 + local_8 * 0x10),
                   *(undefined4 *)(&DAT_00678330 + local_8 * 4),
                   *(int *)(&DAT_00519f28 + local_8 * 0x10),*(int *)(&DAT_00519f2c + local_8 * 0x10)
                  );
        Sprite_DrawScaled((int *)g_DisplaySurfaceBackBuffer,local_20 + local_10,local_24 + local_10,
                          local_18 + local_10 * -2,local_1c + local_10 * -2,local_14);
        iVar2 = DAT_006776a0;
        local_3c[5] = DAT_006776a0;
        local_3c[0] = 0x6c;
        local_3c[1] = 0xbf;
        local_3c[2] = 0x10e;
        local_3c[3] = 0x15e;
        local_3c[4] = 0x1b1;
        local_58[0] = 2;
        local_58[1] = 1;
        local_58[2] = 4;
        local_58[3] = 3;
        local_58[4] = 0;
        local_58[5] = local_8 / 2 + -1;
        *(undefined4 *)(g_DisplaySurfaceScreen + 0x20) = 4;
        local_40 = 400 - (int)*(short *)(iVar2 + 6) / 2;
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceBackBuffer,local_3c[local_58[5]] + -0x1e,local_40,
                   (&DAT_006776a0)[local_58[local_58[5]]],(int)*(short *)(iVar2 + 4),
                   (int)*(short *)(iVar2 + 6));
        FUN_0050dce0((int *)g_DisplaySurfaceBackBuffer,local_20,local_24,local_18,local_1c,
                     (int *)g_DisplaySurfaceScreen,local_20,local_24);
        if (*(int *)(arg1 + 0x28) != 0) {
          (**(code **)(arg1 + 0x28))(arg1);
        }
      }
      else {
        Ai_Subsystem_004be3c4
                  (g_DisplaySurfaceScreen,*(int *)(&DAT_00519f20 + local_8 * 0x10),
                   *(int *)(&DAT_00519f24 + local_8 * 0x10),
                   *(undefined4 *)
                    (&DAT_00519dbc + (*(int *)(arg1 + 0x2c) + -0x31) * 0x54 + arg2 * 4),
                   *(int *)(&DAT_00519f28 + local_8 * 0x10),*(int *)(&DAT_00519f2c + local_8 * 0x10)
                  );
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


