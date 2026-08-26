/*
 * Decompiled function: FUN_00489748
 * Entry Point: 00489748
 * Size: 1359 bytes
 */
#include "magic.h"


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00489748(char *arg1,int arg2)

{
  bool bVar1;
  int iVar2;
  char *str_2;
  int iVar3;
  uint uVar4;
  int local_34;
  int local_28;
  int local_1c;
  char local_18 [4];
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((arg2 != 0) && (DAT_00676d3c == 0)) {
    FUN_0040a3e1();
  }
  local_1c = -1;
  DAT_00527b28 = 0;
  _DAT_00527b1c = 0;
  DAT_00539de4 = 0;
  local_34 = 0;
  if (DAT_00527b18 != -1) {
    local_34 = DAT_00527b18;
  }
  DAT_00676d50 = -1;
  DAT_00676d38 = 1;
  DAT_00539e04 = -1;
  DAT_00527b30 = Mem_AllocOrFree_0050f740(*(int *)(g_DisplaySurfaceScreen + 0x20));
  local_14 = 0x16;
  DAT_00539de0 = 0xff;
  if (DAT_0067bde4 == 0) {
    local_14 = 0xffffffff;
  }
  local_c = 0;
  bVar1 = false;
  Pic_Subsystem_0044b8da();
  FUN_00489c9c(arg1,DAT_00527b18);
  Pic_Subsystem_0044b8aa();
  if (DAT_00676d3c == 0) {
    if (DAT_00527b2c != -1) {
      Mem_AllocOrFree_005016f9();
      local_8 = -1;
    }
    do {
      DAT_00676d38 = 0;
      DAT_0067bda0 = 0;
      if (DAT_00701014 == 0) {
        FUN_0040a2c0();
      }
      iVar3 = DAT_00527b2c;
      if (DAT_00527b2c != -1) {
        iVar2 = Mem_AllocOrFree_00501721();
        local_10 = iVar3 - iVar2 / (DAT_0052244c * 0x3c);
        if (local_10 == 0) {
          local_34 = -1;
          bVar1 = true;
        }
        if (local_8 != local_10) {
          str_2 = _itoa(local_10,&DAT_00539df8,10);
          strcpy(local_18,str_2);
          Surface_FillRect((int *)g_DisplaySurfaceScreen,DAT_00676d44 + -0xe,DAT_00539df0 + 4,0xc,7,
                           0xbc);
          FUN_0040c3cc(local_18,DAT_00676d44 + -8,DAT_00539df0 + 5,0xff);
          local_8 = local_10;
        }
      }
      Pic_Subsystem_0044b84b();
      if ((DAT_0067bda0 == 0) && (local_c == 0)) {
        iVar3 = Mem_AllocOrFree_00408089();
        if (iVar3 != 0) {
          uVar4 = FUN_0048ac2f();
          iVar3 = local_34;
          if ((int)uVar4 < 0x1c) {
            if (uVar4 == 0x1b) {
              local_34 = -1;
              bVar1 = true;
            }
            else {
              if (uVar4 == 0xd) goto LAB_00489ab3;
LAB_00489af7:
              do {
                iVar2 = iVar3;
                local_28 = iVar2 + 1;
                if (0x1f < local_28) goto LAB_00489b95;
                iVar3 = local_28;
              } while (((&DAT_00676d11)[iVar2] == -1) ||
                      (iVar3 = local_28,
                      (((int)(char)(&DAT_00676d11)[iVar2] ^ uVar4 & 0x1f) & 0x1f) != 0));
              local_34 = local_28;
            }
          }
          else if (uVar4 == 0x20) {
LAB_00489ab3:
            if ((DAT_00676d58 & 1 << ((byte)local_34 & 0x1f)) == 0) {
              bVar1 = true;
            }
          }
          else if (uVar4 == 0x4800) {
            if (0 < local_34) {
              local_34 = local_34 + -1;
            }
          }
          else {
            if (uVar4 != 0x5000) goto LAB_00489af7;
            if (local_34 < DAT_00676d40 + -1) {
              local_34 = local_34 + 1;
            }
          }
        }
      }
      else {
        DAT_00527b28 = 1;
        local_c = 1;
        if (DAT_0067bda0 == 2) {
          _DAT_00527b1c = 1;
        }
        local_34 = ((DAT_0067bda8 - DAT_00539df0) + -4) / DAT_00527b30 - DAT_00676d50;
        if ((DAT_0067bda4 < DAT_00539dec) || (DAT_00676d44 < DAT_0067bda4)) {
          local_34 = -1;
        }
        if ((DAT_00676d58 & 1 << ((byte)local_34 & 0x1f)) == 0) {
          if (DAT_0067bda0 == 0) {
            bVar1 = true;
          }
        }
        else {
          local_34 = local_1c;
        }
      }
LAB_00489b95:
      if ((((local_34 < 0) || (DAT_00676d40 <= local_34)) || (DAT_00676d4c != 0)) ||
         (DAT_00676d34 != 0)) {
        local_34 = -1;
      }
      if (local_1c != local_34) {
        FUN_00489c9c(arg1,local_34);
        local_1c = local_34;
        DAT_00539e04 = local_34;
      }
    } while (!bVar1);
    DAT_00539de4 = 1;
    if (local_34 == -1) {
      _DAT_00527b1c = 0;
    }
    else {
      Pic_Subsystem_0044b8da();
      FUN_00489c9c(arg1,local_34);
      FUN_00501736(0x14);
      Pic_Subsystem_0044b8aa();
    }
    DAT_00527b2c = -1;
    DAT_00527b20 = 0xffffffff;
    DAT_00527b18 = -1;
    DAT_00527b24 = 0;
    DAT_00676d34 = 0;
    DAT_00676d58 = 0;
    _DAT_00676d30 = 0;
  }
  else {
    DAT_00676d3c = 0;
    local_34 = -1;
  }
  return local_34;
}


